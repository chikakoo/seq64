## Changes from the Orginal version 1.5
Modifies and adds some of the effects that exist in seq64 2.0+, for those who prefer the old one with the audio bank features.

Renames and additions:
- (72) Chn Release Rate (new)
- (76) Chn Vibrato Rate (new)
- (77) Chn Vibrato -> Chn Vibrato Depth (modified name only)
- (78) Chn Vibrato Delay (new)
- (91) Chn Effect -> Chn Reverb (modified name only)

Some QOL features were also added:
- Commented out some auto breakpoints that are hit if the ROM is invalid, which is checked several times even before a ROM is loaded (so it's mostly just annoying to debug)
- Removed the popup that shows up when a MIDI is successfully imported in favor of just having the ones that come up when there's warnings or errors
- Default to the MIDI File tab, as that's the most common tab to start with usually
- Auto-load the OoT V1.0 ROM Desc file on launch from the last place a ROM Desc was loaded from

## Original readme (as of version 1.5)
seq64 - Sequenced music editor for first-party N64 games.
Created by and Copyright (C) 2018 Sauraen, sauraen@gmail.com
Licensed under the GNU General Public License - see LICENSE.txt
Made using Juce Cross-Platform C++ Library version 3 (free for GPL use) - http://www.juce.com/

SEQ64 is a full-featured editor for sequenced music in first-party Nintendo 64 games.

Click the Wiki tab for more information. Program downloads are in the "bin" folder, or compile from source.

Features:

- Full MIDI import/export of sequences in Audioseq format
- Edit sequence data directly (e.g. to add commands not supported by MIDI)
- Create new Audiobank instrument sets from existing instruments
- Edit and tag instrument definitions
- Definitions of Audioseq and Audiobank formats are editable from the GUI and
  saved in human-readable XML files, not hard-coded; thus, compatible with all
  versions of games that use similar sequence formats
- Seamlessly recalculates CRC/CIC upon saving ROM
- Supports all three ROM byte orderings
- Yay0/Yaz0 compressor/decompressor tool
- Mature, comprehensible GUI
- GPL licensed, cross-platform (Juce C++, full-speed on Windows, Mac, Linux) 

Current project state:

- All features above are complete, minus occasional bugs. If you find a bug, 
  please contact me at the email address shown at the top of this file.

Available versions:

- 32-bit Windows 7/8/10
- 64-bit Windows 7/8/10
- 64-bit Linux (compiled and tested on Ubuntu 16.04) 

Games known to use sequenced music formats compatible with SEQ64:

- Super Mario 64 (+)
- Mario Kart 64 (+)
- Yoshi's Story (+)
- Legend of Zelda: Ocarina of Time: v1.0 (+)(*), v1.2 (+), Debug ROM (+)
- Legend of Zelda: Majora's Mask (+)(*)
- 1080 Snowboarding
- F-ZERO X
- Lylat Wars
- Pokemon Stadium
- Pokemon Stadium 2
- Wave Race 64 (+)

(+: RomDesc included) (*: Relevant data is stored in compressed format; must be decompressed before use) 

SEQ64 is NOT compatible with the sequenced music format in games not made by
Nintendo EAD/SRD, including Rare games or other third-party games. With some
modification it may be able to support their bank file format (instrument sets),
but the sequence file format is completely different. SubDrag's n64miditool has
limited support for these other games' sequence file format.


Tips/How To:

*Please read the wiki! https://github.com/sauraen/seq64/wiki or click on the
Wiki tab above!*

I recommend running seq64 from a terminal, lots of useful information is 
printed! If you're on Windows, the program opens itself in a terminal, so don't
worry about it.

If you already have a ROM and ROM Description File (RomDesc--see the RomDesc 
folder above), load each from their respective menus and some of the lists should
start filling in. Keep in mind that some of the RomDescs provided here are for
the uncompressed versions of the games; data may be at different places in 
compressed ROMs.

If you don't have an existing RomDesc for the game, the first step is to find 
the addresses of the Audioseq file (the first sequence) and of the Audioseq 
Index (a list of pointers to sequences). If a file table is present, you can 
use the file table to help locate these items; if not, you can enter their 
addresses manually. These are both "Known Files" (i.e. files that seq64 knows 
how to handle).

Click on your Audioseq Index entry in the Known Files list to show its contents 
in the index list. You can rename sequences (all properties like this are stored
in the RomDesc file). Click Load Sequence to load it from the ROM. Go to the 
Audioseq tab to work with the loaded sequence.

If you're starting working with a new game, start making a RomDesc for it, then
save it and open it in a text editor. Copy the whole "cmdlist" node from an
existing RomDesc so you have a starting point for the file format. Make sure you
get the XML right! (At least it's human-readable!)
