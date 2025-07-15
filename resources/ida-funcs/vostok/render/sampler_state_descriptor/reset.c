vostok::render::sampler_state_descriptor *__usercall vostok::render::sampler_state_descriptor::reset@<eax>(
        vostok::render::sampler_state_descriptor *this@<ecx>,
        vostok::render::sampler_state_descriptor *result@<eax>)
{
  float v2; // xmm0_4

  result->m_desc.MipLODBias = 0.0;
  v2 = s_bm_current_air_resistance;
  result->m_desc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
  result->m_desc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
  result->m_desc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
  result->m_desc.BorderColor[0] = v2;
  result->m_desc.BorderColor[1] = v2;
  result->m_desc.BorderColor[2] = v2;
  result->m_desc.BorderColor[3] = v2;
  result->m_desc.MinLOD = FLOAT_N3_4028235e38;
  result->m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
  result->m_desc.MaxAnisotropy = 1;
  result->m_desc.ComparisonFunc = D3D11_COMPARISON_NEVER;
  result->m_desc.MaxLOD = FLOAT_3_4028235e38;
  return result;
}
