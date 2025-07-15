void __thiscall vostok::render::res_render_output::update_depth_stencil_buffer(
        vostok::render::res_render_output *this,
        int a2)
{
  int v2; // esi
  ID3D11Device *m_device; // eax
  HRESULT v4; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // ecx
  bool *d3d11_error_string; // eax
  HRESULT v7; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v8; // ecx
  bool *v9; // eax
  unsigned int v10; // eax
  int v11; // ecx
  const char *v12; // edi
  const char *v13; // esi
  bool v14; // cf
  bool v15; // zf
  int v16; // eax
  vostok::render::res_texture *texture; // eax
  vostok::render::resource_manager *v18; // edi
  vostok::render::res_texture *v19; // ecx
  bool v20; // [esp+12h] [ebp-58h]
  char v21; // [esp+21h] [ebp-49h] BYREF
  ID3D11Resource *v22; // [esp+22h] [ebp-48h] BYREF
  _DWORD v23[6]; // [esp+26h] [ebp-44h] BYREF
  _DWORD v24[11]; // [esp+3Eh] [ebp-2Ch] BYREF

  v2 = a2;
  v24[0] = *(_DWORD *)(a2 + 152);
  v24[1] = *(_DWORD *)(a2 + 156);
  v24[2] = 1;
  v24[3] = 1;
  v24[5] = 1;
  m_device = vostok::quasi_singleton<vostok::render::device>::pinst->m_device;
  v24[4] = 44;
  v24[6] = 0;
  v24[7] = 0;
  v24[8] = 72;
  v24[9] = 0;
  v24[10] = 0;
  v4 = m_device->CreateTexture2D(m_device, (const D3D11_TEXTURE2D_DESC *)v24, 0, (ID3D11Texture2D **)&v22);
  if ( !ignore_always_31 && v4 < 0 )
  {
    v21 = 1;
    d3d11_error_string = (bool *)make_d3d11_error_string(v4, v5);
    vostok::debug::on_error(
      (bool *)&v21,
      process_error_true,
      d3d11_error_string,
      ".\\res_render_output.cpp",
      "vostok::render::res_render_output::update_depth_stencil_buffer",
      (const char *)0x1D1);
    if ( vostok::debug::is_debugger_present() || v21 )
      __debugbreak();
  }
  memset(v23, 0, sizeof(v23));
  v23[0] = 45;
  v23[1] = 3;
  v23[3] = 0;
  v7 = vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreateDepthStencilView(
         vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
         v22,
         (const D3D11_DEPTH_STENCIL_VIEW_DESC *)v23,
         (ID3D11DepthStencilView **)(a2 + 220));
  if ( !ignore_always_32 && v7 < 0 )
  {
    v21 = 1;
    v9 = (bool *)make_d3d11_error_string(v7, v8);
    vostok::debug::on_error(
      (bool *)&v21,
      process_error_true,
      v9,
      ".\\res_render_output.cpp",
      "vostok::render::res_render_output::update_depth_stencil_buffer",
      (const char *)0x1DC);
    if ( vostok::debug::is_debugger_present() || v21 )
      __debugbreak();
  }
  v10 = depth_texture_id++;
  vostok::fs_new::path_string_impl::assignf(
    (_DWORD *)(a2 + 12),
    (vostok::buffer_string *)v8,
    (vostok::buffer_string *)"%s%d",
    "$user$depth",
    v10);
  if ( a2 == -24 )
    goto LABEL_19;
  v12 = "null";
  v13 = (const char *)(a2 + 24);
  v11 = 5;
  v16 = 0;
  v14 = 0;
  v15 = 1;
  do
  {
    if ( !v11 )
      break;
    v14 = *v13 < (unsigned int)*v12;
    v15 = *v13++ == *v12++;
    --v11;
  }
  while ( v15 );
  if ( !v15 )
    v16 = -v14 - (v14 - 1);
  v2 = a2;
  if ( v16 )
  {
LABEL_19:
    v18 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
    texture = (vostok::render::res_texture *)vostok::render::resource_manager::find_texture(
                                               (vostok::render::resource_manager *)v11,
                                               (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                                               (const char *)(a2 + 24));
    if ( !texture )
      texture = vostok::render::resource_manager::load_texture(v18, (char *)(v2 + 24), 0, 0, 0, 1, 1, 0xFFFFFFFF, 1, 0);
  }
  else
  {
    texture = 0;
  }
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    texture,
    (vostok::render::res_texture *)(v2 + 224));
  vostok::render::res_texture::set_hw_texture(v19, *(_DWORD *)(v2 + 224), v22, 0, 0, 0, v20);
  v22->Release(v22);
}
