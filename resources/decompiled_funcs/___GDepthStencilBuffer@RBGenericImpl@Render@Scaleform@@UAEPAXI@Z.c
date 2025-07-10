Scaleform::Render::RBGenericImpl::DepthStencilBuffer *__thiscall Scaleform::Render::RBGenericImpl::DepthStencilBuffer::`scalar deleting destructor'(
        Scaleform::Render::RBGenericImpl::DepthStencilBuffer *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->pSurface.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  pRenderTargetData = this->pRenderTargetData;
  this->__vftable = (Scaleform::Render::RBGenericImpl::DepthStencilBuffer_vtbl *)&Scaleform::Render::RenderBuffer::`vftable';
  if ( pRenderTargetData )
  {
    ((void (__thiscall *)(Scaleform::Render::RenderBuffer::RenderTargetData *, int))pRenderTargetData->~Scaleform::Render::RenderBuffer::RenderTargetData)(
      pRenderTargetData,
      1);
    this->pRenderTargetData = 0;
  }
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
