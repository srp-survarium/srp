void __thiscall vostok::particle::particle_world::set_paused(
        vostok::particle::particle_world *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> particle_system_instance,
        bool is_paused)
{
  particle_system_instance.m_object->m_paused = is_paused;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&particle_system_instance);
}
