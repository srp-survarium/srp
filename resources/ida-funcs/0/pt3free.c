void __fastcall pt3free(int a1, char *mem)
{
  char *v2; // esi
  int v3; // eax
  malloc_arena *v4; // ebx
  unsigned int v5; // ecx
  unsigned int v6; // edi
  malloc_arena *v7; // esi
  char *v8; // edx

  if ( __free_hook )
  {
    __free_hook(mem, 0);
  }
  else if ( mem )
  {
    v2 = mem - 8;
    v3 = *((_DWORD *)mem - 1);
    if ( (v3 & 1) != 0 || (*(_DWORD *)v2 & 1) == 0 )
    {
      if ( (v3 & 4) != 0 )
        v7 = *(malloc_arena **)&v2[v3 & 0xFFFFFFF8];
      else
        v7 = &main_arena;
      slwait(&v7->mutex);
      vostok_mspace_free(v8, (malloc_state *)&v7->buf_[8]);
      _mm_pause();
      _InterlockedExchange(&v7->mutex, 0);
    }
    else
    {
      if ( (v3 & 4) != 0 )
        v4 = *(malloc_arena **)&v2[(v3 & 0xFFFFFFF8) - 4];
      else
        v4 = &main_arena;
      v5 = *(_DWORD *)v2 & 0xFFFFFFFE;
      v6 = (v3 & 0xFFFFFFF8) + v5 + 16;
      if ( !munmap((virtual_alloc_region *)&v2[-v5], v6) )
        *(_DWORD *)&v4->buf_[440] -= v6;
    }
  }
}
