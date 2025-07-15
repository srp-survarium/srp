unsigned int __cdecl vostok::resources::pending_queries_count()
{
  unsigned int result; // eax

  result = vostok::resources::g_resources_manager.m_initialized;
  if ( vostok::resources::g_resources_manager.m_initialized )
    return vostok::resources::g_resources_manager.m_variable->m_pending_queries_count;
  return result;
}
