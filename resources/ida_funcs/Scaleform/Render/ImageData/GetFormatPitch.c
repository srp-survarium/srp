unsigned int __stdcall Scaleform::Render::ImageData::GetFormatPitch(
        Scaleform::Render::ImageFormat fmt,
        unsigned int width,
        unsigned int plane)
{
  unsigned int result; // eax

  switch ( fmt & 0xFFF )
  {
    case 1:
    case 2:
      result = 4 * width;
      break;
    case 3:
    case 4:
      result = (3 * width + 3) & 0xFFFFFFFC;
      break;
    case 9:
    case 0x3C:
    case 0x64:
    case 0xC8:
    case 0xC9:
      result = width;
      break;
    case 0x32:
      result = 8 * ((width + 3) >> 2);
      break;
    case 0x33:
    case 0x34:
      result = 16 * ((width + 3) >> 2);
      break;
    case 0x35:
    case 0x36:
    case 0x39:
    case 0x3B:
      result = width >> 1;
      break;
    case 0x37:
    case 0x38:
      result = width >> 2;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
