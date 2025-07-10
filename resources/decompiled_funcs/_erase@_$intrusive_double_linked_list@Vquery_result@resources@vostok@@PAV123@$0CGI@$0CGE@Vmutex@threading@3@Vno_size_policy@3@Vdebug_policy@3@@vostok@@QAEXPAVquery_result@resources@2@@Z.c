void __usercall vostok::intrusive_double_linked_list<vostok::resources::query_result,vostok::resources::query_result *,616,612,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy>::erase(
        vostok::intrusive_double_linked_list<vostok::resources::query_result,vostok::resources::query_result *,616,612,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy> *this@<edi>,
        vostok::resources::query_result *object@<esi>)
{
  vostok::resources::query_result *m_prev_in_generate_if_no_file_queue; // eax
  vostok::resources::query_result *m_next_in_generate_if_no_file_queue; // ecx

  if ( this->m_first )
  {
    vostok::threading::mutex::lock(&this->m_policy);
    m_prev_in_generate_if_no_file_queue = object->m_prev_in_generate_if_no_file_queue;
    m_next_in_generate_if_no_file_queue = object->m_next_in_generate_if_no_file_queue;
    object->m_prev_in_generate_if_no_file_queue = 0;
    object->m_next_in_generate_if_no_file_queue = 0;
    if ( m_prev_in_generate_if_no_file_queue )
      m_prev_in_generate_if_no_file_queue->m_next_in_generate_if_no_file_queue = m_next_in_generate_if_no_file_queue;
    else
      this->m_first = m_next_in_generate_if_no_file_queue;
    if ( m_next_in_generate_if_no_file_queue )
      m_next_in_generate_if_no_file_queue->m_prev_in_generate_if_no_file_queue = m_prev_in_generate_if_no_file_queue;
    else
      this->m_last = m_prev_in_generate_if_no_file_queue;
    object->m_prev_in_generate_if_no_file_queue = 0;
    object->m_next_in_generate_if_no_file_queue = 0;
    boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull((survarium::jump_logic_state_landing *)this);
    LeaveCriticalSection((LPCRITICAL_SECTION)&this->m_policy);
  }
}
