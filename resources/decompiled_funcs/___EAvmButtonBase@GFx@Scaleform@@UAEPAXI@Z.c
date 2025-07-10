Scaleform::GFx::AvmSpriteBase *__thiscall Scaleform::GFx::AvmButtonBase::`vector deleting destructor'(
        Scaleform::GFx::AvmSpriteBase *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AvmSpriteBase_vtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
