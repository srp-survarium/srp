char __usercall Scaleform::GFx::ZlibDecodeHelper@<al>(
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *)@<ecx>,
        void *arg@<eax>,
        const Scaleform::GFx::ZlibDecodeParams *params,
        Scaleform::Render::ImageData *pdest)
{
  char result; // al

  switch ( params->SrcFormat )
  {
    case ColorMappedRGB:
      result = Scaleform::GFx::ZlibDecodeColorMapped(params, pdest, copyScanline, arg);
      break;
    case RGB16:
      result = Scaleform::GFx::ZlibDecodeRGB16(params, pdest, copyScanline, arg);
      break;
    case RGB24:
      result = Scaleform::GFx::ZlibDecodeRGB24(params, pdest, copyScanline, arg);
      break;
    case ColorMappedRGBA:
      result = Scaleform::GFx::ZlibDecodeColorMappedAlpha(params, pdest, copyScanline, arg);
      break;
    case RGBA:
      result = Scaleform::GFx::ZlibDecodeRGBA(params, pdest, copyScanline, arg);
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
