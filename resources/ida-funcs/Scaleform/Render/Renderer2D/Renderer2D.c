void __thiscall Scaleform::Render::Renderer2D::Renderer2D(
        Scaleform::Render::Renderer2D *this,
        Scaleform::Render::HAL *hal)
{
  Scaleform::Render::Renderer2DImpl *v3; // eax
  Scaleform::Render::Renderer2DImpl *v4; // eax
  Scaleform::AmpServer *Instance; // eax
  int v6; // [esp+4h] [ebp-4h] BYREF

  this->__vftable = (Scaleform::Render::Renderer2D_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::Renderer2D_vtbl *)&Scaleform::Render::Renderer2D::`vftable';
  v6 = 65;
  v3 = (Scaleform::Render::Renderer2DImpl *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              2040,
                                              &v6);
  if ( v3 )
    Scaleform::Render::Renderer2DImpl::Renderer2DImpl(v3, (Scaleform::GFx::Resource *)hal);
  else
    v4 = 0;
  this->pImpl = v4;
  Instance = Scaleform::AmpServer::GetInstance();
  Instance->SetRenderer(Instance, this);
}
