malloc_chunk **__usercall dlmalloc@<eax>(unsigned int bytes@<eax>)
{
  unsigned int v1; // edi
  unsigned int v2; // esi
  unsigned int v3; // eax
  unsigned int v4; // esi
  malloc_chunk **v5; // eax
  malloc_chunk *v6; // edi
  malloc_chunk *fd; // ecx
  malloc_chunk **result; // eax
  unsigned int dvsize; // ecx
  char v10; // cl
  int v11; // esi
  malloc_chunk **v12; // eax
  malloc_chunk *v13; // ebx
  malloc_chunk *v14; // edx
  unsigned int v15; // esi
  malloc_chunk *v16; // edi
  malloc_chunk *dv; // ebx
  int v18; // eax
  malloc_chunk **v19; // edx
  unsigned int v20; // ecx
  malloc_chunk *top; // edx
  malloc_chunk *v22; // eax
  unsigned int v23; // eax
  unsigned int topsize; // eax
  char *p_fd; // [esp+Ch] [ebp-Ch]
  malloc_chunk *v26; // [esp+14h] [ebp-4h]

  if ( bytes > 0xF4 )
  {
    if ( bytes >= 0xFFFFFFC0 )
    {
      v1 = -1;
      goto LABEL_34;
    }
    v1 = (bytes + 11) & 0xFFFFFFF8;
    if ( !gm_.treemap )
    {
LABEL_34:
      dvsize = gm_.dvsize;
      if ( v1 > gm_.dvsize )
      {
        topsize = gm_.topsize;
        if ( v1 >= gm_.topsize )
          return (malloc_chunk **)sys_alloc(&gm_, v1);
        gm_.topsize -= v1;
        top = gm_.top;
        gm_.top = (malloc_chunk *)((char *)gm_.top + v1);
        gm_.top->head = (topsize - v1) | 1;
        goto LABEL_37;
      }
LABEL_35:
      v20 = dvsize - v1;
      top = gm_.dv;
      if ( v20 < 0x10 )
      {
        v23 = gm_.dvsize;
        gm_.dvsize = 0;
        gm_.dv = 0;
        top->head = v23 | 3;
        *(unsigned int *)((char *)&top->head + v23) |= 1u;
        return &top->fd;
      }
      v22 = (malloc_chunk *)((char *)gm_.dv + v1);
      gm_.dv = v22;
      gm_.dvsize = v20;
      v22->head = v20 | 1;
      *(unsigned int *)((char *)&v22->prev_foot + v20) = v20;
LABEL_37:
      top->head = v1 | 3;
      return &top->fd;
    }
    result = (malloc_chunk **)tmalloc_large(&gm_, v1);
LABEL_33:
    if ( result )
      return result;
    goto LABEL_34;
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
    v5 = &gm_.smallbins[2 * v4];
    v6 = v5[2];
    fd = v6->fd;
    if ( v5 == (malloc_chunk **)fd )
    {
      gm_.smallmap &= ~(1 << v4);
    }
    else
    {
      if ( (char *)fd < gm_.least_addr )
        abort();
      v5[2] = fd;
      fd->bk = (malloc_chunk *)v5;
    }
    v6->head = (8 * v4) | 3;
    *(&v6->head + 2 * v4) |= 1u;
    return &v6->fd;
  }
  dvsize = gm_.dvsize;
  if ( v1 <= gm_.dvsize )
    goto LABEL_35;
  if ( !v3 )
  {
    if ( !gm_.treemap )
      goto LABEL_34;
    result = (malloc_chunk **)tmalloc_small(&gm_, v1);
    goto LABEL_33;
  }
  _BitScanForward(&v3, (2 * (-1 << v2)) & (v3 << v2) & -((2 * (-1 << v2)) & (v3 << v2)));
  v10 = v3;
  v11 = 8 * v3;
  v12 = &gm_.smallbins[2 * v3];
  v13 = v12[2];
  p_fd = (char *)&v13->fd;
  v14 = v13->fd;
  if ( v12 == (malloc_chunk **)v14 )
  {
    gm_.smallmap &= ~(1 << v10);
  }
  else
  {
    if ( (char *)v14 < gm_.least_addr )
      abort();
    v12[2] = v14;
    v14->bk = (malloc_chunk *)v12;
  }
  v15 = v11 - v1;
  v13->head = v1 | 3;
  v16 = (malloc_chunk *)((char *)v13 + v1);
  v16->head = v15 | 1;
  *(unsigned int *)((char *)&v16->prev_foot + v15) = v15;
  if ( gm_.dvsize )
  {
    dv = gm_.dv;
    v18 = 1 << (gm_.dvsize >> 3);
    v19 = &gm_.smallbins[2 * (gm_.dvsize >> 3)];
    v26 = (malloc_chunk *)v19;
    if ( (v18 & gm_.smallmap) != 0 )
    {
      if ( (char *)v19[2] < gm_.least_addr )
        abort();
      v26 = v19[2];
    }
    else
    {
      gm_.smallmap |= v18;
    }
    v19[2] = gm_.dv;
    v26->bk = dv;
    dv->fd = v26;
    dv->bk = (malloc_chunk *)v19;
  }
  result = (malloc_chunk **)p_fd;
  gm_.dvsize = v15;
  gm_.dv = v16;
  return result;
}
