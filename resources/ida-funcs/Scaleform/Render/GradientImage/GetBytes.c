unsigned int __thiscall Scaleform::Render::GradientImage::GetBytes(
        Scaleform::Render::GradientImage *this,
        int *memRegion)
{
  if ( memRegion )
    *memRegion = 0;
  return 4 * this->Size.Width * this->Size.Height;
}
