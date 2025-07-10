void __userpurge vostok::render::render_target::create(
        vostok::render::render_target *this@<ecx>,
        DXGI_FORMAT format@<eax>,
        const char *name,
        unsigned int width,
        ID3D11Texture2D **height,
        vostok::render::enum_rt_usage usage,
        D3D11_USAGE memory_usage,
        unsigned int sample_count)
{
  unsigned int v8; // ebx
  unsigned int v9; // ebp
  unsigned int v12; // eax
  survarium::options_tab *v13; // ecx
  vostok::render::enum_rt_usage v14; // ecx
  ID3D11Resource **v15; // ebp
  int x; // eax
  HRESULT v17; // eax
  const char *d3d11_error_string; // eax
  int v19; // eax
  ID3D11Resource *v20; // ecx
  HRESULT v21; // eax
  const char *v22; // eax
  bool v23; // zf
  int v24; // eax
  ID3D11Resource *v25; // edx
  HRESULT v26; // eax
  const char *v27; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *texture; // eax
  vostok::render::res_texture *v29; // ecx
  vostok::render::res_texture *v30; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v31; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **p_m_texture; // edi
  bool v33; // [esp+1Ch] [ebp-5Ch]
  bool v34; // [esp+20h] [ebp-58h]
  D3D11_DEPTH_STENCIL_VIEW_DESC ViewDesc; // [esp+30h] [ebp-48h] BYREF
  D3D11_TEXTURE2D_DESC desc; // [esp+48h] [ebp-30h] BYREF

  v8 = (unsigned int)height;
  v9 = width;
  v23 = this->m_surface == 0;
  height = &this->m_surface;
  if ( !v23 )
    return;
  this->m_order = __rdtsc();
  if ( v9 > 0x4000
    || v8 > 0x4000
    || usage == enum_rt_usage_depth_stencil
    && format != DXGI_FORMAT_R24G8_TYPELESS
    && format != DXGI_FORMAT_R16_TYPELESS
    && format != DXGI_FORMAT_D24_UNORM_S8_UINT
    && format != DXGI_FORMAT_D16_UNORM )
  {
    return;
  }
  v12 = vostok::render::utils::calc_surface_size(v9, v8, format, &width);
  v13 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  this->m_memory_usage = v12;
  *(_DWORD *)&v13[1].m_options_count += v12;
  v14 = usage;
  this->m_width = v9;
  this->m_height = v8;
  this->m_format = format;
  this->m_usage = v14;
  memset((int)&desc, 0, sizeof(desc));
  desc.Height = v8;
  desc.Width = v9;
  v15 = height;
  desc.MipLevels = 1;
  desc.ArraySize = 1;
  desc.Format = format;
  desc.SampleDesc.Count = 1;
  desc.Usage = D3D11_USAGE_DEFAULT;
  desc.BindFlags = (usage != enum_rt_usage_depth_stencil ? 32 : 64) | 8;
  if ( !BYTE1(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_ids._M_impl._M_start) )
  {
    if ( (*(int (__stdcall **)(int, D3D11_TEXTURE2D_DESC *, _DWORD, ID3D11Texture2D **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x
                                                                                       + 20))(
           `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
           &desc,
           0,
           height) < 0 )
    {
      x = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x;
      LOBYTE(height) = 1;
      v17 = (*(int (__stdcall **)(int, D3D11_TEXTURE2D_DESC *, _DWORD, ID3D11Resource **))(*(_DWORD *)x + 20))(
              x,
              &desc,
              0,
              v15);
      d3d11_error_string = make_d3d11_error_string(v17);
      vostok::debug::on_error(
        (bool *)&height,
        process_error_true,
        (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_ids._M_impl._M_start
      + 1,
        assert_untyped,
        "assertion_failed",
        d3d11_error_string,
        ".\\render_target.cpp",
        "vostok::render::render_target::create",
        0x103u);
      if ( vostok::debug::is_debugger_present() || (_BYTE)height )
        __debugbreak();
    }
    format = desc.Format;
  }
  if ( usage )
  {
    if ( HIBYTE(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_ids._M_impl._M_start)
      || (*(int (__stdcall **)(int, ID3D11Resource *, _DWORD, ID3D11RenderTargetView **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x
                                                                                        + 36))(
           `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
           *v15,
           0,
           &this->m_rt) >= 0 )
    {
      goto LABEL_32;
    }
    v24 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x;
    v25 = *v15;
    LOBYTE(width) = 1;
    v26 = (*(int (__stdcall **)(int, ID3D11Resource *, _DWORD, ID3D11RenderTargetView **))(*(_DWORD *)v24 + 36))(
            v24,
            v25,
            0,
            &this->m_rt);
    v27 = make_d3d11_error_string(v26);
    vostok::debug::on_error(
      (bool *)&width,
      process_error_true,
      (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_ids._M_impl._M_start
    + 3,
      assert_untyped,
      "assertion_failed",
      v27,
      ".\\render_target.cpp",
      "vostok::render::render_target::create",
      0x134u);
    if ( vostok::debug::is_debugger_present() )
      goto LABEL_31;
    v23 = (_BYTE)width == 0;
  }
  else
  {
    memset(&ViewDesc.Flags, 0, 16);
    ViewDesc.Format = DXGI_FORMAT_UNKNOWN;
    ViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
    switch ( format )
    {
      case DXGI_FORMAT_R32_TYPELESS:
        ViewDesc.Format = DXGI_FORMAT_D32_FLOAT;
        break;
      case DXGI_FORMAT_R24G8_TYPELESS:
        ViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
        break;
      case DXGI_FORMAT_R16_TYPELESS:
        ViewDesc.Format = DXGI_FORMAT_D16_UNORM;
        break;
    }
    if ( BYTE2(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_ids._M_impl._M_start)
      || (*(int (__stdcall **)(int, ID3D11Resource *, D3D11_DEPTH_STENCIL_VIEW_DESC *, ID3D11DepthStencilView **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x + 40))(
           `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
           *v15,
           &ViewDesc,
           &this->m_zrt) >= 0 )
    {
      goto LABEL_32;
    }
    v19 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x;
    v20 = *v15;
    LOBYTE(usage) = 1;
    v21 = (*(int (__stdcall **)(int, ID3D11Resource *, D3D11_DEPTH_STENCIL_VIEW_DESC *, ID3D11DepthStencilView **))(*(_DWORD *)v19 + 40))(
            v19,
            v20,
            &ViewDesc,
            &this->m_zrt);
    v22 = make_d3d11_error_string(v21);
    vostok::debug::on_error(
      (bool *)&usage,
      process_error_true,
      (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_ids._M_impl._M_start
    + 2,
      assert_untyped,
      "assertion_failed",
      v22,
      ".\\render_target.cpp",
      "vostok::render::render_target::create",
      0x127u);
    if ( vostok::debug::is_debugger_present() )
      goto LABEL_31;
    v23 = (_BYTE)usage == enum_rt_usage_depth_stencil;
  }
  if ( !v23 )
LABEL_31:
    __debugbreak();
LABEL_32:
  if ( name )
  {
    texture = (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)vostok::render::resource_manager::create_texture((vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3], name, 0, 0, 0, 1, 1, 0xFFFFFFFF);
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      texture,
      (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&this->m_texture);
  }
  else
  {
    if ( vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
           0x1BCu) )
    {
      vostok::render::res_texture::res_texture(v30, 0);
    }
    else
    {
      v31 = 0;
    }
    p_m_texture = (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&this->m_texture;
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      v31,
      p_m_texture);
    vostok::render::res_texture::set_name(0, (int)*p_m_texture);
    HIBYTE((*p_m_texture)[109].m_object) = 1;
  }
  vostok::render::res_texture::set_hw_texture(v29, *v15, 0, 0, v33, v34);
}
