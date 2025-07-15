void __thiscall vostok::memory::managed_allocator::managed_allocator(vostok::memory::managed_allocator *this)
{
  vostok::memory::g_resources_managed_allocator.m_granularity = 128;
  vostok::memory::g_resources_managed_allocator.m_arena_size = 0;
  vostok::memory::g_resources_managed_allocator.m_arena = 0;
  vostok::memory::g_resources_managed_allocator.vostok::memory::managed_allocator_base::m_temp_arena = 0;
  vostok::memory::g_resources_managed_allocator.m_temp_arena_size = 0;
  vostok::memory::g_resources_managed_allocator.m_free_size = 0;
  vostok::memory::g_resources_managed_allocator.m_first_free = 0;
  vostok::memory::g_resources_managed_allocator.m_know_largest_free_block = 0;
  vostok::memory::g_resources_managed_allocator.m_largest_free_block = 0;
  vostok::memory::g_resources_managed_allocator.m_num_unpinned_objects = 0;
  vostok::memory::g_resources_managed_allocator.m_pinned = 0;
  vostok::memory::g_resources_managed_allocator.m_arena_start = 0;
  vostok::memory::g_resources_managed_allocator.m_arena_end = 0;
  vostok::memory::g_resources_managed_allocator.vostok::memory::base_allocator::m_arena_id = 0;
  vostok::memory::g_resources_managed_allocator.__vftable = (vostok::memory::managed_allocator_vtbl *)&vostok::memory::managed_allocator::`vftable';
  vostok::memory::g_resources_managed_allocator.m_unmovables.m_begin = (vostok::memory::managed_allocator::unmovable *)vostok::memory::g_resources_managed_allocator.m_unmovables.m_buffer;
  vostok::memory::g_resources_managed_allocator.m_unmovables.m_end = (vostok::memory::managed_allocator::unmovable *)vostok::memory::g_resources_managed_allocator.m_unmovables.m_buffer;
  InitializeCriticalSectionAndSpinCount(
    (LPCRITICAL_SECTION)&vostok::memory::g_resources_managed_allocator.m_unmovables_mutex,
    0x2710u);
  InitializeCriticalSectionAndSpinCount(
    (LPCRITICAL_SECTION)&vostok::memory::g_resources_managed_allocator.m_defragmentation_mutex,
    0x2710u);
  vostok::timing::timer::timer(&vostok::memory::g_resources_managed_allocator.m_defragment_timer);
  vostok::memory::g_resources_managed_allocator.m_temp_arena.m_arena_size = 0;
  vostok::memory::g_resources_managed_allocator.m_temp_arena.m_arena = 0;
  vostok::memory::g_resources_managed_allocator.m_temp_arena.m_temp_arena = 0;
  vostok::memory::g_resources_managed_allocator.m_temp_arena.m_temp_arena_size = 0;
  vostok::memory::g_resources_managed_allocator.m_temp_arena.m_free_size = 0;
  vostok::memory::g_resources_managed_allocator.m_temp_arena.m_first_free = 0;
  vostok::memory::g_resources_managed_allocator.m_temp_arena.m_know_largest_free_block = 0;
  vostok::memory::g_resources_managed_allocator.m_temp_arena.m_largest_free_block = 0;
  vostok::memory::g_resources_managed_allocator.m_temp_arena.m_granularity = 128;
  vostok::memory::g_resources_managed_allocator.m_temp_arena.m_num_unpinned_objects = 0;
  vostok::memory::g_resources_managed_allocator.m_temp_arena.m_pinned = 0;
  vostok::memory::g_resources_managed_allocator.m_arena_id = 0;
  vostok::memory::g_resources_managed_allocator.m_temp_arena_size = 0;
  vostok::memory::g_resources_managed_allocator.m_reserved_size = 0;
  vostok::memory::g_resources_managed_allocator.m_defragmenting = 0;
  vostok::memory::g_resources_managed_allocator.m_num_unpinned_objects = 0;
  vostok::memory::g_resources_managed_allocator.m_mode = 0;
  vostok::memory::g_resources_managed_allocator.m_defrag_unmovables = 0;
  vostok::memory::g_resources_managed_allocator.m_whole_moved_bytes = 0;
  vostok::memory::g_resources_managed_allocator.m_defrag_iteration = 1;
}
