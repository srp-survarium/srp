void __thiscall vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>::call_free(
        vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *this,
        void *pointer,
        const char *const function,
        const char *const file,
        const unsigned int line)
{
  vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::deallocate(
    (vostok::memory::single_size_buffer_allocator<292,vostok::threading::mutex> *)this,
    (void **)&this->m_allocator.m_variable->m_on_out_of_memory.vtable,
    (_DWORD **)&pointer);
}
