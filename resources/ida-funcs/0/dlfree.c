void __usercall dlfree(char *mem@<eax>, virtual_alloc_arena *a2@<edi>)
{
  char *v2; // ebx
  unsigned int v3; // esi
  char *v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // esi
  char *v8; // edi
  unsigned int v9; // esi
  unsigned int v10; // eax
  unsigned int v11; // edx
  unsigned int v12; // edi
  unsigned int head; // eax
  unsigned int topsize; // ecx
  malloc_chunk **v15; // eax
  malloc_tree_chunk *v16; // esi
  unsigned int v17; // ebp
  unsigned int v18; // eax
  char *v19; // ecx
  char *child; // eax
  int v21; // eax
  bool v22; // zf
  malloc_tree_chunk **v23; // eax
  unsigned int v24; // eax
  malloc_tree_chunk *v25; // edi
  unsigned int dvsize; // ecx
  unsigned int v27; // eax
  unsigned int v28; // ecx
  malloc_chunk *fd; // eax
  malloc_chunk *bk; // edx
  malloc_chunk **v31; // ecx
  malloc_chunk *prev_foot; // esi
  malloc_chunk *v33; // edi
  malloc_chunk *v34; // eax
  char *p_head; // ecx
  char *v36; // eax
  malloc_chunk *v37; // ecx
  malloc_chunk *v38; // eax
  malloc_tree_chunk **v39; // eax
  unsigned int v40; // eax
  unsigned int v41; // eax
  unsigned int v42; // edi
  unsigned int v43; // ecx
  malloc_chunk **v44; // esi
  malloc_chunk *v45; // eax
  unsigned int v46; // eax
  unsigned int v47; // ecx
  malloc_tree_chunk **v48; // edx
  malloc_tree_chunk *v49; // eax
  char v50; // si
  unsigned int v51; // edx
  char *v52; // esi
  malloc_tree_chunk *v53; // ecx
  unsigned int psize; // [esp+0h] [ebp-8h]
  unsigned int psizea; // [esp+0h] [ebp-8h]
  malloc_chunk *K; // [esp+4h] [ebp-4h]

  if ( !mem )
    return;
  v2 = mem - 8;
  if ( mem - 8 < gm_.least_addr || (v2[4] & 2) == 0 )
    goto erroraction_0;
  v3 = *((_DWORD *)v2 + 1) & 0xFFFFFFF8;
  v4 = &v2[v3];
  psize = v3;
  K = (malloc_chunk *)&v2[v3];
  if ( (*((_DWORD *)v2 + 1) & 1) != 0 )
    goto LABEL_14;
  v5 = *(_DWORD *)v2;
  if ( (*(_DWORD *)v2 & 1) != 0 )
  {
    v6 = v5 & 0xFFFFFFFE;
    v7 = v3 + v6 + 16;
    if ( !munmap(a2, &v2[-v6], v7) )
      gm_.footprint -= v7;
    return;
  }
  v8 = &v2[-v5];
  v9 = v5 + v3;
  psize = v9;
  v2 = v8;
  if ( v8 < gm_.least_addr )
erroraction_0:
    abort();
  if ( v8 == (char *)gm_.dv )
  {
    if ( (v4[4] & 3) == 3 )
    {
      gm_.dvsize = v9;
      *((_DWORD *)v4 + 1) &= ~1u;
      *((_DWORD *)v8 + 1) = v9 | 1;
      *(_DWORD *)&v8[v9] = v9;
      return;
    }
    goto LABEL_14;
  }
  v10 = v5 >> 3;
  if ( v10 < 0x20 )
  {
    v11 = *((_DWORD *)v8 + 2);
    v12 = *((_DWORD *)v8 + 3);
    if ( v11 == v12 )
    {
      gm_.smallmap &= ~(1 << v10);
      goto LABEL_14;
    }
    v15 = &gm_.smallbins[2 * v10];
    if ( ((malloc_chunk **)v11 == v15 || (char *)v11 >= gm_.least_addr)
      && ((malloc_chunk **)v12 == v15 || (char *)v12 >= gm_.least_addr) )
    {
      *(_DWORD *)(v11 + 12) = v12;
      *(_DWORD *)(v12 + 8) = v11;
      goto LABEL_14;
    }
LABEL_26:
    abort();
  }
  v16 = (malloc_tree_chunk *)*((_DWORD *)v8 + 3);
  v17 = *((_DWORD *)v8 + 6);
  if ( v16 == (malloc_tree_chunk *)v8 )
  {
    v16 = (malloc_tree_chunk *)*((_DWORD *)v8 + 5);
    v19 = v8 + 20;
    if ( !v16 )
    {
      v16 = (malloc_tree_chunk *)*((_DWORD *)v8 + 4);
      v19 = v8 + 16;
      if ( !v16 )
        goto LABEL_39;
    }
    while ( 1 )
    {
      child = (char *)&v16->child[1];
      if ( !v16->child[1] )
      {
        child = (char *)v16->child;
        if ( !v16->child[0] )
          break;
      }
      v16 = *(malloc_tree_chunk **)child;
      v19 = child;
    }
    if ( v19 >= gm_.least_addr )
    {
      *(_DWORD *)v19 = 0;
      goto LABEL_39;
    }
LABEL_38:
    abort();
  }
  v18 = *((_DWORD *)v8 + 2);
  if ( (char *)v18 < gm_.least_addr )
    goto LABEL_38;
  *(_DWORD *)(v18 + 12) = v16;
  v16->fd = (malloc_tree_chunk *)v18;
LABEL_39:
  if ( !v17 )
    goto LABEL_14;
  v21 = *((_DWORD *)v8 + 7);
  v22 = v8 == (char *)gm_.treebins[v21];
  v23 = &gm_.treebins[v21];
  if ( v22 )
  {
    *v23 = v16;
    if ( !v16 )
    {
      gm_.treemap &= ~(1 << *((_DWORD *)v8 + 7));
      goto LABEL_14;
    }
  }
  else
  {
    if ( (char *)v17 < gm_.least_addr )
      abort();
    if ( *(char **)(v17 + 16) == v8 )
      *(_DWORD *)(v17 + 16) = v16;
    else
      *(_DWORD *)(v17 + 20) = v16;
    if ( !v16 )
      goto LABEL_14;
  }
  if ( (char *)v16 < gm_.least_addr )
    goto LABEL_26;
  v16->parent = (malloc_tree_chunk *)v17;
  v24 = *((_DWORD *)v8 + 4);
  if ( v24 )
  {
    if ( (char *)v24 < gm_.least_addr )
      abort();
    v16->child[0] = (malloc_tree_chunk *)v24;
    *(_DWORD *)(v24 + 24) = v16;
  }
  v25 = (malloc_tree_chunk *)*((_DWORD *)v8 + 5);
  if ( v25 )
  {
    if ( (char *)v25 >= gm_.least_addr )
    {
      v16->child[1] = v25;
      v25->parent = v16;
      goto LABEL_14;
    }
    goto LABEL_26;
  }
LABEL_14:
  if ( v2 >= (char *)K )
    goto erroraction_0;
  head = K->head;
  if ( (head & 1) == 0 )
    goto erroraction_0;
  if ( (head & 2) != 0 )
  {
    K->head = head & 0xFFFFFFFE;
    *((_DWORD *)v2 + 1) = psize | 1;
    *(_DWORD *)&v2[psize] = psize;
    v42 = psize;
    goto LABEL_103;
  }
  if ( K == gm_.top )
  {
    gm_.top = (malloc_chunk *)v2;
    gm_.topsize += psize;
    topsize = gm_.topsize;
    *((_DWORD *)v2 + 1) = gm_.topsize | 1;
    if ( v2 == (char *)gm_.dv )
    {
      gm_.dv = 0;
      gm_.dvsize = 0;
    }
    if ( topsize > gm_.trim_check )
      sys_trim(&gm_, 0);
    return;
  }
  if ( K == gm_.dv )
  {
    gm_.dvsize += psize;
    dvsize = gm_.dvsize;
    gm_.dv = (malloc_chunk *)v2;
    *((_DWORD *)v2 + 1) = gm_.dvsize | 1;
    *(_DWORD *)&v2[dvsize] = dvsize;
    return;
  }
  v27 = head & 0xFFFFFFF8;
  psizea = v27 + psize;
  v28 = v27 >> 3;
  if ( v27 >> 3 < 0x20 )
  {
    fd = K->fd;
    bk = K->bk;
    if ( fd == bk )
    {
      gm_.smallmap &= ~(1 << v28);
      goto LABEL_100;
    }
    v31 = &gm_.smallbins[2 * v28];
    if ( (fd == (malloc_chunk *)v31 || (char *)fd >= gm_.least_addr)
      && (bk == (malloc_chunk *)v31 || (char *)bk >= gm_.least_addr) )
    {
      fd->bk = bk;
      bk->fd = fd;
      goto LABEL_100;
    }
LABEL_99:
    abort();
  }
  prev_foot = K->bk;
  v33 = K[1].fd;
  if ( prev_foot != K )
  {
    v34 = K->fd;
    if ( (char *)v34 >= gm_.least_addr )
    {
      v34->bk = prev_foot;
      prev_foot->fd = v34;
      goto LABEL_80;
    }
LABEL_79:
    abort();
  }
  prev_foot = (malloc_chunk *)K[1].head;
  p_head = (char *)&K[1].head;
  if ( prev_foot || (prev_foot = (malloc_chunk *)K[1].prev_foot, p_head = (char *)&K[1], prev_foot) )
  {
    while ( 1 )
    {
      v36 = (char *)&prev_foot[1].head;
      if ( !prev_foot[1].head )
      {
        v36 = (char *)&prev_foot[1];
        if ( !prev_foot[1].prev_foot )
          break;
      }
      prev_foot = *(malloc_chunk **)v36;
      p_head = v36;
    }
    if ( p_head < gm_.least_addr )
      goto LABEL_79;
    *(_DWORD *)p_head = 0;
  }
LABEL_80:
  if ( !v33 )
    goto LABEL_100;
  v37 = K;
  v38 = K[1].bk;
  v22 = K == (malloc_chunk *)gm_.treebins[(_DWORD)v38];
  v39 = &gm_.treebins[(_DWORD)v38];
  if ( v22 )
  {
    *v39 = (malloc_tree_chunk *)prev_foot;
    if ( !prev_foot )
    {
      gm_.treemap &= ~(1 << (int)K[1].bk);
      goto LABEL_100;
    }
  }
  else
  {
    if ( (char *)v33 < gm_.least_addr )
      abort();
    if ( (malloc_chunk *)v33[1].prev_foot == K )
      v33[1].prev_foot = (unsigned int)prev_foot;
    else
      v33[1].head = (unsigned int)prev_foot;
    if ( !prev_foot )
      goto LABEL_100;
    v37 = K;
  }
  if ( (char *)prev_foot < gm_.least_addr )
    goto LABEL_99;
  prev_foot[1].fd = v33;
  v40 = v37[1].prev_foot;
  if ( v40 )
  {
    if ( (char *)v40 < gm_.least_addr )
      abort();
    prev_foot[1].prev_foot = v40;
    *(_DWORD *)(v40 + 24) = prev_foot;
  }
  v41 = v37[1].head;
  if ( v41 )
  {
    if ( (char *)v41 < gm_.least_addr )
      goto LABEL_99;
    prev_foot[1].head = v41;
    *(_DWORD *)(v41 + 24) = prev_foot;
  }
LABEL_100:
  v42 = psizea;
  *((_DWORD *)v2 + 1) = psizea | 1;
  *(_DWORD *)&v2[psizea] = psizea;
  if ( v2 == (char *)gm_.dv )
  {
    gm_.dvsize = psizea;
    return;
  }
LABEL_103:
  v43 = v42 >> 3;
  if ( v42 >> 3 < 0x20 )
  {
    v44 = &gm_.smallbins[2 * v43];
    if ( ((1 << v43) & gm_.smallmap) != 0 )
    {
      v45 = v44[2];
      if ( (char *)v45 < gm_.least_addr )
        abort();
      v44[2] = (malloc_chunk *)v2;
      v45->bk = (malloc_chunk *)v2;
      *((_DWORD *)v2 + 2) = v45;
      *((_DWORD *)v2 + 3) = v44;
    }
    else
    {
      gm_.smallmap |= 1 << v43;
      v44[2] = (malloc_chunk *)v2;
      v44[3] = (malloc_chunk *)v2;
      *((_DWORD *)v2 + 2) = v44;
      *((_DWORD *)v2 + 3) = v44;
    }
    return;
  }
  v46 = v42 >> 8;
  if ( v42 >> 8 )
  {
    if ( v46 <= 0xFFFF )
    {
      _BitScanReverse(&v46, v46);
      v47 = ((v42 >> (v46 + 7)) & 1) + 2 * v46;
    }
    else
    {
      v47 = 31;
    }
  }
  else
  {
    v47 = 0;
  }
  *((_DWORD *)v2 + 7) = v47;
  *((_DWORD *)v2 + 5) = 0;
  *((_DWORD *)v2 + 4) = 0;
  v48 = &gm_.treebins[v47];
  if ( ((1 << v47) & gm_.treemap) == 0 )
  {
    gm_.treemap |= 1 << v47;
    *v48 = (malloc_tree_chunk *)v2;
    *((_DWORD *)v2 + 6) = v48;
    *((_DWORD *)v2 + 3) = v2;
    *((_DWORD *)v2 + 2) = v2;
    goto LABEL_128;
  }
  v49 = *v48;
  if ( v47 == 31 )
    v50 = 0;
  else
    v50 = 25 - (v47 >> 1);
  v51 = v42 << v50;
  if ( (v49->head & 0xFFFFFFF8) == v42 )
  {
LABEL_122:
    v53 = v49->fd;
    if ( (char *)v49 >= gm_.least_addr && (char *)v53 >= gm_.least_addr )
    {
      v53->bk = (malloc_tree_chunk *)v2;
      v49->fd = (malloc_tree_chunk *)v2;
      *((_DWORD *)v2 + 2) = v53;
      *((_DWORD *)v2 + 3) = v49;
      *((_DWORD *)v2 + 6) = 0;
      goto LABEL_128;
    }
LABEL_127:
    abort();
  }
  while ( 1 )
  {
    v52 = (char *)&v49->child[v51 >> 31];
    v51 *= 2;
    if ( !*(_DWORD *)v52 )
      break;
    v49 = *(malloc_tree_chunk **)v52;
    if ( (*(_DWORD *)(*(_DWORD *)v52 + 4) & 0xFFFFFFF8) == v42 )
      goto LABEL_122;
  }
  if ( v52 < gm_.least_addr )
    goto LABEL_127;
  *(_DWORD *)v52 = v2;
  *((_DWORD *)v2 + 6) = v49;
  *((_DWORD *)v2 + 3) = v2;
  *((_DWORD *)v2 + 2) = v2;
LABEL_128:
  if ( !--gm_.release_checks )
    release_unused_segments(&gm_);
}
