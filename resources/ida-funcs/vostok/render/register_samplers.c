void __thiscall vostok::render::register_samplers(
        vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC,32> *ecx0)
{
  vostok::render::resource_manager *v1; // edi
  unsigned int m_max_anisotropic; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  ID3D11SamplerState *sampler_state; // eax
  vostok::render::resource_manager *v7; // ecx
  vostok::render::sampler_state_descriptor *v8; // ecx
  ID3D11SamplerState *v9; // eax
  vostok::render::resource_manager *v10; // ecx
  ID3D11SamplerState *v11; // eax
  vostok::render::resource_manager *v12; // ecx
  ID3D11SamplerState *v13; // eax
  vostok::render::resource_manager *v14; // ecx
  ID3D11SamplerState *v15; // eax
  vostok::render::resource_manager *v16; // ecx
  ID3D11SamplerState *v17; // eax
  vostok::render::resource_manager *v18; // ecx
  ID3D11SamplerState *v19; // eax
  vostok::render::resource_manager *v20; // ecx
  ID3D11SamplerState *v21; // eax
  vostok::render::resource_manager *v22; // ecx
  ID3D11SamplerState *v23; // eax
  vostok::render::resource_manager *v24; // ecx
  ID3D11SamplerState *v25; // eax
  vostok::render::resource_manager *v26; // ecx
  ID3D11SamplerState *v27; // eax
  vostok::render::resource_manager *v28; // ecx
  ID3D11SamplerState *v29; // eax
  vostok::render::resource_manager *v30; // ecx
  const char *v31; // edi
  ID3D11SamplerState *v32; // eax
  vostok::render::resource_manager *v33; // ecx
  const char *v34; // edi
  ID3D11SamplerState *v35; // eax
  vostok::render::resource_manager *v36; // ecx
  ID3D11SamplerState *v37; // eax
  vostok::render::resource_manager *v38; // ecx
  ID3D11SamplerState *v39; // eax
  vostok::render::resource_manager *v40; // ecx
  ID3D11SamplerState *v41; // eax
  vostok::render::resource_manager *v42; // ecx
  vostok::render::sampler_state_descriptor *v43; // ecx
  const char *v44; // edi
  ID3D11SamplerState *v45; // eax
  vostok::render::resource_manager *v46; // ecx
  vostok::render::sampler_state_descriptor *v47; // ecx
  const char *v48; // esi
  ID3D11SamplerState *v49; // eax
  vostok::render::resource_manager *v50; // ecx
  vostok::render::resource_manager *v51; // ecx
  vostok::render::sampler_state_descriptor sampler_props; // [esp+Ch] [ebp-44h] BYREF
  char *name; // [esp+48h] [ebp-8h]
  bool v54; // [esp+4Fh] [ebp-1h]

  v1 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC,32>::clear_state_array(
    ecx0,
    &vostok::quasi_singleton<vostok::render::resource_manager>::pinst->m_sampler_cache.states.m_begin);
  *(int *)((char *)&dword_93A84 + (_DWORD)v1 + 4) = *(int *)((char *)&dword_93A84 + (_DWORD)v1);
  m_max_anisotropic = vostok::quasi_singleton<vostok::render::options>::pinst->current.m_max_anisotropic;
  if ( m_max_anisotropic )
  {
    name = (char *)vostok::quasi_singleton<vostok::render::options>::pinst->current.m_max_anisotropic;
    if ( m_max_anisotropic > 4 )
      name = (char *)4;
  }
  else
  {
    name = 0;
  }
  if ( m_max_anisotropic )
  {
    v3 = m_max_anisotropic - 1;
    if ( v3 )
    {
      v4 = v3 - 1;
      if ( v4 )
      {
        v5 = v4 - 1;
        if ( v5 )
        {
          if ( v5 == 1 )
            name = (char *)16;
        }
        else
        {
          name = (char *)8;
        }
      }
      else
      {
        name = (char *)4;
      }
    }
    else
    {
      name = (char *)2;
    }
  }
  else
  {
    name = 0;
  }
  v54 = name != 0;
  vostok::render::sampler_state_descriptor::reset(0, &sampler_props);
  sampler_props.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_props.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_props.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_props.m_desc.Filter = !v54 ? D3D11_FILTER_MIN_MAG_MIP_LINEAR : D3D11_FILTER_ANISOTROPIC;
  if ( v54 )
    sampler_props.m_desc.MaxAnisotropy = (unsigned int)name;
  sampler_props.m_desc.MipLODBias = 0.0;
  sampler_props.m_desc.MinLOD = 0.0;
  sampler_props.m_desc.MaxLOD = float_max_16;
  name = (char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  sampler_state = vostok::render::resource_manager::create_sampler_state(
                    (vostok::render::resource_manager *)&sampler_props,
                    (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                    (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *)&sampler_props);
  vostok::render::resource_manager::register_sampler(v7, name, (ID3D11SamplerState *)&sampler, sampler_state);
  vostok::render::sampler_state_descriptor::reset(v8, &sampler_props);
  sampler_props.m_desc.MipLODBias = 0.0;
  sampler_props.m_desc.MinLOD = 0.0;
  sampler_props.m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
  sampler_props.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_props.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_props.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_props.m_desc.MaxLOD = float_max_16;
  name = (char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  v9 = vostok::render::resource_manager::create_sampler_state(
         (vostok::render::resource_manager *)&sampler_props,
         (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
         (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *)&sampler_props);
  vostok::render::resource_manager::register_sampler(v10, name, (ID3D11SamplerState *)&stru_80CD4C, v9);
  sampler_props.m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
  sampler_props.m_desc.MipLODBias = 0.0;
  sampler_props.m_desc.MinLOD = 0.0;
  sampler_props.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_props.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_props.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_props.m_desc.MaxLOD = float_max_16;
  name = (char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  v11 = vostok::render::resource_manager::create_sampler_state(
          (vostok::render::resource_manager *)&sampler_props,
          (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *)&sampler_props);
  vostok::render::resource_manager::register_sampler(v12, name, (ID3D11SamplerState *)&stru_80CD54, v11);
  sampler_props.m_desc.MipLODBias = 0.0;
  sampler_props.m_desc.MinLOD = 0.0;
  sampler_props.m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
  sampler_props.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_props.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_props.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_props.m_desc.MaxLOD = float_max_16;
  name = (char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  v13 = vostok::render::resource_manager::create_sampler_state(
          (vostok::render::resource_manager *)&sampler_props,
          (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *)&sampler_props);
  vostok::render::resource_manager::register_sampler(v14, name, (ID3D11SamplerState *)&stru_80CD60, v13);
  sampler_props.m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
  sampler_props.m_desc.MipLODBias = 0.0;
  sampler_props.m_desc.MinLOD = 0.0;
  sampler_props.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_props.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_props.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_props.m_desc.MaxLOD = float_max_16;
  name = (char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  v15 = vostok::render::resource_manager::create_sampler_state(
          (vostok::render::resource_manager *)&sampler_props,
          (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *)&sampler_props);
  vostok::render::resource_manager::register_sampler(v16, name, (ID3D11SamplerState *)&stru_80CD6C, v15);
  name = (char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  v17 = vostok::render::resource_manager::create_sampler_state(
          (vostok::render::resource_manager *)&sampler_props,
          (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *)&sampler_props);
  vostok::render::resource_manager::register_sampler(v18, name, (ID3D11SamplerState *)&stru_80CD78, v17);
  name = (char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  v19 = vostok::render::resource_manager::create_sampler_state(
          (vostok::render::resource_manager *)&sampler_props,
          (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *)&sampler_props);
  vostok::render::resource_manager::register_sampler(v20, name, (ID3D11SamplerState *)&stru_80CD84, v19);
  sampler_props.m_desc.MipLODBias = 0.0;
  sampler_props.m_desc.MinLOD = 0.0;
  sampler_props.m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
  sampler_props.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_props.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_props.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_props.m_desc.MaxLOD = float_max_16;
  name = (char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  v21 = vostok::render::resource_manager::create_sampler_state(
          (vostok::render::resource_manager *)&sampler_props,
          (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *)&sampler_props);
  vostok::render::resource_manager::register_sampler(v22, name, (ID3D11SamplerState *)&stru_80CD94, v21);
  name = (char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  v23 = vostok::render::resource_manager::create_sampler_state(
          (vostok::render::resource_manager *)&sampler_props,
          (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *)&sampler_props);
  vostok::render::resource_manager::register_sampler(v24, name, (ID3D11SamplerState *)&stru_80CDA0, v23);
  sampler_props.m_desc.MipLODBias = 0.0;
  sampler_props.m_desc.MinLOD = 0.0;
  sampler_props.m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
  sampler_props.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_props.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_props.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_props.m_desc.MaxLOD = float_max_16;
  name = (char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  v25 = vostok::render::resource_manager::create_sampler_state(
          (vostok::render::resource_manager *)&sampler_props,
          (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *)&sampler_props);
  vostok::render::resource_manager::register_sampler(v26, name, (ID3D11SamplerState *)&stru_80CDAC, v25);
  sampler_props.m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
  sampler_props.m_desc.MipLODBias = 0.0;
  sampler_props.m_desc.MinLOD = 0.0;
  sampler_props.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_props.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_props.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_props.m_desc.MaxLOD = float_max_16;
  name = (char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  v27 = vostok::render::resource_manager::create_sampler_state(
          (vostok::render::resource_manager *)&sampler_props,
          (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *)&sampler_props);
  vostok::render::resource_manager::register_sampler(v28, name, (ID3D11SamplerState *)&stru_80CDB8, v27);
  sampler_props.m_desc.MipLODBias = 0.0;
  sampler_props.m_desc.MinLOD = 0.0;
  sampler_props.m_desc.Filter = D3D11_FILTER_MIN_MAG_LINEAR_MIP_POINT;
  sampler_props.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_props.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_props.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_props.m_desc.MaxLOD = float_max_16;
  name = (char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  v29 = vostok::render::resource_manager::create_sampler_state(
          (vostok::render::resource_manager *)&sampler_props,
          (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *)&sampler_props);
  vostok::render::resource_manager::register_sampler(v30, name, (ID3D11SamplerState *)&stru_80CDC4, v29);
  sampler_props.m_desc.MipLODBias = 0.0;
  sampler_props.m_desc.MinLOD = 0.0;
  sampler_props.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_props.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_props.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_props.m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
  sampler_props.m_desc.MaxLOD = float_max_16;
  v31 = (const char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  v32 = vostok::render::resource_manager::create_sampler_state(
          (vostok::render::resource_manager *)&sampler_props,
          (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *)&sampler_props);
  vostok::render::resource_manager::register_sampler(v33, v31, (ID3D11SamplerState *)&stru_80CDD0, v32);
  sampler_props.m_desc.MipLODBias = 0.0;
  sampler_props.m_desc.MinLOD = 0.0;
  sampler_props.m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
  sampler_props.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_BORDER;
  sampler_props.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_BORDER;
  sampler_props.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_BORDER;
  sampler_props.m_desc.MaxLOD = float_max_16;
  v34 = (const char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  v35 = vostok::render::resource_manager::create_sampler_state(
          (vostok::render::resource_manager *)&sampler_props,
          (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *)&sampler_props);
  vostok::render::resource_manager::register_sampler(v36, v34, (ID3D11SamplerState *)&stru_80CDDC, v35);
  sampler_props.m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
  sampler_props.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_BORDER;
  sampler_props.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_BORDER;
  sampler_props.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_BORDER;
  sampler_props.m_desc.MipLODBias = 0.0;
  sampler_props.m_desc.MaxLOD = float_max_16;
  memset(sampler_props.m_desc.BorderColor, 0, 20);
  name = (char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  v37 = vostok::render::resource_manager::create_sampler_state(
          (vostok::render::resource_manager *)&sampler_props,
          (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *)&sampler_props);
  vostok::render::resource_manager::register_sampler(v38, name, (ID3D11SamplerState *)&stru_80CDE8, v37);
  sampler_props.m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
  sampler_props.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_BORDER;
  sampler_props.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_BORDER;
  sampler_props.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_BORDER;
  sampler_props.m_desc.BorderColor[0] = FLOAT_2000_0;
  sampler_props.m_desc.BorderColor[1] = FLOAT_2000_0;
  sampler_props.m_desc.BorderColor[2] = FLOAT_2000_0;
  sampler_props.m_desc.BorderColor[3] = FLOAT_2000_0;
  name = (char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  v39 = vostok::render::resource_manager::create_sampler_state(
          (vostok::render::resource_manager *)&sampler_props,
          (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *)&sampler_props);
  vostok::render::resource_manager::register_sampler(v40, name, (ID3D11SamplerState *)&stru_80CDF4, v39);
  sampler_props.m_desc.MipLODBias = 0.0;
  sampler_props.m_desc.MinLOD = 0.0;
  sampler_props.m_desc.Filter = D3D11_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT;
  sampler_props.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_props.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_props.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_props.m_desc.MaxLOD = float_max_16;
  sampler_props.m_desc.ComparisonFunc = D3D11_COMPARISON_LESS_EQUAL;
  name = (char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  v41 = vostok::render::resource_manager::create_sampler_state(
          (vostok::render::resource_manager *)&sampler_props,
          (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *)&sampler_props);
  vostok::render::resource_manager::register_sampler(v42, name, (ID3D11SamplerState *)&stru_80CE00, v41);
  vostok::render::sampler_state_descriptor::reset(v43, &sampler_props);
  sampler_props.m_desc.MipLODBias = 0.0;
  sampler_props.m_desc.MinLOD = 0.0;
  sampler_props.m_desc.MaxLOD = float_max_16;
  sampler_props.m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
  sampler_props.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_BORDER;
  sampler_props.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_BORDER;
  sampler_props.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_BORDER;
  sampler_props.m_desc.BorderColor[0] = s_bm_current_air_resistance;
  sampler_props.m_desc.BorderColor[1] = s_bm_current_air_resistance;
  sampler_props.m_desc.BorderColor[2] = s_bm_current_air_resistance;
  sampler_props.m_desc.BorderColor[3] = s_bm_current_air_resistance;
  v44 = (const char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  v45 = vostok::render::resource_manager::create_sampler_state(
          (vostok::render::resource_manager *)&sampler_props,
          (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *)&sampler_props);
  vostok::render::resource_manager::register_sampler(v46, v44, (ID3D11SamplerState *)&stru_80CE08, v45);
  vostok::render::sampler_state_descriptor::reset(v47, &sampler_props);
  sampler_props.m_desc.MipLODBias = 0.0;
  sampler_props.m_desc.MinLOD = 0.0;
  sampler_props.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_props.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_props.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_props.m_desc.Filter = D3D11_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR;
  sampler_props.m_desc.MaxLOD = float_max_16;
  sampler_props.m_desc.ComparisonFunc = D3D11_COMPARISON_LESS_EQUAL;
  v48 = (const char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  v49 = vostok::render::resource_manager::create_sampler_state(
          (vostok::render::resource_manager *)&sampler_props,
          (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *)&sampler_props);
  vostok::render::resource_manager::register_sampler(v50, v48, (ID3D11SamplerState *)&stru_80CE1C, v49);
  vostok::render::resource_manager::bind_samplers_to_shaders(
    v51,
    (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
}
