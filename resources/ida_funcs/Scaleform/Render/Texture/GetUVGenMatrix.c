void __thiscall Scaleform::Render::Texture::GetUVGenMatrix(
        Scaleform::Render::Texture *this,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  double v2; // st7
  unsigned int Height; // [esp+Ch] [ebp-4h]

  Height = this->ImgSize.Height;
  v2 = 1.0 / (double)this->ImgSize.Width;
  *(_QWORD *)&mat->M[0][1] = 0;
  mat->M[0][3] = 0.0;
  mat->M[1][0] = 0.0;
  *(_QWORD *)&mat->M[1][2] = 0;
  mat->M[0][0] = v2;
  mat->M[1][1] = 1.0 / (double)Height;
}
