Scaleform::GFx::ASSoundIntf *__thiscall Scaleform::GFx::ASSoundIntf::`vector deleting destructor'(
        Scaleform::GFx::ASSoundIntf *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::ASSoundIntf_vtbl *)&Scaleform::GFx::ASSoundIntf::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
