void __thiscall vostok::render::device::create(vostok::render::device *this, UINT Flags)
{
  UINT v2; // ebx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v3; // ecx
  int **v4; // esi
  int v5; // ecx
  HRESULT v6; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // ecx
  bool *d3d11_error_string; // eax
  bool has_passed_filters; // al
  D3D_DRIVER_TYPE v10; // ecx
  bool v11; // al
  bool v12; // zf
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v13; // ecx
  const char *Device; // edi
  bool *v15; // eax
  int v16; // esi
  int *v17; // [esp-14h] [ebp-190h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v18; // [esp-4h] [ebp-180h]
  D3D_DRIVER_TYPE v19; // [esp-4h] [ebp-180h]
  unsigned __int8 dst[296]; // [esp+10h] [ebp-16Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v21; // [esp+138h] [ebp-44h] BYREF
  D3D_FEATURE_LEVEL pFeatureLevels[6]; // [esp+15Ch] [ebp-20h] BYREF
  int v23; // [esp+174h] [ebp-8h]

  v23 = 0;
  v2 = Flags;
  vostok::render::device::create_d3d(this, Flags);
  memset((int)dst, 0, 0x124u);
  if ( !ignore_always_2 )
  {
    v4 = (int **)(v2 + 300);
    if ( (*(int (__stdcall **)(_DWORD, unsigned __int8 *))(**(_DWORD **)(v2 + 300) + 32))(*(_DWORD *)(v2 + 300), dst) < 0 )
    {
      v5 = **v4;
      v17 = *v4;
      HIBYTE(Flags) = 1;
      v6 = (*(int (__stdcall **)(int *, unsigned __int8 *))(v5 + 32))(v17, dst);
      d3d11_error_string = (bool *)make_d3d11_error_string(v6, v7);
      vostok::debug::on_error(
        (bool *)&Flags + 3,
        process_error_true,
        d3d11_error_string,
        ".\\device.cpp",
        "vostok::render::device::create",
        (const char *)0xFB);
      if ( vostok::debug::is_debugger_present() || HIBYTE(Flags) )
        __debugbreak();
    }
  }
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                               (const char *)4),
        v3 = v18,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v3,
      &v21);
    v23 = 1;
    vostok::logging::append(
      &v21,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\device.cpp",
      0xFDu,
      "void __thiscall vostok::render::device::create(void)",
      (char *)&initiator_raw.initiator_tree,
      info,
      "* gpu [vendor:%X]-[device:%X]: %S",
      *(_DWORD *)&dst[256],
      *(_DWORD *)&dst[260],
      (const wchar_t *)dst);
  }
  if ( (v23 & 1) != 0 )
  {
    v23 &= ~1u;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v3,
      (int *)&v21);
  }
  Flags = vostok::command_line::key::is_set((vostok::command_line::key *)v3, (int)&g_st_device);
  if ( vostok::command_line::key::is_set((vostok::command_line::key *)Flags, (int)&g_debug_render_device) )
    Flags |= 2u;
  v10 = D3D_DRIVER_TYPE_HARDWARE;
  if ( *(_BYTE *)(v2 + 357) )
  {
    if ( !vostok::core::g_log_filter_tree
      || (v11 = vostok::logging::has_passed_filters(
                  (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                  (const char *)3),
          v10 = v19,
          v11) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v10,
        &v21);
      v23 |= 2u;
      vostok::logging::append(
        &v21,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\device.cpp",
        0x108u,
        "void __thiscall vostok::render::device::create(void)",
        (char *)&initiator_raw.initiator_tree,
        warning,
        "using reference d3d device");
    }
    if ( (v23 & 2) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
        (int *)&v21);
    v10 = D3D_DRIVER_TYPE_REFERENCE;
  }
  v12 = *(_BYTE *)(v2 + 357) == 0;
  pFeatureLevels[0] = D3D_FEATURE_LEVEL_11_0;
  pFeatureLevels[1] = D3D_FEATURE_LEVEL_10_1;
  pFeatureLevels[2] = D3D_FEATURE_LEVEL_10_0;
  pFeatureLevels[3] = D3D_FEATURE_LEVEL_9_3;
  pFeatureLevels[4] = D3D_FEATURE_LEVEL_9_2;
  pFeatureLevels[5] = D3D_FEATURE_LEVEL_9_1;
  if ( v12 )
    v10 = D3D_DRIVER_TYPE_UNKNOWN;
  v23 = v2 + 304;
  Device = (const char *)D3D11CreateDevice(
                           *(IDXGIAdapter **)(v2 + 300),
                           v10,
                           0,
                           Flags,
                           pFeatureLevels,
                           6u,
                           7u,
                           (ID3D11Device **)(v2 + 304),
                           (D3D_FEATURE_LEVEL *)(v2 + 292),
                           (ID3D11DeviceContext **)(v2 + 308));
  if ( (int)Device < 0 )
  {
    if ( !ignore_always_3 )
    {
      HIBYTE(Flags) = 1;
      v15 = (bool *)make_d3d11_error_string((HRESULT)Device, v13);
      vostok::debug::on_error(
        (bool *)&Flags + 3,
        process_error_true,
        v15,
        ".\\device.cpp",
        "vostok::render::device::create",
        (const char *)0x12D);
      if ( vostok::debug::is_debugger_present() || HIBYTE(Flags) )
        __debugbreak();
    }
    if ( !debug_macro_helper_ignore_always_57 )
    {
      HIBYTE(Flags) = 0;
      vostok::debug::on_error(
        (bool *)&Flags + 3,
        process_error_true,
        0,
        "assertion_failed",
        "fatal error",
        ".\\device.cpp",
        "vostok::render::device::create",
        (const char *)0x130,
        "failed to initialize graphics hardware.\nplease try to restart the game.\nCreateDevice returned 0x%08x",
        Device);
      if ( vostok::debug::is_debugger_present() || HIBYTE(Flags) )
        __debugbreak();
    }
  }
  _LN157_0(*(D3D_FEATURE_LEVEL *)(v2 + 292));
  v16 = *(_DWORD *)v23;
  Flags = (UINT)"* create: deviceref:";
  (*(void (__stdcall **)(int))(*(_DWORD *)v16 + 4))(v16);
  (*(void (__stdcall **)(int))(*(_DWORD *)v16 + 8))(v16);
}
