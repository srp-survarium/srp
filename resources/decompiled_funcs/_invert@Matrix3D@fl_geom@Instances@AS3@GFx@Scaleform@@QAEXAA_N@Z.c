void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::invert(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        bool *result)
{
  unsigned __int8 *p_mat4; // edi
  unsigned __int8 *Inverse; // eax
  unsigned __int8 dst[48]; // [esp+F0h] [ebp-E0h] BYREF
  Scaleform::Render::Matrix3x4<float> v6; // [esp+120h] [ebp-B0h] BYREF
  Scaleform::Render::Matrix4x4<double> v7; // [esp+150h] [ebp-80h] BYREF

  p_mat4 = (unsigned __int8 *)&this->mat4;
  Inverse = (unsigned __int8 *)Scaleform::Render::Matrix4x4<double>::GetInverse(&this->mat4, &v7);
  memcpy(p_mat4, Inverse, 0x80u);
  if ( this->pDispObj )
  {
    Scaleform::Render::Matrix4x4<double>::operator Scaleform::Render::Matrix3x4<float>(
      (Scaleform::Render::Matrix4x4<double> *)p_mat4,
      &v6);
    memcpy(dst, (unsigned __int8 *)&v6, sizeof(dst));
    this->pDispObj->SetMatrix3D(this->pDispObj, (const Scaleform::Render::Matrix3x4<float> *)dst);
  }
  *result = 1;
}
