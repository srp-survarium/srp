void __thiscall Scaleform::Render::Matrix3x4<float>::ViewLH(
        Scaleform::Render::Matrix3x4<float> *this,
        const Scaleform::Render::Point3<float> *eyePt,
        const Scaleform::Render::Point3<float> *lookAtPt,
        const Scaleform::Render::Point3<float> *upVec)
{
  Scaleform::Render::Point3<float> zAxis; // [esp+8h] [ebp-Ch] BYREF
  float v5; // [esp+1Ch] [ebp+8h]
  float v6; // [esp+1Ch] [ebp+8h]

  zAxis.x = lookAtPt->x - eyePt->x;
  zAxis.y = lookAtPt->y - eyePt->y;
  zAxis.z = lookAtPt->z - eyePt->z;
  v5 = zAxis.x * zAxis.x + zAxis.y * zAxis.y + zAxis.z * zAxis.z;
  v6 = sqrt(v5);
  zAxis.x = zAxis.x / v6;
  zAxis.y = zAxis.y / v6;
  zAxis.z = zAxis.z / v6;
  Scaleform::Render::Matrix3x4<float>::View(this, eyePt, &zAxis, upVec);
}
