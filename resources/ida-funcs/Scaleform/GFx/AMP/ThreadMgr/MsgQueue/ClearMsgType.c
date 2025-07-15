void __thiscall Scaleform::GFx::AMP::ThreadMgr::MsgQueue::ClearMsgType(
        Scaleform::GFx::AMP::ThreadMgr::MsgQueue *this,
        const Scaleform::GFx::AMP::Message *msg)
{
  Scaleform::GFx::AMP::ThreadMgr::MsgQueue *v2; // ebp
  int v3; // ebx
  Scaleform::RefCountVImpl *pNext; // esi
  Scaleform::String *v5; // edi
  void *v6; // edi
  void *v7; // edi
  Scaleform::RefCountVImpl *RefCount; // edi
  Scaleform::MemoryHeap *v9; // eax
  Scaleform::MemoryHeap *v10; // ebp
  char v11; // [esp+13h] [ebp-11h]
  volatile unsigned int Value; // [esp+18h] [ebp-Ch]
  int v14; // [esp+1Ch] [ebp-8h] BYREF
  int v15; // [esp+20h] [ebp-4h] BYREF

  v2 = this;
  v3 = 0;
  v15 = 0;
  EnterCriticalSection(&this->QueueLock.cs);
  pNext = (Scaleform::RefCountVImpl *)v2->Queue.Root.pNext;
  if ( v2->QueueSize.Value )
  {
    Value = v2->QueueSize.Value;
    do
    {
      if ( !msg
        || (v3 |= 3u,
            v5 = msg->GetMessageName(msg, &v15),
            v11 = 0,
            !strcmp(
               (const char *)((*(_DWORD *)((int (__thiscall *)(Scaleform::RefCountVImpl *, int *))pNext->__vftable[1].~Scaleform::RefCountVImpl)(
                                            pNext,
                                            &v14)
                             & 0xFFFFFFFC)
                            + 8),
               (const char *)((v5->HeapTypeBits & 0xFFFFFFFC) + 8))) )
      {
        v11 = 1;
      }
      if ( (v3 & 2) != 0 )
      {
        v6 = (void *)(v14 & 0xFFFFFFFC);
        v3 &= ~2u;
        if ( InterlockedExchangeAdd((volatile LONG *)((v14 & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
      }
      if ( (v3 & 1) != 0 )
      {
        v7 = (void *)(v15 & 0xFFFFFFFC);
        v3 &= ~1u;
        if ( InterlockedExchangeAdd((volatile LONG *)((v15 & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
      }
      if ( v11 )
      {
        RefCount = (Scaleform::RefCountVImpl *)pNext[1].RefCount;
        v9 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, RefCount);
        pNext[1].__vftable[1].~Scaleform::RefCountVImpl = (void (__thiscall *)(struct Scaleform::RefCountVImpl *))pNext[1].RefCount;
        v10 = v9;
        *(_DWORD *)(pNext[1].RefCount + 8) = pNext[1].__vftable;
        Scaleform::RefCountImpl::Release(pNext);
        pNext = RefCount;
        InterlockedExchangeAdd((volatile LONG *)&this->QueueSize, -1);
        Scaleform::GFx::AMP::ThreadMgr::MsgQueue::CheckSize(this, v10);
        v2 = this;
      }
      --Value;
    }
    while ( Value );
  }
  LeaveCriticalSection(&v2->QueueLock.cs);
}
