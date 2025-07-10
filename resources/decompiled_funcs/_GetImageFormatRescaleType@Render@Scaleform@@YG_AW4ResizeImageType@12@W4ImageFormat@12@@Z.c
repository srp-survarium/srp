Scaleform::Render::ResizeImageType __stdcall Scaleform::Render::GetImageFormatRescaleType(
        Scaleform::Render::ImageFormat format)
{
  Scaleform::Render::ResizeImageType result; // eax

  switch ( format )
  {
    case Image_R8G8B8A8:
    case Image_B8G8R8A8:
      result = ResizeRgbaToRgba;
      break;
    case Image_R8G8B8:
    case Image_B8G8R8:
      result = ResizeRgbToRgb;
      break;
    case Image_A8:
      result = ResizeGray;
      break;
    default:
      result = ResizeNone;
      break;
  }
  return result;
}
