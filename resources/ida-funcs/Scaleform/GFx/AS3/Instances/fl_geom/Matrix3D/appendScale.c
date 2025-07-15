void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::appendScale(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        const Scaleform::GFx::AS3::Value *result,
        long double xScale,
        long double yScale,
        long double zScale)
{
  Scaleform::Render::Matrix4x4<double> m1; // [esp+F0h] [ebp-160h] BYREF
  unsigned __int8 v7[48]; // [esp+170h] [ebp-E0h] BYREF
  Scaleform::Render::Matrix3x4<float> v8; // [esp+1A0h] [ebp-B0h] BYREF
  Scaleform::Render::Matrix4x4<double> dst; // [esp+1D0h] [ebp-80h] BYREF

  memset((int)&m1, 0, sizeof(m1));
  m1.M[3][3] = 1.0;
  m1.M[0][0] = xScale;
  m1.M[1][1] = yScale;
  m1.M[2][2] = zScale;
  memcpy((int)&dst, (const __m128i *)&this->mat4, sizeof(dst));
  Scaleform::Render::Matrix4x4<double>::MultiplyMatrix_NonOpt(&this->mat4, &m1, &dst);
  if ( this->pDispObj )
  {
    Scaleform::Render::Matrix4x4<double>::operator Scaleform::Render::Matrix3x4<float>(&this->mat4, &v8);
    memcpy((int)v7, (const __m128i *)&v8, sizeof(v7));
    this->pDispObj->SetMatrix3D(this->pDispObj, (const Scaleform::Render::Matrix3x4<float> *)v7);
  }
}
