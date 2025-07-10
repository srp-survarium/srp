void __thiscall survarium::damage_zone_core::~damage_zone_core(survarium::damage_zone_core *this)
{
  this->survarium::collision_sensor::survarium::collision_geometry_subscriber::__vftable = (survarium::damage_zone_core_vtbl *)&survarium::damage_zone_core::`vftable'{for `survarium::collision_geometry_subscriber'};
  this->survarium::collision_sensor::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::damage_zone_core::`vftable'{for `survarium::link_resolver'};
  this->survarium::hit_initiator::__vftable = (survarium::hit_initiator_vtbl *)&survarium::damage_zone_core::`vftable'{for `survarium::hit_initiator'};
  this->survarium::player_actions_subscriber::__vftable = (survarium::player_actions_subscriber_vtbl *)&survarium::damage_zone_core::`vftable'{for `survarium::player_actions_subscriber'};
  stlp_std::priv::_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16>>>::~_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16>>>(&this->m_body_parts_filter._M_impl);
  stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info>>::~_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info>>(&this->m_receivers._M_impl);
  vostok::math::curve_line_points<float,0>::~curve_line_points<float,0>(&this->m_motion_on_center_curve);
  vostok::math::curve_line_points<float,0>::~curve_line_points<float,0>(&this->m_motion_on_bound_curve);
  vostok::math::curve_line_points<float,0>::~curve_line_points<float,0>(&this->m_hit_curve);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(&this->survarium::player_actions_subscriber + 1));
  this->survarium::hit_initiator::__vftable = (survarium::hit_initiator_vtbl *)&survarium::hit_initiator::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->id);
  survarium::collision_sensor::~collision_sensor(this);
}
