void __thiscall Scaleform::Render::ContextImpl::ContextCaptureNotify::~ContextCaptureNotify(
        Scaleform::Render::ContextImpl::ContextCaptureNotify *this)
{
  Scaleform::Render::ContextImpl::Context *pOwnedContext; // eax
  _RTL_CRITICAL_SECTION *p_cs; // edi

  pOwnedContext = this->pOwnedContext;
  this->__vftable = (Scaleform::Render::ContextImpl::ContextCaptureNotify_vtbl *)&Scaleform::Render::ContextImpl::ContextCaptureNotify::`vftable';
  if ( pOwnedContext )
  {
    p_cs = &pOwnedContext->pCaptureLock.pObject->LockObject.cs;
    EnterCriticalSection(p_cs);
    this->pPrev->pNext = this->pNext;
    this->pNext->pPrev = this->pPrev;
    this->pOwnedContext = 0;
    LeaveCriticalSection(p_cs);
  }
}
