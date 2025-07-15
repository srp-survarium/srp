void __userpurge vostok::resources::resources_manager::dispatch_query_callbacks(
        vostok::resources::queries_result *ready_query_list@<eax>,
        vostok::resources::queries_result *a2@<ecx>,
        vostok::resources::resources_manager *this,
        const bool finalizing_thread)
{
  vostok::resources::queries_result *v4; // esi
  vostok::resources::queries_result *m_next_ready; // ebp
  vostok::resources::queries_result *v6; // ecx

  v4 = ready_query_list;
  if ( ready_query_list )
  {
    do
    {
      m_next_ready = v4->m_next_ready;
      if ( !(_BYTE)this )
      {
        if ( v4->m_is_queries_for_quality )
          vostok::resources::queries_result::mark_inconsistent_qualities_as_failed(a2);
        if ( !v4->is_cancelled )
        {
          vostok::resources::queries_result::call_user_callback(a2);
          vostok::resources::queries_result::push_to_grm_cache(v6);
        }
      }
      vostok::resources::queries_result::~queries_result(a2);
      v4->m_allocator->call_free(v4->m_allocator, v4);
      v4 = m_next_ready;
    }
    while ( m_next_ready );
  }
}
