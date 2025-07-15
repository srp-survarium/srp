unsigned int __stdcall Scaleform::Render::ImageData::GetFormatPlaneCount(Scaleform::Render::ImageFormat fmt)
{
  switch ( fmt & 0xFFF )
  {
    case 0:
      return 0;
    case 200:
      return 3;
    case 201:
      return 4;
  }
  return 1;
}
