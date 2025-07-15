static_codebook *__usercall vorbis_staticbook_unpack@<eax>(oggpack_buffer *opb@<eax>, __int128 a2@<xmm0>)
{
  static_codebook *v3; // edi
  unsigned int v4; // eax
  unsigned int v5; // ecx
  int v6; // eax
  int v7; // edx
  unsigned int v8; // eax
  unsigned int v9; // eax
  int *v10; // eax
  int v11; // ebx
  bool v12; // cc
  unsigned int v13; // eax
  signed int v14; // eax
  unsigned int v15; // ebx
  int entries; // ecx
  int i; // ebx
  unsigned int v18; // eax
  int j; // ebx
  unsigned int v20; // eax
  unsigned int v21; // eax
  int v22; // ebx
  unsigned int v23; // eax
  int v24; // eax
  int *v25; // eax
  bool v26; // zf
  int v28; // [esp+Ch] [ebp-8h]
  unsigned int v29; // [esp+10h] [ebp-4h]
  int v30; // [esp+10h] [ebp-4h]

  v3 = (static_codebook *)ogg_calloc_impl(1u, 0x28u);
  v3->allocedp = 1;
  if ( (_UNKNOWN *)oggpack_read(opb, 0x18u) != (_UNKNOWN *)((char *)&loc_56433F + 3) )
    goto _errout;
  v3->dim = oggpack_read(opb, 0x10u);
  v4 = oggpack_read(opb, 0x18u);
  v3->entries = v4;
  if ( v4 == -1 )
    goto _errout;
  _ilog(v3->dim);
  v6 = _ilog(v5);
  if ( v6 + v7 > 24 )
    goto _errout;
  v8 = oggpack_read(opb, 1u);
  if ( v8 )
  {
    if ( v8 != 1 )
      goto _errout;
    v9 = oggpack_read(opb, 5u);
    v29 = v9 + 1;
    if ( v9 == -1 )
      goto _errout;
    v10 = (int *)ogg_malloc_impl(4 * v3->entries);
    v11 = 0;
    v12 = v3->entries <= 0;
    v3->lengthlist = v10;
    if ( !v12 )
    {
      v28 = v29 - 1;
      do
      {
        v13 = _ilog(v3->entries - v11);
        v14 = oggpack_read(opb, v13);
        if ( v14 == -1 || v28 > 31 || v14 > v3->entries - v11 )
          goto _errout;
        if ( v14 > 0 )
        {
          if ( (v14 - 1) >> v28 > 1 )
            goto _errout;
          do
          {
            v3->lengthlist[v11++] = v29;
            --v14;
          }
          while ( v14 );
        }
        ++v29;
        ++v28;
      }
      while ( v11 < v3->entries );
    }
  }
  else
  {
    v15 = oggpack_read(opb, 1u);
    entries = v3->entries;
    if ( (entries * (4 * (v15 == 0) + 1) + 7) >> 3 > opb->storage - (opb->endbit + 7) / 8 - opb->endbyte )
      goto _errout;
    v3->lengthlist = (int *)ogg_malloc_impl(4 * entries);
    if ( v15 )
    {
      for ( i = 0; i < v3->entries; ++i )
      {
        if ( oggpack_read(opb, 1u) )
        {
          v18 = oggpack_read(opb, 5u);
          if ( v18 == -1 )
            goto _errout;
          v3->lengthlist[i] = v18 + 1;
        }
        else
        {
          v3->lengthlist[i] = 0;
        }
      }
    }
    else
    {
      for ( j = 0; j < v3->entries; v3->lengthlist[j++] = v20 + 1 )
      {
        v20 = oggpack_read(opb, 5u);
        if ( v20 == -1 )
          goto _errout;
      }
    }
  }
  v21 = oggpack_read(opb, 4u);
  v22 = 0;
  v3->maptype = v21;
  if ( !v21 )
    return v3;
  if ( v21 - 1 > 1
    || (v3->q_min = oggpack_read(opb, 0x20u),
        v3->q_delta = oggpack_read(opb, 0x20u),
        v3->q_quant = oggpack_read(opb, 4u) + 1,
        v23 = oggpack_read(opb, 1u),
        v3->q_sequencep = v23,
        v23 == -1) )
  {
_errout:
    vorbis_staticbook_destroy(v3);
    return 0;
  }
  v30 = 0;
  if ( v3->maptype == 1 )
  {
    if ( v3->dim )
    {
      v24 = _book_maptype1_quantvals(v3, 0, (int)v3, (int)opb, a2);
      goto LABEL_38;
    }
    v30 = 0;
  }
  else if ( v3->maptype == 2 )
  {
    v24 = v3->entries * v3->dim;
LABEL_38:
    v30 = v24;
  }
  if ( (v30 * v3->q_quant + 7) >> 3 > opb->storage - (opb->endbit + 7) / 8 - opb->endbyte )
    goto _errout;
  v25 = (int *)ogg_malloc_impl(4 * v30);
  v26 = v30 == 0;
  v3->quantlist = v25;
  if ( v30 > 0 )
  {
    do
      v3->quantlist[v22++] = oggpack_read(opb, v3->q_quant);
    while ( v22 < v30 );
    v26 = v30 == 0;
  }
  if ( !v26 && v3->quantlist[v30 - 1] == -1 )
    goto _errout;
  return v3;
}
