void __thiscall vostok::memory::doug_lea_allocator::finalize_impl(vostok::memory::doug_lea_allocator *this)
{
  char *v1; // ebx
  int v2; // eax
  void *v3; // esi
  unsigned int v4; // edi

  v1 = (char *)this->m_arena + 444;
  if ( this->m_arena != (void *)-444 )
  {
    do
    {
      v2 = *((_DWORD *)v1 + 3);
      v3 = *(void **)v1;
      v4 = *((_DWORD *)v1 + 1);
      v1 = (char *)*((_DWORD *)v1 + 2);
      if ( (v2 & 1) != 0 && (v2 & 8) == 0 )
        munmap(v3, v4, (virtual_alloc_arena *)this);
    }
    while ( v1 );
  }
}
