void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Transform::matrix3DSet(
        Scaleform::GFx::AS3::Instances::fl_geom::Transform *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *value)
{
  Scaleform::GFx::DisplayObject *pDispObj; // edi
  Scaleform::GFx::DisplayObject *v5; // ecx
  float eY; // [esp+32Ch] [ebp-9Ch] BYREF
  int eZ; // [esp+330h] [ebp-98h] BYREF
  float eX; // [esp+334h] [ebp-94h] BYREF
  Scaleform::Render::Matrix3x4<float> v9; // [esp+338h] [ebp-90h] BYREF
  Scaleform::GFx::DisplayObjectBase::GeomDataType m; // [esp+368h] [ebp-60h] BYREF

  pDispObj = this->pDispObj;
  if ( pDispObj )
  {
    if ( value )
    {
      Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::GetMatrix3DF(value, (Scaleform::Render::Matrix4x4<float> *)&m);
      Scaleform::Render::Matrix3x4<float>::Matrix3x4<float>(&v9, (const Scaleform::Render::Matrix4x4<float> *)&m);
      v9.M[0][3] = v9.M[0][3] * 20.0;
      v9.M[1][3] = v9.M[1][3] * 20.0;
      v9.M[2][3] = 20.0 * v9.M[2][3];
      pDispObj->SetMatrix3D(pDispObj, &v9);
      Scaleform::GFx::DisplayObjectBase::GeomDataType::GeomDataType(&m);
      Scaleform::GFx::DisplayObjectBase::GetGeomData(this->pDispObj, &m);
      m.X = (int)v9.M[0][3];
      m.Y = (int)v9.M[1][3];
      eZ = (int)v9.M[2][3];
      m.Z = (double)eZ;
      Scaleform::Render::Matrix3x4<float>::GetEulerAngles(&v9, &eX, &eY, (float *)&eZ);
      m.Rotation = *(float *)&eZ * 180.0 / 3.141592653589793;
      m.XRotation = eX * 180.0 / 3.141592653589793;
      m.YRotation = 180.0 * eY / 3.141592653589793;
      eY = v9.M[1][0] * v9.M[1][0] + v9.M[0][0] * v9.M[0][0] + v9.M[2][0] * v9.M[2][0];
      eY = sqrt(eY);
      m.XScale = eY * 100.0;
      eY = v9.M[0][1] * v9.M[0][1] + v9.M[1][1] * v9.M[1][1] + v9.M[2][1] * v9.M[2][1];
      eY = sqrt(eY);
      m.YScale = eY * 100.0;
      eY = v9.M[0][2] * v9.M[0][2] + v9.M[1][2] * v9.M[1][2] + v9.M[2][2] * v9.M[2][2];
      eY = sqrt(eY);
      v5 = this->pDispObj;
      m.ZScale = eY * 100.0;
      Scaleform::GFx::DisplayObjectBase::SetGeomData(v5, &m);
    }
    else if ( Scaleform::GFx::DisplayObjectBase::Has3D(pDispObj) )
    {
      Scaleform::GFx::DisplayObjectBase::Clear3D(pDispObj, 0);
    }
    this->pDispObj->SetAcceptAnimMoves(this->pDispObj, 0);
  }
}
