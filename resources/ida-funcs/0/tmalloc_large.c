malloc_tree_chunk **__cdecl tmalloc_large(malloc_state *m, int nb)
{
  malloc_tree_chunk *v3; // edi
  unsigned int v4; // eax
  unsigned int v5; // ebx
  unsigned int v6; // esi
  malloc_tree_chunk *v7; // eax
  int v8; // ecx
  unsigned int v9; // edx
  unsigned int v10; // ecx
  malloc_tree_chunk *v11; // ecx
  unsigned int v12; // edx
  unsigned int v13; // ecx
  char *least_addr; // edx
  malloc_chunk *v15; // edi
  malloc_tree_chunk *bk; // esi
  malloc_tree_chunk *fd; // eax
  malloc_tree_chunk **v18; // ecx
  malloc_tree_chunk **child; // eax
  malloc_tree_chunk *v20; // ecx
  unsigned int index; // eax
  malloc_state *v22; // edx
  bool v23; // zf
  malloc_tree_chunk **v24; // eax
  malloc_tree_chunk *v25; // eax
  malloc_tree_chunk *v26; // eax
  unsigned int v28; // ecx
  malloc_chunk **v29; // esi
  malloc_chunk *v30; // ebx
  unsigned int v31; // eax
  unsigned int v32; // ecx
  unsigned int v33; // edx
  unsigned int treemap; // esi
  malloc_tree_chunk **v35; // edx
  malloc_chunk *v36; // eax
  char v37; // si
  unsigned int v38; // edx
  char *v39; // esi
  char *v40; // edx
  malloc_chunk *v41; // ecx
  unsigned int K; // [esp+10h] [ebp-4h]
  unsigned int Ka; // [esp+10h] [ebp-4h]
  malloc_tree_chunk *v; // [esp+1Ch] [ebp+8h]

  v3 = 0;
  v4 = (unsigned int)nb >> 8;
  v5 = -nb;
  v = 0;
  if ( v4 )
  {
    if ( v4 <= 0xFFFF )
    {
      _BitScanReverse(&v4, v4);
      v6 = (((unsigned int)nb >> (v4 + 7)) & 1) + 2 * v4;
    }
    else
    {
      v6 = 31;
    }
  }
  else
  {
    v6 = 0;
  }
  v7 = m->treebins[v6];
  if ( v7 )
  {
    if ( v6 == 31 )
      LOBYTE(v8) = 0;
    else
      v8 = 25 - (v6 >> 1);
    v9 = nb << v8;
    K = 0;
    while ( 1 )
    {
      v10 = (v7->head & 0xFFFFFFF8) - nb;
      if ( v10 < v5 )
      {
        v3 = v7;
        v = v7;
        v5 = (v7->head & 0xFFFFFFF8) - nb;
        if ( !v10 )
          break;
      }
      v11 = v7->child[1];
      v7 = v7->child[v9 >> 31];
      if ( v11 && v11 != v7 )
        K = (unsigned int)v11;
      if ( !v7 )
      {
        v7 = (malloc_tree_chunk *)K;
        v3 = v;
        break;
      }
      v9 *= 2;
    }
    if ( v7 )
      goto LABEL_24;
    if ( v3 )
      goto LABEL_32;
  }
  if ( (m->treemap & (2 * (-1 << v6))) != 0 )
  {
    v12 = m->treemap & (2 * (-1 << v6));
    _BitScanForward(&v13, v12 & -v12);
    v7 = m->treebins[v13];
  }
  if ( v7 )
  {
    do
    {
LABEL_24:
      if ( (v7->head & 0xFFFFFFF8) - nb < v5 )
      {
        v5 = (v7->head & 0xFFFFFFF8) - nb;
        v3 = v7;
      }
      if ( v7->child[0] )
        v7 = v7->child[0];
      else
        v7 = v7->child[1];
    }
    while ( v7 );
    v = v3;
  }
  if ( !v3 )
    return 0;
LABEL_32:
  if ( v5 >= m->dvsize - nb )
    return 0;
  least_addr = m->least_addr;
  if ( v3 < (malloc_tree_chunk *)least_addr
    || (v15 = (malloc_chunk *)((char *)v + nb), v >= (malloc_tree_chunk *)((char *)v + nb)) )
  {
    abort();
  }
  bk = v->bk;
  Ka = (unsigned int)v->parent;
  if ( bk != v )
  {
    fd = v->fd;
    if ( fd >= (malloc_tree_chunk *)least_addr )
    {
      fd->bk = bk;
      bk->fd = fd;
      goto LABEL_46;
    }
LABEL_45:
    abort();
  }
  bk = v->child[1];
  v18 = &v->child[1];
  if ( bk || (bk = v->child[0], v18 = v->child, bk) )
  {
    while ( 1 )
    {
      child = &bk->child[1];
      if ( !bk->child[1] )
      {
        child = bk->child;
        if ( !bk->child[0] )
          break;
      }
      bk = *child;
      v18 = child;
    }
    if ( v18 < (malloc_tree_chunk **)least_addr )
      goto LABEL_45;
    *v18 = 0;
  }
LABEL_46:
  if ( Ka )
  {
    v20 = v;
    index = v->index;
    v22 = m;
    v23 = v == m->treebins[index];
    v24 = &m->treebins[index];
    if ( v23 )
    {
      *v24 = bk;
      if ( !bk )
      {
        m->treemap &= ~(1 << v->index);
        goto LABEL_66;
      }
    }
    else
    {
      if ( (char *)Ka < m->least_addr )
        abort();
      if ( *(malloc_tree_chunk **)(Ka + 16) == v )
        *(_DWORD *)(Ka + 16) = bk;
      else
        *(_DWORD *)(Ka + 20) = bk;
      if ( !bk )
        goto LABEL_66;
      v20 = v;
      v22 = m;
    }
    if ( (char *)bk < v22->least_addr )
      goto LABEL_65;
    bk->parent = (malloc_tree_chunk *)Ka;
    v25 = v20->child[0];
    if ( v25 )
    {
      if ( (char *)v25 < v22->least_addr )
        abort();
      bk->child[0] = v25;
      v25->parent = bk;
    }
    v26 = v20->child[1];
    if ( !v26 )
      goto LABEL_66;
    if ( (char *)v26 < m->least_addr )
LABEL_65:
      abort();
    bk->child[1] = v26;
    v26->parent = bk;
  }
LABEL_66:
  if ( v5 < 0x10 )
  {
    v->head = (v5 + nb) | 3;
    *(unsigned int *)((char *)&v->head + v5 + nb) |= 1u;
    return &v->fd;
  }
  v->head = nb | 3;
  v15->head = v5 | 1;
  v28 = v5 >> 3;
  *(unsigned int *)((char *)&v15->prev_foot + v5) = v5;
  if ( v5 >> 3 >= 0x20 )
  {
    v31 = v5 >> 8;
    if ( v5 >> 8 )
    {
      if ( v31 <= 0xFFFF )
      {
        _BitScanReverse(&v33, v31);
        v32 = ((v5 >> (v33 + 7)) & 1) + 2 * v33;
      }
      else
      {
        v32 = 31;
      }
    }
    else
    {
      v32 = 0;
    }
    v15[1].head = 0;
    v15[1].prev_foot = 0;
    v15[1].bk = (malloc_chunk *)v32;
    treemap = m->treemap;
    v35 = &m->treebins[v32];
    if ( ((1 << v32) & treemap) == 0 )
    {
      m->treemap = treemap | (1 << v32);
      *v35 = (malloc_tree_chunk *)v15;
      v15[1].fd = (malloc_chunk *)v35;
      v15->bk = v15;
      v15->fd = v15;
      return &v->fd;
    }
    v36 = (malloc_chunk *)*v35;
    if ( v32 == 31 )
      v37 = 0;
    else
      v37 = 25 - (v32 >> 1);
    v38 = v5 << v37;
    if ( (v36->head & 0xFFFFFFF8) == v5 )
    {
LABEL_87:
      v40 = m->least_addr;
      v41 = v36->fd;
      if ( v36 >= (malloc_chunk *)v40 && v41 >= (malloc_chunk *)v40 )
      {
        v41->bk = v15;
        v36->fd = v15;
        v15->bk = v36;
        v15->fd = v41;
        v15[1].fd = 0;
        return &v->fd;
      }
    }
    else
    {
      while ( 1 )
      {
        v39 = (char *)(&v36[1].prev_foot + (v38 >> 31));
        v38 *= 2;
        if ( !*(_DWORD *)v39 )
          break;
        v36 = *(malloc_chunk **)v39;
        if ( (*(_DWORD *)(*(_DWORD *)v39 + 4) & 0xFFFFFFF8) == v5 )
          goto LABEL_87;
      }
      if ( v39 >= m->least_addr )
      {
        *(_DWORD *)v39 = v15;
        v15[1].fd = v36;
        v15->bk = v15;
        v15->fd = v15;
        return &v->fd;
      }
    }
    abort();
  }
  v29 = &m->smallbins[2 * v28];
  if ( (m->smallmap & (1 << v28)) != 0 )
  {
    if ( m->smallbins[2 * v28 + 2] < (malloc_chunk *)m->least_addr )
      abort();
    v30 = m->smallbins[2 * v28 + 2];
    m->smallbins[2 * v28 + 2] = v15;
    v30->bk = v15;
    v15->fd = v30;
    v15->bk = (malloc_chunk *)v29;
    return &v->fd;
  }
  else
  {
    m->smallmap |= 1 << v28;
    m->smallbins[2 * v28 + 2] = v15;
    m->smallbins[2 * v28 + 3] = v15;
    v15->fd = (malloc_chunk *)v29;
    v15->bk = (malloc_chunk *)v29;
    return &v->fd;
  }
}
