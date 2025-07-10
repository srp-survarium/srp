void __usercall vostok::render::res_render_output::~res_render_output(
        vostok::render::res_render_output *this@<ecx>,
        int a2@<eax>)
{
  int v3; // eax
  vostok::render::res_texture *v4; // ecx
  int v5; // eax
  int v6; // eax

  log_ref_count<ID3D11DepthStencilView>(*(ID3D11DepthStencilView **)(a2 + 212), "m_base_zb");
  v3 = *(_DWORD *)(a2 + 212);
  if ( v3 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v3 + 8))(*(_DWORD *)(a2 + 212));
    *(_DWORD *)(a2 + 212) = 0;
  }
  log_ref_count<ID3D11RenderTargetView>(*(ID3D11RenderTargetView **)(a2 + 208), "m_base_rt");
  v5 = *(_DWORD *)(a2 + 208);
  if ( v5 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v5 + 8))(*(_DWORD *)(a2 + 208));
    *(_DWORD *)(a2 + 208) = 0;
  }
  v6 = *(_DWORD *)(a2 + 216);
  if ( v6 )
  {
    if ( (*(_DWORD *)(v6 + 4))-- == 1 )
      vostok::render::res_texture::destroy_impl(v4);
  }
}
