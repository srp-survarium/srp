void __thiscall Scaleform::Render::VectorGlyphShape::GetFillMatrix(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::MeshBase *mesh,
        Scaleform::Render::Matrix2x4<float> *matrix,
        unsigned int layer,
        unsigned int fillIndex,
        unsigned int meshGenFlags)
{
  matrix->M[0][0] = 1.0;
  matrix->M[0][1] = 0.0;
  matrix->M[0][2] = 0.0;
  matrix->M[0][3] = 0.0;
  matrix->M[1][0] = 0.0;
  matrix->M[1][2] = 0.0;
  matrix->M[1][3] = 0.0;
  matrix->M[1][1] = 1.0;
}
