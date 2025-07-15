void __usercall floor0_free_look(vostok::memory::doug_lea_mt_allocator *a1@<ecx>, vostok::memory *a2@<edi>, char *i)
{
  char **v3; // eax
  char *v4; // edi
  int v5; // eax
  char *v6; // edi
  char *v7; // edi
  vostok::memory *v8; // [esp-4h] [ebp-8h]
  vostok::memory *v9; // [esp+0h] [ebp-4h]

  if ( i )
  {
    v3 = (char **)*((_DWORD *)i + 2);
    if ( v3 )
    {
      v8 = a2;
      if ( *v3 )
      {
        v4 = *v3;
        if ( !vostok::memory::g_crt_allocator.__vftable )
          vostok::memory::initialize_crt_allocator(v8);
        vostok::memory::doug_lea_mt_allocator::free_impl(a1, (int)vostok::memory::g_crt_allocator.__vftable, v4);
      }
      v5 = *((_DWORD *)i + 2);
      if ( *(_DWORD *)(v5 + 4) )
      {
        v6 = *(char **)(v5 + 4);
        if ( !vostok::memory::g_crt_allocator.__vftable )
          vostok::memory::initialize_crt_allocator(v8);
        vostok::memory::doug_lea_mt_allocator::free_impl(a1, (int)vostok::memory::g_crt_allocator.__vftable, v6);
      }
      v7 = (char *)*((_DWORD *)i + 2);
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v8);
      vostok::memory::doug_lea_mt_allocator::free_impl(a1, (int)vostok::memory::g_crt_allocator.__vftable, v7);
    }
    *(_DWORD *)i = 0;
    *((_DWORD *)i + 1) = 0;
    *((_DWORD *)i + 2) = 0;
    *((_DWORD *)i + 3) = 0;
    *((_DWORD *)i + 4) = 0;
    *((_DWORD *)i + 5) = 0;
    *((_DWORD *)i + 6) = 0;
    *((_DWORD *)i + 7) = 0;
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(v9);
    vostok::memory::doug_lea_mt_allocator::free_impl(a1, (int)vostok::memory::g_crt_allocator.__vftable, i);
  }
}
