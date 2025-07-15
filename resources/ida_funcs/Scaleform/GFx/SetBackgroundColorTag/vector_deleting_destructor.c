Scaleform::GFx::AS2::RemoveObjectEH *__thiscall Scaleform::GFx::SetBackgroundColorTag::`vector deleting destructor'(
        Scaleform::GFx::AS2::RemoveObjectEH *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AS2::RemoveObjectEH_vtbl *)&Scaleform::GFx::ExecuteTag::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
