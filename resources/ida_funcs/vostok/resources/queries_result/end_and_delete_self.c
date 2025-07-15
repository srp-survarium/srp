void __userpurge vostok::resources::queries_result::end_and_delete_self(
        vostok::resources::queries_result *this@<ecx>,
        vostok::resources::queries_result *a2@<eax>,
        bool finalizing_thread)
{
  vostok::resources::queries_result *v4; // ecx

  if ( !finalizing_thread )
  {
    if ( a2->m_is_queries_for_quality )
      vostok::resources::queries_result::mark_inconsistent_qualities_as_failed(this, a2);
    if ( !a2->is_cancelled )
    {
      vostok::resources::queries_result::call_user_callback(this, (char *)a2);
      vostok::resources::queries_result::push_to_grm_cache(v4, a2);
    }
  }
  vostok::resources::queries_result::~queries_result(this, a2);
  a2->m_allocator->call_free(a2->m_allocator, a2);
}
