void __thiscall Scaleform::Render::ImageData::Initialize(
        Scaleform::Render::ImageData *this,
        Scaleform::Render::ImageFormat format,
        unsigned __int8 mipLevels,
        Scaleform::Render::ImagePlane *pplanes,
        unsigned int planeCount,
        bool separateMipmaps)
{
  Scaleform::Render::ImageData::Clear(this);
  this->Format = format;
  this->LevelCount = mipLevels;
  this->pPlanes = pplanes;
  this->RawPlaneCount = planeCount;
  if ( separateMipmaps )
    this->Flags |= 1u;
  if ( pplanes )
  {
    if ( planeCount == 1 )
      this->Plane0 = *pplanes;
  }
}
