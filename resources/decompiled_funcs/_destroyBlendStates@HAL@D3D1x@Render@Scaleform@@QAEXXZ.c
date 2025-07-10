void __thiscall Scaleform::Render::D3D1x::HAL::destroyBlendStates(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::D3D1x::HAL *thisa)
{
  ID3D11BlendState **BlendStates; // esi
  int v3; // edi

  BlendStates = thisa->BlendStates;
  v3 = 37;
  do
  {
    if ( *BlendStates )
      (*BlendStates)->Release(*BlendStates);
    ++BlendStates;
    --v3;
  }
  while ( v3 );
  memset((int)thisa->BlendStates, 0, sizeof(thisa->BlendStates));
}
