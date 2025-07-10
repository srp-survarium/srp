unsigned int __thiscall vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware>::total_size(
        vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware> *this)
{
  return 120 * this->m_allocator.m_variable->m_max_count;
}
