vostok::render::res_texture *__userpurge vostok::render::resource_manager::create_texture3d@<eax>(
        const D3D11_SUBRESOURCE_DATA *data@<ecx>,
        DXGI_FORMAT format@<eax>,
        vostok::render::resource_manager *this,
        const char *user_name,
        unsigned int width,
        unsigned int height,
        unsigned int depth,
        D3D11_USAGE usage,
        unsigned int mip_levels)
{
  int x; // eax
  HRESULT v12; // eax
  const char *d3d11_error_string; // eax
  void *v14; // eax
  vostok::render::res_texture *v15; // ecx
  int v16; // eax
  int v17; // esi
  const char *v18; // eax
  bool v20; // [esp+Ch] [ebp-16Ch]
  bool v21; // [esp+10h] [ebp-168h]
  bool do_debug_break; // [esp+20h] [ebp-158h] BYREF
  ID3D11Texture3D *d3d_texture; // [esp+24h] [ebp-154h] BYREF
  unsigned int src_row_pitch; // [esp+28h] [ebp-150h] BYREF
  vostok::render::render_target *v25; // [esp+2Ch] [ebp-14Ch]
  D3D11_TEXTURE3D_DESC desc; // [esp+30h] [ebp-148h] BYREF
  stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >,bool> v27; // [esp+54h] [ebp-124h] BYREF
  stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> v28; // [esp+5Ch] [ebp-11Ch] BYREF

  desc.Width = width;
  desc.Height = height;
  desc.Depth = depth;
  desc.MipLevels = 1;
  desc.Format = format;
  desc.Usage = usage;
  desc.BindFlags = 8;
  if ( usage == D3D11_USAGE_IMMUTABLE )
  {
    desc.CPUAccessFlags = 0;
  }
  else if ( usage == D3D11_USAGE_DYNAMIC )
  {
    desc.CPUAccessFlags = (unsigned int)&_sbh_sizeHeaderList;
  }
  desc.MiscFlags = 0;
  d3d_texture = 0;
  if ( !BYTE1(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_waiting_for_bind_action)
    && (*(int (__stdcall **)(int, D3D11_TEXTURE3D_DESC *, const D3D11_SUBRESOURCE_DATA *, ID3D11Texture3D **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x + 24))(
         `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
         &desc,
         data,
         &d3d_texture) < 0 )
  {
    x = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x;
    do_debug_break = 1;
    v12 = (*(int (__stdcall **)(int, D3D11_TEXTURE3D_DESC *, const D3D11_SUBRESOURCE_DATA *, ID3D11Texture3D **))(*(_DWORD *)x + 24))(
            x,
            &desc,
            data,
            &d3d_texture);
    d3d11_error_string = make_d3d11_error_string(v12);
    vostok::debug::on_error(
      &do_debug_break,
      process_error_true,
      (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_waiting_for_bind_action
    + 1,
      assert_untyped,
      "assertion_failed",
      d3d11_error_string,
      ".\\resource_manager.cpp",
      "vostok::render::resource_manager::create_texture3d",
      0xA13u);
    if ( vostok::debug::is_debugger_present() || do_debug_break )
      __debugbreak();
  }
  v14 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
          0x1BCu);
  if ( v14 )
  {
    vostok::render::res_texture::res_texture(v15, (int)v14, 0);
    v17 = v16;
  }
  else
  {
    v17 = 0;
  }
  *(_DWORD *)(v17 + 52) = depth * vostok::render::utils::calc_surface_size(width, height, format, &src_row_pitch);
  v18 = *(const char **)(v17 + 144);
  if ( v18 != user_name )
  {
    *(_DWORD *)(v17 + 148) = v18;
    *v18 = 0;
    vostok::buffer_string::operator+=((vostok::buffer_string *)(v17 + 144), user_name);
  }
  src_row_pitch = *(_DWORD *)(v17 + 144);
  v25 = (vostok::render::render_target *)v17;
  vostok::fs_new::virtual_path_string::virtual_path_string(
    (vostok::fs_new::virtual_path_string *)&v28.first,
    (const char **)&src_row_pitch);
  v28.second = v25;
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::render_target *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::render_target *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::render_target *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *>>>::insert_unique(
    &v28,
    (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&this->m_texture_registry,
    &v27);
  *(_BYTE *)(v17 + 439) = 1;
  vostok::render::res_texture::set_hw_texture(
    (vostok::render::res_texture *)d3d_texture,
    v17,
    d3d_texture,
    0,
    usage == D3D11_USAGE_STAGING,
    v20,
    v21);
  d3d_texture->Release(d3d_texture);
  return (vostok::render::res_texture *)v17;
}
