void __thiscall Scaleform::GFx::DisplayObjectBase::UpdateTransform3D(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // eax
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v3; // eax
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v4; // esi
  Scaleform::Render::Matrix3x4<float> *v5; // eax
  Scaleform::Render::Matrix3x4<float> *v6; // eax
  Scaleform::Render::Matrix3x4<float> *v7; // eax
  float XScale; // [esp+10h] [ebp-1B4h]
  float YScale; // [esp+10h] [ebp-1B4h]
  float ZScale; // [esp+10h] [ebp-1B4h]
  float angle; // [esp+10h] [ebp-1B4h]
  float v12; // [esp+10h] [ebp-1B4h]
  float v13; // [esp+10h] [ebp-1B4h]
  Scaleform::Render::Matrix3x4<float> src; // [esp+14h] [ebp-1B0h] BYREF
  Scaleform::Render::Matrix3x4<float> result; // [esp+44h] [ebp-180h] BYREF
  Scaleform::Render::Matrix3x4<float> v16; // [esp+74h] [ebp-150h] BYREF
  Scaleform::Render::Matrix3x4<float> v17; // [esp+A4h] [ebp-120h] BYREF
  Scaleform::Render::Matrix3x4<float> v18; // [esp+D4h] [ebp-F0h] BYREF
  Scaleform::Render::Matrix3x4<float> v19; // [esp+104h] [ebp-C0h] BYREF
  Scaleform::Render::Matrix3x4<float> m1; // [esp+134h] [ebp-90h] BYREF
  Scaleform::Render::Matrix3x4<float> m2; // [esp+164h] [ebp-60h] BYREF
  Scaleform::Render::Matrix3x4<float> dst; // [esp+194h] [ebp-30h] BYREF

  memset((int)&src, 0, sizeof(src));
  pGeomData = this->pGeomData;
  src.M[0][0] = 1.0;
  src.M[1][1] = 1.0;
  src.M[2][2] = 1.0;
  src.M[0][3] = (float)pGeomData->X;
  src.M[1][3] = (float)pGeomData->Y;
  src.M[2][3] = pGeomData->Z;
  memcpy((int)&dst, (const __m128i *)&src, sizeof(dst));
  memset((int)&src, 0, sizeof(src));
  v3 = this->pGeomData;
  XScale = v3->XScale;
  src.M[0][0] = XScale / 100.0;
  YScale = v3->YScale;
  src.M[1][1] = YScale / 100.0;
  ZScale = v3->ZScale;
  src.M[2][2] = ZScale / 100.0;
  memcpy((int)&m2, (const __m128i *)&src, sizeof(m2));
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
  memcpy((int)&m1, (const __m128i *)v5, sizeof(m1));
  if ( 0.0 == v4->YRotation )
  {
    v6 = &Scaleform::Render::Matrix3x4<float>::Identity;
  }
  else
  {
    v12 = v4->YRotation * 3.141592653589793 / 180.0;
    v6 = Scaleform::Render::Matrix3x4<float>::RotationY(&result, v12);
  }
  memcpy((int)&v16, (const __m128i *)v6, sizeof(v16));
  if ( 0.0 == v4->Rotation )
  {
    v7 = &Scaleform::Render::Matrix3x4<float>::Identity;
  }
  else
  {
    v13 = v4->Rotation * 3.141592653589793 / 180.0;
    v7 = Scaleform::Render::Matrix3x4<float>::RotationZ(&result, v13);
  }
  memcpy((int)&v19, (const __m128i *)v7, sizeof(v19));
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v17, &m1, &m2);
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v18, &v19, &v16);
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&result, &v18, &v17);
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&src, &dst, &result);
  if ( Scaleform::Render::Matrix3x4<float>::IsValid(&src) )
    this->SetMatrix3D(this, &src);
}
