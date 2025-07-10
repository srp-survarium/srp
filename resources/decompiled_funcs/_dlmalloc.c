int *__usercall dlmalloc@<eax>(unsigned int bytes@<eax>)
{
  unsigned int v1; // esi
  unsigned int v2; // edi
  unsigned int v3; // eax
  unsigned int v4; // edi
  malloc_tree_chunk *v5; // esi
  malloc_tree_chunk *fd; // ecx
  malloc_chunk **v7; // eax
  int *result; // eax
  unsigned int dvsize; // ebx
  unsigned int v10; // edx
  char v11; // cl
  unsigned int v12; // edi
  malloc_tree_chunk *v13; // ebx
  malloc_chunk **v14; // eax
  int *p_fd; // ebp
  malloc_tree_chunk *v16; // edx
  unsigned int v17; // edi
  malloc_chunk *v18; // ebx
  malloc_chunk *v19; // ebp
  malloc_chunk **v20; // esi
  malloc_chunk **v21; // eax
  unsigned int v22; // eax
  malloc_chunk *dv; // ecx
  malloc_chunk *v24; // edx
  unsigned int topsize; // eax
  malloc_chunk *top; // edx
  malloc_tree_chunk **v27; // [esp+10h] [ebp-4h]

  if ( bytes > 0xF4 )
  {
    if ( bytes >= 0xFFFFFFC0 )
    {
      v1 = -1;
      goto LABEL_33;
    }
    v1 = (bytes + 11) & 0xFFFFFFF8;
    if ( !gm_.treemap )
    {
LABEL_33:
      dvsize = gm_.dvsize;
      if ( v1 > gm_.dvsize )
      {
        topsize = gm_.topsize;
        if ( v1 >= gm_.topsize )
          return sys_alloc(&gm_, v1);
        gm_.topsize -= v1;
        top = gm_.top;
        gm_.top = (malloc_chunk *)((char *)gm_.top + v1);
        gm_.top->head = (topsize - v1) | 1;
        top->head = v1 | 3;
        return (int *)&top->fd;
      }
      goto LABEL_34;
    }
    result = (int *)tmalloc_large(&gm_, v1);
LABEL_32:
    if ( result )
      return result;
    goto LABEL_33;
  }
  if ( bytes >= 0xB )
    v1 = (bytes + 11) & 0xFFFFFFF8;
  else
    v1 = 16;
  v2 = v1 >> 3;
  v3 = gm_.smallmap >> (v1 >> 3);
  if ( (v3 & 3) != 0 )
  {
    v4 = ((v3 & 1) == 0) + v2;
    v5 = gm_.treebins[2 * v4 - 64];
    fd = v5->fd;
    v7 = &gm_.smallbins[2 * v4];
    if ( v7 == (malloc_chunk **)fd )
    {
      gm_.smallmap &= ~(1 << v4);
    }
    else
    {
      if ( (char *)fd < gm_.least_addr )
        abort();
      v7[2] = (malloc_chunk *)fd;
      fd->bk = (malloc_tree_chunk *)v7;
    }
    v5->head = (8 * v4) | 3;
    *(&v5->head + 2 * v4) |= 1u;
    return (int *)&v5->fd;
  }
  dvsize = gm_.dvsize;
  if ( v1 <= gm_.dvsize )
  {
LABEL_34:
    v22 = dvsize - v1;
    dv = gm_.dv;
    if ( dvsize - v1 < 0x10 )
    {
      gm_.dvsize = 0;
      gm_.dv = 0;
      dv->head = dvsize | 3;
      *(unsigned int *)((char *)&dv->head + dvsize) |= 1u;
    }
    else
    {
      v24 = (malloc_chunk *)((char *)gm_.dv + v1);
      gm_.dvsize = dvsize - v1;
      gm_.dv = v24;
      v24->head = v22 | 1;
      *(unsigned int *)((char *)&v24->prev_foot + v22) = v22;
      dv->head = v1 | 3;
    }
    return (int *)&dv->fd;
  }
  if ( !v3 )
  {
    if ( !gm_.treemap )
      goto LABEL_33;
    result = (int *)tmalloc_small((malloc_chunk *)&gm_, (malloc_chunk *)v1);
    goto LABEL_32;
  }
  _BitScanForward(&v10, (2 * (-1 << v2)) & (v3 << v2) & -((2 * (-1 << v2)) & (v3 << v2)));
  v11 = v10;
  v12 = 8 * v10;
  v13 = gm_.treebins[2 * v10 - 64];
  v14 = &gm_.smallbins[2 * v10];
  p_fd = (int *)&v13->fd;
  v16 = v13->fd;
  v27 = &v13->fd;
  if ( v14 == (malloc_chunk **)v16 )
  {
    gm_.smallmap &= ~(1 << v11);
  }
  else
  {
    if ( (char *)v16 < gm_.least_addr )
      abort();
    v14[2] = (malloc_chunk *)v16;
    v16->bk = (malloc_tree_chunk *)v14;
  }
  v17 = v12 - v1;
  v13->head = v1 | 3;
  v18 = (malloc_chunk *)((char *)v13 + v1);
  v18->head = v17 | 1;
  *(unsigned int *)((char *)&v18->prev_foot + v17) = v17;
  if ( gm_.dvsize )
  {
    v19 = gm_.dv;
    v20 = &gm_.smallbins[2 * (gm_.dvsize >> 3)];
    if ( ((1 << (gm_.dvsize >> 3)) & gm_.smallmap) != 0 )
    {
      v21 = (malloc_chunk **)v20[2];
      if ( (char *)v21 < gm_.least_addr )
        abort();
    }
    else
    {
      gm_.smallmap |= 1 << (gm_.dvsize >> 3);
      v21 = &gm_.smallbins[2 * (gm_.dvsize >> 3)];
    }
    v20[2] = gm_.dv;
    v21[3] = v19;
    v19->fd = (malloc_chunk *)v21;
    v19->bk = (malloc_chunk *)v20;
    p_fd = (int *)v27;
  }
  result = p_fd;
  gm_.dvsize = v17;
  gm_.dv = v18;
  return result;
}
