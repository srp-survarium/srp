void __thiscall Scaleform::WaitConditionImpl::Notify(Scaleform::WaitConditionImpl *this)
{
  Scaleform::WaitConditionImpl::EventPoolEntry *pQueueHead; // ecx
  Scaleform::WaitConditionImpl::EventPoolEntry *pNext; // eax

  EnterCriticalSection(&this->WaitQueueLoc.cs);
  pQueueHead = this->pQueueHead;
  if ( pQueueHead )
  {
    if ( pQueueHead->pNext )
    {
      pNext = pQueueHead->pNext;
      this->pQueueHead = pNext;
      pNext->pPrev = 0;
      SetEvent(pQueueHead->hEvent);
      LeaveCriticalSection(&this->WaitQueueLoc.cs);
      return;
    }
    this->pQueueHead = 0;
    this->pQueueTail = 0;
    SetEvent(pQueueHead->hEvent);
  }
  LeaveCriticalSection(&this->WaitQueueLoc.cs);
}
