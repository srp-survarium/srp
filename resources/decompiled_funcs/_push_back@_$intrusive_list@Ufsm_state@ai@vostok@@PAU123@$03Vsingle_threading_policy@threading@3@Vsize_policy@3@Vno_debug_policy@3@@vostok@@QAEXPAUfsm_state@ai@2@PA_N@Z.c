void __usercall vostok::intrusive_list<vostok::ai::fsm_state,vostok::ai::fsm_state *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::ai::fsm_state,vostok::ai::fsm_state *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this@<eax>,
        vostok::ai::fsm_state *object@<ecx>,
        bool *out_pushed_first@<esi>)
{
  object->next = 0;
  ++this->m_size;
  if ( out_pushed_first )
    *out_pushed_first = this->m_first == 0;
  if ( this->m_first )
    this->m_last->next = object;
  else
    this->m_first = object;
  this->m_last = object;
}
