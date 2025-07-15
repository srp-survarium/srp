malloc_tree_chunk **__cdecl tmalloc_large(malloc_state *m, unsigned int nb)
{
  malloc_tree_chunk *v3; // edx
  unsigned int v4; // eax
  unsigned int v5; // esi
  malloc_tree_chunk *v6; // eax
  unsigned int v7; // esi
  unsigned int v8; // ecx
  malloc_tree_chunk *v9; // ecx
  unsigned int v10; // esi
  unsigned int v11; // eax
  malloc_chunk *v12; // esi
  malloc_tree_chunk *bk; // edi
  malloc_tree_chunk *fd; // eax
  char *v15; // eax
  char *child; // ecx
  malloc_tree_chunk *v17; // eax
  malloc_tree_chunk **v18; // ecx
  malloc_tree_chunk *v19; // ecx
  malloc_tree_chunk *v20; // eax
  unsigned int v21; // ecx
  malloc_chunk **v22; // eax
  unsigned int v23; // ecx
  unsigned int v24; // eax
  unsigned int treemap; // ecx
  malloc_tree_chunk **v26; // edx
  unsigned int v27; // eax
  char *v28; // ecx
  char *least_addr; // ebx
  malloc_chunk *v30; // eax
  malloc_tree_chunk *v32; // [esp+Ch] [ebp-Ch]
  char v33; // [esp+10h] [ebp-8h]
  malloc_tree_chunk *parent; // [esp+10h] [ebp-8h]
  malloc_tree_chunk *v35; // [esp+14h] [ebp-4h]
  unsigned int v36; // [esp+20h] [ebp+8h]

  v36 = -nb;
  v3 = 0;
  v4 = nb >> 8;
  v35 = 0;
  if ( nb >> 8 )
  {
    if ( v4 <= 0xFFFF )
    {
      _BitScanReverse(&v4, v4);
      v5 = ((nb >> (v4 + 7)) & 1) + 2 * v4;
    }
    else
    {
      v5 = 31;
    }
  }
  else
  {
    v5 = 0;
  }
  v6 = m->treebins[v5];
  v33 = v5;
  if ( v6 )
  {
    v7 = nb << (v5 != 31 ? 25 - (v5 >> 1) : 0);
    v32 = 0;
    while ( 1 )
    {
      v8 = (v6->head & 0xFFFFFFF8) - nb;
      if ( v8 < v36 )
      {
        v3 = v6;
        v35 = v6;
        v36 = (v6->head & 0xFFFFFFF8) - nb;
        if ( !v8 )
          break;
      }
      v9 = v6->child[1];
      v6 = v6->child[v7 >> 31];
      if ( v9 && v9 != v6 )
        v32 = v9;
      if ( !v6 )
      {
        v6 = v32;
        break;
      }
      v7 *= 2;
    }
    if ( v6 )
      goto LABEL_21;
    if ( v3 )
      goto LABEL_29;
  }
  if ( (m->treemap & (2 * (-1 << v33))) != 0 )
  {
    v10 = m->treemap & (2 * (-1 << v33));
    _BitScanForward(&v11, v10 & -v10);
    v6 = m->treebins[v11];
  }
  if ( v6 )
  {
    do
    {
LABEL_21:
      if ( (v6->head & 0xFFFFFFF8) - nb < v36 )
      {
        v36 = (v6->head & 0xFFFFFFF8) - nb;
        v3 = v6;
      }
      if ( v6->child[0] )
        v6 = v6->child[0];
      else
        v6 = v6->child[1];
    }
    while ( v6 );
    v35 = v3;
  }
  if ( !v3 )
    return 0;
LABEL_29:
  if ( v36 >= m->dvsize - nb )
    return 0;
  if ( (char *)v3 < m->least_addr
    || (v12 = (malloc_chunk *)((char *)v3 + nb), v3 >= (malloc_tree_chunk *)((char *)v3 + nb)) )
  {
    abort();
  }
  bk = v3->bk;
  parent = v3->parent;
  if ( bk != v3 )
  {
    fd = v3->fd;
    if ( (char *)fd >= m->least_addr )
    {
      fd->bk = bk;
      bk->fd = fd;
      goto LABEL_43;
    }
LABEL_42:
    abort();
  }
  v15 = (char *)&v3->child[1];
  bk = v3->child[1];
  if ( bk || (v15 = (char *)v3->child, (bk = v3->child[0]) != 0) )
  {
    while ( 1 )
    {
      child = (char *)&bk->child[1];
      if ( !bk->child[1] )
      {
        child = (char *)bk->child;
        if ( !bk->child[0] )
          break;
      }
      bk = *(malloc_tree_chunk **)child;
      v15 = child;
    }
    if ( v15 < m->least_addr )
      goto LABEL_42;
    *(_DWORD *)v15 = 0;
  }
LABEL_43:
  if ( parent )
  {
    v17 = v35;
    v18 = &m->treebins[v35->index];
    if ( v35 == *v18 )
    {
      *v18 = bk;
      if ( !bk )
      {
        m->treemap &= ~(1 << v35->index);
        goto LABEL_63;
      }
    }
    else
    {
      if ( (char *)parent < m->least_addr )
        abort();
      if ( parent->child[0] == v35 )
        parent->child[0] = bk;
      else
        parent->child[1] = bk;
      if ( !bk )
        goto LABEL_63;
      v17 = v35;
    }
    if ( (char *)bk < m->least_addr )
      goto LABEL_62;
    bk->parent = parent;
    v19 = v17->child[0];
    if ( v19 )
    {
      if ( (char *)v19 < m->least_addr )
        abort();
      bk->child[0] = v19;
      v19->parent = bk;
    }
    v20 = v17->child[1];
    if ( !v20 )
      goto LABEL_63;
    if ( (char *)v20 < m->least_addr )
LABEL_62:
      abort();
    bk->child[1] = v20;
    v20->parent = bk;
  }
LABEL_63:
  if ( v36 < 0x10 )
  {
    v35->head = (v36 + nb) | 3;
    *(unsigned int *)((char *)&v35->head + v36 + nb) |= 1u;
    return &v35->fd;
  }
  v35->head = nb | 3;
  v12->head = v36 | 1;
  v21 = v36 >> 3;
  *(unsigned int *)((char *)&v12->prev_foot + v36) = v36;
  if ( v36 >> 3 < 0x20 )
  {
    if ( (m->smallmap & (1 << v21)) != 0 )
    {
      v22 = (malloc_chunk **)m->smallbins[2 * v21 + 2];
      if ( (char *)v22 < m->least_addr )
        abort();
    }
    else
    {
      m->smallmap |= 1 << v21;
      v22 = &m->smallbins[2 * v21];
    }
    m->smallbins[2 * v21 + 2] = v12;
    v22[3] = v12;
    v12->fd = (malloc_chunk *)v22;
    v12->bk = (malloc_chunk *)&m->smallbins[2 * v21];
    return &v35->fd;
  }
  v23 = v36 >> 8;
  if ( v36 >> 8 )
  {
    if ( v23 <= 0xFFFF )
    {
      _BitScanReverse(&v23, v23);
      v24 = ((v36 >> (v23 + 7)) & 1) + 2 * v23;
    }
    else
    {
      v24 = 31;
    }
  }
  else
  {
    v24 = 0;
  }
  v12[1].head = 0;
  v12[1].prev_foot = 0;
  v12[1].bk = (malloc_chunk *)v24;
  treemap = m->treemap;
  v26 = &m->treebins[v24];
  if ( ((1 << v24) & treemap) == 0 )
  {
    m->treemap = treemap | (1 << v24);
    *v26 = (malloc_tree_chunk *)v12;
    goto LABEL_78;
  }
  v26 = (malloc_tree_chunk **)*v26;
  v27 = v36 << (v24 != 31 ? 25 - (v24 >> 1) : 0);
  while ( 1 )
  {
    if ( ((unsigned int)v26[1] & 0xFFFFFFF8) == v36 )
    {
      least_addr = m->least_addr;
      v30 = (malloc_chunk *)v26[2];
      if ( v26 >= (malloc_tree_chunk **)least_addr && v30 >= (malloc_chunk *)least_addr )
      {
        v30->bk = v12;
        v26[2] = (malloc_tree_chunk *)v12;
        v12[1].fd = 0;
        v12->fd = v30;
        v12->bk = (malloc_chunk *)v26;
        return &v35->fd;
      }
LABEL_88:
      abort();
    }
    v28 = (char *)&v26[(v27 >> 31) + 4];
    v27 *= 2;
    if ( !*(_DWORD *)v28 )
      break;
    v26 = *(malloc_tree_chunk ***)v28;
  }
  if ( v28 < m->least_addr )
    goto LABEL_88;
  *(_DWORD *)v28 = v12;
LABEL_78:
  v12[1].fd = (malloc_chunk *)v26;
  v12->bk = v12;
  v12->fd = v12;
  return &v35->fd;
}
