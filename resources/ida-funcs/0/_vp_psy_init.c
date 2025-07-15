void __usercall _vp_psy_init(
        vorbis_look_psy *p@<edi>,
        vorbis_info_psy_global *gi@<eax>,
        vorbis_info_psy *vi,
        int n,
        int rate)
{
  int v6; // ebp
  int v7; // eax
  vostok::memory::doug_lea_mt_allocator *v8; // ecx
  int v9; // ebx
  unsigned int v10; // esi
  vostok::memory::doug_lea_mt_allocator *v11; // ecx
  vostok::memory::doug_lea_mt_allocator *v12; // ecx
  int *v13; // eax
  double v14; // st7
  int v15; // ebp
  int v16; // esi
  long double v17; // st7
  int v18; // eax
  double v19; // st7
  double v20; // st6
  double v21; // st5
  double v22; // rt2
  double v23; // st5
  double v24; // st7
  float *ath; // eax
  double v26; // st7
  float *v27; // eax
  int v28; // ebp
  int v29; // esi
  int v30; // ebx
  vorbis_info_psy *v31; // ecx
  int v32; // edx
  int v33; // eax
  int v34; // eax
  int v35; // ecx
  double v36; // st7
  int v37; // esi
  long double v38; // st6
  vostok::memory::doug_lea_mt_allocator *v39; // ecx
  int i; // ebp
  vostok::memory::doug_lea_mt_allocator *v41; // ecx
  int v42; // esi
  long double v43; // st7
  double v44; // st7
  int v45; // ecx
  int v46; // eax
  double v47; // st7
  double v48; // st6
  vorbis_info_psy *v49; // edx
  double v50; // st5
  vostok::memory *v51; // [esp+10h] [ebp-50h]
  bool v52; // [esp+14h] [ebp-4Ch]
  bool v53; // [esp+18h] [ebp-48h]
  bool v54; // [esp+1Ch] [ebp-44h]
  int lo; // [esp+20h] [ebp-40h]
  int hi; // [esp+24h] [ebp-3Ch]
  float base; // [esp+28h] [ebp-38h]
  float basea; // [esp+28h] [ebp-38h]
  int baseb; // [esp+28h] [ebp-38h]
  int v60; // [esp+2Ch] [ebp-34h]
  float v61; // [esp+30h] [ebp-30h]
  int v62; // [esp+30h] [ebp-30h]
  int v63; // [esp+30h] [ebp-30h]
  float v64; // [esp+34h] [ebp-2Ch]
  int v65; // [esp+34h] [ebp-2Ch]
  int v66; // [esp+38h] [ebp-28h]
  float v67; // [esp+38h] [ebp-28h]
  float barka; // [esp+3Ch] [ebp-24h]
  float barkb; // [esp+3Ch] [ebp-24h]
  float bark; // [esp+3Ch] [ebp-24h]
  int v71; // [esp+40h] [ebp-20h]
  double v72; // [esp+48h] [ebp-18h]
  double v73; // [esp+50h] [ebp-10h]
  long double v74; // [esp+58h] [ebp-8h]
  int halfoc; // [esp+68h] [ebp+8h]
  float halfocc; // [esp+68h] [ebp+8h]
  int halfoca; // [esp+68h] [ebp+8h]
  float halfocb; // [esp+68h] [ebp+8h]
  float halfocd; // [esp+68h] [ebp+8h]
  float halfoce; // [esp+68h] [ebp+8h]
  float ratec; // [esp+6Ch] [ebp+Ch]
  int ratea; // [esp+6Ch] [ebp+Ch]
  int rateb; // [esp+6Ch] [ebp+Ch]

  lo = -99;
  hi = 1;
  memset((int)p, 0, sizeof(vorbis_look_psy));
  p->eighth_octave_lines = gi->eighth_octave_lines;
  v6 = (int)(floor(log((double)gi->eighth_octave_lines * 8.0) / log(2.0) + 0.5) - 1.0);
  p->shiftoc = v6;
  v61 = (float)rate;
  v72 = (double)n;
  v7 = (int)((log(v61 * 0.25 * 0.5 / v72) * 1.442695021629333 - 5.965784072875977) * (double)(1 << (v6 + 1))
           - (double)gi->eighth_octave_lines);
  p->firstoc = v7;
  v8 = (vostok::memory::doug_lea_mt_allocator *)(v6 + 1);
  p->total_octave_lines = (int)((log((v72 + 0.25) * v61 * 0.5 / v72) * 1.442695021629333 - 5.965784072875977)
                              * (double)(1 << (v6 + 1))
                              + 0.5)
                        - v7
                        + 1;
  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(v51);
  v9 = n;
  v10 = 4 * n;
  p->ath = (float *)vostok::memory::doug_lea_mt_allocator::malloc_impl(v8, 4 * n);
  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(v51);
  p->octave = (int *)vostok::memory::doug_lea_mt_allocator::malloc_impl(v11, v10);
  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(v51);
  v13 = (int *)vostok::memory::doug_lea_mt_allocator::malloc_impl(v12, v10);
  p->m_val = 1.0;
  p->bark = v13;
  p->vi = vi;
  p->n = n;
  p->rate = rate;
  if ( rate < 26000 )
  {
    v14 = 0.0;
LABEL_13:
    p->m_val = v14;
    goto LABEL_14;
  }
  if ( rate < 38000 )
  {
    v14 = 0.94;
    goto LABEL_13;
  }
  if ( rate > 46000 )
  {
    v14 = 1.275;
    goto LABEL_13;
  }
LABEL_14:
  v15 = 0;
  v16 = 0;
  v73 = (double)rate;
  do
  {
    v62 = v15 + 1;
    v17 = exp(((double)(v15 + 1) * 0.125 - 2.0 + 5.965784072875977) * 0.6931470036506653);
    v18 = (int)floor((v17 + v17) * v72 / v73 + 0.5);
    base = ATH[v15];
    if ( v16 < v18 )
    {
      v19 = base;
      barka = (flt_94E864[v15] - base) / (double)(v18 - v16);
      v20 = barka;
      v21 = 100.0;
      while ( v16 < n )
      {
        ++v16;
        barkb = v19 + v21;
        p->ath[v16 - 1] = barkb;
        v22 = v21;
        v23 = v19 + v20;
        v24 = v22;
        basea = v23;
        if ( v16 >= v18 )
          break;
        v21 = v24;
        v19 = basea;
      }
    }
    ++v15;
  }
  while ( v62 < 87 );
  for ( ; v16 < n; *v27 = v26 )
  {
    ath = p->ath;
    v26 = ath[v16 - 1];
    v27 = &ath[v16++];
  }
  v28 = 0;
  if ( n > 0 )
  {
    v29 = rate / (2 * n);
    v30 = v29 * v29;
    v63 = 0;
    v60 = 0;
    do
    {
      ratec = (float)v63;
      v31 = vi;
      v32 = lo;
      bark = atan(ratec * 0.0007399999885819852) * 13.10000038146973
           + atan((double)(v28 * v60) * 0.00000001849999975434002) * 2.240000009536743
           + ratec * 0.00009999999747378752;
      if ( lo + vi->noisewindowlomin < v28 )
      {
        v66 = lo + vi->noisewindowlomin;
        baseb = lo * v29;
        v33 = lo * v30;
        ratea = lo * v30;
        while ( 1 )
        {
          v64 = (float)baseb;
          if ( atan(v64 * 0.0007399999885819852) * 13.10000038146973
             + atan((double)(v32 * v33) * 0.00000001849999975434002) * 2.240000009536743
             + v64 * 0.00009999999747378752 >= bark - vi->noisewindowlo )
            break;
          ++lo;
          ratea += v30;
          baseb += v29;
          if ( ++v66 >= v28 )
            break;
          v33 = ratea;
          v32 = lo;
        }
        v31 = vi;
      }
      v34 = hi;
      if ( hi <= n )
      {
        v71 = v28 + v31->noisewindowhimin;
        rateb = hi * v29;
        v35 = hi * v30;
        v65 = hi * v30;
        do
        {
          if ( v34 >= v71 )
          {
            v67 = (float)rateb;
            v74 = atan((double)(v34 * v35) * 0.00000001849999975434002) * 2.240000009536743;
            v34 = hi;
            if ( vi->noisewindowhi + bark <= atan(v67 * 0.0007399999885819852) * 13.10000038146973
                                           + v74
                                           + v67 * 0.00009999999747378752 )
              break;
            v35 = v65;
          }
          rateb += v29;
          ++v34;
          v35 += v30;
          hi = v34;
          v65 = v35;
        }
        while ( v34 <= n );
      }
      v60 += v30;
      v63 += v29;
      p->bark[v28++] = (lo << 16) + v34 - 65537;
    }
    while ( v28 < n );
    v9 = n;
  }
  v36 = 0.5;
  v37 = 0;
  for ( halfoc = 0; v37 < v9; halfoc = v37 )
  {
    v38 = (log(v36 * ((double)halfoc + 0.25) * v73 / v72) * 1.442695021629333 - 5.965784072875977)
        * (double)(1 << (LOBYTE(p->shiftoc) + 1))
        + 0.5;
    v36 = 0.5;
    p->octave[v37++] = (int)v38;
  }
  halfocc = v36 * v73 / v72;
  p->tonecurves = setup_tone_curves(vi->toneatt, halfocc, v9, vi->tone_centerboost, vi->tone_decay);
  if ( !vostok::memory::g_crt_allocator.__vftable )
  {
    vostok::debug::preinitialize(v51);
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
        vostok::memory::doug_lea_mt_allocator::doug_lea_mt_allocator(v39, (const bool)v51, v52, v53, v54);
        (*(void (__thiscall **)(char *, unsigned __int8 *, unsigned __int8 *, _DWORD, const char *))(*(_DWORD *)s_crt_allocator_buffer + 4))(
          s_crt_allocator_buffer,
          vostok::memory::s_CRT_arena,
          &vostok::memory::s_CRT_arena[55905848],
          0,
          "CRT allocator");
        v39 = &vostok::memory::g_crt_allocator;
        _InterlockedExchange((volatile __int32 *)&vostok::memory::g_crt_allocator, (__int32)s_crt_allocator_buffer);
      }
    }
  }
  p->noiseoffset = (float **)vostok::memory::doug_lea_mt_allocator::malloc_impl(v39, 0xCu);
  for ( i = 0; i < 3; ++i )
  {
    if ( !vostok::memory::g_crt_allocator.__vftable )
    {
      vostok::debug::preinitialize(v51);
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
          vostok::memory::doug_lea_mt_allocator::doug_lea_mt_allocator(v41, (const bool)v51, v52, v53, v54);
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
    p->noiseoffset[i] = (float *)vostok::memory::doug_lea_mt_allocator::malloc_impl(
                                   (vostok::memory::doug_lea_mt_allocator *)(4 * v9),
                                   4 * v9);
  }
  v42 = 0;
  for ( halfoca = 0; v42 < v9; halfoca = v42 )
  {
    v43 = log(((double)halfoca + 0.5) * v73 / (v72 + v72));
    halfocb = v43 * 1.442695021629333 - 5.965784072875977 + v43 * 1.442695021629333 - 5.965784072875977;
    if ( halfocb >= 0.0 )
    {
      v44 = halfocb;
      if ( halfocb >= 16.0 )
        v44 = (float)16.0;
    }
    else
    {
      v44 = (float)0.0;
    }
    v45 = 0;
    v46 = 4 * (int)v44 + 136;
    halfocd = v44 - (double)(int)v44;
    v47 = halfocd;
    v48 = 1.0 - halfocd;
    do
    {
      v49 = p->vi;
      ++v45;
      v50 = *(float *)((char *)&v49->blockflag + v46) * v47;
      v46 += 68;
      halfoce = v50 + *(float *)((char *)v49 + v46 - 72) * v48;
      p->noiseoffset[v45 - 1][v42] = halfoce;
    }
    while ( v45 < 3 );
    ++v42;
  }
}
