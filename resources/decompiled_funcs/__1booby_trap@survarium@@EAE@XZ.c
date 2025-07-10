void __thiscall survarium::booby_trap::~booby_trap(survarium::booby_trap *this)
{
  const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *m_game_world; // eax
  vostok::resources::unmanaged_resource *m_object; // eax
  vostok::resources::unmanaged_resource *v4; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_particle_fired; // edi
  int i; // ebx
  vostok::resources::unmanaged_resource *v7; // eax

  m_game_world = (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)this->m_game_world;
  this->survarium::booby_trap_core::survarium::game_world_object::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::booby_trap_vtbl *)&survarium::booby_trap::`vftable'{for `survarium::game_world_object'};
  this->survarium::booby_trap_core::survarium::hittable_object::survarium::hit_receiver::vostok::collision::game_object::__vftable = (survarium::hittable_object_vtbl *)&survarium::booby_trap::`vftable'{for `survarium::hittable_object'};
  this->survarium::booby_trap_core::survarium::collision_sensor::survarium::collision_geometry_subscriber::__vftable = (survarium::collision_sensor_vtbl *)&survarium::booby_trap::`vftable'{for `survarium::collision_geometry_subscriber's `survarium::collision_sensor'};
  this->survarium::booby_trap_core::survarium::collision_sensor::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::booby_trap::`vftable'{for `survarium::link_resolver's `survarium::collision_sensor'};
  this->survarium::booby_trap_core::survarium::usable_object::survarium::collision_geometry_subscriber::__vftable = (survarium::usable_object_vtbl *)&survarium::booby_trap::`vftable'{for `survarium::collision_geometry_subscriber's `survarium::usable_object'};
  this->survarium::booby_trap_core::survarium::usable_object::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::booby_trap::`vftable'{for `survarium::link_resolver's `survarium::usable_object'};
  if ( m_game_world[1].m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    vostok::render::scene_renderer::remove_particle_system_instance(
      (vostok::render::scene_renderer *)m_game_world[42].m_object->grm_satisfaction_tree_hook.color_,
      *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)(m_game_world[42].m_object->grm_satisfaction_tree_hook.color_ + 16),
      m_game_world + 1);
  }
  m_object = this->m_sound_fired.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_sound_fired.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_sound_fired.m_object);
  v4 = this->m_particle_fired.m_object;
  p_m_particle_fired = &this->m_particle_fired;
  if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &p_m_particle_fired->m_object->vostok::resources::unmanaged_intrusive_base,
      p_m_particle_fired->m_object);
  for ( i = 3; i >= 0; --i )
  {
    v7 = p_m_particle_fired[-1].m_object;
    --p_m_particle_fired;
    if ( v7 && !_InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &p_m_particle_fired->m_object->vostok::resources::unmanaged_intrusive_base,
        p_m_particle_fired->m_object);
  }
  survarium::booby_trap_core::~booby_trap_core(this);
}
