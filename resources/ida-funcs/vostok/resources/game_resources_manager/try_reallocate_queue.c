char __thiscall vostok::resources::game_resources_manager::try_reallocate_queue(
        vostok::resources::game_resources_manager *this,
        vostok::resources::memory_type *info)
{
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,616,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *m_observed_resource_destructions_left; // ecx
  vostok::resources::query_result *v4; // eax
  bool v5; // bl
  vostok::resources::query_result *m_first; // edi
  char i; // [esp+14h] [ebp+4h]

  for ( i = 0; ; i = 1 )
  {
    m_first = info->queue.m_first;
    if ( !m_first )
      break;
    m_observed_resource_destructions_left = (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,616,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)_InterlockedExchangeAdd(&m_first->m_query_end_guard, 1u);
    v4 = info->queue.m_first;
    if ( v4->m_ready_to_retry_action_that_caused_out_of_memory
      && (m_observed_resource_destructions_left = (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,616,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)v4->m_observed_resource_destructions_left) == 0 )
    {
      v5 = vostok::resources::query_result::retry_action_that_caused_out_of_memory(
             0,
             (vostok::resources::query_result::only_try_to_get_associated_resource_bool)v4);
      if ( v5 )
        vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,616,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_front(
          m_observed_resource_destructions_left,
          (int)&info->queue);
    }
    else
    {
      v5 = 0;
    }
    vostok::resources::query_result::end_query_might_destroy_this(
      (vostok::resources::query_result *)m_observed_resource_destructions_left,
      (int)m_first);
    if ( !v5 )
      break;
  }
  return i;
}
