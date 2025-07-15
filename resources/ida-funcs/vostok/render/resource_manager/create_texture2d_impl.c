vostok::render::res_texture *__userpurge vostok::render::resource_manager::create_texture2d_impl@<eax>(
        D3D11_USAGE usage@<edi>,
        vostok::render::resource_manager *this,
        unsigned int width,
        ID3D11Texture2D *height,
        const D3D11_SUBRESOURCE_DATA *data,
        DXGI_FORMAT format,
        unsigned int mip_levels,
        unsigned int array_size,
        bool use_for_render_target)
{
  ID3D11Texture2D *v9; // ebp
  HRESULT v10; // eax
  const char *d3d11_error_string; // eax
  void *v12; // eax
  vostok::render::res_texture *v13; // ecx
  int v14; // eax
  int v15; // esi
  bool v17; // [esp+0h] [ebp-38h]
  bool v18; // [esp+4h] [ebp-34h]
  D3D11_TEXTURE2D_DESC texure_desc; // [esp+Ch] [ebp-2Ch] BYREF

  v9 = height;
  memset((int)&texure_desc, 0, sizeof(texure_desc));
  texure_desc.Width = (unsigned int)this;
  texure_desc.Height = width;
  texure_desc.Format = (DXGI_FORMAT)height;
  texure_desc.SampleDesc.Count = 1;
  texure_desc.SampleDesc.Quality = 0;
  texure_desc.Usage = usage;
  texure_desc.MipLevels = (unsigned int)data;
  texure_desc.ArraySize = 1;
  texure_desc.BindFlags = ((unsigned __int8)format != DXGI_FORMAT_UNKNOWN ? 0x20 : 0)
                        | (usage != D3D11_USAGE_STAGING ? 8 : 0);
  if ( usage == D3D11_USAGE_DYNAMIC )
    texure_desc.CPUAccessFlags = (unsigned int)&_sbh_sizeHeaderList;
  else
    texure_desc.CPUAccessFlags = usage != D3D11_USAGE_STAGING ? 0 : (unsigned int)&loc_20000;
  v10 = (*(int (__stdcall **)(int, D3D11_TEXTURE2D_DESC *, _DWORD, ID3D11Texture2D **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x
                                                                                      + 20))(
          `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
          &texure_desc,
          0,
          &height);
  if ( !LOBYTE(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_waiting_for_bind_action)
    && v10 < 0 )
  {
    LOBYTE(format) = 1;
    d3d11_error_string = make_d3d11_error_string(v10);
    vostok::debug::on_error(
      (bool *)&format,
      process_error_true,
      (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_waiting_for_bind_action,
      assert_untyped,
      "assertion_failed",
      d3d11_error_string,
      ".\\resource_manager.cpp",
      "vostok::render::resource_manager::create_texture2d_impl",
      0x9BAu);
    if ( vostok::debug::is_debugger_present() || (_BYTE)format )
      __debugbreak();
  }
  v12 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
          0x1BCu);
  if ( v12 )
  {
    vostok::render::res_texture::res_texture(v13, (int)v12, 0);
    v15 = v14;
  }
  else
  {
    v15 = 0;
  }
  *(_DWORD *)(v15 + 52) = vostok::render::utils::calc_surface_size(
                            (unsigned int)this,
                            width,
                            (DXGI_FORMAT)v9,
                            (unsigned int *)&format);
  vostok::render::res_texture::set_hw_texture(
    (vostok::render::res_texture *)(usage == D3D11_USAGE_STAGING),
    v15,
    height,
    0,
    usage == D3D11_USAGE_STAGING,
    v17,
    v18);
  height->Release(height);
  return (vostok::render::res_texture *)v15;
}
