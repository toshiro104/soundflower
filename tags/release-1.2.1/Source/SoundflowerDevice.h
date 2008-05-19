/*
  File:SoundflowerDevice.h

  Version:1.0.1
    ma++ ingalls  |  cycling '74  |  Copyright (C) 2004  |  soundflower.com

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef _SAMPLEAUDIODEVICE_H
#define _SAMPLEAUDIODEVICE_H

#include <IOKit/audio/IOAudioDevice.h>

#define AUDIO_ENGINES_KEY			"AudioEngines"
#define DESCRIPTION_KEY				"Description"
#define BLOCK_SIZE_KEY				"BlockSize"
#define NUM_BLOCKS_KEY				"NumBlocks"
#define NUM_STREAMS_KEY				"NumStreams"
#define FORMATS_KEY				"Formats"
#define SAMPLE_RATES_KEY			"SampleRates"
#define SEPARATE_STREAM_BUFFERS_KEY		"SeparateStreamBuffers"
#define SEPARATE_INPUT_BUFFERS_KEY		"SeparateInputBuffers"

#define SoundflowerDevice com_MyCompany_driver_SoundflowerDevice

class SoundflowerDevice : public IOAudioDevice
{
    friend class Soundflower_AudioEngine;
    
    OSDeclareDefaultStructors(SoundflowerDevice)
    
    virtual bool initHardware(IOService *provider);
    virtual bool createAudioEngines();
    
    static IOReturn volumeChangeHandler(IOService *target, IOAudioControl *volumeControl, SInt32 oldValue, SInt32 newValue);
    virtual IOReturn volumeChanged(IOAudioControl *volumeControl, SInt32 oldValue, SInt32 newValue);
    
    static IOReturn outputMuteChangeHandler(IOService *target, IOAudioControl *muteControl, SInt32 oldValue, SInt32 newValue);
    virtual IOReturn outputMuteChanged(IOAudioControl *muteControl, SInt32 oldValue, SInt32 newValue);

    static IOReturn gainChangeHandler(IOService *target, IOAudioControl *gainControl, SInt32 oldValue, SInt32 newValue);
    virtual IOReturn gainChanged(IOAudioControl *gainControl, SInt32 oldValue, SInt32 newValue);
    
    static IOReturn inputMuteChangeHandler(IOService *target, IOAudioControl *muteControl, SInt32 oldValue, SInt32 newValue);
    virtual IOReturn inputMuteChanged(IOAudioControl *muteControl, SInt32 oldValue, SInt32 newValue);
    
   // static IOReturn passThruChangeHandler(IOService *target, IOAudioControl *passThruControl, SInt32 oldValue, SInt32 newValue);
   // virtual IOReturn passThruChanged(IOAudioControl *passThruControl, SInt32 oldValue, SInt32 newValue);
    
    SInt32 mVolume[16];
    SInt32 mMuteOut[16];
    SInt32 mMuteIn[16];
    SInt32 mGain[16];
    //SInt32 mThru[16];
};

#endif /* _SAMPLEAUDIODEVICE_H */