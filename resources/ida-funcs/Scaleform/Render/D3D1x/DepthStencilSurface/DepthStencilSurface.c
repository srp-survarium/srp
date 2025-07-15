void __userpurge Scaleform::Render::D3D1x::DepthStencilSurface::DepthStencilSurface(
        Scaleform::Render::D3D1x::DepthStencilSurface *this@<esi>,
        const Scaleform::Render::Size<unsigned long> *size@<edi>,
        Scaleform::GFx::Resource *pmanagerLocks)
{
  unsigned int Width; // edx

  this->__vftable = (Scaleform::Render::D3D1x::DepthStencilSurface_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::D3D1x::DepthStencilSurface_vtbl *)&Scaleform::Render::DepthStencilSurface::`vftable';
  if ( pmanagerLocks )
    Scaleform::RefCountImpl::AddRef(pmanagerLocks);
  this->pManagerLocks.pObject = (Scaleform::Render::TextureManagerLocks *)pmanagerLocks;
  this->State = State_PreCapture;
  Width = size->Width;
  this->Size.Height = size->Height;
  this->Size.Width = Width;
  this->__vftable = (Scaleform::Render::D3D1x::DepthStencilSurface_vtbl *)&Scaleform::Render::D3D1x::DepthStencilSurface::`vftable';
  this->pDepthStencilSurface = 0;
  this->pDepthStencilSurfaceView = 0;
}
