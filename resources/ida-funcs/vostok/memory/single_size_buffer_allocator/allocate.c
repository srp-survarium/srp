vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::node *__usercall vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::allocate<16>@<eax>(
        vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *this@<ecx>,
        vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *a2@<esi>)
{
  vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::node *result; // eax

  if ( a2->m_allocated_count >= a2->m_max_count
    && (a2->m_on_out_of_memory.vtable != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(&this->m_on_out_of_memory, a2, a2);
  }
  result = vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::node>::allocate(&a2->m_free_list_head);
  ++a2->m_allocated_count;
  return result;
}


vostok::memory::single_size_buffer_allocator<36,vostok::threading::single_threading_policy>::node *__usercall vostok::memory::single_size_buffer_allocator<36,vostok::threading::single_threading_policy>::allocate<36>@<eax>(
        vostok::memory::single_size_buffer_allocator<36,vostok::threading::single_threading_policy> *this@<ecx>,
        int a2@<esi>)
{
  vostok::memory::single_size_buffer_allocator<36,vostok::threading::single_threading_policy>::node *result; // eax

  if ( *(_DWORD *)(a2 + 36) >= *(_DWORD *)(a2 + 40)
    && (*(_DWORD *)a2 != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    boost::function1<void,vostok::collision::object const &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)this,
      (_DWORD *)a2,
      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)a2);
  }
  result = vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<36,vostok::threading::single_threading_policy>::node>::allocate((vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<36,vostok::threading::single_threading_policy>::node>::free_list_type *)(a2 + 32));
  ++*(_DWORD *)(a2 + 36);
  return result;
}


vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::node *__usercall vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::allocate<44>@<eax>(
        vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy> *this@<ecx>,
        int a2@<esi>)
{
  vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::node *result; // eax

  if ( *(_DWORD *)(a2 + 36) >= *(_DWORD *)(a2 + 40)
    && (*(_DWORD *)a2 != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)this,
      (_DWORD *)a2,
      (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)a2);
  }
  result = vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::node>::allocate((vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::node>::free_list_type *)(a2 + 32));
  ++*(_DWORD *)(a2 + 36);
  return result;
}
