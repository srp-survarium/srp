unsigned int __thiscall vostok::sound::voice_bridge::buffers_queued(vostok::sound::voice_bridge *this)
{
  XAUDIO2_VOICE_STATE vstate; // [esp+4h] [ebp-10h] BYREF

  ((void (__thiscall *)(IXAudio2SourceVoice *, IXAudio2SourceVoice *, XAUDIO2_VOICE_STATE *))this->m_source_voice->GetState)(
    this->m_source_voice,
    this->m_source_voice,
    &vstate);
  return vstate.BuffersQueued;
}
