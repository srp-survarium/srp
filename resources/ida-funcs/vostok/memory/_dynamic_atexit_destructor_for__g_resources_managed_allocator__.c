void __cdecl vostok::memory::_dynamic_atexit_destructor_for__g_resources_managed_allocator__()
{
  vostok::memory::g_resources_managed_allocator.__vftable = (vostok::memory::managed_allocator_vtbl *)&vostok::memory::managed_allocator::`vftable';
  DeleteCriticalSection((LPCRITICAL_SECTION)&vostok::memory::g_resources_managed_allocator.m_defragmentation_mutex);
  DeleteCriticalSection((LPCRITICAL_SECTION)&vostok::memory::g_resources_managed_allocator.m_unmovables_mutex);
  vostok::memory::g_resources_managed_allocator.m_unmovables.m_end = vostok::memory::g_resources_managed_allocator.m_unmovables.m_begin;
  vostok::memory::g_resources_managed_allocator.__vftable = (vostok::memory::managed_allocator_vtbl *)&vostok::memory::base_allocator::`vftable';
}
