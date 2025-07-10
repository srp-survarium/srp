Scaleform::Render::ContextImpl::ContextCaptureNotify *__thiscall Scaleform::Render::ContextImpl::ContextCaptureNotify::`vector deleting destructor'(
        Scaleform::Render::ContextImpl::ContextCaptureNotify *this,
        char a2)
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
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
