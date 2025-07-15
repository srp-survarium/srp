void __cdecl _ve_envelope_clear(vostok::memory::doug_lea_mt_allocator **e)
{
  vostok::memory::doug_lea_mt_allocator *v1; // ecx
  envelope_lookup *v2; // ebx
  vostok::memory::doug_lea_mt_allocator *v3; // ecx
  float **v4; // esi
  int v5; // ebp
  char *v6; // edi
  char *mdct_win; // esi
  vostok::memory::doug_lea_mt_allocator *v8; // ecx
  char *filter; // esi
  vostok::memory::doug_lea_mt_allocator *v10; // ecx
  char *mark; // esi
  char *v12; // [esp+0h] [ebp-10h]
  volatile int *v13; // [esp+4h] [ebp-Ch]
  vostok::memory::inplace_constructor v14; // [esp+8h] [ebp-8h]

  v2 = (envelope_lookup *)e;
  mdct_clear((mdct_lookup *)(e + 4), v1);
  v4 = (float **)(e + 12);
  v5 = 7;
  do
  {
    v6 = (char *)*v4;
    if ( !vostok::memory::g_crt_allocator.__vftable )
    {
      vostok::debug::preinitialize();
      if ( !vostok::core::g_log_callback )
      {
        vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
        vostok::debug::set_log_callback(vostok::core::debug_log_callback);
      }
      LOBYTE(e) = 0;
      vostok::bind_pointer_to_buffer_mt_safe<vostok::memory::doug_lea_mt_allocator,vostok::memory::inplace_constructor>(
        e,
        (char (*)[112])v12,
        v13,
        v14);
    }
    vostok::memory::doug_lea_mt_allocator::free_impl(v3, (int)vostok::memory::g_crt_allocator.__vftable, v6);
    v4 += 4;
    --v5;
  }
  while ( v5 );
  mdct_win = (char *)v2->mdct_win;
  if ( !vostok::memory::g_crt_allocator.__vftable )
  {
    vostok::debug::preinitialize();
    if ( !vostok::core::g_log_callback )
    {
      vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
      vostok::debug::set_log_callback(vostok::core::debug_log_callback);
    }
    LOBYTE(e) = 0;
    vostok::bind_pointer_to_buffer_mt_safe<vostok::memory::doug_lea_mt_allocator,vostok::memory::inplace_constructor>(
      e,
      (char (*)[112])v12,
      v13,
      v14);
  }
  vostok::memory::doug_lea_mt_allocator::free_impl(v3, (int)vostok::memory::g_crt_allocator.__vftable, mdct_win);
  filter = (char *)v2->filter;
  if ( !vostok::memory::g_crt_allocator.__vftable )
  {
    vostok::debug::preinitialize();
    if ( !vostok::core::g_log_callback )
    {
      vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
      vostok::debug::set_log_callback(vostok::core::debug_log_callback);
    }
    LOBYTE(e) = 0;
    vostok::bind_pointer_to_buffer_mt_safe<vostok::memory::doug_lea_mt_allocator,vostok::memory::inplace_constructor>(
      e,
      (char (*)[112])v12,
      v13,
      v14);
  }
  vostok::memory::doug_lea_mt_allocator::free_impl(v8, (int)vostok::memory::g_crt_allocator.__vftable, filter);
  mark = (char *)v2->mark;
  if ( !vostok::memory::g_crt_allocator.__vftable )
  {
    vostok::debug::preinitialize();
    if ( !vostok::core::g_log_callback )
    {
      vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
      vostok::debug::set_log_callback(vostok::core::debug_log_callback);
    }
    LOBYTE(e) = 0;
    vostok::bind_pointer_to_buffer_mt_safe<vostok::memory::doug_lea_mt_allocator,vostok::memory::inplace_constructor>(
      e,
      (char (*)[112])v12,
      v13,
      v14);
  }
  vostok::memory::doug_lea_mt_allocator::free_impl(v10, (int)vostok::memory::g_crt_allocator.__vftable, mark);
  memset((int)v2, 0, sizeof(envelope_lookup));
}
