void __thiscall Scaleform::Render::ContextImpl::Context::AddCaptureNotify(
        Scaleform::Render::ContextImpl::Context *this,
        Scaleform::Render::ContextImpl::ContextCaptureNotify *notify)
{
  Scaleform::Lock *p_LockObject; // edi

  p_LockObject = &this->pCaptureLock.pObject->LockObject;
  EnterCriticalSection(&p_LockObject->cs);
  notify->pOwnedContext = this;
  notify->pPrev = this->CaptureNotifyList.Root.pPrev;
  notify->pNext = (Scaleform::Render::ContextImpl::ContextCaptureNotify *)&this->pCaptureLock;
  this->CaptureNotifyList.Root.pPrev->pNext = notify;
  this->CaptureNotifyList.Root.pPrev = notify;
  LeaveCriticalSection(&p_LockObject->cs);
}
