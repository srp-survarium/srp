malloc_tree_chunk **__cdecl tmalloc_small(malloc_chunk *m, malloc_chunk *nb)
{
  unsigned int v3; // edx
  malloc_tree_chunk *v4; // ecx
  unsigned int v5; // ebp
  malloc_tree_chunk *v6; // edi
  char *prev_foot; // ecx
  malloc_tree_chunk *bk; // esi
  malloc_tree_chunk *fd; // eax
  char *v10; // ecx
  malloc_tree_chunk **child; // eax
  unsigned int index; // ecx
  malloc_chunk *v13; // eax
  malloc_tree_chunk *v14; // eax
  malloc_tree_chunk *v15; // eax
  malloc_tree_chunk **result; // eax
  unsigned int v17; // eax
  int v18; // edx
  malloc_chunk **v19; // ecx
  malloc_chunk *r; // [esp+4h] [ebp-4h]
  malloc_chunk *DV; // [esp+Ch] [ebp+4h]
  malloc_chunk *DVa; // [esp+Ch] [ebp+4h]

  _BitScanForward(&v3, m->head & -m->head);
  v4 = (malloc_tree_chunk *)*(&m[19].prev_foot + v3);
  v5 = (v4->head & 0xFFFFFFF8) - (_DWORD)nb;
LABEL_2:
  v6 = v4;
  while ( 1 )
  {
    v4 = v4->child[0] ? v4->child[0] : v4->child[1];
    if ( !v4 )
      break;
    if ( (v4->head & 0xFFFFFFF8) - (unsigned int)nb < v5 )
    {
      v5 = (v4->head & 0xFFFFFFF8) - (_DWORD)nb;
      goto LABEL_2;
    }
  }
  prev_foot = (char *)m[1].prev_foot;
  if ( v6 < (malloc_tree_chunk *)prev_foot
    || (r = (malloc_chunk *)((char *)nb + (_DWORD)v6), v6 >= (malloc_tree_chunk *)((char *)nb + (int)v6)) )
  {
    abort();
  }
  bk = v6->bk;
  DV = (malloc_chunk *)v6->parent;
  if ( bk != v6 )
  {
    fd = v6->fd;
    if ( fd >= (malloc_tree_chunk *)prev_foot )
    {
      fd->bk = bk;
      bk->fd = fd;
      goto LABEL_22;
    }
LABEL_21:
    abort();
  }
  bk = v6->child[1];
  v10 = (char *)&v6->child[1];
  if ( bk || (bk = v6->child[0], v10 = (char *)v6->child, bk) )
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
      v10 = (char *)child;
    }
    if ( (unsigned int)v10 < m[1].prev_foot )
      goto LABEL_21;
    *(_DWORD *)v10 = 0;
  }
LABEL_22:
  if ( !DV )
    goto LABEL_43;
  index = v6->index;
  if ( v6 == *((malloc_tree_chunk **)&m[19].prev_foot + index) )
  {
    *(&m[19].prev_foot + index) = (unsigned int)bk;
    if ( !bk )
    {
      m->head &= ~(1 << v6->index);
      goto LABEL_43;
    }
    v13 = DV;
  }
  else
  {
    v13 = DV;
    if ( (unsigned int)DV < m[1].prev_foot )
      abort();
    if ( (malloc_tree_chunk *)DV[1].prev_foot == v6 )
      DV[1].prev_foot = (unsigned int)bk;
    else
      DV[1].head = (unsigned int)bk;
    if ( !bk )
      goto LABEL_43;
  }
  if ( (unsigned int)bk < m[1].prev_foot )
    goto LABEL_42;
  bk->parent = (malloc_tree_chunk *)v13;
  v14 = v6->child[0];
  if ( v14 )
  {
    if ( (unsigned int)v14 < m[1].prev_foot )
      abort();
    bk->child[0] = v14;
    v14->parent = bk;
  }
  v15 = v6->child[1];
  if ( v15 )
  {
    if ( (unsigned int)v15 >= m[1].prev_foot )
    {
      bk->child[1] = v15;
      v15->parent = bk;
      goto LABEL_43;
    }
LABEL_42:
    abort();
  }
LABEL_43:
  if ( v5 >= 0x10 )
  {
    v6->head = (unsigned int)nb | 3;
    r->head = v5 | 1;
    *(unsigned int *)((char *)&r->prev_foot + v5) = v5;
    v17 = (unsigned int)m->fd;
    if ( v17 )
    {
      DVa = (malloc_chunk *)m[1].head;
      v18 = 1 << (v17 >> 3);
      if ( (m->prev_foot & v18) != 0 )
      {
        v19 = (malloc_chunk **)*(&m[3].prev_foot + 2 * (v17 >> 3));
        if ( (unsigned int)v19 < m[1].prev_foot )
          abort();
      }
      else
      {
        m->prev_foot |= v18;
        v19 = &m[2].fd + 2 * (v17 >> 3);
      }
      *(&m[3].prev_foot + 2 * (v17 >> 3)) = (unsigned int)DVa;
      v19[3] = DVa;
      DVa->fd = (malloc_chunk *)v19;
      DVa->bk = (malloc_chunk *)((char *)m + 8 * (v17 >> 3) + 40);
    }
    result = &v6->fd;
    m->fd = (malloc_chunk *)v5;
    m[1].head = (unsigned int)r;
  }
  else
  {
    v6->head = ((unsigned int)nb + v5) | 3;
    *(unsigned int *)((char *)&v6->head + v5 + (_DWORD)nb) |= 1u;
    return &v6->fd;
  }
  return result;
}
