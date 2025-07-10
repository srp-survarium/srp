char __thiscall Scaleform::Render::D3D1x::HAL::createBlendStates(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::D3D1x::HAL *thisa)
{
  unsigned int v2; // esi
  char v3; // bl
  unsigned int v4; // ecx
  D3D11_BLEND v5; // edx
  D3D11_BLEND v6; // edi
  unsigned int v7; // eax
  D3D11_BLEND v8; // ecx
  D3D11_BLEND v9; // eax
  ID3D11BlendState **i; // [esp+Ch] [ebp-10Ch]
  D3D11_BLEND_DESC desc; // [esp+10h] [ebp-108h] BYREF

  memset((int)thisa->BlendStates, 0, sizeof(thisa->BlendStates));
  v2 = 0;
  for ( i = thisa->BlendStates; ; ++i )
  {
    memset((int)&desc, 0, sizeof(desc));
    v3 = 0;
    v4 = v2;
    if ( v2 < 0x24 )
    {
      desc.RenderTarget[0].BlendEnable = 1;
      desc.RenderTarget[0].RenderTargetWriteMask = 15;
      if ( v2 >= 0x12 )
      {
        v4 = v2 - 18;
        v3 = 1;
      }
    }
    else
    {
      desc.RenderTarget[0].BlendEnable = 0;
      desc.RenderTarget[0].RenderTargetWriteMask = 0;
    }
    v5 = dword_A8A15C[5 * (v4 % 0x12)];
    v6 = dword_A8A160[5 * (v4 % 0x12)];
    v7 = 5 * (v4 % 0x12);
    desc.RenderTarget[0].BlendOp = acmodes[v7 / 5].BlendOp;
    desc.RenderTarget[0].BlendOpAlpha = desc.RenderTarget[0].BlendOp;
    v8 = dword_A8A164[v7];
    v9 = dword_A8A168[v7];
    desc.RenderTarget[0].SrcBlend = v5;
    desc.RenderTarget[0].DestBlend = v6;
    desc.RenderTarget[0].SrcBlendAlpha = v8;
    desc.RenderTarget[0].DestBlendAlpha = v9;
    if ( v3 )
    {
      if ( v5 == D3D11_BLEND_SRC_ALPHA )
        desc.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;
    }
    if ( thisa->pDevice->CreateBlendState(thisa->pDevice, &desc, i) < 0 )
      break;
    if ( ++v2 >= 0x25 )
      return 1;
  }
  return 0;
}
