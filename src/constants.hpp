//
//  constants.hpp
//
//  Created by Pierre Tardif on 26/09/2019.
//


#include <stdio.h>

// ==== manufacturer SysEx Id Number ==== //

// found here : https://www.midi.org/specifications-old/item/manufacturer-id-numbers

#define ELEKTRON_SysExIDNumber_0    0x00
#define ELEKTRON_SysExIDNumber_1    0x20
#define ELEKTRON_SysExIDNumber_2    0x3C

// ==== //

// ==== CC MSB ==== //

// sourced from https://www.elektron.se/wp-content/uploads/2019/06/Digitakt-User-Manual_ENG.pdf
// page 72


// TRACK
#define TRACKMUTEHEX                0x5E
#define TRACKLEVELHEX               0x5F

// TRIG
#define TRIGNOTEHEX                 0x03
#define TRIGVELOCITYHEX             0x04
#define TRIGLENGTHHEX               0x05
#define TRIGFLTRTRIGHEX             0x0D
#define TRIGLFOTRIGHEX              0x0E

// SRC
#define SRCTUNEMSBHEX               0x01
#define SRCTUNELSBHEX               0x00
#define SRCPLAYMODEHEX              0x11
#define SRCBITREDUCTIONHEX          0x12
#define SRCSAMPLESLOTHEX            0x13
#define SRCSTARTMSBHEX              0x01
#define SRCSTARTLSBHEX              0x04
#define SRCLENGTHMSBHEX             0x01
#define SRCLENGTHLSBHEX             0x05
#define SRCLOOPMSBHEX               0x01
#define SRCLOOPLSBHEX               0x06
#define SRCSAMPLELEVEL              0x17

// FLTR
#define FLTRATTACKHEX               0x46
#define FLTRDECAYHEX                0x47
#define FLTRSUSTAINHEX              0x48
#define FLTRRELEASEHEX              0x49
#define FLTRFREQMSBHEX              0x01
#define FLTRFREQLSBHEX              0x14
#define FLTRRESONNANCEMSBHEX        0x01
#define FLTRRESONNANCELSBHEX        0x15
#define FLTRTYPEHEX                 0x4C
#define FLTRRENVDEPTHMSBHEX         0x01
#define FLTRRENVDEPTHLSBHEX         0x17

// AMP
#define AMPATTACKHEX                0x4E
#define AMPHOLDHEX                  0x4F
#define AMPDECAYHEX                 0x50
#define AMPOVERDRIVEMSBHEX          0x01
#define AMPOVERDRIVELSBHEX          0x1B
#define AMPDELAYMSBHEX              0x01
#define AMPDELAYLSBHEX              0x1C
#define AMPREVERBMSBHEX             0x01
#define AMPREVERBLSBHEX             0x1D
#define AMPPANHEX                   0x0A
#define AMPVOLUMEMSBHEX             0x01
#define AMPVOLUMELSBHEX             0x1F

// LFO
#define LFOSPEEDMSBHEX              0x01
#define LFOSPEEDLSBHEX              0x20
#define LFOMULTIPLIERHEX            0x67
#define LFOFADEHEX                  0x68
#define LFODESTINATIONHEX           0x69
#define LFOWAVEFORMHEX              0x6A
#define LFOSTARTPHASEHEX            0x6B
#define LFOTRIGMODEHEX              0x6C
#define LFODEPTHMSBHEX              0x01
#define LFODEPTHLSBHEX              0x27

// DELAY
#define DELAYDELAYTIMEMSBHEX        0x02
#define DELAYDELAYTIMELSBHEX        0x00
#define DELAYPINGPONGHEX            0x56
#define DELAYSTEREOWIDTHMSBHEX      0x02
#define DELAYSTEREOWIDTHLSBHEX      0x02
#define DELAYFEEDBACKHEX            0x58
#define DELAYHIGHPASSFLTRMSBHEX     0x02
#define DELAYHIGHPASSFLTRLSBHEX     0x04
#define DELAYLOWPASSFLTRMSBHEX      0x02
#define DELAYLOWPASSFLTRLSBHEX      0x05
#define DELAYREVERBSENDMSBHEX       0x02
#define DELAYREVERBSENDLSBHEX       0x06
#define DELAYMIXVOLMSBHEX           0x02
#define DELAYMIXVOLLSBHEX           0x07

// REVERB
#define REVERBPREDELAYHEX           0x18
#define REVERBDECAYHEX              0x19
#define REVERBSHLVFREQHEX           0x1A
#define REVERBSHLVGAINHEX           0x1B
#define REVERBHIGHPASSFLTRHEX       0x1C
#define REVERLOWPASSFLTRHEX         0x1D
#define REVERBPREPOSTCOMPHEX        0x1E
#define REVERBMIXVOLUMEHEX          0x1F

// COMPRESSOR
#define COMPRESSORTHRSHLDHEX        0x6F
#define COMPRESSORATTACKHEX         0x70
#define COMPRESSORRELEASEHEX        0x71
#define COMPRESSORMKUPGAINHEX       0x72
#define COMPRESSORPTTRNVOLHEX       0x77
#define COMPRESSORRATIOHEX          0x73
#define COMPRESSORSIDECHNSRCHEX     0x74
#define COMPRESSORSIDECHNFLTRHEX    0x75
#define COMPRESSORDRYWETMIXHEX      0x76

// DEV
#define PRINT 1

struct HexCharStruct
{
  unsigned char c;
  HexCharStruct(unsigned char _c) : c(_c) { }
};

inline std::ostream& operator<<(std::ostream& o, const HexCharStruct& hs)
{
  return (o << std::hex << (int)hs.c);
}

inline HexCharStruct hex(unsigned char _c)
{
  return HexCharStruct(_c);
}

// ==== ==== //
