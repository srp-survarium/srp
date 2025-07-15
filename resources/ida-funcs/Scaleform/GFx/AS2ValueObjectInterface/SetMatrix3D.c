char __thiscall Scaleform::GFx::AS2ValueObjectInterface::SetMatrix3D(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::Render::Matrix3x4<float> *mat)
{
  Scaleform::GFx::InteractiveObject *v3; // esi
  float eX; // [esp+224h] [ebp-98h] BYREF
  float eY; // [esp+228h] [ebp-94h] BYREF
  unsigned __int8 dst[48]; // [esp+22Ch] [ebp-90h] BYREF
  Scaleform::GFx::DisplayObjectBase::GeomDataType gd; // [esp+25Ch] [ebp-60h] BYREF

  v3 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( !v3 || !Scaleform::Render::Matrix3x4<float>::IsValid(mat) )
    return 0;
  memcpy(dst, (unsigned __int8 *)mat, sizeof(dst));
  *(float *)&dst[12] = *(float *)&dst[12] * 20.0;
  *(float *)&dst[28] = 20.0 * *(float *)&dst[28];
  v3->SetMatrix3D(v3, (const Scaleform::Render::Matrix3x4<float> *)dst);
  Scaleform::GFx::DisplayObjectBase::GeomDataType::GeomDataType(&gd);
  Scaleform::GFx::DisplayObjectBase::GetGeomData(v3, &gd);
  gd.Z = mat->M[2][3];
  eX = mat->M[1][2] * mat->M[1][2] + mat->M[0][2] * mat->M[0][2] + mat->M[2][2] * mat->M[2][2];
  eX = sqrt(eX);
  gd.ZScale = eX * 100.0;
  Scaleform::Render::Matrix3x4<float>::GetEulerAngles(mat, &eX, &eY, 0);
  gd.XRotation = eX * 180.0 / 3.141592653589793;
  gd.YRotation = 180.0 * eY / 3.141592653589793;
  Scaleform::GFx::DisplayObjectBase::SetGeomData(v3, &gd);
  return 1;
}
