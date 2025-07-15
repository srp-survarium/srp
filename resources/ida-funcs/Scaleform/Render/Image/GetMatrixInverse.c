void __thiscall Scaleform::Render::Image::GetMatrixInverse(
        Scaleform::Render::Image *this,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  Scaleform::Render::Matrix2x4<float> *pInverseMatrix; // eax

  pInverseMatrix = this->pInverseMatrix;
  if ( pInverseMatrix )
  {
    *mat = *pInverseMatrix;
  }
  else
  {
    mat->M[0][0] = 1.0;
    mat->M[0][1] = 0.0;
    mat->M[0][2] = 0.0;
    mat->M[0][3] = 0.0;
    mat->M[1][0] = 0.0;
    mat->M[1][2] = 0.0;
    mat->M[1][3] = 0.0;
    mat->M[1][1] = 1.0;
  }
}
