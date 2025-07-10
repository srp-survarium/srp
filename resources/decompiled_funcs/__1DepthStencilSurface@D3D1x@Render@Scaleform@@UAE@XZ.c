void __usercall Scaleform::Render::D3D1x::DepthStencilSurface::~DepthStencilSurface(
        Scaleform::Render::D3D1x::DepthStencilSurface *this@<ecx>,
        Scaleform::RefCountImplCore *a2@<esi>)
{
  Scaleform::RefCountImplCore_vtbl *v2; // eax
  volatile int RefCount; // eax
  Scaleform::RefCountVImpl *v4; // ecx

  v2 = a2[4].__vftable;
  a2->__vftable = (Scaleform::RefCountImplCore_vtbl *)&Scaleform::Render::D3D1x::DepthStencilSurface::`vftable';
  if ( v2 )
    (*((void (__stdcall **)(Scaleform::RefCountImplCore_vtbl *))v2->~Scaleform::RefCountImplCore + 2))(v2);
  RefCount = a2[4].RefCount;
  if ( RefCount )
    (*(void (__stdcall **)(volatile int))(*(_DWORD *)RefCount + 8))(a2[4].RefCount);
  v4 = (Scaleform::RefCountVImpl *)a2[2].__vftable;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  Scaleform::RefCountImplCore::~RefCountImplCore(a2);
}
