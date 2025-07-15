void __thiscall Scaleform::Render::HAL::FilterStackEntry::FilterStackEntry(
        Scaleform::Render::HAL::FilterStackEntry *this,
        const Scaleform::Render::HAL::FilterStackEntry *__that)
{
  Scaleform::Render::RenderTarget *pObject; // ecx

  if ( __that->pPrimitive.pObject )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)__that->pPrimitive.pObject);
  this->pPrimitive.pObject = __that->pPrimitive.pObject;
  pObject = __that->pRenderTarget.pObject;
  if ( pObject )
    pObject->AddRef(pObject);
  this->pRenderTarget.pObject = __that->pRenderTarget.pObject;
}
