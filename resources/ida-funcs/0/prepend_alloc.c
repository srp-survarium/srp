char *__usercall prepend_alloc@<eax>(malloc_state *m@<ecx>, unsigned int nb@<eax>, char *newbase, char *oldbase)
{
  malloc_chunk *v5; // esi
  unsigned int v6; // edx
  malloc_chunk *v7; // ebx
  unsigned int v8; // eax
  unsigned int dvsize; // eax
  unsigned int head; // eax
  malloc_chunk *v11; // eax
  malloc_chunk **v12; // ecx
  malloc_chunk *bk; // eax
  malloc_chunk *fd; // edx
  malloc_chunk *v15; // ecx
  char *p_head; // eax
  unsigned int v17; // edx
  char *v18; // ecx
  malloc_tree_chunk **v19; // ecx
  unsigned int v20; // ecx
  unsigned int v21; // ecx
  unsigned int v22; // ecx
  unsigned int v23; // eax
  unsigned int treemap; // ecx
  malloc_tree_chunk **v25; // edx
  malloc_chunk *v26; // esi
  unsigned int v27; // eax
  char *v28; // ecx
  char *least_addr; // edi
  malloc_chunk *v30; // eax
  char *v32; // [esp+10h] [ebp-Ch]
  unsigned int v33; // [esp+14h] [ebp-8h]
  malloc_chunk *v34; // [esp+18h] [ebp-4h]
  malloc_chunk *v35; // [esp+18h] [ebp-4h]
  unsigned int v36; // [esp+24h] [ebp+8h]
  unsigned int prev_foot; // [esp+24h] [ebp+8h]
  malloc_chunk **v38; // [esp+24h] [ebp+8h]
  unsigned int v39; // [esp+28h] [ebp+Ch]

  v5 = (malloc_chunk *)&oldbase[((unsigned __int8)oldbase & 7) != 0 ? -((unsigned __int8)oldbase & 7) & 7 : 0];
  v32 = &newbase[((unsigned __int8)newbase & 7) != 0 ? -((unsigned __int8)newbase & 7) & 7 : 0];
  v6 = (char *)v5 - v32 - nb;
  v7 = (malloc_chunk *)&v32[nb];
  *((_DWORD *)v32 + 1) = nb | 3;
  v39 = v6;
  if ( v5 == m->top )
  {
    m->topsize += v6;
    v8 = m->topsize | 1;
    m->top = v7;
    v7->head = v8;
    return v32 + 8;
  }
  if ( v5 == m->dv )
  {
    m->dvsize += v6;
    dvsize = m->dvsize;
    m->dv = v7;
    v7->head = dvsize | 1;
    *(unsigned int *)((char *)&v7->prev_foot + dvsize) = dvsize;
    return v32 + 8;
  }
  head = v5->head;
  if ( (head & 2) != 0 )
    goto LABEL_49;
  v33 = head & 0xFFFFFFF8;
  v36 = (head & 0xFFFFFFF8) >> 3;
  if ( v36 >= 0x20 )
  {
    bk = v5->bk;
    fd = v5[1].fd;
    v35 = fd;
    if ( bk != v5 )
    {
      v15 = v5->fd;
      if ( (char *)v15 >= m->least_addr )
      {
        v15->bk = bk;
        bk->fd = v15;
        goto LABEL_28;
      }
LABEL_17:
      abort();
    }
    p_head = (char *)&v5[1].head;
    v17 = v5[1].head;
    prev_foot = v17;
    if ( !v17 )
    {
      p_head = (char *)&v5[1];
      prev_foot = v5[1].prev_foot;
      if ( !prev_foot )
      {
        bk = 0;
        goto LABEL_27;
      }
      v17 = v5[1].prev_foot;
    }
    while ( 1 )
    {
      v18 = (char *)(v17 + 20);
      if ( !*(_DWORD *)(v17 + 20) )
      {
        v18 = (char *)(v17 + 16);
        if ( !*(_DWORD *)(v17 + 16) )
          break;
      }
      p_head = v18;
      prev_foot = *(_DWORD *)v18;
      v17 = *(_DWORD *)v18;
    }
    if ( p_head < m->least_addr )
      goto LABEL_17;
    *(_DWORD *)p_head = 0;
    bk = (malloc_chunk *)prev_foot;
LABEL_27:
    fd = v35;
LABEL_28:
    if ( fd )
    {
      v19 = &m->treebins[(int)v5[1].bk];
      if ( v5 == (malloc_chunk *)*v19 )
      {
        *v19 = (malloc_tree_chunk *)bk;
        if ( !bk )
        {
          m->treemap &= ~(1 << (int)v5[1].bk);
          goto LABEL_47;
        }
      }
      else
      {
        if ( (char *)fd < m->least_addr )
          abort();
        if ( (malloc_chunk *)fd[1].prev_foot == v5 )
          fd[1].prev_foot = (unsigned int)bk;
        else
          fd[1].head = (unsigned int)bk;
        if ( !bk )
          goto LABEL_47;
      }
      if ( (char *)bk < m->least_addr )
        goto LABEL_46;
      bk[1].fd = fd;
      v20 = v5[1].prev_foot;
      if ( v20 )
      {
        if ( (char *)v20 < m->least_addr )
          abort();
        bk[1].prev_foot = v20;
        *(_DWORD *)(v20 + 24) = bk;
      }
      v21 = v5[1].head;
      if ( v21 )
      {
        if ( (char *)v21 < m->least_addr )
          goto LABEL_46;
        bk[1].head = v21;
        *(_DWORD *)(v21 + 24) = bk;
      }
    }
LABEL_47:
    v6 = v39;
    goto LABEL_48;
  }
  v11 = v5->fd;
  v34 = v5->bk;
  if ( v11 != v34 )
  {
    v12 = &m->smallbins[2 * v36];
    if ( (v11 == (malloc_chunk *)v12 || (char *)v11 >= m->least_addr)
      && (v34 == (malloc_chunk *)v12 || (char *)v34 >= m->least_addr) )
    {
      v11->bk = v34;
      v34->fd = v11;
      goto LABEL_48;
    }
LABEL_46:
    abort();
  }
  m->smallmap &= ~(1 << v36);
LABEL_48:
  v5 = (malloc_chunk *)((char *)v5 + v33);
  v6 += v33;
  v39 = v6;
LABEL_49:
  v5->head &= ~1u;
  v7->head = v6 | 1;
  v22 = v6 >> 3;
  *(unsigned int *)((char *)&v7->prev_foot + v6) = v6;
  if ( v6 >> 3 < 0x20 )
  {
    v38 = &m->smallbins[2 * v22];
    if ( ((1 << v22) & m->smallmap) != 0 )
    {
      if ( m->smallbins[2 * v22 + 2] < (malloc_chunk *)m->least_addr )
        abort();
      v38 = (malloc_chunk **)m->smallbins[2 * v22 + 2];
    }
    else
    {
      m->smallmap |= 1 << v22;
    }
    m->smallbins[2 * v22 + 2] = v7;
    v38[3] = v7;
    v7->fd = (malloc_chunk *)v38;
    v7->bk = (malloc_chunk *)&m->smallbins[2 * v22];
    return v32 + 8;
  }
  v23 = v6 >> 8;
  if ( v6 >> 8 )
  {
    if ( v23 <= 0xFFFF )
    {
      _BitScanReverse(&v23, v23);
      v23 = ((v6 >> (v23 + 7)) & 1) + 2 * v23;
    }
    else
    {
      v23 = 31;
    }
  }
  v7[1].head = 0;
  v7[1].prev_foot = 0;
  v7[1].bk = (malloc_chunk *)v23;
  treemap = m->treemap;
  v25 = &m->treebins[v23];
  if ( ((1 << v23) & treemap) == 0 )
  {
    m->treemap = treemap | (1 << v23);
    *v25 = (malloc_tree_chunk *)v7;
    v7[1].fd = (malloc_chunk *)v25;
    goto LABEL_62;
  }
  v26 = (malloc_chunk *)*v25;
  v27 = v39 << (v23 != 31 ? 25 - (v23 >> 1) : 0);
  while ( 1 )
  {
    if ( (v26->head & 0xFFFFFFF8) == v39 )
    {
      least_addr = m->least_addr;
      v30 = v26->fd;
      if ( v26 >= (malloc_chunk *)least_addr && v30 >= (malloc_chunk *)least_addr )
      {
        v30->bk = v7;
        v26->fd = v7;
        v7[1].fd = 0;
        v7->fd = v30;
        v7->bk = v26;
        return v32 + 8;
      }
LABEL_72:
      abort();
    }
    v28 = (char *)(&v26[1].prev_foot + (v27 >> 31));
    v27 *= 2;
    if ( !*(_DWORD *)v28 )
      break;
    v26 = *(malloc_chunk **)v28;
  }
  if ( v28 < m->least_addr )
    goto LABEL_72;
  *(_DWORD *)v28 = v7;
  v7[1].fd = v26;
LABEL_62:
  v7->bk = v7;
  v7->fd = v7;
  return v32 + 8;
}
