void __thiscall vostok::sound::voice_bridge::stop(vostok::sound::voice_bridge *this)
{
  this->m_source_voice->Stop(this->m_source_voice, 0, 0);
}
