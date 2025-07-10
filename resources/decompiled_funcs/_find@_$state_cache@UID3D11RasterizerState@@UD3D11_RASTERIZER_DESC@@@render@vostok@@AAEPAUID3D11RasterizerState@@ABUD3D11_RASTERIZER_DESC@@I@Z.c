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
