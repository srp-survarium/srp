void __thiscall Scaleform::Render::ImageData::GetPlane(
        Scaleform::Render::ImageData *this,
        unsigned int index,
        Scaleform::Render::ImagePlane *pplane)
{
  if ( index >= this->RawPlaneCount )
    Scaleform::Render::ImagePlane::GetMipLevel(
      &this->pPlanes[index % this->RawPlaneCount],
      this->Format,
      index / this->RawPlaneCount,
      pplane,
      index % this->RawPlaneCount);
  else
    *pplane = this->pPlanes[index];
}
