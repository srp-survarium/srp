void __usercall free_starter(virtual_alloc_arena *a1@<edi>, _DWORD *mem)
{
  int v2; // edx
  _DWORD *v3; // ecx
  unsigned int v4; // ebx
  unsigned int v5; // esi

  if ( mem )
  {
    v2 = *(mem - 1);
    v3 = mem - 2;
    if ( (v2 & 1) != 0 || (*v3 & 1) == 0 )
    {
      vostok_mspace_free(&main_arena.buf_[8], mem);
    }
    else
    {
      v4 = *v3 & 0xFFFFFFFE;
      v5 = (v2 & 0xFFFFFFF8) + v4 + 16;
      if ( !munmap(a1, (char *)v3 - v4, v5) )
        *(_DWORD *)&main_arena.buf_[440] -= v5;
    }
  }
}
