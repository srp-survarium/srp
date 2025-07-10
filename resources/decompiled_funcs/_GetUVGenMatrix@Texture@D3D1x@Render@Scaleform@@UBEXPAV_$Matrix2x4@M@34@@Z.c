void __thiscall Scaleform::Render::D3D1x::Texture::GetUVGenMatrix(
        Scaleform::Render::D3D1x::Texture *this,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *p_ImgSize; // eax
  double v3; // st7
  double Height; // st5

  p_ImgSize = (Scaleform::Render::D3D1x::Texture::HWTextureDesc *)&this->ImgSize;
  if ( (this->TextureFlags & 1) == 0 )
    p_ImgSize = this->pTextures;
  v3 = 1.0 / (double)p_ImgSize->Size.Width;
  Height = (double)p_ImgSize->Size.Height;
  *(_QWORD *)&mat->M[0][1] = 0;
  mat->M[0][3] = 0.0;
  mat->M[1][0] = 0.0;
  *(_QWORD *)&mat->M[1][2] = 0;
  mat->M[0][0] = v3;
  mat->M[1][1] = 1.0 / Height;
}
