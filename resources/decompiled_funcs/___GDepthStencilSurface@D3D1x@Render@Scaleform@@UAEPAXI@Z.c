Scaleform::Render::D3D1x::DepthStencilSurface *__thiscall Scaleform::Render::D3D1x::DepthStencilSurface::`scalar deleting destructor'(
        Scaleform::Render::D3D1x::DepthStencilSurface *this,
        char a2)
{
  ID3D11Texture2D *pDepthStencilSurface; // eax
  ID3D11DepthStencilView *pDepthStencilSurfaceView; // eax
  Scaleform::RefCountVImpl *pObject; // ecx

  pDepthStencilSurface = this->pDepthStencilSurface;
  this->__vftable = (Scaleform::Render::D3D1x::DepthStencilSurface_vtbl *)&Scaleform::Render::D3D1x::DepthStencilSurface::`vftable';
  if ( pDepthStencilSurface )
    pDepthStencilSurface->Release(pDepthStencilSurface);
  pDepthStencilSurfaceView = this->pDepthStencilSurfaceView;
  if ( pDepthStencilSurfaceView )
    pDepthStencilSurfaceView->Release(this->pDepthStencilSurfaceView);
  pObject = (Scaleform::RefCountVImpl *)this->pManagerLocks.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
