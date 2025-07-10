Scaleform::Render::HAL::FilterStackEntry *__thiscall Scaleform::Render::HAL::FilterStackEntry::operator=(
        Scaleform::Render::HAL::FilterStackEntry *this,
        const Scaleform::Render::HAL::FilterStackEntry *__that)
{
  Scaleform::Render::RenderTarget *pObject; // ecx
  Scaleform::Render::RenderTarget *v4; // ecx

  if ( __that->pPrimitive.pObject )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)__that->pPrimitive.pObject);
  if ( this->pPrimitive.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)this->pPrimitive.pObject);
  this->pPrimitive.pObject = __that->pPrimitive.pObject;
  pObject = __that->pRenderTarget.pObject;
  if ( pObject )
    pObject->AddRef(pObject);
  v4 = this->pRenderTarget.pObject;
  if ( v4 )
    v4->Release(v4);
  this->pRenderTarget.pObject = __that->pRenderTarget.pObject;
  return this;
}
