void __usercall vostok::render::res_render_output::update_targets(
        vostok::render::res_render_output *this@<ecx>,
        int a2@<esi>)
{
  HRESULT v2; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v3; // ecx
  bool *d3d11_error_string; // eax
  HRESULT v5; // edi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  bool *v7; // eax
  ID3D11Resource *v8; // [esp+8h] [ebp-8h] BYREF
  char v9; // [esp+Fh] [ebp-1h] BYREF

  v2 = (*(int (__stdcall **)(_DWORD, _DWORD, GUID *, ID3D11Resource **))(**(_DWORD **)(a2 + 212) + 36))(
         *(_DWORD *)(a2 + 212),
         0,
         &_GUID_6f15aaf2_d208_4e89_9ab4_489535d34f9c,
         &v8);
  if ( !ignore_always_29 && v2 < 0 )
  {
    v9 = 1;
    d3d11_error_string = (bool *)make_d3d11_error_string(v2, v3);
    vostok::debug::on_error(
      (bool *)&v9,
      process_error_true,
      d3d11_error_string,
      ".\\res_render_output.cpp",
      "vostok::render::res_render_output::update_targets",
      (const char *)0x1B3);
    if ( vostok::debug::is_debugger_present() || v9 )
      __debugbreak();
  }
  v5 = vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreateRenderTargetView(
         vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
         v8,
         0,
         (ID3D11RenderTargetView **)(a2 + 216));
  v8->Release(v8);
  if ( !ignore_always_30 && v5 < 0 )
  {
    v9 = 1;
    v7 = (bool *)make_d3d11_error_string(v5, v6);
    vostok::debug::on_error(
      (bool *)&v9,
      process_error_true,
      v7,
      ".\\res_render_output.cpp",
      "vostok::render::res_render_output::update_targets",
      (const char *)0x1B7);
    if ( vostok::debug::is_debugger_present() || v9 )
      __debugbreak();
  }
  vostok::render::res_render_output::update_depth_stencil_buffer((vostok::render::res_render_output *)v6, a2);
}
