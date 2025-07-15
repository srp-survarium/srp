void __thiscall vostok::memory::crt_allocator::initialize_impl(
        vostok::memory::crt_allocator *this,
        void *buffer,
        unsigned __int64 buffer_size,
        const char *arena_id)
{
  _set_new_mode(1u);
  _set_new_handler((int (__cdecl *)(unsigned int))out_of_memory);
}
