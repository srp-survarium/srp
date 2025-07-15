_DWORD *__cdecl res0_look(vorbis_dsp_state *vd, _DWORD *vr)
{
  vostok::memory::doug_lea_mt_allocator *v2; // ecx
  _DWORD *v3; // edi
  codec_setup_info *codec_setup; // ecx
  int v5; // ebx
  vostok::memory::doug_lea_mt_allocator **v6; // eax
  vostok::memory::doug_lea_mt_allocator *v7; // ecx
  unsigned int v8; // ebx
  void *v9; // ebp
  int v10; // ecx
  bool v11; // cc
  unsigned int *v12; // esi
  unsigned int v13; // eax
  int v14; // esi
  void *v15; // ebp
  _DWORD *v16; // edx
  int v17; // ecx
  int v18; // eax
  vostok::memory::doug_lea_mt_allocator *v19; // ecx
  int v20; // esi
  unsigned int v21; // esi
  void *v22; // eax
  int v23; // ebp
  int v24; // ebx
  int i; // ecx
  int v26; // esi
  vostok::memory *v28; // [esp+0h] [ebp-24h]
  char *v29; // [esp+0h] [ebp-24h]
  volatile int *v30; // [esp+4h] [ebp-20h]
  bool v31; // [esp+8h] [ebp-1Ch]
  bool v32; // [esp+Ch] [ebp-18h]
  int acc; // [esp+10h] [ebp-14h]
  _DWORD *v34; // [esp+14h] [ebp-10h]
  int maxstage; // [esp+18h] [ebp-Ch]
  int dim; // [esp+1Ch] [ebp-8h]
  codec_setup_info *ci; // [esp+20h] [ebp-4h]
  int j; // [esp+28h] [ebp+4h]
  int val; // [esp+2Ch] [ebp+8h]

  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(v28);
  v3 = vostok::memory::doug_lea_mt_allocator::malloc_impl(v2, 0x2Cu);
  memset((int)v3, 0, 0x2Cu);
  codec_setup = (codec_setup_info *)vd->vi->codec_setup;
  *v3 = vr;
  v3[1] = vr[3];
  v5 = v3[1];
  v3[3] = codec_setup->fullbooks;
  v6 = (vostok::memory::doug_lea_mt_allocator **)&codec_setup->fullbooks[vr[5]];
  v3[4] = v6;
  ci = codec_setup;
  v7 = *v6;
  acc = 0;
  maxstage = 0;
  dim = (int)*v6;
  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(v28);
  v8 = 4 * v5;
  v9 = vostok::memory::doug_lea_mt_allocator::malloc_impl(v7, v8);
  memset((int)v9, 0, v8);
  v11 = v3[1] <= 0;
  v3[5] = v9;
  j = 0;
  if ( !v11 )
  {
    v12 = vr + 6;
    v34 = vr + 6;
    do
    {
      v13 = *v12;
      v14 = 0;
      if ( v13 )
      {
        do
        {
          ++v14;
          v13 >>= 1;
        }
        while ( v13 );
        if ( v14 )
        {
          if ( v14 > maxstage )
            maxstage = v14;
          if ( !vostok::memory::g_crt_allocator.__vftable )
            vostok::memory::initialize_crt_allocator(v28);
          v15 = vostok::memory::doug_lea_mt_allocator::malloc_impl(
                  (vostok::memory::doug_lea_mt_allocator *)v10,
                  4 * v14);
          memset((int)v15, 0, 4 * v14);
          v10 = 0;
          *(_DWORD *)(v3[5] + 4 * j) = v15;
          if ( v14 > 0 )
          {
            v16 = &vr[acc + 70];
            do
            {
              if ( ((1 << v10) & *v34) != 0 )
              {
                ++acc;
                *(_DWORD *)(*(_DWORD *)(v3[5] + 4 * j) + 4 * v10) = &ci->fullbooks[*v16++];
              }
              ++v10;
            }
            while ( v10 < v14 );
          }
        }
      }
      v12 = v34 + 1;
      v11 = ++j < v3[1];
      ++v34;
    }
    while ( v11 );
  }
  v17 = dim;
  v3[6] = 1;
  if ( dim > 0 )
  {
    v18 = 1;
    do
    {
      v18 *= v3[1];
      --v17;
    }
    while ( v17 );
    v3[6] = v18;
  }
  v19 = (vostok::memory::doug_lea_mt_allocator *)maxstage;
  v20 = 2 * v3[6];
  v3[2] = maxstage;
  v21 = 2 * v20;
  if ( !vostok::memory::g_crt_allocator.__vftable )
  {
    vostok::debug::preinitialize(v28);
    if ( !vostok::core::g_log_callback )
    {
      vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
      vostok::debug::set_log_callback(vostok::core::debug_log_callback);
    }
    LOBYTE(vr) = 0;
    vostok::bind_pointer_to_buffer_mt_safe<vostok::memory::doug_lea_mt_allocator,vostok::memory::inplace_constructor>(
      (vostok::memory::doug_lea_mt_allocator **)vr,
      (char (*)[112])v29,
      v30,
      (vostok::memory::inplace_constructor)v31);
  }
  v22 = vostok::memory::doug_lea_mt_allocator::malloc_impl(v19, v21);
  v23 = 0;
  v11 = v3[6] <= 0;
  v3[7] = v22;
  if ( !v11 )
  {
    do
    {
      val = v23;
      v24 = v3[6] / v3[1];
      if ( !vostok::memory::g_crt_allocator.__vftable )
      {
        vostok::debug::preinitialize(v28);
        if ( !vostok::core::g_log_callback )
        {
          vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
          vostok::debug::set_log_callback(vostok::core::debug_log_callback);
        }
        if ( !vostok::memory::g_crt_allocator.__vftable )
        {
          if ( _InterlockedExchange((volatile __int32 *)&s_crt_allocator_creation, 1) )
          {
            while ( !vostok::memory::g_crt_allocator.__vftable )
              ;
          }
          else
          {
            vostok::memory::doug_lea_mt_allocator::doug_lea_mt_allocator(
              &s_crt_allocator_creation,
              (const bool)v28,
              (const bool)v30,
              v31,
              v32);
            (*(void (__thiscall **)(char *, unsigned __int8 *, unsigned __int8 *, _DWORD, const char *))(*(_DWORD *)s_crt_allocator_buffer + 4))(
              s_crt_allocator_buffer,
              vostok::memory::s_CRT_arena,
              &vostok::memory::s_CRT_arena[55905848],
              0,
              "CRT allocator");
            _InterlockedExchange((volatile __int32 *)&vostok::memory::g_crt_allocator, (__int32)s_crt_allocator_buffer);
          }
        }
      }
      *(_DWORD *)(v3[7] + 4 * v23) = vostok::memory::doug_lea_mt_allocator::malloc_impl(
                                       (vostok::memory::doug_lea_mt_allocator *)(4 * dim),
                                       4 * dim);
      for ( i = 0; i < dim; *(_DWORD *)(*(_DWORD *)(v3[7] + 4 * v23) + 4 * i - 4) = v26 )
      {
        ++i;
        v26 = val / v24;
        val %= v24;
        v24 /= (int)v3[1];
      }
      ++v23;
    }
    while ( v23 < v3[6] );
  }
  return v3;
}
