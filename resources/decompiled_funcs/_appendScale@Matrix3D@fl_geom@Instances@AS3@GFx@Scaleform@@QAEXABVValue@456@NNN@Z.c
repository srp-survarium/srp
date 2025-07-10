void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::appendScale(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        const Scaleform::GFx::AS3::Value *result,
        long double xScale,
        long double yScale,
        long double zScale)
{
  Scaleform::Render::Matrix4x4<double> dst; // [esp+F0h] [ebp-160h] BYREF
  unsigned __int8 v7[48]; // [esp+170h] [ebp-E0h] BYREF
  Scaleform::Render::Matrix3x4<float> v8; // [esp+1A0h] [ebp-B0h] BYREF
  Scaleform::Render::Matrix4x4<double> m2; // [esp+1D0h] [ebp-80h] BYREF

  memset((int)&dst, 0, sizeof(dst));
  dst.M[3][3] = 1.0;
  dst.M[0][0] = xScale;
  dst.M[1][1] = yScale;
  dst.M[2][2] = zScale;
  memcpy((unsigned __int8 *)&m2, (unsigned __int8 *)&this->mat4, sizeof(m2));
  Scaleform::Render::Matrix4x4<double>::MultiplyMatrix_NonOpt(&this->mat4, &dst, &m2);
  if ( this->pDispObj )
  {
    Scaleform::Render::Matrix4x4<double>::operator Scaleform::Render::Matrix3x4<float>(&this->mat4, &v8);
    memcpy(v7, (unsigned __int8 *)&v8, sizeof(v7));
    this->pDispObj->SetMatrix3D(this->pDispObj, (const Scaleform::Render::Matrix3x4<float> *)v7);
  }
}
