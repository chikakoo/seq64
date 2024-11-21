/*
 * ============================================================================
 *
 * MainComponent.cpp
 * GUI component that holds the menus, tabs, etc. and performs menu functions
 *
 * From seq64 - Sequenced music editor for first-party N64 games
 * Copyright (C) 2014-2019 Sauraen
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * ============================================================================
*/

#include "MainComponent.h"
#include "FilesPane.h"
#include "AudioseqPane.h"
#include "MidiPane.h"
#include "AudiobankPane.h"
#include "Finder.h"
#include "CICSetter.h"
#include "n64checksum.h"

//==============================================================================

MainComponent::MainComponent(SEQ64& seq64_, DocumentWindow& window_) : seq64(seq64_), window(window_)
{
	seq64.maincomponent = this;

	//Menus
	menuBarHeight = 24;

	PopupMenu* menu;
	PopupMenu* submenu;

	menunames.add("ROM");
	menu = new PopupMenu();
	menu->addItem(1, "Load...");
	menu->addSeparator();
	menu->addItem(4, "Byte Ordering...");
	menu->addSeparator();
	menu->addItem(2, "Save");
	menu->addItem(3, "Save As...");
	menus.add(menu);

	menunames.add("RomDesc");
	menu = new PopupMenu();
	menu->addItem(11, "Load...");
	menu->addSeparator();
	menu->addItem(12, "Save");
	menu->addItem(13, "Save As...");
	menus.add(menu);

	menunames.add("Tools");
	menu = new PopupMenu();
	submenu = new PopupMenu();
	submenu->addItem(61, "Decompress Yay0...");
	submenu->addItem(62, "Decompress Yaz0...");
	submenu->addSeparator();
	submenu->addItem(63, "Compress Yay0...");
	submenu->addItem(64, "Compress Yaz0...");
	submenus.add(submenu);
	menu->addSubMenu("Compression", *submenu);
	menus.add(menu);

	menunames.add("Help");
	menu = new PopupMenu();
	menu->addItem(91, "How do I even?");
	menu->addSeparator();
	menu->addItem(92, "Waaaah! Da thingy not working!");
	menu->addItem(93, "I can haz haxxorz?");
	menus.add(menu);

	mnuBar.reset(new MenuBarComponent(this));
	addAndMakeVisible(*mnuBar);
	mnuBar->setColour(TextButton::buttonColourId, Colours::black);

	//Tabbed Panes
	filespane.reset(new FilesPane(seq64));
	audioseqpane.reset(new AudioseqPane(seq64));
	midipane.reset(new MidiPane(seq64));
	audiobankpane.reset(new AudiobankPane(seq64));
	finder.reset(new Finder(seq64));

	tabbox.reset(new TabbedComponent(TabbedButtonBar::TabsAtTop));
	tabbox->addTab("Files", LFWidgetColor(), &*filespane, false);
	tabbox->addTab("Audioseq", LFWidgetColor(), &*audioseqpane, false);
	tabbox->addTab("MIDI File", LFWidgetColor(), &*midipane, false);
	tabbox->addTab("Audiobank", LFWidgetColor(), &*audiobankpane, false);
	tabbox->addTab("Finder", LFWidgetColor(), &*finder, false);
	tabbox->setColour(TabbedComponent::backgroundColourId, LFWindowColor());
	tabbox->setColour(TabbedComponent::outlineColourId, Colours::darkgrey);
	tabbox->setCurrentTabIndex(2);
	addAndMakeVisible(*tabbox);

	//Other
	setSize(1080, 768);

	onROMLoaded();
	tryLoadOoTRomDescription();
}

/// <summary>
/// Tries to load the OoT ROM description from the last folder opened
/// Always calls onRomDescLoaded so that things are initialized
/// </summary>
void MainComponent::tryLoadOoTRomDescription() {
	const String romDescFolderPath = SEQ64::readFolderProperty("romdescfolder").getFullPathName();
	const String descFileName = "oot_v1.0_info.xml";
	const File romDescFile = File(romDescFolderPath + "\\" + descFileName);

	if (romDescFile.existsAsFile()) {
		seq64.romdescfile = romDescFile;
		if (!seq64.loadRomDesc()) {
			seq64.romdescfile = File();
		}
	}

	onRomDescLoaded();
}

MainComponent::~MainComponent()
{
}

StringArray MainComponent::getMenuBarNames() {
	return menunames;
}
PopupMenu MainComponent::getMenuForIndex(int topLevelMenuIndex, const String& menuName) {
	return *menus[topLevelMenuIndex];
}

void MainComponent::actuallySaveROM() {
	if (!seq64.romfile.hasWriteAccess()) return;
	UpdateCRC(seq64.rom);
	SEQ64::say("Saving 0x" + ROM::hex((uint32)seq64.rom.getSize())
		+ " bytes to " + seq64.romfile.getFullPathName());
	if (!seq64.romfile.replaceWithData(seq64.rom.getData(), (int)seq64.rom.getSize())) {
		SEQ64::say("Error: could not write file " + seq64.romfile.getFullPathName() + "!");
		return;
	}
	SEQ64::say("Successfully saved 0x" + ROM::hex((uint32)seq64.romfile.getSize()) + " bytes");
}
void MainComponent::actuallySaveRomDesc() {
	SEQ64::say("Saving XML ROM description parameters");
	std::unique_ptr<XmlElement> xml;
	xml = seq64.romdesc.createXml();
	if (xml != nullptr) {
		if (xml->writeToFile(seq64.romdescfile, "<!-- seq64 ROM Description File -->")) {
			SEQ64::say("Successfully saved");
			return;
		}
	}
	SEQ64::say("Error: could not write file " + seq64.romdescfile.getFullPathName() + "!");
	return;
}

void MainComponent::menuItemSelected(int menuItemID, int topLevelMenuIndex) {
	if (menuItemID == 1) {
		//ROM::Load...
		FileChooser box("Select a ROM to load...", SEQ64::readFolderProperty("romfolder"),
			"*.z64;*.n64;*.v64;*.r64;*.ndd;*.ndr", SEQ64::useNativeFileChooser());
		if (box.browseForFileToOpen()) {
			seq64.romfile = box.getResult();
			if (!seq64.romfile.existsAsFile()) {
				SEQ64::say("File " + seq64.romfile.getFullPathName() + " does not exist!");
				seq64.romfile = "";
				seq64.rom.reset();
				return;
			}
			//Save what folder you're in
			SEQ64::writeProperty("romfolder", seq64.romfile.getParentDirectory().getFullPathName());
			//Load ROM
			if (!seq64.loadROM()) {
				seq64.romfile = File();
				return;
			}
			while (seq64.rom.cic_index < 0) {
				int res = NativeMessageBox::showYesNoCancelBox(AlertWindow::WarningIcon,
					"CRC Check", "ROM CRCs did not match according to any known CIC!\n"
					"\n"
					"Your options:\n"
					"Click Yes: Select a different byte ordering, then check CRC again\n"
					"Click No: Select CIC manually\n"
					"Click Cancel: No change, but CIC will not be updated when ROM is saved", nullptr, nullptr);
				if (res == 1) {
					queryByteOrdering();
					FindCIC(seq64.rom);
				}
				else if (res == 2) {
					DialogWindow::LaunchOptions cicbox;
					cicbox.dialogTitle = "Set CIC";
					cicbox.dialogBackgroundColour = Colours::lightgrey;
					cicbox.content.setOwned(new CICSetter(seq64));
					cicbox.resizable = false;
					cicbox.launchAsync();
					break;
				}
				else {
					seq64.rom.cic_index = 0;
					break;
				}
			}
			onROMLoaded();
		}
		return;
	}
	else if (menuItemID == 2) {
		//ROM::Save
		if (seq64.rom.getSize() == 0) {
			SEQ64::say("No ROM to save!");
			return;
		}
		if (!seq64.romfile.exists()) {
			menuItemID = 3; //Save As instead!
		}
		else {
			if (!NativeMessageBox::showOkCancelBox(AlertWindow::WarningIcon,
				"Overwrite?", "Save over " + seq64.romfile.getFileName() + "?", nullptr, nullptr)) return;
			actuallySaveROM();
			return;
		}
	}
	if (menuItemID == 3) {
		//ROM::Save As...
		if (seq64.rom.getSize() == 0) {
			SEQ64::say("No ROM to save!");
			return;
		}
		File newsavelocation = (seq64.romfile.exists() ? seq64.romfile : SEQ64::readFolderProperty("romfolder"));
		String extension;
		if (seq64.romfile.exists()) {
			extension = seq64.romfile.getFileExtension();
		}
		else {
			switch (seq64.rom.byteOrdering) {
			case ROM::ABCD: extension = ".z64"; break;
			case ROM::BADC: extension = ".n64"; break;
			case ROM::DCBA: extension = ".r64"; break;
			default: extension = ".rom"; break;
			}
		}
		FileChooser box("Save As", newsavelocation, "*", SEQ64::useNativeFileChooser());
		if (box.browseForFileToSave(true)) {
			newsavelocation = box.getResult();
			if (!newsavelocation.hasWriteAccess()) {
				SEQ64::say("Cannot write to " + newsavelocation.getFullPathName() + "!");
				return;
			}
			if (newsavelocation.getFileExtension() == "") {
				newsavelocation = newsavelocation.withFileExtension(extension);
			}
		}
		else {
			return;
		}
		seq64.romfile = newsavelocation;
		actuallySaveROM();
		return;
	}
	else if (menuItemID == 4) {
		//ROM::Byte Ordering...
		queryByteOrdering();
		return;
	}
	else if (menuItemID == 11) {
		//RomDesc::Load...
		FileChooser box("Select a ROM description file to load...", SEQ64::readFolderProperty("romdescfolder"),
			"*.xml", SEQ64::useNativeFileChooser());
		if (box.browseForFileToOpen()) {
			seq64.romdescfile = box.getResult();
			if (!seq64.romdescfile.existsAsFile()) {
				SEQ64::say("File " + seq64.romdescfile.getFullPathName() + " does not exist!");
				seq64.romdescfile = File();
				return;
			}
			//Save what folder you're in
			SEQ64::writeProperty("romdescfolder", seq64.romdescfile.getParentDirectory().getFullPathName());
			//Load XML
			if (!seq64.loadRomDesc()) {
				seq64.romdescfile = File();
				return;
			}
			onRomDescLoaded();
			return;
		}
		return;
	}
	else if (menuItemID == 12) {
		//RomDesc::Save
		if (seq64.romdescfile.exists()) {
			actuallySaveRomDesc();
		}
		else {
			SEQ64::say("No file to save to!");
		}
		return;
	}
	else if (menuItemID == 13) {
		//RomDesc::Save As...
		File newsavelocation = File::getSpecialLocation(File::userHomeDirectory);
		if (seq64.romdescfile.exists()) {
			newsavelocation = seq64.romdescfile.getParentDirectory();
		}
		FileChooser box("Save As", newsavelocation, "*.xml", SEQ64::useNativeFileChooser());
		if (box.browseForFileToSave(true)) {
			newsavelocation = box.getResult();
			if (!newsavelocation.hasWriteAccess()) {
				SEQ64::say("Cannot write to " + newsavelocation.getFullPathName() + "!");
				return;
			}
			if (newsavelocation.getFileExtension() == "") {
				newsavelocation = newsavelocation.withFileExtension(".xml");
			}
			seq64.romdescfile = newsavelocation;
			actuallySaveRomDesc();
		}
		else {
			return;
		}
		return;
	}
	else if (menuItemID == 61) {
		//Tools::Compression::Decompress Yay0...
		doCodecOperation(0);
		return;
	}
	else if (menuItemID == 62) {
		//Tools::Compression::Decompress Yaz0...
		doCodecOperation(1);
		return;
	}
	else if (menuItemID == 63) {
		//Tools::Compression::Compress Yay0...
		doCodecOperation(2);
		return;
	}
	else if (menuItemID == 64) {
		//Tools::Compression::Compress Yaz0...
		doCodecOperation(3);
		return;
	}
	else if (menuItemID == 91) {
		//Help::How do I even?
		NativeMessageBox::showMessageBox(AlertWindow::NoIcon, "Help Topics", helpText1);
		return;
	}
	else if (menuItemID == 92) {
		//Help::Waaaah! Da thingy not working!
		int res = NativeMessageBox::showYesNoCancelBox(AlertWindow::QuestionIcon, "You called?",
			"Are you REALLY sure the software is broken, and it's not just that you don't know how to use it?", nullptr, nullptr);
		if (res != 1) {
			NativeMessageBox::showMessageBox(AlertWindow::InfoIcon, "n00b",
				"Click Help > How do I even? for links to information about how to use seq64.");
		}
		else {
			NativeMessageBox::showMessageBox(AlertWindow::InfoIcon, "Report a Bug",
				helpText2
				+ (char)('A' - 1)
				+ (char)('j' - 3)
				+ (char)('p' - 3)
				+ (char)('h' - 7)
				+ (char)('m' - 4)
				+ (char)('n' - 2)
				+ (char)('.' - 0)
				+ (char)('i' - 6)
				+ (char)('x' - 9)
				+ (char)('s' - 6)
				+ (char)(')' - 9)
				+ helpText2b);
		}
		return;
	}
	else if (menuItemID == 93) {
		//Help::I can haz haxxorz?
		NativeMessageBox::showMessageBox(AlertWindow::NoIcon, "About seq64", helpText3);
		return;
	}
	SEQ64::say("Bad menu item selected, " + String(menuItemID));
}

void MainComponent::queryByteOrdering() {
	if (!seq64.romfile.exists() || seq64.rom.getSize() == 0) {
		SEQ64::say("No ROM loaded!");
		NativeMessageBox::showMessageBox(AlertWindow::InfoIcon, "Byte Ordering",
			"No ROM loaded!");
		return;
	}
	ROM::BYTEORDERING orig_order = seq64.rom.byteOrdering;
	String orig_order_name;
	switch (orig_order) {
	case ROM::ABCD: orig_order_name = "ABCD"; break;
	case ROM::BADC: orig_order_name = "BADC"; break;
	case ROM::DCBA: orig_order_name = "DCBA"; break;
	default: orig_order_name = "ERROR"; jassertfalse;
	}
	String name_cur = seq64.rom.getROMName();
	seq64.rom.byteOrdering = ROM::ABCD;
	String name_abcd = seq64.rom.getROMName();
	seq64.rom.byteOrdering = ROM::BADC;
	String name_badc = seq64.rom.getROMName();
	seq64.rom.byteOrdering = ROM::DCBA;
	String name_dcba = seq64.rom.getROMName();

	int res = NativeMessageBox::showYesNoCancelBox(AlertWindow::QuestionIcon, "Byte Ordering",
		"To determine the correct byte ordering, select\n"
		"which option below looks like the correct ROM name.\n"
		"(Currently " + orig_order_name + " with name " + name_cur + ")\n"
		"\n"
		"Click 'Yes' for ABCD order: " + name_abcd + "\n"
		"Click 'No' for BADC order: " + name_badc + "\n"
		"Click 'Cancel' for DCBA order: " + name_dcba, nullptr, nullptr);

	String new_order_name;
	switch (res) {
	case 1: seq64.rom.byteOrdering = ROM::ABCD; new_order_name = "ABCD"; break;
	case 2: seq64.rom.byteOrdering = ROM::BADC; new_order_name = "BADC"; break;
	case 0: seq64.rom.byteOrdering = ROM::DCBA; new_order_name = "DCBA"; break;
	default: jassertfalse; new_order_name = "ERROR";
	}
	if (orig_order != seq64.rom.byteOrdering) {
		NativeMessageBox::showMessageBox(AlertWindow::InfoIcon, "Byte Ordering",
			"Changed from " + orig_order_name + " to " + new_order_name + " byte ordering.");
		onROMLoaded();
	}
}

void MainComponent::doCodecOperation(int operation) {
	String conv_desc, op_desc;
	switch (operation) {
	case 0: conv_desc = "Yay0 compressed"; op_desc = "Decompressing from Yay0..."; break;
	case 1: conv_desc = "Yaz0 compressed"; op_desc = "Decompressing from Yaz0..."; break;
	case 2: conv_desc = "uncompressed"; op_desc = "Compressing as Yay0..."; break;
	case 3: conv_desc = "uncompressed"; op_desc = "Compressing as Yaz0..."; break;
	default: SEQ64::say("Error"); return;
	};
	FileChooser box("Choose input " + conv_desc + " file...",
		SEQ64::readFolderProperty("codecfolder"), "", SEQ64::useNativeFileChooser());
	if (!box.browseForFileToOpen()) return;
	File inputfile = box.getResult();
	if (!inputfile.existsAsFile()) {
		SEQ64::say("File does not exist!");
		return;
	}
	SEQ64::writeProperty("codecfolder", inputfile.getParentDirectory().getFullPathName());
	codec = nullptr;
	codec.reset(new Yax0Codec(operation, inputfile, conv_desc));
	codec->setStatusMessage(op_desc);
	codec->launchThread();
}

void MainComponent::paint(Graphics& g)
{

}

void MainComponent::resized()
{
	mnuBar->setBounds(0, 0, getWidth(), menuBarHeight);
	tabbox->setBounds(0, menuBarHeight, getWidth(), getHeight() - menuBarHeight);
}

void MainComponent::onROMLoaded() {
	window.setName(seq64.rom.getROMName() + "- seq64");
	onRomDescLoaded();
}
void MainComponent::onRomDescLoaded() {
	filespane->romDescLoaded();
	audiobankpane->romDescLoaded();
	audioseqpane->refreshCmdList();
	midipane->refreshMIDIControls();
	onGotABI();
}
void MainComponent::onSeqLoaded() {
	audioseqpane->fillSeqSections();
	audioseqpane->fillSeqCommands();
}
void MainComponent::onBankLoaded() {
	audiobankpane->bankLoaded();
}
void MainComponent::onGotABI() {
	audiobankpane->gotABI();
}

const String MainComponent::helpText1 = String(
	"We understand you might be confused. seq64 is a complex program\n"
	"and intends you to have some knowledge of n64 music and ROM\n"
	"hacking in general.\n"
	"\n"
	"There are resources available to help you get started with seq64.\n"
	"Access the online documentation by going to https://github.com/sauraen/seq64\n"
	"and clicking on the Wiki tab at the top. This includes tutorials and\n"
	"step-by-step guides to importing and exporting MIDIs and editing banks.\n"
	"\n"
	"If seq64 gives errors when using a RomDesc, check that the RomDesc\n"
	"is for the same version of the ROM that you're using, and that your ROM\n"
	"is decompressed (if applicable). Also, if your ROM crashes when playing\n"
	"back the edited music, make sure you're using the most up-to-date version\n"
	"of the RomDesc, or else file a bug report.\n"
);

const String MainComponent::helpText2 = String(
	"Contact Sauraen on Twitter at @sauraen\n"
	"or send Sauraen an email at sauraen"
);

const String MainComponent::helpText2b = String(
	".\n"
	"\n"
	"Do NOT ask me for sets of MIDIs exported from one of these games.\n"
	"If you want such a set, check out the SEQ64 command line options\n"
	"(by simply running ./seq64 --help or seq64.exe --help) and then\n"
	"write a script to repeatedly run the program and extract each song."
);

const String MainComponent::helpText3 = String(
	"Yes! You CAN haz haxxorz.\n"
	"\n"
	"seq64 is licensed under the GNU General Public License version 3.0.\n"
	"This means you can distribute and modify it under certain conditions;\n"
	"see the license for details.\n"
	"\n"
	"seq64 - sequenced music editor for first-party N64 games\n"
	"Copyright (C) 2014-2019 Sauraen; components under other copyrights\n"
	"(but all GPL licensed), see their source files for details.\n"
	"\n"
	"This program is free software: you can redistribute it and/or modify\n"
	"it under the terms of the GNU General Public License as published by\n"
	"the Free Software Foundation, either version 3 of the License, or\n"
	"(at your option) any later version.\n"
	"\n"
	"This program is distributed in the hope that it will be useful,\n"
	"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
	"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
	"GNU General Public License for more details.\n"
	"\n"
	"You should have received a copy of the GNU General Public License\n"
	"along with this program.  If not, see <http://www.gnu.org/licenses/>.\n"
);
