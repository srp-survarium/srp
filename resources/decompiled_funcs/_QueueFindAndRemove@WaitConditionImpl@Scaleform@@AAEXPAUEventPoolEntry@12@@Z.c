void __thiscall Scaleform::WaitConditionImpl::QueueFindAndRemove(
        Scaleform::WaitConditionImpl *this,
        Scaleform::WaitConditionImpl::EventPoolEntry *pentry)
{
  Scaleform::WaitConditionImpl::EventPoolEntry *pQueueHead; // eax
  Scaleform::WaitConditionImpl::EventPoolEntry *pPrev; // eax
  Scaleform::WaitConditionImpl::EventPoolEntry *pNext; // eax

  pQueueHead = this->pQueueHead;
  if ( pQueueHead )
  {
    while ( pQueueHead != pentry )
    {
      pQueueHead = pQueueHead->pNext;
      if ( !pQueueHead )
        return;
    }
    pPrev = pentry->pPrev;
    if ( pPrev )
      pPrev->pNext = pentry->pNext;
    else
      this->pQueueHead = pentry->pNext;
    pNext = pentry->pNext;
    if ( pNext )
      pNext->pPrev = pentry->pPrev;
    else
      this->pQueueTail = pentry->pPrev;
  }
}
