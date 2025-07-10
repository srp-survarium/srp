void __thiscall vostok::uninitialized_reference<vostok::network::network_world>::destroy(
        vostok::uninitialized_reference<vostok::network::network_world> *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  ((void (__thiscall *)(vostok::network::network_world *, _DWORD))this->m_variable->~vostok::network::network_world)(
    this->m_variable,
    0);
  this->m_initialized = 0;
}
