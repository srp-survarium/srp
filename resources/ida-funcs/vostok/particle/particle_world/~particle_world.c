void __thiscall vostok::particle::particle_world::~particle_world(vostok::particle::particle_world *this)
{
  vostok::intrusive_list<vostok::particle::particle_system_instance_impl,vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>,724,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *p_m_ticked_instances_list; // edi
  vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *v3; // ecx

  p_m_ticked_instances_list = &this->m_ticked_instances_list;
  this->__vftable = (vostok::particle::particle_world_vtbl *)&vostok::particle::particle_world::`vftable';
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_ticked_instances_list.m_last);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&p_m_ticked_instances_list->m_first);
  DeleteCriticalSection((LPCRITICAL_SECTION)&p_m_ticked_instances_list->vostok::threading::mutex);
  vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::~fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>(
    v3,
    (int)&this->m_allocator);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
