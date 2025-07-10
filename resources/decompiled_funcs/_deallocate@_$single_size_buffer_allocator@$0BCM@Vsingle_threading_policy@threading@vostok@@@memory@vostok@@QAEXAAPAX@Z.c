void __thiscall vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::deallocate(
        vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *this,
        void **pointer)
{
  vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node *freeing_node; // [esp+10h] [ebp-4h]

  freeing_node = (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node *)*pointer;
  freeing_node->next = this->m_free_list_head.pointer;
  this->m_free_list_head.pointer = freeing_node;
  --this->m_allocated_count;
  *pointer = 0;
}
