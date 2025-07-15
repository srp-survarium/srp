void __thiscall vostok::ai::fsm::fsm(vostok::ai::fsm *this)
{
  vostok::intrusive_list<vostok::ai::fsm_state,vostok::ai::fsm_state *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::ai::fsm_state,vostok::ai::fsm_state *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>(
    &this->m_states,
    this);
  this->m_current_state = 0;
}
