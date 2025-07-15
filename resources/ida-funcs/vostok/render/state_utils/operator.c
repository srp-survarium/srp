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


bool __usercall vostok::render::state_utils::operator==@<al>(
        const D3D11_DEPTH_STENCIL_DESC *desc1@<ecx>,
        const D3D11_DEPTH_STENCIL_DESC *desc2@<eax>)
{
  return desc1->DepthEnable == desc2->DepthEnable
      && desc1->DepthWriteMask == desc2->DepthWriteMask
      && desc1->DepthFunc == desc2->DepthFunc
      && desc1->StencilEnable == desc2->StencilEnable
      && desc1->StencilReadMask == desc2->StencilReadMask
      && desc1->StencilWriteMask == desc2->StencilWriteMask
      && desc1->FrontFace.StencilFailOp == desc2->FrontFace.StencilFailOp
      && desc1->FrontFace.StencilDepthFailOp == desc2->FrontFace.StencilDepthFailOp
      && desc1->FrontFace.StencilPassOp == desc2->FrontFace.StencilPassOp
      && desc1->FrontFace.StencilFunc == desc2->FrontFace.StencilFunc
      && desc1->BackFace.StencilFailOp == desc2->BackFace.StencilFailOp
      && desc1->BackFace.StencilDepthFailOp == desc2->BackFace.StencilDepthFailOp
      && desc1->BackFace.StencilPassOp == desc2->BackFace.StencilPassOp
      && desc1->BackFace.StencilFunc == desc2->BackFace.StencilFunc;
}


bool __fastcall vostok::render::state_utils::operator==(
        const D3D11_RASTERIZER_DESC *desc2,
        const D3D11_RASTERIZER_DESC *desc1)
{
  return desc1->FillMode == desc2->FillMode
      && desc1->CullMode == desc2->CullMode
      && desc1->FrontCounterClockwise == desc2->FrontCounterClockwise
      && desc1->DepthBias == desc2->DepthBias
      && desc1->DepthBiasClamp == desc2->DepthBiasClamp
      && desc1->SlopeScaledDepthBias == desc2->SlopeScaledDepthBias
      && desc1->DepthClipEnable == desc2->DepthClipEnable
      && desc1->ScissorEnable == desc2->ScissorEnable
      && desc1->MultisampleEnable == desc2->MultisampleEnable
      && desc1->AntialiasedLineEnable == desc2->AntialiasedLineEnable;
}


bool __fastcall vostok::render::state_utils::operator==(
        const D3D11_SAMPLER_DESC *desc2,
        const D3D11_SAMPLER_DESC *desc1)
{
  return desc1->Filter == desc2->Filter
      && desc1->AddressU == desc2->AddressU
      && desc1->AddressV == desc2->AddressV
      && desc1->AddressW == desc2->AddressW
      && desc1->MipLODBias == desc2->MipLODBias
      && desc1->ComparisonFunc == desc2->ComparisonFunc
      && desc1->BorderColor[0] == desc2->BorderColor[0]
      && desc1->BorderColor[1] == desc2->BorderColor[1]
      && desc1->BorderColor[2] == desc2->BorderColor[2]
      && desc1->BorderColor[3] == desc2->BorderColor[3]
      && desc1->MinLOD == desc2->MinLOD
      && desc1->MaxLOD == desc2->MaxLOD;
}
