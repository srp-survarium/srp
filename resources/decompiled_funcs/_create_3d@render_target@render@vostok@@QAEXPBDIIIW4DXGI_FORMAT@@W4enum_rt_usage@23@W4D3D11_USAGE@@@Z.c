void __userpurge vostok::render::render_target::create_3d(
        unsigned int width@<ecx>,
        unsigned int height@<eax>,
        vostok::render::render_target *this,
        const char *name,
        unsigned int depth,
        DXGI_FORMAT format,
        vostok::render::enum_rt_usage usage,
        D3D11_USAGE memory_usage)
{
  DXGI_FORMAT v8; // ebx
  vostok::render::render_target *v9; // ebp
  unsigned int v12; // eax
  survarium::options_tab *v13; // ecx
  unsigned int v14; // edi
  int x; // eax
  HRESULT v16; // eax
  const char *d3d11_error_string; // eax
  int v18; // eax
  ID3D11Texture3D *m_surface_3d; // ecx
  HRESULT v20; // eax
  const char *v21; // eax
  vostok::render::res_texture *texture; // eax
  vostok::render::res_texture *v23; // ecx
  vostok::render::res_texture *m_object; // esi
  bool v25; // zf
  vostok::render::res_texture *v26; // ecx
  vostok::render::res_texture *v27; // eax
  vostok::render::res_texture *v28; // esi
  vostok::render::res_texture *v29; // esi
  char *m_begin; // eax
  vostok::buffer_string *p_m_string; // esi
  bool v32; // [esp+20h] [ebp-4Ch]
  bool v33; // [esp+24h] [ebp-48h]
  D3D11_RENDER_TARGET_VIEW_DESC desc_rt; // [esp+30h] [ebp-3Ch] BYREF
  D3D11_TEXTURE3D_DESC desc; // [esp+44h] [ebp-28h] BYREF

  v8 = format;
  v9 = this;
  if ( !this->m_surface_3d )
  {
    v12 = vostok::render::utils::calc_surface_size(width, height, format, (unsigned int *)&format);
    v13 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
    v9->m_memory_usage = v12;
    *(_DWORD *)&v13[1].m_options_count += v12;
    desc.Width = width;
    v14 = depth;
    desc.CPUAccessFlags = 0;
    desc.MiscFlags = 0;
    desc.Height = height;
    desc.Depth = depth;
    desc.MipLevels = 1;
    desc.Format = v8;
    desc.Usage = D3D11_USAGE_DEFAULT;
    desc.BindFlags = 40;
    if ( !BYTE1(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_to_bind)
      && (*(int (__stdcall **)(int, D3D11_TEXTURE3D_DESC *, _DWORD, ID3D11Texture3D **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x
                                                                                       + 24))(
           `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
           &desc,
           0,
           &v9->m_surface_3d) < 0 )
    {
      x = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x;
      LOBYTE(format) = 1;
      v16 = (*(int (__stdcall **)(int, D3D11_TEXTURE3D_DESC *, _DWORD, ID3D11Texture3D **))(*(_DWORD *)x + 24))(
              x,
              &desc,
              0,
              &v9->m_surface_3d);
      d3d11_error_string = make_d3d11_error_string(v16);
      vostok::debug::on_error(
        (bool *)&format,
        process_error_true,
        (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_to_bind
      + 1,
        assert_untyped,
        "assertion_failed",
        d3d11_error_string,
        ".\\render_target.cpp",
        "vostok::render::render_target::create_3d",
        0x5Cu);
      if ( vostok::debug::is_debugger_present() || (_BYTE)format )
        __debugbreak();
    }
    desc_rt.Format = v8;
    desc_rt.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE3D;
    desc_rt.Buffer = 0;
    desc_rt.Texture1DArray.ArraySize = v14;
    if ( !BYTE2(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_to_bind)
      && (*(int (__stdcall **)(int, ID3D11Texture3D *, D3D11_RENDER_TARGET_VIEW_DESC *, ID3D11RenderTargetView **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x + 36))(
           `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
           v9->m_surface_3d,
           &desc_rt,
           &v9->m_rt) < 0 )
    {
      v18 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x;
      m_surface_3d = v9->m_surface_3d;
      LOBYTE(this) = 1;
      v20 = (*(int (__stdcall **)(int, ID3D11Texture3D *, D3D11_RENDER_TARGET_VIEW_DESC *, ID3D11RenderTargetView **))(*(_DWORD *)v18 + 36))(
              v18,
              m_surface_3d,
              &desc_rt,
              &v9->m_rt);
      v21 = make_d3d11_error_string(v20);
      vostok::debug::on_error(
        (bool *)&this,
        process_error_true,
        (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_to_bind
      + 2,
        assert_untyped,
        "assertion_failed",
        v21,
        ".\\render_target.cpp",
        "vostok::render::render_target::create_3d",
        0x66u);
      if ( vostok::debug::is_debugger_present() || (_BYTE)this )
        __debugbreak();
    }
    if ( name )
    {
      texture = vostok::render::resource_manager::create_texture(
                  (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                  name,
                  0,
                  0,
                  0,
                  1,
                  1,
                  0xFFFFFFFF);
      v23 = 0;
      if ( texture )
      {
        ++texture->m_reference_count;
        v23 = texture;
      }
      m_object = v9->m_texture.m_object;
      v9->m_texture.m_object = v23;
      if ( m_object )
      {
        v25 = m_object->m_reference_count-- == 1;
        if ( v25 )
          vostok::render::res_texture::destroy_impl(v23);
      }
    }
    else
    {
      if ( vostok::memory::doug_lea_allocator::malloc_impl(
             (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
             0x1BCu) )
      {
        vostok::render::res_texture::res_texture(v26, 0);
      }
      else
      {
        v27 = 0;
      }
      v23 = 0;
      if ( v27 )
      {
        ++v27->m_reference_count;
        v23 = v27;
      }
      v28 = v9->m_texture.m_object;
      v9->m_texture.m_object = v23;
      if ( v28 )
      {
        v25 = v28->m_reference_count-- == 1;
        if ( v25 )
          vostok::render::res_texture::destroy_impl(v23);
      }
      v29 = v9->m_texture.m_object;
      m_begin = v29->m_name.m_string.m_begin;
      p_m_string = &v29->m_name.m_string;
      if ( m_begin )
      {
        p_m_string->m_end = m_begin;
        *m_begin = 0;
        vostok::buffer_string::operator+=(p_m_string, 0);
      }
      v9->m_texture.m_object->m_is_registered = 1;
    }
    vostok::render::res_texture::set_hw_texture(v23, v9->m_surface_3d, 0, 0, v32, v33);
  }
}
