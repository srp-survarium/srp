void __usercall vostok::render::state_utils::reset(D3D11_BLEND_DESC *desc@<eax>)
{
  D3D11_BLEND *p_SrcBlend; // eax
  int v3; // edx

  memset((int)desc, 0, sizeof(D3D11_BLEND_DESC));
  desc->AlphaToCoverageEnable = 0;
  desc->IndependentBlendEnable = 0;
  p_SrcBlend = &desc->RenderTarget[0].SrcBlend;
  v3 = 8;
  do
  {
    *((_DWORD *)p_SrcBlend - 1) = 0;
    *p_SrcBlend = D3D11_BLEND_ONE;
    *((_DWORD *)p_SrcBlend + 1) = 1;
    *((_DWORD *)p_SrcBlend + 2) = 1;
    *((_DWORD *)p_SrcBlend + 3) = 2;
    *((_DWORD *)p_SrcBlend + 4) = 1;
    *((_DWORD *)p_SrcBlend + 5) = 1;
    *((_BYTE *)p_SrcBlend + 24) = 15;
    p_SrcBlend += 8;
    --v3;
  }
  while ( v3 );
}


void __usercall vostok::render::state_utils::reset(D3D11_DEPTH_STENCIL_DESC *desc@<esi>)
{
  memset((int)desc, 0, sizeof(D3D11_DEPTH_STENCIL_DESC));
  desc->StencilReadMask = 127;
  desc->StencilWriteMask = 127;
  desc->DepthEnable = 1;
  desc->DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
  desc->DepthFunc = D3D11_COMPARISON_LESS;
  desc->StencilEnable = 1;
  desc->FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
  desc->FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
  desc->FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
  desc->FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
  desc->BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
  desc->BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
  desc->BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
  desc->BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
}


void __usercall vostok::render::state_utils::reset(D3D11_RASTERIZER_DESC *desc@<eax>)
{
  *(_QWORD *)&desc->FillMode = 0;
  *(_QWORD *)&desc->FrontCounterClockwise = 0;
  *(_QWORD *)&desc->DepthBiasClamp = 0;
  *(_QWORD *)&desc->DepthClipEnable = 0;
  *(_QWORD *)&desc->MultisampleEnable = 0;
  desc->FillMode = D3D11_FILL_SOLID;
  desc->CullMode = D3D11_CULL_BACK;
  desc->FrontCounterClockwise = 0;
  desc->DepthBias = 0;
  desc->DepthBiasClamp = 0.0;
  desc->SlopeScaledDepthBias = 0.0;
  desc->DepthClipEnable = 1;
  desc->ScissorEnable = 0;
  desc->MultisampleEnable = 0;
  desc->AntialiasedLineEnable = 0;
}
