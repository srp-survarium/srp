Scaleform::Render::ImageSwizzler *__thiscall Scaleform::Render::ImageSwizzler::`scalar deleting destructor'(
        Scaleform::Render::ImageSwizzler *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::ImageSwizzler_vtbl *)&Scaleform::Render::ImageSwizzler::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
