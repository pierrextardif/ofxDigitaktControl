//
//  constants.hpp
//
//  Created by Pierre Tardif on 26/09/2019.
//


#include <stdio.h>

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
#define TUNEMSBHEX                  0x01
#define TUNELSBHEX                  0x00
#define PLAYMODEHEX                 0x11
#define BITREDUCTIONHEX             0x12
#define SAMPLESLOTHEX               0x13
#define STARTHEX                    0x14
#define LENGTHHEX                   0x15
#define LOOPHEX                     0x16
#define SAMPLELEVEL                 0x17

// FLTR
#define FLTRATTACKHEX               0x46
#define FLTRDECAYHEX                0x47
#define FLTRSUSTAINHEX              0x48
#define FLTRRELEASEHEX              0x49
#define FLTRFREQHEX                 0x4A
#define FLTRRESONNANCEHEX           0x4B
#define FLTRTYPEHEX                 0x4C
#define FLTRRENVDEPTHHEX            0x4D

// AMP
#define AMPATTACKHEX                0x4E
#define AMPHOLDHEX                  0x4F
#define AMPDECAYHEX                 0x50
#define AMPOVERDRIVEHEX             0x51
#define AMPDELAYSENDHEX             0x52
#define AMPREVERBSENDHEX            0x53
#define AMPPANHEX                   0x0A
#define AMPVOLUMEHEX                0x07

// LFO
#define LFOSPEEDHEX                 0x66
#define LFOMULTIPLIERHEX            0x67
#define LFOFADEHEX                  0x68
#define LFODESTINATIONHEX           0x69
#define LFOWAVEFORMHEX              0x6A
#define LFOSTARTPHASEHEX            0x6B
#define LFOTRIGMODEHEX              0x6C
#define LFODEPTHHEX                 0x6D
#define LFODEPTHHEXLSB              0x6E

// DELAY
#define DELAYDELAYTIMEHEX           0x55
#define DELAYPINGPONGHEX            0x56
#define DELAYSTEREOWIDTHHEX         0x57
#define DELAYFEEDBACKHEX            0x58
#define DELAYHIGHPASSFLTRHEX        0x59
#define DELAYLOWPASSFLTRHEX         0x5A
#define DELAYREVERBSENDHEX          0x5B
#define DELAYMIXVOLHEX              0x5C

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
