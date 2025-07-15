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


Scaleform::Render::Matrix4x4<double> *__cdecl Scaleform::Render::Matrix4x4<double>::Rotation(
        Scaleform::Render::Matrix4x4<double> *result,
        long double angle,
        const Scaleform::Render::Point3<double> *axis)
{
  double v4; // st5
  long double v5; // st4
  long double v6; // st3
  long double v7; // st2
  long double v8; // rt0
  Scaleform::Render::Matrix4x4<double> *v9; // eax
  long double ys; // [esp+4h] [ebp-8h]
  float resulta; // [esp+10h] [ebp+4h]
  float resultb; // [esp+10h] [ebp+4h]
  float zs; // [esp+14h] [ebp+8h]
  long double zsa; // [esp+14h] [ebp+8h]

  memset((int)result, 0, sizeof(Scaleform::Render::Matrix4x4<double>));
  result->M[3][3] = 1.0;
  resulta = angle;
  zs = cos(resulta);
  resultb = sin(resulta);
  v4 = zs;
  v5 = axis->y * axis->x * (1.0 - zs);
  v6 = axis->z * axis->x * (1.0 - zs);
  v7 = axis->y * axis->z * (1.0 - zs);
  ys = axis->y * resultb;
  v8 = axis->x * resultb;
  zsa = resultb * axis->z;
  result->M[0][0] = axis->x * axis->x * (1.0 - v4) + v4;
  result->M[0][1] = v5 - zsa;
  result->M[0][2] = ys + v6;
  result->M[1][0] = v5 + zsa;
  result->M[1][1] = axis->y * axis->y * (1.0 - v4) + v4;
  result->M[1][2] = v7 - v8;
  result->M[2][0] = v6 - ys;
  result->M[2][1] = v8 + v7;
  v9 = result;
  result->M[2][2] = v4 + (1.0 - v4) * (axis->z * axis->z);
  return v9;
}
