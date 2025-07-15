Scaleform::Render::Matrix3x4<float> *__cdecl Scaleform::Render::Matrix3x4<float>::RotationZ(
        Scaleform::Render::Matrix3x4<float> *result,
        float angle)
{
  Scaleform::Render::Matrix3x4<float> *v2; // eax
  float v3; // [esp+8h] [ebp-8h]
  float v4; // [esp+8h] [ebp-8h]
  float v5; // [esp+Ch] [ebp-4h]

  memset((int)result, 0, sizeof(Scaleform::Render::Matrix3x4<float>));
  v3 = cos(angle);
  v5 = v3;
  v4 = sin(angle);
  v2 = result;
  result->M[0][0] = v5;
  result->M[1][0] = v4;
  result->M[2][0] = 0.0;
  result->M[0][1] = -v4;
  result->M[1][1] = v5;
  result->M[2][1] = 0.0;
  result->M[0][2] = 0.0;
  result->M[1][2] = 0.0;
  result->M[2][2] = 1.0;
  return v2;
}
