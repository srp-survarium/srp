void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::positionSet(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *value)
{
  Scaleform::GFx::DisplayObject *pDispObj; // esi
  Scaleform::Render::Matrix3x4<float> v4; // [esp+40h] [ebp-60h] BYREF
  Scaleform::Render::Matrix3x4<float> dst; // [esp+70h] [ebp-30h] BYREF

  pDispObj = this->pDispObj;
  this->mat4.M[0][3] = value->x * 20.0;
  this->mat4.M[1][3] = value->y * 20.0;
  this->mat4.M[2][3] = 20.0 * value->z;
  if ( pDispObj )
  {
    Scaleform::Render::Matrix4x4<double>::operator Scaleform::Render::Matrix3x4<float>(&this->mat4, &v4);
    memcpy((int)&dst, (const __m128i *)&v4, sizeof(dst));
    pDispObj->SetMatrix3D(pDispObj, &dst);
  }
}
