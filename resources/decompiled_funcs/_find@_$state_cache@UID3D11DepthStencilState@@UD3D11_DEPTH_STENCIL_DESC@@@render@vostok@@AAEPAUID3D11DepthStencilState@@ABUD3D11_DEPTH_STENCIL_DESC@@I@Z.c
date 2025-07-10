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
