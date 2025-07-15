void __thiscall vostok::sound::voice_bridge::flush_source_buffers(vostok::sound::voice_bridge *this)
{
  this->m_source_voice->FlushSourceBuffers(this->m_source_voice);
}
