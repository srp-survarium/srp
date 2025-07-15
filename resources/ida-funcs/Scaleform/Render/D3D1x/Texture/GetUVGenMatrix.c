void __thiscall Scaleform::Render::D3D1x::Texture::GetUVGenMatrix(
        Scaleform::Render::D3D1x::Texture *this,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *p_ImgSize; // eax
  double Width; // st7
  unsigned int Height; // [esp+Ch] [ebp-24h]
  Scaleform::Render::Matrix2x4<float> m; // [esp+10h] [ebp-20h] BYREF

  p_ImgSize = (Scaleform::Render::D3D1x::Texture::HWTextureDesc *)&this->ImgSize;
  if ( (this->TextureFlags & 1) == 0 )
    p_ImgSize = this->pTextures;
  Width = (double)p_ImgSize->Size.Width;
  Height = p_ImgSize->Size.Height;
  memset(&m.M[0][1], 0, 16);
  m.M[0][0] = 1.0 / Width;
  *(_QWORD *)&m.M[1][2] = 0;
  m.M[1][1] = 1.0 / (double)Height;
  Scaleform::Render::Matrix2x4<float>::SetMatrix(mat, &m);
}
