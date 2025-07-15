void (__stdcall *__stdcall Scaleform::Render::GetImageConvertFunc(
        Scaleform::Render::ImageFormat destFormat,
        Scaleform::Render::ImageFormat sourceFormat))(unsigned __int8 *pd, const __m128i *ps, unsigned int size, Scaleform::Render::Palette *__formal, void *a5)
{
  Scaleform::Render::ImageFormat Source; // eax
  Scaleform::Render::ScanlineConvert *v4; // ecx

  if ( destFormat == sourceFormat )
    return Scaleform::Render::ImageBase::CopyScanlineDefault;
  Source = ImageScanlineConvertTable[0].Source;
  v4 = ImageScanlineConvertTable;
  if ( ImageScanlineConvertTable[0].Source == Image_None )
    return 0;
  while ( Source != sourceFormat || v4->Dest != destFormat )
  {
    Source = v4[1].Source;
    ++v4;
    if ( Source == Image_None )
      return 0;
  }
  return (void (__stdcall *)(unsigned __int8 *, const __m128i *, unsigned int, Scaleform::Render::Palette *, void *))v4->CopyFunc;
}
