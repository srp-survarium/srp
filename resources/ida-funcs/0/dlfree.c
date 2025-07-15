void __usercall dlfree(char *mem@<eax>)
{
  char *v1; // esi
  virtual_alloc_arena *v2; // ecx
  malloc_chunk *v3; // ebx
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // edi
  unsigned int v7; // ecx
  unsigned int v8; // ecx
  unsigned int v9; // eax
  unsigned int v10; // edx
  unsigned int head; // eax
  unsigned int topsize; // ecx
  malloc_chunk **v13; // ecx
  unsigned int v14; // edi
  unsigned int v15; // eax
  char *v16; // eax
  char *v17; // ecx
  malloc_tree_chunk **v18; // ecx
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int dvsize; // ecx
  unsigned int v22; // eax
  unsigned int v23; // ecx
  malloc_chunk *fd; // eax
  malloc_chunk *bk; // ebx
  malloc_chunk **v26; // ecx
  malloc_chunk *prev_foot; // edi
  malloc_chunk *v28; // eax
  char *p_head; // eax
  char *v30; // ecx
  malloc_tree_chunk **v31; // eax
  unsigned int v32; // eax
  unsigned int v33; // ebx
  unsigned int v34; // edi
  unsigned int v35; // ecx
  malloc_chunk **v36; // edi
  malloc_chunk **v37; // ebx
  unsigned int v38; // eax
  malloc_tree_chunk **v39; // edx
  unsigned int v40; // eax
  char *v41; // ecx
  malloc_tree_chunk *v42; // eax
  unsigned int v43; // [esp+4h] [ebp-8h]
  malloc_chunk *v44; // [esp+4h] [ebp-8h]
  virtual_alloc_arena *v45; // [esp+8h] [ebp-4h]
  unsigned int v46; // [esp+8h] [ebp-4h]

  if ( !mem )
    return;
  v1 = mem - 8;
  if ( mem - 8 < gm_.least_addr || (v1[4] & 2) == 0 )
    goto erroraction;
  v2 = (virtual_alloc_arena *)(*((_DWORD *)v1 + 1) & 0xFFFFFFF8);
  v45 = v2;
  v3 = (malloc_chunk *)&v1[(_DWORD)v2];
  if ( (*((_DWORD *)v1 + 1) & 1) != 0 )
    goto LABEL_13;
  v4 = *(_DWORD *)v1;
  if ( (*(_DWORD *)v1 & 1) != 0 )
  {
    v5 = v4 & 0xFFFFFFFE;
    v6 = (unsigned int)&v2->out_of_memory_handler_parameter + v5;
    if ( !munmap(&v1[-v5], v6, v2) )
      gm_.footprint -= v6;
    return;
  }
  v1 -= v4;
  v7 = (unsigned int)v2 + v4;
  v45 = (virtual_alloc_arena *)v7;
  if ( v1 < gm_.least_addr )
erroraction:
    abort();
  if ( v1 == (char *)gm_.dv )
  {
    if ( (v3->head & 3) == 3 )
    {
      gm_.dvsize = v7;
      v3->head &= ~1u;
      *((_DWORD *)v1 + 1) = v7 | 1;
      *(_DWORD *)&v1[v7] = v7;
      return;
    }
    goto LABEL_13;
  }
  v8 = v4 >> 3;
  if ( v4 >> 3 < 0x20 )
  {
    v9 = *((_DWORD *)v1 + 2);
    v10 = *((_DWORD *)v1 + 3);
    if ( v9 == v10 )
    {
      gm_.smallmap &= ~(1 << v8);
      goto LABEL_13;
    }
    v13 = &gm_.smallbins[2 * v8];
    if ( ((malloc_chunk **)v9 == v13 || (char *)v9 >= gm_.least_addr)
      && ((malloc_chunk **)v10 == v13 || (char *)v10 >= gm_.least_addr) )
    {
      *(_DWORD *)(v9 + 12) = v10;
      *(_DWORD *)(v10 + 8) = v9;
      goto LABEL_13;
    }
LABEL_55:
    abort();
  }
  v14 = *((_DWORD *)v1 + 3);
  v43 = *((_DWORD *)v1 + 6);
  if ( (char *)v14 == v1 )
  {
    v16 = v1 + 20;
    v14 = *((_DWORD *)v1 + 5);
    if ( !v14 )
    {
      v16 = v1 + 16;
      v14 = *((_DWORD *)v1 + 4);
      if ( !v14 )
        goto LABEL_37;
    }
    while ( 1 )
    {
      v17 = (char *)(v14 + 20);
      if ( !*(_DWORD *)(v14 + 20) )
      {
        v17 = (char *)(v14 + 16);
        if ( !*(_DWORD *)(v14 + 16) )
          break;
      }
      v14 = *(_DWORD *)v17;
      v16 = v17;
    }
    if ( v16 >= gm_.least_addr )
    {
      *(_DWORD *)v16 = 0;
      goto LABEL_37;
    }
LABEL_36:
    abort();
  }
  v15 = *((_DWORD *)v1 + 2);
  if ( (char *)v15 < gm_.least_addr )
    goto LABEL_36;
  *(_DWORD *)(v15 + 12) = v14;
  *(_DWORD *)(v14 + 8) = v15;
LABEL_37:
  if ( !v43 )
    goto LABEL_13;
  v18 = &gm_.treebins[*((_DWORD *)v1 + 7)];
  if ( v1 == (char *)*v18 )
  {
    *v18 = (malloc_tree_chunk *)v14;
    if ( !v14 )
    {
      gm_.treemap &= ~(1 << *((_DWORD *)v1 + 7));
      goto LABEL_13;
    }
  }
  else
  {
    if ( (char *)v43 < gm_.least_addr )
      abort();
    if ( *(char **)(v43 + 16) == v1 )
      *(_DWORD *)(v43 + 16) = v14;
    else
      *(_DWORD *)(v43 + 20) = v14;
    if ( !v14 )
      goto LABEL_13;
  }
  if ( (char *)v14 < gm_.least_addr )
    goto LABEL_55;
  *(_DWORD *)(v14 + 24) = v43;
  v19 = *((_DWORD *)v1 + 4);
  if ( v19 )
  {
    if ( (char *)v19 < gm_.least_addr )
      abort();
    *(_DWORD *)(v14 + 16) = v19;
    *(_DWORD *)(v19 + 24) = v14;
  }
  v20 = *((_DWORD *)v1 + 5);
  if ( v20 )
  {
    if ( (char *)v20 >= gm_.least_addr )
    {
      *(_DWORD *)(v14 + 20) = v20;
      *(_DWORD *)(v20 + 24) = v14;
      goto LABEL_13;
    }
    goto LABEL_55;
  }
LABEL_13:
  if ( v1 >= (char *)v3 )
    goto erroraction;
  head = v3->head;
  if ( (head & 1) == 0 )
    goto erroraction;
  if ( (head & 2) == 0 )
  {
    if ( v3 == gm_.top )
    {
      gm_.top = (malloc_chunk *)v1;
      gm_.topsize += (unsigned int)v45;
      topsize = gm_.topsize;
      *((_DWORD *)v1 + 1) = gm_.topsize | 1;
      if ( v1 == (char *)gm_.dv )
      {
        gm_.dv = 0;
        gm_.dvsize = 0;
      }
      if ( topsize > gm_.trim_check )
        sys_trim(&gm_, 0);
      return;
    }
    if ( v3 == gm_.dv )
    {
      gm_.dv = (malloc_chunk *)v1;
      gm_.dvsize += (unsigned int)v45;
      dvsize = gm_.dvsize;
      *((_DWORD *)v1 + 1) = gm_.dvsize | 1;
      *(_DWORD *)&v1[dvsize] = dvsize;
      return;
    }
    v22 = head & 0xFFFFFFF8;
    v46 = (unsigned int)v45 + v22;
    v23 = v22 >> 3;
    if ( v22 >> 3 < 0x20 )
    {
      fd = v3->fd;
      bk = v3->bk;
      if ( fd == bk )
      {
        gm_.smallmap &= ~(1 << v23);
        goto LABEL_98;
      }
      v26 = &gm_.smallbins[2 * v23];
      if ( (fd == (malloc_chunk *)v26 || (char *)fd >= gm_.least_addr)
        && (bk == (malloc_chunk *)v26 || (char *)bk >= gm_.least_addr) )
      {
        fd->bk = bk;
        bk->fd = fd;
        goto LABEL_98;
      }
LABEL_97:
      abort();
    }
    prev_foot = v3->bk;
    v44 = v3[1].fd;
    if ( prev_foot != v3 )
    {
      v28 = v3->fd;
      if ( (char *)v28 >= gm_.least_addr )
      {
        v28->bk = prev_foot;
        prev_foot->fd = v28;
        goto LABEL_79;
      }
LABEL_78:
      abort();
    }
    p_head = (char *)&v3[1].head;
    prev_foot = (malloc_chunk *)v3[1].head;
    if ( prev_foot || (p_head = (char *)&v3[1], (prev_foot = (malloc_chunk *)v3[1].prev_foot) != 0) )
    {
      while ( 1 )
      {
        v30 = (char *)&prev_foot[1].head;
        if ( !prev_foot[1].head )
        {
          v30 = (char *)&prev_foot[1];
          if ( !prev_foot[1].prev_foot )
            break;
        }
        prev_foot = *(malloc_chunk **)v30;
        p_head = v30;
      }
      if ( p_head < gm_.least_addr )
        goto LABEL_78;
      *(_DWORD *)p_head = 0;
    }
LABEL_79:
    if ( !v44 )
      goto LABEL_98;
    v31 = &gm_.treebins[(int)v3[1].bk];
    if ( v3 == (malloc_chunk *)*v31 )
    {
      *v31 = (malloc_tree_chunk *)prev_foot;
      if ( !prev_foot )
      {
        gm_.treemap &= ~(1 << (int)v3[1].bk);
        goto LABEL_98;
      }
    }
    else
    {
      if ( (char *)v44 < gm_.least_addr )
        abort();
      if ( (malloc_chunk *)v44[1].prev_foot == v3 )
        v44[1].prev_foot = (unsigned int)prev_foot;
      else
        v44[1].head = (unsigned int)prev_foot;
      if ( !prev_foot )
        goto LABEL_98;
    }
    if ( (char *)prev_foot < gm_.least_addr )
      goto LABEL_97;
    prev_foot[1].fd = v44;
    v32 = v3[1].prev_foot;
    if ( v32 )
    {
      if ( (char *)v32 < gm_.least_addr )
        abort();
      prev_foot[1].prev_foot = v32;
      *(_DWORD *)(v32 + 24) = prev_foot;
    }
    v33 = v3[1].head;
    if ( v33 )
    {
      if ( (char *)v33 < gm_.least_addr )
        goto LABEL_97;
      prev_foot[1].head = v33;
      *(_DWORD *)(v33 + 24) = prev_foot;
    }
LABEL_98:
    v34 = v46;
    *((_DWORD *)v1 + 1) = v46 | 1;
    *(_DWORD *)&v1[v46] = v46;
    if ( v1 == (char *)gm_.dv )
    {
      gm_.dvsize = v46;
      return;
    }
    goto LABEL_101;
  }
  v3->head = head & 0xFFFFFFFE;
  *((_DWORD *)v1 + 1) = (unsigned int)v45 | 1;
  *(_DWORD *)&v1[(_DWORD)v45] = v45;
  v34 = (unsigned int)v45;
LABEL_101:
  v35 = v34 >> 3;
  if ( v34 >> 3 < 0x20 )
  {
    v36 = &gm_.smallbins[2 * v35];
    v37 = v36;
    if ( ((1 << v35) & gm_.smallmap) != 0 )
    {
      if ( (char *)v36[2] < gm_.least_addr )
        abort();
      v37 = (malloc_chunk **)v36[2];
    }
    else
    {
      gm_.smallmap |= 1 << v35;
    }
    v36[2] = (malloc_chunk *)v1;
    v37[3] = (malloc_chunk *)v1;
    *((_DWORD *)v1 + 2) = v37;
    *((_DWORD *)v1 + 3) = v36;
    return;
  }
  v38 = v34 >> 8;
  if ( v34 >> 8 )
  {
    if ( v38 <= 0xFFFF )
    {
      _BitScanReverse(&v38, v38);
      v38 = ((v34 >> (v38 + 7)) & 1) + 2 * v38;
    }
    else
    {
      v38 = 31;
    }
  }
  *((_DWORD *)v1 + 5) = 0;
  *((_DWORD *)v1 + 4) = 0;
  *((_DWORD *)v1 + 7) = v38;
  v39 = &gm_.treebins[v38];
  if ( ((1 << v38) & gm_.treemap) == 0 )
  {
    gm_.treemap |= 1 << v38;
    *v39 = (malloc_tree_chunk *)v1;
    goto LABEL_114;
  }
  v39 = (malloc_tree_chunk **)*v39;
  v40 = v34 << (v38 != 31 ? 25 - (v38 >> 1) : 0);
  while ( 1 )
  {
    if ( ((unsigned int)v39[1] & 0xFFFFFFF8) == v34 )
    {
      v42 = v39[2];
      if ( (char *)v39 >= gm_.least_addr && (char *)v42 >= gm_.least_addr )
      {
        v42->bk = (malloc_tree_chunk *)v1;
        v39[2] = (malloc_tree_chunk *)v1;
        *((_DWORD *)v1 + 6) = 0;
        *((_DWORD *)v1 + 2) = v42;
        *((_DWORD *)v1 + 3) = v39;
        goto LABEL_125;
      }
LABEL_124:
      abort();
    }
    v41 = (char *)&v39[(v40 >> 31) + 4];
    v40 *= 2;
    if ( !*(_DWORD *)v41 )
      break;
    v39 = *(malloc_tree_chunk ***)v41;
  }
  if ( v41 < gm_.least_addr )
    goto LABEL_124;
  *(_DWORD *)v41 = v1;
LABEL_114:
  *((_DWORD *)v1 + 6) = v39;
  *((_DWORD *)v1 + 3) = v1;
  *((_DWORD *)v1 + 2) = v1;
LABEL_125:
  if ( !--gm_.release_checks )
    release_unused_segments(&gm_);
}
