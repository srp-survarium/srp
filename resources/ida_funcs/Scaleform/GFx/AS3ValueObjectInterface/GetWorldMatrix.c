char __thiscall Scaleform::GFx::AS3ValueObjectInterface::GetWorldMatrix(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata,
        Scaleform::Render::Matrix2x4<float> *pmat)
{
  int v3; // eax
  Scaleform::GFx::DisplayObjectBase *v5; // ecx
  Scaleform::Render::Matrix2x4<float> v6; // [esp+20h] [ebp-20h] BYREF

  v3 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v3 + 60) - 17) >= 0xC || (*(_DWORD *)(v3 + 56) & 0x20) != 0 )
    return 0;
  v5 = (Scaleform::GFx::DisplayObjectBase *)pdata[12];
  v6.M[0][0] = 1.0;
  v6.M[0][1] = 0.0;
  v6.M[0][2] = 0.0;
  v6.M[0][3] = 0.0;
  v6.M[1][0] = 0.0;
  v6.M[1][2] = 0.0;
  v6.M[1][3] = 0.0;
  v6.M[1][1] = 1.0;
  Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v5, &v6);
  v6.M[0][3] = v6.M[0][3] * 0.05000000074505806;
  v6.M[1][3] = 0.05000000074505806 * v6.M[1][3];
  *pmat = v6;
  return 1;
}
