void __cdecl _vp_psy_clear(vostok::memory::doug_lea_mt_allocator **p)
{
  vostok::memory::doug_lea_mt_allocator *v1; // ecx
  vorbis_look_psy *v2; // ebx
  float *v3; // esi
  int *v4; // esi
  int *v5; // esi
  int i; // ebp
  int j; // esi
  vostok::memory::doug_lea_mt_allocator *v8; // ecx
  void *v9; // edi
  vostok::memory::doug_lea_mt_allocator *v10; // ecx
  float **v11; // esi
  vostok::memory::doug_lea_mt_allocator *v12; // ecx
  float ***tonecurves; // esi
  int k; // esi
  float *v15; // edi
  float **noiseoffset; // esi
  vostok::memory *v17; // [esp+0h] [ebp-18h]
  char *v18; // [esp+0h] [ebp-18h]
  char *v19; // [esp+0h] [ebp-18h]
  volatile int *v20; // [esp+4h] [ebp-14h]
  vostok::memory::inplace_constructor v21; // [esp+8h] [ebp-10h]
  vostok::memory::doug_lea_mt_allocator **pointer; // [esp+14h] [ebp-4h]

  v2 = (vorbis_look_psy *)p;
  if ( p )
  {
    v3 = (float *)p[4];
    if ( v3 )
    {
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v17);
      vostok::memory::doug_lea_mt_allocator::free_impl(v1, v3);
    }
    v4 = (int *)p[5];
    if ( v4 )
    {
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v17);
      vostok::memory::doug_lea_mt_allocator::free_impl(v1, v4);
    }
    v5 = (int *)p[6];
    if ( v5 )
    {
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v17);
      vostok::memory::doug_lea_mt_allocator::free_impl(v1, v5);
    }
    if ( p[2] )
    {
      for ( i = 0; i < 17; ++i )
      {
        for ( j = 0; j < 32; j += 4 )
        {
          v8 = (vostok::memory::doug_lea_mt_allocator *)v2->tonecurves[i];
          v9 = *(vostok::memory::doug_lea_mt_allocator_vtbl **)((char *)&v8->__vftable + j);
          if ( !vostok::memory::g_crt_allocator.__vftable )
          {
            vostok::debug::preinitialize(v17);
            if ( !vostok::core::g_log_callback )
            {
              vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
              vostok::debug::set_log_callback(vostok::core::debug_log_callback);
            }
            LOBYTE(p) = 0;
            vostok::bind_pointer_to_buffer_mt_safe<vostok::memory::doug_lea_mt_allocator,vostok::memory::inplace_constructor>(
              p,
              (char (*)[112])v18,
              v20,
              v21);
          }
          vostok::memory::doug_lea_mt_allocator::free_impl(v8, v9);
        }
        v11 = v2->tonecurves[i];
        if ( !vostok::memory::g_crt_allocator.__vftable )
        {
          vostok::debug::preinitialize(v17);
          if ( !vostok::core::g_log_callback )
          {
            vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
            vostok::debug::set_log_callback(vostok::core::debug_log_callback);
          }
          LOBYTE(pointer) = 0;
          vostok::bind_pointer_to_buffer_mt_safe<vostok::memory::doug_lea_mt_allocator,vostok::memory::inplace_constructor>(
            pointer,
            (char (*)[112])v19,
            v20,
            v21);
        }
        vostok::memory::doug_lea_mt_allocator::free_impl(v10, v11);
      }
      tonecurves = v2->tonecurves;
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v17);
      vostok::memory::doug_lea_mt_allocator::free_impl(v12, tonecurves);
    }
    if ( v2->noiseoffset )
    {
      for ( k = 0; k < 3; ++k )
      {
        v15 = v2->noiseoffset[k];
        if ( !vostok::memory::g_crt_allocator.__vftable )
          vostok::memory::initialize_crt_allocator(v17);
        vostok::memory::doug_lea_mt_allocator::free_impl(v1, v15);
      }
      noiseoffset = v2->noiseoffset;
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v17);
      vostok::memory::doug_lea_mt_allocator::free_impl(v1, noiseoffset);
    }
    memset((int)v2, 0, sizeof(vorbis_look_psy));
  }
}
