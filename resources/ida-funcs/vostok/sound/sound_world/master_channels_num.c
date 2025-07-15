unsigned __int8 __thiscall vostok::sound::sound_world::master_channels_num(vostok::sound::sound_world *this)
{
  XAUDIO2_VOICE_DETAILS voice_details; // [esp+4h] [ebp-Ch] BYREF

  this->m_master_voice->GetVoiceDetails(this->m_master_voice, &voice_details);
  return voice_details.InputChannels;
}
