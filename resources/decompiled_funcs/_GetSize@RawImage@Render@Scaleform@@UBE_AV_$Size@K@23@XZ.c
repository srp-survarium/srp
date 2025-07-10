Scaleform::Render::Size<unsigned long> *__thiscall Scaleform::Render::RawImage::GetSize(
        Scaleform::Render::RawImage *this,
        Scaleform::Render::Size<unsigned long> *result)
{
  Scaleform::Render::ImagePlane *pPlanes; // ecx
  unsigned int Width; // edx
  Scaleform::Render::Size<unsigned long> *v4; // eax
  unsigned int Height; // ecx

  pPlanes = this->Data.pPlanes;
  Width = pPlanes->Width;
  v4 = result;
  Height = pPlanes->Height;
  result->Width = Width;
  result->Height = Height;
  return v4;
}
