int vostok::memory::_dynamic_initializer_for__g_resources_links_allocator__()
{
  vostok::memory::g_resources_links_allocator.m_allocator.m_initialized = 0;
  vostok::memory::g_resources_links_allocator.m_allocator.m_construction_started = 0;
  vostok::memory::g_resources_links_allocator.m_arena_id = 0;
  return atexit(vostok::memory::_dynamic_atexit_destructor_for__g_resources_links_allocator__);
}
