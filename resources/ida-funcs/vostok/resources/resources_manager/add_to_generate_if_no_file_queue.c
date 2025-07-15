void __usercall vostok::resources::resources_manager::add_to_generate_if_no_file_queue(
        vostok::resources::query_result *query@<eax>,
        vostok::threading::mutex *a2@<ecx>)
{
  vostok::resources::query_result *m_last; // eax

  vostok::threading::mutex::lock(
    a2,
    (_RTL_CRITICAL_SECTION *)&s_resources_manager_buffer.m_generate_if_no_file_queue.m_policy);
  m_last = s_resources_manager_buffer.m_generate_if_no_file_queue.m_last;
  query->m_next_in_generate_if_no_file_queue = 0;
  query->m_prev_in_generate_if_no_file_queue = m_last;
  if ( s_resources_manager_buffer.m_generate_if_no_file_queue.m_first )
    s_resources_manager_buffer.m_generate_if_no_file_queue.m_last->m_next_in_generate_if_no_file_queue = query;
  else
    s_resources_manager_buffer.m_generate_if_no_file_queue.m_first = query;
  s_resources_manager_buffer.m_generate_if_no_file_queue.m_last = query;
  LeaveCriticalSection((LPCRITICAL_SECTION)&s_resources_manager_buffer.m_generate_if_no_file_queue.m_policy);
  _InterlockedOr(&query->m_flags, 0x20u);
}
