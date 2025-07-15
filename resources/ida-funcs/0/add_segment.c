void __cdecl add_segment(malloc_state *m, malloc_chunk *tbase, unsigned int tsize, unsigned int mmapped)
{
  malloc_chunk *top; // ebx
  malloc_segment *v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // edi
  _DWORD *v8; // ecx
  unsigned int i; // esi
  unsigned int v10; // edx
  unsigned int v11; // ecx
  malloc_chunk **v12; // edi
  unsigned int v13; // ecx
  unsigned int v14; // edx
  unsigned int treemap; // ecx
  malloc_tree_chunk **v16; // esi
  unsigned int v17; // edx
  char *v18; // ecx
  char *least_addr; // eax
  malloc_chunk *v20; // ecx
  unsigned int v21; // [esp+10h] [ebp-8h]
  unsigned int v22; // [esp+14h] [ebp-4h]
  unsigned int v23; // [esp+24h] [ebp+Ch]

  top = m->top;
  v5 = segment_holding(m, (char *)top);
  v21 = (unsigned int)&v5->base[v5->size];
  v6 = v21
     - 47
     + (((LOBYTE(v5->base) + LOBYTE(v5->size) - 47) & 7) != 0 ? -((LOBYTE(v5->base) + LOBYTE(v5->size) - 47) & 7) & 7 : 0);
  if ( v6 >= (unsigned int)&top[1] )
  {
    v22 = v6;
    v7 = v6;
  }
  else
  {
    v7 = (unsigned int)top;
    v22 = (unsigned int)top;
  }
  init_top(m, tbase, tsize - 40);
  *(_DWORD *)(v7 + 4) = 27;
  *(malloc_segment *)(v7 + 8) = m->seg;
  m->seg.base = (char *)tbase;
  m->seg.size = tsize;
  m->seg.sflags = mmapped;
  m->seg.next = (malloc_segment *)(v22 + 8);
  v8 = (_DWORD *)(v22 + 28);
  for ( i = v22 + 32; ; i += 4 )
  {
    *v8 = 7;
    if ( i >= v21 )
      break;
    ++v8;
  }
  if ( (malloc_chunk *)v22 == top )
    return;
  v10 = v22 - (_DWORD)top;
  *(unsigned int *)((char *)&top->head + v10) &= ~1u;
  top->head = (v22 - (_DWORD)top) | 1;
  v11 = (v22 - (unsigned int)top) >> 3;
  v23 = v22 - (_DWORD)top;
  *(unsigned int *)((char *)&top->prev_foot + v10) = v10;
  if ( v11 < 0x20 )
  {
    v12 = &m->smallbins[2 * v11];
    if ( (m->smallmap & (1 << v11)) != 0 )
    {
      if ( m->smallbins[2 * v11 + 2] < (malloc_chunk *)m->least_addr )
        abort();
      v12 = (malloc_chunk **)m->smallbins[2 * v11 + 2];
    }
    else
    {
      m->smallmap |= 1 << v11;
    }
    m->smallbins[2 * v11 + 2] = top;
    v12[3] = top;
    top->fd = (malloc_chunk *)v12;
    top->bk = (malloc_chunk *)&m->smallbins[2 * v11];
    return;
  }
  v13 = v10 >> 8;
  if ( v10 >> 8 )
  {
    if ( v13 <= 0xFFFF )
    {
      _BitScanReverse(&v13, v13);
      v14 = ((v10 >> (v13 + 7)) & 1) + 2 * v13;
    }
    else
    {
      v14 = 31;
    }
  }
  else
  {
    v14 = 0;
  }
  top[1].head = 0;
  top[1].prev_foot = 0;
  top[1].bk = (malloc_chunk *)v14;
  treemap = m->treemap;
  v16 = &m->treebins[v14];
  if ( (treemap & (1 << v14)) == 0 )
  {
    m->treemap = (1 << v14) | treemap;
    *v16 = (malloc_tree_chunk *)top;
    goto LABEL_22;
  }
  v16 = (malloc_tree_chunk **)*v16;
  v17 = v23 << (v14 != 31 ? 25 - (v14 >> 1) : 0);
  while ( 1 )
  {
    if ( ((unsigned int)v16[1] & 0xFFFFFFF8) == v23 )
    {
      least_addr = m->least_addr;
      v20 = (malloc_chunk *)v16[2];
      if ( v16 >= (malloc_tree_chunk **)least_addr && v20 >= (malloc_chunk *)least_addr )
      {
        v20->bk = top;
        v16[2] = (malloc_tree_chunk *)top;
        top[1].fd = 0;
        top->fd = v20;
        top->bk = (malloc_chunk *)v16;
        return;
      }
LABEL_32:
      abort();
    }
    v18 = (char *)&v16[(v17 >> 31) + 4];
    v17 *= 2;
    if ( !*(_DWORD *)v18 )
      break;
    v16 = *(malloc_tree_chunk ***)v18;
  }
  if ( v18 < m->least_addr )
    goto LABEL_32;
  *(_DWORD *)v18 = top;
LABEL_22:
  top[1].fd = (malloc_chunk *)v16;
  top->bk = top;
  top->fd = top;
}
