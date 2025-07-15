int __thiscall vostok::memory::crt_allocator::total_size(vostok::memory::crt_allocator *this)
{
  void *heap_handle; // eax

  heap_handle = _get_heap_handle();
  return mem_usage(heap_handle);
}
