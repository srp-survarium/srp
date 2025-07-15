malloc_chunk **__usercall prepend_alloc@<eax>(
        char *newbase@<edx>,
        unsigned int nb@<eax>,
        malloc_tree_chunk *m,
        char *oldbase)
{
  int v5; // ecx
  char *v6; // edx
  int v7; // ecx
  malloc_chunk *v8; // edi
  malloc_chunk *v9; // ebp
  unsigned int v10; // edx
  unsigned int v11; // eax
  unsigned int fd; // eax
  unsigned int head; // eax
  malloc_chunk *bk; // esi
  unsigned int v16; // eax
  unsigned int v17; // ecx
  malloc_chunk *v18; // eax
  malloc_chunk **v19; // ecx
  malloc_tree_chunk *v20; // eax
  malloc_tree_chunk *v21; // ecx
  char *p_head; // ecx
  char *v23; // eax
  malloc_chunk *v24; // ecx
  bool v25; // zf
  malloc_tree_chunk **v26; // ecx
  malloc_tree_chunk *prev_foot; // eax
  malloc_tree_chunk *v28; // eax
  unsigned int v29; // ecx
  malloc_chunk **v30; // esi
  malloc_chunk *v31; // edi
  unsigned int v32; // eax
  unsigned int v33; // ecx
  unsigned int v34; // edi
  malloc_tree_chunk **v35; // esi
  malloc_chunk *v36; // eax
  char v37; // di
  unsigned int v38; // esi
  char *v39; // edi
  char *v40; // ebx
  malloc_chunk *v41; // ecx
  malloc_chunk *p; // [esp+10h] [ebp-8h]
  unsigned int nsize; // [esp+14h] [ebp-4h]
  malloc_tree_chunk *XP; // [esp+1Ch] [ebp+4h]

  v5 = (unsigned __int8)newbase & 7;
  if ( ((unsigned __int8)newbase & 7) != 0 )
    v5 = -v5 & 7;
  v6 = &newbase[v5];
  v7 = (unsigned __int8)oldbase & 7;
  p = (malloc_chunk *)v6;
  if ( ((unsigned __int8)oldbase & 7) != 0 )
    v7 = -v7 & 7;
  v8 = (malloc_chunk *)&oldbase[v7];
  v9 = (malloc_chunk *)&v6[nb];
  v10 = &oldbase[v7] - v6 - nb;
  p->head = nb | 3;
  if ( &oldbase[v7] == (char *)m->parent )
  {
    m->bk = (malloc_tree_chunk *)((char *)m->bk + v10);
    v11 = (int)m->bk | 1;
    m->parent = (malloc_tree_chunk *)v9;
    v9->head = v11;
    return &p->fd;
  }
  if ( v8 == (malloc_chunk *)m->child[1] )
  {
    m->fd = (malloc_tree_chunk *)((char *)m->fd + v10);
    fd = (unsigned int)m->fd;
    m->child[1] = (malloc_tree_chunk *)v9;
    v9->head = fd | 1;
    *(unsigned int *)((char *)&v9->prev_foot + fd) = fd;
    return &p->fd;
  }
  head = v8->head;
  if ( (head & 2) == 0 )
  {
    bk = v8->bk;
    v16 = head & 0xFFFFFFF8;
    v17 = v16 >> 3;
    nsize = v16;
    if ( v16 >> 3 < 0x20 )
    {
      v18 = v8->fd;
      if ( v18 == bk )
      {
        m->prev_foot &= ~(1 << v17);
LABEL_48:
        v8 = (malloc_chunk *)((char *)v8 + nsize);
        v10 += nsize;
        goto LABEL_49;
      }
      v19 = (malloc_chunk **)(&m[1].fd + 2 * v17);
      if ( (v18 == (malloc_chunk *)v19 || (malloc_tree_chunk *)v18 >= m->child[0])
        && (bk == (malloc_chunk *)v19 || (malloc_tree_chunk *)bk >= m->child[0]) )
      {
        v18->bk = bk;
        bk->fd = v18;
        goto LABEL_48;
      }
LABEL_47:
      abort();
    }
    v20 = (malloc_tree_chunk *)v8[1].fd;
    XP = v20;
    if ( bk == v8 )
    {
      bk = (malloc_chunk *)v8[1].head;
      p_head = (char *)&v8[1].head;
      if ( !bk )
      {
        bk = (malloc_chunk *)v8[1].prev_foot;
        p_head = (char *)&v8[1];
        if ( !bk )
          goto LABEL_29;
      }
      while ( 1 )
      {
        v23 = (char *)&bk[1].head;
        if ( !bk[1].head )
        {
          v23 = (char *)&bk[1];
          if ( !bk[1].prev_foot )
            break;
        }
        bk = *(malloc_chunk **)v23;
        p_head = v23;
      }
      if ( (malloc_tree_chunk *)p_head >= m->child[0] )
      {
        *(_DWORD *)p_head = 0;
        v20 = XP;
        goto LABEL_29;
      }
    }
    else
    {
      v21 = (malloc_tree_chunk *)v8->fd;
      if ( v21 >= m->child[0] )
      {
        v21->bk = (malloc_tree_chunk *)bk;
        bk->fd = (malloc_chunk *)v21;
LABEL_29:
        if ( !v20 )
          goto LABEL_48;
        v24 = v8[1].bk;
        v25 = v8 == (malloc_chunk *)m[9].child[(_DWORD)v24];
        v26 = &m[9].child[(_DWORD)v24];
        if ( v25 )
        {
          *v26 = (malloc_tree_chunk *)bk;
          if ( !bk )
          {
            m->head &= ~(1 << (int)v8[1].bk);
            goto LABEL_48;
          }
        }
        else
        {
          if ( v20 < m->child[0] )
            abort();
          if ( (malloc_chunk *)v20->child[0] == v8 )
            v20->child[0] = (malloc_tree_chunk *)bk;
          else
            v20->child[1] = (malloc_tree_chunk *)bk;
          if ( !bk )
            goto LABEL_48;
        }
        if ( (malloc_tree_chunk *)bk >= m->child[0] )
        {
          bk[1].fd = (malloc_chunk *)v20;
          prev_foot = (malloc_tree_chunk *)v8[1].prev_foot;
          if ( prev_foot )
          {
            if ( prev_foot < m->child[0] )
              abort();
            bk[1].prev_foot = (unsigned int)prev_foot;
            prev_foot->parent = (malloc_tree_chunk *)bk;
          }
          v28 = (malloc_tree_chunk *)v8[1].head;
          if ( !v28 )
            goto LABEL_48;
          if ( v28 >= m->child[0] )
          {
            bk[1].head = (unsigned int)v28;
            v28->parent = (malloc_tree_chunk *)bk;
            goto LABEL_48;
          }
        }
        goto LABEL_47;
      }
    }
    abort();
  }
LABEL_49:
  v8->head &= ~1u;
  v9->head = v10 | 1;
  v29 = v10 >> 3;
  *(unsigned int *)((char *)&v9->prev_foot + v10) = v10;
  if ( v10 >> 3 >= 0x20 )
  {
    v32 = v10 >> 8;
    if ( v10 >> 8 )
    {
      if ( v32 <= 0xFFFF )
      {
        _BitScanReverse(&v32, v32);
        v33 = ((v10 >> (v32 + 7)) & 1) + 2 * v32;
      }
      else
      {
        v33 = 31;
      }
    }
    else
    {
      v33 = 0;
    }
    v9[1].head = 0;
    v9[1].prev_foot = 0;
    v9[1].bk = (malloc_chunk *)v33;
    v34 = m->head;
    v35 = &m[9].child[v33];
    if ( ((1 << v33) & v34) == 0 )
    {
      m->head = v34 | (1 << v33);
      *v35 = (malloc_tree_chunk *)v9;
      v9[1].fd = (malloc_chunk *)v35;
      v9->bk = v9;
      v9->fd = v9;
      return &p->fd;
    }
    v36 = (malloc_chunk *)*v35;
    if ( v33 == 31 )
      v37 = 0;
    else
      v37 = 25 - (v33 >> 1);
    v38 = v10 << v37;
    if ( (v36->head & 0xFFFFFFF8) == v10 )
    {
LABEL_68:
      v40 = (char *)m->child[0];
      v41 = v36->fd;
      if ( v36 >= (malloc_chunk *)v40 && v41 >= (malloc_chunk *)v40 )
      {
        v41->bk = v9;
        v36->fd = v9;
        v9->bk = v36;
        v9->fd = v41;
        v9[1].fd = 0;
        return &p->fd;
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
        if ( (*(_DWORD *)(*(_DWORD *)v39 + 4) & 0xFFFFFFF8) == v10 )
          goto LABEL_68;
      }
      if ( (malloc_tree_chunk *)v39 >= m->child[0] )
      {
        *(_DWORD *)v39 = v9;
        v9[1].fd = v36;
        v9->bk = v9;
        v9->fd = v9;
        return &p->fd;
      }
    }
    abort();
  }
  v30 = (malloc_chunk **)(&m[1].fd + 2 * v29);
  if ( ((1 << v29) & m->prev_foot) != 0 )
  {
    if ( m[1].child[2 * v29] < m->child[0] )
      abort();
    v31 = (malloc_chunk *)m[1].child[2 * v29];
    m[1].child[2 * v29] = (malloc_tree_chunk *)v9;
    v31->bk = v9;
    v9->fd = v31;
    v9->bk = (malloc_chunk *)v30;
    return &p->fd;
  }
  else
  {
    m->prev_foot |= 1 << v29;
    m[1].child[2 * v29] = (malloc_tree_chunk *)v9;
    m[1].child[2 * v29 + 1] = (malloc_tree_chunk *)v9;
    v9->fd = (malloc_chunk *)v30;
    v9->bk = (malloc_chunk *)v30;
    return &p->fd;
  }
}
