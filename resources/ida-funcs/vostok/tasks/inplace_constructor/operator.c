void __thiscall vostok::tasks::inplace_constructor::operator()(vostok::tasks::inplace_constructor *this)
{
  *(_DWORD *)&s_task_types_allocator_buffer[4] = 0;
  *(_DWORD *)&s_task_types_allocator_buffer[8] = 0;
  *(_DWORD *)&s_task_types_allocator_buffer[12] = 0;
  s_task_types_allocator_buffer[16] = 0;
  *(_DWORD *)s_task_types_allocator_buffer = &stru_807510.m_buffer[508];
  *(_DWORD *)&s_task_types_allocator_buffer[80] = &s_task_types_allocator_buffer[24];
  *(_DWORD *)&s_task_types_allocator_buffer[84] = 0;
  *(_DWORD *)&s_task_types_allocator_buffer[88] = 0;
  *(_DWORD *)&s_task_types_allocator_buffer[96] = 0;
  vostok::memory::base_allocator::initialize(
    (vostok::memory::base_allocator *)s_task_types_allocator_buffer,
    s_task_types_arena,
    0xFFFF0u,
    &stru_807510.m_buffer[124]);
}
