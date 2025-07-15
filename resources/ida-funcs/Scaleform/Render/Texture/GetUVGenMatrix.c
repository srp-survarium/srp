void __thiscall Scaleform::Render::Texture::GetUVGenMatrix(
        Scaleform::Render::Texture *this,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  unsigned int Width; // eax
  unsigned int Height; // [esp+Ch] [ebp-24h]
  Scaleform::Render::Matrix2x4<float> m; // [esp+10h] [ebp-20h] BYREF

  Width = this->ImgSize.Width;
  Height = this->ImgSize.Height;
  memset(&m.M[0][1], 0, 16);
  m.M[0][0] = 1.0 / (double)Width;
  *(_QWORD *)&m.M[1][2] = 0;
  m.M[1][1] = 1.0 / (double)Height;
  Scaleform::Render::Matrix2x4<float>::SetMatrix(mat, &m);
}
