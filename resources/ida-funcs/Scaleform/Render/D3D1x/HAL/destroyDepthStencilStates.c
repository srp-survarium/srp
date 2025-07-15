void __thiscall Scaleform::Render::D3D1x::HAL::destroyDepthStencilStates(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::D3D1x::HAL *thisa)
{
  ID3D11DepthStencilState **DepthStencilStates; // esi
  int v3; // edi

  DepthStencilStates = thisa->DepthStencilStates;
  v3 = 8;
  do
  {
    if ( *DepthStencilStates )
      (*DepthStencilStates)->Release(*DepthStencilStates);
    ++DepthStencilStates;
    --v3;
  }
  while ( v3 );
  *(_QWORD *)thisa->DepthStencilStates = 0;
  *(_QWORD *)&thisa->DepthStencilStates[2] = 0;
  *(_QWORD *)&thisa->DepthStencilStates[4] = 0;
  *(_QWORD *)&thisa->DepthStencilStates[6] = 0;
}
