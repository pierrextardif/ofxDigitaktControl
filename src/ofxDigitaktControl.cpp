//
//  ofxDigitaktControl.cpp
//
//  Created by Pierre Tardif on 26/09/2019.
//

#include "ofxDigitaktControl.hpp"

void ofxDigitaktControl::setup(){
    
    // print the available output ports to the console
   midiOut.listOutPorts();
   
   // connect
   midiOut.openPort(0); // by number

    mainGui.setup("mainParams");
    trackTrigGUI.setup("Track & Trigger");
    srcFltrGUI.setup("Source & Filter");
    ampLfoGUI.setup("Amp & Lfo");
    effectsGUI.setup("Effects");

    midiTrack.setName("TRACK");
    midiTrig.setName("TRIG");
    midiSrc.setName("SRC");
    midiFLTR.setName("FLTR");
    midiAMP.setName("AMP");
    midiLFO.setName("LFO");
    midiDelay.setName("DELAY");
    midiReverb.setName("REVERB");
    midiCompressor.setName("COMPRESSOR");

    mainGui.add(channelGUI.set("channel", 0, 0, 7));

    midiTrack.add(trackMute.set("Mute", false));
    midiTrack.add(trackLevel.set("Level",50, 0, 127));
    midiTrack.add(midiTrackSend.set("Send TRACK", false));

    midiTrig.add(trigNote.set("Note", 63, 0, 127));
    midiTrig.add(trigVelocity.set("Velocity", 60, 0, 127));
    midiTrig.add(trigLength.set("Length", 63, 0, 127));
    midiTrig.add(trigFilterTrig.set("Filter Trig", false));
    midiTrig.add(trigLFOTrig.set("LFO Trig", false));
    midiTrig.add(midiTrigSend.set("Send TRIG", false));

    midiSrc.add(srcTune.set("Tune", 0, -24, 24));
    midiSrc.add(srcPlayMode.set("PlayMode", 3, 0, 3));
    midiSrc.add(srcBitReduction.set("BitReduction", 0, 0, 127));
    midiSrc.add(srcSampleSlot.set("Sample Slot", 0, 0, 127));
    midiSrc.add(srcStart.set("Start", 0, 0, 120));
    midiSrc.add(srcFinish.set("Finish", 0, 0, 120));
    midiSrc.add(srcLoop.set("Loop", 0, 0, 120));
    midiSrc.add(srcSampleLevel.set("Level", 127, 0, 127));
    midiSrc.add(midiSrcSend.set
                ("Send SRC", false));

    midiFLTR.add(fltrAttack.set("Attack", 0, 0, 127));
    midiFLTR.add(fltrDecay.set("Decay", 0, 0, 127));
    midiFLTR.add(fltrSustain.set("Sustain", 0, 0, 127));
    midiFLTR.add(fltrRelease.set("Release", 0, 0, 127));
    midiFLTR.add(frequency.set("Frequency", 0, 0, 127));
    midiFLTR.add(resonnance.set("Resonnance", 0, 0, 127));
    midiFLTR.add(fltrType.set("FltrType", 0, 0, 2));
    midiFLTR.add(fltrEnvelop.set("FltrEnvelop", 0, -64, 63));
    midiFLTR.add(midiFltrSend.set("Send FLTR", false));

    midiAMP.add(ampAttack.set("Attack", 0, 0, 127));
    midiAMP.add(ampHold.set("Hold", 0, 0, 127));
    midiAMP.add(ampDecay.set("Decay", 0, 0, 127));
    midiAMP.add(ampOverdrive.set("Overdrive", 0, 0, 127));
    midiAMP.add(ampDelay.set("Delay", 0, 0, 127));
    midiAMP.add(ampReverb.set("Reverb", 0, 0, 127));
    midiAMP.add(ampPan.set("Pan", 0, 0, 127));
    midiAMP.add(ampVolume.set("Volume", 0, 0, 127));
    midiAMP.add(midiAmpSend.set("Send AMP", false));


    midiLFO.add(lfoSpeed.set("Speed", 0, -64, 63));
    midiLFO.add(lfoMultiplier.set("Multiplier", 0, 0, 23));
    midiLFO.add(lfoFadeInOut.set("Fade", 0, -64, 63));
    midiLFO.add(lfoDestination.set("Destination", 0, 0, 32));
    midiLFO.add(lfoWave.set("Wave", 0, 0, 6));
    midiLFO.add(lfoStartPhase.set("Start", 0, 0, 127));
    midiLFO.add(lfoMode.set("Mode", 0, 0, 4));
    midiLFO.add(lfoDepth.set("Depth", 0, -64, 63));
    midiLFO.add(midiLfoSend.set("Send LFO", false));

    midiDelay.add(delayTime.set("Time", 0, 0, 127));
    midiDelay.add(delayPingPong.set("PingPong", false));
    midiDelay.add(delayStereoWidth.set("Stereo Width", 0, -64, 63));
    midiDelay.add(delayFeedback.set("Feedback", 0, 0, 198));
    midiDelay.add(delayHighPassFltr.set("HighPass Fltr", 0, 0, 127));
    midiDelay.add(delayLowPassFltr.set("LowPass Fltr", 0, 0, 127));
    midiDelay.add(delayReverbSend.set("Reverb Send", 0, 0, 127));
    midiDelay.add(delayMixVolume.set("Mix Volume", 0, 0, 127));
    midiDelay.add(midiDelaySend.set("Send DELAY", false));

    midiReverb.add(reverbPreDelay.set("Pre Delay", 0, 0, 127));
    midiReverb.add(reverbDecayTime.set("Decay Time", 0, 0, 127));
    midiReverb.add(reverbShelvingFreq.set("Shelving Freq", 0, 0, 127));
    midiReverb.add(reverbShelvingGain.set("Shelving Gain", 0, 0, 127));
    midiReverb.add(reverbHighPassFltr.set("HighPass Fltr", 0, 0, 127));
    midiReverb.add(reverbLowPassFltr.set("LowPass Fltr", 0, 0, 127));
    midiReverb.add(reverbPrePost.set("Pre COMP / Post COMP", 0, 0, 1));
    midiReverb.add(midiReverbSend.set("Send REVERB", false));

    midiCompressor.add(compressorThreshold.set("Threshold", 0, 0, 127));
    midiCompressor.add(compressorAttack.set("Attack", 0, 0, 127));
    midiCompressor.add(compressorRelease.set("Release", 0, 0, 127));
    midiCompressor.add(compressorMakeUpGain.set("Make Up Gain", 0, 0, 24));
    midiCompressor.add(compressorPatternVolume.set("Pattern Volume", 0, 0, 127));
    midiCompressor.add(compressorRatio.set("Ratio", 0, 0, 8));
    midiCompressor.add(compressorSideChainSource.set("SideChain Source", 0, 0, 8));
    midiCompressor.add(compressorSideChainFltr.set("SideChain FLTR", 0, -64, 63));
    midiCompressor.add(compressorDryWetMix.set("Dry/Wet MIX", 0, 0, 127));
    midiCompressor.add(midiCompressorSend.set("midiCompressorSend", false));


    trackTrigGUI.add(midiTrack);
    trackTrigGUI.add(midiTrig);

    srcFltrGUI.add(midiSrc);
    srcFltrGUI.add(midiFLTR);

    ampLfoGUI.add(midiAMP);
    ampLfoGUI.add(midiLFO);

    effectsGUI.add(midiDelay);
    effectsGUI.add(midiReverb);
    effectsGUI.add(midiCompressor);

    mainGui.setPosition(5,2);
    trackTrigGUI.setPosition(5, 40);
    srcFltrGUI.setPosition(5, 280);
    ampLfoGUI.setPosition(206, 2);
    effectsGUI.setPosition(407, 2);
    
    
    channelGUI.addListener(this, &ofxDigitaktControl::listenToChannel);
}

void ofxDigitaktControl::update(){
    
        if(midiTrackSend){
            
            midiTrackSend = false;
            sendTrackMessages();
        }
        if(midiTrigSend){
    
            midiTrigSend = false;
//            channelUnsigned = 0xB0 | (unsigned char)channelGUI;
            
            sendTRIGMessages();
        }
        
        if(midiSrcSend){
    
            midiSrcSend = false;
//            channelUnsigned = 0xB0 | (unsigned char)channelGUI;
            
            sendSRCMessages();
        }
        if(midiFltrSend){
            midiFltrSend = false;
//            channelUnsigned = 0xB0 | (unsigned char)channelGUI;
            
            sendFLTRMessages();
        }
        if(midiAmpSend){
            midiAmpSend = false;
//            channelUnsigned = 0xB0 | (unsigned char)channelGUI;
            
            sendAMPMessages();
        }
        if(midiLfoSend){
            midiLfoSend = false;
//            channelUnsigned = 0xB0 | (unsigned char)channelGUI;
            
            sendLFOMessages();
        }
        if(midiDelaySend){
            midiDelaySend = false;
//            channelUnsigned = 0xB0 | (unsigned char)channelGUI;
            
            sendDelayMessages();
        }
        if(midiReverbSend){
            midiReverbSend = false;
//            channelUnsigned = 0xB0 | (unsigned char)channelGUI;
            
            sendReverbMessages();
        }
        if(midiCompressorSend){
            midiCompressorSend = false;
//            channelUnsigned = 0xB0 | (unsigned char)channelGUI;
            
            sendCompressorMessages();
        }
}

void ofxDigitaktControl::draw(){
    mainGui.draw();
    trackTrigGUI.draw();
    srcFltrGUI.draw();
    ampLfoGUI.draw();
    effectsGUI.draw();
}

void ofxDigitaktControl::exit(){
    
    // clean up
    midiOut.closePort();
    
    
    channelGUI.removeListener(this, &ofxDigitaktControl::listenToChannel);
}

void ofxDigitaktControl::listenToChannel(int& channel){
    channelUnsigned = 0xB0 | (unsigned char)channel;
    
}
void ofxDigitaktControl::sendTrackMessages(){

    unsigned char trackMuteUnsigned = (unsigned char)trackMute << 0x00;
    unsigned char trackLevelUnsigned = (unsigned char)trackLevel << 0x00;
    
//    cout << "trackLevelUnsigned = " << hex(trackLevelUnsigned) << endl;
    
    midiOut << StartMidi() << MIDI_SYSEX
    << 0x00 << 0x20 << 0x3C
    << 0x00
    << channelUnsigned
    
    << TRACKMUTEHEX
    << trackMuteUnsigned

    << TRACKLEVELHEX
    << trackLevelUnsigned

    << channelUnsigned << 0x06 << trackLevelUnsigned
    << channelUnsigned << 0x26 << trackLevelUnsigned
    << MIDI_SYSEX_END << FinishMidi();
    
}
void ofxDigitaktControl::sendTRIGMessages(){

    unsigned char trigNoteUnsigned = (unsigned char)(trigNote) << 0x00;
    unsigned char trigVelocityUnsigned = (unsigned char)trigVelocity << 0x00;
    unsigned char trigLengthUnsigned = (unsigned char)trigLength << 0x00;
    unsigned char trigFilterTrigUnsigned = (unsigned char)trigFilterTrig << 0x00;
    unsigned char trigLFOTrigUnsigned = (unsigned char)trigLFOTrig << 0x00;
    
    
    midiOut << StartMidi() << MIDI_SYSEX
    << 0x00 << 0x20 << 0x3C
    << 0x00
    << channelUnsigned
    
    << TRIGNOTEHEX
    << trigNoteUnsigned
//
    << TRIGVELOCITYHEX
    << trigVelocityUnsigned
    
    << TRIGLENGTHHEX
    << trigLengthUnsigned

    << TRIGFLTRTRIGHEX
    << trigFilterTrigUnsigned
    
    << TRIGLFOTRIGHEX
    << trigLFOTrigUnsigned
    << channelUnsigned << 0x06 << 0x00
    << channelUnsigned << 0x26 << 0x00
    << MIDI_SYSEX_END << FinishMidi();
    
}

void ofxDigitaktControl::sendSRCMessages(){
    
    unsigned char tuneUnsigned = (unsigned char)(srcTune) << 0x00;
    //        unsigned char tuneUnsigned = (unsigned char)((ofMap(tune, -24, 24, 0, 100)* 0.53125 - 26.96875)) << 0x00;
    //        tuneUnsigned = 0x2f;
    //        tuneUnsigned = 0x5f; // does not send to 23.5 but 24
    //        tuneUnsigned = 0x51;

    //        std::cout << "tuneUnsigned = " << hex(tuneUnsigned) << endl;
    unsigned char playModeUnsigned = (unsigned char)(srcPlayMode) << 0x00;
    unsigned char bitReductionUnsigned = (unsigned char)srcBitReduction << 0x00;
    unsigned char sampleUnsigned = (unsigned char)srcSampleSlot << 0x00;
    unsigned char startUnsigned = (unsigned char)srcStart << 0x00;
    unsigned char finishUnsigned = (unsigned char)srcFinish << 0x00;
    unsigned char loopUnsigned = (unsigned char)srcLoop << 0x00;
    unsigned char sampleLevelUnsigned = (unsigned char)srcSampleLevel << 0x00;
    
    
    midiOut << StartMidi() << MIDI_SYSEX
    << 0x00 << 0x20 << 0x3C
    << 0x00
    << channelUnsigned
    
//    << TUNEHEX
//    << tuneUnsigned
//        << 0x10
    
    << PLAYMODEHEX
    << playModeUnsigned
//
    << STARTHEX
    << startUnsigned
    
    << LENGTHHEX
    << finishUnsigned

    << LOOPHEX
    << loopUnsigned
    
    << BITREDUCTIONHEX
    << bitReductionUnsigned

    << SAMPLELEVEL
    << sampleLevelUnsigned

    << SAMPLESLOTHEX
    << sampleUnsigned
    << channelUnsigned << 0x06 << 0x00
    << channelUnsigned << 0x26 << 0x00
    << MIDI_SYSEX_END << FinishMidi();
    
//    cout << "sending Sample Slot :" << endl;
//    cout << "On channel : " << ofToString(channelGUI) << endl;
//    cout << "with sampleSlot : " << ofToString(sampleSlot) << endl;
}

void ofxDigitaktControl::sendFLTRMessages(){
    
    unsigned char fltrAttackUnsigned = (unsigned char)(fltrAttack) << 0x00;
    unsigned char fltrDecayUnsigned = (unsigned char)fltrDecay << 0x00;
    unsigned char fltrSustainUnsigned = (unsigned char)fltrSustain << 0x00;
    unsigned char fltrReleaseUnsigned = (unsigned char)fltrRelease << 0x00;
    unsigned char frequencyUnsigned = (unsigned char)frequency << 0x00;
    unsigned char resonnanceUnsigned = (unsigned char)resonnance << 0x00;
    unsigned char fltrTypeUnsigned = (unsigned char)fltrType << 0x00;
    unsigned char fltrEnvelopUnsigned = (unsigned char)fltrEnvelop << 0x00;
    
    
    midiOut << StartMidi() << MIDI_SYSEX
    << 0x00 << 0x20 << 0x3C
    << 0x00
    << channelUnsigned
    
    
    << FLTRATTACKHEX
    << fltrAttackUnsigned
//
    << FLTRDECAYHEX
    << fltrDecayUnsigned
    
    << FLTRSUSTAINHEX
    << fltrSustainUnsigned

    << FLTRRELEASEHEX
    << fltrReleaseUnsigned
    
    << FLTRFREQHEX
    << frequencyUnsigned

    << FLTRRESONNANCEHEX
    << resonnanceUnsigned
    
    << FLTRTYPEHEX
    << fltrTypeUnsigned
    
    << FLTRRENVDEPTHHEX
    << fltrEnvelopUnsigned

//    << SAMPLESLOTHEX
//    << sampleUnsigned
    << channelUnsigned << 0x06 << 0x00
    << channelUnsigned << 0x26 << 0x00
    << MIDI_SYSEX_END << FinishMidi();
}

void ofxDigitaktControl::sendAMPMessages(){

    unsigned char fltrAttackUnsigned = (unsigned char)(ampAttack) << 0x00;
    unsigned char fltrDecayUnsigned = (unsigned char)ampHold << 0x00;
    unsigned char fltrSustainUnsigned = (unsigned char)ampDecay << 0x00;
    unsigned char fltrReleaseUnsigned = (unsigned char)ampOverdrive << 0x00;
    unsigned char frequencyUnsigned = (unsigned char)ampDelay << 0x00;
    unsigned char resonnanceUnsigned = (unsigned char)ampReverb << 0x00;
    unsigned char fltrTypeUnsigned = (unsigned char)ampPan << 0x00;
    unsigned char fltrEnvelopUnsigned = (unsigned char)ampVolume << 0x00;
    
    
    midiOut << StartMidi() << MIDI_SYSEX
    << 0x00 << 0x20 << 0x3C
    << 0x00
    << channelUnsigned
    
    
    << AMPATTACKHEX
    << fltrAttackUnsigned
//
    << AMPHOLDHEX
    << fltrDecayUnsigned
    
    << AMPDECAYHEX
    << fltrSustainUnsigned

    << AMPOVERDRIVEHEX
    << fltrReleaseUnsigned
    
    << AMPDELAYSENDHEX
    << frequencyUnsigned

    << AMPREVERBSENDHEX
    << resonnanceUnsigned
    
    << AMPPANHEX
    << fltrTypeUnsigned
    
    << AMPVOLUMEHEX
    << fltrEnvelopUnsigned

//    << SAMPLESLOTHEX
//    << sampleUnsigned
    << channelUnsigned << 0x06 << 0x00
    << channelUnsigned << 0x26 << 0x00
    << MIDI_SYSEX_END << FinishMidi();
}

void ofxDigitaktControl::sendLFOMessages(){

    unsigned char lfoSpeedUnsigned = (unsigned char)lfoSpeed << 0x00;
    unsigned char lfoMultiplierUnsigned = (unsigned char)lfoMultiplier << 0x00;
    unsigned char lfoFadeInOutUnsigned = (unsigned char)lfoFadeInOut << 0x00;
    unsigned char lfoDestinationUnsigned = (unsigned char)lfoDestination << 0x00;
    unsigned char lfoWaveUnsigned = (unsigned char)lfoWave << 0x00;
    unsigned char lfoStartPhaseUnsigned = (unsigned char)lfoStartPhase << 0x00;
    unsigned char lfoModeUnsigned = (unsigned char)lfoMode << 0x00;
    unsigned char lfoDepthUnsigned = (unsigned char)lfoDepth << 0x00;
    
    
    midiOut << StartMidi() << MIDI_SYSEX
    << 0x00 << 0x20 << 0x3C
    << 0x00
    << channelUnsigned
    
    
    << LFOSPEEDHEX
    << lfoSpeedUnsigned
//
    << LFOMULTIPLIERHEX
    << lfoMultiplierUnsigned
    
    << LFOFADEHEX
    << lfoFadeInOutUnsigned

    << LFODESTINATIONHEX
    << lfoDestinationUnsigned
    
    << LFOWAVEFORMHEX
    << lfoWaveUnsigned

    << LFOSTARTPHASEHEX
    << lfoStartPhaseUnsigned
    
    << LFOTRIGMODEHEX
    << lfoModeUnsigned
    
    << LFODEPTHHEX
    << lfoDepthUnsigned
    
    << channelUnsigned << 0x06 << 0x00
    << channelUnsigned << 0x26 << 0x00
    << MIDI_SYSEX_END << FinishMidi();

}

void ofxDigitaktControl::sendDelayMessages(){

    unsigned char delayTimeUnsigned = (unsigned char)delayTime << 0x00;
    unsigned char delayPingPongUnsigned = (unsigned char)delayPingPong << 0x00;
    unsigned char delayStereoWidthUnsigned = (unsigned char)delayStereoWidth << 0x00;
    unsigned char delayFeedbackUnsigned = (unsigned char)delayFeedback << 0x00;
    unsigned char delayHighPassFltrUnsigned = (unsigned char)delayHighPassFltr << 0x00;
    unsigned char delayLowPassFltrUnsigned = (unsigned char)delayLowPassFltr << 0x00;
    unsigned char delayReverbSendUnsigned = (unsigned char)delayReverbSend << 0x00;
    unsigned char delayMixVolumeUnsigned = (unsigned char)delayMixVolume << 0x00;
    
    
    midiOut << StartMidi() << MIDI_SYSEX
    << 0x00 << 0x20 << 0x3C
    << 0x00
    << channelUnsigned
    
    
    << DELAYDELAYTIMEHEX
    << delayTimeUnsigned
//
    << DELAYPINGPONGHEX
    << delayPingPongUnsigned
    
    << DELAYSTEREOWIDTHHEX
    << delayStereoWidthUnsigned

    << DELAYFEEDBACKHEX
    << delayFeedbackUnsigned
    
    << DELAYHIGHPASSFLTRHEX
    << delayHighPassFltrUnsigned

    << DELAYLOWPASSFLTRHEX
    << delayReverbSendUnsigned
    
    << DELAYREVERBSENDHEX
    << delayReverbSendUnsigned
    
    << DELAYMIXVOLHEX
    << delayMixVolumeUnsigned
    
    << channelUnsigned << 0x06 << 0x00
    << channelUnsigned << 0x26 << 0x00
    << MIDI_SYSEX_END << FinishMidi();

}

void ofxDigitaktControl::sendReverbMessages(){

    unsigned char reverbPreDelayUnsigned = (unsigned char)reverbPreDelay << 0x00;
    unsigned char reverbDecayTimeUnsigned = (unsigned char)reverbDecayTime << 0x00;
    unsigned char reverbShelvingFreqUnsigned = (unsigned char)reverbShelvingFreq << 0x00;
    unsigned char reverbShelvingGainUnsigned = (unsigned char)reverbShelvingGain << 0x00;
    unsigned char reverbHighPassFltrUnsigned = (unsigned char)reverbHighPassFltr << 0x00;
    unsigned char reverbLowPassFltrUnsigned = (unsigned char)reverbLowPassFltr << 0x00;
    unsigned char reverbPrePostUnsigned = (unsigned char)reverbPrePost << 0x00;
    unsigned char reverbMixVolumeUnsigned = (unsigned char)reverbMixVolume << 0x00;
    
    
    midiOut << StartMidi() << MIDI_SYSEX
    << 0x00 << 0x20 << 0x3C
    << 0x00
    << channelUnsigned
    
    
    << REVERBPREDELAYHEX
    << reverbPreDelayUnsigned
//
    << REVERBDECAYHEX
    << reverbDecayTimeUnsigned
    
    << REVERBSHLVFREQHEX
    << reverbShelvingFreqUnsigned

    << REVERBSHLVGAINHEX
    << reverbShelvingGainUnsigned
    
    << REVERBHIGHPASSFLTRHEX
    << reverbHighPassFltrUnsigned

    << REVERLOWPASSFLTRHEX
    << reverbLowPassFltrUnsigned
    
    << REVERBPREPOSTCOMPHEX
    << reverbPrePostUnsigned
    
    << REVERBMIXVOLUMEHEX
    << reverbMixVolumeUnsigned
    
    << channelUnsigned << 0x06 << 0x00
    << channelUnsigned << 0x26 << 0x00
    << MIDI_SYSEX_END << FinishMidi();

}

void ofxDigitaktControl::sendCompressorMessages(){

    unsigned char compressorThresholdUnsigned = (unsigned char)compressorThreshold << 0x00;
    unsigned char compressorAttackUnsigned = (unsigned char)compressorAttack << 0x00;
    unsigned char compressorReleaseUnsigned = (unsigned char)compressorRelease << 0x00;
    unsigned char compressorMakeUpGainUnsigned = (unsigned char)compressorMakeUpGain << 0x00;
    unsigned char compressorPatternVolumeUnsigned = (unsigned char)compressorPatternVolume << 0x00;
    unsigned char compressorRatioUnsigned = (unsigned char)compressorRatio << 0x00;
    unsigned char compressorSideChainSourceUnsigned = (unsigned char)compressorSideChainSource << 0x00;
    unsigned char compressorSideChainFltrUnsigned = (unsigned char)compressorSideChainFltr << 0x00;
    unsigned char compressorDryWetMixUnsigned = (unsigned char)compressorDryWetMix << 0x00;
    
    
    midiOut << StartMidi() << MIDI_SYSEX
    << 0x00 << 0x20 << 0x3C
    << 0x00
    << channelUnsigned
    
    
    << COMPRESSORTHRSHLDHEX
    << compressorThresholdUnsigned
//
    << COMPRESSORATTACKHEX
    << compressorAttackUnsigned
    
    << COMPRESSORRELEASEHEX
    << compressorReleaseUnsigned

    << COMPRESSORMKUPGAINHEX
    << compressorMakeUpGainUnsigned
    
    << COMPRESSORPTTRNVOLHEX
    << compressorPatternVolumeUnsigned

    << COMPRESSORRATIOHEX
    << compressorRatioUnsigned
    
    << COMPRESSORSIDECHNSRCHEX
    << compressorSideChainSourceUnsigned
    
    << COMPRESSORSIDECHNFLTRHEX
    << compressorSideChainFltrUnsigned
    
    << COMPRESSORDRYWETMIXHEX
    << compressorDryWetMixUnsigned
    
    << channelUnsigned << 0x06 << 0x00
    << channelUnsigned << 0x26 << 0x00
    << MIDI_SYSEX_END << FinishMidi();

}
