void __thiscall vostok::memory::managed_allocator::initialize_impl(
        vostok::memory::managed_allocator *this,
        unsigned __int8 *arena,
        unsigned __int64 size,
        const char *arena_id)
{
  unsigned int m_temp_arena_size; // edi
  unsigned int v5; // ebp
  unsigned __int8 *v6; // eax

  m_temp_arena_size = this->m_temp_arena_size;
  v5 = size - m_temp_arena_size;
  v6 = &arena[m_temp_arena_size];
  this->m_temp_arena.m_arena = arena;
  this->m_temp_arena.m_arena_size = m_temp_arena_size;
  this->m_temp_arena.m_free_size = m_temp_arena_size;
  this->m_temp_arena.m_first_free = (vostok::memory::managed_node *)arena;
  if ( arena )
  {
    *((_DWORD *)arena + 8) = 0;
    *((_DWORD *)arena + 11) = 0;
    arena[48] = 1;
    *((_DWORD *)arena + 10) = m_temp_arena_size;
    *((_DWORD *)arena + 1) = 0;
    *((_DWORD *)arena + 2) = 0;
    *((_DWORD *)arena + 3) = 0;
    *(_DWORD *)arena = 0;
    *((_DWORD *)arena + 6) = 0;
    *((_DWORD *)arena + 7) = 0;
    *((_DWORD *)arena + 9) = 0;
    *((_DWORD *)arena + 5) = 0;
    *((_DWORD *)arena + 4) = 0;
  }
  this->m_arena = v6;
  this->m_arena_size = v5;
  this->m_free_size = v5;
  this->m_first_free = (vostok::memory::managed_node *)v6;
  if ( v6 )
  {
    *((_DWORD *)v6 + 8) = 0;
    *((_DWORD *)v6 + 11) = 0;
    *((_DWORD *)v6 + 10) = v5;
    *((_DWORD *)v6 + 1) = 0;
    *((_DWORD *)v6 + 2) = 0;
    *((_DWORD *)v6 + 3) = 0;
    *(_DWORD *)v6 = 0;
    *((_DWORD *)v6 + 6) = 0;
    *((_DWORD *)v6 + 7) = 0;
    *((_DWORD *)v6 + 9) = 0;
    *((_DWORD *)v6 + 5) = 0;
    *((_DWORD *)v6 + 4) = 0;
    v6[48] = 1;
  }
  this->m_arena_id = arena_id;
}
