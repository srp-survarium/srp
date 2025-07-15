float ***__cdecl setup_tone_curves(float *curveatt_dB, float binHz, int n, float center_boost, float center_decay_rate)
{
  vostok::memory::doug_lea_mt_allocator *v5; // ecx
  void *v6; // esp
  double v7; // st7
  double v8; // st6
  double v9; // st5
  double v10; // st4
  const float *v11; // ebx
  double v12; // st3
  double v13; // st2
  int v14; // esi
  double v15; // rtt
  double v16; // rt0
  double v17; // st2
  double v18; // st4
  int v19; // edx
  float *v20; // ecx
  int v21; // edi
  double v22; // st1
  float *v23; // eax
  const void *v24; // edx
  double v25; // st5
  float *v26; // ecx
  int v27; // edi
  int i; // esi
  double v29; // st4
  double v30; // st4
  double v31; // st7
  float *v32; // ebx
  double v33; // st7
  float *v34; // edx
  float *v35; // edi
  float *v36; // esi
  int v37; // ebx
  int v38; // ecx
  bool v39; // cc
  void *v40; // eax
  double v41; // st7
  int v42; // edi
  long double v43; // st7
  double v44; // st7
  int v45; // esi
  long double v46; // st7
  int v47; // eax
  void *v48; // eax
  int v49; // eax
  float *v50; // ebx
  int v51; // esi
  int v52; // edi
  int v53; // eax
  int v54; // edx
  int v55; // ecx
  float *j; // edx
  int v57; // esi
  int v58; // ebx
  int v59; // edi
  int v60; // ecx
  int v61; // eax
  float v62; // edx
  float *v63; // edi
  int v64; // ecx
  double v65; // st6
  float *v66; // ecx
  float *v67; // edx
  float *v68; // ecx
  int v69; // edi
  float *v70; // ebx
  float *v71; // esi
  int v72; // eax
  double v73; // st7
  int v74; // ecx
  float *v75; // edx
  float *v76; // esi
  double v77; // st6
  float *v78; // edx
  char (*v80)[112]; // [esp+8h] [ebp-7F44h] BYREF
  volatile int *v81; // [esp+Ch] [ebp-7F40h]
  vostok::memory::inplace_constructor v82; // [esp+10h] [ebp-7F3Ch]
  bool v83; // [esp+14h] [ebp-7F38h]
  _DWORD dst[7616]; // [esp+18h] [ebp-7F34h] BYREF
  float v85; // [esp+7718h] [ebp-834h] BYREF
  float c2[392]; // [esp+77F8h] [ebp-754h] BYREF
  _BYTE v87[224]; // [esp+7E18h] [ebp-134h] BYREF
  double v88; // [esp+7EF8h] [ebp-54h]
  vostok::memory::doug_lea_mt_allocator **pointer; // [esp+7F04h] [ebp-48h]
  double v90; // [esp+7F08h] [ebp-44h]
  double v91; // [esp+7F10h] [ebp-3Ch]
  _DWORD *v92; // [esp+7F1Ch] [ebp-30h]
  char (**v93)[112]; // [esp+7F20h] [ebp-2Ch]
  int v94; // [esp+7F24h] [ebp-28h]
  float *v95; // [esp+7F28h] [ebp-24h]
  const float *v96; // [esp+7F2Ch] [ebp-20h]
  int v97; // [esp+7F30h] [ebp-1Ch]
  float *c; // [esp+7F34h] [ebp-18h]
  int v99; // [esp+7F38h] [ebp-14h]
  float v100; // [esp+7F3Ch] [ebp-10h]
  int att; // [esp+7F40h] [ebp-Ch]
  int v102; // [esp+7F44h] [ebp-8h]

  v6 = alloca(4 * n);
  v93 = &v80;
  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator((vostok::memory *)v80);
  v92 = vostok::memory::doug_lea_mt_allocator::malloc_impl(v5, 0x44u);
  memset((int)dst, 0, sizeof(dst));
  v7 = center_decay_rate;
  v8 = center_boost;
  v9 = -30.0;
  v96 = ATH;
  v10 = 999.0;
  v11 = ATH;
  v12 = -30.0;
  v13 = 0.0;
  v97 = 0;
  *(float *)&c = COERCE_FLOAT(dst);
  v94 = (int)tonemasks;
  v14 = 0;
  while ( 2 )
  {
    while ( 1 )
    {
      v16 = v13;
      v17 = v10;
      v18 = v16;
      v100 = v17;
      v19 = v14 + v97;
      v20 = (float *)v11;
      v21 = 4;
      do
      {
        v22 = v100;
        if ( v19 >= 88 )
        {
          if ( v22 > v12 )
            v100 = v9;
        }
        else if ( *v20 < v22 )
        {
          v100 = *v20;
        }
        ++v20;
        ++v19;
        --v21;
      }
      while ( v21 );
      c2[++v14 + 391] = v100;
      ++v11;
      if ( v14 >= 56 )
        break;
      v15 = v17;
      v13 = v18;
      v10 = v15;
    }
    v23 = c;
    v24 = (const void *)v94;
    v25 = v18;
    qmemcpy(c + 112, (const void *)v94, 0x540u);
    qmemcpy(v23, v24, 0xE0u);
    v95 = v23 + 56;
    qmemcpy(v23 + 56, v24, 0xE0u);
    v26 = v23;
    v27 = 8;
    do
    {
      for ( i = 16; i > -40; --i )
      {
        *(float *)&att = COERCE_FLOAT(abs32(i));
        *(float *)&v99 = (double)att * v7 + v8;
        v29 = *(float *)&v99;
        if ( *(float *)&v99 < v25 )
        {
          if ( v8 > v25 )
            goto LABEL_21;
          v29 = *(float *)&v99;
        }
        if ( v29 > v25 && v25 > v8 )
LABEL_21:
          *(float *)&v99 = v25;
        v30 = *(float *)&v99 + *v26++;
        *(v26 - 1) = v30;
      }
      --v27;
      v99 = (int)v26;
    }
    while ( v27 );
    v31 = *(float *)((char *)curveatt_dB + v97);
    *(float *)&v102 = 0.0;
    v32 = &v85;
    v91 = v31 + 100.0;
    do
    {
      att = 2;
      if ( v102 >= 2 )
        att = v102;
      *(float *)&att = v91 - (double)att * 10.0 - 30.0;
      attenuate_curve(c, *(float *)&att);
      v33 = (double)v102 * 10.0;
      qmemcpy(v32, v87, 0xE0u);
      *(float *)&att = 100.0 - v33 - 30.0;
      attenuate_curve(v32, *(float *)&att);
      max_curve(v32, v34);
      c += 56;
      v32 += 56;
      ++v102;
    }
    while ( v102 < 8 );
    v35 = v95;
    v36 = c2;
    v37 = 7;
    do
    {
      min_curve(v36, v36 - 56);
      min_curve(v35, v36);
      v36 += 56;
      v35 += 56;
      --v37;
    }
    while ( v37 );
    v94 += 1344;
    v97 += 4;
    v38 = v99;
    v39 = (int)(v96 + 4) < (int)&unk_94E970;
    v96 += 4;
    c = (float *)v99;
    if ( v39 )
    {
      v11 = v96;
      v14 = 0;
      v7 = center_decay_rate;
      v8 = center_boost;
      v9 = -30.0;
      v10 = 999.0;
      v13 = 0.0;
      v12 = -30.0;
      continue;
    }
    break;
  }
  *(float *)&v99 = 0.0;
  while ( 1 )
  {
    if ( !vostok::memory::g_crt_allocator.__vftable )
    {
      vostok::debug::preinitialize((vostok::debug *)v80);
      if ( !vostok::core::g_log_callback )
      {
        vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
        vostok::debug::set_log_callback(vostok::core::debug_log_callback);
      }
      LOBYTE(pointer) = 0;
      vostok::bind_pointer_to_buffer_mt_safe<vostok::memory::doug_lea_mt_allocator,vostok::memory::inplace_constructor>(
        pointer,
        v80,
        v81,
        v82);
    }
    v40 = vostok::memory::doug_lea_mt_allocator::malloc_impl((vostok::memory::doug_lea_mt_allocator *)v38, 0x20u);
    v41 = (double)v99;
    v92[v37] = v40;
    v91 = v41 * 0.5;
    v42 = (int)floor(exp((v91 + 5.965784072875977) * 0.6931470036506653) / binHz);
    att = v42;
    v43 = log((double)v42 * binHz + 1.0);
    v44 = ceil(v43 * 1.442695021629333 - 5.965784072875977 + v43 * 1.442695021629333 - 5.965784072875977);
    att = v42 + 1;
    v45 = (int)v44;
    v97 = (int)v44;
    v46 = log((double)(v42 + 1) * binHz);
    v47 = (int)floor(v46 * 1.442695021629333 - 5.965784072875977 + v46 * 1.442695021629333 - 5.965784072875977);
    att = v47;
    if ( v45 > v37 )
    {
      v45 = v37;
      v97 = v37;
    }
    v38 = 0;
    if ( v45 < 0 )
      v97 = 0;
    if ( v47 >= 17 )
      att = 16;
    v100 = 0.0;
    c = (float *)(v37 + 1);
    do
    {
      if ( !vostok::memory::g_crt_allocator.__vftable )
      {
        vostok::debug::preinitialize((vostok::debug *)v80);
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
              (vostok::memory::doug_lea_mt_allocator *)v38,
              (const bool)v80,
              (const bool)v81,
              *(_BYTE *)&v82,
              v83);
            (*(void (__thiscall **)(char *, unsigned __int8 *, unsigned __int8 *, _DWORD, const char *))(*(_DWORD *)s_crt_allocator_buffer + 4))(
              s_crt_allocator_buffer,
              vostok::memory::s_CRT_arena,
              &vostok::memory::s_CRT_arena[55905848],
              0,
              "CRT allocator");
            v38 = (int)&vostok::memory::g_crt_allocator;
            _InterlockedExchange((volatile __int32 *)&vostok::memory::g_crt_allocator, (__int32)s_crt_allocator_buffer);
          }
        }
      }
      v48 = vostok::memory::doug_lea_mt_allocator::malloc_impl((vostok::memory::doug_lea_mt_allocator *)v38, 0xE8u);
      *(_DWORD *)(v92[v99] + 4 * LODWORD(v100)) = v48;
      if ( n > 0 )
        memset32(v93, 1148829696, n);
      v96 = (const float *)v97;
      if ( v97 <= att )
      {
        v49 = LODWORD(v100) + 8 * v97;
        v94 = 56 * v49;
        v95 = (float *)&dst[56 * v49 + 55];
        do
        {
          v50 = (float *)v93;
          v51 = 0;
          *(float *)&v102 = 0.0;
          v88 = (double)(int)v96 * 0.5;
          do
          {
            v90 = (double)v102 * 0.125 + v88;
            v52 = (int)(exp((v90 - 2.0625 + 5.965784072875977) * 0.6931470036506653) / binHz);
            v53 = (int)(exp((v90 - 1.9375 + 5.965784072875977) * 0.6931470036506653) / binHz + 1.0);
            v54 = v53;
            if ( v52 < 0 )
              v52 = 0;
            v55 = n;
            if ( v52 > n )
              v52 = n;
            if ( v52 < v51 )
              v51 = v52;
            if ( v53 < 0 )
              v54 = 0;
            if ( v54 > n )
              v54 = n;
            for ( ; v51 < v54; ++v51 )
            {
              if ( v51 >= v55 )
                break;
              if ( *(float *)&dst[v94 + v102] < (double)v50[v51] )
                v50[v51] = *(float *)&dst[v94 + v102];
              v55 = n;
            }
            ++v102;
          }
          while ( v102 < 56 );
          for ( j = v95; v51 < v55; ++v51 )
          {
            if ( *j < (double)v50[v51] )
              v50[v51] = *j;
          }
          v94 += 448;
          v39 = (int)v96 + 1 <= att;
          v96 = (const float *)((char *)v96 + 1);
          v95 = j + 448;
        }
        while ( v39 );
      }
      if ( (int)c < 17 )
      {
        v57 = 0;
        v58 = 0;
        *(float *)&v102 = 0.0;
        do
        {
          v90 = (double)v102 * 0.125 + v91;
          v59 = (int)(exp((v90 - 2.0625 + 5.965784072875977) * 0.6931470036506653) / binHz);
          v102 = (int)(exp((v90 - 1.9375 + 5.965784072875977) * 0.6931470036506653) / binHz + 1.0);
          if ( v59 < 0 )
            v59 = 0;
          v60 = n;
          if ( v59 > n )
            v59 = n;
          if ( v59 < v57 )
            v57 = v59;
          v61 = v102;
          if ( v102 < 0 )
          {
            v61 = 0;
            *(float *)&v102 = 0.0;
          }
          if ( v61 > n )
          {
            v61 = n;
            v102 = n;
          }
          if ( v57 < v61 )
          {
            v62 = v100;
            v63 = (float *)v93;
            do
            {
              if ( v57 >= v60 )
                break;
              v64 = v58 + 56 * (LODWORD(v62) + 8 * (_DWORD)c);
              v65 = *(float *)&dst[v64];
              v66 = (float *)&dst[v64];
              if ( v65 < v63[v57] )
                v63[v57] = *v66;
              v60 = n;
              ++v57;
            }
            while ( v57 < v102 );
          }
          v102 = ++v58;
        }
        while ( v58 < 56 );
        if ( v57 < v60 )
        {
          v67 = (float *)v93;
          v68 = (float *)&dst[448 * (_DWORD)c + 55 + 56 * LODWORD(v100)];
          do
          {
            if ( *v68 < (double)v67[v57] )
              v67[v57] = *v68;
            ++v57;
          }
          while ( v57 < n );
        }
      }
      v69 = 0;
      v95 = *(float **)(v92[v99] + 4 * LODWORD(v100));
      v70 = v95 + 2;
      *(float *)&v102 = 0.0;
      v71 = v95 + 2;
      do
      {
        v72 = (int)(exp(((double)v102 * 0.125 + v91 - 2.0 + 5.965784072875977) * 0.6931470036506653) / binHz);
        if ( v72 >= 0 )
        {
          if ( v72 < n )
            v73 = *(float *)&v93[v72];
          else
            v73 = -999.0;
        }
        else
        {
          v73 = -999.0;
        }
        ++v69;
        *v71++ = v73;
        v102 = v69;
      }
      while ( v69 < 56 );
      v74 = 0;
      v75 = v70;
      do
      {
        if ( *v75 > -200.0 )
          break;
        ++v74;
        ++v75;
      }
      while ( v74 < 16 );
      v76 = v95;
      v102 = v74;
      v77 = (double)v74;
      v38 = 55;
      v78 = v95 + 57;
      *v95 = v77;
      do
      {
        if ( *v78 > -200.0 )
          break;
        --v38;
        --v78;
      }
      while ( v38 > 17 );
      v102 = v38;
      v39 = ++LODWORD(v100) < 8;
      v76[1] = (float)v38;
    }
    while ( v39 );
    v99 = (int)c;
    if ( (int)c >= 17 )
      break;
    v37 = v99;
  }
  return (float ***)v92;
}
