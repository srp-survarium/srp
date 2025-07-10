void __userpurge Scaleform::Render::D3D1x::RenderTargetData::RenderTargetData(
        Scaleform::Render::D3D1x::RenderTargetData *this@<esi>,
        Scaleform::Render::RenderBuffer *buffer@<eax>,
        Scaleform::Render::DepthStencilBuffer *pdsb@<edi>,
        ID3D11View *prt,
        ID3D11View *pdss)
{
  ID3D11View *pDSSurface; // eax

  this->__vftable = (Scaleform::Render::D3D1x::RenderTargetData_vtbl *)&Scaleform::Render::RenderBuffer::RenderTargetData::`vftable';
  this->pBuffer = buffer;
  if ( pdsb )
    pdsb->AddRef(pdsb);
  this->pDepthStencilBuffer.pObject = pdsb;
  this->CacheID = 0;
  this->__vftable = (Scaleform::Render::D3D1x::RenderTargetData_vtbl *)&Scaleform::Render::D3D1x::RenderTargetData::`vftable';
  this->pRenderSurface = prt;
  this->pDSSurface = pdss;
  if ( prt )
    prt->AddRef(prt);
  pDSSurface = this->pDSSurface;
  if ( pDSSurface )
    pDSSurface->AddRef(this->pDSSurface);
}
