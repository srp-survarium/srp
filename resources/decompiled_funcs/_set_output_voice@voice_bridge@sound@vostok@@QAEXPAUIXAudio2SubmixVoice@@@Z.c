void __thiscall vostok::sound::voice_bridge::set_output_voice(
        vostok::sound::voice_bridge *this,
        IXAudio2SubmixVoice *output_voice)
{
  XAUDIO2_VOICE_SENDS sends; // [esp+4h] [ebp-10h] BYREF
  XAUDIO2_SEND_DESCRIPTOR desc; // [esp+Ch] [ebp-8h] BYREF

  if ( output_voice )
  {
    desc.Flags = 0;
    desc.pOutputVoice = output_voice;
    sends.SendCount = 1;
    sends.pSends = &desc;
    this->m_source_voice->SetOutputVoices(this->m_source_voice, &sends);
  }
  else
  {
    this->m_source_voice->SetOutputVoices(this->m_source_voice, 0);
  }
}
