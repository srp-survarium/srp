int *__usercall vostok_mspace_malloc@<eax>(malloc_state *msp@<eax>, unsigned int bytes)
{
  unsigned int v4; // edi
  unsigned int v5; // ebx
  unsigned int v6; // eax
  int *result; // eax
  char (__stdcall *out_of_memory_handler)(void *, const void *, int); // eax
  unsigned int v9; // ebx
  malloc_chunk *v10; // edi
  malloc_chunk *v11; // ecx
  char *v12; // eax
  int v13; // edx
  malloc_chunk *v14; // ebp
  char *v15; // eax
  malloc_chunk *fd; // ecx
  unsigned int v17; // ebx
  int v18; // ecx
  malloc_chunk *v19; // edi
  unsigned int v20; // eax
  int v21; // edx
  malloc_chunk *v22; // ecx
  unsigned int dvsize; // edx
  malloc_chunk *v24; // ecx
  unsigned int v25; // eax
  char *v26; // edx
  malloc_chunk *top; // eax
  unsigned int topsize; // ecx
  malloc_chunk *DV; // [esp+10h] [ebp-8h]
  int F; // [esp+1Ch] [ebp+4h]

  F = 1;
  while ( bytes > 0xF4 )
  {
    if ( bytes >= 0xFFFFFFC0 )
    {
      v4 = -1;
      goto LABEL_16;
    }
    v4 = (bytes + 11) & 0xFFFFFFF8;
    if ( msp->treemap )
    {
      result = (int *)tmalloc_large(msp, (bytes + 11) & 0xFFFFFFF8);
LABEL_15:
      if ( result )
        return result;
    }
LABEL_16:
    if ( v4 <= msp->dvsize )
    {
LABEL_40:
      dvsize = msp->dvsize;
      v24 = msp->dv;
      v25 = dvsize - v4;
      if ( dvsize - v4 < 0x10 )
      {
        msp->dvsize = 0;
        msp->dv = 0;
        v24->head = dvsize | 3;
        *(unsigned int *)((char *)&v24->head + dvsize) |= 1u;
      }
      else
      {
        v26 = (char *)v24 + v4;
        msp->dvsize = v25;
        msp->dv = (malloc_chunk *)((char *)v24 + v4);
        *((_DWORD *)v26 + 1) = v25 | 1;
        *(_DWORD *)&v26[v25] = v25;
        v24->head = v4 | 3;
      }
      return (int *)&v24->fd;
    }
    if ( v4 < msp->topsize )
    {
      msp->topsize -= v4;
      top = msp->top;
      topsize = msp->topsize;
      msp->top = (malloc_chunk *)((char *)top + v4);
      *(unsigned int *)((char *)&top->head + v4) = topsize | 1;
      top->head = v4 | 3;
      return (int *)&top->fd;
    }
    out_of_memory_handler = msp->out_of_memory_handler;
    if ( !out_of_memory_handler )
      return sys_alloc(msp, v4);
    if ( !F )
    {
      out_of_memory_handler(msp, msp->out_of_memory_parameter, 0);
      return 0;
    }
    F = 0;
    if ( !out_of_memory_handler(msp, msp->out_of_memory_parameter, 1) )
      return 0;
  }
  if ( bytes >= 0xB )
    v4 = (bytes + 11) & 0xFFFFFFF8;
  else
    v4 = 16;
  v5 = v4 >> 3;
  v6 = msp->smallmap >> (v4 >> 3);
  if ( (v6 & 3) == 0 )
  {
    if ( v4 <= msp->dvsize )
      goto LABEL_40;
    if ( v6 )
    {
      _BitScanForward((unsigned int *)&v13, (2 * (-1 << v5)) & (v6 << v5) & -((2 * (-1 << v5)) & (v6 << v5)));
      v14 = msp->smallbins[2 * v13 + 2];
      v15 = (char *)&msp->smallbins[2 * v13];
      fd = v14->fd;
      if ( v15 == (char *)fd )
      {
        msp->smallmap &= ~(1 << v13);
      }
      else
      {
        if ( (char *)fd < msp->least_addr )
          abort();
        msp->smallbins[2 * v13 + 2] = fd;
        fd->bk = (malloc_chunk *)v15;
      }
      v17 = 8 * v13 - v4;
      v18 = v4 | 3;
      v19 = (malloc_chunk *)((char *)v14 + v4);
      v14->head = v18;
      v19->head = v17 | 1;
      *(unsigned int *)((char *)&v19->prev_foot + v17) = v17;
      v20 = msp->dvsize;
      if ( v20 )
      {
        DV = msp->dv;
        v21 = 1 << (v20 >> 3);
        if ( (msp->smallmap & v21) != 0 )
        {
          v22 = msp->smallbins[2 * (v20 >> 3) + 2];
          if ( (char *)v22 < msp->least_addr )
            abort();
        }
        else
        {
          msp->smallmap |= v21;
          v22 = (malloc_chunk *)&msp->smallbins[2 * (v20 >> 3)];
        }
        msp->smallbins[2 * (v20 >> 3) + 2] = DV;
        v22->bk = DV;
        DV->fd = v22;
        DV->bk = (malloc_chunk *)&msp->smallbins[2 * (v20 >> 3)];
      }
      result = (int *)&v14->fd;
      msp->dv = v19;
      msp->dvsize = v17;
      return result;
    }
    if ( msp->treemap )
    {
      result = (int *)tmalloc_small((malloc_chunk *)msp, (malloc_chunk *)v4);
      goto LABEL_15;
    }
    goto LABEL_16;
  }
  v9 = ((v6 & 1) == 0) + v5;
  v10 = msp->smallbins[2 * v9 + 2];
  v11 = v10->fd;
  v12 = (char *)&msp->smallbins[2 * v9];
  if ( v12 == (char *)v11 )
  {
    msp->smallmap &= ~(1 << v9);
  }
  else
  {
    if ( (char *)v11 < msp->least_addr )
      abort();
    msp->smallbins[2 * v9 + 2] = v11;
    v11->bk = (malloc_chunk *)v12;
  }
  v10->head = (8 * v9) | 3;
  *(&v10->head + 2 * v9) |= 1u;
  return (int *)&v10->fd;
}
