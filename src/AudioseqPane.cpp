/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.5

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
/*
 * ============================================================================
 *
 * AudioseqPane.cpp
 * GUI component for sequence editor screen
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

#include "SeqFile.h"
//[/Headers]

#include "AudioseqPane.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
AudioseqPane::AudioseqPane(SEQ64& seq64_)
	: seq64(seq64_)
{
	//[Constructor_pre] You can add your own custom stuff here..
	//[/Constructor_pre]

	groupComponent.reset(new GroupComponent("new group",
		TRANS("Loaded Sequence")));
	addAndMakeVisible(groupComponent.get());

	groupComponent->setBounds(408, 0, 648, 672);

	groupComponent3.reset(new GroupComponent("new group",
		TRANS("Command Editor")));
	addAndMakeVisible(groupComponent3.get());

	groupComponent3->setBounds(0, 0, 400, 672);

	groupComponent6.reset(new GroupComponent("new group",
		TRANS("Edit Parameter")));
	addAndMakeVisible(groupComponent6.get());

	groupComponent6->setBounds(152, 456, 240, 208);

	groupComponent5.reset(new GroupComponent("new group",
		TRANS("Valid in")));
	addAndMakeVisible(groupComponent5.get());

	groupComponent5->setBounds(280, 352, 112, 96);

	label10.reset(new Label("new label",
		TRANS("Command:")));
	addAndMakeVisible(label10.get());
	label10->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
	label10->setJustificationType(Justification::centredLeft);
	label10->setEditable(false, false, false);
	label10->setColour(TextEditor::textColourId, Colours::black);
	label10->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	label10->setBounds(8, 392, 80, 24);

	txtCmd.reset(new TextEditor("new text editor"));
	addAndMakeVisible(txtCmd.get());
	txtCmd->setMultiLine(false);
	txtCmd->setReturnKeyStartsNewLine(false);
	txtCmd->setReadOnly(false);
	txtCmd->setScrollbarsShown(true);
	txtCmd->setCaretVisible(true);
	txtCmd->setPopupMenuEnabled(true);
	txtCmd->setText(String());

	txtCmd->setBounds(96, 392, 48, 24);

	btnCmdAdd.reset(new TextButton("new button"));
	addAndMakeVisible(btnCmdAdd.get());
	btnCmdAdd->setButtonText(TRANS("Add"));
	btnCmdAdd->setConnectedEdges(Button::ConnectedOnBottom);
	btnCmdAdd->addListener(this);

	btnCmdAdd->setBounds(352, 16, 40, 24);

	btnCmdDel.reset(new TextButton("new button"));
	addAndMakeVisible(btnCmdDel.get());
	btnCmdDel->setButtonText(TRANS("Del"));
	btnCmdDel->setConnectedEdges(Button::ConnectedOnTop);
	btnCmdDel->addListener(this);

	btnCmdDel->setBounds(352, 40, 40, 24);

	optCmdDataFixed.reset(new ToggleButton("new toggle button"));
	addAndMakeVisible(optCmdDataFixed.get());
	optCmdDataFixed->setButtonText(TRANS("Fixed"));
	optCmdDataFixed->setRadioGroupId(1);
	optCmdDataFixed->addListener(this);
	optCmdDataFixed->setToggleState(true, dontSendNotification);

	optCmdDataFixed->setBounds(160, 544, 71, 24);

	optCmdDataVar.reset(new ToggleButton("new toggle button"));
	addAndMakeVisible(optCmdDataVar.get());
	optCmdDataVar->setButtonText(TRANS("Variable"));
	optCmdDataVar->setRadioGroupId(1);
	optCmdDataVar->addListener(this);

	optCmdDataVar->setBounds(160, 568, 72, 24);

	lblCmdDataSize.reset(new Label("new label",
		TRANS("length")));
	addAndMakeVisible(lblCmdDataSize.get());
	lblCmdDataSize->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
	lblCmdDataSize->setJustificationType(Justification::centredLeft);
	lblCmdDataSize->setEditable(false, false, false);
	lblCmdDataSize->setColour(TextEditor::textColourId, Colours::black);
	lblCmdDataSize->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	lblCmdDataSize->setBounds(240, 552, 47, 24);

	txtCmdDataSize.reset(new TextEditor("txtCmdDat"));
	addAndMakeVisible(txtCmdDataSize.get());
	txtCmdDataSize->setMultiLine(false);
	txtCmdDataSize->setReturnKeyStartsNewLine(false);
	txtCmdDataSize->setReadOnly(false);
	txtCmdDataSize->setScrollbarsShown(true);
	txtCmdDataSize->setCaretVisible(true);
	txtCmdDataSize->setPopupMenuEnabled(true);
	txtCmdDataSize->setText(TRANS("1"));

	txtCmdDataSize->setBounds(288, 552, 32, 24);

	label11.reset(new Label("new label",
		TRANS("(dec)")));
	addAndMakeVisible(label11.get());
	label11->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
	label11->setJustificationType(Justification::centredLeft);
	label11->setEditable(false, false, false);
	label11->setColour(TextEditor::textColourId, Colours::black);
	label11->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	label11->setBounds(320, 552, 48, 24);

	label2.reset(new Label("new label",
		TRANS("Action:")));
	addAndMakeVisible(label2.get());
	label2->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
	label2->setJustificationType(Justification::centredLeft);
	label2->setEditable(false, false, false);
	label2->setColour(TextEditor::textColourId, Colours::black);
	label2->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	label2->setBounds(8, 424, 56, 24);

	cbxAction.reset(new ComboBox("Action"));
	addAndMakeVisible(cbxAction.get());
	cbxAction->setEditableText(false);
	cbxAction->setJustificationType(Justification::centredLeft);
	cbxAction->setTextWhenNothingSelected(String());
	cbxAction->setTextWhenNoChoicesAvailable(TRANS("(no choices)"));
	cbxAction->addItem(TRANS("No Action"), 1);
	cbxAction->addItem(TRANS("End of Data"), 2);
	cbxAction->addItem(TRANS("Timestamp"), 3);
	cbxAction->addItem(TRANS("Jump Same Level"), 4);
	cbxAction->addItem(TRANS("Call Same Level"), 5);
	cbxAction->addItem(TRANS("Loop Start"), 6);
	cbxAction->addItem(TRANS("Loop End"), 7);
	cbxAction->addItem(TRANS("Ptr Channel Header"), 8);
	cbxAction->addItem(TRANS("Ptr Track Data"), 9);
	cbxAction->addItem(TRANS("Sequence Format"), 10);
	cbxAction->addItem(TRANS("Sequence Type"), 11);
	cbxAction->addItem(TRANS("Channel Enable"), 12);
	cbxAction->addItem(TRANS("Channel Disable"), 13);
	cbxAction->addItem(TRANS("Master Volume"), 14);
	cbxAction->addItem(TRANS("Tempo"), 15);
	cbxAction->addItem(TRANS("Chn Reset"), 16);
	cbxAction->addItem(TRANS("Chn Priority"), 17);
	cbxAction->addItem(TRANS("Chn Volume"), 18);
	cbxAction->addItem(TRANS("Chn Pan"), 19);
	cbxAction->addItem(TRANS("Chn Effects"), 20);
	cbxAction->addItem(TRANS("Chn Vibrato"), 21);
	cbxAction->addItem(TRANS("Chn Pitch Bend"), 22);
	cbxAction->addItem(TRANS("Chn Instrument"), 23);
	cbxAction->addItem(TRANS("Chn Transpose"), 24);
	cbxAction->addItem(TRANS("Layer Transpose"), 25);
	cbxAction->addItem(TRANS("Track Note"), 26);
	cbxAction->addListener(this);

	cbxAction->setBounds(64, 424, 208, 24);

	label9.reset(new Label("new label",
		TRANS("Name:")));
	addAndMakeVisible(label9.get());
	label9->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
	label9->setJustificationType(Justification::centredLeft);
	label9->setEditable(false, false, false);
	label9->setColour(TextEditor::textColourId, Colours::black);
	label9->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	label9->setBounds(8, 360, 55, 24);

	txtCmdName.reset(new TextEditor("new text editor"));
	addAndMakeVisible(txtCmdName.get());
	txtCmdName->setMultiLine(false);
	txtCmdName->setReturnKeyStartsNewLine(false);
	txtCmdName->setReadOnly(false);
	txtCmdName->setScrollbarsShown(true);
	txtCmdName->setCaretVisible(true);
	txtCmdName->setPopupMenuEnabled(true);
	txtCmdName->setText(String());

	txtCmdName->setBounds(64, 360, 208, 24);

	txtCmdEnd.reset(new TextEditor("new text editor"));
	addAndMakeVisible(txtCmdEnd.get());
	txtCmdEnd->setMultiLine(false);
	txtCmdEnd->setReturnKeyStartsNewLine(false);
	txtCmdEnd->setReadOnly(false);
	txtCmdEnd->setScrollbarsShown(true);
	txtCmdEnd->setCaretVisible(true);
	txtCmdEnd->setPopupMenuEnabled(true);
	txtCmdEnd->setText(String());

	txtCmdEnd->setBounds(176, 392, 48, 24);

	label12.reset(new Label("new label",
		TRANS("to")));
	addAndMakeVisible(label12.get());
	label12->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
	label12->setJustificationType(Justification::centredLeft);
	label12->setEditable(false, false, false);
	label12->setColour(TextEditor::textColourId, Colours::black);
	label12->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	label12->setBounds(152, 392, 23, 24);

	optCmdSeq.reset(new ToggleButton("new toggle button"));
	addAndMakeVisible(optCmdSeq.get());
	optCmdSeq->setButtonText(TRANS("Seq header"));
	optCmdSeq->addListener(this);

	optCmdSeq->setBounds(288, 368, 103, 24);

	optCmdChn.reset(new ToggleButton("new toggle button"));
	addAndMakeVisible(optCmdChn.get());
	optCmdChn->setButtonText(TRANS("Chn header"));
	optCmdChn->addListener(this);

	optCmdChn->setBounds(288, 392, 104, 24);

	optCmdTrk.reset(new ToggleButton("new toggle button"));
	addAndMakeVisible(optCmdTrk.get());
	optCmdTrk->setButtonText(TRANS("Track data"));
	optCmdTrk->addListener(this);

	optCmdTrk->setBounds(288, 416, 104, 24);

	label13.reset(new Label("new label",
		TRANS("Parameters:")));
	addAndMakeVisible(label13.get());
	label13->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
	label13->setJustificationType(Justification::centredLeft);
	label13->setEditable(false, false, false);
	label13->setColour(TextEditor::textColourId, Colours::black);
	label13->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	label13->setBounds(8, 456, 104, 24);

	btnParamAdd.reset(new TextButton("new button"));
	addAndMakeVisible(btnParamAdd.get());
	btnParamAdd->setButtonText(TRANS("Add"));
	btnParamAdd->setConnectedEdges(Button::ConnectedOnBottom);
	btnParamAdd->addListener(this);

	btnParamAdd->setBounds(104, 480, 40, 24);

	btnParamDel.reset(new TextButton("new button"));
	addAndMakeVisible(btnParamDel.get());
	btnParamDel->setButtonText(TRANS("Del"));
	btnParamDel->setConnectedEdges(Button::ConnectedOnTop);
	btnParamDel->addListener(this);

	btnParamDel->setBounds(104, 504, 40, 24);

	btnParamUp.reset(new TextButton("new button"));
	addAndMakeVisible(btnParamUp.get());
	btnParamUp->setButtonText(TRANS("Up"));
	btnParamUp->setConnectedEdges(Button::ConnectedOnBottom);
	btnParamUp->addListener(this);

	btnParamUp->setBounds(104, 616, 40, 24);

	btnParamDn.reset(new TextButton("new button"));
	addAndMakeVisible(btnParamDn.get());
	btnParamDn->setButtonText(TRANS("Dn"));
	btnParamDn->setConnectedEdges(Button::ConnectedOnTop);
	btnParamDn->addListener(this);

	btnParamDn->setBounds(104, 640, 40, 24);

	optCmdOffset.reset(new ToggleButton("new toggle button"));
	addAndMakeVisible(optCmdOffset.get());
	optCmdOffset->setButtonText(TRANS("Cmd Offset (no data)"));
	optCmdOffset->setRadioGroupId(1);
	optCmdOffset->addListener(this);

	optCmdOffset->setBounds(160, 520, 160, 24);

	label14.reset(new Label("new label",
		TRANS("Data source:")));
	addAndMakeVisible(label14.get());
	label14->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
	label14->setJustificationType(Justification::centredLeft);
	label14->setEditable(false, false, false);
	label14->setColour(TextEditor::textColourId, Colours::black);
	label14->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	label14->setBounds(160, 496, 224, 24);

	label15.reset(new Label("new label",
		TRANS("Meaning:")));
	addAndMakeVisible(label15.get());
	label15->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
	label15->setJustificationType(Justification::centredLeft);
	label15->setEditable(false, false, false);
	label15->setColour(TextEditor::textColourId, Colours::black);
	label15->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	label15->setBounds(160, 592, 72, 24);

	txtParamName.reset(new TextEditor("new text editor"));
	addAndMakeVisible(txtParamName.get());
	txtParamName->setMultiLine(false);
	txtParamName->setReturnKeyStartsNewLine(false);
	txtParamName->setReadOnly(false);
	txtParamName->setScrollbarsShown(true);
	txtParamName->setCaretVisible(true);
	txtParamName->setPopupMenuEnabled(true);
	txtParamName->setText(String());

	txtParamName->setBounds(216, 472, 166, 24);

	label16.reset(new Label("new label",
		TRANS("Name:")));
	addAndMakeVisible(label16.get());
	label16->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
	label16->setJustificationType(Justification::centredLeft);
	label16->setEditable(false, false, false);
	label16->setColour(TextEditor::textColourId, Colours::black);
	label16->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	label16->setBounds(160, 472, 55, 24);

	cbxMeaning.reset(new ComboBox("Meaning"));
	addAndMakeVisible(cbxMeaning.get());
	cbxMeaning->setEditableText(false);
	cbxMeaning->setJustificationType(Justification::centredLeft);
	cbxMeaning->setTextWhenNothingSelected(String());
	cbxMeaning->setTextWhenNoChoicesAvailable(TRANS("(no choices)"));
	cbxMeaning->addListener(this);

	cbxMeaning->setBounds(232, 592, 150, 24);

	label17.reset(new Label("new label",
		TRANS("Add (dec):")));
	addAndMakeVisible(label17.get());
	label17->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
	label17->setJustificationType(Justification::centredLeft);
	label17->setEditable(false, false, false);
	label17->setColour(TextEditor::textColourId, Colours::black);
	label17->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	label17->setBounds(160, 624, 64, 24);

	label18.reset(new Label("new label",
		TRANS("Multiply:")));
	addAndMakeVisible(label18.get());
	label18->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
	label18->setJustificationType(Justification::centredLeft);
	label18->setEditable(false, false, false);
	label18->setColour(TextEditor::textColourId, Colours::black);
	label18->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	label18->setBounds(272, 624, 64, 24);

	txtParamAdd.reset(new TextEditor("new text editor"));
	addAndMakeVisible(txtParamAdd.get());
	txtParamAdd->setMultiLine(false);
	txtParamAdd->setReturnKeyStartsNewLine(false);
	txtParamAdd->setReadOnly(false);
	txtParamAdd->setScrollbarsShown(true);
	txtParamAdd->setCaretVisible(true);
	txtParamAdd->setPopupMenuEnabled(true);
	txtParamAdd->setText(TRANS("0"));

	txtParamAdd->setBounds(224, 624, 47, 24);

	txtParamMult.reset(new TextEditor("new text editor"));
	addAndMakeVisible(txtParamMult.get());
	txtParamMult->setMultiLine(false);
	txtParamMult->setReturnKeyStartsNewLine(false);
	txtParamMult->setReadOnly(false);
	txtParamMult->setScrollbarsShown(true);
	txtParamMult->setCaretVisible(true);
	txtParamMult->setPopupMenuEnabled(true);
	txtParamMult->setText(TRANS("1.0"));

	txtParamMult->setBounds(336, 624, 47, 24);

	btnCmdUp.reset(new TextButton("new button"));
	addAndMakeVisible(btnCmdUp.get());
	btnCmdUp->setButtonText(TRANS("Up"));
	btnCmdUp->setConnectedEdges(Button::ConnectedOnBottom);
	btnCmdUp->addListener(this);

	btnCmdUp->setBounds(352, 296, 40, 24);

	btnCmdDn.reset(new TextButton("new button"));
	addAndMakeVisible(btnCmdDn.get());
	btnCmdDn->setButtonText(TRANS("Dn"));
	btnCmdDn->setConnectedEdges(Button::ConnectedOnTop);
	btnCmdDn->addListener(this);

	btnCmdDn->setBounds(352, 320, 40, 24);

	label3.reset(new Label("new label",
		TRANS("@Addr: Typ Ch Ly Events")));
	addAndMakeVisible(label3.get());
	label3->setFont(Font(Font::getDefaultMonospacedFontName(), 14.00f, Font::plain));
	label3->setJustificationType(Justification::centredLeft);
	label3->setEditable(false, false, false);
	label3->setColour(TextEditor::textColourId, Colours::black);
	label3->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	label3->setBounds(416, 88, 192, 24);

	label4.reset(new Label("new label",
		TRANS("@Addr: Data           Command")));
	addAndMakeVisible(label4.get());
	label4->setFont(Font(Font::getDefaultMonospacedFontName(), 14.00f, Font::plain));
	label4->setJustificationType(Justification::centredLeft);
	label4->setEditable(false, false, false);
	label4->setColour(TextEditor::textColourId, Colours::black);
	label4->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	label4->setBounds(696, 16, 352, 24);

	btnSeqCmdAdd.reset(new TextButton("new button"));
	addAndMakeVisible(btnSeqCmdAdd.get());
	btnSeqCmdAdd->setButtonText(TRANS("Add"));
	btnSeqCmdAdd->setConnectedEdges(Button::ConnectedOnLeft | Button::ConnectedOnRight);
	btnSeqCmdAdd->addListener(this);

	btnSeqCmdAdd->setBounds(880, 560, 40, 24);

	btnSeqCmdDelete.reset(new TextButton("new button"));
	addAndMakeVisible(btnSeqCmdDelete.get());
	btnSeqCmdDelete->setButtonText(TRANS("Del"));
	btnSeqCmdDelete->setConnectedEdges(Button::ConnectedOnLeft);
	btnSeqCmdDelete->addListener(this);

	btnSeqCmdDelete->setBounds(920, 560, 40, 24);

	btnSeqCmdUp.reset(new TextButton("new button"));
	addAndMakeVisible(btnSeqCmdUp.get());
	btnSeqCmdUp->setButtonText(TRANS("Up"));
	btnSeqCmdUp->setConnectedEdges(Button::ConnectedOnRight);
	btnSeqCmdUp->addListener(this);

	btnSeqCmdUp->setBounds(968, 560, 40, 24);

	btnSeqCmdDn.reset(new TextButton("new button"));
	addAndMakeVisible(btnSeqCmdDn.get());
	btnSeqCmdDn->setButtonText(TRANS("Dn"));
	btnSeqCmdDn->setConnectedEdges(Button::ConnectedOnLeft);
	btnSeqCmdDn->addListener(this);

	btnSeqCmdDn->setBounds(1008, 560, 40, 24);

	cbxSeqCmdType.reset(new ComboBox("new combo box"));
	addAndMakeVisible(cbxSeqCmdType.get());
	cbxSeqCmdType->setEditableText(false);
	cbxSeqCmdType->setJustificationType(Justification::centredLeft);
	cbxSeqCmdType->setTextWhenNothingSelected(TRANS("[Command to add]"));
	cbxSeqCmdType->setTextWhenNoChoicesAvailable(TRANS("(no choices)"));
	cbxSeqCmdType->addListener(this);

	cbxSeqCmdType->setBounds(696, 560, 184, 24);

	label7.reset(new Label("new label",
		TRANS("Value:")));
	addAndMakeVisible(label7.get());
	label7->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
	label7->setJustificationType(Justification::centredLeft);
	label7->setEditable(false, false, false);
	label7->setColour(TextEditor::textColourId, Colours::black);
	label7->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	label7->setBounds(888, 616, 64, 24);

	txtSeqCmdValue.reset(new TextEditor("new text editor"));
	addAndMakeVisible(txtSeqCmdValue.get());
	txtSeqCmdValue->setMultiLine(false);
	txtSeqCmdValue->setReturnKeyStartsNewLine(false);
	txtSeqCmdValue->setReadOnly(false);
	txtSeqCmdValue->setScrollbarsShown(true);
	txtSeqCmdValue->setCaretVisible(true);
	txtSeqCmdValue->setPopupMenuEnabled(true);
	txtSeqCmdValue->setText(String());

	txtSeqCmdValue->setBounds(952, 616, 88, 24);

	lblSeqInfo.reset(new Label("new label",
		TRANS("Sequence information")));
	addAndMakeVisible(lblSeqInfo.get());
	lblSeqInfo->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
	lblSeqInfo->setJustificationType(Justification::topLeft);
	lblSeqInfo->setEditable(false, false, false);
	lblSeqInfo->setColour(TextEditor::textColourId, Colours::black);
	lblSeqInfo->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	lblSeqInfo->setBounds(416, 16, 272, 16);

	lblSeqCmdAction.reset(new Label("new label",
		TRANS("Command Action:")));
	addAndMakeVisible(lblSeqCmdAction.get());
	lblSeqCmdAction->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
	lblSeqCmdAction->setJustificationType(Justification::centredLeft);
	lblSeqCmdAction->setEditable(false, false, false);
	lblSeqCmdAction->setColour(TextEditor::textColourId, Colours::black);
	lblSeqCmdAction->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	lblSeqCmdAction->setBounds(696, 592, 352, 24);

	lblValueEquiv.reset(new Label("new label",
		TRANS("[dec, note equiv.]")));
	addAndMakeVisible(lblValueEquiv.get());
	lblValueEquiv->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
	lblValueEquiv->setJustificationType(Justification::centredLeft);
	lblValueEquiv->setEditable(false, false, false);
	lblValueEquiv->setColour(TextEditor::textColourId, Colours::black);
	lblValueEquiv->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	lblValueEquiv->setBounds(888, 640, 152, 24);

	lblSeqCmdAction2.reset(new Label("new label",
		TRANS("Sections:")));
	addAndMakeVisible(lblSeqCmdAction2.get());
	lblSeqCmdAction2->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
	lblSeqCmdAction2->setJustificationType(Justification::centredLeft);
	lblSeqCmdAction2->setEditable(false, false, false);
	lblSeqCmdAction2->setColour(TextEditor::textColourId, Colours::black);
	lblSeqCmdAction2->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	lblSeqCmdAction2->setBounds(416, 64, 120, 24);

	btnReParse.reset(new TextButton("new button"));
	addAndMakeVisible(btnReParse.get());
	btnReParse->setButtonText(TRANS("Re-Parse"));
	btnReParse->addListener(this);

	btnReParse->setBounds(608, 88, 80, 24);

	btnSaveRaw.reset(new TextButton("new button"));
	addAndMakeVisible(btnSaveRaw.get());
	btnSaveRaw->setButtonText(TRANS("Save Raw"));
	btnSaveRaw->setConnectedEdges(Button::ConnectedOnRight);
	btnSaveRaw->addListener(this);

	btnSaveRaw->setBounds(416, 40, 136, 24);

	btnLoadRaw.reset(new TextButton("new button"));
	addAndMakeVisible(btnLoadRaw.get());
	btnLoadRaw->setButtonText(TRANS("Load Raw"));
	btnLoadRaw->setConnectedEdges(Button::ConnectedOnLeft);
	btnLoadRaw->addListener(this);

	btnLoadRaw->setBounds(552, 40, 136, 24);


	//[UserPreSize]

	lsmCommands.reset(new TextListModel());
	lsmCommands->setListener(this);

	lstCommands.reset(new ListBox("Commands", lsmCommands.get()));
	addAndMakeVisible(lstCommands.get());
	lstCommands->setMultipleSelectionEnabled(false);
	lstCommands->setRowHeight(16);
	lstCommands->setOutlineThickness(1);
	lstCommands->setColour(ListBox::outlineColourId, Colours::lightgrey);

	lsmParameters.reset(new TextListModel());
	lsmParameters->setListener(this);

	lstParameters.reset(new ListBox("Parameters", lsmParameters.get()));
	addAndMakeVisible(lstParameters.get());
	lstParameters->setMultipleSelectionEnabled(false);
	lstParameters->setRowHeight(16);
	lstParameters->setOutlineThickness(1);
	lstParameters->setColour(ListBox::outlineColourId, Colours::lightgrey);

	lsmSeqSections.reset(new TextListModel());
	lsmSeqSections->setListener(this);
	lsmSeqSections->setFont(Font(Font::getDefaultMonospacedFontName(), 14.00f, Font::plain));

	lstSeqSections.reset(new ListBox("SeqSections", lsmSeqSections.get()));
	addAndMakeVisible(lstSeqSections.get());
	lstSeqSections->setMultipleSelectionEnabled(false);
	lstSeqSections->setRowHeight(16);
	lstSeqSections->setOutlineThickness(1);
	lstSeqSections->setColour(ListBox::outlineColourId, Colours::lightgrey);

	lsmSeqCommands.reset(new TextListModel());
	lsmSeqCommands->setListener(this);
	lsmSeqCommands->setFont(Font(Font::getDefaultMonospacedFontName(), 14.00f, Font::plain));

	lstSeqCommands.reset(new ListBox("SeqCommands", lsmSeqCommands.get()));
	addAndMakeVisible(lstSeqCommands.get());
	lstSeqCommands->setMultipleSelectionEnabled(false);
	lstSeqCommands->setRowHeight(16);
	lstSeqCommands->setOutlineThickness(1);
	lstSeqCommands->setColour(ListBox::outlineColourId, Colours::lightgrey);

	lsmSeqCmdParams.reset(new TextListModel());
	lsmSeqCmdParams->setListener(this);

	lstSeqCmdParams.reset(new ListBox("SeqCmdParams", lsmSeqCmdParams.get()));
	addAndMakeVisible(lstSeqCmdParams.get());
	lstSeqCmdParams->setMultipleSelectionEnabled(false);
	lstSeqCmdParams->setRowHeight(16);
	lstSeqCmdParams->setOutlineThickness(1);
	lstSeqCmdParams->setColour(ListBox::outlineColourId, Colours::lightgrey);


	txtCmdName->addListener(this);
	txtCmd->addListener(this);
	txtCmdEnd->addListener(this);
	txtParamName->addListener(this);
	txtCmdDataSize->addListener(this);
	txtParamAdd->addListener(this);
	txtParamMult->addListener(this);
	txtSeqCmdValue->addListener(this);


	//[/UserPreSize]

	setSize(1078, 713);


	//[Constructor] You can add your own custom stuff here..
	//[/Constructor]
}

AudioseqPane::~AudioseqPane()
{
	//[Destructor_pre]. You can add your own custom destruction code here..
	//[/Destructor_pre]

	groupComponent = nullptr;
	groupComponent3 = nullptr;
	groupComponent6 = nullptr;
	groupComponent5 = nullptr;
	label10 = nullptr;
	txtCmd = nullptr;
	btnCmdAdd = nullptr;
	btnCmdDel = nullptr;
	optCmdDataFixed = nullptr;
	optCmdDataVar = nullptr;
	lblCmdDataSize = nullptr;
	txtCmdDataSize = nullptr;
	label11 = nullptr;
	label2 = nullptr;
	cbxAction = nullptr;
	label9 = nullptr;
	txtCmdName = nullptr;
	txtCmdEnd = nullptr;
	label12 = nullptr;
	optCmdSeq = nullptr;
	optCmdChn = nullptr;
	optCmdTrk = nullptr;
	label13 = nullptr;
	btnParamAdd = nullptr;
	btnParamDel = nullptr;
	btnParamUp = nullptr;
	btnParamDn = nullptr;
	optCmdOffset = nullptr;
	label14 = nullptr;
	label15 = nullptr;
	txtParamName = nullptr;
	label16 = nullptr;
	cbxMeaning = nullptr;
	label17 = nullptr;
	label18 = nullptr;
	txtParamAdd = nullptr;
	txtParamMult = nullptr;
	btnCmdUp = nullptr;
	btnCmdDn = nullptr;
	label3 = nullptr;
	label4 = nullptr;
	btnSeqCmdAdd = nullptr;
	btnSeqCmdDelete = nullptr;
	btnSeqCmdUp = nullptr;
	btnSeqCmdDn = nullptr;
	cbxSeqCmdType = nullptr;
	label7 = nullptr;
	txtSeqCmdValue = nullptr;
	lblSeqInfo = nullptr;
	lblSeqCmdAction = nullptr;
	lblValueEquiv = nullptr;
	lblSeqCmdAction2 = nullptr;
	btnReParse = nullptr;
	btnSaveRaw = nullptr;
	btnLoadRaw = nullptr;


	//[Destructor]. You can add your own custom destruction code here..
	lstCommands = nullptr;
	lstParameters = nullptr;
	lstSeqSections = nullptr;
	lstSeqCommands = nullptr;
	lstSeqCmdParams = nullptr;
	lsmCommands = nullptr;
	lsmParameters = nullptr;
	lsmSeqSections = nullptr;
	lsmSeqCommands = nullptr;
	lsmSeqCmdParams = nullptr;
	//[/Destructor]
}

//==============================================================================
void AudioseqPane::paint(Graphics& g)
{
	//[UserPrePaint] Add your own custom painting code here..
	//[/UserPrePaint]

	g.fillAll(Colour(0xff323e44));

	//[UserPaint] Add your own custom painting code here..
	//[/UserPaint]
}

void AudioseqPane::resized()
{
	//[UserPreResize] Add your own custom resize code here..
	//[/UserPreResize]

	//[UserResized] Add your own custom resize handling here..

	lstCommands->setBounds(8, 16, 336, 328);
	lstParameters->setBounds(8, 480, 88, 184);
	lstSeqSections->setBounds(416, 112, 272, 552);
	lstSeqCommands->setBounds(696, 40, 352, 520);
	lstSeqCmdParams->setBounds(696, 616, 184, 48);

	//[/UserResized]
}

void AudioseqPane::buttonClicked(Button* buttonThatWasClicked)
{
	//[UserbuttonClicked_Pre]
	//[/UserbuttonClicked_Pre]

	if (buttonThatWasClicked == btnCmdAdd.get())
	{
		//[UserButtonCode_btnCmdAdd] -- add your button handler code here..
		ValueTree cmdlistnode = seq64.romdesc.getOrCreateChildWithName("cmdlist", nullptr);
		ValueTree cmd("command");
		cmd.setProperty("cmd", 0, nullptr);
		cmd.setProperty("name", "Unnamed", nullptr);
		cmd.setProperty("action", "No Action", nullptr);
		cmdlistnode.addChild(cmd, cmdlistnode.getNumChildren(), nullptr);
		refreshCmdList();
		lstCommands->selectRow(lsmCommands->getNumRows() - 1);
		//[/UserButtonCode_btnCmdAdd]
	}
	else if (buttonThatWasClicked == btnCmdDel.get())
	{
		//[UserButtonCode_btnCmdDel] -- add your button handler code here..
		int pos = lstCommands->getLastRowSelected();
		if (pos >= 0) {
			seq64.romdesc.getChildWithName("cmdlist").removeChild(pos, nullptr);
			refreshCmdList();
			lstCommands->selectRow(-1);
		}
		//[/UserButtonCode_btnCmdDel]
	}
	else if (buttonThatWasClicked == optCmdDataFixed.get())
	{
		//[UserButtonCode_optCmdDataFixed] -- add your button handler code here..
		if (selparam.isValid()) {
			selparam.setProperty("datasrc", "fixed", nullptr);
			lblCmdDataSize->setText("length", dontSendNotification);
		}
		//[/UserButtonCode_optCmdDataFixed]
	}
	else if (buttonThatWasClicked == optCmdDataVar.get())
	{
		//[UserButtonCode_optCmdDataVar] -- add your button handler code here..
		if (selparam.isValid()) {
			selparam.setProperty("datasrc", "variable", nullptr);
			lblCmdDataSize->setText("up to", dontSendNotification);
		}
		//[/UserButtonCode_optCmdDataVar]
	}
	else if (buttonThatWasClicked == optCmdSeq.get())
	{
		//[UserButtonCode_optCmdSeq] -- add your button handler code here..
		if (selcmd.isValid()) {
			selcmd.setProperty("validinseq", optCmdSeq->getToggleState(), nullptr);
		}
		//[/UserButtonCode_optCmdSeq]
	}
	else if (buttonThatWasClicked == optCmdChn.get())
	{
		//[UserButtonCode_optCmdChn] -- add your button handler code here..
		if (selcmd.isValid()) {
			selcmd.setProperty("validinchn", optCmdChn->getToggleState(), nullptr);
		}
		//[/UserButtonCode_optCmdChn]
	}
	else if (buttonThatWasClicked == optCmdTrk.get())
	{
		//[UserButtonCode_optCmdTrk] -- add your button handler code here..
		if (selcmd.isValid()) {
			selcmd.setProperty("validintrk", optCmdTrk->getToggleState(), nullptr);
		}
		//[/UserButtonCode_optCmdTrk]
	}
	else if (buttonThatWasClicked == btnParamAdd.get())
	{
		//[UserButtonCode_btnParamAdd] -- add your button handler code here..
		if (!selcmd.isValid()) return;
		ValueTree param("parameter");
		param.setProperty("datasrc", "fixed", nullptr);
		param.setProperty("datalen", 0, nullptr);
		param.setProperty("name", "Unnamed", nullptr);
		param.setProperty("meaning", "None", nullptr);
		param.setProperty("add", 0, nullptr);
		param.setProperty("multiply", 1.0f, nullptr);
		selcmd.addChild(param, selcmd.getNumChildren(), nullptr);
		refreshParamList();
		lstParameters->selectRow(lsmParameters->getNumRows() - 1);
		//[/UserButtonCode_btnParamAdd]
	}
	else if (buttonThatWasClicked == btnParamDel.get())
	{
		//[UserButtonCode_btnParamDel] -- add your button handler code here..
		int pos = lstParameters->getLastRowSelected();
		if (pos >= 0) {
			selcmd.removeChild(pos, nullptr);
			refreshParamList();
			lstParameters->selectRow(-1);
		}
		//[/UserButtonCode_btnParamDel]
	}
	else if (buttonThatWasClicked == btnParamUp.get())
	{
		//[UserButtonCode_btnParamUp] -- add your button handler code here..
		int pos = lstParameters->getLastRowSelected();
		if (pos > 0) {
			selcmd.moveChild(pos, pos - 1, nullptr);
			refreshParamList();
			lstParameters->selectRow(pos - 1);
		}
		//[/UserButtonCode_btnParamUp]
	}
	else if (buttonThatWasClicked == btnParamDn.get())
	{
		//[UserButtonCode_btnParamDn] -- add your button handler code here..
		int pos = lstParameters->getLastRowSelected();
		if (pos >= 0 && pos < lsmParameters->getNumRows() - 1) {
			selcmd.moveChild(pos, pos + 1, nullptr);
			refreshParamList();
			lstParameters->selectRow(pos + 1);
		}
		//[/UserButtonCode_btnParamDn]
	}
	else if (buttonThatWasClicked == optCmdOffset.get())
	{
		//[UserButtonCode_optCmdOffset] -- add your button handler code here..
		if (selparam.isValid()) {
			selparam.setProperty("datasrc", "offset", nullptr);
			txtCmdDataSize->setText("");
			lblCmdDataSize->setText("(none)", dontSendNotification);
		}
		//[/UserButtonCode_optCmdOffset]
	}
	else if (buttonThatWasClicked == btnCmdUp.get())
	{
		//[UserButtonCode_btnCmdUp] -- add your button handler code here..
		int pos = lstCommands->getLastRowSelected();
		if (pos > 0) {
			seq64.romdesc.getChildWithName("cmdlist").moveChild(pos, pos - 1, nullptr);
			refreshCmdList();
			lstCommands->selectRow(pos - 1);
		}
		//[/UserButtonCode_btnCmdUp]
	}
	else if (buttonThatWasClicked == btnCmdDn.get())
	{
		//[UserButtonCode_btnCmdDn] -- add your button handler code here..
		int pos = lstCommands->getLastRowSelected();
		if (pos >= 0 && pos < lsmCommands->getNumRows() - 1) {
			seq64.romdesc.getChildWithName("cmdlist").moveChild(pos, pos + 1, nullptr);
			refreshCmdList();
			lstCommands->selectRow(pos + 1);
		}
		//[/UserButtonCode_btnCmdDn]
	}
	else if (buttonThatWasClicked == btnSeqCmdAdd.get())
	{
		//[UserButtonCode_btnSeqCmdAdd] -- add your button handler code here..
		if (&*seq64.seq == nullptr) return;
		int selsec = lstSeqSections->getLastRowSelected();
		if (selsec < 0 || selsec >= seq64.seq->getNumSections()) return;
		SeqData* section = seq64.seq->getSection(selsec);
		int selcmdidx = lstSeqCommands->getLastRowSelected();
		if (selcmdidx < 0 || selcmdidx >= section->cmdoffsets.size()) return;
		uint32 cmdaddr = section->cmdoffsets[selcmdidx];
		//Calculate the number of bytes to add
		ValueTree cmdlistnode = seq64.romdesc.getOrCreateChildWithName("cmdlist", nullptr);
		ValueTree cmd = cmdlistnode.getChildWithProperty("name", cbxSeqCmdType->getText());
		if (!cmd.isValid()) {
			SEQ64::say("No command found with name " + cbxSeqCmdType->getText() + "!");
			return;
		}
		int bytesToAdd = 1;
		ValueTree param;
		String datasrc;
		int datalen;
		for (int i = 0; i < cmd.getNumChildren(); i++) {
			param = cmd.getChild(i);
			datasrc = param.getProperty("datasrc", "fixed");
			datalen = param.getProperty("datalen", 1);
			if (datasrc == "fixed") {
				bytesToAdd += datalen;
			}
			else if (datasrc == "variable") {
				bytesToAdd += datalen - 1;
			}
		}
		SEQ64::say("Adding " + String(bytesToAdd) + " bytes @" + ROM::hex(cmdaddr, 4));
		seq64.seq->insertSpaceAt(cmdaddr, bytesToAdd, (selcmdidx != 0));
		seq64.seq->writeByte(cmdaddr, (int)cmd.getProperty("cmd", 0));
		seqStructureChanged();
		//[/UserButtonCode_btnSeqCmdAdd]
	}
	else if (buttonThatWasClicked == btnSeqCmdDelete.get())
	{
		//[UserButtonCode_btnSeqCmdDelete] -- add your button handler code here..
		if (&*seq64.seq == nullptr) return;
		int selsec = lstSeqSections->getLastRowSelected();
		if (selsec < 0 || selsec >= seq64.seq->getNumSections()) return;
		SeqData* section = seq64.seq->getSection(selsec);
		int selcmdidx = lstSeqCommands->getLastRowSelected();
		if (selcmdidx < 0 || selcmdidx >= section->cmdoffsets.size()) return;
		uint32 cmdaddr = section->cmdoffsets[selcmdidx];
		ValueTree command = seq64.seq->getCommand(cmdaddr, section->stype);
		int len = command.getProperty("length", 1);
		SEQ64::say("Removing " + String(len) + " bytes @" + ROM::hex(cmdaddr, 4));
		seq64.seq->removeData(cmdaddr, len, selsec);
		seqStructureChanged();
		//[/UserButtonCode_btnSeqCmdDelete]
	}
	else if (buttonThatWasClicked == btnSeqCmdUp.get())
	{
		//[UserButtonCode_btnSeqCmdUp] -- add your button handler code here..
		if (&*seq64.seq == nullptr) return;
		int selsec = lstSeqSections->getLastRowSelected();
		if (selsec < 0 || selsec >= seq64.seq->getNumSections()) return;
		SeqData* section = seq64.seq->getSection(selsec);
		int selcmdidx = lstSeqCommands->getLastRowSelected();
		if (selcmdidx <= 0 || selcmdidx >= section->cmdoffsets.size()) return;
		seq64.seq->swapCommands(selsec, selcmdidx - 1);
		lsmSeqCommands->set(selcmdidx - 1, seq64.seq->getCommandDescription(selsec, selcmdidx - 1));
		lstSeqCommands->repaintRow(selcmdidx - 1);
		lsmSeqCommands->set(selcmdidx, seq64.seq->getCommandDescription(selsec, selcmdidx));
		lstSeqCommands->repaintRow(selcmdidx);
		lstSeqCommands->selectRow(selcmdidx - 1);
		//[/UserButtonCode_btnSeqCmdUp]
	}
	else if (buttonThatWasClicked == btnSeqCmdDn.get())
	{
		//[UserButtonCode_btnSeqCmdDn] -- add your button handler code here..
		if (&*seq64.seq == nullptr) return;
		int selsec = lstSeqSections->getLastRowSelected();
		if (selsec < 0 || selsec >= seq64.seq->getNumSections()) return;
		SeqData* section = seq64.seq->getSection(selsec);
		int selcmdidx = lstSeqCommands->getLastRowSelected();
		if (selcmdidx < 0 || selcmdidx >= section->cmdoffsets.size() - 1) return;
		seq64.seq->swapCommands(selsec, selcmdidx);
		lsmSeqCommands->set(selcmdidx, seq64.seq->getCommandDescription(selsec, selcmdidx));
		lstSeqCommands->repaintRow(selcmdidx);
		lsmSeqCommands->set(selcmdidx + 1, seq64.seq->getCommandDescription(selsec, selcmdidx + 1));
		lstSeqCommands->repaintRow(selcmdidx + 1);
		lstSeqCommands->selectRow(selcmdidx + 1);
		//[/UserButtonCode_btnSeqCmdDn]
	}
	else if (buttonThatWasClicked == btnReParse.get())
	{
		//[UserButtonCode_btnReParse] -- add your button handler code here..
		seqStructureChanged();
		//[/UserButtonCode_btnReParse]
	}
	else if (buttonThatWasClicked == btnSaveRaw.get())
	{
		//[UserButtonCode_btnSaveRaw] -- add your button handler code here..
		Identifier idRawSeq = "understandrawsequence";
		if (&*seq64.seq == nullptr) return;
		if (seq64.readProperty(idRawSeq) != "yes") {
			if (!NativeMessageBox::showOkCancelBox(AlertWindow::WarningIcon,
				"Are you sure you know what you're doing?",
				"This just saves a raw binary copy of the current\n"
				"sequence data below. This will be most likely incompatible\n"
				"with any other game, and is definitely not a MIDI.\n\n"
				"Are you sure you want to continue?", nullptr, nullptr)) return;
			seq64.writeProperty(idRawSeq, "yes");
		}
		File savelocation = SEQ64::readFolderProperty("romfolder");
		FileChooser box("Save Raw", savelocation, "*", SEQ64::useNativeFileChooser());
		if (!box.browseForFileToSave(true)) return;
		savelocation = box.getResult();
		if (!seq64.seq->saveRaw(savelocation)) {
			NativeMessageBox::showMessageBox(AlertWindow::WarningIcon, "Oh no",
				"Saving failed, check the command line output for details.");
		}
		//[/UserButtonCode_btnSaveRaw]
	}
	else if (buttonThatWasClicked == btnLoadRaw.get())
	{
		//[UserButtonCode_btnLoadRaw] -- add your button handler code here..
		Identifier idRawSeq = "understandrawsequence";
		if (seq64.readProperty(idRawSeq) != "yes") {
			if (!NativeMessageBox::showOkCancelBox(AlertWindow::WarningIcon,
				"Are you sure you know what you're doing?",
				"This just loads raw binary sequence data into the window below.\n"
				"The file you load must be a raw sequence saved from this game,\n"
				"otherwise it will almost certainly crash.\n"
				"(Also, this is NOT the Import MIDI button.)\n\n"
				"Are you sure you want to continue?", nullptr, nullptr)) return;
			seq64.writeProperty(idRawSeq, "yes");
		}
		if (!seq64.romdesc.isValid() || seq64.romdesc.getOrCreateChildWithName("cmdlist", nullptr).getNumChildren() == 0) {
			NativeMessageBox::showMessageBox(AlertWindow::WarningIcon, "Guess you didn't know what you were doing after all",
				"Load a RomDesc before trying to load a raw sequence.");
			return;
		}
		if (&*seq64.seq != nullptr) {
			if (!NativeMessageBox::showOkCancelBox(AlertWindow::WarningIcon,
				"Overwrite?",
				"A sequence is already loaded, are you sure you want to overwrite it?", nullptr, nullptr)) return;
		}
		File loadlocation = SEQ64::readFolderProperty("romfolder");
		FileChooser box("Load Raw", loadlocation, "*", SEQ64::useNativeFileChooser());
		if (!box.browseForFileToOpen()) return;
		loadlocation = box.getResult();
		seq64.seq.reset(new SeqFile(seq64.romdesc));
		if (!seq64.seq->loadRaw(loadlocation)) {
			NativeMessageBox::showMessageBox(AlertWindow::WarningIcon, "Oh no",
				"Loading failed, check the command line output for details.");
		}
		fillSeqSections();
		fillSeqCommands();
		//[/UserButtonCode_btnLoadRaw]
	}

	//[UserbuttonClicked_Post]
	//[/UserbuttonClicked_Post]
}

void AudioseqPane::comboBoxChanged(ComboBox* comboBoxThatHasChanged)
{
	//[UsercomboBoxChanged_Pre]
	//[/UsercomboBoxChanged_Pre]

	if (comboBoxThatHasChanged == cbxAction.get())
	{
		//[UserComboBoxCode_cbxAction] -- add your combo box handling code here..
		if (selcmd.isValid()) {
			String action = cbxAction->getText();
			selcmd.setProperty("action", action, nullptr);
			fillMeaningsBox(action);
			lsmCommands->set(lstCommands->getLastRowSelected(), getCommandDesc(selcmd));
			lstCommands->repaintRow(lstCommands->getLastRowSelected());
		}
		//[/UserComboBoxCode_cbxAction]
	}
	else if (comboBoxThatHasChanged == cbxMeaning.get())
	{
		//[UserComboBoxCode_cbxMeaning] -- add your combo box handling code here..
		if (selparam.isValid()) {
			String meaning = cbxMeaning->getText();
			selparam.setProperty("meaning", meaning, nullptr);
		}
		//[/UserComboBoxCode_cbxMeaning]
	}
	else if (comboBoxThatHasChanged == cbxSeqCmdType.get())
	{
		//[UserComboBoxCode_cbxSeqCmdType] -- add your combo box handling code here..
		//[/UserComboBoxCode_cbxSeqCmdType]
	}

	//[UsercomboBoxChanged_Post]
	//[/UsercomboBoxChanged_Post]
}

void AudioseqPane::visibilityChanged()
{
	//[UserCode_visibilityChanged] -- Add your code here...
	//[/UserCode_visibilityChanged]
}

void AudioseqPane::broughtToFront()
{
	//[UserCode_broughtToFront] -- Add your code here...
	//fillSeqSections();
	//[/UserCode_broughtToFront]
}

void AudioseqPane::focusGained(FocusChangeType cause)
{
	//[UserCode_focusGained] -- Add your code here...
	//fillSeqSections();
	//[/UserCode_focusGained]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

bool AudioseqPane::keyPressed(const KeyPress& key) {
	if (key == KeyPress(KeyPress::F11Key)) {
		int r = lstSeqCommands->getLastRowSelected();
		if (r > 0) {
			lstSeqCommands->selectRow(r - 1);
		}
		return true;
	}
	else if (key == KeyPress(KeyPress::F12Key)) {
		int r = lstSeqCommands->getLastRowSelected();
		if (r < lsmSeqCommands->getNumRows() - 1) {
			lstSeqCommands->selectRow(r + 1);
		}
		return true;
	}
	else if (key == KeyPress('v', ModifierKeys::altModifier, 0)) {
		if (&*seq64.seq == nullptr) return true;
		int selsec = lstSeqSections->getLastRowSelected();
		if (selsec < 0 || selsec >= seq64.seq->getNumSections()) return true;
		SeqData* section = seq64.seq->getSection(selsec);
		int selcmdidx = lstSeqCommands->getLastRowSelected();
		if (selcmdidx < 0 || selcmdidx >= section->cmdoffsets.size()) return true;
		uint32 cmdaddr = section->cmdoffsets[selcmdidx];
		ValueTree cmd = seq64.seq->getCommand(cmdaddr, section->stype);
		ValueTree param = cmd.getChildWithProperty("meaning", "Velocity");
		if (!param.isValid()) {
			SEQ64::say("Command has no Velocity property");
			return true;
		}
		int ret = seq64.seq->editCmdParam(selsec, cmdaddr, section->stype, "Velocity", 0);
		if (ret < 0) {
			SEQ64::say("Setting velocity to 0 failed");
		}
		if (ret > 0) {
			seqStructureChanged();
		}
		else if (ret == 0) {
			lsmSeqCommands->set(selcmdidx, seq64.seq->getCommandDescription(selsec, selcmdidx));
			lstSeqCommands->repaintRow(selcmdidx);
		}
	}
	return false;
}

void AudioseqPane::rowSelected(TextListModel* parent, int row) {
	if (parent == &*lsmCommands) {
		ValueTree cmdlistnode = seq64.romdesc.getOrCreateChildWithName("cmdlist", nullptr);
		selcmd = cmdlistnode.getChild(row);
		refreshCmdControls();
	}
	else if (parent == &*lsmParameters) {
		selparam = selcmd.getChild(row);
		refreshParamControls();
	}
	else if (parent == &*lsmSeqSections) {
		fillSeqCommands();
	}
	else if (parent == &*lsmSeqCommands) {
		refreshSeqCmdControls();
	}
	else if (parent == &*lsmSeqCmdParams) {
		refreshSeqCmdParamControls();
	}
}

void AudioseqPane::textEditorTextChanged(TextEditor& editorThatWasChanged) {
	int val;
	String text = editorThatWasChanged.getText();
	if (&editorThatWasChanged == &*txtParamAdd
		|| &editorThatWasChanged == &*txtCmdDataSize) {
		val = text.getIntValue();
	}
	else {
		val = text.getHexValue32();
	}
	bool turnRed = (val <= 0);
	bool redrawCmdItem = false;

	if (&editorThatWasChanged == &*txtCmdName) {
		if (!selcmd.isValid()) return;
		selcmd.setProperty("name", text, nullptr);
		turnRed = false;
		redrawCmdItem = true;
	}
	else if (&editorThatWasChanged == &*txtCmd) {
		if (!selcmd.isValid()) return;
		selcmd.setProperty("cmd", val, nullptr);
		redrawCmdItem = true;
	}
	else if (&editorThatWasChanged == &*txtCmdEnd) {
		if (!selcmd.isValid()) return;
		if (text != "") {
			selcmd.setProperty("cmdend", val, nullptr);
			if (val < (int)selcmd.getProperty("cmd", 0xFF)) {
				turnRed = true;
			}
		}
		else {
			selcmd.removeProperty("cmdend", nullptr);
			turnRed = false;
		}
		redrawCmdItem = true;
	}
	else if (&editorThatWasChanged == &*txtParamName) {
		if (!selparam.isValid()) return;
		selparam.setProperty("name", text, nullptr);
		turnRed = false;
	}
	else if (&editorThatWasChanged == &*txtParamAdd) {
		if (!selparam.isValid()) return;
		selparam.setProperty("add", val, nullptr);
		turnRed = false;
	}
	else if (&editorThatWasChanged == &*txtParamMult) {
		if (!selparam.isValid()) return;
		float v = text.getFloatValue();
		if (v <= 0.0f) v = 1.0f;
		selparam.setProperty("multiply", v, nullptr);
		turnRed = false;
	}
	else if (&editorThatWasChanged == &*txtCmdDataSize) {
		if (!selparam.isValid()) return;
		if (val < 0) val = 0;
		selparam.setProperty("datalen", val, nullptr);
		turnRed = false;
	}
	else if (&editorThatWasChanged == &*txtSeqCmdValue) {
		if (&*seq64.seq == nullptr) return;
		int selsec = lstSeqSections->getLastRowSelected();
		if (selsec < 0 || selsec >= seq64.seq->getNumSections()) return;
		SeqData* section = seq64.seq->getSection(selsec);
		int selcmdidx = lstSeqCommands->getLastRowSelected();
		if (selcmdidx < 0 || selcmdidx >= section->cmdoffsets.size()) return;
		uint32 cmdaddr = section->cmdoffsets[selcmdidx];
		ValueTree cmd = seq64.seq->getCommand(cmdaddr, section->stype);
		int selparamidx = lstSeqCmdParams->getLastRowSelected();
		if (selparamidx < 0 || selparamidx >= cmd.getNumChildren()) return;
		ValueTree param = cmd.getChild(selparamidx);
		int ret = seq64.seq->editCmdParam(selsec, cmdaddr, section->stype, param.getProperty("meaning", "None"), val);
		turnRed = (ret < 0);
		if (ret > 0) {
			seqStructureChanged();
		}
		else if (ret == 0) {
			lsmSeqCommands->set(selcmdidx, seq64.seq->getCommandDescription(selsec, selcmdidx));
			lstSeqCommands->repaintRow(selcmdidx);
		}
	}
	if (turnRed) {
		editorThatWasChanged.setColour(TextEditor::backgroundColourId, Colours::red);
	}
	else {
		editorThatWasChanged.setColour(TextEditor::backgroundColourId, LFWidgetColor());
	}
	if (redrawCmdItem) {
		lsmCommands->set(lstCommands->getLastRowSelected(), getCommandDesc(selcmd));
		lstCommands->repaintRow(lstCommands->getLastRowSelected());
	}

}


void AudioseqPane::refreshCmdControls() {
	if (selcmd.isValid()) {
		txtCmdName->setText(selcmd.getProperty("name", "Error!").toString());
		txtCmd->setText(ROM::hex((uint8)(int)selcmd.getProperty("cmd", 0)));
		if (selcmd.hasProperty("cmdend")) {
			txtCmdEnd->setText(ROM::hex((uint8)(int)selcmd.getProperty("cmdend", 0)));
		}
		else {
			txtCmdEnd->setText("");
		}
		optCmdSeq->setToggleState((bool)selcmd.getProperty("validinseq", false), dontSendNotification);
		optCmdChn->setToggleState((bool)selcmd.getProperty("validinchn", false), dontSendNotification);
		optCmdTrk->setToggleState((bool)selcmd.getProperty("validintrk", false), dontSendNotification);
		String action = selcmd.getProperty("action", "No Action").toString();
		cbxAction->setText(action);
		fillMeaningsBox(action);
	}
	else {
		txtCmdName->setText("");
		txtCmd->setText("");
		txtCmdEnd->setText("");
		optCmdSeq->setToggleState(false, dontSendNotification);
		optCmdChn->setToggleState(false, dontSendNotification);
		optCmdTrk->setToggleState(false, dontSendNotification);
		cbxAction->setText("No Action");
		fillMeaningsBox("No Action");
		refreshParamList();
		lstParameters->selectRow(0);
	}
	refreshParamList();
}

void AudioseqPane::refreshParamControls() {
	if (selparam.isValid()) {
		String src = selparam.getProperty("datasrc", "fixed").toString();
		if (src == "variable") {
			optCmdDataVar->setToggleState(true, dontSendNotification);
			txtCmdDataSize->setText(String((int)selparam.getProperty("datalen", 0)));
			lblCmdDataSize->setText("up to", dontSendNotification);
		}
		else if (src == "offset") {
			optCmdOffset->setToggleState(true, dontSendNotification);
			txtCmdDataSize->setText("");
			lblCmdDataSize->setText("(none)", dontSendNotification);
		}
		else {
			optCmdDataFixed->setToggleState(true, dontSendNotification);
			txtCmdDataSize->setText(String((int)selparam.getProperty("datalen", 0)));
			lblCmdDataSize->setText("length", dontSendNotification);
		}
		txtParamName->setText(selparam.getProperty("name", "Unnamed").toString());
		cbxMeaning->setText(selparam.getProperty("meaning", "None").toString());
		txtParamAdd->setText(String((int)selparam.getProperty("add", 0)));
		txtParamMult->setText(String((float)selparam.getProperty("multiply", 1.0f)));
	}
	else {
		optCmdDataFixed->setToggleState(true, dontSendNotification);
		txtCmdDataSize->setText("0");
		lblCmdDataSize->setText("length", dontSendNotification);
		txtParamName->setText("");
		cbxMeaning->setText("None");
		txtParamAdd->setText("0");
		txtParamMult->setText("1");
	}
}

void AudioseqPane::refreshCmdList() {
	lsmCommands->clear();
	lstCommands->updateContent();
	ValueTree cmdlistnode = seq64.romdesc.getOrCreateChildWithName("cmdlist", nullptr);
	ValueTree cmd;
	String desc;
	for (int i = 0; i < cmdlistnode.getNumChildren(); i++) {
		cmd = cmdlistnode.getChild(i);
		if (cmd.getType() == Identifier("command")) {
			lsmCommands->add(getCommandDesc(cmd));
		}
	}
	lstCommands->updateContent();
}
void AudioseqPane::refreshParamList() {
	lsmParameters->clear();
	lstParameters->updateContent();
	if (selcmd.isValid()) {
		ValueTree param;
		for (int i = 0; i < selcmd.getNumChildren(); i++) {
			param = selcmd.getChild(i);
			if (param.getType() == Identifier("parameter")) {
				lsmParameters->add(String(i));
			}
		}
	}
	lstParameters->updateContent();
}

String AudioseqPane::getCommandDesc(ValueTree cmd) {
	String desc = ROM::hex((uint8)(int)cmd.getProperty("cmd", 0));
	if (cmd.hasProperty("cmdend")) {
		desc += " to " + ROM::hex((uint8)(int)cmd.getProperty("cmdend", 0));
	}
	desc += ": " + cmd.getProperty("name").toString();
	desc += " (" + cmd.getProperty("action").toString() + ")";
	return desc;
}


void AudioseqPane::fillMeaningsBox(String action) {
	cbxMeaning->clear(dontSendNotification);
	cbxMeaning->addItem("None", cbxMeaning->getNumItems() + 1);
	cbxMeaning->addItem("Delay", cbxMeaning->getNumItems() + 1);
	if (action == "No Action") {
		//None
	}
	else if (action == "End of Data") {
		//None
	}
	else if (action == "Timestamp") {
		//None--use Delay
	}
	else if (action == "Jump Same Level") {
		cbxMeaning->addItem("Absolute Address", cbxMeaning->getNumItems() + 1);
		cbxMeaning->addItem("Relative Address", cbxMeaning->getNumItems() + 1);
	}
	else if (action == "Call Same Level") {
		cbxMeaning->addItem("Absolute Address", cbxMeaning->getNumItems() + 1);
		cbxMeaning->addItem("Relative Address", cbxMeaning->getNumItems() + 1);
	}
	else if (action == "Loop Start") {
		cbxMeaning->addItem("Loop Count", cbxMeaning->getNumItems() + 1);
	}
	else if (action == "Loop End") {
		//None
	}
	else if (action == "Ptr Channel Header") {
		cbxMeaning->addItem("Channel", cbxMeaning->getNumItems() + 1);
		cbxMeaning->addItem("Absolute Address", cbxMeaning->getNumItems() + 1);
		cbxMeaning->addItem("Relative Address", cbxMeaning->getNumItems() + 1);
	}
	else if (action == "Ptr Track Data") {
		cbxMeaning->addItem("Note Layer", cbxMeaning->getNumItems() + 1);
		cbxMeaning->addItem("Absolute Address", cbxMeaning->getNumItems() + 1);
		cbxMeaning->addItem("Relative Address", cbxMeaning->getNumItems() + 1);
	}
	else if (action == "Sequence Format") {
		cbxMeaning->addItem("Value", cbxMeaning->getNumItems() + 1);
	}
	else if (action == "Sequence Type") {
		cbxMeaning->addItem("Value", cbxMeaning->getNumItems() + 1);
	}
	else if (action == "Channel Enable") {
		cbxMeaning->addItem("Bitfield", cbxMeaning->getNumItems() + 1);
	}
	else if (action == "Channel Disable") {
		cbxMeaning->addItem("Bitfield", cbxMeaning->getNumItems() + 1);
	}
	else if (action == "Master Volume") {
		cbxMeaning->addItem("Value", cbxMeaning->getNumItems() + 1);
	}
	else if (action == "Tempo") {
		cbxMeaning->addItem("Value", cbxMeaning->getNumItems() + 1);
	}
	else if (action == "Chn Reset") {
		//None
	}
	else if (action == "Chn Priority") {
		cbxMeaning->addItem("Value", cbxMeaning->getNumItems() + 1);
	}
	else if (action == "Chn Volume") {
		cbxMeaning->addItem("Value", cbxMeaning->getNumItems() + 1);
	}
	else if (action == "Chn Pan") {
		cbxMeaning->addItem("Value", cbxMeaning->getNumItems() + 1);
	}
	else if (action == "Chn Effects") {
		cbxMeaning->addItem("Value", cbxMeaning->getNumItems() + 1);
	}
	else if (action == "Chn Vibrato") {
		cbxMeaning->addItem("Value", cbxMeaning->getNumItems() + 1);
	}
	else if (action == "Chn Pitch Bend") {
		cbxMeaning->addItem("Value", cbxMeaning->getNumItems() + 1);
	}
	else if (action == "Chn Transpose") {
		cbxMeaning->addItem("Value", cbxMeaning->getNumItems() + 1);
	}
	else if (action == "Layer Transpose") {
		cbxMeaning->addItem("Value", cbxMeaning->getNumItems() + 1);
	}
	else if (action == "Chn Instrument") {
		cbxMeaning->addItem("Value", cbxMeaning->getNumItems() + 1);
	}
	else if (action == "Track Note") {
		cbxMeaning->addItem("Note Layer", cbxMeaning->getNumItems() + 1);
		cbxMeaning->addItem("Note", cbxMeaning->getNumItems() + 1);
		cbxMeaning->addItem("Velocity", cbxMeaning->getNumItems() + 1);
		cbxMeaning->addItem("Gate Time", cbxMeaning->getNumItems() + 1);
	}
	else {
		cbxMeaning->clear(dontSendNotification);
		cbxMeaning->addItem("ERROR fillMeaningsBox", cbxMeaning->getNumItems() + 1);
	}
	cbxMeaning->setSelectedItemIndex(0, dontSendNotification);
}

void AudioseqPane::fillSeqSections() {
	if (&*seq64.seq == nullptr) return;
	lsmSeqSections->clear();
	lstSeqSections->updateContent();
	for (int s = 0; s < seq64.seq->getNumSections(); s++) {
		lsmSeqSections->add(seq64.seq->getSectionDescription(s));
	}
	String seqinfo = "Sequence ";
	if (seq64.seq->name != "") {
		seqinfo += "\"" + seq64.seq->name + "\"";
	}
	seqinfo += ": length " + ROM::hex(seq64.seq->getLength(), 4);
	seqinfo += " (" + String(seq64.seq->getNumSections()) + " sections)";
	lblSeqInfo->setText(seqinfo, dontSendNotification);
	lstSeqSections->updateContent();
}

void AudioseqPane::fillSeqCommands() {
	int selcmdidx = lstSeqCommands->getLastRowSelected();
	lsmSeqCommands->clear();
	lstSeqCommands->updateContent();
	if (&*seq64.seq == nullptr) return;
	int selsec = lstSeqSections->getLastRowSelected();
	if (selsec < 0 || selsec >= seq64.seq->getNumSections()) return;
	int cmds = seq64.seq->getSection(selsec)->cmdoffsets.size();
	for (int c = 0; c < cmds; c++) {
		lsmSeqCommands->add(seq64.seq->getCommandDescription(selsec, c));
	}
	lstSeqCommands->updateContent();
	lstSeqCommands->selectRow(selcmdidx);
	//Fill New Command box
	cbxSeqCmdType->clear(dontSendNotification);
	int stype = seq64.seq->getSection(selsec)->stype;
	ValueTree cmdlistnode = seq64.romdesc.getOrCreateChildWithName("cmdlist", nullptr);
	ValueTree cmd;
	String desc;
	for (int i = 0; i < cmdlistnode.getNumChildren(); i++) {
		cmd = cmdlistnode.getChild(i);
		if (cmd.getType() == Identifier("command")) {
			if ((stype == 0 && (bool)cmd.getProperty("validinseq", false))
				|| (stype == 1 && (bool)cmd.getProperty("validinchn", false))
				|| (stype == 2 && (bool)cmd.getProperty("validintrk", false))) {
				cbxSeqCmdType->addItem(cmd.getProperty("name", "ERROR").toString(), cbxSeqCmdType->getNumItems() + 1);
			}
		}
	}
	cbxMeaning->setSelectedItemIndex(0, dontSendNotification);
}


void AudioseqPane::refreshSeqCmdControls() {
	if (&*seq64.seq == nullptr) return;
	int selparamidx = lstSeqCmdParams->getLastRowSelected();
	if (selparamidx < 0) selparamidx = 0;
	int selsec = lstSeqSections->getLastRowSelected();
	if (selsec < 0 || selsec >= seq64.seq->getNumSections()) return;
	SeqData* section = seq64.seq->getSection(selsec);
	int selcmdidx = lstSeqCommands->getLastRowSelected();
	if (selcmdidx < 0 || selcmdidx >= section->cmdoffsets.size()) return;
	uint32 cmdaddr = section->cmdoffsets[selcmdidx];
	ValueTree cmd = seq64.seq->getCommand(cmdaddr, section->stype);
	lblSeqCmdAction->setText("Command Action: " + cmd.getProperty("action", "No Action").toString(), dontSendNotification);
	ValueTree param;
	lsmSeqCmdParams->clear();
	lstSeqCmdParams->updateContent();
	int params = cmd.getNumChildren();
	for (int i = 0; i < params; i++) {
		param = cmd.getChild(i);
		lsmSeqCmdParams->add(param.getProperty("name", "Unnamed"));
	}
	lstSeqCmdParams->updateContent();
	lstSeqCmdParams->selectRow(selparamidx);
}

void AudioseqPane::refreshSeqCmdParamControls() {
	if (&*seq64.seq == nullptr) return;
	int selsec = lstSeqSections->getLastRowSelected();
	if (selsec < 0 || selsec >= seq64.seq->getNumSections()) {
		txtSeqCmdValue->setText("", dontSendNotification);
		return;
	}
	SeqData* section = seq64.seq->getSection(selsec);
	int selcmdidx = lstSeqCommands->getLastRowSelected();
	if (selcmdidx < 0 || selcmdidx >= section->cmdoffsets.size()) {
		txtSeqCmdValue->setText("", dontSendNotification);
		return;
	}
	uint32 cmdaddr = section->cmdoffsets[selcmdidx];
	ValueTree cmd = seq64.seq->getCommand(cmdaddr, section->stype);
	int selparamidx = lstSeqCmdParams->getLastRowSelected();
	if (selparamidx < 0 || selparamidx >= cmd.getNumChildren()) {
		txtSeqCmdValue->setText("", dontSendNotification);
		return;
	}
	ValueTree param = cmd.getChild(selparamidx);
	int len = (int)param.getProperty("datalen", 1) * 2;
	if (len <= 0) len = 2;
	txtSeqCmdValue->setText(ROM::hex((uint32)(int)param.getProperty("value", 0),
		len), dontSendNotification);
}

void AudioseqPane::seqStructureChanged() {
	if (&*seq64.seq == nullptr) return;
	int selsec = lstSeqSections->getLastRowSelected();
	int selparamidx = lstSeqCmdParams->getLastRowSelected();
	seq64.seq->parse();
	fillSeqSections();
	lstSeqSections->selectRow(selsec);
	lstSeqCmdParams->selectRow(selparamidx);
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

	This is where the Projucer stores the metadata that describe this GUI layout, so
	make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AudioseqPane" componentName=""
				 parentClasses="public Component, public TextEditor::Listener, public TextListModel::Listener"
				 constructorParams="SEQ64&amp; seq64_" variableInitialisers="seq64(seq64_)"
				 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
				 fixedSize="1" initialWidth="1078" initialHeight="713">
  <METHODS>
	<METHOD name="focusGained (FocusChangeType cause)"/>
	<METHOD name="visibilityChanged()"/>
	<METHOD name="broughtToFront()"/>
  </METHODS>
  <BACKGROUND backgroundColour="ff323e44"/>
  <GROUPCOMPONENT name="new group" id="b3355c52e381c7e5" memberName="groupComponent"
				  virtualName="" explicitFocusOrder="0" pos="408 0 648 672" title="Loaded Sequence"/>
  <GROUPCOMPONENT name="new group" id="f1d4a599b3267719" memberName="groupComponent3"
				  virtualName="" explicitFocusOrder="0" pos="0 0 400 672" title="Command Editor"/>
  <GROUPCOMPONENT name="new group" id="977c50d4ba0f1784" memberName="groupComponent6"
				  virtualName="" explicitFocusOrder="0" pos="152 456 240 208" title="Edit Parameter"/>
  <GROUPCOMPONENT name="new group" id="b9f9c4c5353e7b92" memberName="groupComponent5"
				  virtualName="" explicitFocusOrder="0" pos="280 352 112 96" title="Valid in"/>
  <LABEL name="new label" id="120e7da910b9fa36" memberName="label10" virtualName=""
		 explicitFocusOrder="0" pos="8 392 80 24" edTextCol="ff000000"
		 edBkgCol="0" labelText="Command:" editableSingleClick="0" editableDoubleClick="0"
		 focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
		 kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="c17bf80cbae3b9bf" memberName="txtCmd"
			  virtualName="" explicitFocusOrder="0" pos="96 392 48 24" initialText=""
			  multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
			  caret="1" popupmenu="1"/>
  <TEXTBUTTON name="new button" id="33646eda08c514f8" memberName="btnCmdAdd"
			  virtualName="" explicitFocusOrder="0" pos="352 16 40 24" buttonText="Add"
			  connectedEdges="8" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="4ad518eab3cf4e38" memberName="btnCmdDel"
			  virtualName="" explicitFocusOrder="0" pos="352 40 40 24" buttonText="Del"
			  connectedEdges="4" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="new toggle button" id="de7cafa15549ae99" memberName="optCmdDataFixed"
				virtualName="" explicitFocusOrder="0" pos="160 544 71 24" buttonText="Fixed"
				connectedEdges="0" needsCallback="1" radioGroupId="1" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="1ac143856715712c" memberName="optCmdDataVar"
				virtualName="" explicitFocusOrder="0" pos="160 568 72 24" buttonText="Variable"
				connectedEdges="0" needsCallback="1" radioGroupId="1" state="0"/>
  <LABEL name="new label" id="5ef4448d8600da02" memberName="lblCmdDataSize"
		 virtualName="" explicitFocusOrder="0" pos="240 552 47 24" edTextCol="ff000000"
		 edBkgCol="0" labelText="length" editableSingleClick="0" editableDoubleClick="0"
		 focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
		 kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="txtCmdDat" id="6db88ac89d3dcd1d" memberName="txtCmdDataSize"
			  virtualName="" explicitFocusOrder="0" pos="288 552 32 24" initialText="1"
			  multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
			  caret="1" popupmenu="1"/>
  <LABEL name="new label" id="63098370e332d46f" memberName="label11" virtualName=""
		 explicitFocusOrder="0" pos="320 552 48 24" edTextCol="ff000000"
		 edBkgCol="0" labelText="(dec)" editableSingleClick="0" editableDoubleClick="0"
		 focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
		 kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="1260a931f1b77e50" memberName="label2" virtualName=""
		 explicitFocusOrder="0" pos="8 424 56 24" edTextCol="ff000000"
		 edBkgCol="0" labelText="Action:" editableSingleClick="0" editableDoubleClick="0"
		 focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
		 kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="Action" id="4cabd0b9e2965ff5" memberName="cbxAction" virtualName=""
			explicitFocusOrder="0" pos="64 424 208 24" editable="0" layout="33"
			items="No Action&#10;End of Data&#10;Timestamp&#10;Jump Same Level&#10;Call Same Level&#10;Loop Start&#10;Loop End&#10;Ptr Channel Header&#10;Ptr Track Data&#10;Sequence Format&#10;Sequence Type&#10;Channel Enable&#10;Channel Disable&#10;Master Volume&#10;Tempo&#10;Chn Reset&#10;Chn Priority&#10;Chn Volume&#10;Chn Pan&#10;Chn Effects&#10;Chn Vibrato&#10;Chn Pitch Bend&#10;Chn Instrument&#10;Chn Transpose&#10;Layer Transpose&#10;Track Note"
			textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="6d034f22b803ef0c" memberName="label9" virtualName=""
		 explicitFocusOrder="0" pos="8 360 55 24" edTextCol="ff000000"
		 edBkgCol="0" labelText="Name:" editableSingleClick="0" editableDoubleClick="0"
		 focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
		 kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="17aae1e70c35fd59" memberName="txtCmdName"
			  virtualName="" explicitFocusOrder="0" pos="64 360 208 24" initialText=""
			  multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
			  caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="391e87c7412baa15" memberName="txtCmdEnd"
			  virtualName="" explicitFocusOrder="0" pos="176 392 48 24" initialText=""
			  multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
			  caret="1" popupmenu="1"/>
  <LABEL name="new label" id="2dce25261c0a7641" memberName="label12" virtualName=""
		 explicitFocusOrder="0" pos="152 392 23 24" edTextCol="ff000000"
		 edBkgCol="0" labelText="to" editableSingleClick="0" editableDoubleClick="0"
		 focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
		 kerning="0.0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="6760f7dd9298e144" memberName="optCmdSeq"
				virtualName="" explicitFocusOrder="0" pos="288 368 103 24" buttonText="Seq header"
				connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="e198702d72e71f55" memberName="optCmdChn"
				virtualName="" explicitFocusOrder="0" pos="288 392 104 24" buttonText="Chn header"
				connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="d079eea3af0c26a4" memberName="optCmdTrk"
				virtualName="" explicitFocusOrder="0" pos="288 416 104 24" buttonText="Track data"
				connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="5666e65f925f98ec" memberName="label13" virtualName=""
		 explicitFocusOrder="0" pos="8 456 104 24" edTextCol="ff000000"
		 edBkgCol="0" labelText="Parameters:" editableSingleClick="0"
		 editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
		 fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="972d79b803f377c4" memberName="btnParamAdd"
			  virtualName="" explicitFocusOrder="0" pos="104 480 40 24" buttonText="Add"
			  connectedEdges="8" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="1ba257bf64ce7e89" memberName="btnParamDel"
			  virtualName="" explicitFocusOrder="0" pos="104 504 40 24" buttonText="Del"
			  connectedEdges="4" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="2f3dd0a3ebcb78d5" memberName="btnParamUp"
			  virtualName="" explicitFocusOrder="0" pos="104 616 40 24" buttonText="Up"
			  connectedEdges="8" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="cee83a628d87bd1a" memberName="btnParamDn"
			  virtualName="" explicitFocusOrder="0" pos="104 640 40 24" buttonText="Dn"
			  connectedEdges="4" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="new toggle button" id="3134f7ae28bcfdd3" memberName="optCmdOffset"
				virtualName="" explicitFocusOrder="0" pos="160 520 160 24" buttonText="Cmd Offset (no data)"
				connectedEdges="0" needsCallback="1" radioGroupId="1" state="0"/>
  <LABEL name="new label" id="9da40dae5b71c4cf" memberName="label14" virtualName=""
		 explicitFocusOrder="0" pos="160 496 224 24" edTextCol="ff000000"
		 edBkgCol="0" labelText="Data source:" editableSingleClick="0"
		 editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
		 fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="eed9a48d3bb5e03b" memberName="label15" virtualName=""
		 explicitFocusOrder="0" pos="160 592 72 24" edTextCol="ff000000"
		 edBkgCol="0" labelText="Meaning:" editableSingleClick="0" editableDoubleClick="0"
		 focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
		 kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="b867bd3ceb8e1203" memberName="txtParamName"
			  virtualName="" explicitFocusOrder="0" pos="216 472 166 24" initialText=""
			  multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
			  caret="1" popupmenu="1"/>
  <LABEL name="new label" id="8306c58890811511" memberName="label16" virtualName=""
		 explicitFocusOrder="0" pos="160 472 55 24" edTextCol="ff000000"
		 edBkgCol="0" labelText="Name:" editableSingleClick="0" editableDoubleClick="0"
		 focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
		 kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="Meaning" id="5955524ab0ec02c1" memberName="cbxMeaning"
			virtualName="" explicitFocusOrder="0" pos="232 592 150 24" editable="0"
			layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="8d5abd7e709bfe4f" memberName="label17" virtualName=""
		 explicitFocusOrder="0" pos="160 624 64 24" edTextCol="ff000000"
		 edBkgCol="0" labelText="Add (dec):" editableSingleClick="0" editableDoubleClick="0"
		 focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
		 kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="9a94c821168285dc" memberName="label18" virtualName=""
		 explicitFocusOrder="0" pos="272 624 64 24" edTextCol="ff000000"
		 edBkgCol="0" labelText="Multiply:" editableSingleClick="0" editableDoubleClick="0"
		 focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
		 kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="d44ee99ec4017196" memberName="txtParamAdd"
			  virtualName="" explicitFocusOrder="0" pos="224 624 47 24" initialText="0"
			  multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
			  caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="9adbc3822f7d0ac1" memberName="txtParamMult"
			  virtualName="" explicitFocusOrder="0" pos="336 624 47 24" initialText="1.0"
			  multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
			  caret="1" popupmenu="1"/>
  <TEXTBUTTON name="new button" id="5c1f23230407fcb1" memberName="btnCmdUp"
			  virtualName="" explicitFocusOrder="0" pos="352 296 40 24" buttonText="Up"
			  connectedEdges="8" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="98d71ec28a9ccb5f" memberName="btnCmdDn"
			  virtualName="" explicitFocusOrder="0" pos="352 320 40 24" buttonText="Dn"
			  connectedEdges="4" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="cfb894eaf50ddd48" memberName="label3" virtualName=""
		 explicitFocusOrder="0" pos="416 88 192 24" edTextCol="ff000000"
		 edBkgCol="0" labelText="@Addr: Typ Ch Ly Events" editableSingleClick="0"
		 editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default monospaced font"
		 fontsize="14.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="eafcae42c6686b48" memberName="label4" virtualName=""
		 explicitFocusOrder="0" pos="696 16 352 24" edTextCol="ff000000"
		 edBkgCol="0" labelText="@Addr: Data           Command" editableSingleClick="0"
		 editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default monospaced font"
		 fontsize="14.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="cf3f95690aa55b7c" memberName="btnSeqCmdAdd"
			  virtualName="" explicitFocusOrder="0" pos="880 560 40 24" buttonText="Add"
			  connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="9661fb86a4ef0a7c" memberName="btnSeqCmdDelete"
			  virtualName="" explicitFocusOrder="0" pos="920 560 40 24" buttonText="Del"
			  connectedEdges="1" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="322ab17ff1c48b0f" memberName="btnSeqCmdUp"
			  virtualName="" explicitFocusOrder="0" pos="968 560 40 24" buttonText="Up"
			  connectedEdges="2" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="24ae8e838a4add93" memberName="btnSeqCmdDn"
			  virtualName="" explicitFocusOrder="0" pos="1008 560 40 24" buttonText="Dn"
			  connectedEdges="1" needsCallback="1" radioGroupId="0"/>
  <COMBOBOX name="new combo box" id="91d638859dfe0501" memberName="cbxSeqCmdType"
			virtualName="" explicitFocusOrder="0" pos="696 560 184 24" editable="0"
			layout="33" items="" textWhenNonSelected="[Command to add]" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="1ef07cd6fece0549" memberName="label7" virtualName=""
		 explicitFocusOrder="0" pos="888 616 64 24" edTextCol="ff000000"
		 edBkgCol="0" labelText="Value:" editableSingleClick="0" editableDoubleClick="0"
		 focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
		 kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="28b2ef3b6fe44f9a" memberName="txtSeqCmdValue"
			  virtualName="" explicitFocusOrder="0" pos="952 616 88 24" initialText=""
			  multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
			  caret="1" popupmenu="1"/>
  <LABEL name="new label" id="a69b237684dc0a0d" memberName="lblSeqInfo"
		 virtualName="" explicitFocusOrder="0" pos="416 16 272 16" edTextCol="ff000000"
		 edBkgCol="0" labelText="Sequence information" editableSingleClick="0"
		 editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
		 fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="9"/>
  <LABEL name="new label" id="4b6f4c5b150b8e9" memberName="lblSeqCmdAction"
		 virtualName="" explicitFocusOrder="0" pos="696 592 352 24" edTextCol="ff000000"
		 edBkgCol="0" labelText="Command Action:" editableSingleClick="0"
		 editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
		 fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="44ea1cfa0e02c008" memberName="lblValueEquiv"
		 virtualName="" explicitFocusOrder="0" pos="888 640 152 24" edTextCol="ff000000"
		 edBkgCol="0" labelText="[dec, note equiv.]" editableSingleClick="0"
		 editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
		 fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="e7b46dfed4aed5ba" memberName="lblSeqCmdAction2"
		 virtualName="" explicitFocusOrder="0" pos="416 64 120 24" edTextCol="ff000000"
		 edBkgCol="0" labelText="Sections:" editableSingleClick="0" editableDoubleClick="0"
		 focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
		 kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="45d2e07ee4fefabe" memberName="btnReParse"
			  virtualName="" explicitFocusOrder="0" pos="608 88 80 24" buttonText="Re-Parse"
			  connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="314c7ad20af8b2a3" memberName="btnSaveRaw"
			  virtualName="" explicitFocusOrder="0" pos="416 40 136 24" buttonText="Save Raw"
			  connectedEdges="2" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="49d654ce272e9526" memberName="btnLoadRaw"
			  virtualName="" explicitFocusOrder="0" pos="552 40 136 24" buttonText="Load Raw"
			  connectedEdges="1" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

