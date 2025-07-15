void __thiscall vostok::particle::particle_world::remove(
        vostok::particle::particle_world *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> in_particle_system_instance)
{
  this->remove_particle_system_instance(this, in_particle_system_instance.m_object);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&in_particle_system_instance);
}
