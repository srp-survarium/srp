char __thiscall Scaleform::Render::D3D1x::HAL::createConstantBuffers(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::D3D1x::HAL *thisa)
{
  int v2; // edi
  ID3D11Buffer **i; // esi
  ID3D11Device *pDevice; // eax
  __int128 v6; // [esp+28h] [ebp-20h] BYREF
  __int64 v7; // [esp+38h] [ebp-10h]

  *(_QWORD *)thisa->ConstantBuffers = 0;
  *(_QWORD *)&thisa->ConstantBuffers[2] = 0;
  *(_QWORD *)&thisa->ConstantBuffers[4] = 0;
  *(_QWORD *)&thisa->ConstantBuffers[6] = 0;
  v6 = 0;
  v7 = 0;
  v2 = 0;
  for ( i = thisa->ConstantBuffers; ; ++i )
  {
    pDevice = thisa->pDevice;
    *(_QWORD *)&v6 = 0x2000040C0LL;
    DWORD2(v6) = 4;
    HIDWORD(v6) = &_sbh_sizeHeaderList;
    if ( pDevice->CreateBuffer(pDevice, (const D3D11_BUFFER_DESC *)&v6, 0, i) < 0 )
      break;
    if ( (unsigned int)++v2 >= 8 )
      return 1;
  }
  return 0;
}
