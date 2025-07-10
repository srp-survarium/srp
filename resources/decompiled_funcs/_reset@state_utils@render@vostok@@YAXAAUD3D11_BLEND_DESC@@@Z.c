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
