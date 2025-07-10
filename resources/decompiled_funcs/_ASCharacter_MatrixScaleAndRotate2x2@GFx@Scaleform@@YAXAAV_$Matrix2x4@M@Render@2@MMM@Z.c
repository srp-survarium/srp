void __cdecl Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(
        Scaleform::Render::Matrix2x4<float> *m,
        float sx,
        float sy,
        float radians)
{
  float x00; // [esp+0h] [ebp-10h]
  float x00a; // [esp+0h] [ebp-10h]
  float cosAngle; // [esp+4h] [ebp-Ch]
  float x10; // [esp+8h] [ebp-8h]
  float sinAngle; // [esp+Ch] [ebp-4h]
  float x11; // [esp+14h] [ebp+4h]
  float x01; // [esp+20h] [ebp+10h]
  float x01a; // [esp+20h] [ebp+10h]

  x00 = cos(radians);
  cosAngle = x00;
  x01 = sin(radians);
  sinAngle = x01;
  x00a = m->M[0][0];
  x01a = m->M[0][1];
  x10 = m->M[1][0];
  x11 = m->M[1][1];
  m->M[0][0] = (x00a * cosAngle - x10 * sinAngle) * sx;
  m->M[0][1] = (x01a * cosAngle - x11 * sinAngle) * sy;
  m->M[1][0] = (x10 * cosAngle + x00a * sinAngle) * sx;
  m->M[1][1] = sy * (sinAngle * x01a + cosAngle * x11);
}
