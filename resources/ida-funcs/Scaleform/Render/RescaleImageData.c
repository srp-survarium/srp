void __stdcall Scaleform::Render::RescaleImageData(
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData *src,
        Scaleform::Render::ResizeImageType resizeType)
{
  unsigned int PlaneCount; // ebx
  unsigned int i; // edi
  Scaleform::Render::ImagePlane pplane; // [esp+10h] [ebp-28h] BYREF
  Scaleform::Render::ImagePlane v6; // [esp+24h] [ebp-14h] BYREF

  PlaneCount = Scaleform::Render::ImageData::GetPlaneCount(src);
  for ( i = 0; i < PlaneCount; ++i )
  {
    memset(&pplane, 0, sizeof(pplane));
    memset(&v6, 0, sizeof(v6));
    Scaleform::Render::ImageData::GetPlane(src, i, &pplane);
    Scaleform::Render::ImageData::GetPlane(dest, i, &v6);
    Scaleform::Render::ResizeImageBilinear(
      v6.pData,
      v6.Width,
      v6.Height,
      v6.Pitch,
      pplane.pData,
      pplane.Width,
      pplane.Height,
      pplane.Pitch,
      resizeType);
  }
}
