int *__usercall internal_memalign@<eax>(unsigned int bytes@<eax>, malloc_state *m, unsigned int alignment)
{
  unsigned int v3; // ebp
  unsigned int i; // ecx
  unsigned int v6; // esi
  int *v7; // eax
  virtual_alloc_arena *v8; // edi
  int v9; // eax
  char *v10; // ebp
  int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edx
  char *v14; // eax
  unsigned int v15; // edx
  char *v16; // ebx
  char *leader; // [esp+10h] [ebp+8h]

  v3 = alignment;
  if ( alignment > 8 )
  {
    if ( alignment < 0x10 )
      v3 = 16;
    if ( ((v3 - 1) & v3) != 0 )
    {
      for ( i = 16; i < v3; i *= 2 )
        ;
      v3 = i;
    }
    if ( bytes < -64 - v3
      && (bytes >= 0xB ? (v6 = (bytes + 11) & 0xFFFFFFF8) : (v6 = 16),
          m != &gm_ ? (v7 = vostok_mspace_malloc(m, v6 + v3 + 12)) : (v7 = dlmalloc(v6 + v3 + 12)),
          v7) )
    {
      leader = 0;
      v8 = (virtual_alloc_arena *)(v7 - 2);
      if ( (unsigned int)v7 % v3 )
      {
        v9 = (-v3 & ((unsigned int)v7 + v3 - 1)) - 8;
        if ( (unsigned int)(v9 - (_DWORD)v8) < 0x10 )
          v10 = (char *)(v9 + v3);
        else
          v10 = (char *)v9;
        v11 = v10 - (char *)v8;
        v12 = ((int)v8->arena_id & 0xFFFFFFF8) - (v10 - (char *)v8);
        if ( ((int)v8->arena_id & 1) != 0 || ((int)v8->first_free_region & 1) == 0 )
        {
          *((_DWORD *)v10 + 1) = v12 | *((_DWORD *)v10 + 1) & 1 | 2;
          *(_DWORD *)&v10[v12 + 4] |= 1u;
          v8->arena_id = (const char *)(v11 | (int)v8->arena_id & 1 | 2);
          *((_DWORD *)v10 + 1) |= 1u;
          leader = (char *)&v8->start_pointer;
        }
        else
        {
          *(_DWORD *)v10 = (char *)v8->first_free_region + v11;
          *((_DWORD *)v10 + 1) = v12 | 2;
        }
        v8 = (virtual_alloc_arena *)v10;
      }
      if ( ((int)v8->arena_id & 1) == 0 && ((int)v8->first_free_region & 1) != 0
        || (v13 = (int)v8->arena_id & 0xFFFFFFF8, v13 <= v6 + 16) )
      {
        v16 = 0;
      }
      else
      {
        v8->arena_id = (const char *)(v6 | (int)v8->arena_id & 1 | 2);
        *(const char **)((char *)&v8->arena_id + v6) = (const char *)(*(int *)((char *)&v8->arena_id + v6) | 1);
        v14 = (char *)v8 + v6;
        v15 = v13 - v6;
        *((_DWORD *)v14 + 1) = v15 | *(int *)((_BYTE *)&v8->arena_id + v6) & 1 | 2;
        *(_DWORD *)&v14[v15 + 4] |= 1u;
        v16 = (char *)&v8->start_pointer + v6;
      }
      if ( leader )
      {
        if ( m == &gm_ )
          dlfree(leader, v8);
        else
          vostok_mspace_free(m, leader);
      }
      if ( v16 )
      {
        if ( m == &gm_ )
        {
          dlfree(v16, v8);
          return (int *)&v8->start_pointer;
        }
        vostok_mspace_free(m, v16);
      }
      return (int *)&v8->start_pointer;
    }
    else
    {
      return 0;
    }
  }
  else if ( m == &gm_ )
  {
    return dlmalloc(bytes);
  }
  else
  {
    return vostok_mspace_malloc(m, bytes);
  }
}
