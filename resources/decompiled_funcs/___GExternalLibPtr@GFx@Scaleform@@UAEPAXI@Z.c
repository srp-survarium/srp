Scaleform::GFx::ExternalLibPtr *__thiscall Scaleform::GFx::ExternalLibPtr::`scalar deleting destructor'(
        Scaleform::GFx::ExternalLibPtr *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::ExternalLibPtr_vtbl *)&Scaleform::GFx::ExternalLibPtr::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
