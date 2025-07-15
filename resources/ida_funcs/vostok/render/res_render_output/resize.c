void __usercall vostok::render::res_render_output::resize(
        vostok::render::res_render_output *this@<ecx>,
        HWND force_resize@<eax>)
{
  vostok::render::res_render_output::resize(this, 0, 0, this->m_windowed, force_resize);
}


void __userpurge vostok::render::res_render_output::resize(
        vostok::render::res_render_output *this@<esi>,
        unsigned int size_x@<eax>,
        unsigned int size_y@<ecx>,
        bool windowed,
        HWND force_resize)
{
  unsigned int y; // edi
  unsigned int x; // ebp
  HWND__ *m_window; // eax
  ID3D11RenderTargetView *m_base_rt; // eax
  vostok::render::res_texture *m_object; // edi
  ID3D11Resource *m_surface; // eax
  ID3D11ShaderResourceView *m_sh_res_view; // eax
  IDXGISwapChain *m_swap_chain; // eax
  unsigned int BufferCount; // edx
  HRESULT v14; // eax
  const char *d3d11_error_string; // eax
  bool m_windowed; // cl
  IDXGIOutput *v17; // edi
  IDXGISwapChain *v18; // eax
  IDXGISwapChain_vtbl *v19; // edx
  int v20; // eax
  vostok::render::res_render_output *v21; // ecx
  HWND v22; // ebx
  HWND i; // eax
  IDXGISwapChain *v24; // eax
  BOOL v25; // edx
  HRESULT v26; // eax
  const char *v27; // eax
  unsigned int Width; // [esp+18h] [ebp-50h]
  unsigned int Height; // [esp+1Ch] [ebp-4Ch]
  DXGI_FORMAT Format; // [esp+20h] [ebp-48h]
  vostok::math::uint2 new_size; // [esp+40h] [ebp-28h] BYREF
  tagMSG msg; // [esp+48h] [ebp-20h] BYREF

  y = size_y;
  x = size_x;
  new_size = (vostok::math::uint2)__PAIR64__(size_y, size_x);
  if ( !size_x || !size_y )
  {
    m_window = this->m_window;
    if ( m_window )
    {
      vostok::render::res_render_output::select_resolution(m_window, &new_size.x, &new_size.y, windowed);
      y = new_size.y;
      x = new_size.x;
    }
    else
    {
      GetLastError();
    }
  }
  if ( ((_BYTE)force_resize
     || this->m_swap_chain_desc.BufferDesc.Width != x
     || this->m_swap_chain_desc.BufferDesc.Height != y
     || this->m_windowed != windowed)
    && x >= 0x10
    && y >= 0x10 )
  {
    this->m_swap_chain_desc.Windowed = windowed;
    this->m_windowed = windowed;
    this->m_swap_chain_desc.BufferDesc.Width = x;
    this->m_swap_chain_desc.BufferDesc.Height = y;
    log_ref_count<ID3D11DepthStencilView>(this->m_base_zb, "ref_count : m_base_zb");
    log_ref_count<ID3D11RenderTargetView>(this->m_base_rt, "ref_count : m_base_rt");
    m_base_rt = this->m_base_rt;
    if ( m_base_rt )
    {
      m_base_rt->Release(this->m_base_rt);
      this->m_base_rt = 0;
    }
    m_object = this->m_texture_zb.m_object;
    m_object->m_mip_level_cut = 0;
    m_surface = m_object->m_surface;
    if ( m_surface )
    {
      m_surface->Release(m_object->m_surface);
      m_object->m_surface = 0;
    }
    m_sh_res_view = m_object->m_sh_res_view;
    if ( m_sh_res_view )
    {
      m_sh_res_view->Release(m_object->m_sh_res_view);
      m_object->m_sh_res_view = 0;
    }
    m_object->m_surface = 0;
    m_object->m_desc_valid = 0;
    m_object->m_desc_3d_valid = 0;
    if ( !BYTE1(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_ids._M_impl._M_finish)
      && this->m_swap_chain->ResizeBuffers(
           this->m_swap_chain,
           this->m_swap_chain_desc.BufferCount,
           this->m_swap_chain_desc.BufferDesc.Width,
           this->m_swap_chain_desc.BufferDesc.Height,
           this->m_swap_chain_desc.BufferDesc.Format,
           0) < 0 )
    {
      m_swap_chain = this->m_swap_chain;
      Format = this->m_swap_chain_desc.BufferDesc.Format;
      Height = this->m_swap_chain_desc.BufferDesc.Height;
      Width = this->m_swap_chain_desc.BufferDesc.Width;
      BufferCount = this->m_swap_chain_desc.BufferCount;
      LOBYTE(force_resize) = 1;
      v14 = m_swap_chain->ResizeBuffers(m_swap_chain, BufferCount, Width, Height, Format, 0);
      d3d11_error_string = make_d3d11_error_string(v14);
      vostok::debug::on_error(
        (bool *)&force_resize,
        process_error_true,
        (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_ids._M_impl._M_finish
      + 1,
        assert_untyped,
        "assertion_failed",
        d3d11_error_string,
        ".\\res_render_output.cpp",
        "vostok::render::res_render_output::resize",
        0x136u);
      if ( vostok::debug::is_debugger_present() || (_BYTE)force_resize )
        __debugbreak();
    }
    m_windowed = this->m_windowed;
    if ( m_windowed )
      v17 = 0;
    else
      v17 = (IDXGIOutput *)*((_DWORD *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_sound_scene.m_object
                           + *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                             + 47));
    v18 = this->m_swap_chain;
    v19 = v18->lpVtbl;
    force_resize = 0;
    v20 = v19->SetFullscreenState(v18, !m_windowed, v17);
    v22 = force_resize;
    if ( v20 )
    {
      SetFocus(this->m_swap_chain_desc.OutputWindow);
      for ( i = (HWND)GetMessageA(&msg, v22, (UINT)v22, (UINT)v22);
            i != v22;
            i = (HWND)GetMessageA(&msg, v22, (UINT)v22, (UINT)v22) )
      {
        if ( i != HWND_MESSAGE|0x2 )
        {
          TranslateMessage(&msg);
          DispatchMessageA(&msg);
        }
      }
      if ( BYTE2(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_ids._M_impl._M_finish) == (_BYTE)v22
        && this->m_swap_chain->SetFullscreenState(this->m_swap_chain, this->m_windowed == (unsigned __int8)v22, v17) < 0 )
      {
        v24 = this->m_swap_chain;
        v25 = this->m_windowed == (unsigned __int8)v22;
        LOBYTE(force_resize) = 1;
        v26 = v24->SetFullscreenState(v24, v25, v17);
        v27 = make_d3d11_error_string(v26);
        vostok::debug::on_error(
          (bool *)&force_resize,
          process_error_true,
          (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_ids._M_impl._M_finish
        + 2,
          (vostok::assert_enum)v22,
          "assertion_failed",
          v27,
          ".\\res_render_output.cpp",
          "vostok::render::res_render_output::resize",
          0x14Cu);
        if ( vostok::debug::is_debugger_present() || (_BYTE)force_resize != (_BYTE)v22 )
          __debugbreak();
      }
    }
    vostok::render::res_render_output::update_targets(v21, (int)this);
    this->m_present_sync_mode = *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                                + 241) != 0;
  }
}
