void __usercall vostok_mspace_free(malloc_state *msp@<esi>, char *mem@<eax>)
{
  char *v2; // edi
  unsigned int v3; // ebp
  char *v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // ebx
  char *least_addr; // ebx
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // edx
  unsigned int head; // eax
  unsigned int topsize; // eax
  char *v14; // eax
  malloc_tree_chunk *v15; // ebx
  unsigned int v16; // edx
  unsigned int v17; // eax
  char *v18; // ecx
  char *child; // eax
  int v20; // eax
  bool v21; // zf
  malloc_tree_chunk **v22; // eax
  unsigned int v23; // eax
  malloc_tree_chunk *v24; // eax
  unsigned int dvsize; // eax
  unsigned int v26; // eax
  unsigned int v27; // ecx
  malloc_chunk *fd; // eax
  malloc_chunk *bk; // edx
  char *v30; // ecx
  malloc_chunk *prev_foot; // ebx
  malloc_chunk *v32; // eax
  malloc_chunk *v33; // ecx
  malloc_chunk *v34; // eax
  malloc_chunk *v35; // ecx
  malloc_chunk **v36; // eax
  unsigned int v37; // eax
  unsigned int v38; // eax
  unsigned int v39; // ecx
  malloc_chunk **v40; // ebx
  malloc_chunk *v41; // eax
  unsigned int v42; // eax
  unsigned int v43; // ecx
  unsigned int v44; // edx
  unsigned int treemap; // ebx
  malloc_tree_chunk **v46; // edx
  malloc_tree_chunk *v47; // eax
  char v48; // bl
  unsigned int v49; // edx
  unsigned int v50; // ebx
  char *v51; // edx
  unsigned int v52; // ecx
  malloc_chunk *next; // [esp+4h] [ebp-Ch]
  unsigned int K; // [esp+Ch] [ebp-4h]

  if ( !mem )
    return;
  v2 = mem - 8;
  if ( mem - 8 < msp->least_addr || (v2[4] & 2) == 0 )
    goto erroraction;
  v3 = *((_DWORD *)v2 + 1) & 0xFFFFFFF8;
  v4 = &v2[v3];
  next = (malloc_chunk *)&v2[v3];
  if ( (*((_DWORD *)v2 + 1) & 1) != 0 )
    goto LABEL_14;
  v5 = *(_DWORD *)v2;
  if ( (*(_DWORD *)v2 & 1) != 0 )
  {
    v6 = v5 & 0xFFFFFFFE;
    v7 = v6 + v3 + 16;
    if ( !munmap((virtual_alloc_arena *)&v2[-v6], &v2[-v6], v7) )
      msp->footprint -= v7;
    return;
  }
  least_addr = msp->least_addr;
  v2 -= v5;
  v3 += v5;
  if ( v2 < least_addr )
erroraction:
    abort();
  if ( v2 == (char *)msp->dv )
  {
    if ( (v4[4] & 3) == 3 )
    {
      msp->dvsize = v3;
      *((_DWORD *)v4 + 1) &= ~1u;
      *((_DWORD *)v2 + 1) = v3 | 1;
      *(_DWORD *)&v2[v3] = v3;
      return;
    }
    goto LABEL_14;
  }
  v9 = v5 >> 3;
  if ( v9 < 0x20 )
  {
    v10 = *((_DWORD *)v2 + 2);
    v11 = *((_DWORD *)v2 + 3);
    if ( v10 == v11 )
    {
      msp->smallmap &= ~(1 << v9);
      goto LABEL_14;
    }
    v14 = (char *)&msp->smallbins[2 * v9];
    if ( ((char *)v10 == v14 || v10 >= (unsigned int)least_addr)
      && ((char *)v11 == v14 || v11 >= (unsigned int)least_addr) )
    {
      *(_DWORD *)(v10 + 12) = v11;
      *(_DWORD *)(v11 + 8) = v10;
      goto LABEL_14;
    }
LABEL_26:
    abort();
  }
  v15 = (malloc_tree_chunk *)*((_DWORD *)v2 + 3);
  v16 = *((_DWORD *)v2 + 6);
  if ( v15 == (malloc_tree_chunk *)v2 )
  {
    v15 = (malloc_tree_chunk *)*((_DWORD *)v2 + 5);
    v18 = v2 + 20;
    if ( !v15 )
    {
      v15 = (malloc_tree_chunk *)*((_DWORD *)v2 + 4);
      v18 = v2 + 16;
      if ( !v15 )
        goto LABEL_39;
    }
    while ( 1 )
    {
      child = (char *)&v15->child[1];
      if ( !v15->child[1] )
      {
        child = (char *)v15->child;
        if ( !v15->child[0] )
          break;
      }
      v15 = *(malloc_tree_chunk **)child;
      v18 = child;
    }
    if ( v18 >= msp->least_addr )
    {
      *(_DWORD *)v18 = 0;
      goto LABEL_39;
    }
LABEL_38:
    abort();
  }
  v17 = *((_DWORD *)v2 + 2);
  if ( (char *)v17 < msp->least_addr )
    goto LABEL_38;
  *(_DWORD *)(v17 + 12) = v15;
  v15->fd = (malloc_tree_chunk *)v17;
LABEL_39:
  if ( !v16 )
    goto LABEL_14;
  v20 = *((_DWORD *)v2 + 7);
  v21 = v2 == (char *)msp->treebins[v20];
  v22 = &msp->treebins[v20];
  if ( v21 )
  {
    *v22 = v15;
    if ( !v15 )
    {
      msp->treemap &= ~(1 << *((_DWORD *)v2 + 7));
      goto LABEL_14;
    }
  }
  else
  {
    if ( (char *)v16 < msp->least_addr )
      abort();
    if ( *(char **)(v16 + 16) == v2 )
      *(_DWORD *)(v16 + 16) = v15;
    else
      *(_DWORD *)(v16 + 20) = v15;
    if ( !v15 )
      goto LABEL_14;
  }
  if ( (char *)v15 < msp->least_addr )
    goto LABEL_26;
  v15->parent = (malloc_tree_chunk *)v16;
  v23 = *((_DWORD *)v2 + 4);
  if ( v23 )
  {
    if ( (char *)v23 < msp->least_addr )
      abort();
    v15->child[0] = (malloc_tree_chunk *)v23;
    *(_DWORD *)(v23 + 24) = v15;
  }
  v24 = (malloc_tree_chunk *)*((_DWORD *)v2 + 5);
  if ( v24 )
  {
    if ( (char *)v24 >= msp->least_addr )
    {
      v15->child[1] = v24;
      v24->parent = v15;
      goto LABEL_14;
    }
    goto LABEL_26;
  }
LABEL_14:
  if ( v2 >= (char *)next )
    goto erroraction;
  head = next->head;
  if ( (head & 1) == 0 )
    goto erroraction;
  if ( (head & 2) != 0 )
  {
    next->head = head & 0xFFFFFFFE;
    *((_DWORD *)v2 + 1) = v3 | 1;
    *(_DWORD *)&v2[v3] = v3;
    goto LABEL_103;
  }
  if ( next == msp->top )
  {
    msp->topsize += v3;
    topsize = msp->topsize;
    msp->top = (malloc_chunk *)v2;
    *((_DWORD *)v2 + 1) = topsize | 1;
    if ( v2 == (char *)msp->dv )
    {
      msp->dv = 0;
      msp->dvsize = 0;
    }
    if ( topsize > msp->trim_check )
      sys_trim(msp, 0);
    return;
  }
  if ( next == msp->dv )
  {
    msp->dvsize += v3;
    dvsize = msp->dvsize;
    msp->dv = (malloc_chunk *)v2;
    *((_DWORD *)v2 + 1) = dvsize | 1;
    *(_DWORD *)&v2[dvsize] = dvsize;
    return;
  }
  v26 = head & 0xFFFFFFF8;
  v27 = v26 >> 3;
  v3 += v26;
  if ( v26 >> 3 < 0x20 )
  {
    fd = next->fd;
    bk = next->bk;
    if ( fd == bk )
    {
      msp->smallmap &= ~(1 << v27);
      goto LABEL_100;
    }
    v30 = (char *)&msp->smallbins[2 * v27];
    if ( (fd == (malloc_chunk *)v30 || (char *)fd >= msp->least_addr)
      && (bk == (malloc_chunk *)v30 || (char *)bk >= msp->least_addr) )
    {
      fd->bk = bk;
      bk->fd = fd;
      goto LABEL_100;
    }
LABEL_99:
    abort();
  }
  prev_foot = next->bk;
  K = (unsigned int)next[1].fd;
  if ( prev_foot != next )
  {
    v32 = next->fd;
    if ( (char *)v32 >= msp->least_addr )
    {
      v32->bk = prev_foot;
      prev_foot->fd = v32;
      goto LABEL_80;
    }
LABEL_79:
    abort();
  }
  prev_foot = (malloc_chunk *)next[1].head;
  v33 = (malloc_chunk *)((char *)next + 20);
  if ( prev_foot || (prev_foot = (malloc_chunk *)next[1].prev_foot, v33 = next + 1, prev_foot) )
  {
    while ( 1 )
    {
      v34 = (malloc_chunk *)((char *)prev_foot + 20);
      if ( !prev_foot[1].head )
      {
        v34 = prev_foot + 1;
        if ( !prev_foot[1].prev_foot )
          break;
      }
      prev_foot = (malloc_chunk *)v34->prev_foot;
      v33 = v34;
    }
    if ( (char *)v33 < msp->least_addr )
      goto LABEL_79;
    v33->prev_foot = 0;
  }
LABEL_80:
  if ( !K )
    goto LABEL_100;
  v35 = next;
  v36 = (malloc_chunk **)&msp->treebins[(int)next[1].bk];
  if ( next == *v36 )
  {
    *v36 = prev_foot;
    if ( !prev_foot )
    {
      msp->treemap &= ~(1 << (int)next[1].bk);
      goto LABEL_100;
    }
  }
  else
  {
    if ( (char *)K < msp->least_addr )
      abort();
    if ( *(malloc_chunk **)(K + 16) == next )
      *(_DWORD *)(K + 16) = prev_foot;
    else
      *(_DWORD *)(K + 20) = prev_foot;
    if ( !prev_foot )
      goto LABEL_100;
    v35 = next;
  }
  if ( (char *)prev_foot < msp->least_addr )
    goto LABEL_99;
  prev_foot[1].fd = (malloc_chunk *)K;
  v37 = v35[1].prev_foot;
  if ( v37 )
  {
    if ( (char *)v37 < msp->least_addr )
      abort();
    prev_foot[1].prev_foot = v37;
    *(_DWORD *)(v37 + 24) = prev_foot;
  }
  v38 = v35[1].head;
  if ( v38 )
  {
    if ( (char *)v38 < msp->least_addr )
      goto LABEL_99;
    prev_foot[1].head = v38;
    *(_DWORD *)(v38 + 24) = prev_foot;
  }
LABEL_100:
  *((_DWORD *)v2 + 1) = v3 | 1;
  *(_DWORD *)&v2[v3] = v3;
  if ( v2 == (char *)msp->dv )
  {
    msp->dvsize = v3;
    return;
  }
LABEL_103:
  v39 = v3 >> 3;
  if ( v3 >> 3 < 0x20 )
  {
    v40 = &msp->smallbins[2 * v39];
    if ( ((1 << v39) & msp->smallmap) != 0 )
    {
      v41 = msp->smallbins[2 * v39 + 2];
      if ( (char *)v41 < msp->least_addr )
        abort();
      msp->smallbins[2 * v39 + 2] = (malloc_chunk *)v2;
      v41->bk = (malloc_chunk *)v2;
      *((_DWORD *)v2 + 2) = v41;
      *((_DWORD *)v2 + 3) = v40;
    }
    else
    {
      msp->smallmap |= 1 << v39;
      msp->smallbins[2 * v39 + 2] = (malloc_chunk *)v2;
      msp->smallbins[2 * v39 + 3] = (malloc_chunk *)v2;
      *((_DWORD *)v2 + 2) = v40;
      *((_DWORD *)v2 + 3) = v40;
    }
    return;
  }
  v42 = v3 >> 8;
  if ( v3 >> 8 )
  {
    if ( v42 <= 0xFFFF )
    {
      _BitScanReverse(&v44, v42);
      v43 = ((v3 >> (v44 + 7)) & 1) + 2 * v44;
    }
    else
    {
      v43 = 31;
    }
  }
  else
  {
    v43 = 0;
  }
  *((_DWORD *)v2 + 5) = 0;
  *((_DWORD *)v2 + 4) = 0;
  *((_DWORD *)v2 + 7) = v43;
  treemap = msp->treemap;
  v46 = &msp->treebins[v43];
  if ( ((1 << v43) & treemap) == 0 )
  {
    msp->treemap = treemap | (1 << v43);
    *v46 = (malloc_tree_chunk *)v2;
    *((_DWORD *)v2 + 6) = v46;
    *((_DWORD *)v2 + 3) = v2;
    *((_DWORD *)v2 + 2) = v2;
    goto LABEL_128;
  }
  v47 = *v46;
  if ( v43 == 31 )
    v48 = 0;
  else
    v48 = 25 - (v43 >> 1);
  v49 = v3 << v48;
  if ( (v47->head & 0xFFFFFFF8) == v3 )
  {
LABEL_122:
    v51 = msp->least_addr;
    v52 = (unsigned int)v47->fd;
    if ( v47 >= (malloc_tree_chunk *)v51 && v52 >= (unsigned int)v51 )
    {
      *(_DWORD *)(v52 + 12) = v2;
      v47->fd = (malloc_tree_chunk *)v2;
      *((_DWORD *)v2 + 2) = v52;
      *((_DWORD *)v2 + 3) = v47;
      *((_DWORD *)v2 + 6) = 0;
      goto LABEL_128;
    }
LABEL_127:
    abort();
  }
  while ( 1 )
  {
    v50 = (unsigned int)&v47->child[v49 >> 31];
    v49 *= 2;
    if ( !*(_DWORD *)v50 )
      break;
    v47 = *(malloc_tree_chunk **)v50;
    if ( (*(_DWORD *)(*(_DWORD *)v50 + 4) & 0xFFFFFFF8) == v3 )
      goto LABEL_122;
  }
  if ( (char *)v50 < msp->least_addr )
    goto LABEL_127;
  *(_DWORD *)v50 = v2;
  *((_DWORD *)v2 + 6) = v47;
  *((_DWORD *)v2 + 3) = v2;
  *((_DWORD *)v2 + 2) = v2;
LABEL_128:
  v21 = msp->release_checks-- == 1;
  if ( v21 )
    release_unused_segments(msp);
}
