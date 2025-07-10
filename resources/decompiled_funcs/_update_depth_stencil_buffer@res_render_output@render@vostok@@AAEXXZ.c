void __usercall vostok::render::res_render_output::update_depth_stencil_buffer(
        vostok::render::res_render_output *this@<ecx>,
        int a2@<edi>)
{
  unsigned int v2; // ecx
  int x; // eax
  HRESULT v4; // eax
  const char *d3d11_error_string; // eax
  HRESULT v6; // eax
  const char *v7; // eax
  vostok::render::res_texture *texture; // eax
  vostok::render::res_texture *v9; // ecx
  int v10; // esi
  unsigned int v12; // [esp+Eh] [ebp-60h]
  bool v13; // [esp+12h] [ebp-5Ch]
  bool v14; // [esp+16h] [ebp-58h]
  bool do_debug_break; // [esp+21h] [ebp-4Dh] BYREF
  ID3D11Texture2D *depth_texture; // [esp+22h] [ebp-4Ch] BYREF
  D3D11_DEPTH_STENCIL_VIEW_DESC descDSV; // [esp+26h] [ebp-48h] BYREF
  D3D11_TEXTURE2D_DESC desc_depth; // [esp+3Eh] [ebp-30h] BYREF

  v2 = *(_DWORD *)(a2 + 148);
  desc_depth.Width = *(_DWORD *)(a2 + 144);
  x = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x;
  desc_depth.Height = v2;
  desc_depth.MipLevels = 1;
  desc_depth.ArraySize = 1;
  desc_depth.Format = DXGI_FORMAT_R24G8_TYPELESS;
  desc_depth.SampleDesc.Count = 1;
  desc_depth.SampleDesc.Quality = 0;
  desc_depth.Usage = D3D11_USAGE_DEFAULT;
  desc_depth.BindFlags = 72;
  desc_depth.CPUAccessFlags = 0;
  desc_depth.MiscFlags = 0;
  v4 = (*(int (__stdcall **)(int, D3D11_TEXTURE2D_DESC *, _DWORD, ID3D11Texture2D **))(*(_DWORD *)x + 20))(
         x,
         &desc_depth,
         0,
         &depth_texture);
  if ( !BYTE2(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_ids._M_impl._M_end_of_storage._M_data)
    && v4 < 0 )
  {
    do_debug_break = 1;
    d3d11_error_string = make_d3d11_error_string(v4);
    vostok::debug::on_error(
      &do_debug_break,
      process_error_true,
      (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_ids._M_impl._M_end_of_storage._M_data
    + 2,
      assert_untyped,
      "assertion_failed",
      d3d11_error_string,
      ".\\res_render_output.cpp",
      "vostok::render::res_render_output::update_depth_stencil_buffer",
      0x189u);
    if ( vostok::debug::is_debugger_present() || do_debug_break )
      __debugbreak();
  }
  memset(&descDSV.Flags, 0, 16);
  descDSV.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
  descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
  v6 = (*(int (__stdcall **)(int, ID3D11Texture2D *, D3D11_DEPTH_STENCIL_VIEW_DESC *, int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x
                                                                                          + 40))(
         `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
         depth_texture,
         &descDSV,
         a2 + 212);
  if ( !HIBYTE(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_ids._M_impl._M_end_of_storage._M_data)
    && v6 < 0 )
  {
    do_debug_break = 1;
    v7 = make_d3d11_error_string(v6);
    vostok::debug::on_error(
      &do_debug_break,
      process_error_true,
      (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_ids._M_impl._M_end_of_storage._M_data
    + 3,
      assert_untyped,
      "assertion_failed",
      v7,
      ".\\res_render_output.cpp",
      "vostok::render::res_render_output::update_depth_stencil_buffer",
      0x194u);
    if ( vostok::debug::is_debugger_present() || do_debug_break )
      __debugbreak();
  }
  v12 = depth_texture_id++;
  vostok::buffer_string::assignf((vostok::buffer_string *)(a2 + 4), "%s%d", "$user$depth", v12);
  texture = vostok::render::resource_manager::create_texture(
              (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
              (const char *)(a2 + 16),
              0,
              0,
              0,
              1,
              1,
              0xFFFFFFFF);
  v9 = 0;
  if ( texture )
  {
    ++texture->m_reference_count;
    v9 = texture;
  }
  v10 = *(_DWORD *)(a2 + 216);
  *(_DWORD *)(a2 + 216) = v9;
  if ( v10 )
  {
    if ( (*(_DWORD *)(v10 + 4))-- == 1 )
      vostok::render::res_texture::destroy_impl(v9);
  }
  vostok::render::res_texture::set_hw_texture(
    (vostok::render::res_texture *)depth_texture,
    depth_texture,
    0,
    0,
    v13,
    v14);
  depth_texture->Release(depth_texture);
}
