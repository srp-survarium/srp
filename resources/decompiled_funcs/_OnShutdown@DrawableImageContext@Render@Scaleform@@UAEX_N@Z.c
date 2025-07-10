void __thiscall Scaleform::Render::DrawableImageContext::OnShutdown(
        Scaleform::Render::DrawableImageContext *this,
        bool waitFlag)
{
  unsigned int *v3; // eax
  unsigned int Capacity; // esi
  Scaleform::Event *v5; // edi
  bool v6; // zf
  Scaleform::Render::ContextImpl::ContextCaptureNotify *pNext; // esi

  while ( 1 )
  {
    v3 = this == (Scaleform::Render::DrawableImageContext *)-64 ? 0 : &this->TreeRootKillListLock.cs.SpinCount;
    if ( (unsigned int *)this->TreeRootKillList.Data.Policy.Capacity == v3 )
      break;
    Capacity = this->TreeRootKillList.Data.Policy.Capacity;
    if ( Capacity )
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)this->TreeRootKillList.Data.Policy.Capacity);
    EnterCriticalSection((LPCRITICAL_SECTION)&this->pControlContext);
    if ( *(_DWORD *)(Capacity + 12) )
    {
      *(_DWORD *)(*(_DWORD *)(Capacity + 8) + 12) = *(_DWORD *)(Capacity + 12);
      *(_DWORD *)(*(_DWORD *)(Capacity + 12) + 8) = *(_DWORD *)(Capacity + 8);
      *(_DWORD *)(Capacity + 8) = 0;
      *(_DWORD *)(Capacity + 12) = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&this->pControlContext);
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)Capacity);
    Scaleform::RefCountImpl::AddRef(*(Scaleform::GFx::Resource **)(Capacity + 92));
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(Capacity + 64) + 4))(
      *(_DWORD *)(Capacity + 64),
      *(_DWORD *)(Capacity + 92));
    v5 = (Scaleform::Event *)(*(_DWORD *)(Capacity + 92) + 12);
    Scaleform::Event::Wait(v5, 0xFFFFFFFF);
    Scaleform::Event::ResetEvent(v5);
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)Capacity);
  }
  v6 = this->pNext == 0;
  this->pOwnedContext = 0;
  if ( !v6 )
  {
    Scaleform::Render::DrawableImageContext::processTreeRootKillList((Scaleform::Render::DrawableImageContext *)((char *)this - 8));
    if ( waitFlag )
    {
      pNext = this->pNext;
      if ( pNext )
      {
        Scaleform::Render::ContextImpl::Context::~Context((Scaleform::Render::ContextImpl::Context *)this->pNext);
        operator delete(pNext);
      }
      this->pNext = 0;
    }
    else
    {
      Scaleform::Render::ContextImpl::Context::Shutdown((Scaleform::Render::ContextImpl::Context *)this->pNext, 0);
    }
  }
}
