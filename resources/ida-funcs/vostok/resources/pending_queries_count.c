int __cdecl vostok::resources::pending_queries_count()
{
  if ( vostok::resources::g_resources_manager_initialized )
    return s_resources_manager_buffer.m_pending_queries_count;
  else
    return 0;
}
