void __usercall vostok::render::res_render_output::initialize_swap_chain(
        vostok::render::res_render_output *this@<ecx>,
        int a2@<eax>)
{
  int MessageA; // eax
  IDXGIFactory_vtbl *v4; // edx
  HRESULT v5; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  bool *d3d11_error_string; // eax
  vostok::render::res_render_output *v8; // ecx
  IDXGIFactory *m_dxgi_factory; // [esp-1Ch] [ebp-4Ch]
  ID3D11Device *m_device; // [esp-18h] [ebp-48h]
  MSG Msg; // [esp+10h] [ebp-20h] BYREF
  char v12; // [esp+2Fh] [ebp-1h] BYREF

  if ( vostok::quasi_singleton<vostok::render::device>::pinst->m_dxgi_factory->CreateSwapChain(
         vostok::quasi_singleton<vostok::render::device>::pinst->m_dxgi_factory,
         vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
         (DXGI_SWAP_CHAIN_DESC *)(a2 + 152),
         (IDXGISwapChain **)(a2 + 212)) )
  {
    SetFocus(*(HWND *)(a2 + 196));
    while ( 1 )
    {
      MessageA = GetMessageA(&Msg, 0, 0, 0);
      if ( !MessageA )
        break;
      if ( MessageA != -1 )
      {
        TranslateMessage(&Msg);
        DispatchMessageA(&Msg);
      }
    }
    if ( !ignore_always_22
      && vostok::quasi_singleton<vostok::render::device>::pinst->m_dxgi_factory->CreateSwapChain(
           vostok::quasi_singleton<vostok::render::device>::pinst->m_dxgi_factory,
           vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
           (DXGI_SWAP_CHAIN_DESC *)(a2 + 152),
           (IDXGISwapChain **)(a2 + 212)) < 0 )
    {
      v4 = vostok::quasi_singleton<vostok::render::device>::pinst->m_dxgi_factory->lpVtbl;
      m_device = vostok::quasi_singleton<vostok::render::device>::pinst->m_device;
      m_dxgi_factory = vostok::quasi_singleton<vostok::render::device>::pinst->m_dxgi_factory;
      v12 = 1;
      v5 = v4->CreateSwapChain(
             m_dxgi_factory,
             m_device,
             (DXGI_SWAP_CHAIN_DESC *)(a2 + 152),
             (IDXGISwapChain **)(a2 + 212));
      d3d11_error_string = (bool *)make_d3d11_error_string(v5, v6);
      vostok::debug::on_error(
        (bool *)&v12,
        process_error_true,
        d3d11_error_string,
        ".\\res_render_output.cpp",
        "vostok::render::res_render_output::initialize_swap_chain",
        (const char *)0x8B);
      if ( vostok::debug::is_debugger_present() || v12 )
        __debugbreak();
    }
  }
  vostok::quasi_singleton<vostok::render::device>::pinst->m_dxgi_factory->MakeWindowAssociation(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_dxgi_factory,
    *(HWND__ **)(a2 + 228),
    2u);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_dxgi_factory->MakeWindowAssociation(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_dxgi_factory,
    *(HWND__ **)(a2 + 228),
    1u);
  vostok::render::res_render_output::update_targets(v8, a2);
}
