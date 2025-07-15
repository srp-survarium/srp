Scaleform::Render::RenderBuffer::RenderTargetData *__thiscall Scaleform::Render::RenderBuffer::RenderTargetData::`vector deleting destructor'(
        Scaleform::Render::RenderBuffer::RenderTargetData *this,
        char a2)
{
  Scaleform::Render::DepthStencilBuffer *pObject; // ecx

  this->__vftable = (Scaleform::Render::RenderBuffer::RenderTargetData_vtbl *)&Scaleform::Render::RenderBuffer::RenderTargetData::`vftable';
  pObject = this->pDepthStencilBuffer.pObject;
  if ( pObject )
    pObject->Release(pObject);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
