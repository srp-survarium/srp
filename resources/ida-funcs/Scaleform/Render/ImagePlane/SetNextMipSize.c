void __thiscall Scaleform::Render::ImagePlane::SetNextMipSize(Scaleform::Render::ImagePlane *this)
{
  unsigned int v1; // eax
  unsigned int v2; // eax

  v1 = this->Width >> 1;
  if ( !v1 )
    v1 = 1;
  this->Width = v1;
  v2 = this->Height >> 1;
  if ( !v2 )
    v2 = 1;
  this->Height = v2;
}
