char __thiscall Scaleform::GFx::AS2ValueObjectInterface::SetDisplayMatrix(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  Scaleform::GFx::InteractiveObject *v3; // edi
  double v5; // st7
  int v6; // eax
  double v7; // st7
  double v8; // st6
  float v9[3]; // [esp+F0h] [ebp-80h] BYREF
  float v10; // [esp+FCh] [ebp-74h]
  float v11; // [esp+100h] [ebp-70h]
  float v12; // [esp+104h] [ebp-6Ch]
  float v13; // [esp+108h] [ebp-68h]
  float v14; // [esp+10Ch] [ebp-64h]
  Scaleform::GFx::DisplayObjectBase::GeomDataType gd; // [esp+110h] [ebp-60h] BYREF

  v3 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( !v3 || !Scaleform::Render::Matrix2x4<float>::IsValid(mat) )
    return 0;
  v9[0] = mat->M[0][0];
  v9[1] = mat->M[0][1];
  v9[2] = mat->M[0][2];
  v10 = mat->M[0][3];
  v11 = mat->M[1][0];
  v12 = mat->M[1][1];
  v13 = mat->M[1][2];
  v14 = mat->M[1][3];
  v10 = v10 * 20.0;
  v14 = 20.0 * v14;
  v3->SetMatrix(v3, (const Scaleform::Render::Matrix2x4<float> *)v9);
  Scaleform::GFx::DisplayObjectBase::GeomDataType::GeomDataType(&gd);
  Scaleform::GFx::DisplayObjectBase::GetGeomData(v3, &gd);
  v5 = mat->M[1][3];
  gd.X = (int)mat->M[0][3];
  v6 = (int)v5;
  v7 = mat->M[1][0];
  v8 = mat->M[0][0];
  gd.Y = v6;
  gd.XScale = sqrt(v7 * v7 + v8 * v8) * 100.0;
  gd.YScale = sqrt(mat->M[1][1] * mat->M[1][1] + mat->M[0][1] * mat->M[0][1]) * 100.0;
  gd.Rotation = atan2(mat->M[1][0], mat->M[0][0]) * 180.0 / 3.141592653589793;
  Scaleform::GFx::DisplayObjectBase::SetGeomData(v3, &gd);
  return 1;
}
