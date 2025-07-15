void __thiscall vostok::tasks::inplace_constructor::operator()(vostok::tasks::inplace_constructor *this)
{
  *(_DWORD *)&s_task_types_allocator_buffer[4] = 0;
  *(_DWORD *)&s_task_types_allocator_buffer[8] = 0;
  *(_DWORD *)&s_task_types_allocator_buffer[12] = 0;
  *(_DWORD *)s_task_types_allocator_buffer = &vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware>::`vftable';
  *(_DWORD *)&s_task_types_allocator_buffer[40] = &s_task_types_allocator_buffer[24];
  *(_DWORD *)&s_task_types_allocator_buffer[44] = 0;
  *(_DWORD *)&s_task_types_allocator_buffer[48] = 0;
  *(_DWORD *)&s_task_types_allocator_buffer[56] = 0;
  vostok::memory::base_allocator::initialize(
    (vostok::memory::base_allocator *)s_task_types_allocator_buffer,
    s_task_types_arena,
    (unsigned int)&loc_FFFEF + 1,
    &stru_95DC74.m_buffer[404]);
}
