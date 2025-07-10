int __usercall vorbis_unpack_books@<eax>(oggpack_buffer *opb@<eax>, bool a2@<bl>, _DWORD *a3@<esi>, vorbis_info *vi)
{
  _DWORD *codec_setup; // ebp
  signed int v7; // eax
  vostok::memory::doug_lea_mt_allocator *v8; // ecx
  static_codebook **v9; // ebx
  static_codebook *v10; // eax
  int v11; // ebx
  signed int v12; // eax
  int v13; // ebx
  unsigned int v14; // eax
  void *v15; // eax
  signed int v16; // eax
  int v17; // ebx
  unsigned int v18; // eax
  void *v19; // eax
  signed int v20; // eax
  int v21; // ebx
  unsigned int v22; // eax
  void *v23; // eax
  signed int v24; // eax
  vostok::memory::doug_lea_mt_allocator *v25; // ecx
  _DWORD *v26; // ebx
  _DWORD *v27; // eax
  int v28; // eax
  int v29; // eax
  vostok::debug *v30; // [esp-8h] [ebp-14h]
  bool v31; // [esp-4h] [ebp-10h]
  bool v32; // [esp+0h] [ebp-Ch]
  bool v33; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  codec_setup = vi->codec_setup;
  if ( !codec_setup )
    return -129;
  v31 = a2;
  v30 = (vostok::debug *)a3;
  v7 = oggpack_read(opb, 8u) + 1;
  codec_setup[6] = v7;
  if ( v7 > 0 )
  {
    a3 = 0;
    v9 = (static_codebook **)(codec_setup + 456);
    while ( 1 )
    {
      v10 = vorbis_staticbook_unpack(opb, v8);
      *v9 = v10;
      if ( !v10 )
        break;
      a3 = (_DWORD *)((char *)a3 + 1);
      ++v9;
      if ( (int)a3 >= codec_setup[6] )
      {
        a3 = (_DWORD *)(oggpack_read(opb, 6u) + 1);
        if ( (int)a3 > 0 )
        {
          v11 = 0;
          while ( !oggpack_read(opb, 0x10u) )
          {
            if ( ++v11 >= (int)a3 )
            {
              v12 = oggpack_read(opb, 6u) + 1;
              codec_setup[4] = v12;
              if ( v12 > 0 )
              {
                v13 = 0;
                a3 = codec_setup + 264;
                while ( 1 )
                {
                  v14 = oggpack_read(opb, 0x10u);
                  *(a3 - 64) = v14;
                  if ( v14 > 1 )
                    break;
                  v15 = _floor_P[v14]->unpack(vi, opb);
                  *a3 = v15;
                  if ( !v15 )
                    break;
                  ++v13;
                  ++a3;
                  if ( v13 >= codec_setup[4] )
                  {
                    v16 = oggpack_read(opb, 6u) + 1;
                    codec_setup[5] = v16;
                    if ( v16 > 0 )
                    {
                      v17 = 0;
                      a3 = codec_setup + 392;
                      while ( 1 )
                      {
                        v18 = oggpack_read(opb, 0x10u);
                        *(a3 - 64) = v18;
                        if ( v18 > 2 )
                          break;
                        v19 = _residue_P[v18]->unpack(vi, opb);
                        *a3 = v19;
                        if ( !v19 )
                          break;
                        ++v17;
                        ++a3;
                        if ( v17 >= codec_setup[5] )
                        {
                          v20 = oggpack_read(opb, 6u) + 1;
                          codec_setup[3] = v20;
                          if ( v20 > 0 )
                          {
                            v21 = 0;
                            a3 = codec_setup + 136;
                            while ( 1 )
                            {
                              v22 = oggpack_read(opb, 0x10u);
                              *(a3 - 64) = v22;
                              if ( v22 )
                                break;
                              v23 = _mapping_P[0]->unpack(vi, opb);
                              *a3 = v23;
                              if ( !v23 )
                                break;
                              ++v21;
                              ++a3;
                              if ( v21 >= codec_setup[3] )
                              {
                                v24 = oggpack_read(opb, 6u) + 1;
                                codec_setup[2] = v24;
                                if ( v24 > 0 )
                                {
                                  i = 0;
                                  v26 = codec_setup + 8;
                                  while ( 1 )
                                  {
                                    if ( !vostok::memory::g_crt_allocator.__vftable )
                                    {
                                      vostok::debug::preinitialize(v30);
                                      if ( !vostok::core::g_log_callback )
                                      {
                                        vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
                                        vostok::debug::set_log_callback(vostok::core::debug_log_callback);
                                      }
                                      if ( !vostok::memory::g_crt_allocator.__vftable )
                                      {
                                        v25 = &s_crt_allocator_creation;
                                        if ( _InterlockedExchange((volatile __int32 *)&s_crt_allocator_creation, 1) )
                                        {
                                          while ( !vostok::memory::g_crt_allocator.__vftable )
                                            ;
                                        }
                                        else
                                        {
                                          vostok::memory::doug_lea_mt_allocator::doug_lea_mt_allocator(
                                            &s_crt_allocator_creation,
                                            (const bool)v30,
                                            v31,
                                            v32,
                                            v33);
                                          (*(void (__thiscall **)(char *, unsigned __int8 *, unsigned __int8 *, _DWORD, const char *))(*(_DWORD *)s_crt_allocator_buffer + 4))(
                                            s_crt_allocator_buffer,
                                            vostok::memory::s_CRT_arena,
                                            &vostok::memory::s_CRT_arena[55905848],
                                            0,
                                            "CRT allocator");
                                          v25 = (vostok::memory::doug_lea_mt_allocator *)_InterlockedExchange(
                                                                                           (volatile __int32 *)&vostok::memory::g_crt_allocator,
                                                                                           (__int32)s_crt_allocator_buffer);
                                        }
                                      }
                                    }
                                    v27 = vostok::memory::doug_lea_mt_allocator::malloc_impl(v25, 0x10u);
                                    *v27 = 0;
                                    v27[1] = 0;
                                    v27[2] = 0;
                                    v27[3] = 0;
                                    *v26 = v27;
                                    LOBYTE(a3) = 1;
                                    *(_DWORD *)*v26 = oggpack_read(opb, 1u);
                                    *(_DWORD *)(*v26 + 4) = oggpack_read(opb, 0x10u);
                                    *(_DWORD *)(*v26 + 8) = oggpack_read(opb, 0x10u);
                                    *(_DWORD *)(*v26 + 12) = oggpack_read(opb, 8u);
                                    v28 = *v26;
                                    if ( *(int *)(*v26 + 4) >= 1 )
                                      break;
                                    if ( *(int *)(v28 + 8) >= 1 )
                                      break;
                                    v29 = *(_DWORD *)(v28 + 12);
                                    if ( v29 >= codec_setup[3] || v29 < 0 )
                                      break;
                                    ++v26;
                                    if ( ++i >= codec_setup[2] )
                                    {
                                      if ( oggpack_read(opb, 1u) != 1 )
                                        goto err_out_2;
                                      return 0;
                                    }
                                  }
                                }
                                goto err_out_2;
                              }
                            }
                          }
                          goto err_out_2;
                        }
                      }
                    }
                    goto err_out_2;
                  }
                }
              }
              goto err_out_2;
            }
          }
        }
        break;
      }
    }
  }
err_out_2:
  vorbis_info_clear((bool)codec_setup, (vostok::memory *)opb, (bool)a3, (vostok::memory::doug_lea_mt_allocator *)vi);
  return -133;
}
