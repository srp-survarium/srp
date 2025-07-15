void __thiscall vostok::memory::managed_allocator::managed_allocator(vostok::memory::managed_allocator *this)
{
  vostok::threading::mutex_tasks_unaware *v1; // ecx
  vostok::threading::mutex_tasks_unaware *v2; // ecx
  vostok::timing::timer *v3; // ecx
  vostok::memory::managed_allocator_base *v4; // ecx

  vostok::memory::managed_allocator_base::managed_allocator_base(
    (vostok::memory::managed_allocator_base *)this,
    (int)&vostok::memory::g_resources_managed_allocator.vostok::memory::managed_allocator_base);
  vostok::memory::g_resources_managed_allocator.m_arena_start = 0;
  vostok::memory::g_resources_managed_allocator.m_arena_end = 0;
  vostok::memory::g_resources_managed_allocator.vostok::memory::base_allocator::m_arena_id = 0;
  vostok::memory::g_resources_managed_allocator.m_use_memory_monitor = 0;
  vostok::memory::g_resources_managed_allocator.__vftable = (vostok::memory::managed_allocator_vtbl *)&vostok::memory::managed_allocator::`vftable';
  vostok::memory::g_resources_managed_allocator.m_unmovables.m_begin = (vostok::memory::managed_allocator::unmovable *)vostok::memory::g_resources_managed_allocator.m_unmovables.m_buffer;
  vostok::memory::g_resources_managed_allocator.m_unmovables.m_end = (vostok::memory::managed_allocator::unmovable *)vostok::memory::g_resources_managed_allocator.m_unmovables.m_buffer;
  vostok::memory::g_resources_managed_allocator.m_unmovables.m_max_end = (vostok::memory::managed_allocator::unmovable *)(&vostok::memory::g_resources_managed_allocator.m_unmovables + 1);
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    v1,
    (_RTL_CRITICAL_SECTION *)&vostok::memory::g_resources_managed_allocator.m_unmovables_mutex);
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    v2,
    (_RTL_CRITICAL_SECTION *)&vostok::memory::g_resources_managed_allocator.m_defragmentation_mutex);
  vostok::timing::timer::timer(v3, (LARGE_INTEGER *)&vostok::memory::g_resources_managed_allocator.m_defragment_timer);
  vostok::memory::managed_allocator_base::managed_allocator_base(
    v4,
    (int)&vostok::memory::g_resources_managed_allocator.m_temp_arena);
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
