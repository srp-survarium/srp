void __thiscall Scaleform::Render::DrawableImageContext::~DrawableImageContext(
        Scaleform::Render::DrawableImageContext *this)
{
  Scaleform::Render::ContextImpl::Context *RContext; // edi
  Scaleform::Render::ContextImpl::ContextCaptureNotify *v3; // ebx
  Scaleform::Render::ContextImpl::Context *pControlContext; // ecx

  RContext = this->RContext;
  v3 = &this->Scaleform::Render::ContextImpl::ContextCaptureNotify;
  this->Scaleform::RefCountBase<Scaleform::Render::DrawableImageContext,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::DrawableImageContext_vtbl *)&Scaleform::Render::DrawableImageContext::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::DrawableImageContext,2>'};
  this->Scaleform::Render::ContextImpl::ContextCaptureNotify::__vftable = (Scaleform::Render::ContextImpl::ContextCaptureNotify_vtbl *)&Scaleform::Render::DrawableImageContext::`vftable'{for `Scaleform::Render::ContextImpl::ContextCaptureNotify'};
  if ( RContext )
  {
    Scaleform::Render::ContextImpl::Context::~Context(RContext);
    operator delete(RContext);
    this->RContext = 0;
  }
  pControlContext = this->pControlContext;
  if ( pControlContext )
    Scaleform::Render::ContextImpl::Context::RemoveCaptureNotify(pControlContext, v3);
  Scaleform::Render::DrawableImageContext::processTreeRootKillList(this);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->TreeRootKillList.Data.Data);
  Scaleform::Lock::~Lock(&this->TreeRootKillListLock);
  Scaleform::Render::ContextImpl::ContextCaptureNotify::~ContextCaptureNotify(v3);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
