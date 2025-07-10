void __thiscall Scaleform::Render::D3D1x::Texture::computeUpdateConvertRescaleFlags(
        Scaleform::Render::D3D1x::Texture *this,
        bool rescale,
        bool swMipGen,
        Scaleform::Render::ImageFormat inputFormat,
        Scaleform::Render::ResizeImageType *rescaleType,
        Scaleform::Render::ImageFormat *rescaleBuffFromat,
        bool *convert)
{
  Scaleform::Render::ImageFormat (__thiscall *GetImageFormat)(Scaleform::Render::TextureFormat *); // eax
  _BYTE *v8; // edx

  if ( rescale )
  {
    GetImageFormat = this->pFormat[1].GetImageFormat;
    if ( GetImageFormat == (Scaleform::Render::ImageFormat (__thiscall *)(Scaleform::Render::TextureFormat *))28 )
    {
LABEL_5:
      *rescaleBuffFromat = Image_R8G8B8A8;
      *rescaleType = ResizeRgbaToRgba;
      goto LABEL_8;
    }
    if ( GetImageFormat == (Scaleform::Render::ImageFormat (__thiscall *)(Scaleform::Render::TextureFormat *))65 )
    {
      *rescaleBuffFromat = Image_A8;
      *rescaleType = ResizeGray;
    }
    else
    {
      if ( GetImageFormat == (Scaleform::Render::ImageFormat (__thiscall *)(Scaleform::Render::TextureFormat *))87 )
        goto LABEL_5;
      *convert = 1;
    }
  }
LABEL_8:
  if ( swMipGen && !Scaleform::Render::D3D1x::IsD3DFormatMipGenCompatible((DXGI_FORMAT)this->pFormat[1].GetImageFormat) )
    *v8 = 1;
}
