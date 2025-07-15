void __userpurge vostok::render::res_render_output::resize(
        unsigned int *size_x@<ecx>,
        unsigned int size_y@<eax>,
        vostok::render::res_render_output *this,
        HWND__ *windowed,
        const char *force_resize)
{
  unsigned int *v5; // esi
  unsigned int v6; // edi
  unsigned __int8 v7; // cl
  vostok::render::options *v8; // eax
  unsigned int m_monitor_index; // eax
  IDXGISwapChain *v10; // eax
  IDXGISwapChain_vtbl *v11; // ecx
  BOOL v12; // edx
  HRESULT v13; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v14; // ecx
  bool *v15; // eax
  ID3D11DepthStencilView *m_base_zb; // esi
  ID3D11RenderTargetView *m_base_rt; // esi
  float z; // eax
  bool v19; // zf
  vostok::render::res_texture *v20; // ecx
  ID3D11DepthStencilView *v21; // eax
  ID3D11RenderTargetView *v22; // eax
  vostok::render::res_render_output *v23; // ecx
  IDXGISwapChain *m_swap_chain; // eax
  IDXGISwapChain_vtbl *v25; // ecx
  HRESULT v26; // edi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v27; // ecx
  bool *d3d11_error_string; // eax
  IDXGISwapChain *v29; // eax
  IDXGISwapChain_vtbl *v30; // ecx
  BOOL v31; // edx
  HRESULT v32; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v33; // ecx
  bool *v34; // eax
  DXGI_FORMAT Format; // [esp-14h] [ebp-30h]
  bool v36; // [esp+0h] [ebp-1Ch]
  unsigned int *v37; // [esp+10h] [ebp-Ch] BYREF
  unsigned int v38; // [esp+14h] [ebp-8h] BYREF
  IDXGIOutput *v39; // [esp+28h] [ebp+Ch]

  v5 = size_x;
  v6 = size_y;
  v37 = size_x;
  v38 = size_y;
  if ( !size_x || !size_y )
  {
    if ( this->m_window )
    {
      vostok::render::res_render_output::select_resolution(size_x, (unsigned int *)&v37, &v38, windowed, this->m_window);
      v6 = v38;
      v5 = v37;
    }
    else
    {
      GetLastError();
    }
  }
  if ( !(_BYTE)force_resize
    && (unsigned int *)this->m_swap_chain_desc.BufferDesc.Width == v5
    && this->m_swap_chain_desc.BufferDesc.Height == v6 )
  {
    v7 = (unsigned __int8)windowed;
    if ( this->m_windowed == (_BYTE)windowed )
      return;
  }
  else
  {
    v7 = (unsigned __int8)windowed;
  }
  if ( (unsigned int)v5 >= 0x10 && v6 >= 0x10 )
  {
    if ( (unsigned int *)this->m_swap_chain_desc.BufferDesc.Width != v5
      || (HIBYTE(force_resize) = 0, this->m_swap_chain_desc.BufferDesc.Height != v6) )
    {
      HIBYTE(force_resize) = 1;
    }
    this->m_swap_chain_desc.Windowed = v7;
    v8 = vostok::quasi_singleton<vostok::render::options>::pinst;
    this->m_windowed = v7;
    m_monitor_index = v8->current.m_monitor_index;
    if ( v7 )
      v39 = 0;
    else
      v39 = vostok::quasi_singleton<vostok::render::device>::pinst->m_outputs[m_monitor_index];
    if ( HIBYTE(force_resize) )
    {
      this->m_swap_chain_desc.BufferDesc.Width = (unsigned int)v5;
      this->m_swap_chain_desc.BufferDesc.Height = v6;
      m_base_zb = this->m_base_zb;
      force_resize = "ref_count : m_base_zb";
      m_base_zb->AddRef(m_base_zb);
      m_base_zb->Release(m_base_zb);
      m_base_rt = this->m_base_rt;
      force_resize = "ref_count : m_base_rt";
      m_base_rt->AddRef(m_base_rt);
      m_base_rt->Release(m_base_rt);
      z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      v19 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) == 0;
      *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) = 0;
      LOBYTE(v20) = !v19;
      *(_BYTE *)(LODWORD(z) + 117) |= !v19;
      v21 = this->m_base_zb;
      if ( v21 )
      {
        v21->Release(this->m_base_zb);
        this->m_base_zb = 0;
      }
      v22 = this->m_base_rt;
      if ( v22 )
      {
        v22->Release(this->m_base_rt);
        this->m_base_rt = 0;
      }
      vostok::render::res_texture::set_hw_texture(v20, (int)this->m_texture_zb.m_object, 0, 0, 0, 0, v36);
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
        0,
        (vostok::render::res_texture *)&this->m_texture_zb);
      if ( !ignore_always_25
        && this->m_swap_chain->ResizeBuffers(
             this->m_swap_chain,
             this->m_swap_chain_desc.BufferCount,
             this->m_swap_chain_desc.BufferDesc.Width,
             this->m_swap_chain_desc.BufferDesc.Height,
             this->m_swap_chain_desc.BufferDesc.Format,
             0) < 0 )
      {
        m_swap_chain = this->m_swap_chain;
        v25 = m_swap_chain->lpVtbl;
        Format = this->m_swap_chain_desc.BufferDesc.Format;
        HIBYTE(force_resize) = 1;
        v26 = v25->ResizeBuffers(
                m_swap_chain,
                this->m_swap_chain_desc.BufferCount,
                this->m_swap_chain_desc.BufferDesc.Width,
                this->m_swap_chain_desc.BufferDesc.Height,
                Format,
                0);
        d3d11_error_string = (bool *)make_d3d11_error_string(v26, v27);
        vostok::debug::on_error(
          (bool *)&force_resize + 3,
          process_error_true,
          d3d11_error_string,
          ".\\res_render_output.cpp",
          "vostok::render::res_render_output::resize",
          (const char *)0x153);
        if ( vostok::debug::is_debugger_present() || HIBYTE(force_resize) )
          __debugbreak();
      }
      if ( !ignore_always_26 && this->m_swap_chain->SetFullscreenState(this->m_swap_chain, !this->m_windowed, v39) < 0 )
      {
        v29 = this->m_swap_chain;
        v30 = v29->lpVtbl;
        v31 = !this->m_windowed;
        HIBYTE(force_resize) = 1;
        v32 = v30->SetFullscreenState(v29, v31, v39);
        v34 = (bool *)make_d3d11_error_string(v32, v33);
        vostok::debug::on_error(
          (bool *)&force_resize + 3,
          process_error_true,
          v34,
          ".\\res_render_output.cpp",
          "vostok::render::res_render_output::resize",
          (const char *)0x167);
        if ( vostok::debug::is_debugger_present() || HIBYTE(force_resize) )
          __debugbreak();
      }
      vostok::render::res_render_output::update_targets(v23, (int)this);
      this->m_present_sync_mode = vostok::quasi_singleton<vostok::render::options>::pinst->current.m_vsync;
    }
    else if ( !ignore_always_24 && this->m_swap_chain->SetFullscreenState(this->m_swap_chain, v7 == 0, v39) < 0 )
    {
      v10 = this->m_swap_chain;
      v11 = v10->lpVtbl;
      v12 = !this->m_windowed;
      HIBYTE(force_resize) = 1;
      v13 = v11->SetFullscreenState(v10, v12, v39);
      v15 = (bool *)make_d3d11_error_string(v13, v14);
      vostok::debug::on_error(
        (bool *)&force_resize + 3,
        process_error_true,
        v15,
        ".\\res_render_output.cpp",
        "vostok::render::res_render_output::resize",
        (const char *)0x129);
      if ( vostok::debug::is_debugger_present() || HIBYTE(force_resize) )
        __debugbreak();
    }
  }
}
