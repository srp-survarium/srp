Scaleform::Render::Size<unsigned long> *__stdcall Scaleform::Render::ImageData::GetFormatPlaneSize(
        Scaleform::Render::Size<unsigned long> *result,
        Scaleform::Render::ImageFormat fmt,
        const Scaleform::Render::Size<unsigned long> *sz,
        unsigned int plane)
{
  Scaleform::Render::Size<unsigned long> *v4; // eax
  unsigned int v5; // edx
  unsigned int Width; // edx

  if ( (fmt & 0xFFFu) - 200 <= 1 && (plane == 1 || plane == 2) )
  {
    v4 = result;
    v5 = sz->Width >> 1;
    result->Height = sz->Height >> 1;
    result->Width = v5;
  }
  else
  {
    Width = sz->Width;
    v4 = result;
    result->Height = sz->Height;
    result->Width = Width;
  }
  return v4;
}
