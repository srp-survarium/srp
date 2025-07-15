char *__userpurge vostok::memory::doug_lea_allocator::malloc_impl@<eax>(
        vostok::memory::doug_lea_allocator *this@<ecx>,
        int a2@<esi>,
        unsigned int size,
        char *description,
        const char *const function,
        const char *const file,
        const unsigned int line)
{
  char *v8; // edi
  vostok::memory::base_allocator *v9; // ecx
  bool v10; // zf
  const char *v11; // eax
  vostok::memory::base_allocator *v12; // [esp-4h] [ebp-14h]
  bool do_debug_break; // [esp+Fh] [ebp-1h] BYREF

  if ( *(_BYTE *)(a2 + 42) )
    return 0;
  v8 = vostok_mspace_malloc(*(malloc_state **)(a2 + 20), size);
  v9 = v12;
  v10 = v8 == 0;
  if ( !v8 )
  {
    if ( !*(_BYTE *)(a2 + 41) && !debug_macro_helper_ignore_always_18 )
    {
      v11 = *(const char **)(a2 + 12);
      do_debug_break = 0;
      if ( !v11 )
        v11 = uri;
      vostok::debug::on_error(
        &do_debug_break,
        process_error_true,
        0,
        "assertion_failed",
        "fatal error",
        ".\\memory_doug_lea_allocator.cpp",
        "vostok::memory::doug_lea_allocator::malloc_impl",
        (const char *)0x90,
        "out of memory in arena %s",
        v11);
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
    v10 = 1;
  }
  *(_BYTE *)(a2 + 42) = *(_BYTE *)(a2 + 41) & v10;
  if ( !*(_BYTE *)(a2 + 43) )
    return v8;
  if ( !v8 )
    return 0;
  return (char *)vostok::memory::base_allocator::on_malloc(v9, v8, size, 0, description);
}
