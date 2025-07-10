unsigned int __cdecl release_unused_segments(malloc_state *m)
{
  char *v2; // edx
  malloc_chunk *bk; // edi
  unsigned int sflags; // eax
  int v5; // eax
  malloc_chunk *v6; // esi
  int v7; // eax
  malloc_chunk *fd; // ebp
  malloc_chunk *v9; // eax
  char *p_head; // ecx
  char *v11; // eax
  malloc_chunk *v12; // eax
  bool v13; // zf
  malloc_tree_chunk **v14; // eax
  unsigned int prev_foot; // eax
  unsigned int head; // eax
  unsigned int v17; // eax
  unsigned int v18; // ecx
  unsigned int treemap; // edi
  malloc_tree_chunk **v20; // edx
  malloc_chunk *v21; // eax
  char v22; // di
  unsigned int v23; // edx
  char *v24; // edi
  char *least_addr; // edx
  malloc_chunk *v26; // ecx
  unsigned int v27; // eax
  unsigned int released; // [esp+8h] [ebp-1Ch]
  int nsegs; // [esp+Ch] [ebp-18h]
  unsigned int size; // [esp+10h] [ebp-14h]
  malloc_segment *pred; // [esp+14h] [ebp-10h]
  malloc_segment *next; // [esp+18h] [ebp-Ch]
  char *base; // [esp+1Ch] [ebp-8h]
  unsigned int K; // [esp+20h] [ebp-4h]
  malloc_segment *ma; // [esp+28h] [ebp+4h]

  pred = &m->seg;
  released = 0;
  nsegs = 0;
  ma = m->seg.next;
  if ( !ma )
  {
LABEL_63:
    v27 = 255;
    goto LABEL_64;
  }
  do
  {
    v2 = ma->base;
    bk = (malloc_chunk *)ma->size;
    sflags = ma->sflags;
    ++nsegs;
    base = ma->base;
    size = (unsigned int)bk;
    next = ma->next;
    if ( (sflags & 1) == 0 || (sflags & 8) != 0 )
      goto LABEL_61;
    v5 = (int)ma->base & 7;
    if ( ((unsigned __int8)v2 & 7) != 0 )
      v5 = -v5 & 7;
    v6 = (malloc_chunk *)&v2[v5];
    v7 = *(_DWORD *)&v2[v5 + 4];
    K = v7 & 0xFFFFFFF8;
    if ( (v7 & 2) != 0 || (char *)((unsigned int)v6 + (v7 & 0xFFFFFFF8)) < &v2[(int)bk - 40] )
      goto LABEL_61;
    if ( v6 == m->dv )
    {
      m->dv = 0;
      m->dvsize = 0;
      goto LABEL_40;
    }
    bk = v6->bk;
    fd = v6[1].fd;
    if ( bk == v6 )
    {
      bk = (malloc_chunk *)v6[1].head;
      p_head = (char *)&v6[1].head;
      if ( bk || (bk = (malloc_chunk *)v6[1].prev_foot, p_head = (char *)&v6[1], bk) )
      {
        while ( 1 )
        {
          v11 = (char *)&bk[1].head;
          if ( !bk[1].head )
          {
            v11 = (char *)&bk[1];
            if ( !bk[1].prev_foot )
              break;
          }
          bk = *(malloc_chunk **)v11;
          p_head = v11;
        }
        if ( p_head < m->least_addr )
LABEL_20:
          abort();
        *(_DWORD *)p_head = 0;
      }
    }
    else
    {
      v9 = v6->fd;
      if ( (char *)v9 < m->least_addr )
        goto LABEL_20;
      v9->bk = bk;
      bk->fd = v9;
    }
    if ( fd )
    {
      v12 = v6[1].bk;
      v13 = v6 == (malloc_chunk *)m->treebins[(_DWORD)v12];
      v14 = &m->treebins[(_DWORD)v12];
      if ( v13 )
      {
        *v14 = (malloc_tree_chunk *)bk;
        if ( !bk )
        {
          m->treemap &= ~(1 << (int)v6[1].bk);
          goto LABEL_40;
        }
      }
      else
      {
        if ( (char *)fd < m->least_addr )
          abort();
        if ( (malloc_chunk *)fd[1].prev_foot == v6 )
          fd[1].prev_foot = (unsigned int)bk;
        else
          fd[1].head = (unsigned int)bk;
        if ( !bk )
          goto LABEL_40;
      }
      if ( (char *)bk < m->least_addr )
        goto LABEL_39;
      bk[1].fd = fd;
      prev_foot = v6[1].prev_foot;
      if ( prev_foot )
      {
        if ( (char *)prev_foot < m->least_addr )
          abort();
        bk[1].prev_foot = prev_foot;
        *(_DWORD *)(prev_foot + 24) = bk;
      }
      head = v6[1].head;
      if ( head )
      {
        if ( (char *)head < m->least_addr )
LABEL_39:
          abort();
        bk[1].head = head;
        *(_DWORD *)(head + 24) = bk;
      }
    }
LABEL_40:
    if ( munmap((virtual_alloc_arena *)bk, base, size) )
    {
      v17 = K >> 8;
      if ( K >> 8 )
      {
        if ( v17 <= 0xFFFF )
        {
          _BitScanReverse(&v17, v17);
          v18 = ((K >> (v17 + 7)) & 1) + 2 * v17;
        }
        else
        {
          v18 = 31;
        }
      }
      else
      {
        v18 = 0;
      }
      v6[1].bk = (malloc_chunk *)v18;
      v6[1].head = 0;
      v6[1].prev_foot = 0;
      treemap = m->treemap;
      v20 = &m->treebins[v18];
      if ( ((1 << v18) & treemap) != 0 )
      {
        v21 = (malloc_chunk *)*v20;
        if ( v18 == 31 )
          v22 = 0;
        else
          v22 = 25 - (v18 >> 1);
        v23 = K << v22;
        if ( (v21->head & 0xFFFFFFF8) == K )
        {
LABEL_55:
          least_addr = m->least_addr;
          v26 = v21->fd;
          if ( v21 < (malloc_chunk *)least_addr || v26 < (malloc_chunk *)least_addr )
            goto LABEL_60;
          v26->bk = v6;
          v21->fd = v6;
          v6->fd = v26;
          v6->bk = v21;
          v6[1].fd = 0;
        }
        else
        {
          while ( 1 )
          {
            v24 = (char *)(&v21[1].prev_foot + (v23 >> 31));
            v23 *= 2;
            if ( !*(_DWORD *)v24 )
              break;
            v21 = *(malloc_chunk **)v24;
            if ( (*(_DWORD *)(*(_DWORD *)v24 + 4) & 0xFFFFFFF8) == K )
              goto LABEL_55;
          }
          if ( v24 < m->least_addr )
LABEL_60:
            abort();
          *(_DWORD *)v24 = v6;
          v6[1].fd = v21;
          v6->bk = v6;
          v6->fd = v6;
        }
      }
      else
      {
        m->treemap = treemap | (1 << v18);
        *v20 = (malloc_tree_chunk *)v6;
        v6[1].fd = (malloc_chunk *)v20;
        v6->bk = v6;
        v6->fd = v6;
      }
    }
    else
    {
      released += size;
      m->footprint -= size;
      ma = pred;
      pred->next = next;
    }
LABEL_61:
    pred = ma;
    ma = next;
  }
  while ( next );
  v27 = nsegs;
  if ( nsegs <= 255 )
    goto LABEL_63;
LABEL_64:
  m->release_checks = v27;
  return released;
}
