void __thiscall Scaleform::MutexImpl::Unlock(Scaleform::MutexImpl *this, Scaleform::Mutex *pmutex)
{
  volatile unsigned int v3; // ebp
  Scaleform::Waitable::HandlerArray *pHandlers; // edi
  Scaleform::Waitable::HandlerArray *v5; // ebx
  BOOL v6; // eax

  v3 = --this->LockCount;
  pHandlers = pmutex->pHandlers;
  v5 = 0;
  if ( pHandlers )
  {
    InterlockedExchangeAdd(&pHandlers->RefCount.Value, 1);
    v5 = pHandlers;
  }
  if ( this->Recursive )
    v6 = ReleaseMutex(this->hMutexOrSemaphore);
  else
    v6 = ReleaseSemaphore(this->hMutexOrSemaphore, 1, 0);
  if ( v6 && !v3 )
  {
    if ( !v5 )
      return;
    Scaleform::Waitable::HandlerArray::CallWaitHandlers(v5);
  }
  if ( v5 )
    Scaleform::Waitable::HandlerArray::Release(v5);
}
