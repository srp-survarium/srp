Scaleform::Render::DepthStencilBuffer *__thiscall Scaleform::Render::RenderBuffer::`vector deleting destructor'(
        Scaleform::Render::DepthStencilBuffer *this,
        char a2)
{
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // ecx

  pRenderTargetData = this->pRenderTargetData;
  this->__vftable = (Scaleform::Render::DepthStencilBuffer_vtbl *)&Scaleform::Render::RenderBuffer::`vftable';
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
