malloc_chunk **__usercall vostok_mspace_malloc@<eax>(malloc_state *msp@<eax>, unsigned int bytes)
{
  unsigned int v3; // edi
  unsigned int v4; // ebx
  unsigned int v5; // eax
  malloc_chunk **result; // eax
  char (__stdcall *out_of_memory_handler)(void *, const void *, int); // eax
  unsigned int v8; // ebx
  malloc_chunk **v9; // eax
  malloc_chunk *v10; // edi
  malloc_chunk *v11; // ecx
  unsigned int v12; // ebx
  malloc_chunk **v13; // eax
  malloc_chunk *fd; // ecx
  unsigned int v15; // ecx
  unsigned int v16; // ebx
  malloc_chunk *v17; // edi
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int dvsize; // edx
  malloc_chunk *dv; // ecx
  unsigned int v22; // eax
  char *v23; // edx
  unsigned int v24; // eax
  malloc_chunk *v25; // [esp+10h] [ebp-Ch]
  int v26; // [esp+18h] [ebp-4h]
  malloc_chunk **v27; // [esp+18h] [ebp-4h]
  malloc_chunk *v28; // [esp+24h] [ebp+8h]

  v26 = 1;
  while ( bytes > 0xF4 )
  {
    if ( bytes >= 0xFFFFFFC0 )
    {
      v3 = -1;
      goto LABEL_16;
    }
    v3 = (bytes + 11) & 0xFFFFFFF8;
    if ( msp->treemap )
    {
      result = (malloc_chunk **)tmalloc_large(msp, v3);
LABEL_15:
      if ( result )
        return result;
    }
LABEL_16:
    if ( v3 <= msp->dvsize )
    {
LABEL_41:
      dvsize = msp->dvsize;
      dv = msp->dv;
      v22 = dvsize - v3;
      if ( dvsize - v3 < 0x10 )
      {
        msp->dvsize = 0;
        msp->dv = 0;
        dv->head = dvsize | 3;
        *(unsigned int *)((char *)&dv->head + dvsize) |= 1u;
        return &dv->fd;
      }
      v23 = (char *)dv + v3;
      msp->dv = (malloc_chunk *)((char *)dv + v3);
      msp->dvsize = v22;
      *((_DWORD *)v23 + 1) = v22 | 1;
      *(_DWORD *)&v23[v22] = v22;
LABEL_43:
      dv->head = v3 | 3;
      return &dv->fd;
    }
    if ( v3 < msp->topsize )
    {
      msp->topsize -= v3;
      dv = msp->top;
      v24 = msp->topsize | 1;
      msp->top = (malloc_chunk *)((char *)dv + v3);
      *(unsigned int *)((char *)&dv->head + v3) = v24;
      goto LABEL_43;
    }
    out_of_memory_handler = msp->out_of_memory_handler;
    if ( !out_of_memory_handler )
      return (malloc_chunk **)sys_alloc(msp, v3);
    if ( !v26 )
    {
      out_of_memory_handler(msp, msp->out_of_memory_parameter, 0);
      return 0;
    }
    v26 = 0;
    if ( !out_of_memory_handler(msp, msp->out_of_memory_parameter, 1) )
      return 0;
  }
  if ( bytes >= 0xB )
    v3 = (bytes + 11) & 0xFFFFFFF8;
  else
    v3 = 16;
  v4 = v3 >> 3;
  v5 = msp->smallmap >> (v3 >> 3);
  if ( (v5 & 3) == 0 )
  {
    if ( v3 <= msp->dvsize )
      goto LABEL_41;
    if ( v5 )
    {
      _BitScanForward(&v5, (2 * (-1 << v4)) & (v5 << v4) & -((2 * (-1 << v4)) & (v5 << v4)));
      v12 = v5;
      v13 = &msp->smallbins[2 * v5];
      v28 = v13[2];
      fd = v28->fd;
      if ( v13 == (malloc_chunk **)fd )
      {
        msp->smallmap &= ~(1 << v12);
      }
      else
      {
        if ( (char *)fd < msp->least_addr )
          abort();
        v13[2] = fd;
        fd->bk = (malloc_chunk *)v13;
      }
      v15 = v3;
      v16 = 8 * v12 - v3;
      v17 = (malloc_chunk *)((char *)v28 + v3);
      v28->head = v15 | 3;
      v17->head = v16 | 1;
      *(unsigned int *)((char *)&v17->prev_foot + v16) = v16;
      v18 = msp->dvsize;
      if ( v18 )
      {
        v19 = v18 >> 3;
        v25 = msp->dv;
        v27 = &msp->smallbins[2 * v19];
        if ( (msp->smallmap & (1 << v19)) != 0 )
        {
          if ( msp->smallbins[2 * v19 + 2] < (malloc_chunk *)msp->least_addr )
            abort();
          v27 = (malloc_chunk **)msp->smallbins[2 * v19 + 2];
        }
        else
        {
          msp->smallmap |= 1 << v19;
        }
        msp->smallbins[2 * v19 + 2] = v25;
        v27[3] = v25;
        v25->fd = (malloc_chunk *)v27;
        v25->bk = (malloc_chunk *)&msp->smallbins[2 * v19];
      }
      result = &v28->fd;
      msp->dvsize = v16;
      msp->dv = v17;
      return result;
    }
    if ( msp->treemap )
    {
      result = (malloc_chunk **)tmalloc_small(msp, v3);
      goto LABEL_15;
    }
    goto LABEL_16;
  }
  v8 = ((v5 & 1) == 0) + v4;
  v9 = &msp->smallbins[2 * v8];
  v10 = msp->smallbins[2 * v8 + 2];
  v11 = v10->fd;
  if ( v9 == (malloc_chunk **)v11 )
  {
    msp->smallmap &= ~(1 << v8);
  }
  else
  {
    if ( (char *)v11 < msp->least_addr )
      abort();
    msp->smallbins[2 * v8 + 2] = v11;
    v11->bk = (malloc_chunk *)v9;
  }
  v10->head = (8 * v8) | 3;
  *(&v10->head + 2 * v8) |= 1u;
  return &v10->fd;
}
