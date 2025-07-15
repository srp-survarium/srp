bool __usercall vostok::resources::game_resources_manager::try_reallocate_queue_front@<al>(
        vostok::resources::memory_type *info@<eax>,
        vostok::resources::game_resources_manager *this)
{
  vostok::resources::query_result *m_first; // eax

  m_first = info->queue.m_first;
  return m_first->m_ready_to_retry_action_that_caused_out_of_memory
      && !m_first->m_observed_resource_destructions_left
      && vostok::resources::query_result::retry_action_that_caused_out_of_memory(0, m_first);
}
