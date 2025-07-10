unsigned int __stdcall Scaleform::Render::ImageData::GetFormatBitsPerPixel(
        Scaleform::Render::ImageFormat fmt,
        unsigned int plane)
{
  unsigned int result; // eax

  switch ( fmt & 0xFFF )
  {
    case 1:
    case 2:
    case 0x33:
    case 0x34:
      result = 32;
      break;
    case 3:
    case 4:
      result = 24;
      break;
    case 9:
    case 0x64:
    case 0xC8:
    case 0xC9:
      result = 8;
      break;
    case 0x32:
      result = 16;
      break;
    case 0x35:
    case 0x36:
    case 0x39:
      result = 4;
      break;
    case 0x37:
    case 0x38:
      result = 2;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
