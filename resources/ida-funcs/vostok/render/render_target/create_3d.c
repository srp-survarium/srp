void __userpurge vostok::render::render_target::create_3d(
        vostok::render::render_target *this@<ecx>,
        const char *name,
        char *width,
        unsigned int height,
        unsigned int depth,
        DXGI_FORMAT format,
        vostok::render::enum_rt_usage usage,
        D3D11_USAGE memory_usage)
{
  unsigned int v8; // eax
  ID3D11Device_vtbl *v9; // ecx
  HRESULT v10; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // ecx
  bool *d3d11_error_string; // eax
  ID3D11Texture3D **v13; // edi
  ID3D11Device *v14; // eax
  ID3D11Device_vtbl *v15; // ecx
  HRESULT v16; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v17; // ecx
  bool *v18; // eax
  char *v19; // esi
  const char *v20; // edi
  int v21; // ecx
  bool v22; // cf
  bool v23; // zf
  int v24; // eax
  vostok::render::res_texture *texture; // eax
  int *v26; // edi
  vostok::render::res_texture *v27; // ecx
  void *v28; // eax
  vostok::render::res_texture *v29; // ecx
  vostok::render::res_texture *v30; // eax
  ID3D11Device *m_device; // [esp+16h] [ebp-6Ch]
  ID3D11Texture3D *v32; // [esp+1Ah] [ebp-68h]
  const char *v33; // [esp+32h] [ebp-50h]
  const char *v34; // [esp+36h] [ebp-4Ch]
  unsigned int v35; // [esp+3Ah] [ebp-48h]
  char v36; // [esp+41h] [ebp-41h] BYREF
  ID3D11Texture3D **v37; // [esp+42h] [ebp-40h]
  unsigned int row_min_pitch; // [esp+46h] [ebp-3Ch] BYREF
  _DWORD v39[5]; // [esp+4Ah] [ebp-38h] BYREF
  _DWORD v40[9]; // [esp+5Eh] [ebp-24h] BYREF

  v37 = (ID3D11Texture3D **)(name + 16);
  if ( !*((_DWORD *)name + 4) )
  {
    *((_DWORD *)name + 2) = 0;
    v8 = vostok::render::utils::calc_surface_size(0x10u, 0x10u, DXGI_FORMAT_B8G8R8A8_UNORM, &row_min_pitch);
    *((_DWORD *)name + 12) = v8;
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst->m_render_target_video_memory += v8;
    memset(v40, 0, sizeof(v40));
    v40[0] = 16;
    v40[1] = 16;
    v40[2] = 16;
    v40[3] = 1;
    v40[4] = 87;
    v40[5] = 0;
    v40[6] = 40;
    if ( !ignore_always_15
      && vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreateTexture3D(
           vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
           (const D3D11_TEXTURE3D_DESC *)v40,
           0,
           v37) < 0 )
    {
      v9 = vostok::quasi_singleton<vostok::render::device>::pinst->m_device->lpVtbl;
      m_device = vostok::quasi_singleton<vostok::render::device>::pinst->m_device;
      v36 = 1;
      v10 = v9->CreateTexture3D(m_device, (const D3D11_TEXTURE3D_DESC *)v40, 0, v37);
      d3d11_error_string = (bool *)make_d3d11_error_string(v10, v11);
      vostok::debug::on_error(
        (bool *)&v36,
        process_error_true,
        d3d11_error_string,
        ".\\render_target.cpp",
        "vostok::render::render_target::create_3d",
        (const char *)0x6A);
      if ( vostok::debug::is_debugger_present() || v36 )
        __debugbreak();
    }
    v39[0] = 87;
    v39[1] = 8;
    v39[2] = 0;
    v39[3] = 0;
    v39[4] = 16;
    if ( !ignore_always_16 )
    {
      v13 = v37;
      if ( vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreateRenderTargetView(
             vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
             *v37,
             (const D3D11_RENDER_TARGET_VIEW_DESC *)v39,
             (ID3D11RenderTargetView **)(name + 20)) < 0 )
      {
        v14 = vostok::quasi_singleton<vostok::render::device>::pinst->m_device;
        v15 = v14->lpVtbl;
        v32 = *v13;
        v36 = 1;
        v16 = v15->CreateRenderTargetView(
                v14,
                v32,
                (const D3D11_RENDER_TARGET_VIEW_DESC *)v39,
                (ID3D11RenderTargetView **)name + 5);
        v18 = (bool *)make_d3d11_error_string(v16, v17);
        vostok::debug::on_error(
          (bool *)&v36,
          process_error_true,
          v18,
          ".\\render_target.cpp",
          "vostok::render::render_target::create_3d",
          (const char *)0x74);
        if ( vostok::debug::is_debugger_present() || v36 )
          __debugbreak();
      }
    }
    if ( width )
    {
      v19 = width;
      v20 = "null";
      v21 = 5;
      v24 = 0;
      v22 = 0;
      v23 = 1;
      do
      {
        if ( !v21 )
          break;
        v22 = (unsigned __int8)*v19 < (unsigned int)*v20;
        v23 = *v19++ == *v20++;
        --v21;
      }
      while ( v23 );
      if ( !v23 )
        v24 = -v22 - (v22 - 1);
      if ( v24 )
      {
        texture = (vostok::render::res_texture *)vostok::render::resource_manager::find_texture(
                                                   (vostok::render::resource_manager *)v21,
                                                   (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                                                   width);
        if ( !texture )
          texture = vostok::render::resource_manager::load_texture(
                      vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                      width,
                      0,
                      0,
                      0,
                      1,
                      1,
                      0xFFFFFFFF,
                      1,
                      0);
      }
      else
      {
        texture = 0;
      }
      v26 = (int *)(name + 28);
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
        texture,
        (vostok::render::res_texture *)(name + 28));
    }
    else
    {
      v28 = vostok::memory::new_helper<vostok::render::res_texture>::call<vostok::memory::doug_lea_allocator>(
              vostok::render::g_allocator,
              v33,
              v34,
              v35);
      if ( v28 )
        vostok::render::res_texture::res_texture(v29, (int)v28, 0);
      else
        v30 = 0;
      v26 = (int *)(name + 28);
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
        v30,
        (vostok::render::res_texture *)(name + 28));
      vostok::render::res_texture::set_name(*((vostok::render::res_texture **)name + 7), 0);
      *(_BYTE *)(*((_DWORD *)name + 7) + 459) = 1;
    }
    vostok::render::res_texture::set_hw_texture(v27, *v26, *v37, 0, 0, 0, (bool)v33);
  }
}
