Scaleform::GFx::StateBag *__thiscall Scaleform::GFx::StateBag::`vector deleting destructor'(
        Scaleform::GFx::StateBag *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::StateBag::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
