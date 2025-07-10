vostok::ai::fsm_state *__thiscall vostok::intrusive_list<vostok::ai::fsm_state,vostok::ai::fsm_state *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front(
        vostok::intrusive_list<vostok::ai::fsm_state,vostok::ai::fsm_state *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this)
{
  vostok::ai::fsm_state *result; // eax
  vostok::ai::fsm_state *next; // edx

  if ( !this->m_first )
    return 0;
  result = this->m_first;
  --this->m_size;
  next = result->next;
  this->m_first = next;
  if ( !next )
    this->m_last = 0;
  result->next = 0;
  return result;
}
