void __stdcall Scaleform::Render::ConvertImageData(
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData *src,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *scanlineArg)
{
  unsigned int PlaneCount; // eax
  unsigned int v5; // ebp
  unsigned int v6; // edi
  unsigned int formatPlaneCount; // [esp+Ch] [ebp-30h]
  Scaleform::Render::ImageFormat format; // [esp+10h] [ebp-2Ch]
  Scaleform::Render::ImagePlane splane; // [esp+14h] [ebp-28h] BYREF
  Scaleform::Render::ImagePlane dplane; // [esp+28h] [ebp-14h] BYREF
  unsigned int desta; // [esp+40h] [ebp+4h]

  format = src->Format;
  formatPlaneCount = Scaleform::Render::ImageData::GetFormatPlaneCount(src->Format);
  PlaneCount = Scaleform::Render::ImageData::GetPlaneCount(src);
  v5 = PlaneCount;
  v6 = 0;
  if ( PlaneCount )
  {
    desta = PlaneCount % formatPlaneCount;
    do
    {
      memset(&splane, 0, sizeof(splane));
      memset(&dplane, 0, sizeof(dplane));
      Scaleform::Render::ImageData::GetPlane(src, v6, &splane);
      Scaleform::Render::ImageData::GetPlane(dest, v6, &dplane);
      Scaleform::Render::ConvertImagePlane(
        &dplane,
        &splane,
        format,
        desta,
        copyScanline,
        dest->pPalette.pObject,
        scanlineArg);
      ++v6;
    }
    while ( v6 < v5 );
  }
}
