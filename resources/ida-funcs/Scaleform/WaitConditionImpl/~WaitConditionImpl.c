void __thiscall Scaleform::WaitConditionImpl::~WaitConditionImpl(Scaleform::WaitConditionImpl *this)
{
  Scaleform::WaitConditionImpl::EventPoolEntry *pFreeEventList; // esi
  Scaleform::WaitConditionImpl::EventPoolEntry *v3; // edi
  void *hEvent; // eax

  pFreeEventList = this->pFreeEventList;
  while ( pFreeEventList )
  {
    v3 = pFreeEventList;
    hEvent = pFreeEventList->hEvent;
    pFreeEventList = pFreeEventList->pNext;
    CloseHandle(hEvent);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
  }
  this->pFreeEventList = 0;
  this->pQueueTail = 0;
  this->pQueueHead = 0;
  Scaleform::Lock::~Lock(&this->WaitQueueLoc);
}
