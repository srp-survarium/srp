void __usercall vostok::resources::resources_manager::push_new_query(
        vostok::resources::query_result *query@<eax>,
        vostok::threading::mutex *a2@<ecx>)
{
  vostok::resources::resources_manager *v3; // ecx
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *p_m_new_inorder_queries; // esi
  vostok::resources::resources_manager *v5; // [esp+0h] [ebp-8h]

  if ( (query->m_flags & 0x10000000) == 0 || (query->m_flags & 0x2000000) != 0 )
  {
    if ( (query->m_flags & 0x8000000) != 0 || query->m_parent->m_parent_query )
    {
      p_m_new_inorder_queries = &s_resources_manager_buffer.m_new_inorder_queries;
    }
    else if ( (query->m_flags & 0x10) != 0 )
    {
      p_m_new_inorder_queries = &s_resources_manager_buffer.m_new_queries_with_locked_fat_it;
    }
    else
    {
      p_m_new_inorder_queries = &s_resources_manager_buffer.m_new_queries_with_unlocked_fat_it;
    }
    vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      p_m_new_inorder_queries,
      query,
      a2);
  }
  else if ( GetCurrentThreadId() == s_resources_manager_buffer.m_resources_thread_id )
  {
    vostok::resources::resources_manager::init_new_autoselect_quality_query(query, v5);
  }
  else
  {
    vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &s_resources_manager_buffer.m_new_autoselect_quality_queries,
      query,
      (vostok::threading::mutex *)s_resources_manager_buffer.m_resources_thread_id);
    vostok::resources::resources_manager::wakeup_resources_thread(v3, (int)&s_resources_manager_buffer);
  }
}
