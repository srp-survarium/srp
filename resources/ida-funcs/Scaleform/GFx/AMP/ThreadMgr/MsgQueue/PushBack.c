void __thiscall Scaleform::GFx::AMP::ThreadMgr::MsgQueue::PushBack(
        Scaleform::GFx::AMP::ThreadMgr::MsgQueue *this,
        Scaleform::GFx::AMP::Message *msg)
{
  Scaleform::MemoryHeap *v3; // eax

  EnterCriticalSection(&this->QueueLock.cs);
  msg->pPrev = this->Queue.Root.pPrev;
  msg->pNext = (Scaleform::GFx::AMP::Message *)&this->QueueLock.cs.LockSemaphore;
  this->Queue.Root.pPrev->pNext = msg;
  this->Queue.Root.pPrev = msg;
  InterlockedExchangeAdd((volatile LONG *)&this->QueueSize, 1);
  v3 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, msg);
  Scaleform::GFx::AMP::ThreadMgr::MsgQueue::CheckSize(this, v3);
  LeaveCriticalSection(&this->QueueLock.cs);
}
