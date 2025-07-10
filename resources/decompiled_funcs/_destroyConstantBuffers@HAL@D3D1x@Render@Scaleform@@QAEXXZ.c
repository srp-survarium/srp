void __thiscall Scaleform::Render::D3D1x::HAL::destroyConstantBuffers(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::D3D1x::HAL *thisa)
{
  ID3D11Buffer **ConstantBuffers; // esi
  int v3; // edi

  ConstantBuffers = thisa->ConstantBuffers;
  v3 = 8;
  do
  {
    if ( *ConstantBuffers )
      (*ConstantBuffers)->Release(*ConstantBuffers);
    ++ConstantBuffers;
    --v3;
  }
  while ( v3 );
  *(_QWORD *)thisa->ConstantBuffers = 0;
  *(_QWORD *)&thisa->ConstantBuffers[2] = 0;
  *(_QWORD *)&thisa->ConstantBuffers[4] = 0;
  *(_QWORD *)&thisa->ConstantBuffers[6] = 0;
}
