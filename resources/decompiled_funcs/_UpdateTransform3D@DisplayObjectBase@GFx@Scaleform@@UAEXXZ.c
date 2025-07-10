void __thiscall Scaleform::GFx::DisplayObjectBase::UpdateTransform3D(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // eax
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v3; // eax
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v4; // esi
  Scaleform::Render::Matrix3x4<float> *v5; // eax
  Scaleform::Render::Matrix3x4<float> *v6; // eax
  Scaleform::Render::Matrix3x4<float> *v7; // eax
  float XScale; // [esp+4ECh] [ebp-1B4h]
  float YScale; // [esp+4ECh] [ebp-1B4h]
  float ZScale; // [esp+4ECh] [ebp-1B4h]
  float angle; // [esp+4ECh] [ebp-1B4h]
  float v12; // [esp+4ECh] [ebp-1B4h]
  float v13; // [esp+4ECh] [ebp-1B4h]
  Scaleform::Render::Matrix3x4<float> dst; // [esp+4F0h] [ebp-1B0h] BYREF
  Scaleform::Render::Matrix3x4<float> result; // [esp+520h] [ebp-180h] BYREF
  Scaleform::Render::Matrix3x4<float> v16; // [esp+550h] [ebp-150h] BYREF
  Scaleform::Render::Matrix3x4<float> v17; // [esp+580h] [ebp-120h] BYREF
  Scaleform::Render::Matrix3x4<float> v18; // [esp+5B0h] [ebp-F0h] BYREF
  Scaleform::Render::Matrix3x4<float> v19; // [esp+5E0h] [ebp-C0h] BYREF
  Scaleform::Render::Matrix3x4<float> m1; // [esp+610h] [ebp-90h] BYREF
  Scaleform::Render::Matrix3x4<float> m2; // [esp+640h] [ebp-60h] BYREF
  Scaleform::Render::Matrix3x4<float> v22; // [esp+670h] [ebp-30h] BYREF

  memset((int)&dst, 0, sizeof(dst));
  pGeomData = this->pGeomData;
  dst.M[0][0] = 1.0;
  dst.M[1][1] = 1.0;
  dst.M[2][2] = 1.0;
  dst.M[0][3] = (float)pGeomData->X;
  dst.M[1][3] = (float)pGeomData->Y;
  dst.M[2][3] = pGeomData->Z;
  memcpy((unsigned __int8 *)&v22, (unsigned __int8 *)&dst, sizeof(v22));
  memset((int)&dst, 0, sizeof(dst));
  v3 = this->pGeomData;
  XScale = v3->XScale;
  dst.M[0][0] = XScale / 100.0;
  YScale = v3->YScale;
  dst.M[1][1] = YScale / 100.0;
  ZScale = v3->ZScale;
  dst.M[2][2] = ZScale / 100.0;
  memcpy((unsigned __int8 *)&m2, (unsigned __int8 *)&dst, sizeof(m2));
  v4 = this->pGeomData;
  if ( 0.0 == v4->XRotation )
  {
    v5 = &Scaleform::Render::Matrix3x4<float>::Identity;
  }
  else
  {
    angle = v4->XRotation * 3.141592653589793 / 180.0;
    v5 = Scaleform::Render::Matrix3x4<float>::RotationX(&result, angle);
  }
  memcpy((unsigned __int8 *)&m1, (unsigned __int8 *)v5, sizeof(m1));
  if ( 0.0 == v4->YRotation )
  {
    v6 = &Scaleform::Render::Matrix3x4<float>::Identity;
  }
  else
  {
    v12 = v4->YRotation * 3.141592653589793 / 180.0;
    v6 = Scaleform::Render::Matrix3x4<float>::RotationY(&result, v12);
  }
  memcpy((unsigned __int8 *)&v16, (unsigned __int8 *)v6, sizeof(v16));
  if ( 0.0 == v4->Rotation )
  {
    v7 = &Scaleform::Render::Matrix3x4<float>::Identity;
  }
  else
  {
    v13 = v4->Rotation * 3.141592653589793 / 180.0;
    v7 = Scaleform::Render::Matrix3x4<float>::RotationZ(&result, v13);
  }
  memcpy((unsigned __int8 *)&v19, (unsigned __int8 *)v7, sizeof(v19));
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v17, &m1, &m2);
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v18, &v19, &v16);
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&result, &v18, &v17);
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&dst, &v22, &result);
  if ( Scaleform::Render::Matrix3x4<float>::IsValid(&dst) )
    this->SetMatrix3D(this, &dst);
}
