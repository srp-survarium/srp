void __thiscall vostok::particle::particle_world::~particle_world(vostok::particle::particle_world *this)
{
  vostok::threading::mutex *v1; // ecx

  this->__vftable = (vostok::particle::particle_world_vtbl *)&vostok::particle::particle_world::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_ticked_instances_list.m_last);
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_ticked_instances_list.m_first);
  vostok::threading::mutex::~mutex(v1, (_RTL_CRITICAL_SECTION *)&this->m_ticked_instances_list.vostok::threading::mutex);
  vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::~fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>(&this->m_allocator);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_allocator);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
