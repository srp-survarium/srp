void __thiscall survarium::generic_anomaly_core::~generic_anomaly_core(survarium::generic_anomaly_core *this)
{
  survarium::vector<vostok::resources::request> *v1; // ecx

  this->survarium::link_resolver::__vftable = (survarium::generic_anomaly_core_vtbl *)&survarium::generic_anomaly_core::`vftable'{for `survarium::link_resolver'};
  this->survarium::player_actions_subscriber::__vftable = (survarium::player_actions_subscriber_vtbl *)&survarium::generic_anomaly_core::`vftable'{for `survarium::player_actions_subscriber'};
  stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::~_Impl_vector<void *,survarium::std_allocator<void *>>(
    (survarium::vector<vostok::resources::request> *)this,
    (void **)&this->m_states._M_impl._M_start);
  stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::~_Impl_vector<void *,survarium::std_allocator<void *>>(
    v1,
    (void **)&this->m_artefact_containers._M_impl._M_start);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->gap8);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(&this->gap8 + 1));
}
