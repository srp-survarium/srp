Scaleform::Render::Matrix4x4<double> *__cdecl Scaleform::Render::Matrix4x4<double>::Rotation(
        Scaleform::Render::Matrix4x4<double> *result,
        long double angle,
        const Scaleform::Render::Point3<double> *axis,
        const Scaleform::Render::Point3<double> *pivot)
{
  const Scaleform::Render::Matrix4x4<double> *v4; // eax
  Scaleform::Render::Matrix4x4<double> dst; // [esp+4Ch] [ebp-180h] BYREF
  Scaleform::Render::Matrix4x4<double> m2; // [esp+CCh] [ebp-100h] BYREF
  Scaleform::Render::Matrix4x4<double> v8; // [esp+14Ch] [ebp-80h] BYREF

  memset((int)&dst, 0, sizeof(dst));
  dst.M[0][0] = 1.0;
  dst.M[1][1] = 1.0;
  dst.M[2][2] = 1.0;
  dst.M[3][3] = 1.0;
  dst.M[0][3] = pivot->x;
  dst.M[1][3] = pivot->y;
  dst.M[2][3] = pivot->z;
  v4 = Scaleform::Render::Matrix4x4<double>::Rotation(&v8, angle, axis);
  Scaleform::Render::Matrix4x4<double>::MultiplyMatrix_NonOpt(&m2, v4, &dst);
  memset((int)&dst, 0, sizeof(dst));
  dst.M[0][0] = 1.0;
  dst.M[1][1] = 1.0;
  dst.M[2][2] = 1.0;
  dst.M[3][3] = 1.0;
  dst.M[0][3] = -pivot->x;
  dst.M[1][3] = -pivot->y;
  dst.M[2][3] = -pivot->z;
  Scaleform::Render::Matrix4x4<double>::MultiplyMatrix_NonOpt(result, &dst, &m2);
  return result;
}
