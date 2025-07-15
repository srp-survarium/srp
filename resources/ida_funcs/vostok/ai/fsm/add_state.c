void __thiscall vostok::ai::fsm::add_state(vostok::ai::fsm *this, vostok::ai::fsm_state *state)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::intrusive_list<vostok::ai::fsm_state,vostok::ai::fsm_state *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
    &this->m_states,
    state,
    0);
}
