char __thiscall Scaleform::GFx::AS3ValueObjectInterface::SetDisplayMatrix(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  int v3; // eax
  Scaleform::GFx::DisplayObjectBase *v5; // edi
  double v6; // st7
  int v7; // eax
  double v8; // st7
  double v9; // st6
  float v10[3]; // [esp+F0h] [ebp-80h] BYREF
  float v11; // [esp+FCh] [ebp-74h]
  float v12; // [esp+100h] [ebp-70h]
  float v13; // [esp+104h] [ebp-6Ch]
  float v14; // [esp+108h] [ebp-68h]
  float v15; // [esp+10Ch] [ebp-64h]
  Scaleform::GFx::DisplayObjectBase::GeomDataType gd; // [esp+110h] [ebp-60h] BYREF

  v3 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v3 + 60) - 17) >= 0xC )
    return 0;
  if ( (*(_DWORD *)(v3 + 56) & 0x20) != 0 )
    return 0;
  v5 = (Scaleform::GFx::DisplayObjectBase *)pdata[12];
  if ( !Scaleform::Render::Matrix2x4<float>::IsValid(mat) )
    return 0;
  v10[0] = mat->M[0][0];
  v10[1] = mat->M[0][1];
  v10[2] = mat->M[0][2];
  v11 = mat->M[0][3];
  v12 = mat->M[1][0];
  v13 = mat->M[1][1];
  v14 = mat->M[1][2];
  v15 = mat->M[1][3];
  v11 = v11 * 20.0;
  v15 = 20.0 * v15;
  v5->SetMatrix(v5, (const Scaleform::Render::Matrix2x4<float> *)v10);
  Scaleform::GFx::DisplayObjectBase::GeomDataType::GeomDataType(&gd);
  Scaleform::GFx::DisplayObjectBase::GetGeomData(v5, &gd);
  v6 = mat->M[1][3];
  gd.X = (int)mat->M[0][3];
  v7 = (int)v6;
  v8 = mat->M[1][0];
  v9 = mat->M[0][0];
  gd.Y = v7;
  gd.XScale = sqrt(v8 * v8 + v9 * v9) * 100.0;
  gd.YScale = sqrt(mat->M[1][1] * mat->M[1][1] + mat->M[0][1] * mat->M[0][1]) * 100.0;
  gd.Rotation = atan2(mat->M[1][0], mat->M[0][0]) * 180.0 / 3.141592653589793;
  Scaleform::GFx::DisplayObjectBase::SetGeomData(v5, &gd);
  return 1;
}
