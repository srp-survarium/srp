void __usercall vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::node>::deallocate(
        vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::node>::free_list_type *freeing_node@<esi>,
        vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::node>::free_list_type *free_list_head)
{
  vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::node>::free_list_type *i; // edi
  signed __int64 v3; // rax
  unsigned int counter; // ecx
  vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::node *pointer; // ebx

  for ( i = free_list_head; ; i = free_list_head )
  {
    LODWORD(v3) = i->pointer;
    counter = i->counter;
    freeing_node->pointer->next = i->pointer;
    HIDWORD(v3) = counter;
    pointer = freeing_node->pointer;
    freeing_node->counter = counter;
    if ( _InterlockedCompareExchange64(&i->whole, __SPAIR64__(freeing_node->counter, (unsigned int)pointer), v3) == __PAIR64__(counter, v3) )
      break;
  }
}
