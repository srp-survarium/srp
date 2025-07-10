void __thiscall Scaleform::GFx::AS2::BitmapFilterObject::Finalize_GC(Scaleform::GFx::AS2::BitmapFilterObject *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  Scaleform::GFx::AS2::Object::Finalize_GC(this);
  pObject = (Scaleform::RefCountVImpl *)this->pFilter.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pFilter.pObject = 0;
}
