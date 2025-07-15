void __thiscall vostok::memory::managed_allocator::initialize_impl(
        vostok::memory::managed_allocator *this,
        char *arena,
        unsigned __int64 size,
        const char *arena_id)
{
  unsigned int m_temp_arena_size; // edx
  unsigned __int8 *v6; // ebx
  unsigned int v7; // edi

  m_temp_arena_size = this->m_temp_arena_size;
  v6 = (unsigned __int8 *)&arena[m_temp_arena_size];
  v7 = size - m_temp_arena_size;
  vostok::memory::managed_allocator_base::initialize((unsigned __int8 *)arena, m_temp_arena_size, &this->m_temp_arena);
  vostok::memory::managed_allocator_base::initialize(v6, v7, &this->vostok::memory::managed_allocator_base);
  this->m_arena_id = arena_id;
}
