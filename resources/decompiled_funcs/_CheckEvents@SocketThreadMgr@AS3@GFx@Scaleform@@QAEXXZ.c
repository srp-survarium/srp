void __thiscall Scaleform::GFx::AS3::SocketThreadMgr::CheckEvents(Scaleform::GFx::AS3::SocketThreadMgr *this)
{
  Scaleform::Lock *p_EventQueueLock; // edi
  unsigned int v3; // ebx
  int v4; // edi
  Scaleform::GFx::AS3::SocketThreadMgr::EventInfo *v5; // ecx
  unsigned int Size; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *p_EventQueue; // esi
  Scaleform::Lock *locker; // [esp+Ch] [ebp-4h]

  p_EventQueueLock = &this->EventQueueLock;
  locker = &this->EventQueueLock;
  EnterCriticalSection(&this->EventQueueLock.cs);
  v3 = 0;
  if ( this->EventQueue.Data.Size )
  {
    v4 = 0;
    do
    {
      v5 = &this->EventQueue.Data.Data[v4];
      if ( v5->EventType )
      {
        if ( v5->EventType == EventConnect )
        {
          Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteConnectEvent(this->AS3Sock);
        }
        else if ( v5->EventType == EventSocketData )
        {
          Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteSocketDataEvent(
            this->AS3Sock,
            *v5->EventParameters.Data.Data,
            0);
        }
      }
      else
      {
        Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteCloseEvent(this->AS3Sock);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->EventQueue.Data.Size );
    p_EventQueueLock = locker;
  }
  Size = this->EventQueue.Data.Size;
  p_EventQueue = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&this->EventQueue;
  if ( !Size )
  {
    if ( !p_EventQueue->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_EventQueue,
        p_EventQueue,
        0);
    goto LABEL_18;
  }
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo>::DestructArray(
    (Scaleform::GFx::AS3::SocketThreadMgr::EventInfo *)p_EventQueue->Data,
    Size);
  if ( (p_EventQueue->Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_18:
    p_EventQueue->Size = 0;
    LeaveCriticalSection(&p_EventQueueLock->cs);
    return;
  }
  if ( p_EventQueue->Data )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_EventQueue->Data);
    p_EventQueue->Data = 0;
  }
  p_EventQueue->Policy.Capacity = 0;
  p_EventQueue->Size = 0;
  LeaveCriticalSection(&p_EventQueueLock->cs);
}
