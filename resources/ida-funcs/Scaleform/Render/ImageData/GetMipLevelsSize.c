int __stdcall Scaleform::Render::ImageData::GetMipLevelsSize(
        Scaleform::Render::ImageFormat format,
        const Scaleform::Render::Size<unsigned long> *sz,
        unsigned int levels,
        unsigned int plane)
{
  unsigned int Width; // esi
  unsigned int Height; // edi
  int v6; // ebx
  unsigned int i; // ebp
  Scaleform::Render::Size<unsigned long> v9; // [esp+10h] [ebp-8h] BYREF

  Width = sz->Width;
  Height = sz->Height;
  v6 = 0;
  v9.Width = sz->Width;
  v9.Height = Height;
  for ( i = levels; i; v9.Height = Height )
  {
    Width >>= 1;
    v6 += Scaleform::Render::ImageData::GetMipLevelSize(format, &v9, plane);
    if ( !Width )
      Width = 1;
    Height >>= 1;
    if ( !Height )
      Height = 1;
    --i;
    v9.Width = Width;
  }
  return v6;
}
