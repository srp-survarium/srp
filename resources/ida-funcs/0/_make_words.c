unsigned int *__cdecl _make_words(int *l, int n, int sparsecount)
{
  vostok::memory::doug_lea_mt_allocator *v3; // ecx
  int v4; // ebx
  int v5; // ebp
  int v6; // esi
  unsigned int *v7; // esi
  int v8; // edi
  unsigned int *v9; // ebx
  int v10; // ecx
  unsigned int v11; // esi
  int v12; // eax
  unsigned int v13; // edx
  int i; // eax
  int v15; // eax
  vostok::memory::doug_lea_mt_allocator *v16; // ecx
  int v17; // ebx
  int *v18; // edi
  int v19; // edx
  int v20; // eax
  int v21; // ecx
  unsigned int v22; // ebp
  vostok::memory *v24; // [esp+0h] [ebp-A0h]
  char *v25; // [esp+0h] [ebp-A0h]
  volatile int *v26; // [esp+4h] [ebp-9Ch]
  vostok::memory::inplace_constructor v27; // [esp+8h] [ebp-98h]
  unsigned int *r; // [esp+14h] [ebp-8Ch]
  unsigned int marker[34]; // [esp+18h] [ebp-88h] BYREF

  v4 = sparsecount;
  v5 = n;
  v6 = sparsecount;
  if ( !sparsecount )
    v6 = n;
  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(v24);
  v7 = (unsigned int *)vostok::memory::doug_lea_mt_allocator::malloc_impl(v3, 4 * v6);
  r = v7;
  memset((int)marker, 0, 0x84u);
  v8 = 0;
  if ( n > 0 )
  {
    v9 = v7;
    while ( 1 )
    {
      v10 = l[v8];
      if ( v10 <= 0 )
      {
        if ( !sparsecount )
          ++v9;
      }
      else
      {
        v11 = marker[v10];
        if ( v10 < 32 && v11 >> v10 )
        {
          if ( !vostok::memory::g_crt_allocator.__vftable )
            vostok::memory::initialize_crt_allocator(v24);
          vostok::memory::doug_lea_mt_allocator::free_impl((vostok::memory::doug_lea_mt_allocator *)v10, r);
          return 0;
        }
        *v9++ = v11;
        v12 = v10;
        while ( 1 )
        {
          v13 = marker[v12];
          if ( (v13 & 1) != 0 )
            break;
          marker[v12--] = v13 + 1;
          if ( v12 <= 0 )
            goto LABEL_17;
        }
        if ( v12 == 1 )
          ++marker[1];
        else
          marker[v12] = 2 * marker[v12 - 1];
LABEL_17:
        for ( i = v10 + 1; i < 33; ++i )
        {
          if ( marker[i] >> 1 != v11 )
            break;
          v11 = marker[i];
          marker[i] = 2 * marker[i - 1];
        }
      }
      if ( ++v8 >= n )
      {
        v4 = sparsecount;
        v7 = r;
        break;
      }
    }
  }
  if ( v4 == 1 )
  {
LABEL_29:
    v17 = 0;
    if ( n > 0 )
    {
      v18 = (int *)v7;
      do
      {
        v19 = l[v17];
        v20 = 0;
        v21 = 0;
        if ( v19 > 0 )
        {
          do
          {
            v22 = (unsigned int)*v18 >> v21++;
            v20 = v22 & 1 | (2 * v20);
          }
          while ( v21 < v19 );
          v5 = n;
        }
        if ( !sparsecount || v19 )
          *v18++ = v20;
        ++v17;
      }
      while ( v17 < v5 );
      return r;
    }
    return v7;
  }
  else
  {
    v15 = 1;
    while ( 1 )
    {
      v16 = (vostok::memory::doug_lea_mt_allocator *)(32 - v15);
      if ( ((0xFFFFFFFF >> (32 - v15)) & marker[v15]) != 0 )
        break;
      if ( ++v15 >= 33 )
        goto LABEL_29;
    }
    if ( !vostok::memory::g_crt_allocator.__vftable )
    {
      vostok::debug::preinitialize(v24);
      if ( !vostok::core::g_log_callback )
      {
        vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
        vostok::debug::set_log_callback(vostok::core::debug_log_callback);
      }
      LOBYTE(r) = 0;
      vostok::bind_pointer_to_buffer_mt_safe<vostok::memory::doug_lea_mt_allocator,vostok::memory::inplace_constructor>(
        (vostok::memory::doug_lea_mt_allocator **)r,
        (char (*)[112])v25,
        v26,
        v27);
    }
    vostok::memory::doug_lea_mt_allocator::free_impl(v16, v7);
    return 0;
  }
}
