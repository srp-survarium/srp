void __userpurge vostok::render::res_texture::set_hw_texture(
        vostok::render::res_texture *this@<ecx>,
        int a2@<eax>,
        ID3D11Resource *surface,
        unsigned int mip_level_cut,
        int staging,
        bool srgb,
        bool __formal)
{
  int v8; // eax
  _DWORD *v9; // edi
  int v10; // eax
  ID3D11Resource *v11; // eax
  unsigned int v12; // eax
  DXGI_FORMAT v13; // edx
  int v14; // edx
  ID3D11Device_vtbl *v15; // ecx
  HRESULT v16; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v17; // ecx
  bool *d3d11_error_string; // eax
  ID3D11Device *m_device; // [esp-1Ch] [ebp-44h]
  ID3D11Resource *v20; // [esp-18h] [ebp-40h]
  DXGI_FORMAT *p_srgb_format; // [esp-14h] [ebp-3Ch]
  ID3D11ShaderResourceView **v22; // [esp-10h] [ebp-38h]
  int v23; // [esp-4h] [ebp-2Ch]
  DXGI_FORMAT srgb_format; // [esp+10h] [ebp-18h] BYREF
  int v25; // [esp+14h] [ebp-14h]
  int v26; // [esp+18h] [ebp-10h]
  int v27; // [esp+1Ch] [ebp-Ch]
  int v28; // [esp+20h] [ebp-8h]
  unsigned int v29; // [esp+24h] [ebp-4h]

  if ( surface )
    surface->AddRef(surface);
  *(_DWORD *)(a2 + 452) = mip_level_cut;
  v8 = *(_DWORD *)(a2 + 440);
  if ( v8 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v8 + 8))(*(_DWORD *)(a2 + 440));
    *(_DWORD *)(a2 + 440) = 0;
  }
  v9 = (_DWORD *)(a2 + 448);
  v10 = *(_DWORD *)(a2 + 448);
  if ( v10 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v10 + 8))(*(_DWORD *)(a2 + 448));
    *v9 = 0;
  }
  v11 = surface;
  *(_DWORD *)(a2 + 440) = surface;
  *(_BYTE *)(a2 + 456) = 0;
  *(_BYTE *)(a2 + 457) = 0;
  if ( v11 )
  {
    vostok::render::res_texture::desc_update(this, a2);
    (*(void (__stdcall **)(_DWORD, ID3D11Resource **))(**(_DWORD **)(a2 + 440) + 28))(*(_DWORD *)(a2 + 440), &surface);
    if ( surface != (ID3D11Resource *)3 )
    {
      if ( surface == (ID3D11Resource *)4 )
      {
        if ( (_BYTE)staging )
          goto LABEL_33;
        if ( ignore_always_12
          || vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreateShaderResourceView(
               vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
               *(ID3D11Resource **)(a2 + 440),
               0,
               (ID3D11ShaderResourceView **)(a2 + 448)) >= 0 )
        {
          return;
        }
        v23 = 274;
      }
      else
      {
        if ( ignore_always_13
          || vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreateShaderResourceView(
               vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
               *(ID3D11Resource **)(a2 + 440),
               0,
               (ID3D11ShaderResourceView **)(a2 + 448)) >= 0 )
        {
          return;
        }
        v23 = 279;
      }
      v22 = (ID3D11ShaderResourceView **)(a2 + 448);
      p_srgb_format = 0;
LABEL_38:
      v20 = *(ID3D11Resource **)(a2 + 440);
      v15 = vostok::quasi_singleton<vostok::render::device>::pinst->m_device->lpVtbl;
      m_device = vostok::quasi_singleton<vostok::render::device>::pinst->m_device;
      HIBYTE(staging) = 1;
      v16 = v15->CreateShaderResourceView(m_device, v20, (const D3D11_SHADER_RESOURCE_VIEW_DESC *)p_srgb_format, v22);
      d3d11_error_string = (bool *)make_d3d11_error_string(v16, v17);
      vostok::debug::on_error(
        (bool *)&staging + 3,
        process_error_true,
        d3d11_error_string,
        ".\\res_texture.cpp",
        "vostok::render::res_texture::set_hw_texture",
        (const char *)v23);
      if ( vostok::debug::is_debugger_present() || HIBYTE(staging) )
        __debugbreak();
      return;
    }
    if ( (*(_BYTE *)(a2 + 124) & 4) != 0 )
    {
      v25 = 9;
    }
    else
    {
      if ( *(_DWORD *)(a2 + 104) <= 1u )
      {
        v12 = *(_DWORD *)(a2 + 96);
        v26 = 0;
        if ( v12 <= 1 )
        {
          v25 = 4;
        }
        else
        {
          v25 = 5;
          v28 = 0;
          v29 = v12;
        }
LABEL_17:
        v13 = *(_DWORD *)(a2 + 100);
        v27 = *(_DWORD *)(a2 + 92);
        srgb_format = vostok::render::get_srgb_format(v13, srgb);
        switch ( v14 )
        {
          case '\'':
            srgb_format = DXGI_FORMAT_R32_FLOAT;
            break;
          case ',':
            srgb_format = DXGI_FORMAT_R24_UNORM_X8_TYPELESS;
            break;
          case '5':
            srgb_format = DXGI_FORMAT_R16_UNORM;
            break;
        }
        if ( !(_BYTE)staging && *(_DWORD *)(a2 + 104) <= 1u )
        {
          if ( ignore_always_11
            || vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreateShaderResourceView(
                 vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
                 *(ID3D11Resource **)(a2 + 440),
                 (const D3D11_SHADER_RESOURCE_VIEW_DESC *)&srgb_format,
                 (ID3D11ShaderResourceView **)(a2 + 448)) >= 0 )
          {
            return;
          }
          v23 = 261;
          v22 = (ID3D11ShaderResourceView **)(a2 + 448);
          p_srgb_format = &srgb_format;
          goto LABEL_38;
        }
LABEL_33:
        *v9 = 0;
        return;
      }
      v25 = 6;
    }
    v26 = 0;
    goto LABEL_17;
  }
}
