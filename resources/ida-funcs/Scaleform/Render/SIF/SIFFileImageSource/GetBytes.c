unsigned int __thiscall Scaleform::Render::SIF::SIFFileImageSource::GetBytes(
        Scaleform::Render::SIF::SIFFileImageSource *this,
        int *memRegion)
{
  if ( memRegion )
    *memRegion = 0;
  return (Scaleform::Render::ImageData::GetFormatBitsPerPixel(this->Data.Format, 0)
        * this->Data.pPlanes->Height
        * this->Data.pPlanes->Width) >> 3;
}
