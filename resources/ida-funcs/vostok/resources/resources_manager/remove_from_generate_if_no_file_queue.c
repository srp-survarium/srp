void __usercall vostok::resources::resources_manager::remove_from_generate_if_no_file_queue(
        vostok::resources::query_result *query@<esi>)
{
  vostok::resources::query_result *m_prev_in_generate_if_no_file_queue; // eax
  vostok::resources::query_result *m_next_in_generate_if_no_file_queue; // ecx

  _InterlockedAnd(&query->m_flags, 0xFFFFFFDF);
  if ( s_resources_manager_buffer.m_generate_if_no_file_queue.m_first )
  {
    vostok::threading::mutex::lock(
      (vostok::threading::mutex *)&query->m_flags,
      (_RTL_CRITICAL_SECTION *)&s_resources_manager_buffer.m_generate_if_no_file_queue.m_policy);
    m_prev_in_generate_if_no_file_queue = query->m_prev_in_generate_if_no_file_queue;
    m_next_in_generate_if_no_file_queue = query->m_next_in_generate_if_no_file_queue;
    query->m_prev_in_generate_if_no_file_queue = 0;
    query->m_next_in_generate_if_no_file_queue = 0;
    if ( m_prev_in_generate_if_no_file_queue )
      m_prev_in_generate_if_no_file_queue->m_next_in_generate_if_no_file_queue = m_next_in_generate_if_no_file_queue;
    else
      s_resources_manager_buffer.m_generate_if_no_file_queue.m_first = m_next_in_generate_if_no_file_queue;
    if ( m_next_in_generate_if_no_file_queue )
      m_next_in_generate_if_no_file_queue->m_prev_in_generate_if_no_file_queue = m_prev_in_generate_if_no_file_queue;
    else
      s_resources_manager_buffer.m_generate_if_no_file_queue.m_last = m_prev_in_generate_if_no_file_queue;
    query->m_prev_in_generate_if_no_file_queue = 0;
    query->m_next_in_generate_if_no_file_queue = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&s_resources_manager_buffer.m_generate_if_no_file_queue.m_policy);
  }
}
