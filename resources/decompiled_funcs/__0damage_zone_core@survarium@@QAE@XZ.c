void __thiscall survarium::damage_zone_core::damage_zone_core(survarium::damage_zone_core *this)
{
  survarium::collision_sensor::collision_sensor(this);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->id);
  this->survarium::hit_initiator::__vftable = (survarium::hit_initiator_vtbl *)&survarium::hit_initiator::`vftable';
  this->id = -1;
  this->is_local = 1;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)(&this->survarium::player_actions_subscriber + 1));
  this->survarium::player_actions_subscriber::__vftable = (survarium::player_actions_subscriber_vtbl *)&survarium::player_actions_subscriber::`vftable';
  this->survarium::collision_sensor::survarium::collision_geometry_subscriber::__vftable = (survarium::damage_zone_core_vtbl *)&survarium::damage_zone_core::`vftable'{for `survarium::collision_geometry_subscriber'};
  this->survarium::collision_sensor::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::damage_zone_core::`vftable'{for `survarium::link_resolver'};
  this->survarium::hit_initiator::__vftable = (survarium::hit_initiator_vtbl *)&survarium::damage_zone_core::`vftable'{for `survarium::hit_initiator'};
  this->survarium::player_actions_subscriber::__vftable = (survarium::player_actions_subscriber_vtbl *)&survarium::damage_zone_core::`vftable'{for `survarium::player_actions_subscriber'};
  vostok::math::curve_line_points<float,0>::curve_line_points<float,0>(&this->m_hit_curve);
  vostok::math::curve_line_points<float,0>::curve_line_points<float,0>(&this->m_motion_on_bound_curve);
  vostok::math::curve_line_points<float,0>::curve_line_points<float,0>(&this->m_motion_on_center_curve);
  this->m_physics_world = 0;
  this->m_owner = 0;
  this->m_receivers._M_impl._M_start = 0;
  this->m_receivers._M_impl._M_finish = 0;
  this->m_receivers._M_impl._M_end_of_storage._M_data = 0;
  this->m_body_parts_filter._M_impl._M_start = 0;
  this->m_body_parts_filter._M_impl._M_finish = 0;
  this->m_body_parts_filter._M_impl._M_end_of_storage._M_data = 0;
  vostok::fixed_string<32>::fixed_string<32>(&this->m_damage_type);
  this->m_accumulated_hit_time_ms = 0;
  this->m_standalone = 1;
}
