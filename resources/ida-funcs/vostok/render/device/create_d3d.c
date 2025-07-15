void __thiscall vostok::render::device::create_d3d(vostok::render::device *this, unsigned int wcs1)
{
  unsigned int v2; // ebx
  wchar_t *v3; // esi
  int DXGIFactory; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // ecx
  bool *d3d11_error_string; // eax
  _DWORD *v7; // edi
  int *v8; // eax
  int v9; // edx
  int i; // eax
  wchar_t *v11; // ecx
  wchar_t *v12; // eax
  bool v13; // cf
  wchar_t v14; // dx
  int v15; // eax
  unsigned __int16 *v16; // eax
  unsigned __int16 *v17; // eax
  unsigned __int16 *v18; // eax
  unsigned __int16 *v19; // eax
  bool v20; // al
  bool v21; // al
  bool has_passed_filters; // al
  vostok::math::int2 *v23; // eax
  int v24; // edi
  void *v25; // ebx
  int *v26; // eax
  int v27; // ecx
  int v28; // eax
  int *v29; // eax
  HRESULT v30; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v31; // ecx
  bool *v32; // eax
  void *v33; // esp
  HRESULT v34; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v35; // ecx
  bool *v36; // eax
  bool v37; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v38; // ecx
  int v39; // ebx
  vostok::math::int2 *v40; // eax
  unsigned int v41; // edx
  wchar_t *v42; // eax
  bool v43; // zf
  bool v44; // al
  int v45; // ecx
  int *v46; // eax
  int v47; // ecx
  wchar_t *v48; // [esp-4h] [ebp-C8h]
  wchar_t *v49; // [esp-4h] [ebp-C8h]
  wchar_t *v50; // [esp-4h] [ebp-C8h]
  wchar_t *v51; // [esp-4h] [ebp-C8h]
  wchar_t *v52; // [esp-4h] [ebp-C8h]
  wchar_t *v53; // [esp-4h] [ebp-C8h]
  wchar_t *v54; // [esp-4h] [ebp-C8h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v55; // [esp-4h] [ebp-C8h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v56; // [esp-4h] [ebp-C8h]
  _BYTE v57[16]; // [esp+0h] [ebp-C4h] BYREF
  char v58[100]; // [esp+10h] [ebp-B4h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v59; // [esp+74h] [ebp-50h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v60; // [esp+78h] [ebp-4Ch] BYREF
  int **v61; // [esp+98h] [ebp-2Ch]
  unsigned int v62; // [esp+9Ch] [ebp-28h]
  int *v63; // [esp+A0h] [ebp-24h]
  vostok::math::int2 *v64; // [esp+A4h] [ebp-20h]
  int v65; // [esp+A8h] [ebp-1Ch]
  int **v66; // [esp+ACh] [ebp-18h]
  int v67; // [esp+B0h] [ebp-14h]
  unsigned int v68; // [esp+B4h] [ebp-10h] BYREF
  int *v69; // [esp+B8h] [ebp-Ch] BYREF
  int v70; // [esp+BCh] [ebp-8h]

  v70 = 0;
  v2 = wcs1;
  v3 = (wchar_t *)(wcs1 + 296);
  DXGIFactory = CreateDXGIFactory(&_GUID_7b7166ec_21c7_44ae_b21a_c9ae321ae369, (void **)(wcs1 + 296));
  if ( !ignore_always && DXGIFactory < 0 )
  {
    HIBYTE(wcs1) = 1;
    d3d11_error_string = (bool *)make_d3d11_error_string(DXGIFactory, v5);
    vostok::debug::on_error(
      (bool *)&wcs1 + 3,
      process_error_true,
      d3d11_error_string,
      ".\\device.cpp",
      "vostok::render::device::create_d3d",
      (const char *)0x64);
    if ( vostok::debug::is_debugger_present() || HIBYTE(wcs1) )
      __debugbreak();
  }
  *(_DWORD *)(v2 + 336) = GetSystemMetrics(0);
  v7 = (_DWORD *)(v2 + 300);
  *(_DWORD *)(v2 + 340) = GetSystemMetrics(1);
  v8 = *(int **)v3;
  *(_DWORD *)(v2 + 300) = 0;
  *(_BYTE *)(v2 + 357) = 0;
  *(_DWORD *)(v2 + 352) = 1;
  v9 = *v8;
  v61 = (int **)(v2 + 300);
  wcs1 = 0;
  for ( i = (*(int (__stdcall **)(int *, _DWORD, unsigned int))(v9 + 28))(v8, 0, v2 + 300);
        ;
        i = (*(int (__stdcall **)(_DWORD, unsigned int, unsigned int))(**(_DWORD **)(v2 + 296) + 28))(
              *(_DWORD *)(v2 + 296),
              wcs1,
              v2 + 300) )
  {
    if ( i == -2005270526 )
      goto LABEL_38;
    (*(void (__stdcall **)(_DWORD, unsigned int))(*(_DWORD *)*v7 + 32))(*v7, v2);
    v11 = L"NVIDIA PerfHUD";
    v12 = (wchar_t *)v2;
    while ( 1 )
    {
      v13 = *v12 < *v11;
      if ( *v12 != *v11 )
        break;
      if ( !*v12 )
        goto LABEL_12;
      v14 = v12[1];
      v13 = v14 < v11[1];
      if ( v14 != v11[1] )
        break;
      v12 += 2;
      v11 += 2;
      if ( !v14 )
      {
LABEL_12:
        v15 = 0;
        goto LABEL_14;
      }
    }
    v15 = -v13 - (v13 - 1);
LABEL_14:
    if ( !v15 )
      break;
    v16 = wcsstr((const wchar_t *)v2, L"NVIDIA");
    v11 = v48;
    if ( v16
      || (v17 = wcsstr((const wchar_t *)v2, L"ATI"), v11 = v49, v17)
      || (v18 = wcsstr((const wchar_t *)v2, L"AMD"), v11 = v50, v18)
      || (v19 = wcsstr((const wchar_t *)v2, L"RADEON"), v11 = v51, v19) )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                   (const char *)2),
            v11 = v54,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v11,
          &v60);
        v70 |= 2u;
        vostok::logging::append(
          &v60,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\device.cpp",
          0x85u,
          "void __thiscall vostok::render::device::create_d3d(void)",
          (char *)&initiator_raw.initiator_tree,
          error,
          "Using graphics adapter %S",
          (const wchar_t *)v2);
      }
      if ( (v70 & 2) != 0 )
      {
        v70 &= ~2u;
        goto LABEL_37;
      }
      goto LABEL_38;
    }
    if ( !vostok::core::g_log_filter_tree
      || (v20 = vostok::logging::has_passed_filters(
                  (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                  (const char *)2),
          v11 = v52,
          v20) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v11,
        &v60);
      v70 |= 4u;
      vostok::logging::append(
        &v60,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\device.cpp",
        0x8Bu,
        "void __thiscall vostok::render::device::create_d3d(void)",
        (char *)&initiator_raw.initiator_tree,
        error,
        "Using default graphics adapter");
    }
    if ( (v70 & 4) != 0 )
    {
      v70 &= ~4u;
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
        (int *)&v60);
    }
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v7 + 8))(*v7);
    *v7 = 0;
    ++wcs1;
  }
  *(_BYTE *)(v2 + 357) = 1;
  if ( !vostok::core::g_log_filter_tree
    || (v21 = vostok::logging::has_passed_filters(
                (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                (const char *)2),
        v11 = v53,
        v21) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v11,
      &v60);
    v70 |= 1u;
    vostok::logging::append(
      &v60,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\device.cpp",
      0x7Bu,
      "void __thiscall vostok::render::device::create_d3d(void)",
      (char *)&initiator_raw.initiator_tree,
      error,
      "Using NVIDIA NVPerfHUD");
  }
  if ( (v70 & 1) != 0 )
  {
    v70 &= ~1u;
LABEL_37:
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
      (int *)&v60);
  }
LABEL_38:
  if ( !*v7 )
    (*(void (__stdcall **)(_DWORD, _DWORD, unsigned int))(**(_DWORD **)(v2 + 296) + 28))(
      *(_DWORD *)(v2 + 296),
      0,
      v2 + 300);
  vostok::render::g_num_monitors = 0;
  v23 = vostok::render::g_monitor_resolutions[0];
  wcs1 = 6;
  do
  {
    v24 = 512;
    do
    {
      v23->x = 0;
      v23->y = 0;
      ++v23;
      --v24;
    }
    while ( v24 );
    --wcs1;
  }
  while ( wcs1 );
  v25 = (void *)(v2 + 312);
  memset(v25, 0, 0x18u);
  v26 = *v61;
  v69 = 0;
  v27 = *v26;
  v67 = 0;
  v28 = (*(int (__stdcall **)(int *, _DWORD, int **))(v27 + 28))(v26, 0, &v69);
  if ( v28 != -2005270526 )
  {
    v65 = 0;
    v64 = vostok::render::g_monitor_resolutions[0];
    v66 = (int **)v25;
    do
    {
      if ( v28 < 0 )
        break;
      v29 = v69;
      *v66 = v69;
      v68 = 0;
      v30 = (*(int (__stdcall **)(int *, int, _DWORD, unsigned int *, _DWORD))(*v29 + 32))(v29, 28, 0, &v68, 0);
      if ( !ignore_always_0 && v30 < 0 )
      {
        HIBYTE(wcs1) = 1;
        v32 = (bool *)make_d3d11_error_string(v30, v31);
        vostok::debug::on_error(
          (bool *)&wcs1 + 3,
          process_error_true,
          v32,
          ".\\device.cpp",
          "vostok::render::device::create_d3d",
          (const char *)0xB5);
        if ( vostok::debug::is_debugger_present() || HIBYTE(wcs1) )
          __debugbreak();
      }
      v33 = alloca(28 * v68);
      v34 = (*(int (__stdcall **)(int *, int, _DWORD, unsigned int *, _BYTE *))(*v69 + 32))(v69, 28, 0, &v68, v57);
      if ( !ignore_always_1 && v34 < 0 )
      {
        HIBYTE(wcs1) = 1;
        v36 = (bool *)make_d3d11_error_string(v34, v35);
        vostok::debug::on_error(
          (bool *)&wcs1 + 3,
          process_error_true,
          v36,
          ".\\device.cpp",
          "vostok::render::device::create_d3d",
          (const char *)0xBA);
        if ( vostok::debug::is_debugger_present() || HIBYTE(wcs1) )
          __debugbreak();
      }
      wcs1 = 0;
      if ( !vostok::core::g_log_filter_tree
        || (v37 = vostok::logging::has_passed_filters(
                    (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                    (const char *)4),
            v35 = v55,
            v37) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v35,
          &v60);
        v70 |= 8u;
        vostok::logging::append(
          &v60,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\device.cpp",
          0xBEu,
          "void __thiscall vostok::render::device::create_d3d(void)",
          (char *)&initiator_raw.initiator_tree,
          info,
          "monitor %d",
          v67);
      }
      if ( (v70 & 8) != 0 )
      {
        v70 &= ~8u;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v35,
          (int *)&v60);
      }
      v62 = 0;
      if ( v68 )
      {
        v63 = (int *)v57;
        while ( 2 )
        {
          v38 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v63[1];
          v39 = *v63;
          v40 = v64;
          v59 = v38;
          v41 = 0;
          while ( v40->x != v39
               || (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v40->y != v38 )
          {
            ++v41;
            ++v40;
            if ( v41 >= 0x200 )
            {
              v42 = (wchar_t *)(wcs1 + v65);
              v43 = vostok::core::g_log_filter_tree == 0;
              vostok::render::g_monitor_resolutions[0][(_DWORD)v42].x = v39;
              dword_47DE69C[2 * (_DWORD)v42] = (int)v38;
              if ( v43
                || (v44 = vostok::logging::has_passed_filters(
                            (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                            (const char *)4),
                    v38 = v56,
                    v44) )
              {
                boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
                  v38,
                  &v60);
                v70 |= 0x10u;
                vostok::logging::append(
                  &v60,
                  (void *const)vostok::core::g_log_flags,
                  &vostok::core::g_log_format,
                  ".\\device.cpp",
                  0xC5u,
                  "void __thiscall vostok::render::device::create_d3d(void)",
                  (char *)&initiator_raw.initiator_tree,
                  info,
                  "  %dx%d",
                  v39,
                  v59);
              }
              if ( (v70 & 0x10) != 0 )
              {
                v70 &= ~0x10u;
                boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
                  (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v38,
                  (int *)&v60);
              }
              if ( ++wcs1 >= 0x200 )
                goto LABEL_75;
              break;
            }
          }
          ++v62;
          v63 += 7;
          if ( v62 < v68 )
            continue;
          break;
        }
      }
LABEL_75:
      v45 = *v69;
      ++vostok::render::g_num_monitors;
      (*(void (__stdcall **)(int *, char *))(v45 + 28))(v69, v58);
      ++v67;
      v46 = *v61;
      v69 = 0;
      v47 = *v46;
      ++v66;
      v64 += 512;
      v65 += 512;
      v28 = (*(int (__stdcall **)(int *, int, int **))(v47 + 28))(v46, v67, &v69);
    }
    while ( v28 != -2005270526 );
  }
  if ( (int)vostok::render::g_num_monitors <= 0 )
    vostok::debug::terminate("Monitor not found!");
}
