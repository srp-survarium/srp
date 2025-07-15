Scaleform::GFx::GFxPlaceObjectUnpacked *__thiscall Scaleform::GFx::GFxPlaceObjectUnpacked::`vector deleting destructor'(
        Scaleform::GFx::GFxPlaceObjectUnpacked *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  this->__vftable = (Scaleform::GFx::GFxPlaceObjectUnpacked_vtbl *)&Scaleform::GFx::GFxPlaceObjectUnpacked::`vftable';
  pObject = (Scaleform::RefCountVImpl *)this->Pos.pFilters.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->__vftable = (Scaleform::GFx::GFxPlaceObjectUnpacked_vtbl *)&Scaleform::GFx::ExecuteTag::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
