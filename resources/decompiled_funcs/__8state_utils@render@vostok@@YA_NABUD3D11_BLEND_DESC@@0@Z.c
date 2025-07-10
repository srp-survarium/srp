char __usercall vostok::render::state_utils::operator==@<al>(
        const D3D11_BLEND_DESC *desc1@<eax>,
        const D3D11_BLEND_DESC *desc2@<edx>)
{
  int v4; // edi
  D3D11_BLEND *p_DestBlend; // ecx
  D3D11_RENDER_TARGET_BLEND_DESC *RenderTarget; // eax
  int v7; // esi

  if ( desc1->AlphaToCoverageEnable != desc2->AlphaToCoverageEnable
    || desc1->IndependentBlendEnable != desc2->IndependentBlendEnable )
  {
    return 0;
  }
  v4 = 0;
  p_DestBlend = &desc1->RenderTarget[0].DestBlend;
  RenderTarget = desc2->RenderTarget;
  v7 = (char *)desc1 - (char *)desc2;
  while ( *(int *)((char *)&RenderTarget->BlendEnable + v7) == RenderTarget->BlendEnable
       && *((_DWORD *)p_DestBlend - 1) == RenderTarget->SrcBlend
       && *p_DestBlend == RenderTarget->DestBlend
       && *((_DWORD *)p_DestBlend + 1) == RenderTarget->BlendOp
       && *((_DWORD *)p_DestBlend + 2) == RenderTarget->SrcBlendAlpha
       && *((_DWORD *)p_DestBlend + 3) == RenderTarget->DestBlendAlpha
       && *((_DWORD *)p_DestBlend + 4) == RenderTarget->BlendOpAlpha
       && *((_BYTE *)p_DestBlend + 20) == RenderTarget->RenderTargetWriteMask )
  {
    ++v4;
    p_DestBlend += 8;
    ++RenderTarget;
    if ( v4 >= 8 )
      return 1;
  }
  return 0;
}
