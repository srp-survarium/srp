void __thiscall vostok::particle::particle_world::particle_world(
        vostok::particle::particle_world *this,
        vostok::particle::engine *engine)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, 1u);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_allocator);
  this->__vftable = (vostok::particle::particle_world_vtbl *)&vostok::particle::particle_world::`vftable';
  vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>(&this->m_allocator);
  vostok::intrusive_list<vostok::particle::particle_system_instance_impl,vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>,656,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::particle::particle_system_instance_impl,vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>,656,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(&this->m_ticked_instances_list);
  this->m_engine = engine;
  this->m_num_particles = 0;
  this->m_max_particles = 50000;
}
