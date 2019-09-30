//
//  ofxDigitaktControl.hpp
//
//  Created by Pierre Tardif on 26/09/2019.
//

#ifndef ofxDigitaktControl_hpp
#define ofxDigitaktControl_hpp

#include <stdio.h>

#include "ofMain.h"

// addons
#include "ofxMidi.h"
#include "ofxGui.h"

#include "constants.hpp"

class ofxDigitaktControl{
    
    public :
    
    ofxDigitaktControl(){
        
    }
    
    
    void setup();
    void update();
    void draw();
    void exit();
    
    ofxMidiOut midiOut;
    
    ofxPanel mainGui, trackTrigGUI, srcFltrGUI, ampLfoGUI, effectsGUI;
    
    bool guiON;
    ofParameter < int > channelGUI;
    	
    ofParameterGroup midiTrack;
    ofParameter < bool > trackMute;
    ofParameter < int > trackLevel;
    ofParameter < bool > midiTrackSend;
    
    ofParameterGroup midiTrig;
    ofParameter < int > trigNote;
    ofParameter < int > trigVelocity;
    ofParameter < int > trigLength;
    ofParameter < bool > trigFilterTrig;
    ofParameter < bool > trigLFOTrig;
    ofParameter < bool > midiTrigSend;
    
    ofParameterGroup midiSrc;
    ofParameter < float > srcTune;
    ofParameter < int > srcPlayMode;
    ofParameter < int > srcBitReduction;
    ofParameter < float > srcStart;
    ofParameter < float > srcFinish;
    ofParameter < float > srcLoop;
    ofParameter < int > srcSampleSlot;
    ofParameter < int > srcSampleLevel;
    ofParameter < bool > midiSrcSend;
    
    ofParameterGroup midiFLTR;
    ofParameter < int > fltrAttack;
    ofParameter < int > fltrDecay;
    ofParameter < int > fltrSustain;
    ofParameter < int > fltrRelease;
    ofParameter < float > frequency;
    ofParameter < float > resonnance;
    ofParameter < int > fltrType;
    ofParameter < float > fltrEnvelop;
    ofParameter < bool > midiFltrSend;
    
    ofParameterGroup midiAMP;
    ofParameter < int > ampAttack;
    ofParameter < int > ampHold;
    ofParameter < int > ampDecay;
    ofParameter < float > ampOverdrive;
    ofParameter < float > ampDelay;
    ofParameter < float > ampReverb;
    ofParameter < int > ampPan;
    ofParameter < float > ampVolume;
    ofParameter < bool > midiAmpSend;
    
    ofParameterGroup midiLFO;
    ofParameter < float > lfoSpeed;
    ofParameter < int > lfoMultiplier;
    ofParameter < int > lfoFadeInOut;
    ofParameter < int > lfoDestination;
    ofParameter < int > lfoWave;
    ofParameter < int > lfoStartPhase;
    ofParameter < int > lfoMode;
    ofParameter < float > lfoDepth;
    ofParameter < bool > midiLfoSend;
    
    ofParameterGroup midiDelay;
    ofParameter < float > delayTime;
    ofParameter < bool > delayPingPong;
    ofParameter < float > delayStereoWidth;
    ofParameter < int > delayFeedback;
    ofParameter < float > delayHighPassFltr;
    ofParameter < float > delayLowPassFltr;
    ofParameter < float > delayReverbSend;
    ofParameter < float > delayMixVolume;
    ofParameter < bool > midiDelaySend;
    
    ofParameterGroup midiReverb;
    ofParameter < float > reverbPreDelay;
    ofParameter < int > reverbDecayTime;
    ofParameter < float > reverbShelvingFreq;
    ofParameter < float > reverbShelvingGain;
    ofParameter < float > reverbHighPassFltr;
    ofParameter < float > reverbLowPassFltr;
    ofParameter < int > reverbPrePost;
    ofParameter < float > reverbMixVolume;
    ofParameter < bool > midiReverbSend;
    
    ofParameterGroup midiCompressor;
    ofParameter < int > compressorThreshold;
    ofParameter < int > compressorAttack;
    ofParameter < int > compressorRelease;
    ofParameter < float > compressorMakeUpGain;
    ofParameter < int > compressorPatternVolume;
    ofParameter < int > compressorRatio;
    ofParameter < int > compressorSideChainSource;
    ofParameter < int > compressorSideChainFltr;
    ofParameter < int > compressorDryWetMix;
    ofParameter < bool > midiCompressorSend;
    
    // channel
    unsigned char channelUnsigned;
    
    void listenToChannel(int& channel);
    
    // send messages
    void sendTrackMessages();
    void sendTRIGMessages();
    void sendSRCMessages();
    void sendFLTRMessages();
    void sendAMPMessages();
    void sendLFOMessages();
    void sendDelayMessages();
    void sendReverbMessages();
    void sendCompressorMessages();
    
    vector < unsigned char > initMidiMessage();
    void wrapMidiMessageCC(vector < unsigned char >* sysExMsg);
    
    void addNRPNMessage(vector < unsigned char > * midiMessage, unsigned char addressMSB, unsigned char addressLSB, unsigned char valMSB, unsigned valLSB );

};

#endif /* ofxDigitaktControl_hpp */
