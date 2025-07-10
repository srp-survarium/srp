void __thiscall Scaleform::Render::DrawableImageContext::DrawableImageContext(
        Scaleform::Render::DrawableImageContext *this,
        Scaleform::Render::ContextImpl::Context *controlContext,
        Scaleform::Render::ThreadCommandQueue *commandQueue,
        const Scaleform::Render::Interfaces *i)
{
  unsigned int *p_Size; // ecx
  Scaleform::Render::ContextImpl::Context *v6; // edi
  Scaleform::MemoryHeap *v7; // eax
  Scaleform::Render::ContextImpl::Context *v8; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // ecx

  this->Scaleform::RefCountBase<Scaleform::Render::DrawableImageContext,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::DrawableImageContext_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Scaleform::Render::ContextImpl::ContextCaptureNotify::__vftable = (Scaleform::Render::ContextImpl::ContextCaptureNotify_vtbl *)&Scaleform::Render::ContextImpl::ContextCaptureNotify::`vftable';
  this->pOwnedContext = 0;
  this->pRTCommandQueue = commandQueue;
  this->Scaleform::RefCountBase<Scaleform::Render::DrawableImageContext,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::DrawableImageContext_vtbl *)&Scaleform::Render::DrawableImageContext::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::DrawableImageContext,2>'};
  this->Scaleform::Render::ContextImpl::ContextCaptureNotify::__vftable = (Scaleform::Render::ContextImpl::ContextCaptureNotify_vtbl *)&Scaleform::Render::DrawableImageContext::`vftable'{for `Scaleform::Render::ContextImpl::ContextCaptureNotify'};
  this->RContext = 0;
  this->pControlContext = controlContext;
  Scaleform::Lock::Lock(&this->TreeRootKillListLock, 0);
  this->TreeRootKillList.Data.Data = 0;
  this->TreeRootKillList.Data.Size = 0;
  this->TreeRootKillList.Data.Policy.Capacity = 0;
  if ( this == (Scaleform::Render::DrawableImageContext *)-72 )
    p_Size = 0;
  else
    p_Size = &this->TreeRootKillList.Data.Size;
  this->QueueList.Root.pPrev = (Scaleform::Render::DICommandQueue *)p_Size;
  this->QueueList.Root.pNext = (Scaleform::Render::DICommandQueue *)p_Size;
  this->IDefaults = *i;
  v6 = (Scaleform::Render::ContextImpl::Context *)operator new(0xA0u);
  if ( v6 )
  {
    v7 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    Scaleform::Render::ContextImpl::Context::Context(v6, (int)v6, v7);
  }
  else
  {
    v8 = 0;
  }
  pControlContext = this->pControlContext;
  this->RContext = v8;
  if ( pControlContext )
    Scaleform::Render::ContextImpl::Context::AddCaptureNotify(
      pControlContext,
      &this->Scaleform::Render::ContextImpl::ContextCaptureNotify);
}
