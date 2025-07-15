void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::invert(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        bool *result)
{
  Scaleform::Render::Matrix4x4<double> *p_mat4; // edi
  const __m128i *Inverse; // eax
  unsigned __int8 dst[48]; // [esp+F0h] [ebp-E0h] BYREF
  Scaleform::Render::Matrix3x4<float> v6; // [esp+120h] [ebp-B0h] BYREF
  Scaleform::Render::Matrix4x4<double> v7; // [esp+150h] [ebp-80h] BYREF

  p_mat4 = &this->mat4;
  Inverse = (const __m128i *)Scaleform::Render::Matrix4x4<double>::GetInverse(&this->mat4, &v7);
  memcpy((int)p_mat4, Inverse, sizeof(Scaleform::Render::Matrix4x4<double>));
  if ( this->pDispObj )
  {
    Scaleform::Render::Matrix4x4<double>::operator Scaleform::Render::Matrix3x4<float>(p_mat4, &v6);
    memcpy((int)dst, (const __m128i *)&v6, sizeof(dst));
    this->pDispObj->SetMatrix3D(this->pDispObj, (const Scaleform::Render::Matrix3x4<float> *)dst);
  }
  *result = 1;
}
