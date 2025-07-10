void __thiscall vostok::particle::particle_system_instance::~particle_system_instance(
        vostok::particle::particle_system_instance *this)
{
  `vector destructor iterator'(
    (char *)this->m_lods,
    0x20u,
    10,
    (void (__thiscall *)(void *))vostok::particle::lod_entry::~lod_entry);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->m_lods);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
