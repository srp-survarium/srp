void __stdcall Scaleform::Render::RescaleImageData(
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData *src,
        Scaleform::Render::ResizeImageType resizeType)
{
  unsigned int PlaneCount; // ebx
  unsigned int i; // edi
  Scaleform::Render::ImagePlane splane; // [esp+10h] [ebp-28h] BYREF
  Scaleform::Render::ImagePlane dplane; // [esp+24h] [ebp-14h] BYREF

  PlaneCount = Scaleform::Render::ImageData::GetPlaneCount(src);
  for ( i = 0; i < PlaneCount; ++i )
  {
    memset(&splane, 0, sizeof(splane));
    memset(&dplane, 0, sizeof(dplane));
    Scaleform::Render::ImageData::GetPlane(src, i, &splane);
    Scaleform::Render::ImageData::GetPlane(dest, i, &dplane);
    Scaleform::Render::ResizeImageBilinear(
      dplane.pData,
      dplane.Width,
      dplane.Height,
      dplane.Pitch,
      splane.pData,
      splane.Width,
      splane.Height,
      splane.Pitch,
      resizeType);
  }
}
