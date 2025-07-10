static_codebook *__usercall vorbis_staticbook_unpack@<eax>(
        oggpack_buffer *opb@<eax>,
        vostok::memory::doug_lea_mt_allocator *a2@<ecx>)
{
  static_codebook *v3; // esi
  unsigned int v4; // eax
  unsigned int dim; // ecx
  int i; // edx
  int j; // ecx
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // ebp
  int *v11; // eax
  int v12; // ebx
  bool v13; // cc
  unsigned int v14; // ecx
  unsigned int m; // eax
  signed int v16; // eax
  unsigned int v17; // ebx
  int entries; // ecx
  int k; // ebx
  unsigned int v20; // eax
  int v21; // ebx
  unsigned int v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // eax
  int v25; // ebx
  int v26; // ebp
  bool v27; // zf
  vostok::memory *v29; // [esp+0h] [ebp-14h]
  int v30; // [esp+10h] [ebp-4h]

  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(v29);
  v3 = (static_codebook *)vostok::memory::doug_lea_mt_allocator::malloc_impl(a2, 0x28u);
  v3->dim = 0;
  v3->entries = 0;
  v3->lengthlist = 0;
  v3->maptype = 0;
  v3->q_min = 0;
  v3->q_delta = 0;
  v3->q_quant = 0;
  v3->q_sequencep = 0;
  v3->quantlist = 0;
  v3->allocedp = 1;
  if ( (_UNKNOWN *)oggpack_read(opb, 0x18u) != &loc_564342 )
    goto _errout;
  v3->dim = oggpack_read(opb, 0x10u);
  v4 = oggpack_read(opb, 0x18u);
  v3->entries = v4;
  if ( v4 == -1 )
    goto _errout;
  dim = v3->dim;
  for ( i = 0; dim; dim >>= 1 )
    ++i;
  for ( j = 0; v4; v4 >>= 1 )
    ++j;
  if ( i + j > 24 )
    goto _errout;
  v8 = oggpack_read(opb, 1u);
  if ( !v8 )
  {
    v17 = oggpack_read(opb, 1u);
    entries = v3->entries;
    if ( (entries * (4 * (v17 == 0) + 1) + 7) >> 3 <= opb->storage - (opb->endbit + 7) / 8 - opb->endbyte )
    {
      v3->lengthlist = (int *)malloc(4 * entries);
      if ( v17 )
      {
        for ( k = 0; k < v3->entries; ++k )
        {
          if ( oggpack_read(opb, 1u) )
          {
            v20 = oggpack_read(opb, 5u);
            if ( v20 == -1 )
              goto _errout;
            v3->lengthlist[k] = v20 + 1;
          }
          else
          {
            v3->lengthlist[k] = 0;
          }
        }
      }
      else
      {
        v21 = 0;
        if ( v3->entries > 0 )
        {
          while ( 1 )
          {
            v22 = oggpack_read(opb, 5u);
            if ( v22 == -1 )
              goto _errout;
            v3->lengthlist[v21++] = v22 + 1;
            if ( v21 >= v3->entries )
              goto LABEL_37;
          }
        }
      }
      goto LABEL_37;
    }
_errout:
    vorbis_staticbook_destroy(v3);
    return 0;
  }
  if ( v8 != 1 )
    goto _errout;
  v9 = oggpack_read(opb, 5u);
  v10 = v9 + 1;
  if ( v9 == -1 )
    goto _errout;
  v11 = (int *)malloc(4 * v3->entries);
  v12 = 0;
  v13 = v3->entries <= 0;
  v3->lengthlist = v11;
  if ( !v13 )
  {
    v30 = v10 - 1;
    do
    {
      v14 = v3->entries - v12;
      for ( m = 0; v14; v14 >>= 1 )
        ++m;
      v16 = oggpack_read(opb, m);
      if ( v16 == -1 || v30 > 31 || v16 > v3->entries - v12 )
        goto _errout;
      if ( v16 > 0 )
      {
        if ( (v16 - 1) >> v30 > 1 )
          goto _errout;
        do
        {
          v3->lengthlist[v12++] = v10;
          --v16;
        }
        while ( v16 );
      }
      ++v30;
      ++v10;
    }
    while ( v12 < v3->entries );
  }
LABEL_37:
  v23 = oggpack_read(opb, 4u);
  v3->maptype = v23;
  if ( v23 )
  {
    if ( v23 - 1 > 1 )
      goto _errout;
    v3->q_min = oggpack_read(opb, 0x20u);
    v3->q_delta = oggpack_read(opb, 0x20u);
    v3->q_quant = oggpack_read(opb, 4u) + 1;
    v24 = oggpack_read(opb, 1u);
    v3->q_sequencep = v24;
    if ( v24 == -1 )
      goto _errout;
    v25 = 0;
    if ( v3->maptype == 1 )
    {
      v25 = v3->dim ? _book_maptype1_quantvals(v3) : 0;
    }
    else if ( v3->maptype == 2 )
    {
      v25 = v3->entries * v3->dim;
    }
    if ( (v25 * v3->q_quant + 7) >> 3 > opb->storage - (opb->endbit + 7) / 8 - opb->endbyte )
      goto _errout;
    v26 = 0;
    v3->quantlist = (int *)malloc(4 * v25);
    v27 = v25 == 0;
    if ( v25 > 0 )
    {
      do
        v3->quantlist[v26++] = oggpack_read(opb, v3->q_quant);
      while ( v26 < v25 );
      v27 = v25 == 0;
    }
    if ( !v27 && v3->quantlist[v25 - 1] == -1 )
      goto _errout;
  }
  return v3;
}
