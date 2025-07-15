char __thiscall Scaleform::Render::ContextImpl::Context::IsShutdownComplete(
        Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Lock *p_LockObject; // esi

  p_LockObject = &this->pCaptureLock.pObject->LockObject;
  EnterCriticalSection(&p_LockObject->cs);
  if ( !this->ShutdownRequested || this->pRenderer )
  {
    LeaveCriticalSection(&p_LockObject->cs);
    return 0;
  }
  else
  {
    LeaveCriticalSection(&p_LockObject->cs);
    return 1;
  }
}
