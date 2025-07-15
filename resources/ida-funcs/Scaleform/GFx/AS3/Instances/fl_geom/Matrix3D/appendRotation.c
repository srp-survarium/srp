void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::appendRotation(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        const Scaleform::GFx::AS3::Value *result,
        long double degrees,
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *axis,
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *pivotPoint)
{
  double v5; // st7
  const Scaleform::Render::Matrix4x4<double> *v7; // ebx
  double x; // [esp+3D8h] [ebp-178h]
  double v9; // [esp+3D8h] [ebp-178h]
  double y; // [esp+3E0h] [ebp-170h]
  double v11; // [esp+3E0h] [ebp-170h]
  double z; // [esp+3E8h] [ebp-168h]
  Scaleform::Render::Matrix3x4<float> v13; // [esp+3F0h] [ebp-160h] BYREF
  Scaleform::Render::Point3<double> pivot[2]; // [esp+420h] [ebp-130h] BYREF
  Scaleform::Render::Matrix4x4<double> dst; // [esp+450h] [ebp-100h] BYREF
  Scaleform::Render::Matrix4x4<double> v16; // [esp+4D0h] [ebp-80h] BYREF

  v5 = 0.0;
  if ( axis )
  {
    x = axis->x;
    y = axis->y;
    z = axis->z;
  }
  else
  {
    x = 0.0;
    y = 0.0;
    z = 0.0;
  }
  *(double *)&v13.M[0][0] = x;
  *(double *)&v13.M[0][2] = y;
  *(double *)&v13.M[1][0] = z;
  if ( pivotPoint )
  {
    v9 = pivotPoint->x;
    v11 = pivotPoint->y;
    v5 = pivotPoint->z;
  }
  else
  {
    v9 = 0.0;
    v11 = 0.0;
  }
  pivot[0].x = v9;
  pivot[0].y = v11;
  pivot[0].z = v5;
  v7 = Scaleform::Render::Matrix4x4<double>::Rotation(
         &v16,
         degrees * 3.141592653589793 / 180.0,
         (const Scaleform::Render::Point3<double> *)&v13,
         pivot);
  memcpy((int)&dst, (const __m128i *)&this->mat4, sizeof(dst));
  Scaleform::Render::Matrix4x4<double>::MultiplyMatrix_NonOpt(&this->mat4, v7, &dst);
  if ( this->pDispObj )
  {
    Scaleform::Render::Matrix4x4<double>::operator Scaleform::Render::Matrix3x4<float>(&this->mat4, &v13);
    memcpy((int)pivot, (const __m128i *)&v13, sizeof(pivot));
    this->pDispObj->SetMatrix3D(this->pDispObj, (const Scaleform::Render::Matrix3x4<float> *)pivot);
  }
}
