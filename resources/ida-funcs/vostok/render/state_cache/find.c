ID3D11BlendState *__userpurge vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC>::find@<eax>(
        vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC> *this@<ecx>,
        int *a2@<edi>,
        const D3D11_BLEND_DESC *desc,
        unsigned int CRC)
{
  int v4; // eax
  int v5; // esi
  D3D11_BLEND_DESC desc_candidate; // [esp+10h] [ebp-10Ch] BYREF

  v4 = *a2;
  v5 = 0;
  if ( !((a2[1] - *a2) >> 3) )
    return 0;
  while ( 1 )
  {
    if ( *(_DWORD *)(v4 + 8 * v5) == CRC )
    {
      (*(void (__stdcall **)(_DWORD, D3D11_BLEND_DESC *))(**(_DWORD **)(v4 + 8 * v5 + 4) + 28))(
        *(_DWORD *)(v4 + 8 * v5 + 4),
        &desc_candidate);
      if ( vostok::render::state_utils::operator==(&desc_candidate, desc) )
        break;
    }
    v4 = *a2;
    if ( ++v5 >= (unsigned int)((a2[1] - *a2) >> 3) )
      return 0;
  }
  if ( v5 == -1 )
    return 0;
  else
    return *(ID3D11BlendState **)(*a2 + 8 * v5 + 4);
}


ID3D11DepthStencilState *__userpurge vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC>::find@<eax>(
        vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC> *this@<ecx>,
        int *a2@<edi>,
        const D3D11_DEPTH_STENCIL_DESC *desc,
        unsigned int CRC)
{
  int v4; // eax
  int v5; // esi
  D3D11_DEPTH_STENCIL_DESC desc_candidate; // [esp+Ch] [ebp-34h] BYREF

  v4 = *a2;
  v5 = 0;
  if ( !((a2[1] - *a2) >> 3) )
    return 0;
  while ( 1 )
  {
    if ( *(_DWORD *)(v4 + 8 * v5) == CRC )
    {
      (*(void (__stdcall **)(_DWORD, D3D11_DEPTH_STENCIL_DESC *))(**(_DWORD **)(v4 + 8 * v5 + 4) + 28))(
        *(_DWORD *)(v4 + 8 * v5 + 4),
        &desc_candidate);
      if ( vostok::render::state_utils::operator==(&desc_candidate, desc) )
        break;
    }
    v4 = *a2;
    if ( ++v5 >= (unsigned int)((a2[1] - *a2) >> 3) )
      return 0;
  }
  if ( v5 == -1 )
    return 0;
  else
    return *(ID3D11DepthStencilState **)(*a2 + 8 * v5 + 4);
}


ID3D11RasterizerState *__userpurge vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::find@<eax>(
        const D3D11_RASTERIZER_DESC *desc@<edi>,
        vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC> *this,
        unsigned int CRC)
{
  vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record *M_start; // eax
  int v4; // esi
  D3D11_RASTERIZER_DESC desc_candidate; // [esp+10h] [ebp-2Ch] BYREF

  M_start = this->states._M_impl._M_start;
  v4 = 0;
  if ( !(this->states._M_impl._M_finish - this->states._M_impl._M_start) )
    return 0;
  while ( 1 )
  {
    if ( M_start[v4].crc == CRC )
    {
      M_start[v4].state->GetDesc(M_start[v4].state, &desc_candidate);
      if ( desc_candidate.FillMode == desc->FillMode
        && desc_candidate.CullMode == desc->CullMode
        && desc_candidate.FrontCounterClockwise == desc->FrontCounterClockwise
        && desc_candidate.DepthBias == desc->DepthBias
        && desc_candidate.DepthBiasClamp == desc->DepthBiasClamp
        && desc_candidate.SlopeScaledDepthBias == desc->SlopeScaledDepthBias
        && desc_candidate.DepthClipEnable == desc->DepthClipEnable
        && desc_candidate.ScissorEnable == desc->ScissorEnable
        && desc_candidate.MultisampleEnable == desc->MultisampleEnable
        && desc_candidate.AntialiasedLineEnable == desc->AntialiasedLineEnable )
      {
        break;
      }
    }
    M_start = this->states._M_impl._M_start;
    if ( ++v4 >= (unsigned int)(this->states._M_impl._M_finish - this->states._M_impl._M_start) )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  else
    return this->states._M_impl._M_start[v4].state;
}


ID3D11SamplerState *__userpurge vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::find@<eax>(
        vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC> *this@<ecx>,
        int *a2@<edi>,
        const D3D11_SAMPLER_DESC *desc,
        unsigned int CRC)
{
  int v4; // eax
  int v5; // esi
  D3D11_SAMPLER_DESC desc_candidate; // [esp+Ch] [ebp-34h] BYREF

  v4 = *a2;
  v5 = 0;
  if ( !((a2[1] - *a2) >> 3) )
    return 0;
  while ( 1 )
  {
    if ( *(_DWORD *)(v4 + 8 * v5) == CRC )
    {
      (*(void (__stdcall **)(_DWORD, D3D11_SAMPLER_DESC *))(**(_DWORD **)(v4 + 8 * v5 + 4) + 28))(
        *(_DWORD *)(v4 + 8 * v5 + 4),
        &desc_candidate);
      if ( vostok::render::state_utils::operator==(&desc_candidate, desc) )
        break;
    }
    v4 = *a2;
    if ( ++v5 >= (unsigned int)((a2[1] - *a2) >> 3) )
      return 0;
  }
  if ( v5 == -1 )
    return 0;
  else
    return *(ID3D11SamplerState **)(*a2 + 8 * v5 + 4);
}
