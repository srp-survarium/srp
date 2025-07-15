char __thiscall Scaleform::GFx::AS3ValueObjectInterface::SetMatrix3D(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata,
        Scaleform::Render::Matrix3x4<float> *mat)
{
  int v3; // eax
  Scaleform::GFx::DisplayObjectBase *v5; // edi
  float eX; // [esp+224h] [ebp-98h] BYREF
  float eY; // [esp+228h] [ebp-94h] BYREF
  unsigned __int8 dst[48]; // [esp+22Ch] [ebp-90h] BYREF
  Scaleform::GFx::DisplayObjectBase::GeomDataType gd; // [esp+25Ch] [ebp-60h] BYREF

  v3 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v3 + 60) - 17) >= 0xC )
    return 0;
  if ( (*(_DWORD *)(v3 + 56) & 0x20) != 0 )
    return 0;
  v5 = (Scaleform::GFx::DisplayObjectBase *)pdata[12];
  if ( !Scaleform::Render::Matrix3x4<float>::IsValid(mat) )
    return 0;
  memcpy(dst, (unsigned __int8 *)mat, sizeof(dst));
  *(float *)&dst[12] = *(float *)&dst[12] * 20.0;
  *(float *)&dst[28] = *(float *)&dst[28] * 20.0;
  *(float *)&dst[44] = 20.0 * *(float *)&dst[44];
  v5->SetMatrix3D(v5, (const Scaleform::Render::Matrix3x4<float> *)dst);
  Scaleform::GFx::DisplayObjectBase::GeomDataType::GeomDataType(&gd);
  Scaleform::GFx::DisplayObjectBase::GetGeomData(v5, &gd);
  gd.Z = mat->M[2][3];
  eX = mat->M[1][2] * mat->M[1][2] + mat->M[0][2] * mat->M[0][2] + mat->M[2][2] * mat->M[2][2];
  eX = sqrt(eX);
  gd.ZScale = eX * 100.0;
  Scaleform::Render::Matrix3x4<float>::GetEulerAngles(mat, &eX, &eY, 0);
  gd.XRotation = eX * 180.0 / 3.141592653589793;
  gd.YRotation = 180.0 * eY / 3.141592653589793;
  Scaleform::GFx::DisplayObjectBase::SetGeomData(v5, &gd);
  return 1;
}
