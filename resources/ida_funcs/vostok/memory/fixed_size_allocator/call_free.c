void __thiscall vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::call_free(
        vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *this,
        void *pointer)
{
  vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::deallocate(
    this,
    &pointer);
}


void __thiscall vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware>::call_free(
        vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex> *this,
        vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::node *pointer)
{
  vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex> *m_variable; // edi
  vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::node>::free_list_type freeing_node; // [esp+8h] [ebp-8h] BYREF

  m_variable = this->m_allocator.m_variable;
  freeing_node.pointer = pointer;
  vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::node>::deallocate(
    &freeing_node,
    &m_variable->m_free_list_head);
  _InterlockedExchangeAdd(&m_variable->m_allocated_count, 0xFFFFFFFF);
}
