void __thiscall vostok::memory::allocator_adapter<vostok::memory::single_size_fixed_allocator<10340,128,vostok::threading::multi_threading_policy>>::call_free(
        vostok::memory::allocator_adapter<vostok::memory::single_size_fixed_allocator<10340,128,vostok::threading::multi_threading_policy> > *this,
        void *pointer,
        const char *const function,
        const char *const file,
        const unsigned int line)
{
  vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::deallocate(
    (vostok::memory::single_size_buffer_allocator<292,vostok::threading::mutex> *)this,
    (void **)&this->m_allocator->m_on_out_of_memory.vtable,
    (_DWORD **)&pointer);
}
