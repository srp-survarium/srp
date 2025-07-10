char __thiscall Scaleform::Render::D3D1x::HAL::createDepthStencilStates(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::D3D1x::HAL *thisa)
{
  int v2; // esi
  ID3D11Device *pDevice; // eax
  D3D11_DEPTH_STENCIL_DESC desc; // [esp+4h] [ebp-34h] BYREF

  *(_QWORD *)thisa->DepthStencilStates = 0;
  *(_QWORD *)&thisa->DepthStencilStates[2] = 0;
  v2 = 0;
  *(_QWORD *)&thisa->DepthStencilStates[4] = 0;
  *(_QWORD *)&thisa->DepthStencilStates[6] = 0;
  while ( 1 )
  {
    memset((int)&desc, 0, sizeof(desc));
    desc.DepthFunc = D3D11_COMPARISON_ALWAYS;
    desc.StencilReadMask = -1;
    desc.StencilWriteMask = -1;
    desc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
    desc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
    desc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
    desc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
    switch ( v2 )
    {
      case 0:
        desc.StencilEnable = 0;
        break;
      case 1:
        desc.StencilEnable = 1;
        desc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
        desc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_REPLACE;
        desc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_REPLACE;
        break;
      case 2:
        desc.StencilEnable = 1;
        desc.FrontFace.StencilFunc = D3D11_COMPARISON_LESS_EQUAL;
        desc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_REPLACE;
        desc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
        desc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
        break;
      case 3:
        desc.StencilEnable = 1;
        desc.FrontFace.StencilFunc = D3D11_COMPARISON_EQUAL;
        desc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_INCR;
        desc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
        break;
      case 4:
        desc.DepthEnable = 1;
        desc.DepthFunc = D3D11_COMPARISON_ALWAYS;
        desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
        break;
      case 5:
        desc.StencilEnable = 1;
        desc.FrontFace.StencilFunc = D3D11_COMPARISON_LESS_EQUAL;
        desc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
        break;
      case 6:
        desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
        desc.DepthEnable = 1;
        desc.DepthFunc = D3D11_COMPARISON_EQUAL;
        break;
      case 7:
        desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
        desc.DepthEnable = 0;
        break;
      default:
        break;
    }
    pDevice = thisa->pDevice;
    desc.BackFace = desc.FrontFace;
    if ( pDevice->CreateDepthStencilState(pDevice, &desc, &thisa->DepthStencilStates[v2]) < 0 )
      return 0;
    if ( (unsigned int)++v2 >= 8 )
      return 1;
  }
}
