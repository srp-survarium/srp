void __thiscall Scaleform::Render::D3D1x::RenderTargetData::~RenderTargetData(
        Scaleform::Render::D3D1x::RenderTargetData *this)
{
  ID3D11View *pRenderSurface; // eax
  ID3D11View *pDSSurface; // eax

  pRenderSurface = this->pRenderSurface;
  this->__vftable = (Scaleform::Render::D3D1x::RenderTargetData_vtbl *)&Scaleform::Render::D3D1x::RenderTargetData::`vftable';
  if ( pRenderSurface )
    pRenderSurface->Release(pRenderSurface);
  pDSSurface = this->pDSSurface;
  if ( pDSSurface )
    pDSSurface->Release(this->pDSSurface);
  Scaleform::Render::RenderBuffer::RenderTargetData::~RenderTargetData(this);
}
