void __cdecl free_starter(char *mem)
{
  char *v1; // esi
  int v2; // ecx
  unsigned int v3; // edx
  unsigned int v4; // edi

  if ( mem )
  {
    v1 = mem - 8;
    v2 = *((_DWORD *)mem - 1);
    if ( (v2 & 1) != 0 || (*(_DWORD *)v1 & 1) == 0 )
    {
      vostok_mspace_free(mem, (malloc_state *)&main_arena.buf_[8]);
    }
    else
    {
      v3 = *(_DWORD *)v1 & 0xFFFFFFFE;
      v4 = (v2 & 0xFFFFFFF8) + v3 + 16;
      if ( !munmap((virtual_alloc_region *)&v1[-v3], v4) )
        *(_DWORD *)&main_arena.buf_[440] -= v4;
    }
  }
}
