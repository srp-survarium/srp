void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::identity(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        const Scaleform::GFx::AS3::Value *result)
{
  Scaleform::Render::Matrix4x4<double> *p_mat4; // esi
  Scaleform::Render::Matrix3x4<float> v4; // [esp+40h] [ebp-60h] BYREF
  unsigned __int8 dst[48]; // [esp+70h] [ebp-30h] BYREF

  p_mat4 = &this->mat4;
  memset((int)&this->mat4, 0, sizeof(this->mat4));
  p_mat4->M[0][0] = 1.0;
  p_mat4->M[1][1] = 1.0;
  p_mat4->M[2][2] = 1.0;
  p_mat4->M[3][3] = 1.0;
  if ( this->pDispObj )
  {
    Scaleform::Render::Matrix4x4<double>::operator Scaleform::Render::Matrix3x4<float>(p_mat4, &v4);
    memcpy(dst, (unsigned __int8 *)&v4, sizeof(dst));
    this->pDispObj->SetMatrix3D(this->pDispObj, (const Scaleform::Render::Matrix3x4<float> *)dst);
  }
}
