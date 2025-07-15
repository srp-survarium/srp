void __thiscall survarium::damage_zone_core::~damage_zone_core(survarium::damage_zone_core *this)
{
  vostok::math::curve_line_points<float,0> *v2; // ecx
  vostok::memory::doug_lea_allocator *v3; // ecx
  const char *v4; // [esp+0h] [ebp-Ch]
  const char *v5; // [esp+4h] [ebp-8h]
  unsigned int v6; // [esp+8h] [ebp-4h]

  v2 = (vostok::math::curve_line_points<float,0> *)survarium::g_allocator;
  this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::damage_zone_core_vtbl *)&survarium::damage_zone_core::`vftable'{for `vostok::resources::unmanaged_resource'};
  this->survarium::collision_sensor::survarium::collision_geometry_subscriber::__vftable = (survarium::collision_sensor_vtbl *)&survarium::damage_zone_core::`vftable'{for `survarium::collision_geometry_subscriber'};
  this->survarium::collision_sensor::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::damage_zone_core::`vftable'{for `survarium::link_resolver'};
  this->survarium::hit_initiator::__vftable = (survarium::hit_initiator_vtbl *)&survarium::damage_zone_core::`vftable'{for `survarium::hit_initiator'};
  this->survarium::player_actions_subscriber::__vftable = (survarium::player_actions_subscriber_vtbl *)&survarium::damage_zone_core::`vftable'{for `survarium::player_actions_subscriber'};
  this->survarium::tickable_object::__vftable = (survarium::tickable_object_vtbl *)&survarium::damage_zone_core::`vftable'{for `survarium::tickable_object'};
  this->survarium::serializable_object::__vftable = (survarium::serializable_object_vtbl *)&survarium::damage_zone_core::`vftable'{for `survarium::serializable_object'};
  vostok::math::curve_line_points<float,0>::free_memory(v2, (int)&this->m_distance_curve);
  vostok::math::curve_line_points<float,0>::free_memory(
    (vostok::math::curve_line_points<float,0> *)survarium::g_allocator,
    (int)&this->m_speed_curve);
  `vector destructor iterator'(
    (char *)&this->m_effects,
    4u,
    20,
    (void (__thiscall *)(void *))vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>::~intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_effect_emitter);
  if ( this->m_body_parts._M_impl._M_start )
    vostok::memory::doug_lea_allocator::free_impl(
      v3,
      (int)survarium::g_allocator,
      (char *)this->m_body_parts._M_impl._M_start,
      v4,
      v5,
      v6);
  stlp_std::priv::_Impl_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>,survarium::std_allocator<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>>::~_Impl_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>,survarium::std_allocator<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>>(
    (stlp_std::priv::_Impl_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>,survarium::std_allocator<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > > *)v3,
    (char **)&this->m_subscribed_objects);
  this->survarium::hit_initiator::__vftable = (survarium::hit_initiator_vtbl *)&survarium::hit_initiator::`vftable';
  survarium::collision_sensor::~collision_sensor(&this->survarium::collision_sensor);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
