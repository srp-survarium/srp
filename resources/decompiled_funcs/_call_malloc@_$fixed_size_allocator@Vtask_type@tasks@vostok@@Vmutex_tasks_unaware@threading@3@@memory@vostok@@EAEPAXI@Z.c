vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::node *__thiscall vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware>::call_malloc(
        vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware> *this,
        unsigned int size)
{
  vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware> *m_variable; // esi
  vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::node *result; // eax

  m_variable = this->m_allocator.m_variable;
  result = vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::node>::allocate(&m_variable->m_free_list_head);
  _InterlockedExchangeAdd(&m_variable->m_allocated_count, 1u);
  return result;
}
