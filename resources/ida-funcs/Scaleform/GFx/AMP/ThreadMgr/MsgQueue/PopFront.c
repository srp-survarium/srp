Scaleform::GFx::AMP::Message *__thiscall Scaleform::GFx::AMP::ThreadMgr::MsgQueue::PopFront(
        Scaleform::GFx::AMP::ThreadMgr::MsgQueue *this)
{
  Scaleform::GFx::AMP::Message *pNext; // esi
  Scaleform::GFx::AMP::Message *p_LockSemaphore; // ecx
  Scaleform::MemoryHeap *v4; // ebx

  pNext = 0;
  EnterCriticalSection(&this->QueueLock.cs);
  if ( this == (Scaleform::GFx::AMP::ThreadMgr::MsgQueue *)-24 )
    p_LockSemaphore = 0;
  else
    p_LockSemaphore = (Scaleform::GFx::AMP::Message *)&this->QueueLock.cs.LockSemaphore;
  if ( this->Queue.Root.pNext != p_LockSemaphore )
  {
    pNext = this->Queue.Root.pNext;
    v4 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, pNext);
    pNext->pPrev->pNext = pNext->pNext;
    pNext->pNext->pPrev = pNext->pPrev;
    InterlockedExchangeAdd((volatile LONG *)&this->QueueSize, -1);
    Scaleform::GFx::AMP::ThreadMgr::MsgQueue::CheckSize(this, v4);
  }
  LeaveCriticalSection(&this->QueueLock.cs);
  return pNext;
}
