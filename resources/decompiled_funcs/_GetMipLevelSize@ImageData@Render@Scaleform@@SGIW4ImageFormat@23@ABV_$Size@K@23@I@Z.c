int __stdcall Scaleform::Render::ImageData::GetMipLevelSize(
        Scaleform::Render::ImageFormat format,
        const Scaleform::Render::Size<unsigned long> *sz,
        unsigned int plane)
{
  __int32 v3; // eax
  unsigned int v4; // ecx
  unsigned int v5; // eax
  unsigned int v7; // edx
  unsigned int v8; // eax
  unsigned int FormatPitch; // eax
  int v10; // ecx

  v3 = format & 0xFFF;
  if ( v3 == 50 )
  {
    v4 = 1;
    if ( (sz->Width + 3) >> 2 )
      v4 = (sz->Width + 3) >> 2;
    v5 = (sz->Height + 3) >> 2;
    if ( !v5 )
      v5 = 1;
    return 8 * v5 * v4;
  }
  else if ( (unsigned int)(v3 - 51) > 1 )
  {
    FormatPitch = Scaleform::Render::ImageData::GetFormatPitch(format, sz->Width, plane);
    return *(_DWORD *)(v10 + 4) * FormatPitch;
  }
  else
  {
    v7 = 1;
    if ( (sz->Width + 3) >> 2 )
      v7 = (sz->Width + 3) >> 2;
    v8 = (sz->Height + 3) >> 2;
    if ( !v8 )
      v8 = 1;
    return 16 * v7 * v8;
  }
}
