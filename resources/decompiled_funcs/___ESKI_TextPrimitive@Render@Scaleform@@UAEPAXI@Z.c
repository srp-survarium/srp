Scaleform::Render::SKI_TextPrimitive *__thiscall Scaleform::Render::SKI_TextPrimitive::`vector deleting destructor'(
        Scaleform::Render::SKI_TextPrimitive *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::SKI_TextPrimitive_vtbl *)&Scaleform::Render::SortKeyInterface::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
