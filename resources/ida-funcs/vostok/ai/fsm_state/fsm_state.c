void __thiscall vostok::ai::fsm_state::fsm_state(vostok::ai::fsm_state *this)
{
  survarium::game_camera *v1; // ecx
  vostok::intrusive_list<vostok::ai::fsm_state_transition,vostok::ai::fsm_state_transition *,36,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *p_transitions; // [esp+4h] [ebp-4h]

  p_transitions = &this->transitions;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this,
    &this->transitions.m_size);
  survarium::weapon_user_dead_state::finalize(v1);
  p_transitions->m_first = 0;
  p_transitions->m_last = 0;
}
