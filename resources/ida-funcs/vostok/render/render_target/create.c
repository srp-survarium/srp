void __thiscall vostok::render::render_target::create(
        vostok::render::render_target *this,
        const char *name,
        char *width,
        unsigned int height,
        DXGI_FORMAT format,
        DXGI_FORMAT usage,
        D3D11_USAGE memory_usage,
        unsigned int sample_count)
{
  unsigned int v8; // eax
  ID3D11Resource **v9; // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v10; // ecx
  bool has_passed_filters; // al
  bool *d3d11_error_string; // eax
  ID3D11Device *m_device; // eax
  ID3D11Device_vtbl *v14; // ecx
  HRESULT v15; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v16; // ecx
  ID3D11Device *v17; // eax
  ID3D11Device_vtbl *v18; // ecx
  bool *v19; // eax
  char *v20; // esi
  const char *v21; // edi
  int v22; // ecx
  bool v23; // cf
  bool v24; // zf
  int v25; // eax
  vostok::render::res_texture *texture; // eax
  vostok::render::resource_manager *v27; // esi
  int *v28; // ebx
  vostok::render::res_texture *v29; // ecx
  void *v30; // eax
  vostok::render::res_texture *v31; // ecx
  vostok::render::res_texture *v32; // eax
  ID3D11Resource *v33; // [esp+6h] [ebp-A0h]
  ID3D11Resource *v34; // [esp+6h] [ebp-A0h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v35; // [esp+1Ah] [ebp-8Ch]
  int v36; // [esp+1Ah] [ebp-8Ch]
  const char *v37; // [esp+1Eh] [ebp-88h]
  const char *v38; // [esp+22h] [ebp-84h]
  unsigned int v39; // [esp+26h] [ebp-80h]
  int v40; // [esp+2Eh] [ebp-78h] BYREF
  ID3D11Texture2D **v41; // [esp+32h] [ebp-74h]
  int v42; // [esp+36h] [ebp-70h]
  unsigned int row_min_pitch; // [esp+3Ah] [ebp-6Ch] BYREF
  _DWORD v44[6]; // [esp+3Eh] [ebp-68h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v45; // [esp+56h] [ebp-50h] BYREF
  unsigned __int8 dst[44]; // [esp+7Ah] [ebp-2Ch] BYREF

  v42 = 0;
  v41 = (ID3D11Texture2D **)(name + 12);
  if ( *((_DWORD *)name + 3) )
    return;
  *((_QWORD *)name + 7) = __rdtsc();
  if ( height > 0x4000
    || (unsigned int)format > 0x4000
    || memory_usage == D3D11_USAGE_DEFAULT
    && usage != DXGI_FORMAT_R24G8_TYPELESS
    && usage != DXGI_FORMAT_R16_TYPELESS
    && usage != DXGI_FORMAT_D24_UNORM_S8_UINT
    && usage != DXGI_FORMAT_D16_UNORM )
  {
    return;
  }
  v8 = vostok::render::utils::calc_surface_size(height, format, usage, &row_min_pitch);
  *((_DWORD *)name + 12) = v8;
  *((_DWORD *)name + 2) = sample_count;
  if ( !sample_count )
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst->m_render_target_video_memory += v8;
  *((_DWORD *)name + 8) = height;
  *((_DWORD *)name + 11) = memory_usage;
  *((_DWORD *)name + 9) = format;
  *((_DWORD *)name + 10) = usage;
  memset((int)dst, 0, sizeof(dst));
  *(_DWORD *)dst = height;
  *(_DWORD *)&dst[28] = sample_count;
  *(_DWORD *)&dst[4] = format;
  *(_DWORD *)&dst[16] = usage;
  v9 = v41;
  *(_DWORD *)&dst[32] = (memory_usage != D3D11_USAGE_DEFAULT ? 32 : 64) | 8;
  *(_DWORD *)&dst[8] = 1;
  *(_DWORD *)&dst[12] = 1;
  *(_DWORD *)&dst[20] = 1;
  row_min_pitch = vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreateTexture2D(
                    vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
                    (const D3D11_TEXTURE2D_DESC *)dst,
                    0,
                    v41);
  if ( (row_min_pitch & 0x80000000) != 0 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                 (const char *)2),
          v10 = v35,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v10,
        &v45);
      v42 = 1;
      vostok::logging::append(
        &v45,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\render_target.cpp",
        0x121u,
        "void __thiscall vostok::render::render_target::create(const char *,unsigned int,unsigned int,enum DXGI_FORMAT,en"
        "um vostok::render::enum_rt_usage,enum D3D11_USAGE,unsigned int)",
        (char *)&initiator_raw.initiator_tree,
        error,
        "failed to create render target %s %dx%d with format %d, usage: %d, mem usage: %d, sample count %d",
        width,
        height,
        format,
        usage,
        memory_usage,
        sample_count,
        1);
      v9 = v41;
    }
    if ( (v42 & 1) != 0 )
    {
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
        (int *)&v45);
      v9 = v41;
    }
  }
  if ( !ignore_always_19 && (row_min_pitch & 0x80000000) != 0 )
  {
    HIBYTE(v40) = 1;
    d3d11_error_string = (bool *)make_d3d11_error_string(row_min_pitch, v10);
    vostok::debug::on_error(
      (bool *)&v40 + 3,
      process_error_true,
      d3d11_error_string,
      ".\\render_target.cpp",
      "vostok::render::render_target::create",
      (const char *)0x124);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v40) )
      __debugbreak();
  }
  if ( memory_usage == D3D11_USAGE_DEFAULT )
  {
    memset(v44, 0, sizeof(v44));
    v44[0] = 0;
    v44[1] = 3;
    v44[3] = 0;
    switch ( *(_DWORD *)&dst[16] )
    {
      case '\'':
        v44[0] = 40;
        break;
      case ',':
        v44[0] = 45;
        break;
      case '5':
        v44[0] = 55;
        break;
    }
    if ( ignore_always_20
      || vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreateDepthStencilView(
           vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
           *v9,
           (const D3D11_DEPTH_STENCIL_VIEW_DESC *)v44,
           (ID3D11DepthStencilView **)(name + 24)) >= 0 )
    {
      goto LABEL_38;
    }
    m_device = vostok::quasi_singleton<vostok::render::device>::pinst->m_device;
    v14 = m_device->lpVtbl;
    v36 = 326;
    v33 = *v9;
    HIBYTE(v40) = 1;
    v15 = v14->CreateDepthStencilView(
            m_device,
            v33,
            (const D3D11_DEPTH_STENCIL_VIEW_DESC *)v44,
            (ID3D11DepthStencilView **)name + 6);
    goto LABEL_35;
  }
  if ( !ignore_always_21
    && vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreateRenderTargetView(
         vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
         *v9,
         0,
         (ID3D11RenderTargetView **)(name + 20)) < 0 )
  {
    v17 = vostok::quasi_singleton<vostok::render::device>::pinst->m_device;
    v18 = v17->lpVtbl;
    v36 = 339;
    v34 = *v9;
    HIBYTE(v40) = 1;
    v15 = v18->CreateRenderTargetView(v17, v34, 0, (ID3D11RenderTargetView **)name + 5);
LABEL_35:
    v19 = (bool *)make_d3d11_error_string(v15, v16);
    vostok::debug::on_error(
      (bool *)&v40 + 3,
      process_error_true,
      v19,
      ".\\render_target.cpp",
      "vostok::render::render_target::create",
      (const char *)v36);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v40) )
      __debugbreak();
  }
LABEL_38:
  if ( width )
  {
    v20 = width;
    v21 = "null";
    v22 = 5;
    v25 = 0;
    v23 = 0;
    v24 = 1;
    do
    {
      if ( !v22 )
        break;
      v23 = (unsigned __int8)*v20 < (unsigned int)*v21;
      v24 = *v20++ == *v21++;
      --v22;
    }
    while ( v24 );
    if ( !v24 )
      v25 = -v23 - (v23 - 1);
    if ( v25 )
    {
      v27 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
      texture = (vostok::render::res_texture *)vostok::render::resource_manager::find_texture(
                                                 (vostok::render::resource_manager *)v22,
                                                 (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                                                 width);
      if ( !texture )
        texture = vostok::render::resource_manager::load_texture(v27, width, 0, 0, 0, 1, 1, 0xFFFFFFFF, 1, 0);
    }
    else
    {
      texture = 0;
    }
    v28 = (int *)(name + 28);
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      texture,
      (vostok::render::res_texture *)(name + 28));
  }
  else
  {
    v30 = vostok::memory::new_helper<vostok::render::res_texture>::call<vostok::memory::doug_lea_allocator>(
            vostok::render::g_allocator,
            v37,
            v38,
            v39);
    if ( v30 )
      vostok::render::res_texture::res_texture(v31, (int)v30, 0);
    else
      v32 = 0;
    v28 = (int *)(name + 28);
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      v32,
      (vostok::render::res_texture *)(name + 28));
    vostok::render::res_texture::set_name(*((vostok::render::res_texture **)name + 7), 0);
    *(_BYTE *)(*((_DWORD *)name + 7) + 459) = 1;
  }
  vostok::render::res_texture::set_hw_texture(v29, *v28, *v41, 0, 0, 0, (bool)v37);
}
