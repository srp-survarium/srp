void __userpurge vostok::resources::resources_manager::dispatch_query_callbacks(
        vostok::resources::queries_result *ready_query_list@<eax>,
        vostok::resources::queries_result *a2@<ecx>,
        vostok::resources::resources_manager *this,
        const bool finalizing_thread)
{
  vostok::resources::queries_result *v4; // edi
  vostok::resources::queries_result *m_next_ready; // esi

  v4 = ready_query_list;
  if ( ready_query_list )
  {
    do
    {
      m_next_ready = v4->m_next_ready;
      vostok::resources::queries_result::end_and_delete_self(a2, (int)v4, (bool)this);
      v4 = m_next_ready;
    }
    while ( m_next_ready );
  }
}
