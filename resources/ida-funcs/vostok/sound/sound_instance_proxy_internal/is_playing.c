BOOL __thiscall vostok::sound::sound_instance_proxy_internal::is_playing(
        vostok::sound::sound_instance_proxy_internal *this)
{
  return this->m_propagators.m_first != 0;
}
