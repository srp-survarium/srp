void __thiscall vostok::particle::particle_system_instance::particle_system_instance(
        vostok::particle::particle_system_instance *this)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, 1u);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this->m_lods);
  this->__vftable = (vostok::particle::particle_system_instance_vtbl *)&vostok::particle::particle_system_instance::`vftable';
  `vector constructor iterator'(
    (char *)this->m_lods,
    0x20u,
    10,
    (void *(__thiscall *)(void *))vostok::particle::lod_entry::lod_entry);
  this->m_particle_world = 0;
}
