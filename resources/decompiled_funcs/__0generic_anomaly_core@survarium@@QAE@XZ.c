void __thiscall survarium::generic_anomaly_core::generic_anomaly_core(survarium::generic_anomaly_core *this)
{
  survarium::link_resolver *v1; // ecx
  survarium::vector<vostok::resources::request> *v2; // ecx

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)(&this->gap8 + 1));
  survarium::link_resolver::link_resolver(v1, this);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->gap8);
  this->survarium::player_actions_subscriber::__vftable = (survarium::player_actions_subscriber_vtbl *)&survarium::player_actions_subscriber::`vftable';
  this->survarium::link_resolver::__vftable = (survarium::generic_anomaly_core_vtbl *)&survarium::generic_anomaly_core::`vftable'{for `survarium::link_resolver'};
  this->survarium::player_actions_subscriber::__vftable = (survarium::player_actions_subscriber_vtbl *)&survarium::generic_anomaly_core::`vftable'{for `survarium::player_actions_subscriber'};
  this->m_artefact_grab_time_ms = 0;
  stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_Impl_vector<void *,survarium::std_allocator<void *>>(
    (survarium::vector<vostok::resources::request> *)this,
    &this->m_artefact_containers._M_impl._M_start);
  stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_Impl_vector<void *,survarium::std_allocator<void *>>(
    v2,
    &this->m_states._M_impl._M_start);
  this->m_current_state = 0;
  this->m_was_zone_trigger_event = 0;
  this->m_was_shoot_trigger_event = 0;
  this->m_physics_world = 0;
  this->m_scheduler = 0;
}
