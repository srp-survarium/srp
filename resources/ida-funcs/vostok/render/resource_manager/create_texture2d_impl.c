vostok::render::res_texture *__userpurge vostok::render::resource_manager::create_texture2d_impl@<eax>(
        vostok::render::resource_manager *this@<ecx>,
        unsigned int width,
        unsigned int height,
        const D3D11_SUBRESOURCE_DATA *data,
        DXGI_FORMAT format,
        D3D11_USAGE usage,
        unsigned int mip_levels,
        unsigned int array_size,
        bool use_for_render_target)
{
  HRESULT v10; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // ecx
  bool *d3d11_error_string; // eax
  void *v13; // eax
  vostok::render::res_texture *v14; // ecx
  int v15; // esi
  int v16; // eax
  vostok::render::res_texture *v17; // [esp-4h] [ebp-40h]
  const char *v18; // [esp+0h] [ebp-3Ch]
  bool v19; // [esp+0h] [ebp-3Ch]
  const char *v20; // [esp+4h] [ebp-38h]
  unsigned int v21; // [esp+8h] [ebp-34h]
  unsigned __int8 dst[44]; // [esp+Ch] [ebp-30h] BYREF
  ID3D11Resource *surface; // [esp+38h] [ebp-4h] BYREF

  if ( vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_no_render_targets) )
    return 0;
  memset((int)dst, 0, sizeof(dst));
  *(_DWORD *)dst = width;
  *(_DWORD *)&dst[4] = height;
  *(_DWORD *)&dst[8] = mip_levels;
  *(_DWORD *)&dst[16] = format;
  *(_DWORD *)&dst[20] = 1;
  *(_DWORD *)&dst[24] = 0;
  *(_DWORD *)&dst[28] = usage;
  *(_DWORD *)&dst[12] = 1;
  *(_DWORD *)&dst[32] = ((unsigned __int8)array_size != 0 ? 0x20 : 0) | (usage != D3D11_USAGE_STAGING ? 8 : 0);
  if ( usage == D3D11_USAGE_DYNAMIC )
  {
    *(_DWORD *)&dst[36] = &_sbh_sizeHeaderList;
  }
  else
  {
    *(_DWORD *)&dst[36] = &loc_20000;
    if ( usage != D3D11_USAGE_STAGING )
      *(_DWORD *)&dst[36] = 0;
  }
  v10 = vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreateTexture2D(
          vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
          (const D3D11_TEXTURE2D_DESC *)dst,
          data,
          (ID3D11Texture2D **)&surface);
  if ( !ignore_always_9 && v10 < 0 )
  {
    HIBYTE(array_size) = 1;
    d3d11_error_string = (bool *)make_d3d11_error_string(v10, v11);
    vostok::debug::on_error(
      (bool *)&array_size + 3,
      process_error_true,
      d3d11_error_string,
      ".\\resource_manager.cpp",
      "vostok::render::resource_manager::create_texture2d_impl",
      (const char *)0xCEC);
    if ( vostok::debug::is_debugger_present() || HIBYTE(array_size) )
      __debugbreak();
  }
  v13 = vostok::memory::new_helper<vostok::render::res_texture>::call<vostok::memory::doug_lea_allocator>(
          vostok::render::g_allocator,
          v18,
          v20,
          v21);
  v15 = 0;
  if ( v13 )
  {
    vostok::render::res_texture::res_texture(v14, (int)v13, 0);
    v15 = v16;
  }
  *(_DWORD *)(v15 + 64) = vostok::render::utils::calc_surface_size(width, height, format, &array_size);
  vostok::render::res_texture::set_hw_texture(v17, v15, surface, 0, usage == D3D11_USAGE_STAGING, 0, v19);
  surface->Release(surface);
  return (vostok::render::res_texture *)v15;
}
