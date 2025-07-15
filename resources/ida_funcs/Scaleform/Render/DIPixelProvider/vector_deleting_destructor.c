Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider *__thiscall Scaleform::Render::DIPixelProvider::`vector deleting destructor'(
        Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider_vtbl *)&Scaleform::Render::GlyphCacheConfig::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
