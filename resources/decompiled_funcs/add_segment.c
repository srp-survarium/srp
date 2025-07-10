void __usercall add_segment(malloc_state *m@<eax>, char *tbase, unsigned int tsize, unsigned int mmapped)
{
  malloc_chunk *top; // esi
  malloc_segment *p_seg; // ecx
  int v6; // ecx
  malloc_chunk *v7; // ebx
  int v8; // ebp
  malloc_segment *p_fd; // edi
  char *v10; // edx
  unsigned int v11; // ecx
  malloc_chunk **p_bk; // ecx
  malloc_chunk *v13; // edx
  unsigned int v14; // ebx
  unsigned int v15; // ecx
  malloc_chunk **v16; // edi
  malloc_chunk *v17; // ecx
  unsigned int v18; // ecx
  unsigned int v19; // edx
  unsigned int treemap; // edx
  malloc_tree_chunk **v21; // ebp
  malloc_chunk *v22; // edx
  char v23; // bp
  unsigned int v24; // edi
  char *v25; // ebp
  char *least_addr; // eax
  malloc_chunk *fd; // ecx
  char *old_end; // [esp+10h] [ebp-4h]

  top = m->top;
  p_seg = &m->seg;
  do
  {
    if ( (char *)top >= p_seg->base && (char *)top < &p_seg->base[p_seg->size] )
      break;
    p_seg = p_seg->next;
  }
  while ( p_seg );
  old_end = &p_seg->base[p_seg->size];
  v6 = ((_BYTE)old_end - 47) & 7;
  if ( (((_BYTE)old_end - 47) & 7) != 0 )
    v6 = -v6 & 7;
  v7 = (malloc_chunk *)&old_end[v6 - 47];
  if ( v7 < &top[1] )
    v7 = m->top;
  v8 = (unsigned __int8)tbase & 7;
  p_fd = (malloc_segment *)&v7->fd;
  if ( ((unsigned __int8)tbase & 7) != 0 )
    v8 = -v8 & 7;
  v10 = &tbase[v8];
  v11 = tsize - 40 - v8;
  m->top = (malloc_chunk *)&tbase[v8];
  m->topsize = v11;
  *((_DWORD *)v10 + 1) = v11 | 1;
  *(_DWORD *)&v10[v11 + 4] = 40;
  m->trim_check = mparams.trim_threshold;
  v7->head = 27;
  *(_QWORD *)&p_fd->base = *(_QWORD *)&m->seg.base;
  *(_QWORD *)&v7[1].prev_foot = *(_QWORD *)&m->seg.next;
  m->seg.base = tbase;
  m->seg.size = tsize;
  p_bk = &v7[1].bk;
  m->seg.sflags = mmapped;
  m->seg.next = p_fd;
  v13 = v7 + 2;
  for ( v7[1].bk = (malloc_chunk *)7; v13 < (malloc_chunk *)old_end; *p_bk = (malloc_chunk *)7 )
  {
    ++p_bk;
    v13 = (malloc_chunk *)((char *)v13 + 4);
  }
  if ( v7 != top )
  {
    v14 = (char *)v7 - (char *)top;
    *(unsigned int *)((char *)&top->head + v14) &= ~1u;
    top->head = v14 | 1;
    v15 = v14 >> 3;
    *(unsigned int *)((char *)&top->prev_foot + v14) = v14;
    if ( v14 >> 3 >= 0x20 )
    {
      v18 = v14 >> 8;
      if ( v14 >> 8 )
      {
        if ( v18 <= 0xFFFF )
        {
          _BitScanReverse(&v19, v18);
          v18 = ((v14 >> (v19 + 7)) & 1) + 2 * v19;
        }
        else
        {
          v18 = 31;
        }
      }
      top[1].bk = (malloc_chunk *)v18;
      top[1].head = 0;
      top[1].prev_foot = 0;
      treemap = m->treemap;
      v21 = &m->treebins[v18];
      if ( (treemap & (1 << v18)) != 0 )
      {
        v22 = (malloc_chunk *)*v21;
        if ( v18 == 31 )
          v23 = 0;
        else
          v23 = 25 - (v18 >> 1);
        v24 = v14 << v23;
        if ( (v22->head & 0xFFFFFFF8) == v14 )
        {
LABEL_33:
          least_addr = m->least_addr;
          fd = v22->fd;
          if ( v22 >= (malloc_chunk *)least_addr && fd >= (malloc_chunk *)least_addr )
          {
            fd->bk = top;
            v22->fd = top;
            top->fd = fd;
            top->bk = v22;
            top[1].fd = 0;
            return;
          }
        }
        else
        {
          while ( 1 )
          {
            v25 = (char *)(&v22[1].prev_foot + (v24 >> 31));
            v24 *= 2;
            if ( !*(_DWORD *)v25 )
              break;
            v22 = *(malloc_chunk **)v25;
            if ( (*(_DWORD *)(*(_DWORD *)v25 + 4) & 0xFFFFFFF8) == v14 )
              goto LABEL_33;
          }
          if ( v25 >= m->least_addr )
          {
            *(_DWORD *)v25 = top;
            top[1].fd = v22;
            top->bk = top;
            top->fd = top;
            return;
          }
        }
        abort();
      }
      m->treemap = (1 << v18) | treemap;
      *v21 = (malloc_tree_chunk *)top;
      top[1].fd = (malloc_chunk *)v21;
      top->bk = top;
      top->fd = top;
    }
    else
    {
      v16 = &m->smallbins[2 * v15];
      if ( (m->smallmap & (1 << v15)) != 0 )
      {
        v17 = m->smallbins[2 * v15 + 2];
        if ( (char *)v17 < m->least_addr )
          abort();
        v16[2] = top;
        v17->bk = top;
        top->bk = (malloc_chunk *)v16;
        top->fd = v17;
      }
      else
      {
        m->smallmap |= 1 << v15;
        m->smallbins[2 * v15 + 2] = top;
        m->smallbins[2 * v15 + 3] = top;
        top->bk = (malloc_chunk *)v16;
        top->fd = (malloc_chunk *)&m->smallbins[2 * v15];
      }
    }
  }
}
