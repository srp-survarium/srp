void __thiscall vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>::initialize_impl(
        vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex> *this,
        char *arena,
        unsigned __int64 size,
        const char *arena_id)
{
  char *v5; // eax

  this->m_arena_id = arena_id;
  v5 = arena;
  if ( ((unsigned __int8)arena & 7) != 0 )
    v5 = &arena[-((unsigned __int8)arena & 7) + 8];
  if ( this != (vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex> *)-24 )
    vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::single_size_buffer_allocator<12,vostok::threading::mutex>(
      (vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex> *)&this->m_allocator,
      v5,
      size);
  _InterlockedExchange(&this->m_allocator.m_initialized, 1);
}
