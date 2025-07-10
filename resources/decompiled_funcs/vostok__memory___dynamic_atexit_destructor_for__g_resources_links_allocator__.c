void __cdecl vostok::memory::_dynamic_atexit_destructor_for__g_resources_links_allocator__()
{
  vostok::memory::g_resources_links_allocator.m_allocator.m_initialized = 0;
  vostok::memory::g_resources_links_allocator.__vftable = (vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>_vtbl *)&vostok::memory::base_allocator::`vftable';
}
