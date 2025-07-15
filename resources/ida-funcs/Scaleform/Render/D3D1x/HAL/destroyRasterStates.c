void __thiscall Scaleform::Render::D3D1x::HAL::destroyRasterStates(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::D3D1x::HAL *thisa)
{
  ID3D11RasterizerState **RasterStates; // esi
  int v3; // edi

  RasterStates = thisa->RasterStates;
  v3 = 2;
  do
  {
    if ( *RasterStates )
      (*RasterStates)->Release(*RasterStates);
    ++RasterStates;
    --v3;
  }
  while ( v3 );
  *(_QWORD *)thisa->RasterStates = 0;
}
