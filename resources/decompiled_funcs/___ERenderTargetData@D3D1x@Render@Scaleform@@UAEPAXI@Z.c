Scaleform::Render::D3D1x::RenderTargetData *__thiscall Scaleform::Render::D3D1x::RenderTargetData::`vector deleting destructor'(
        Scaleform::Render::D3D1x::RenderTargetData *this,
        char a2)
{
  ID3D11View *pRenderSurface; // eax
  ID3D11View *pDSSurface; // eax
  Scaleform::Render::DepthStencilBuffer *pObject; // ecx

  pRenderSurface = this->pRenderSurface;
  this->__vftable = (Scaleform::Render::D3D1x::RenderTargetData_vtbl *)&Scaleform::Render::D3D1x::RenderTargetData::`vftable';
  if ( pRenderSurface )
    pRenderSurface->Release(pRenderSurface);
  pDSSurface = this->pDSSurface;
  if ( pDSSurface )
    pDSSurface->Release(this->pDSSurface);
  this->__vftable = (Scaleform::Render::D3D1x::RenderTargetData_vtbl *)&Scaleform::Render::RenderBuffer::RenderTargetData::`vftable';
  pObject = this->pDepthStencilBuffer.pObject;
  if ( pObject )
    pObject->Release(pObject);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
