void __stdcall Scaleform::Render::ConvertImageData(
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData *src,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *scanlineArg)
{
  unsigned int PlaneCount; // eax
  unsigned int v5; // ebp
  unsigned int v6; // edi
  unsigned int FormatPlaneCount; // [esp+Ch] [ebp-30h]
  Scaleform::Render::ImageFormat format; // [esp+10h] [ebp-2Ch]
  Scaleform::Render::ImagePlane pplane; // [esp+14h] [ebp-28h] BYREF
  Scaleform::Render::ImagePlane dplane; // [esp+28h] [ebp-14h] BYREF
  unsigned int v12; // [esp+40h] [ebp+4h]

  format = src->Format;
  FormatPlaneCount = Scaleform::Render::ImageData::GetFormatPlaneCount(src->Format);
  PlaneCount = Scaleform::Render::ImageData::GetPlaneCount(src);
  v5 = PlaneCount;
  v6 = 0;
  if ( PlaneCount )
  {
    v12 = PlaneCount % FormatPlaneCount;
    do
    {
      memset(&pplane, 0, sizeof(pplane));
      memset(&dplane, 0, sizeof(dplane));
      Scaleform::Render::ImageData::GetPlane(src, v6, &pplane);
      Scaleform::Render::ImageData::GetPlane(dest, v6, &dplane);
      Scaleform::Render::ConvertImagePlane(
        &dplane,
        &pplane,
        format,
        v12,
        copyScanline,
        dest->pPalette.pObject,
        scanlineArg);
      ++v6;
    }
    while ( v6 < v5 );
  }
}
