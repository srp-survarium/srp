unsigned int __stdcall Scaleform::Render::ImageSize_MipLevelCount(Scaleform::Render::Size<unsigned long> sz)
{
  unsigned int Width; // ecx
  unsigned int result; // eax
  unsigned int Height; // edx

  Width = sz.Width;
  result = 1;
  if ( sz.Width > 1 )
  {
    Height = sz.Height;
    do
    {
      if ( Height <= 1 )
        break;
      Width >>= 1;
      if ( !Width )
        Width = 1;
      Height >>= 1;
      if ( !Height )
        Height = 1;
      ++result;
    }
    while ( Width > 1 );
  }
  return result;
}
