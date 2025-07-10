void __thiscall Scaleform::GFx::AS2::UserDefinedFunctionObject::Finalize_GC(
        Scaleform::GFx::AS2::UserDefinedFunctionObject *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->pContext.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pContext.pObject = 0;
  Scaleform::GFx::AS2::Object::Finalize_GC(this);
}
