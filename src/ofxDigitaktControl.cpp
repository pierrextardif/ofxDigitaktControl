//
//  ofxDigitaktControl.cpp
//
//  Created by Pierre Tardif on 26/09/2019.
//

#include "ofxDigitaktControl.hpp"

void ofxDigitaktControl::setup(){
    
    midiOut.listOutPorts();
    // connect
    midiOut.openPort(0); // by number
    
    guiON = true;

    mainGui.setup("mainParams");
    trackTrigGUI.setup("Track_Trigger");
    srcFltrGUI.setup("Source_Filter");
    ampLfoGUI.setup("Amp_Lfo");
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

    mainGui.add(channelGUI.set("channel", 1, 1, 8));

    midiTrack.add(trackMute.set("Mute", false));
    midiTrack.add(trackLevel.set("Level",50, 0, 127));
    midiTrack.add(midiTrackSend.set("Send TRACK", false));

    midiTrig.add(trigNote.set("Note", 0, -24, 24));
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
    midiSrc.add(midiSrcSend.set("Send SRC", false));

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
    midiAMP.add(ampPan.set("Pan", 0, -64, 63));
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
    midiReverb.add(reverbMixVolume.set("Mix Volume", 0, 0, 127));
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
    channelUnsigned = 0xB0 | (unsigned char)(channelGUI-1);
}

//--------------------------------------------------------------
void ofxDigitaktControl::update(){
    if(midiTrackSend){
        midiTrackSend = false;
        sendTrackMessages();
    }

    if(midiTrigSend){
        midiTrigSend = false;
        sendTRIGMessages();
    }

    if(midiSrcSend){
        midiSrcSend = false;
        sendSRCMessages();
    }

    if(midiFltrSend){
        midiFltrSend = false;
        sendFLTRMessages();
    }

    if(midiAmpSend){
        midiAmpSend = false;
        sendAMPMessages();
    }

    if(midiLfoSend){
        midiLfoSend = false;
        sendLFOMessages();
    }

    if(midiDelaySend){
        midiDelaySend = false;
        sendDelayMessages();
    }

    if(midiReverbSend){
        midiReverbSend = false;
        sendReverbMessages();
    }

    if(midiCompressorSend){
        midiCompressorSend = false;
        sendCompressorMessages();
    }
}

//--------------------------------------------------------------
void ofxDigitaktControl::draw(){
    if(guiON){
        mainGui.draw();
        trackTrigGUI.draw();
        srcFltrGUI.draw();
        ampLfoGUI.draw();
        effectsGUI.draw();
    }
}

//--------------------------------------------------------------
void ofxDigitaktControl::exit(){
    
    // clean up
    midiOut.closePort();
    
    channelGUI.removeListener(this, &ofxDigitaktControl::listenToChannel);
}

//--------------------------------------------------------------
void ofxDigitaktControl::listenToChannel(int& channel){
    channelUnsigned = 0xB0 | (unsigned char)(channel-1);
    
    if(PRINT)cout << "this is the channel :  " << channel << endl;
    
}

//--------------------------------------------------------------
void ofxDigitaktControl::sendTrackMessages(){

    unsigned char trackMuteUnsigned =  (unsigned char)trackMute << 0x00;
    unsigned char trackLevelUnsigned = (unsigned char)trackLevel << 0x00;
    
    vector < unsigned char > midiSysExMsg = initMidiMessage();
    
    midiSysExMsg.push_back(channelUnsigned);
    midiSysExMsg.push_back(TRACKMUTEHEX);
    midiSysExMsg.push_back(trackMuteUnsigned);
    midiSysExMsg.push_back(TRACKLEVELHEX);
    midiSysExMsg.push_back(trackLevelUnsigned);
    wrapMidiMessageCC(&midiSysExMsg);
    
    midiSysExMsg.push_back(MIDI_SYSEX_END);
    midiOut.sendMidiBytes(midiSysExMsg);
    
}

//--------------------------------------------------------------
void ofxDigitaktControl::sendTRIGMessages(){

    // trig note not wuite right :/
    unsigned char trigNoteUnsigned = (unsigned char)(ofMap(trigNote, -24, 24, 34, 84)) << 0x00;
    unsigned char trigVelocityUnsigned = (unsigned char)trigVelocity << 0x00;
    unsigned char trigLengthUnsigned = (unsigned char)trigLength << 0x00;
    unsigned char trigFilterTrigUnsigned = (unsigned char)trigFilterTrig << 0x00;
    unsigned char trigLFOTrigUnsigned = (unsigned char)trigLFOTrig << 0x00;
    
    // start Message
    vector < unsigned char > midiSysExMsg = initMidiMessage();
    
    // CC Messages
    midiSysExMsg.push_back(channelUnsigned);
    midiSysExMsg.push_back(TRIGNOTEHEX);
    midiSysExMsg.push_back(trigNoteUnsigned);
    midiSysExMsg.push_back(TRIGVELOCITYHEX);
    midiSysExMsg.push_back(trigVelocityUnsigned);
    midiSysExMsg.push_back(TRIGLENGTHHEX);
    midiSysExMsg.push_back(trigLengthUnsigned);
    midiSysExMsg.push_back(TRIGFLTRTRIGHEX);
    midiSysExMsg.push_back(trigFilterTrigUnsigned);
    midiSysExMsg.push_back(TRIGLFOTRIGHEX);
    midiSysExMsg.push_back(trigLFOTrigUnsigned);
    wrapMidiMessageCC(&midiSysExMsg);
    
    // end & send Message
    midiSysExMsg.push_back(MIDI_SYSEX_END);
    midiOut.sendMidiBytes(midiSysExMsg);
    
}

//--------------------------------------------------------------
void ofxDigitaktControl::sendSRCMessages(){
    
    unsigned char tuneUnsignedMSB = (unsigned char)(ofMap(floor(srcTune), -24, 24, 41, 88)) << 0x00;
    unsigned char tuneUnsignedLSB = (unsigned char)(ofMap(srcTune - floor(srcTune), 0, 1, 0, 127)) << 0x00;
    
    unsigned char playModeUnsigned = (unsigned char)(srcPlayMode) << 0x00;
    unsigned char bitReductionUnsigned = (unsigned char)srcBitReduction << 0x00;
    unsigned char sampleUnsigned = (unsigned char)srcSampleSlot << 0x00;
    
    unsigned char startUnsignedMSB = (unsigned char)(floor(srcStart)) << 0x00;
    unsigned char startUnsignedLSB = (unsigned char)(ofMap(srcStart - floor(srcStart), 0, 1, 0, 127)) << 0x00;
    
    unsigned char lenghtUnsignedMSB = (unsigned char)(floor(srcFinish)) << 0x00;
    unsigned char lengthUnsignedLSB = (unsigned char)(ofMap(srcFinish - floor(srcFinish), 0, 1, 0, 127)) << 0x00;
    
    
    unsigned char loopUnsignedMSB = (unsigned char)(floor(srcLoop)) << 0x00;
    unsigned char loopUnsignedLSB = (unsigned char)(ofMap(srcLoop - floor(srcLoop), 0, 1, 0, 127)) << 0x00;
    
    unsigned char sampleLevelUnsigned = (unsigned char)srcSampleLevel << 0x00;
    
    // start Message
    vector < unsigned char > midiSysExMsg = initMidiMessage();
    
    //NRPN messages
    addNRPNMessage(&midiSysExMsg, SRCTUNEMSBHEX, SRCTUNELSBHEX, tuneUnsignedMSB, tuneUnsignedLSB);
    addNRPNMessage(&midiSysExMsg, SRCSTARTMSBHEX, SRCSTARTLSBHEX, startUnsignedMSB, startUnsignedLSB);
    addNRPNMessage(&midiSysExMsg, SRCLENGTHMSBHEX, SRCLENGTHMSBHEX, lenghtUnsignedMSB, lengthUnsignedLSB);
    addNRPNMessage(&midiSysExMsg, SRCLOOPMSBHEX, SRCLOOPLSBHEX, loopUnsignedMSB, loopUnsignedMSB);
    
    // CC Messages
    midiSysExMsg.push_back(channelUnsigned);
    midiSysExMsg.push_back(SRCPLAYMODEHEX);
    midiSysExMsg.push_back(playModeUnsigned);
    midiSysExMsg.push_back(SRCBITREDUCTIONHEX);
    midiSysExMsg.push_back(bitReductionUnsigned);
    midiSysExMsg.push_back(SRCSAMPLESLOTHEX);
    midiSysExMsg.push_back(sampleUnsigned);
    midiSysExMsg.push_back(SRCSAMPLELEVEL);
    midiSysExMsg.push_back(sampleLevelUnsigned);
    wrapMidiMessageCC(&midiSysExMsg);
    
    // end & send Message
    midiSysExMsg.push_back(MIDI_SYSEX_END);
    midiOut.sendMidiBytes(midiSysExMsg);
}

//--------------------------------------------------------------
void ofxDigitaktControl::sendFLTRMessages(){
    
    unsigned char fltrAttackUnsigned = (unsigned char)fltrAttack << 0x00;
    unsigned char fltrDecayUnsigned = (unsigned char)fltrDecay << 0x00;
    unsigned char fltrSustainUnsigned = (unsigned char)fltrSustain << 0x00;
    unsigned char fltrReleaseUnsigned = (unsigned char)fltrRelease << 0x00;
    
    unsigned char frequencyMSBUnsigned = (unsigned char)floor(frequency) << 0x00;
    unsigned char frequencyLSBUnsigned = (unsigned char)(ofMap(frequency - floor(frequency), 0, 1, 0, 127)) << 0x00;
    
    unsigned char resonnanceMSBUnsigned = (unsigned char)floor(resonnance) << 0x00;
    unsigned char resonnanceLSBUnsigned = (unsigned char)(ofMap(resonnance - floor(resonnance), 0, 1, 0, 127)) << 0x00;

    unsigned char fltrTypeUnsigned = (unsigned char)fltrType << 0x00;
    
    unsigned char fltrEnvelopMSBUnsigned = ( (unsigned char)(ofMap(floor(fltrEnvelop), -64, 63, 0, 127) )) << 0x00;
    unsigned char fltrEnvelopLSBUnsigned = (unsigned char)(ofMap(fltrEnvelop - floor(fltrEnvelop), 0, 1, 0, 127)) << 0x00;
    
    // start Message
    vector < unsigned char > midiSysExMsg = initMidiMessage();
    
    //NRPN messages
    addNRPNMessage(&midiSysExMsg, FLTRFREQMSBHEX, FLTRFREQLSBHEX, frequencyMSBUnsigned, frequencyLSBUnsigned);
    addNRPNMessage(&midiSysExMsg, FLTRRESONNANCEMSBHEX, FLTRRESONNANCELSBHEX, resonnanceMSBUnsigned, resonnanceLSBUnsigned);
    addNRPNMessage(&midiSysExMsg, FLTRRENVDEPTHMSBHEX, FLTRRENVDEPTHLSBHEX, fltrEnvelopMSBUnsigned, fltrEnvelopLSBUnsigned);
    
    // CC Messages
    midiSysExMsg.push_back(channelUnsigned);
    midiSysExMsg.push_back(FLTRATTACKHEX);
    midiSysExMsg.push_back(fltrAttackUnsigned);
    midiSysExMsg.push_back(FLTRDECAYHEX);
    midiSysExMsg.push_back(fltrDecayUnsigned);
    midiSysExMsg.push_back(FLTRSUSTAINHEX);
    midiSysExMsg.push_back(fltrSustainUnsigned);
    midiSysExMsg.push_back(FLTRRELEASEHEX);
    midiSysExMsg.push_back(fltrReleaseUnsigned);
    midiSysExMsg.push_back(FLTRTYPEHEX);
    midiSysExMsg.push_back(fltrTypeUnsigned);
    wrapMidiMessageCC(&midiSysExMsg);
    
    // end & send Message
    midiSysExMsg.push_back(MIDI_SYSEX_END);
    midiOut.sendMidiBytes(midiSysExMsg);
}

//--------------------------------------------------------------
void ofxDigitaktControl::sendAMPMessages(){

    unsigned char ampAttackUnsigned = (unsigned char)(ampAttack) << 0x00;
    unsigned char ampHoldUnsigned = (unsigned char)ampHold << 0x00;
    unsigned char ampDecayUnsigned = (unsigned char)ampDecay << 0x00;
    
    unsigned char ampOverdriveMSBUnsigned = (unsigned char) floor(ampOverdrive) << 0x00;
    unsigned char ampOverdriveLSBUnsigned = (unsigned char)(ofMap(ampOverdrive - floor(ampOverdrive), 0, 1, 0, 127)) << 0x00;
    
    unsigned char ampDelayMSBUnsigned = (unsigned char) floor(ampDelay) << 0x00;
    unsigned char ampDelayLSBUnsigned = (unsigned char) (ofMap(ampDelay - floor(ampDelay), 0, 1, 0, 127)) << 0x00;
    
    unsigned char ampReverbMSBUnsigned = (unsigned char) floor(ampReverb) << 0x00;
    unsigned char ampReverbLSBUnsigned = (unsigned char) (ofMap(ampReverb - floor(ampReverb), 0, 1, 0, 127)) << 0x00;
    
    unsigned char ampPanUnsigned = (unsigned char)(ofMap(ampPan, -63, 64, 0, 127)) << 0x00;
    
    unsigned char ampVlmMSBUnsigned = ( (unsigned char) floor(ampVolume) ) << 0x00;
    unsigned char ampVlmLSBUnsigned = (unsigned char) (ofMap(ampVolume - floor(ampVolume), 0, 1, 0, 127)) << 0x00;
    
    // start Message
    vector < unsigned char > midiSysExMsg = initMidiMessage();
    
    //NRPN messages
    addNRPNMessage(&midiSysExMsg, AMPOVERDRIVEMSBHEX, AMPOVERDRIVELSBHEX, ampOverdriveMSBUnsigned, ampOverdriveLSBUnsigned);
    addNRPNMessage(&midiSysExMsg, AMPDELAYMSBHEX, AMPDELAYLSBHEX, ampDelayMSBUnsigned, ampDelayLSBUnsigned);
    addNRPNMessage(&midiSysExMsg, AMPREVERBMSBHEX, AMPREVERBLSBHEX, ampReverbMSBUnsigned, ampReverbLSBUnsigned);
    addNRPNMessage(&midiSysExMsg, AMPVOLUMEMSBHEX, AMPVOLUMELSBHEX, ampVlmMSBUnsigned, ampVlmLSBUnsigned);
    
    
    // CC Messages
    midiSysExMsg.push_back(channelUnsigned);
    midiSysExMsg.push_back(AMPATTACKHEX);
    midiSysExMsg.push_back(ampAttackUnsigned);
    midiSysExMsg.push_back(AMPHOLDHEX);
    midiSysExMsg.push_back(ampHoldUnsigned);
    midiSysExMsg.push_back(AMPDECAYHEX);
    midiSysExMsg.push_back(ampDecayUnsigned);
    midiSysExMsg.push_back(AMPPANHEX);
    midiSysExMsg.push_back(ampPanUnsigned);
    wrapMidiMessageCC(&midiSysExMsg);
    
    midiSysExMsg.push_back(MIDI_SYSEX_END);
    midiOut.sendMidiBytes(midiSysExMsg);
    
}

//--------------------------------------------------------------
void ofxDigitaktControl::sendLFOMessages(){

    unsigned char lfoSpeedMSBUnsigned = (unsigned char) (ofMap(lfoSpeed, -64, 63, 0, 127) )  << 0x00;
    unsigned char lfoSpeedLSBUnsigned = (unsigned char) (ofMap(lfoSpeed - floor(lfoSpeed), 0, 1, 0, 127)) << 0x00;
    
    unsigned char lfoMultiplierUnsigned = (unsigned char)lfoMultiplier << 0x00;
    unsigned char lfoFadeInOutUnsigned = (unsigned char)lfoFadeInOut << 0x00;
    unsigned char lfoDestinationUnsigned = (unsigned char)lfoDestination << 0x00;
    unsigned char lfoWaveUnsigned = (unsigned char)lfoWave << 0x00;
    unsigned char lfoStartPhaseUnsigned = (unsigned char)lfoStartPhase << 0x00;
    unsigned char lfoModeUnsigned = (unsigned char)lfoMode << 0x00;
    
    unsigned char lfoDepthMSBUnsigned = (unsigned char) (ofMap(lfoDepth, -64, 63, 0, 127) )  << 0x00;
    unsigned char lfoDepthLSBUnsigned = (unsigned char) (ofMap(lfoDepth - floor(lfoDepth), 0, 1, 0, 127))  << 0x00;
    
    // start Message
    vector < unsigned char > midiSysExMsg = initMidiMessage();
    
    //NRPN messages
    addNRPNMessage(&midiSysExMsg, LFOSPEEDMSBHEX, LFOSPEEDLSBHEX, lfoSpeedMSBUnsigned, lfoSpeedLSBUnsigned);
    addNRPNMessage(&midiSysExMsg, LFODEPTHMSBHEX, LFODEPTHLSBHEX, lfoDepthMSBUnsigned, lfoDepthLSBUnsigned);
    
    // CC Messages
    midiSysExMsg.push_back(channelUnsigned);
    midiSysExMsg.push_back(LFOMULTIPLIERHEX);
    midiSysExMsg.push_back(lfoMultiplierUnsigned);
    midiSysExMsg.push_back(LFOFADEHEX);
    midiSysExMsg.push_back(lfoFadeInOutUnsigned);
    midiSysExMsg.push_back(LFODESTINATIONHEX);
    midiSysExMsg.push_back(lfoDestinationUnsigned);
    midiSysExMsg.push_back(LFOWAVEFORMHEX);
    midiSysExMsg.push_back(lfoWaveUnsigned);
    midiSysExMsg.push_back(LFOSTARTPHASEHEX);
    midiSysExMsg.push_back(lfoStartPhaseUnsigned);
    midiSysExMsg.push_back(LFOTRIGMODEHEX);
    midiSysExMsg.push_back(lfoModeUnsigned);
    wrapMidiMessageCC(&midiSysExMsg);
    
    midiSysExMsg.push_back(MIDI_SYSEX_END);
    midiOut.sendMidiBytes(midiSysExMsg);
}

//--------------------------------------------------------------
void ofxDigitaktControl::sendDelayMessages(){

    unsigned char delayTimeMSBUnsigned = (unsigned char) floor(delayTime) << 0x00;
    unsigned char delayTimeLSBUnsigned = (unsigned char) (ofMap(delayTime - floor(delayTime), 0, 1, 0, 127))  << 0x00;
    
    unsigned char delayPingPongUnsigned = (unsigned char)delayPingPong << 0x00;
    
    unsigned char delayStereoWidthMSBUnsigned = (unsigned char) (ofMap(delayStereoWidth, -64, 63, 0, 127) )  << 0x00;
    unsigned char delayStereoWidthLSBUnsigned = (unsigned char) (ofMap(delayStereoWidth - floor(delayStereoWidth), 0, 1, 0, 127))  << 0x00;
    
    unsigned char delayFeedbackUnsigned = (unsigned char)delayFeedback << 0x00;
    
    unsigned char delayHighPassFltrMSBUnsigned  = (unsigned char) floor(delayHighPassFltr) << 0x00;
    unsigned char delayHighPassFltrLSBUnsigned  = (unsigned char) (ofMap(delayHighPassFltr - floor(delayHighPassFltr), 0, 1, 0, 127))  << 0x00;
    unsigned char delayLowPassFltrMSBUnsigned   = (unsigned char) floor(delayLowPassFltr) << 0x00;
    unsigned char delayLowPassFltrLSBUnsigned   = (unsigned char) (ofMap(delayLowPassFltr - floor(delayLowPassFltr), 0, 1, 0, 127)) << 0x00;
    unsigned char delayReverbSendMSBUnsigned    = (unsigned char) floor(delayReverbSend) << 0x00;
    unsigned char delayReverbSendLSBUnsigned    = (unsigned char) (ofMap(delayReverbSend - floor(delayReverbSend), 0, 1, 0, 127)) << 0x00;
    unsigned char delayMixVolumeMSBUnsigned     = (unsigned char) floor(delayMixVolume) << 0x00;
    unsigned char delayMixVolumeLSBUnsigned     = (unsigned char) (ofMap(delayMixVolume - floor(delayMixVolume), 0, 1, 0, 127)) << 0x00;
    
    // start Message
    vector < unsigned char > midiSysExMsg = initMidiMessage();
    
    //NRPN messages
    addNRPNMessage(&midiSysExMsg, DELAYDELAYTIMEMSBHEX, DELAYDELAYTIMELSBHEX,       delayTimeMSBUnsigned, delayTimeLSBUnsigned);
    addNRPNMessage(&midiSysExMsg, DELAYSTEREOWIDTHMSBHEX, DELAYSTEREOWIDTHLSBHEX,   delayStereoWidthMSBUnsigned, delayStereoWidthLSBUnsigned);
    addNRPNMessage(&midiSysExMsg, DELAYHIGHPASSFLTRMSBHEX, DELAYHIGHPASSFLTRLSBHEX, delayHighPassFltrMSBUnsigned, delayHighPassFltrLSBUnsigned);
    addNRPNMessage(&midiSysExMsg, DELAYLOWPASSFLTRMSBHEX, DELAYLOWPASSFLTRLSBHEX,   delayLowPassFltrMSBUnsigned, delayLowPassFltrLSBUnsigned);
    addNRPNMessage(&midiSysExMsg, DELAYREVERBSENDMSBHEX, DELAYREVERBSENDLSBHEX,     delayReverbSendMSBUnsigned, delayReverbSendLSBUnsigned);
    addNRPNMessage(&midiSysExMsg, DELAYMIXVOLMSBHEX, DELAYMIXVOLLSBHEX,             delayMixVolumeMSBUnsigned, delayMixVolumeLSBUnsigned);
    
    // CC Messages
    midiSysExMsg.push_back(channelUnsigned);
    midiSysExMsg.push_back(DELAYPINGPONGHEX);
    midiSysExMsg.push_back(delayPingPongUnsigned);
    midiSysExMsg.push_back(DELAYFEEDBACKHEX);
    midiSysExMsg.push_back(delayFeedbackUnsigned);
    wrapMidiMessageCC(&midiSysExMsg);
    
    midiSysExMsg.push_back(MIDI_SYSEX_END);
    midiOut.sendMidiBytes(midiSysExMsg);
}

//--------------------------------------------------------------
void ofxDigitaktControl::sendReverbMessages(){

    unsigned char reverbPreDelayMSBUnsigned = (unsigned char) floor(reverbPreDelay) << 0x00;
    unsigned char reverbPreDelayLSBUnsigned = (unsigned char) (ofMap(reverbPreDelay - floor(reverbPreDelay), 0, 1, 0, 127))  << 0x00;
    
    unsigned char reverbDecayTimeUnsigned = (unsigned char)reverbDecayTime << 0x00;
    
    unsigned char reverbShelvingFreqMSBUnsigned = (unsigned char) floor(reverbShelvingFreq) << 0x00;
    unsigned char reverbShelvingFreqLSBUnsigned = (unsigned char) (ofMap(reverbShelvingFreq - floor(reverbShelvingFreq), 0, 1, 0, 127))  << 0x00;
    unsigned char reverbShelvingGainMSBUnsigned = (unsigned char) floor(reverbShelvingGain) << 0x00;
    unsigned char reverbShelvingGainLSBUnsigned = (unsigned char) (ofMap(reverbShelvingGain - floor(reverbShelvingGain), 0, 1, 0, 127))  << 0x00;
    unsigned char reverbHighPassFltrMSBUnsigned = (unsigned char) floor(reverbHighPassFltr) << 0x00;
    unsigned char reverbHighPassFltrLSBUnsigned = (unsigned char) (ofMap(reverbHighPassFltr - floor(reverbHighPassFltr), 0, 1, 0, 127))  << 0x00;
    unsigned char reverbLowPassFltrMSBUnsigned = (unsigned char) floor(reverbLowPassFltr) << 0x00;
    unsigned char reverbLowPassFltrLSBUnsigned = (unsigned char) (ofMap(reverbLowPassFltr - floor(reverbLowPassFltr), 0, 1, 0, 127))  << 0x00;
    
    unsigned char reverbLowPassFltrUnsigned = (unsigned char)reverbLowPassFltr << 0x00;
    unsigned char reverbPrePostUnsigned = (unsigned char)reverbPrePost << 0x00;
    
    unsigned char reverbMixVolumeMSBUnsigned = (unsigned char) floor(reverbMixVolume) << 0x00;
    unsigned char reverbMixVolumeLSBUnsigned = (unsigned char) (ofMap(reverbMixVolume - floor(reverbMixVolume), 0, 1, 0, 127))  << 0x00;
    
    // start Message
    vector < unsigned char > midiSysExMsg = initMidiMessage();
    
    //NRPN messages
    addNRPNMessage(&midiSysExMsg, REVERBPREDELAYMSBHEX, REVERBPREDELAYLSBHEX,           reverbPreDelayMSBUnsigned, reverbPreDelayLSBUnsigned);
    addNRPNMessage(&midiSysExMsg, REVERBSHLVFREQMSBHEX, REVERBSHLVFREQLSBHEX,           reverbShelvingFreqMSBUnsigned, reverbShelvingFreqLSBUnsigned);
    addNRPNMessage(&midiSysExMsg, REVERBSHLVGAINMSBHEX, REVERBSHLVGAINLSBHEX,           reverbShelvingGainMSBUnsigned, reverbShelvingGainMSBUnsigned);
    addNRPNMessage(&midiSysExMsg, REVERBHIGHPASSFLTRMSBHEX, REVERBHIGHPASSFLTRLSBHEX,   reverbHighPassFltrMSBUnsigned, reverbHighPassFltrLSBUnsigned);
    addNRPNMessage(&midiSysExMsg, REVERLOWPASSFLTRMSBHEX, REVERLOWPASSFLTRLSBHEX,       reverbLowPassFltrMSBUnsigned, reverbLowPassFltrLSBUnsigned);
    addNRPNMessage(&midiSysExMsg, REVERBMIXVOLUMEMSBHEX, REVERBMIXVOLUMELSBHEX,         reverbMixVolumeMSBUnsigned, reverbMixVolumeLSBUnsigned);
    
    
    // CC Messages
    midiSysExMsg.push_back(channelUnsigned);
    midiSysExMsg.push_back(REVERBDECAYHEX);
    midiSysExMsg.push_back(reverbDecayTimeUnsigned);
    midiSysExMsg.push_back(REVERBPREPOSTCOMPHEX);
    midiSysExMsg.push_back(reverbPrePostUnsigned);
    wrapMidiMessageCC(&midiSysExMsg);
    
    midiSysExMsg.push_back(MIDI_SYSEX_END);
    midiOut.sendMidiBytes(midiSysExMsg);
}

//--------------------------------------------------------------
void ofxDigitaktControl::sendCompressorMessages(){

    unsigned char compressorThresholdUnsigned = (unsigned char)compressorThreshold << 0x00;
    unsigned char compressorAttackUnsigned = (unsigned char)compressorAttack << 0x00;
    unsigned char compressorReleaseUnsigned = (unsigned char)compressorRelease << 0x00;
    
    unsigned char compressorMakeUpGainMSBUnsigned = (unsigned char) (ofMap(compressorMakeUpGain, 0, 24, 0, 127) )  << 0x00;
    unsigned char compressorMakeUpGainLSBUnsigned = (unsigned char) (ofMap(compressorMakeUpGain - floor(compressorMakeUpGain), 0, 1, 0, 127))  << 0x00;
    
    unsigned char compressorPatternVolumeUnsigned = (unsigned char)compressorPatternVolume << 0x00;
    unsigned char compressorRatioUnsigned = (unsigned char)compressorRatio << 0x00;
    unsigned char compressorSideChainSourceUnsigned = (unsigned char)compressorSideChainSource << 0x00;
    unsigned char compressorSideChainFltrUnsigned = (unsigned char)ofMap(compressorSideChainFltr, -64, 63, 0, 127) << 0x00;
    unsigned char compressorDryWetMixUnsigned = (unsigned char)compressorDryWetMix << 0x00;
    
    // start Message
    vector < unsigned char > midiSysExMsg = initMidiMessage();
    
    //NRPN messages
    addNRPNMessage(&midiSysExMsg, COMPRESSORMKUPGAINMSBHEX, COMPRESSORMKUPGAINLSBHEX, compressorMakeUpGainMSBUnsigned, compressorMakeUpGainLSBUnsigned);
        
    // CC Messages
    midiSysExMsg.push_back(channelUnsigned);
    midiSysExMsg.push_back(COMPRESSORTHRSHLDHEX);
    midiSysExMsg.push_back(compressorThresholdUnsigned);
    midiSysExMsg.push_back(COMPRESSORATTACKHEX);
    midiSysExMsg.push_back(compressorAttackUnsigned);
    midiSysExMsg.push_back(COMPRESSORRELEASEHEX);
    midiSysExMsg.push_back(compressorReleaseUnsigned);
    midiSysExMsg.push_back(COMPRESSORPTTRNVOLHEX);
    midiSysExMsg.push_back(compressorPatternVolumeUnsigned);
    midiSysExMsg.push_back(COMPRESSORRATIOHEX);
    midiSysExMsg.push_back(compressorRatioUnsigned);
    midiSysExMsg.push_back(COMPRESSORSIDECHNSRCHEX);
    midiSysExMsg.push_back(compressorSideChainSourceUnsigned);
    midiSysExMsg.push_back(COMPRESSORSIDECHNFLTRHEX);
    midiSysExMsg.push_back(compressorSideChainFltrUnsigned);
    midiSysExMsg.push_back(COMPRESSORDRYWETMIXHEX);
    midiSysExMsg.push_back(compressorDryWetMixUnsigned);
    wrapMidiMessageCC(&midiSysExMsg);
    
    midiSysExMsg.push_back(MIDI_SYSEX_END);
    midiOut.sendMidiBytes(midiSysExMsg);
    
}

//--------------------------------------------------------------
vector < unsigned char > ofxDigitaktControl::initMidiMessage(){
    vector < unsigned char > sysExMsg;
    
    sysExMsg.push_back(MIDI_SYSEX);
    sysExMsg.push_back(ELEKTRON_SysExIDNumber_0);
    sysExMsg.push_back(ELEKTRON_SysExIDNumber_1);
    sysExMsg.push_back(ELEKTRON_SysExIDNumber_2);
    // talk to all machines from Elektron using 0x00
    sysExMsg.push_back(0x00);
    
    return sysExMsg;
}

void ofxDigitaktControl::wrapMidiMessageCC(vector < unsigned char >* sysExMsg){
    sysExMsg->push_back(channelUnsigned);
    sysExMsg->push_back(CCMSBVALUE);
    sysExMsg->push_back(0x7F);
    sysExMsg->push_back(channelUnsigned);
    sysExMsg->push_back(CCLSBVALUE);
    sysExMsg->push_back(0x7F);
}

//--------------------------------------------------------------
void ofxDigitaktControl::addNRPNMessage(vector < unsigned char > * sysExMsg, unsigned char addressMSB, unsigned char addressLSB, unsigned char valMSB, unsigned valLSB ){
    
    // MSB address
    sysExMsg->push_back(channelUnsigned);
    sysExMsg->push_back(CCMSBADRESS);
    sysExMsg->push_back(addressMSB);
    
    // LSB address
    sysExMsg->push_back(channelUnsigned);
    sysExMsg->push_back(CCLSBADRESS);
    sysExMsg->push_back(addressLSB);
    
    // MSB val
    sysExMsg->push_back(channelUnsigned);
    sysExMsg->push_back(CCMSBVALUE);
    sysExMsg->push_back(valMSB);
    
    // LSB val
    sysExMsg->push_back(channelUnsigned);
    sysExMsg->push_back(CCLSBVALUE);
    sysExMsg->push_back(valLSB);
    
    // MSB & LSB running status in effect
    sysExMsg->push_back(channelUnsigned);
    sysExMsg->push_back(CCMSBADRESS);
    sysExMsg->push_back(0x7F);
    sysExMsg->push_back(channelUnsigned);
    sysExMsg->push_back(CCLSBADRESS);
    sysExMsg->push_back(0x7F);

}
