void __thiscall vostok::sound::sound_voice::stop(vostok::sound::sound_voice *this)
{
  this->m_is_playing = 0;
  vostok::sound::voice_bridge::stop(this->m_voice);
  vostok::sound::voice_bridge::flush_source_buffers(this->m_voice);
}
