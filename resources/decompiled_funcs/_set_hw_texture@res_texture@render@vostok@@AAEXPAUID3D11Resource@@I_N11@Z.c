void __userpurge vostok::render::res_texture::set_hw_texture(
        vostok::render::res_texture *this@<ecx>,
        int a2@<eax>,
        ID3D11Resource *surface,
        unsigned int mip_level_cut,
        bool staging,
        bool srgb,
        bool depth_stencil)
{
  ID3D11Resource *v7; // ebp
  int v9; // eax
  int v10; // eax
  _DWORD *v11; // edi
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // eax
  DXGI_FORMAT v15; // eax
  int v16; // eax
  int v17; // ecx
  HRESULT v18; // eax
  int v19; // eax
  int v20; // edx
  HRESULT v21; // eax
  int x; // eax
  int v23; // ecx
  HRESULT v24; // eax
  bool *v25; // [esp-8h] [ebp-44h]
  const char *d3d11_error_string; // [esp+4h] [ebp-38h]
  const char *v27; // [esp+4h] [ebp-38h]
  unsigned int v28; // [esp+10h] [ebp-2Ch]
  D3D11_SHADER_RESOURCE_VIEW_DESC view_desc; // [esp+24h] [ebp-18h] BYREF

  v7 = surface;
  if ( surface )
    surface->AddRef(surface);
  *(_DWORD *)(a2 + 432) = mip_level_cut;
  v9 = *(_DWORD *)(a2 + 420);
  if ( v9 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v9 + 8))(*(_DWORD *)(a2 + 420));
    *(_DWORD *)(a2 + 420) = 0;
  }
  v10 = *(_DWORD *)(a2 + 428);
  v11 = (_DWORD *)(a2 + 428);
  if ( v10 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v10 + 8))(*(_DWORD *)(a2 + 428));
    *v11 = 0;
  }
  *(_DWORD *)(a2 + 420) = v7;
  *(_BYTE *)(a2 + 436) = 0;
  *(_BYTE *)(a2 + 437) = 0;
  if ( v7 )
  {
    vostok::render::res_texture::desc_update(this, a2);
    (*(void (__stdcall **)(_DWORD, ID3D11Resource **))(**(_DWORD **)(a2 + 420) + 28))(*(_DWORD *)(a2 + 420), &surface);
    if ( surface != (ID3D11Resource *)3 )
    {
      if ( surface != (ID3D11Resource *)4 )
      {
        if ( HIBYTE(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_key_name)
          || (*(int (__stdcall **)(int, _DWORD, _DWORD, int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x
                                                            + 28))(
               `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
               *(_DWORD *)(a2 + 420),
               0,
               a2 + 428) >= 0 )
        {
          return;
        }
        x = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x;
        v23 = *(_DWORD *)(a2 + 420);
        v28 = 246;
        staging = 1;
        v24 = (*(int (__stdcall **)(int, int, _DWORD, int))(*(_DWORD *)x + 28))(x, v23, 0, a2 + 428);
        d3d11_error_string = make_d3d11_error_string(v24);
        v25 = (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_key_name
            + 3;
        goto LABEL_37;
      }
      if ( !staging )
      {
        if ( BYTE2(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_key_name)
          || (*(int (__stdcall **)(int, _DWORD, _DWORD, int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x
                                                            + 28))(
               `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
               *(_DWORD *)(a2 + 420),
               0,
               a2 + 428) >= 0 )
        {
          return;
        }
        v19 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x;
        v20 = *(_DWORD *)(a2 + 420);
        staging = 1;
        v21 = (*(int (__stdcall **)(int, int, _DWORD, int))(*(_DWORD *)v19 + 28))(v19, v20, 0, a2 + 428);
        v27 = make_d3d11_error_string(v21);
        vostok::debug::on_error(
          &staging,
          process_error_true,
          (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_key_name
        + 2,
          assert_untyped,
          "assertion_failed",
          v27,
          ".\\res_texture.cpp",
          "vostok::render::res_texture::set_hw_texture",
          0xF1u);
        goto LABEL_38;
      }
LABEL_33:
      *v11 = 0;
      return;
    }
    if ( (*(_BYTE *)(a2 + 104) & 4) != 0 )
    {
      view_desc.ViewDimension = D3D_SRV_DIMENSION_TEXTURECUBE;
    }
    else
    {
      if ( *(_DWORD *)(a2 + 84) <= 1u )
      {
        v12 = *(_DWORD *)(a2 + 76);
        view_desc.Buffer.FirstElement = 0;
        if ( v12 <= 1 )
        {
          v14 = *(_DWORD *)(a2 + 72);
          view_desc.ViewDimension = D3D_SRV_DIMENSION_TEXTURE2D;
          view_desc.Buffer.NumElements = v14;
        }
        else
        {
          v13 = *(_DWORD *)(a2 + 72);
          view_desc.ViewDimension = D3D_SRV_DIMENSION_TEXTURE2DARRAY;
          view_desc.Texture1DArray.ArraySize = v12;
          *(_QWORD *)&view_desc.Texture2D.MipLevels = v13;
        }
LABEL_17:
        v15 = *(_DWORD *)(a2 + 80);
        view_desc.Format = v15;
        switch ( v15 )
        {
          case DXGI_FORMAT_R32_TYPELESS:
            view_desc.Format = DXGI_FORMAT_R32_FLOAT;
            break;
          case DXGI_FORMAT_R24G8_TYPELESS:
            view_desc.Format = DXGI_FORMAT_R24_UNORM_X8_TYPELESS;
            break;
          case DXGI_FORMAT_R16_TYPELESS:
            view_desc.Format = DXGI_FORMAT_R16_UNORM;
            break;
        }
        if ( !staging && *(_DWORD *)(a2 + 84) <= 1u )
        {
          if ( BYTE1(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_key_name)
            || (*(int (__stdcall **)(int, _DWORD, D3D11_SHADER_RESOURCE_VIEW_DESC *, int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x
                                                                                         + 28))(
                 `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
                 *(_DWORD *)(a2 + 420),
                 &view_desc,
                 a2 + 428) >= 0 )
          {
            return;
          }
          v16 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x;
          v28 = 228;
          v17 = *(_DWORD *)(a2 + 420);
          staging = 1;
          v18 = (*(int (__stdcall **)(int, int, D3D11_SHADER_RESOURCE_VIEW_DESC *, int))(*(_DWORD *)v16 + 28))(
                  v16,
                  v17,
                  &view_desc,
                  a2 + 428);
          d3d11_error_string = make_d3d11_error_string(v18);
          v25 = (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_key_name
              + 1;
LABEL_37:
          vostok::debug::on_error(
            &staging,
            process_error_true,
            v25,
            assert_untyped,
            "assertion_failed",
            d3d11_error_string,
            ".\\res_texture.cpp",
            "vostok::render::res_texture::set_hw_texture",
            v28);
LABEL_38:
          if ( vostok::debug::is_debugger_present() || staging )
            __debugbreak();
          return;
        }
        goto LABEL_33;
      }
      view_desc.ViewDimension = D3D_SRV_DIMENSION_TEXTURE2DMS;
    }
    view_desc.Buffer.NumElements = *(_DWORD *)(a2 + 72);
    view_desc.Buffer.FirstElement = 0;
    goto LABEL_17;
  }
}
