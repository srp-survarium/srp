Scaleform::GFx::ResourceReport *__thiscall Scaleform::GFx::ResourceReport::`scalar deleting destructor'(
        Scaleform::GFx::ResourceReport *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::ResourceReport_vtbl *)&Scaleform::GFx::ResourceReport::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
