void __thiscall Scaleform::Render::Matrix4x4<double>::ViewRH(
        Scaleform::Render::Matrix4x4<double> *this,
        const Scaleform::Render::Point3<double> *eyePt,
        const Scaleform::Render::Point3<double> *lookAtPt,
        const Scaleform::Render::Point3<double> *upVec)
{
  long double v4; // st7
  Scaleform::Render::Point3<double> zAxis; // [esp+8h] [ebp-18h] BYREF

  zAxis.x = eyePt->x - lookAtPt->x;
  zAxis.y = eyePt->y - lookAtPt->y;
  zAxis.z = eyePt->z - lookAtPt->z;
  v4 = sqrt(zAxis.z * zAxis.z + zAxis.y * zAxis.y + zAxis.x * zAxis.x);
  zAxis.x = zAxis.x / v4;
  zAxis.y = zAxis.y / v4;
  zAxis.z = zAxis.z / v4;
  Scaleform::Render::Matrix4x4<double>::View(this, eyePt, &zAxis, upVec);
}
