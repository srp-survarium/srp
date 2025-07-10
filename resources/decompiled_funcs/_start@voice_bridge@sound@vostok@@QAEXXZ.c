void __thiscall vostok::sound::voice_bridge::start(vostok::sound::voice_bridge *this)
{
  this->m_source_voice->Start(this->m_source_voice, 0, 0);
}
