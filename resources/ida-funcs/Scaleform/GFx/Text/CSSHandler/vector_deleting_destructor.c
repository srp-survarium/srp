Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider *__thiscall Scaleform::GFx::Text::CSSHandler<wchar_t>::`vector deleting destructor'(
        Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider_vtbl *)&Scaleform::GFx::AMP::ConnStatusInterface::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
