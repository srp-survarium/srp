void __thiscall Scaleform::Render::Matrix3x4<float>::ViewRH(
        Scaleform::Render::Matrix3x4<float> *this,
        const Scaleform::Render::Point3<float> *eyePt,
        const Scaleform::Render::Point3<float> *lookAtPt,
        const Scaleform::Render::Point3<float> *upVec)
{
  Scaleform::Render::Point3<float> zAxis; // [esp+8h] [ebp-Ch] BYREF
  float eyePta; // [esp+18h] [ebp+4h]
  float eyePtb; // [esp+18h] [ebp+4h]

  zAxis.x = eyePt->x - lookAtPt->x;
  zAxis.y = eyePt->y - lookAtPt->y;
  zAxis.z = eyePt->z - lookAtPt->z;
  eyePta = zAxis.x * zAxis.x + zAxis.y * zAxis.y + zAxis.z * zAxis.z;
  eyePtb = sqrt(eyePta);
  zAxis.x = zAxis.x / eyePtb;
  zAxis.y = zAxis.y / eyePtb;
  zAxis.z = zAxis.z / eyePtb;
  Scaleform::Render::Matrix3x4<float>::View(this, eyePt, &zAxis, upVec);
}
