ID3D11RasterizerState *__userpurge vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC,32>::find@<eax>(
        vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC,32> *this@<eax>,
        const D3D11_RASTERIZER_DESC *desc@<esi>,
        unsigned int CRC)
{
  int v3; // ebx
  unsigned int v4; // edx
  vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC,32>::state_record *i; // ecx

  v3 = 0;
  v4 = this->states.m_end - this->states.m_begin;
  if ( !v4 )
    return 0;
  for ( i = this->states.m_begin;
        i->crc != CRC
     || i->desc.FillMode != desc->FillMode
     || i->desc.CullMode != desc->CullMode
     || i->desc.FrontCounterClockwise != desc->FrontCounterClockwise
     || i->desc.DepthBias != desc->DepthBias
     || i->desc.DepthBiasClamp != desc->DepthBiasClamp
     || i->desc.SlopeScaledDepthBias != desc->SlopeScaledDepthBias
     || i->desc.DepthClipEnable != desc->DepthClipEnable
     || i->desc.ScissorEnable != desc->ScissorEnable
     || i->desc.MultisampleEnable != desc->MultisampleEnable
     || i->desc.AntialiasedLineEnable != desc->AntialiasedLineEnable;
        ++i )
  {
    if ( ++v3 >= v4 )
      return 0;
  }
  if ( v3 == -1 )
    return 0;
  else
    return this->states.m_begin[v3].state;
}


ID3D11SamplerState *__userpurge vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32>::find@<eax>(
        vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *this@<eax>,
        const D3D11_SAMPLER_DESC *desc@<esi>,
        unsigned int CRC)
{
  int v3; // ebx
  vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32>::state_record *i; // ecx
  unsigned int v6; // [esp+8h] [ebp-4h]

  v3 = 0;
  v6 = this->states.m_end - this->states.m_begin;
  if ( !v6 )
    return 0;
  for ( i = this->states.m_begin;
        i->crc != CRC
     || i->desc.Filter != desc->Filter
     || i->desc.AddressU != desc->AddressU
     || i->desc.AddressV != desc->AddressV
     || i->desc.AddressW != desc->AddressW
     || i->desc.MipLODBias != desc->MipLODBias
     || i->desc.ComparisonFunc != desc->ComparisonFunc
     || i->desc.BorderColor[0] != desc->BorderColor[0]
     || i->desc.BorderColor[1] != desc->BorderColor[1]
     || i->desc.BorderColor[2] != desc->BorderColor[2]
     || i->desc.BorderColor[3] != desc->BorderColor[3]
     || i->desc.MinLOD != desc->MinLOD
     || i->desc.MaxLOD != desc->MaxLOD;
        ++i )
  {
    if ( ++v3 >= v6 )
      return 0;
  }
  if ( v3 == -1 )
    return 0;
  else
    return this->states.m_begin[v3].state;
}
