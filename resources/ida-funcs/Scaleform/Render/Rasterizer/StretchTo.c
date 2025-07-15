Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::Render::Rasterizer::StretchTo(
        Scaleform::Render::VertexPath *this,
        Scaleform::Render::Matrix2x4<float> *result,
        float __formal,
        float a4,
        float a5,
        float a6)
{
  Scaleform::Render::Matrix2x4<float> *v6; // eax

  v6 = result;
  result->M[0][0] = 1.0;
  result->M[0][1] = 0.0;
  result->M[0][2] = 0.0;
  result->M[0][3] = 0.0;
  result->M[1][0] = 0.0;
  result->M[1][2] = 0.0;
  result->M[1][3] = 0.0;
  result->M[1][1] = 1.0;
  return v6;
}
