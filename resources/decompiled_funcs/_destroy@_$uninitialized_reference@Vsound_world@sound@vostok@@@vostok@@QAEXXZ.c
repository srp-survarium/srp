void __thiscall vostok::uninitialized_reference<vostok::sound::sound_world>::destroy(
        vostok::uninitialized_reference<vostok::sound::sound_world> *this)
{
  ((void (__thiscall *)(vostok::sound::sound_world *, _DWORD))this->m_variable->~vostok::sound::world)(
    this->m_variable,
    0);
  this->m_initialized = 0;
}
