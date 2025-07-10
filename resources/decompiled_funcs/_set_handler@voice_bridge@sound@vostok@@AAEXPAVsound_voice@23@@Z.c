void __thiscall vostok::sound::voice_bridge::set_handler(
        vostok::sound::voice_bridge *this,
        vostok::sound::sound_voice *handler)
{
  this->m_handler = handler;
  if ( !this->m_handler )
    vostok::sound::voice_bridge::stop(this);
}
