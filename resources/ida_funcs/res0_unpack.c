char *__cdecl res0_unpack(vorbis_info *vi, oggpack_buffer *opb)
{
  vostok::memory::doug_lea_mt_allocator *v2; // ecx
  int v3; // ebp
  char *v4; // esi
  signed int v5; // eax
  unsigned int v6; // ebx
  signed int v7; // eax
  signed int v8; // eax
  int v9; // eax
  int v10; // ebp
  int v11; // ebx
  signed int *v12; // ebp
  signed int v13; // eax
  int books; // ebx
  int v15; // ecx
  int *v16; // edx
  static_codebook *v17; // eax
  int entries; // edx
  int dim; // eax
  int v20; // ecx
  vostok::memory::doug_lea_mt_allocator *v22; // ecx
  vostok::memory *v23; // [esp+0h] [ebp-18h]
  char *v24; // [esp+0h] [ebp-18h]
  volatile int *v25; // [esp+4h] [ebp-14h]
  vostok::memory::inplace_constructor v26; // [esp+8h] [ebp-10h]
  int acc; // [esp+10h] [ebp-8h]
  codec_setup_info *ci; // [esp+14h] [ebp-4h]

  v3 = 0;
  acc = 0;
  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(v23);
  v4 = (char *)vostok::memory::doug_lea_mt_allocator::malloc_impl(v2, 0xB18u);
  memset((int)v4, 0, 0xB18u);
  ci = (codec_setup_info *)vi->codec_setup;
  *(_DWORD *)v4 = oggpack_read(opb, 0x18u);
  *((_DWORD *)v4 + 1) = oggpack_read(opb, 0x18u);
  *((_DWORD *)v4 + 2) = oggpack_read(opb, 0x18u) + 1;
  *((_DWORD *)v4 + 3) = oggpack_read(opb, 6u) + 1;
  v5 = oggpack_read(opb, 8u);
  *((_DWORD *)v4 + 5) = v5;
  if ( v5 >= 0 )
  {
    if ( *((int *)v4 + 3) <= 0 )
    {
LABEL_13:
      v10 = acc;
      v11 = 0;
      if ( acc <= 0 )
      {
LABEL_18:
        books = ci->books;
        if ( *((_DWORD *)v4 + 5) < books )
        {
          v15 = 0;
          if ( v10 <= 0 )
          {
LABEL_24:
            v17 = ci->book_param[*((_DWORD *)v4 + 5)];
            entries = v17->entries;
            dim = v17->dim;
            v20 = 1;
            if ( dim >= 1 )
            {
              while ( 1 )
              {
                v20 *= *((_DWORD *)v4 + 3);
                if ( v20 > entries )
                  break;
                if ( --dim <= 0 )
                {
                  *((_DWORD *)v4 + 4) = v20;
                  return v4;
                }
              }
            }
          }
          else
          {
            v16 = (int *)(v4 + 280);
            while ( *v16 < books && ci->book_param[*v16]->maptype )
            {
              ++v15;
              ++v16;
              if ( v15 >= v10 )
                goto LABEL_24;
            }
          }
        }
      }
      else
      {
        v12 = (signed int *)(v4 + 280);
        while ( 1 )
        {
          v13 = oggpack_read(opb, 8u);
          if ( v13 < 0 )
            break;
          *v12 = v13;
          ++v11;
          ++v12;
          if ( v11 >= acc )
          {
            v10 = acc;
            goto LABEL_18;
          }
        }
      }
    }
    else
    {
      vi = (vorbis_info *)(v4 + 24);
      while ( 1 )
      {
        v6 = oggpack_read(opb, 3u);
        v7 = oggpack_read(opb, 1u);
        if ( v7 < 0 )
          break;
        if ( v7 )
        {
          v8 = oggpack_read(opb, 5u);
          if ( v8 < 0 )
            break;
          v6 |= 8 * v8;
        }
        v9 = 0;
        for ( vi->version = v6; v6; v6 >>= 1 )
          v9 += v6 & 1;
        acc += v9;
        vi = (vorbis_info *)((char *)vi + 4);
        if ( ++v3 >= *((_DWORD *)v4 + 3) )
          goto LABEL_13;
      }
    }
  }
  memset((int)v4, 0, 0xB18u);
  if ( !vostok::memory::g_crt_allocator.__vftable )
  {
    vostok::debug::preinitialize(v23);
    if ( !vostok::core::g_log_callback )
    {
      vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
      vostok::debug::set_log_callback(vostok::core::debug_log_callback);
    }
    LOBYTE(vi) = 0;
    vostok::bind_pointer_to_buffer_mt_safe<vostok::memory::doug_lea_mt_allocator,vostok::memory::inplace_constructor>(
      (vostok::memory::doug_lea_mt_allocator **)vi,
      (char (*)[112])v24,
      v25,
      v26);
  }
  vostok::memory::doug_lea_mt_allocator::free_impl(v22, v4);
  return 0;
}
