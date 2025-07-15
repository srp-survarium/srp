Scaleform::Render::Text::StyleManagerBase *__thiscall Scaleform::GFx::Text::CSSHandler<wchar_t>::`vector deleting destructor'(
        Scaleform::Render::Text::StyleManagerBase *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::Text::StyleManagerBase_vtbl *)&Scaleform::GFx::Text::CSSHandler<wchar_t>::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}
