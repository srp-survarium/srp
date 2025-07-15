malloc_tree_chunk **__usercall tmalloc_small@<eax>(malloc_state *m@<esi>, unsigned int nb)
{
  unsigned int v2; // eax
  malloc_tree_chunk *v3; // eax
  unsigned int v4; // edx
  malloc_tree_chunk *v5; // ebx
  malloc_tree_chunk *bk; // edi
  malloc_tree_chunk *parent; // ecx
  malloc_tree_chunk *fd; // eax
  char *v9; // eax
  char *child; // ecx
  malloc_tree_chunk **v11; // eax
  malloc_tree_chunk *v12; // eax
  malloc_tree_chunk *v13; // eax
  unsigned int dvsize; // eax
  unsigned int v15; // eax
  malloc_chunk **v16; // ecx
  malloc_chunk *dv; // [esp+0h] [ebp-10h]
  malloc_chunk *v19; // [esp+4h] [ebp-Ch]
  malloc_tree_chunk *v20; // [esp+8h] [ebp-8h]

  _BitScanForward(&v2, m->treemap & -m->treemap);
  v3 = m->treebins[v2];
  v4 = (v3->head & 0xFFFFFFF8) - nb;
LABEL_2:
  v5 = v3;
  while ( 1 )
  {
    v3 = v3->child[0] ? v3->child[0] : v3->child[1];
    if ( !v3 )
      break;
    if ( (v3->head & 0xFFFFFFF8) - nb < v4 )
    {
      v4 = (v3->head & 0xFFFFFFF8) - nb;
      goto LABEL_2;
    }
  }
  if ( (char *)v5 < m->least_addr
    || (v19 = (malloc_chunk *)((char *)v5 + nb), v5 >= (malloc_tree_chunk *)((char *)v5 + nb)) )
  {
    abort();
  }
  bk = v5->bk;
  parent = v5->parent;
  v20 = parent;
  if ( bk != v5 )
  {
    fd = v5->fd;
    if ( (char *)fd >= m->least_addr )
    {
      fd->bk = bk;
      bk->fd = fd;
LABEL_22:
      parent = v20;
      goto LABEL_23;
    }
    goto LABEL_21;
  }
  v9 = (char *)&v5->child[1];
  bk = v5->child[1];
  if ( bk || (v9 = (char *)v5->child, (bk = v5->child[0]) != 0) )
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
      v9 = child;
    }
    if ( v9 >= m->least_addr )
    {
      *(_DWORD *)v9 = 0;
      goto LABEL_22;
    }
LABEL_21:
    abort();
  }
LABEL_23:
  if ( !parent )
    goto LABEL_42;
  v11 = &m->treebins[v5->index];
  if ( v5 == *v11 )
  {
    *v11 = bk;
    if ( !bk )
    {
      m->treemap &= ~(1 << v5->index);
      goto LABEL_42;
    }
  }
  else
  {
    if ( (char *)parent < m->least_addr )
      abort();
    if ( parent->child[0] == v5 )
      parent->child[0] = bk;
    else
      parent->child[1] = bk;
    if ( !bk )
      goto LABEL_42;
  }
  if ( (char *)bk < m->least_addr )
    goto LABEL_41;
  bk->parent = parent;
  v12 = v5->child[0];
  if ( v12 )
  {
    if ( (char *)v12 < m->least_addr )
      abort();
    bk->child[0] = v12;
    v12->parent = bk;
  }
  v13 = v5->child[1];
  if ( v13 )
  {
    if ( (char *)v13 >= m->least_addr )
    {
      bk->child[1] = v13;
      v13->parent = bk;
      goto LABEL_42;
    }
LABEL_41:
    abort();
  }
LABEL_42:
  if ( v4 >= 0x10 )
  {
    v5->head = nb | 3;
    v19->head = v4 | 1;
    *(unsigned int *)((char *)&v19->prev_foot + v4) = v4;
    dvsize = m->dvsize;
    if ( dvsize )
    {
      v15 = dvsize >> 3;
      dv = m->dv;
      if ( (m->smallmap & (1 << v15)) != 0 )
      {
        v16 = (malloc_chunk **)m->smallbins[2 * v15 + 2];
        if ( (char *)v16 < m->least_addr )
          abort();
      }
      else
      {
        m->smallmap |= 1 << v15;
        v16 = &m->smallbins[2 * v15];
      }
      m->smallbins[2 * v15 + 2] = dv;
      v16[3] = dv;
      dv->fd = (malloc_chunk *)v16;
      dv->bk = (malloc_chunk *)&m->smallbins[2 * v15];
    }
    m->dvsize = v4;
    m->dv = v19;
  }
  else
  {
    v5->head = (v4 + nb) | 3;
    *(unsigned int *)((char *)&v5->head + v4 + nb) |= 1u;
  }
  return &v5->fd;
}
