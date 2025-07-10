unsigned int __stdcall Scaleform::Render::ImageData::GetFormatScanlineCount(
        Scaleform::Render::ImageFormat fmt,
        unsigned int height,
        unsigned int plane)
{
  unsigned int result; // eax

  result = height;
  if ( (fmt & 0xFFFu) - 50 <= 2 )
    return (height + 3) >> 2;
  return result;
}
