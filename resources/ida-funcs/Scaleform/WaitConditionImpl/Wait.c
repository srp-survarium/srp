char __thiscall Scaleform::WaitConditionImpl::Wait(
        Scaleform::WaitConditionImpl *this,
        Scaleform::Mutex *pmutex,
        DWORD delay)
{
  Scaleform::Mutex *v3; // ebp
  Scaleform::WaitConditionImpl::EventPoolEntry *NewEvent; // esi
  Scaleform::WaitConditionImpl::EventPoolEntry *pQueueTail; // eax
  Scaleform::MutexImpl *pImpl; // eax
  bool v9; // zf
  volatile unsigned int v10; // ebp
  DWORD v11; // ebp
  volatile unsigned int v12; // edi
  Scaleform::MutexImpl *v13; // esi
  char v14; // [esp+Fh] [ebp-5h]
  volatile unsigned int LockCount; // [esp+10h] [ebp-4h]

  v3 = pmutex;
  v14 = 0;
  LockCount = pmutex->pImpl->LockCount;
  if ( !LockCount )
    return 0;
  EnterCriticalSection(&this->WaitQueueLoc.cs);
  NewEvent = Scaleform::WaitConditionImpl::GetNewEvent(this);
  pQueueTail = this->pQueueTail;
  if ( pQueueTail )
  {
    NewEvent->pPrev = pQueueTail;
    this->pQueueTail->pNext = NewEvent;
    NewEvent->pNext = 0;
  }
  else
  {
    NewEvent->pPrev = 0;
    NewEvent->pNext = 0;
    this->pQueueHead = NewEvent;
  }
  this->pQueueTail = NewEvent;
  LeaveCriticalSection(&this->WaitQueueLoc.cs);
  pImpl = pmutex->pImpl;
  v9 = !pImpl->Recursive;
  pImpl->LockCount = 0;
  if ( v9 )
  {
    ReleaseSemaphore(pmutex->pImpl->hMutexOrSemaphore, 1, 0);
  }
  else
  {
    v10 = LockCount;
    do
    {
      ReleaseMutex(pmutex->pImpl->hMutexOrSemaphore);
      --v10;
    }
    while ( v10 );
    v3 = pmutex;
  }
  Scaleform::Waitable::CallWaitHandlers(v3);
  v11 = WaitForSingleObject(NewEvent->hEvent, delay);
  EnterCriticalSection(&this->WaitQueueLoc.cs);
  if ( !v11 || v11 == 128 )
  {
    v14 = 1;
    ResetEvent(NewEvent->hEvent);
    NewEvent->pNext = this->pFreeEventList;
  }
  else
  {
    Scaleform::WaitConditionImpl::QueueFindAndRemove(this, NewEvent);
    ResetEvent(NewEvent->hEvent);
    NewEvent->pNext = this->pFreeEventList;
  }
  NewEvent->pPrev = 0;
  this->pFreeEventList = NewEvent;
  LeaveCriticalSection(&this->WaitQueueLoc.cs);
  v12 = LockCount;
  do
  {
    v13 = pmutex->pImpl;
    if ( !WaitForSingleObject(v13->hMutexOrSemaphore, 0xFFFFFFFF) )
      ++v13->LockCount;
    --v12;
  }
  while ( v12 );
  return v14;
}
