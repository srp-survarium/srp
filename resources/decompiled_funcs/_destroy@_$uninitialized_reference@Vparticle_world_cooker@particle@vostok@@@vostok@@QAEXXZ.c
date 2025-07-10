void __thiscall vostok::uninitialized_reference<vostok::particle::particle_world_cooker>::destroy(
        vostok::uninitialized_reference<vostok::particle::particle_world_cooker> *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  ((void (__thiscall *)(vostok::particle::particle_world_cooker *, _DWORD))this->m_variable->~vostok::particle::particle_world_cooker)(
    this->m_variable,
    0);
  this->m_initialized = 0;
}
