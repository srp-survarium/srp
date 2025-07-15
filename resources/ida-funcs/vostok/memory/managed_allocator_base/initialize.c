void __userpurge vostok::memory::managed_allocator_base::initialize(
        unsigned __int8 *arena@<eax>,
        unsigned int size@<edx>,
        vostok::memory::managed_allocator_base *this)
{
  this->m_arena = arena;
  this->m_arena_size = size;
  this->m_free_size = size;
  this->m_first_free = (vostok::memory::managed_node *)arena;
  if ( arena )
  {
    *((_DWORD *)arena + 8) = 0;
    *((_DWORD *)arena + 11) = 0;
    arena[48] = 1;
    *((_DWORD *)arena + 10) = size;
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
}
