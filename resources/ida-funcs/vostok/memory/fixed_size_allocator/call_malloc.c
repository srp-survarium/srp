vostok::memory::single_size_buffer_allocator<292,vostok::threading::mutex>::node *__thiscall vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::call_malloc(
        vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *this,
        unsigned int size,
        const char *const description,
        const char *const function,
        const char *const file,
        const unsigned int line)
{
  vostok::memory::single_size_buffer_allocator<292,vostok::threading::mutex> *m_variable; // esi
  vostok::memory::single_size_buffer_allocator<292,vostok::threading::mutex>::node *result; // eax

  m_variable = this->m_allocator.m_variable;
  if ( m_variable->m_allocated_count >= m_variable->m_max_count
    && (m_variable->m_on_out_of_memory.vtable != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    boost::function1<void,vostok::collision::object const &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)this,
      m_variable,
      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)this->m_allocator.m_variable);
  }
  result = vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<292,vostok::threading::mutex>::node>::allocate(&m_variable->m_free_list_head);
  _InterlockedExchangeAdd(&m_variable->m_allocated_count, 1u);
  return result;
}


vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::node *__thiscall vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>::call_malloc(
        vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex> *this,
        unsigned int size,
        const char *const description,
        const char *const function,
        const char *const file,
        const unsigned int line)
{
  vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex> *m_variable; // esi
  vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::node *result; // eax

  m_variable = this->m_allocator.m_variable;
  if ( m_variable->m_allocated_count >= m_variable->m_max_count
    && (m_variable->m_on_out_of_memory.vtable != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    boost::function1<void,vostok::collision::object const &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)this,
      m_variable,
      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)this->m_allocator.m_variable);
  }
  result = vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::node>::allocate(&m_variable->m_free_list_head);
  _InterlockedExchangeAdd(&m_variable->m_allocated_count, 1u);
  return result;
}


vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::node *__thiscall vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware>::call_malloc(
        vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware> *this,
        unsigned int size,
        const char *const description,
        const char *const function,
        const char *const file,
        const unsigned int line)
{
  vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware> *m_variable; // esi
  vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::node *result; // eax

  m_variable = this->m_allocator.m_variable;
  if ( m_variable->m_allocated_count >= m_variable->m_max_count
    && (m_variable->m_on_out_of_memory.vtable != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    boost::function1<void,vostok::collision::object const &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)this,
      m_variable,
      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)this->m_allocator.m_variable);
  }
  result = vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::node>::allocate(&m_variable->m_free_list_head);
  _InterlockedExchangeAdd(&m_variable->m_allocated_count, 1u);
  return result;
}
