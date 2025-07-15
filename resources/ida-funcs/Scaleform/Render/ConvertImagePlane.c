void __stdcall Scaleform::Render::ConvertImagePlane(
        const Scaleform::Render::ImagePlane *dplane,
        const Scaleform::Render::ImagePlane *splane,
        Scaleform::Render::ImageFormat format,
        unsigned int formatPlaneIndex,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        Scaleform::Render::Palette *pcolorMap,
        void *scanlineArg)
{
  unsigned int FormatBitsPerPixel; // ebp
  unsigned int FormatScanlineCount; // eax
  unsigned __int8 *pData; // esi
  unsigned __int8 *v10; // edi
  unsigned int plane; // [esp+20h] [ebp+10h]

  FormatBitsPerPixel = Scaleform::Render::ImageData::GetFormatBitsPerPixel(format, formatPlaneIndex);
  FormatScanlineCount = Scaleform::Render::ImageData::GetFormatScanlineCount(format, splane->Height, formatPlaneIndex);
  pData = splane->pData;
  v10 = dplane->pData;
  if ( FormatScanlineCount )
  {
    plane = FormatScanlineCount;
    do
    {
      copyScanline(v10, pData, (FormatBitsPerPixel * splane->Width) >> 3, pcolorMap, scanlineArg);
      pData += splane->Pitch;
      v10 += dplane->Pitch;
      --plane;
    }
    while ( plane );
  }
}
