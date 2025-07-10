void __thiscall Scaleform::Render::HAL::FilterStackEntry::~FilterStackEntry(
        Scaleform::Render::HAL::FilterStackEntry *this)
{
  Scaleform::Render::RenderTarget *pObject; // ecx

  pObject = this->pRenderTarget.pObject;
  if ( pObject )
    pObject->Release(pObject);
  if ( this->pPrimitive.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)this->pPrimitive.pObject);
}
