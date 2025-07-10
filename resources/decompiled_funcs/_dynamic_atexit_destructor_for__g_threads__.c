void __cdecl dynamic_atexit_destructor_for__g_threads__()
{
  vostok::buffer_vector<vostok::apc::callback>::destroy(g_threads.m_begin, &g_threads.m_end);
  g_threads.m_end = g_threads.m_begin;
}
