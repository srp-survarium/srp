void __thiscall Scaleform::WaitConditionImpl::NotifyAll(Scaleform::WaitConditionImpl *this)
{
  Scaleform::WaitConditionImpl::EventPoolEntry *pQueueHead; // eax
  Scaleform::WaitConditionImpl::EventPoolEntry *pNext; // ecx
  Scaleform::WaitConditionImpl::EventPoolEntry *v4; // ecx

  EnterCriticalSection(&this->WaitQueueLoc.cs);
  pQueueHead = this->pQueueHead;
  if ( pQueueHead )
  {
    if ( pQueueHead->pNext )
    {
      pNext = pQueueHead->pNext;
      this->pQueueHead = pNext;
      pNext->pPrev = 0;
    }
    else
    {
      this->pQueueHead = 0;
      this->pQueueTail = 0;
    }
    while ( 1 )
    {
      SetEvent(pQueueHead->hEvent);
      pQueueHead = this->pQueueHead;
      if ( !pQueueHead )
        break;
      if ( pQueueHead->pNext )
      {
        v4 = pQueueHead->pNext;
        this->pQueueHead = v4;
        v4->pPrev = 0;
      }
      else
      {
        this->pQueueHead = 0;
        this->pQueueTail = 0;
      }
    }
  }
  LeaveCriticalSection(&this->WaitQueueLoc.cs);
}
