void __stdcall Scaleform::Render::ResizeImageBilinear(
        unsigned __int8 *pDst,
        int dstWidth,
        int dstHeight,
        int dstPitch,
        unsigned __int8 *pSrc,
        int srcWidth,
        int srcHeight,
        int srcPitch,
        Scaleform::Render::ResizeImageType type)
{
  if ( dstWidth > 0 && dstHeight > 0 && srcWidth > 0 && srcHeight > 0 )
  {
    switch ( type )
    {
      case ResizeRgbToRgb:
        Scaleform::Render::ImageResizeFilter2x2_void____cdecl___unsigned_char___unsigned_char_const___unsigned_char_const___unsigned_char_const___unsigned_char_const___int_int__(
          pDst,
          dstWidth,
          dstHeight,
          dstPitch,
          3,
          pSrc,
          srcWidth,
          srcHeight,
          srcPitch,
          3,
          Scaleform::Render::PixelFilterBilinearRGB24);
        break;
      case ResizeRgbaToRgba:
        Scaleform::Render::ImageResizeFilter2x2_void____cdecl___unsigned_char___unsigned_char_const___unsigned_char_const___unsigned_char_const___unsigned_char_const___int_int__(
          pDst,
          dstWidth,
          dstHeight,
          dstPitch,
          4,
          pSrc,
          srcWidth,
          srcHeight,
          srcPitch,
          4,
          Scaleform::Render::PixelFilterBilinearRGBA32);
        break;
      case ResizeRgbToRgba:
        Scaleform::Render::ImageResizeFilter2x2_void____cdecl___unsigned_char___unsigned_char_const___unsigned_char_const___unsigned_char_const___unsigned_char_const___int_int__(
          pDst,
          dstWidth,
          dstHeight,
          dstPitch,
          4,
          pSrc,
          srcWidth,
          srcHeight,
          srcPitch,
          3,
          Scaleform::Render::PixelFilterBilinearRGBtoRGBA32);
        break;
      case ResizeGray:
        Scaleform::Render::ImageResizeFilter2x2_void____cdecl___unsigned_char___unsigned_char_const___unsigned_char_const___unsigned_char_const___unsigned_char_const___int_int__(
          pDst,
          dstWidth,
          dstHeight,
          dstPitch,
          1,
          pSrc,
          srcWidth,
          srcHeight,
          srcPitch,
          1,
          Scaleform::Render::PixelFilterBilinearGray8);
        break;
      default:
        return;
    }
  }
}
