Scaleform::Render::Matrix4x4<float> *__cdecl Scaleform::Render::Matrix4x4<float>::Translation(
        Scaleform::Render::Matrix4x4<float> *result,
        float tX,
        float tY,
        float tZ)
{
  Scaleform::Render::Matrix4x4<float> *v4; // eax

  memset((int)result, 0, sizeof(Scaleform::Render::Matrix4x4<float>));
  result->M[0][0] = 1.0;
  result->M[1][1] = 1.0;
  v4 = result;
  result->M[2][2] = 1.0;
  result->M[3][3] = 1.0;
  result->M[0][3] = tX;
  result->M[1][3] = tY;
  result->M[2][3] = tZ;
  return v4;
}
