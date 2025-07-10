int __usercall vorbis_book_init_decode@<eax>(codebook *c@<eax>, const static_codebook *s)
{
  int v2; // ebx
  int entries; // eax
  int *lengthlist; // ecx
  int v6; // edx
  vostok::memory::doug_lea_mt_allocator *v7; // ecx
  unsigned int *words; // esi
  void *v9; // esp
  unsigned int *v11; // edx
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int *v16; // esi
  void *v17; // esp
  int v18; // eax
  int v19; // ecx
  int *v20; // eax
  int v21; // esi
  int v22; // ecx
  unsigned int v23; // esi
  unsigned int *codelist; // edx
  bool v25; // zf
  const static_codebook *v26; // ebx
  vostok::memory::doug_lea_mt_allocator *dec_index; // ecx
  unsigned int **v28; // esi
  int v29; // eax
  bool v30; // cc
  char *v31; // eax
  unsigned int **v32; // edx
  int v33; // ecx
  int *v34; // eax
  char *v35; // eax
  unsigned int used_entries; // ecx
  int i; // eax
  int v38; // eax
  int dec_firsttablen; // ecx
  int v40; // ebx
  unsigned int *v41; // eax
  int v42; // esi
  unsigned int *v43; // ebx
  char *dec_codelengths; // eax
  int v45; // ecx
  char *v46; // eax
  int v47; // ebx
  unsigned int v48; // edx
  unsigned int v49; // eax
  unsigned int v50; // edx
  unsigned int v51; // eax
  int v52; // edx
  int v53; // eax
  char *v54; // esi
  unsigned int v55; // esi
  unsigned int v56; // edx
  unsigned int v57; // ebx
  unsigned int v58; // ecx
  int v59; // ebx
  unsigned int v60; // ecx
  unsigned int **v61; // ebx
  int v62; // eax
  int v63; // eax
  unsigned int v64; // ebx
  __int16 v65; // si
  unsigned int v66; // edx
  unsigned int v67; // ecx
  unsigned int v68; // eax
  unsigned int v69; // [esp-4h] [ebp-28h]
  char (*v70)[112]; // [esp+0h] [ebp-24h] BYREF
  volatile int *v71; // [esp+4h] [ebp-20h]
  vostok::memory::inplace_constructor v72; // [esp+8h] [ebp-1Ch]
  unsigned int mask; // [esp+Ch] [ebp-18h]
  int tabn; // [esp+10h] [ebp-14h]
  unsigned int *codes; // [esp+14h] [ebp-10h]
  unsigned int size; // [esp+18h] [ebp-Ch]
  int hi; // [esp+1Ch] [ebp-8h]
  unsigned int **codep; // [esp+20h] [ebp-4h]
  int lo; // [esp+2Ch] [ebp+8h]
  int loa; // [esp+2Ch] [ebp+8h]

  v2 = 0;
  memset((int)c, 0, sizeof(codebook));
  entries = s->entries;
  if ( entries > 0 )
  {
    lengthlist = s->lengthlist;
    v6 = s->entries;
    do
    {
      if ( *lengthlist > 0 )
        ++v2;
      ++lengthlist;
      --v6;
    }
    while ( v6 );
  }
  c->entries = entries;
  c->used_entries = v2;
  c->dim = s->dim;
  if ( v2 > 0 )
  {
    words = _make_words(s->lengthlist, s->entries, v2);
    codes = words;
    size = 4 * v2;
    v9 = alloca(4 * v2);
    codep = (unsigned int **)&v70;
    if ( !words )
    {
      vorbis_book_clear(c, v7);
      return -1;
    }
    v11 = words;
    tabn = (char *)codep - (char *)words;
    hi = v2;
    do
    {
      v12 = __ROL4__(*v11, 16);
      v13 = (v12 << 8) ^ (unsigned int)&vostok::memory::s_CRT_arena[5508919] & ((v12 << 8) ^ (v12 >> 8));
      v14 = (16 * v13) ^ ((16 * v13) ^ (v13 >> 4)) & 0xF0F0F0F;
      v15 = (4 * v14) ^ ((4 * v14) ^ (v14 >> 2)) & 0x33333333;
      *v11 = (2 * v15) ^ ((2 * v15) ^ (v15 >> 1)) & 0x55555555;
      *(unsigned int *)((char *)v11 + tabn) = (unsigned int)v11;
      ++v11;
      --hi;
    }
    while ( hi );
    v16 = codes;
    qsort((char *)codep, v2, 4u, (int (__cdecl *)(const void *, const void *))sort32a);
    v17 = alloca(size);
    hi = (int)&v70;
    if ( !vostok::memory::g_crt_allocator.__vftable )
    {
      vostok::debug::preinitialize((vostok::debug *)v70);
      if ( !vostok::core::g_log_callback )
      {
        vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
        vostok::debug::set_log_callback(vostok::core::debug_log_callback);
      }
      LOBYTE(tabn) = 0;
      vostok::bind_pointer_to_buffer_mt_safe<vostok::memory::doug_lea_mt_allocator,vostok::memory::inplace_constructor>(
        (vostok::memory::doug_lea_mt_allocator **)tabn,
        v70,
        v71,
        v72);
    }
    c->codelist = (unsigned int *)vostok::memory::doug_lea_mt_allocator::malloc_impl(
                                    (vostok::memory::doug_lea_mt_allocator *)size,
                                    size);
    v18 = 0;
    v19 = hi;
    do
    {
      *(_DWORD *)(v19 + 4 * (codep[v18] - v16)) = v18;
      ++v18;
    }
    while ( v18 < v2 );
    v20 = (int *)hi;
    v21 = (int)v16 - hi;
    tabn = v21;
    codep = (unsigned int **)v2;
    while ( 1 )
    {
      v22 = *v20;
      v23 = *(int *)((char *)v20 + v21);
      codelist = c->codelist;
      ++v20;
      v25 = codep == (unsigned int **)1;
      codep = (unsigned int **)((char *)codep - 1);
      codelist[v22] = v23;
      if ( v25 )
        break;
      v21 = tabn;
    }
    if ( !vostok::memory::g_crt_allocator.__vftable )
    {
      vostok::debug::preinitialize((vostok::debug *)v70);
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
            (const bool)v70,
            (const bool)v71,
            *(_BYTE *)&v72,
            mask);
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
    vostok::memory::doug_lea_mt_allocator::free_impl((vostok::memory::doug_lea_mt_allocator *)codes, codes);
    c->valuelist = _book_unquantize(s, v2, (int *)hi);
    if ( !vostok::memory::g_crt_allocator.__vftable )
    {
      vostok::debug::preinitialize((vostok::debug *)v70);
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
            (const bool)v70,
            (const bool)v71,
            *(_BYTE *)&v72,
            mask);
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
    v26 = s;
    c->dec_index = (int *)vostok::memory::doug_lea_mt_allocator::malloc_impl(
                            (vostok::memory::doug_lea_mt_allocator *)size,
                            size);
    v28 = 0;
    v29 = 0;
    v30 = s->entries <= 0;
    codep = 0;
    if ( !v30 )
    {
      do
      {
        if ( s->lengthlist[v29] > 0 )
        {
          dec_index = (vostok::memory::doug_lea_mt_allocator *)c->dec_index;
          *((_DWORD *)&dec_index->__vftable + *(_DWORD *)(hi + 4 * (_DWORD)v28)) = v29;
          v28 = (unsigned int **)((char *)v28 + 1);
        }
        ++v29;
      }
      while ( v29 < s->entries );
      codep = v28;
    }
    if ( !vostok::memory::g_crt_allocator.__vftable )
    {
      vostok::debug::preinitialize((vostok::debug *)v70);
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
            dec_index,
            (const bool)v70,
            (const bool)v71,
            *(_BYTE *)&v72,
            mask);
          (*(void (__thiscall **)(char *, unsigned __int8 *, unsigned __int8 *, _DWORD, const char *))(*(_DWORD *)s_crt_allocator_buffer + 4))(
            s_crt_allocator_buffer,
            vostok::memory::s_CRT_arena,
            &vostok::memory::s_CRT_arena[55905848],
            0,
            "CRT allocator");
          dec_index = &vostok::memory::g_crt_allocator;
          _InterlockedExchange((volatile __int32 *)&vostok::memory::g_crt_allocator, (__int32)s_crt_allocator_buffer);
          v28 = codep;
        }
      }
    }
    v31 = (char *)vostok::memory::doug_lea_mt_allocator::malloc_impl(dec_index, (unsigned int)v28);
    v32 = 0;
    v33 = 0;
    c->dec_codelengths = v31;
    v30 = s->entries <= 0;
    codep = 0;
    if ( !v30 )
    {
      do
      {
        v34 = v26->lengthlist;
        v30 = v34[v33] <= 0;
        v35 = (char *)&v34[v33];
        if ( !v30 )
        {
          c->dec_codelengths[*(_DWORD *)(hi + 4 * (_DWORD)v32)] = *v35;
          v26 = s;
          v32 = (unsigned int **)((char *)v32 + 1);
        }
        ++v33;
      }
      while ( v33 < v26->entries );
      codep = v32;
    }
    used_entries = c->used_entries;
    for ( i = 0; used_entries; used_entries >>= 1 )
      ++i;
    v38 = i - 4;
    c->dec_firsttablen = v38;
    if ( v38 < 5 )
      c->dec_firsttablen = 5;
    if ( c->dec_firsttablen > 8 )
      c->dec_firsttablen = 8;
    dec_firsttablen = c->dec_firsttablen;
    v40 = 1 << dec_firsttablen;
    tabn = 1 << dec_firsttablen;
    if ( !vostok::memory::g_crt_allocator.__vftable )
    {
      vostok::debug::preinitialize((vostok::debug *)v70);
      if ( !vostok::core::g_log_callback )
      {
        vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
        vostok::debug::set_log_callback(vostok::core::debug_log_callback);
      }
      if ( !vostok::memory::g_crt_allocator.__vftable )
      {
        dec_firsttablen = (int)&s_crt_allocator_creation;
        if ( _InterlockedExchange((volatile __int32 *)&s_crt_allocator_creation, 1) )
        {
          while ( !vostok::memory::g_crt_allocator.__vftable )
            ;
        }
        else
        {
          vostok::memory::doug_lea_mt_allocator::doug_lea_mt_allocator(
            &s_crt_allocator_creation,
            (const bool)v70,
            (const bool)v71,
            *(_BYTE *)&v72,
            mask);
          (*(void (__thiscall **)(char *, unsigned __int8 *, unsigned __int8 *, _DWORD, const char *))(*(_DWORD *)s_crt_allocator_buffer + 4))(
            s_crt_allocator_buffer,
            vostok::memory::s_CRT_arena,
            &vostok::memory::s_CRT_arena[55905848],
            0,
            "CRT allocator");
          dec_firsttablen = _InterlockedExchange(
                              (volatile __int32 *)&vostok::memory::g_crt_allocator,
                              (__int32)s_crt_allocator_buffer);
        }
      }
    }
    v41 = (unsigned int *)vostok::memory::doug_lea_mt_allocator::malloc_impl(
                            (vostok::memory::doug_lea_mt_allocator *)dec_firsttablen,
                            4 * v40);
    v69 = 4 * v40;
    v42 = 0;
    v43 = v41;
    memset((int)v41, 0, v69);
    v30 = (int)codep <= 0;
    c->dec_firsttable = v43;
    c->dec_maxlength = 0;
    if ( !v30 )
    {
      do
      {
        dec_codelengths = c->dec_codelengths;
        v45 = dec_codelengths[v42];
        v46 = &dec_codelengths[v42];
        if ( c->dec_maxlength < v45 )
          c->dec_maxlength = v45;
        v47 = *v46;
        if ( v47 <= c->dec_firsttablen )
        {
          v48 = __ROL4__(c->codelist[v42], 16);
          v49 = (v48 << 8) ^ (unsigned int)&vostok::memory::s_CRT_arena[5508919] & ((v48 << 8) ^ (v48 >> 8));
          v50 = (16 * v49) ^ ((16 * v49) ^ (v49 >> 4)) & 0xF0F0F0F;
          v51 = (4 * v50) ^ ((4 * v50) ^ (v50 >> 2)) & 0x33333333;
          v52 = (2 * v51) ^ ((2 * v51) ^ (v51 >> 1)) & 0x55555555;
          v53 = 0;
          lo = 0;
          if ( 1 << (LOBYTE(c->dec_firsttablen) - v47) > 0 )
          {
            do
            {
              c->dec_firsttable[v52 | (v53 << c->dec_codelengths[v42])] = v42 + 1;
              v53 = lo + 1;
              lo = v53;
            }
            while ( v53 < 1 << (LOBYTE(c->dec_firsttablen) - c->dec_codelengths[v42]) );
          }
        }
        ++v42;
      }
      while ( v42 < (int)codep );
    }
    v54 = 0;
    loa = 0;
    mask = -2 << (31 - LOBYTE(c->dec_firsttablen));
    hi = 0;
    for ( codes = 0; (int)codes < tabn; codes = (unsigned int *)((char *)codes + 1) )
    {
      v55 = (_DWORD)v54 << (32 - LOBYTE(c->dec_firsttablen));
      v56 = __ROL4__(v55, 16);
      v57 = 16 * ((v56 << 8) ^ (unsigned int)&vostok::memory::s_CRT_arena[5508919] & ((v56 << 8) ^ (v56 >> 8)));
      v58 = v57
          ^ (v57
           ^ (((v56 << 8) ^ (unsigned int)&vostok::memory::s_CRT_arena[5508919] & ((v56 << 8) ^ (v56 >> 8))) >> 4))
          & 0xF0F0F0F;
      v59 = 2 * ((4 * v58) ^ ((4 * v58) ^ (v58 >> 2)) & 0x33333333);
      if ( !c->dec_firsttable[v59 ^ (v59 ^ (((4 * v58) ^ ((4 * v58) ^ (v58 >> 2)) & 0x33333333) >> 1)) & 0x55555555] )
      {
        v60 = loa;
        v61 = codep;
        v62 = loa + 1;
        if ( loa + 1 < (int)codep )
        {
          v61 = codep;
          size = (unsigned int)&c->codelist[loa + 1];
          do
          {
            if ( *(_DWORD *)size > v55 )
              break;
            ++loa;
            size += 4;
            ++v62;
          }
          while ( v62 < (int)codep );
          v60 = loa;
        }
        v63 = hi;
        if ( hi < (int)v61 )
        {
          size = (unsigned int)&c->codelist[hi];
          do
          {
            if ( v55 < (mask & *(_DWORD *)size) )
              break;
            size += 4;
            ++v63;
          }
          while ( v63 < (int)v61 );
          v60 = loa;
          hi = v63;
        }
        v64 = (unsigned int)v61 - v63;
        v65 = v60;
        if ( v60 > 0x7FFF )
          v65 = 0x7FFF;
        if ( v64 > 0x7FFF )
          v64 = 0x7FFF;
        v66 = (v56 << 8) ^ (unsigned int)&vostok::memory::s_CRT_arena[5508919] & ((v56 << 8) ^ (v56 >> 8));
        v67 = (16 * v66) ^ ((16 * v66) ^ (v66 >> 4)) & 0xF0F0F0F;
        v68 = (4 * v67) ^ ((4 * v67) ^ (v67 >> 2)) & 0x33333333;
        c->dec_firsttable[(2 * v68) ^ ((2 * v68) ^ (v68 >> 1)) & 0x55555555] = v64
                                                                             | ((*(_DWORD *)&v65 | 0xFFFF0000) << 15);
      }
      v54 = (char *)codes + 1;
    }
  }
  return 0;
}
