vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *__usercall vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::allocate_impl@<eax>(
        vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> *this@<ecx>,
        int a2@<eax>)
{
  volatile signed __int32 *v3; // edi
  vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *result; // eax

  v3 = (volatile signed __int32 *)(a2 + 40);
  if ( *(_DWORD *)(a2 + 40) >= *(_DWORD *)(a2 + 44)
    && (*(_DWORD *)a2 != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    boost::function1<void,vostok::collision::object const &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)this,
      (_DWORD *)a2,
      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)a2);
  }
  result = vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node>::allocate((vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node>::free_list_type *)(a2 + 32));
  _InterlockedExchangeAdd(v3, 1u);
  return result;
}


vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node *__usercall vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::allocate_impl@<eax>(
        vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock> *this@<ecx>,
        int a2@<eax>)
{
  volatile signed __int32 *v3; // edi
  vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node *result; // eax

  v3 = (volatile signed __int32 *)(a2 + 40);
  if ( *(_DWORD *)(a2 + 40) >= *(_DWORD *)(a2 + 44)
    && (*(_DWORD *)a2 != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    boost::function1<void,vostok::collision::object const &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)this,
      (_DWORD *)a2,
      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)a2);
  }
  result = vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node>::allocate((vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node>::free_list_type *)(a2 + 32));
  _InterlockedExchangeAdd(v3, 1u);
  return result;
}
