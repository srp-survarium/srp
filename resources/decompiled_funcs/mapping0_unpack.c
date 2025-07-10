signed int *__usercall mapping0_unpack@<eax>(
        vostok::memory::doug_lea_mt_allocator *a1@<ecx>,
        vostok::memory *a2@<edi>,
        vorbis_info *vi,
        oggpack_buffer *opb)
{
  signed int *v4; // ebx
  signed int v5; // eax
  signed int v6; // eax
  vostok::memory::doug_lea_mt_allocator *v7; // ecx
  signed int v9; // eax
  signed int v10; // eax
  signed int *v11; // ebp
  int channels; // ecx
  unsigned int v13; // eax
  unsigned int j; // ecx
  signed int v15; // esi
  int v16; // ecx
  unsigned int v17; // eax
  unsigned int k; // ecx
  signed int v19; // eax
  int v20; // ecx
  int v21; // ebp
  signed int *v22; // esi
  signed int v23; // eax
  signed int *m; // esi
  signed int v25; // eax
  signed int v26; // eax
  vostok::memory *i; // [esp+0h] [ebp-8h]
  int ia; // [esp+0h] [ebp-8h]
  int ib; // [esp+0h] [ebp-8h]
  codec_setup_info *ci; // [esp+4h] [ebp-4h]

  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(i);
  v4 = (signed int *)vostok::memory::doug_lea_mt_allocator::malloc_impl(a1, 0xC88u);
  memset((int)v4, 0, 0xC88u);
  ci = (codec_setup_info *)vi->codec_setup;
  memset((int)v4, 0, 0xC88u);
  v5 = oggpack_read(opb, 1u);
  if ( v5 < 0 )
    goto err_out_0;
  if ( v5 )
  {
    v6 = oggpack_read(opb, 4u) + 1;
    *v4 = v6;
    if ( v6 <= 0 )
      goto err_out_0;
  }
  else
  {
    *v4 = 1;
  }
  v9 = oggpack_read(opb, 1u);
  if ( v9 >= 0 )
  {
    if ( v9 )
    {
      v10 = oggpack_read(opb, 8u) + 1;
      v4[289] = v10;
      if ( v10 > 0 )
      {
        ia = 0;
        v11 = v4 + 546;
        while ( 1 )
        {
          channels = vi->channels;
          v13 = 0;
          if ( channels )
          {
            for ( j = channels - 1; j; j >>= 1 )
              ++v13;
          }
          v15 = oggpack_read(opb, v13);
          *(v11 - 256) = v15;
          v16 = vi->channels;
          v17 = 0;
          if ( v16 )
          {
            for ( k = v16 - 1; k; k >>= 1 )
              ++v17;
          }
          v19 = oggpack_read(opb, v17);
          *v11 = v19;
          if ( v15 < 0 )
            break;
          if ( v19 < 0 )
            break;
          if ( v15 == v19 )
            break;
          v20 = vi->channels;
          if ( v15 >= v20 || v19 >= v20 )
            break;
          ++v11;
          if ( ++ia >= v4[289] )
            goto LABEL_28;
        }
      }
    }
    else
    {
LABEL_28:
      if ( !oggpack_read(opb, 2u) )
      {
        if ( *v4 <= 1 || (v21 = 0, vi->channels <= 0) )
        {
LABEL_35:
          ib = 0;
          if ( *v4 <= 0 )
            return v4;
          for ( m = v4 + 273; ; ++m )
          {
            oggpack_read(opb, 8u);
            v25 = oggpack_read(opb, 8u);
            *(m - 16) = v25;
            if ( v25 >= ci->floors )
              break;
            if ( v25 < 0 )
              break;
            v26 = oggpack_read(opb, 8u);
            *m = v26;
            if ( v26 >= ci->residues || v26 < 0 )
              break;
            if ( ++ib >= *v4 )
              return v4;
          }
        }
        else
        {
          v22 = v4 + 1;
          while ( 1 )
          {
            v23 = oggpack_read(opb, 4u);
            *v22 = v23;
            if ( v23 >= *v4 || v23 < 0 )
              break;
            ++v21;
            ++v22;
            if ( v21 >= vi->channels )
              goto LABEL_35;
          }
        }
      }
    }
  }
err_out_0:
  if ( v4 )
  {
    memset((int)v4, 0, 0xC88u);
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(a2);
    vostok::memory::doug_lea_mt_allocator::free_impl(v7, v4);
  }
  return 0;
}
