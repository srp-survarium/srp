void __thiscall Scaleform::GFx::AMP::Server::RenderProfile::RenderProfile(
        Scaleform::GFx::AMP::Server::RenderProfile *this)
{
  Scaleform::GFx::AMP::ViewStats *v2; // eax
  Scaleform::GFx::AMP::ViewStats *v3; // eax
  Scaleform::GFx::AMP::ViewStats *v4; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  int v6; // [esp+8h] [ebp-4h] BYREF

  this->__vftable = (Scaleform::GFx::AMP::Server::RenderProfile_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AMP::Server::RenderProfile_vtbl *)&Scaleform::GFx::AMP::Server::RenderProfile::`vftable';
  this->DisplayTimings.pObject = 0;
  v6 = 2;
  v2 = (Scaleform::GFx::AMP::ViewStats *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                           Scaleform::Memory::pGlobalHeap,
                                           this,
                                           288,
                                           &v6);
  if ( v2 )
  {
    Scaleform::GFx::AMP::ViewStats::ViewStats(v2);
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->DisplayTimings.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->DisplayTimings.pObject = v4;
}
