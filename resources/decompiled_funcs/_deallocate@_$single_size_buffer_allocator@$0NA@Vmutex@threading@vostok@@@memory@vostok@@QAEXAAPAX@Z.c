void __thiscall vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex>::deallocate(
        vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock> *this,
        void **pointer)
{
  vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::node>::free_list_type comperand; // [esp+24h] [ebp-14h]
  __int64 freeing_node; // [esp+30h] [ebp-8h]

  LODWORD(freeing_node) = *pointer;
  do
  {
    comperand.whole = (volatile __int64)this->m_free_list_head;
    *(_DWORD *)freeing_node = this->m_free_list_head.pointer;
    HIDWORD(freeing_node) = comperand.counter;
  }
  while ( vostok::threading::interlocked_compare_exchange(&this->m_free_list_head.whole, freeing_node, comperand.whole) != comperand.whole );
  vostok::threading::multi_threading_policy::intrusive_ptr_decrement<vostok::resources::unmanaged_intrusive_base>((vostok::resources::unmanaged_intrusive_base *)&this->m_allocated_count);
  *pointer = 0;
}
