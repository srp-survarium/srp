void __thiscall Scaleform::Render::Matrix3x4<float>::ViewLH(
        Scaleform::Render::Matrix3x4<float> *this,
        const Scaleform::Render::Point3<float> *eyePt,
        const Scaleform::Render::Point3<float> *lookAtPt,
        const Scaleform::Render::Point3<float> *upVec)
{
  Scaleform::Render::Point3<float> zAxis; // [esp+8h] [ebp-Ch] BYREF
  float lookAtPta; // [esp+1Ch] [ebp+8h]
  float lookAtPtb; // [esp+1Ch] [ebp+8h]

  zAxis.x = lookAtPt->x - eyePt->x;
  zAxis.y = lookAtPt->y - eyePt->y;
  zAxis.z = lookAtPt->z - eyePt->z;
  lookAtPta = zAxis.x * zAxis.x + zAxis.y * zAxis.y + zAxis.z * zAxis.z;
  lookAtPtb = sqrt(lookAtPta);
  zAxis.x = zAxis.x / lookAtPtb;
  zAxis.y = zAxis.y / lookAtPtb;
  zAxis.z = zAxis.z / lookAtPtb;
  Scaleform::Render::Matrix3x4<float>::View(this, eyePt, &zAxis, upVec);
}
