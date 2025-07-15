bool __usercall vostok::resources::game_resources_manager::try_reallocate_queue@<al>(
        vostok::resources::memory_type *info@<esi>,
        vostok::resources::game_resources_manager *this)
{
  vostok::resources::query_result *m_first; // ebp
  bool result; // al
  vostok::resources::query_result *v4; // ecx
  vostok::resources::query_result *v5; // eax
  vostok::resources::query_result *v6; // ecx
  vostok::resources::query_result *m_next_out_of_memory; // eax
  bool reallocated_some; // [esp+12h] [ebp-2h]
  bool reallocated; // [esp+13h] [ebp-1h]

  m_first = info->queue.m_first;
  result = 0;
  reallocated_some = 0;
  if ( m_first )
  {
    do
    {
      v4 = (vostok::resources::query_result *)_InterlockedExchangeAdd(&m_first->m_query_end_guard, 1u);
      v5 = info->queue.m_first;
      if ( v5->m_ready_to_retry_action_that_caused_out_of_memory && !v5->m_observed_resource_destructions_left )
      {
        reallocated = vostok::resources::query_result::retry_action_that_caused_out_of_memory(v4, info->queue.m_first);
        if ( reallocated && info->queue.m_first )
        {
          vostok::threading::mutex::lock(&info->queue.vostok::threading::mutex);
          if ( info->queue.m_first )
          {
            v6 = info->queue.m_first;
            --info->queue.m_size;
            m_next_out_of_memory = v6->m_next_out_of_memory;
            info->queue.m_first = m_next_out_of_memory;
            if ( !m_next_out_of_memory )
              info->queue.m_last = 0;
            v6->m_next_out_of_memory = 0;
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&info->queue.vostok::threading::mutex);
        }
      }
      else
      {
        reallocated = 0;
      }
      if ( !_InterlockedExchangeAdd(&m_first->m_query_end_guard, 0xFFFFFFFF) )
        vostok::resources::query_result::end_query_might_destroy_this_impl(v4, m_first);
      if ( !reallocated )
        break;
      m_first = info->queue.m_first;
      reallocated_some = 1;
    }
    while ( m_first );
    return reallocated_some;
  }
  return result;
}
