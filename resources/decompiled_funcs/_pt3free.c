void __usercall pt3free(char *mem@<eax>)
{
  int v2; // eax
  char *v3; // ecx
  virtual_alloc_arena *v4; // edi
  unsigned int v5; // edx
  unsigned int v6; // esi
  malloc_arena *v7; // edx
  int v8; // edx
  volatile __int32 *p_mutex; // ecx
  malloc_arena *ar_ptr; // [esp+4h] [ebp-8h]

  if ( __free_hook )
  {
    __free_hook(mem, 0);
  }
  else if ( mem )
  {
    v2 = *((_DWORD *)mem - 1);
    v3 = mem - 8;
    if ( (v2 & 1) != 0 || (*(_DWORD *)v3 & 1) == 0 )
    {
      if ( (v2 & 4) != 0 )
        v7 = *(malloc_arena **)&v3[v2 & 0xFFFFFFF8];
      else
        v7 = &main_arena;
      ar_ptr = v7;
      slwait(&v7->mutex);
      vostok_mspace_free((void *)(v8 + 32), mem);
      p_mutex = &ar_ptr->mutex;
      _mm_pause();
      _InterlockedExchange(p_mutex, 0);
    }
    else
    {
      if ( (v2 & 4) != 0 )
        v4 = *(virtual_alloc_arena **)&v3[(v2 & 0xFFFFFFF8) - 4];
      else
        v4 = (virtual_alloc_arena *)&main_arena;
      v5 = *(_DWORD *)v3 & 0xFFFFFFFE;
      v6 = (v2 & 0xFFFFFFF8) + v5 + 16;
      if ( !munmap(v4, &v3[-v5], v6) )
        v4[14].out_of_memory_handler_parameter = (char *)v4[14].out_of_memory_handler_parameter - v6;
    }
  }
}
