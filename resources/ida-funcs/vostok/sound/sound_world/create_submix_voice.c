IXAudio2SubmixVoice *__thiscall vostok::sound::sound_world::create_submix_voice(
        vostok::sound::sound_world *this,
        unsigned __int8 input_channels_count,
        unsigned __int8 processing_stage)
{
  XAUDIO2_VOICE_DETAILS voice_details; // [esp+8h] [ebp-14h] BYREF
  IXAudio2SubmixVoice *submix_voice; // [esp+14h] [ebp-8h] BYREF
  HRESULT res; // [esp+18h] [ebp-4h]

  if ( !this->m_is_audio_device_exist )
    return 0;
  this->m_master_voice->GetVoiceDetails(this->m_master_voice, &voice_details);
  res = this->m_xaudio->CreateSubmixVoice(
          this->m_xaudio,
          &submix_voice,
          input_channels_count,
          44100u,
          0,
          processing_stage,
          0,
          0);
  res = submix_voice->SetOutputVoices(submix_voice, 0);
  return submix_voice;
}
