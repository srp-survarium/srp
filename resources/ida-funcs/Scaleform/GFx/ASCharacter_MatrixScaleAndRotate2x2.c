void __cdecl Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(
        Scaleform::Render::Matrix2x4<float> *m,
        float sx,
        float sy,
        float radians)
{
  float v5; // [esp+0h] [ebp-10h]
  float v6; // [esp+0h] [ebp-10h]
  float v7; // [esp+4h] [ebp-Ch]
  float v8; // [esp+8h] [ebp-8h]
  float v9; // [esp+Ch] [ebp-4h]
  float v10; // [esp+14h] [ebp+4h]
  float v11; // [esp+20h] [ebp+10h]
  float v12; // [esp+20h] [ebp+10h]

  v5 = cos(radians);
  v7 = v5;
  v11 = sin(radians);
  v9 = v11;
  v6 = m->M[0][0];
  v12 = m->M[0][1];
  v8 = m->M[1][0];
  v10 = m->M[1][1];
  m->M[0][0] = (v6 * v7 - v8 * v9) * sx;
  m->M[0][1] = (v12 * v7 - v10 * v9) * sy;
  m->M[1][0] = (v8 * v7 + v6 * v9) * sx;
  m->M[1][1] = sy * (v9 * v12 + v7 * v10);
}
