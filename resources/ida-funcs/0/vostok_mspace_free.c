void __usercall vostok_mspace_free(char *mem@<eax>, malloc_state *msp)
{
  char *v2; // esi
  unsigned int v3; // edi
  char *v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // edi
  unsigned int v8; // eax
  unsigned int v9; // edx
  unsigned int v10; // ecx
  unsigned int head; // eax
  unsigned int topsize; // eax
  malloc_chunk **v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // edx
  unsigned int v16; // ecx
  char *v17; // ecx
  char *v18; // edx
  malloc_tree_chunk **v19; // ecx
  unsigned int v20; // ecx
  unsigned int v21; // ecx
  unsigned int dvsize; // eax
  unsigned int v23; // eax
  unsigned int v24; // ecx
  malloc_chunk *fd; // eax
  malloc_chunk *bk; // edx
  malloc_chunk **v27; // ecx
  malloc_chunk *prev_foot; // edi
  malloc_chunk *v29; // eax
  char *p_head; // eax
  char *v31; // ecx
  malloc_chunk *v32; // eax
  malloc_tree_chunk **v33; // ecx
  unsigned int v34; // ecx
  unsigned int v35; // eax
  unsigned int v36; // eax
  unsigned int v37; // ecx
  unsigned int v38; // ecx
  unsigned int v39; // eax
  unsigned int treemap; // ecx
  malloc_tree_chunk **v41; // edx
  unsigned int v42; // eax
  char *v43; // ecx
  char *least_addr; // ecx
  malloc_tree_chunk *v45; // eax
  unsigned int v47; // [esp+8h] [ebp-10h]
  malloc_chunk *v48; // [esp+8h] [ebp-10h]
  malloc_chunk **v49; // [esp+8h] [ebp-10h]
  malloc_chunk *v50; // [esp+10h] [ebp-8h]
  unsigned int v51; // [esp+14h] [ebp-4h]

  if ( !mem )
    return;
  v2 = mem - 8;
  if ( mem - 8 < msp->least_addr || (v2[4] & 2) == 0 )
    goto erroraction_0;
  v3 = *((_DWORD *)v2 + 1) & 0xFFFFFFF8;
  v4 = &v2[v3];
  v51 = v3;
  v50 = (malloc_chunk *)&v2[v3];
  if ( (*((_DWORD *)v2 + 1) & 1) != 0 )
    goto LABEL_13;
  v5 = *(_DWORD *)v2;
  if ( (*(_DWORD *)v2 & 1) != 0 )
  {
    v6 = v5 & 0xFFFFFFFE;
    v7 = v3 + v6 + 16;
    if ( !munmap(&v2[-v6], v7, (virtual_alloc_arena *)(*((_DWORD *)v2 + 1) & 0xFFFFFFF8)) )
      msp->footprint -= v7;
    return;
  }
  v2 -= v5;
  v3 += v5;
  v51 = v3;
  if ( v2 < msp->least_addr )
erroraction_0:
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
    goto LABEL_13;
  }
  v8 = v5 >> 3;
  if ( v8 < 0x20 )
  {
    v9 = *((_DWORD *)v2 + 2);
    v10 = *((_DWORD *)v2 + 3);
    if ( v9 == v10 )
    {
      msp->smallmap &= ~(1 << v8);
      goto LABEL_13;
    }
    v13 = &msp->smallbins[2 * v8];
    if ( ((malloc_chunk **)v9 == v13 || (char *)v9 >= msp->least_addr)
      && ((malloc_chunk **)v10 == v13 || (char *)v10 >= msp->least_addr) )
    {
      *(_DWORD *)(v9 + 12) = v10;
      *(_DWORD *)(v10 + 8) = v9;
      goto LABEL_13;
    }
LABEL_55:
    abort();
  }
  v14 = *((_DWORD *)v2 + 3);
  v15 = *((_DWORD *)v2 + 6);
  v47 = v15;
  if ( (char *)v14 == v2 )
  {
    v17 = v2 + 20;
    v14 = *((_DWORD *)v2 + 5);
    if ( !v14 )
    {
      v17 = v2 + 16;
      v14 = *((_DWORD *)v2 + 4);
      if ( !v14 )
        goto LABEL_37;
    }
    while ( 1 )
    {
      v18 = (char *)(v14 + 20);
      if ( !*(_DWORD *)(v14 + 20) )
      {
        v18 = (char *)(v14 + 16);
        if ( !*(_DWORD *)(v14 + 16) )
          break;
      }
      v14 = *(_DWORD *)v18;
      v17 = v18;
    }
    if ( v17 >= msp->least_addr )
    {
      *(_DWORD *)v17 = 0;
      v15 = v47;
      goto LABEL_37;
    }
LABEL_36:
    abort();
  }
  v16 = *((_DWORD *)v2 + 2);
  if ( (char *)v16 < msp->least_addr )
    goto LABEL_36;
  *(_DWORD *)(v16 + 12) = v14;
  *(_DWORD *)(v14 + 8) = v16;
LABEL_37:
  if ( !v15 )
    goto LABEL_13;
  v19 = &msp->treebins[*((_DWORD *)v2 + 7)];
  if ( v2 == (char *)*v19 )
  {
    *v19 = (malloc_tree_chunk *)v14;
    if ( !v14 )
    {
      msp->treemap &= ~(1 << *((_DWORD *)v2 + 7));
      goto LABEL_13;
    }
  }
  else
  {
    if ( (char *)v15 < msp->least_addr )
      abort();
    if ( *(char **)(v15 + 16) == v2 )
      *(_DWORD *)(v15 + 16) = v14;
    else
      *(_DWORD *)(v15 + 20) = v14;
    if ( !v14 )
      goto LABEL_13;
  }
  if ( (char *)v14 < msp->least_addr )
    goto LABEL_55;
  *(_DWORD *)(v14 + 24) = v15;
  v20 = *((_DWORD *)v2 + 4);
  if ( v20 )
  {
    if ( (char *)v20 < msp->least_addr )
      abort();
    *(_DWORD *)(v14 + 16) = v20;
    *(_DWORD *)(v20 + 24) = v14;
  }
  v21 = *((_DWORD *)v2 + 5);
  if ( v21 )
  {
    if ( (char *)v21 >= msp->least_addr )
    {
      *(_DWORD *)(v14 + 20) = v21;
      *(_DWORD *)(v21 + 24) = v14;
      goto LABEL_13;
    }
    goto LABEL_55;
  }
LABEL_13:
  if ( v2 >= (char *)v50 )
    goto erroraction_0;
  head = v50->head;
  if ( (head & 1) == 0 )
    goto erroraction_0;
  if ( (head & 2) == 0 )
  {
    if ( v50 == msp->top )
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
    if ( v50 == msp->dv )
    {
      msp->dvsize += v3;
      dvsize = msp->dvsize;
      msp->dv = (malloc_chunk *)v2;
      *((_DWORD *)v2 + 1) = dvsize | 1;
      *(_DWORD *)&v2[dvsize] = dvsize;
      return;
    }
    v23 = head & 0xFFFFFFF8;
    v24 = v23 >> 3;
    v51 = v23 + v3;
    if ( v23 >> 3 < 0x20 )
    {
      fd = v50->fd;
      bk = v50->bk;
      if ( fd == bk )
      {
        msp->smallmap &= ~(1 << v24);
        goto LABEL_99;
      }
      v27 = &msp->smallbins[2 * v24];
      if ( (fd == (malloc_chunk *)v27 || (char *)fd >= msp->least_addr)
        && (bk == (malloc_chunk *)v27 || (char *)bk >= msp->least_addr) )
      {
        fd->bk = bk;
        bk->fd = fd;
        goto LABEL_99;
      }
LABEL_98:
      abort();
    }
    prev_foot = v50->bk;
    v48 = v50[1].fd;
    if ( prev_foot != v50 )
    {
      v29 = v50->fd;
      if ( (char *)v29 >= msp->least_addr )
      {
        v29->bk = prev_foot;
        prev_foot->fd = v29;
        goto LABEL_79;
      }
LABEL_78:
      abort();
    }
    p_head = (char *)&v50[1].head;
    prev_foot = (malloc_chunk *)v50[1].head;
    if ( prev_foot || (p_head = (char *)&v50[1], (prev_foot = (malloc_chunk *)v50[1].prev_foot) != 0) )
    {
      while ( 1 )
      {
        v31 = (char *)&prev_foot[1].head;
        if ( !prev_foot[1].head )
        {
          v31 = (char *)&prev_foot[1];
          if ( !prev_foot[1].prev_foot )
            break;
        }
        prev_foot = *(malloc_chunk **)v31;
        p_head = v31;
      }
      if ( p_head < msp->least_addr )
        goto LABEL_78;
      *(_DWORD *)p_head = 0;
    }
LABEL_79:
    if ( !v48 )
      goto LABEL_99;
    v32 = v50;
    v33 = &msp->treebins[(int)v50[1].bk];
    if ( v50 == (malloc_chunk *)*v33 )
    {
      *v33 = (malloc_tree_chunk *)prev_foot;
      if ( !prev_foot )
      {
        msp->treemap &= ~(1 << (int)v50[1].bk);
        goto LABEL_99;
      }
    }
    else
    {
      if ( (char *)v48 < msp->least_addr )
        abort();
      if ( (malloc_chunk *)v48[1].prev_foot == v50 )
        v48[1].prev_foot = (unsigned int)prev_foot;
      else
        v48[1].head = (unsigned int)prev_foot;
      if ( !prev_foot )
        goto LABEL_99;
      v32 = v50;
    }
    if ( (char *)prev_foot < msp->least_addr )
      goto LABEL_98;
    prev_foot[1].fd = v48;
    v34 = v32[1].prev_foot;
    if ( v34 )
    {
      if ( (char *)v34 < msp->least_addr )
        abort();
      prev_foot[1].prev_foot = v34;
      *(_DWORD *)(v34 + 24) = prev_foot;
    }
    v35 = v32[1].head;
    if ( v35 )
    {
      if ( (char *)v35 < msp->least_addr )
        goto LABEL_98;
      prev_foot[1].head = v35;
      *(_DWORD *)(v35 + 24) = prev_foot;
    }
LABEL_99:
    v36 = v51;
    *((_DWORD *)v2 + 1) = v51 | 1;
    *(_DWORD *)&v2[v51] = v51;
    if ( v2 == (char *)msp->dv )
    {
      msp->dvsize = v51;
      return;
    }
    goto LABEL_102;
  }
  v50->head = head & 0xFFFFFFFE;
  *((_DWORD *)v2 + 1) = v3 | 1;
  v36 = v51;
  *(_DWORD *)&v2[v3] = v3;
LABEL_102:
  v37 = v36 >> 3;
  if ( v36 >> 3 < 0x20 )
  {
    v49 = &msp->smallbins[2 * v37];
    if ( ((1 << v37) & msp->smallmap) != 0 )
    {
      if ( msp->smallbins[2 * v37 + 2] < (malloc_chunk *)msp->least_addr )
        abort();
      v49 = (malloc_chunk **)msp->smallbins[2 * v37 + 2];
    }
    else
    {
      msp->smallmap |= 1 << v37;
    }
    msp->smallbins[2 * v37 + 2] = (malloc_chunk *)v2;
    v49[3] = (malloc_chunk *)v2;
    *((_DWORD *)v2 + 2) = v49;
    *((_DWORD *)v2 + 3) = &msp->smallbins[2 * v37];
    return;
  }
  v38 = v36 >> 8;
  if ( v36 >> 8 )
  {
    if ( v38 <= 0xFFFF )
    {
      _BitScanReverse(&v38, v38);
      v39 = ((v36 >> (v38 + 7)) & 1) + 2 * v38;
    }
    else
    {
      v39 = 31;
    }
  }
  else
  {
    v39 = 0;
  }
  *((_DWORD *)v2 + 5) = 0;
  *((_DWORD *)v2 + 4) = 0;
  *((_DWORD *)v2 + 7) = v39;
  treemap = msp->treemap;
  v41 = &msp->treebins[v39];
  if ( ((1 << v39) & treemap) == 0 )
  {
    msp->treemap = treemap | (1 << v39);
    *v41 = (malloc_tree_chunk *)v2;
    goto LABEL_116;
  }
  v41 = (malloc_tree_chunk **)*v41;
  v42 = v51 << (v39 != 31 ? 25 - (v39 >> 1) : 0);
  while ( 1 )
  {
    if ( ((unsigned int)v41[1] & 0xFFFFFFF8) == v51 )
    {
      least_addr = msp->least_addr;
      v45 = v41[2];
      if ( v41 >= (malloc_tree_chunk **)least_addr && v45 >= (malloc_tree_chunk *)least_addr )
      {
        v45->bk = (malloc_tree_chunk *)v2;
        v41[2] = (malloc_tree_chunk *)v2;
        *((_DWORD *)v2 + 6) = 0;
        *((_DWORD *)v2 + 2) = v45;
        *((_DWORD *)v2 + 3) = v41;
        goto LABEL_127;
      }
LABEL_126:
      abort();
    }
    v43 = (char *)&v41[(v42 >> 31) + 4];
    v42 *= 2;
    if ( !*(_DWORD *)v43 )
      break;
    v41 = *(malloc_tree_chunk ***)v43;
  }
  if ( v43 < msp->least_addr )
    goto LABEL_126;
  *(_DWORD *)v43 = v2;
LABEL_116:
  *((_DWORD *)v2 + 6) = v41;
  *((_DWORD *)v2 + 3) = v2;
  *((_DWORD *)v2 + 2) = v2;
LABEL_127:
  if ( msp->release_checks-- == 1 )
    release_unused_segments(msp);
}
