void __thiscall Scaleform::Render::ContextImpl::Context::RemoveCaptureNotify(
        Scaleform::Render::ContextImpl::Context *this,
        Scaleform::Render::ContextImpl::ContextCaptureNotify *notify)
{
  Scaleform::Lock *p_LockObject; // esi

  p_LockObject = &this->pCaptureLock.pObject->LockObject;
  EnterCriticalSection(&p_LockObject->cs);
  notify->pPrev->pNext = notify->pNext;
  notify->pNext->pPrev = notify->pPrev;
  notify->pOwnedContext = 0;
  LeaveCriticalSection(&p_LockObject->cs);
}
