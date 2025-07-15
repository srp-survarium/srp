void __thiscall Scaleform::GFx::AMP::ThreadMgr::MsgQueue::Clear(Scaleform::GFx::AMP::ThreadMgr::MsgQueue *this)
{
  Scaleform::GFx::AMP::Message *v2; // eax
  Scaleform::RefCountVImpl *pNext; // ecx
  Scaleform::Event *SizeEvent; // ecx

  EnterCriticalSection(&this->QueueLock.cs);
  while ( 1 )
  {
    v2 = this == (Scaleform::GFx::AMP::ThreadMgr::MsgQueue *)-24
       ? 0
       : (Scaleform::GFx::AMP::Message *)&this->QueueLock.cs.LockSemaphore;
    if ( this->Queue.Root.pNext == v2 )
      break;
    pNext = (Scaleform::RefCountVImpl *)this->Queue.Root.pNext;
    pNext[1].__vftable[1].~Scaleform::RefCountVImpl = (void (__thiscall *)(struct Scaleform::RefCountVImpl *))pNext[1].RefCount;
    *(_DWORD *)(pNext[1].RefCount + 8) = pNext[1].__vftable;
    Scaleform::RefCountImpl::Release(pNext);
  }
  InterlockedExchange((volatile LONG *)&this->QueueSize, 0);
  SizeEvent = this->SizeEvent;
  if ( SizeEvent )
    Scaleform::Event::SetEvent(SizeEvent);
  LeaveCriticalSection(&this->QueueLock.cs);
}
