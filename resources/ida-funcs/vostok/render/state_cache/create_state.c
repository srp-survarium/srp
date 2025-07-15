void __thiscall vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC,32>::create_state(
        vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC,32> *this,
        D3D11_BLEND_DESC desc,
        ID3D11BlendState **ppIState)
{
  ID3D11Device_vtbl *v3; // ecx
  HRESULT v4; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // ecx
  bool *d3d11_error_string; // eax
  ID3D11Device *m_device; // [esp-18h] [ebp-24h]
  char v8; // [esp+Bh] [ebp-1h] BYREF

  if ( !ignore_always_40
    && vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreateBlendState(
         vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
         (const D3D11_BLEND_DESC *)&desc.IndependentBlendEnable,
         (ID3D11BlendState **)desc.AlphaToCoverageEnable) < 0 )
  {
    v3 = vostok::quasi_singleton<vostok::render::device>::pinst->m_device->lpVtbl;
    m_device = vostok::quasi_singleton<vostok::render::device>::pinst->m_device;
    v8 = 1;
    v4 = v3->CreateBlendState(
           m_device,
           (const D3D11_BLEND_DESC *)&desc.IndependentBlendEnable,
           (ID3D11BlendState **)desc.AlphaToCoverageEnable);
    d3d11_error_string = (bool *)make_d3d11_error_string(v4, v5);
    vostok::debug::on_error(
      (bool *)&v8,
      process_error_true,
      d3d11_error_string,
      ".\\state_cache.cpp",
      "vostok::render::state_cache<struct ID3D11BlendState,struct D3D11_BLEND_DESC,32>::create_state",
      (const char *)0x3C);
    if ( vostok::debug::is_debugger_present() || v8 )
      __debugbreak();
  }
}


void __thiscall vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC,32>::create_state(
        vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC,32> *this,
        D3D11_RASTERIZER_DESC desc,
        ID3D11RasterizerState **ppIState)
{
  ID3D11Device_vtbl *v3; // ecx
  HRESULT v4; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // ecx
  bool *d3d11_error_string; // eax
  ID3D11Device *m_device; // [esp-18h] [ebp-24h]
  char v8; // [esp+Bh] [ebp-1h] BYREF

  if ( !ignore_always_38
    && vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreateRasterizerState(
         vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
         (const D3D11_RASTERIZER_DESC *)&desc.CullMode,
         (ID3D11RasterizerState **)desc.FillMode) < 0 )
  {
    v3 = vostok::quasi_singleton<vostok::render::device>::pinst->m_device->lpVtbl;
    m_device = vostok::quasi_singleton<vostok::render::device>::pinst->m_device;
    v8 = 1;
    v4 = v3->CreateRasterizerState(
           m_device,
           (const D3D11_RASTERIZER_DESC *)&desc.CullMode,
           (ID3D11RasterizerState **)desc.FillMode);
    d3d11_error_string = (bool *)make_d3d11_error_string(v4, v5);
    vostok::debug::on_error(
      (bool *)&v8,
      process_error_true,
      d3d11_error_string,
      ".\\state_cache.cpp",
      "vostok::render::state_cache<struct ID3D11RasterizerState,struct D3D11_RASTERIZER_DESC,32>::create_state",
      (const char *)0x2E);
    if ( vostok::debug::is_debugger_present() || v8 )
      __debugbreak();
  }
}


void __thiscall vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32>::create_state(
        vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *this,
        D3D11_SAMPLER_DESC desc,
        ID3D11SamplerState **ppIState)
{
  ID3D11Device_vtbl *v3; // ecx
  HRESULT v4; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // ecx
  bool *d3d11_error_string; // eax
  ID3D11Device *m_device; // [esp-18h] [ebp-20h]
  char v8; // [esp+7h] [ebp-1h] BYREF

  if ( !ignore_always_41
    && vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreateSamplerState(
         vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
         &desc,
         ppIState) < 0 )
  {
    v3 = vostok::quasi_singleton<vostok::render::device>::pinst->m_device->lpVtbl;
    m_device = vostok::quasi_singleton<vostok::render::device>::pinst->m_device;
    v8 = 1;
    v4 = v3->CreateSamplerState(m_device, &desc, ppIState);
    d3d11_error_string = (bool *)make_d3d11_error_string(v4, v5);
    vostok::debug::on_error(
      (bool *)&v8,
      process_error_true,
      d3d11_error_string,
      ".\\state_cache.cpp",
      "vostok::render::state_cache<struct ID3D11SamplerState,struct D3D11_SAMPLER_DESC,32>::create_state",
      (const char *)0x43);
    if ( vostok::debug::is_debugger_present() || v8 )
      __debugbreak();
  }
}
