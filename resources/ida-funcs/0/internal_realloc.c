unsigned __int8 *__cdecl internal_realloc(malloc_state *m, unsigned __int8 *oldmem, unsigned int bytes)
{
  int v4; // eax
  malloc_chunk *v5; // edi
  unsigned int v6; // esi
  malloc_chunk *v7; // ecx
  unsigned int v8; // edx
  int v9; // eax
  unsigned int v10; // ebp
  char *v11; // ecx
  unsigned int topsize; // ecx
  unsigned int v13; // ebp
  int *v14; // eax
  unsigned __int8 *v15; // ebp
  int v16; // eax
  unsigned int v17; // esi
  malloc_chunk *newp; // [esp+4h] [ebp-8h]
  char *extra; // [esp+8h] [ebp-4h]

  if ( bytes >= 0xFFFFFFC0 )
    return 0;
  v4 = *((_DWORD *)oldmem - 1);
  v5 = (malloc_chunk *)(oldmem - 8);
  v6 = v4 & 0xFFFFFFF8;
  v7 = (malloc_chunk *)&oldmem[(v4 & 0xFFFFFFF8) - 8];
  extra = 0;
  if ( (char *)(oldmem - 8) < m->least_addr || (v4 & 2) == 0 || v5 >= v7 || (v7->head & 1) == 0 )
    abort();
  if ( bytes >= 0xB )
    v8 = (bytes + 11) & 0xFFFFFFF8;
  else
    v8 = 16;
  v9 = v4 & 1;
  if ( v9 || (v5->prev_foot & 1) == 0 )
  {
    if ( v6 < v8 )
    {
      if ( v7 != m->top )
        goto LABEL_25;
      topsize = m->topsize;
      if ( topsize + v6 <= v8 )
        goto LABEL_25;
      v5->head = v8 | v9 | 2;
      *(unsigned int *)((char *)&v5->head + v8) |= 1u;
      v13 = v6 + topsize - v8;
      *(unsigned int *)((char *)&v5->head + v8) = v13 | 1;
      m->top = (malloc_chunk *)((char *)v5 + v8);
      m->topsize = v13;
      newp = (malloc_chunk *)(oldmem - 8);
    }
    else
    {
      v10 = v6 - v8;
      newp = (malloc_chunk *)(oldmem - 8);
      if ( v6 - v8 >= 0x10 )
      {
        v11 = (char *)v5 + v8;
        v5->head = v8 | v9 | 2;
        *((_DWORD *)v11 + 1) |= 1u;
        *((_DWORD *)v11 + 1) = v10 | *(unsigned int *)((_BYTE *)&v5->head + v8) & 1 | 2;
        *(_DWORD *)&v11[v10 + 4] |= 1u;
        extra = (char *)&oldmem[v8];
      }
    }
  }
  else
  {
    newp = mmap_resize(v5, v8);
  }
  if ( newp )
  {
    if ( extra )
    {
      if ( m == &gm_ )
      {
        dlfree(extra, (virtual_alloc_arena *)v5);
        return (unsigned __int8 *)&newp->fd;
      }
      vostok_mspace_free(m, extra);
    }
    return (unsigned __int8 *)&newp->fd;
  }
LABEL_25:
  if ( m == &gm_ )
    v14 = dlmalloc(bytes);
  else
    v14 = vostok_mspace_malloc(m, bytes);
  v15 = (unsigned __int8 *)v14;
  if ( v14 )
  {
    if ( (v5->head & 1) != 0 || (v16 = 8, (v5->prev_foot & 1) == 0) )
      v16 = 4;
    v17 = v6 - v16;
    if ( v17 >= bytes )
      v17 = bytes;
    memcpy(v15, oldmem, v17);
    if ( m == &gm_ )
    {
      dlfree((char *)oldmem, (virtual_alloc_arena *)v5);
      return v15;
    }
    vostok_mspace_free(m, (char *)oldmem);
  }
  return v15;
}
