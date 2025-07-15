vostok::ai::fsm_state *__thiscall vostok::ai::fsm::pop_state(vostok::ai::fsm *this)
{
  return vostok::intrusive_list<vostok::ai::fsm_state,vostok::ai::fsm_state *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front(&this->m_states);
}
