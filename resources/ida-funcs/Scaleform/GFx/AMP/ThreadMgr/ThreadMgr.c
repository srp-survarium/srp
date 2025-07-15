void __thiscall Scaleform::GFx::AMP::ThreadMgr::ThreadMgr(
        Scaleform::GFx::AMP::ThreadMgr *this,
        bool initSocketLib,
        Scaleform::GFx::AMP::SendInterface *sendCallback,
        Scaleform::GFx::AMP::ConnStatusInterface *connectionCallback,
        Scaleform::Event *sendQueueWaitEvent,
        Scaleform::Event *rcvQueueWaitEvent,
        Scaleform::GFx::AMP::SocketImplFactory *socketFactory,
        Scaleform::GFx::AMP::MessageTypeRegistry *msgTypeRegistry)
{
  Scaleform::GFx::AMP::Message *p_LockSemaphore; // ecx
  Scaleform::GFx::AMP::Message *v10; // ecx
  Scaleform::GFx::AMP::Message *v11; // ecx
  Scaleform::GFx::AMP::Message *v12; // ecx
  Scaleform::Event *v13; // ecx
  Scaleform::GFx::AMP::MessageTypeRegistry *v14; // eax
  Scaleform::GFx::AMP::MessageTypeRegistry *v15; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  int v17; // [esp+10h] [ebp-4h] BYREF

  this->__vftable = (Scaleform::GFx::AMP::ThreadMgr_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AMP::ThreadMgr_vtbl *)&Scaleform::GFx::AMP::ThreadMgr::`vftable';
  this->SocketThread.pObject = 0;
  this->BroadcastThread.pObject = 0;
  this->BroadcastRecvThread.pObject = 0;
  this->CompressThread.pObject = 0;
  this->Port = 0;
  Scaleform::Lock::Lock(&this->BroadcastInfoLock, 0);
  this->BroadcastPort = 0;
  Scaleform::StringLH::StringLH(&this->BroadcastApp);
  Scaleform::StringLH::StringLH(&this->BroadcastFile);
  this->BroadcastRecvPort = 0;
  Scaleform::StringLH::StringLH(&this->IpAddress);
  this->Server = 1;
  Scaleform::Lock::Lock(&this->SocketLock, 0);
  Scaleform::GFx::AMP::Socket::Socket(&this->Sock, initSocketLib, socketFactory);
  this->HeartbeatIntervalMillisecs = 1000;
  this->InitSocketLib = initSocketLib;
  Scaleform::Lock::Lock(&this->InitLock, 0);
  Scaleform::Lock::Lock(&this->StatusLock, 0);
  this->Exiting = 0;
  this->LastSendHeartbeat = 0;
  this->LastRcvdHeartbeat = 0;
  this->ConnectionStatus = CS_Idle;
  InterlockedExchange((volatile LONG *)&this->SendRate, 0);
  InterlockedExchange((volatile LONG *)&this->ReceiveRate, 0);
  InterlockedExchange((volatile LONG *)&this->ValidConnection, 0);
  Scaleform::Lock::Lock(&this->MsgReceivedQueue.QueueLock, 0);
  if ( this == (Scaleform::GFx::AMP::ThreadMgr *)-232 )
    p_LockSemaphore = 0;
  else
    p_LockSemaphore = (Scaleform::GFx::AMP::Message *)&this->MsgReceivedQueue.QueueLock.cs.LockSemaphore;
  this->MsgReceivedQueue.Queue.Root.pPrev = p_LockSemaphore;
  this->MsgReceivedQueue.Queue.Root.pNext = p_LockSemaphore;
  InterlockedExchange((volatile LONG *)&this->MsgReceivedQueue.QueueSize, 0);
  this->MsgReceivedQueue.MaxSize = 100;
  this->MsgReceivedQueue.SizeEvent = rcvQueueWaitEvent;
  this->MsgReceivedQueue.SizeCheckHysterisisPercent = 90;
  if ( rcvQueueWaitEvent )
    Scaleform::Event::SetEvent(rcvQueueWaitEvent);
  Scaleform::Lock::Lock(&this->MsgSendQueue.QueueLock, 0);
  if ( this == (Scaleform::GFx::AMP::ThreadMgr *)-280 )
    v10 = 0;
  else
    v10 = (Scaleform::GFx::AMP::Message *)&this->MsgSendQueue.QueueLock.cs.LockSemaphore;
  this->MsgSendQueue.Queue.Root.pPrev = v10;
  this->MsgSendQueue.Queue.Root.pNext = v10;
  InterlockedExchange((volatile LONG *)&this->MsgSendQueue.QueueSize, 0);
  this->MsgSendQueue.MaxSize = 100;
  this->MsgSendQueue.SizeEvent = sendQueueWaitEvent;
  this->MsgSendQueue.SizeCheckHysterisisPercent = 90;
  if ( sendQueueWaitEvent )
    Scaleform::Event::SetEvent(sendQueueWaitEvent);
  Scaleform::Lock::Lock(&this->MsgUncompressedQueue.QueueLock, 0);
  if ( this == (Scaleform::GFx::AMP::ThreadMgr *)-328 )
    v11 = 0;
  else
    v11 = (Scaleform::GFx::AMP::Message *)&this->MsgUncompressedQueue.QueueLock.cs.LockSemaphore;
  this->MsgUncompressedQueue.Queue.Root.pPrev = v11;
  this->MsgUncompressedQueue.Queue.Root.pNext = v11;
  InterlockedExchange((volatile LONG *)&this->MsgUncompressedQueue.QueueSize, 0);
  this->MsgUncompressedQueue.MaxSize = 100;
  this->MsgUncompressedQueue.SizeEvent = rcvQueueWaitEvent;
  this->MsgUncompressedQueue.SizeCheckHysterisisPercent = 90;
  if ( rcvQueueWaitEvent )
    Scaleform::Event::SetEvent(rcvQueueWaitEvent);
  Scaleform::Lock::Lock(&this->MsgCompressedQueue.QueueLock, 0);
  if ( this == (Scaleform::GFx::AMP::ThreadMgr *)-376 )
    v12 = 0;
  else
    v12 = (Scaleform::GFx::AMP::Message *)&this->MsgCompressedQueue.QueueLock.cs.LockSemaphore;
  this->MsgCompressedQueue.Queue.Root.pPrev = v12;
  this->MsgCompressedQueue.Queue.Root.pNext = v12;
  InterlockedExchange((volatile LONG *)&this->MsgCompressedQueue.QueueSize, 0);
  v13 = sendQueueWaitEvent;
  this->MsgCompressedQueue.MaxSize = 100;
  this->MsgCompressedQueue.SizeEvent = sendQueueWaitEvent;
  this->MsgCompressedQueue.SizeCheckHysterisisPercent = 90;
  if ( sendQueueWaitEvent )
  {
    Scaleform::Event::SetEvent(sendQueueWaitEvent);
    v13 = sendQueueWaitEvent;
  }
  this->SendQueueWaitEvent = v13;
  this->RcvQueueWaitEvent = rcvQueueWaitEvent;
  InterlockedExchange((volatile LONG *)&this->MsgVersion, 33);
  this->ConnectionChangedCallback = connectionCallback;
  this->SocketFactory = socketFactory;
  this->LastGFxVersion = 0;
  this->SendCallback = sendCallback;
  this->MsgTypeRegistry.pObject = 0;
  Scaleform::GFx::AS3::AvmDisplayObj::Bind(
    (Scaleform::GFx::AS3::AvmDisplayObj *)&this->Sock,
    (Scaleform::GFx::DisplayObject *)&this->SocketLock);
  v17 = 580;
  v14 = (Scaleform::GFx::AMP::MessageTypeRegistry *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      this,
                                                      12,
                                                      &v17);
  if ( v14 )
  {
    v14->__vftable = (Scaleform::GFx::AMP::MessageTypeRegistry_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v14->RefCount = 1;
    v14->__vftable = (Scaleform::GFx::AMP::MessageTypeRegistry_vtbl *)&Scaleform::GFx::AMP::MessageTypeRegistry::`vftable';
    v14->DescriptorMap.mHash.pTable = 0;
    v15 = v14;
  }
  else
  {
    v15 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->MsgTypeRegistry.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->MsgTypeRegistry.pObject = v15;
  Scaleform::GFx::AMP::MessageTypeRegistry::AddMessageType<Scaleform::GFx::AMP::MessageHeartbeat>(
    this->MsgTypeRegistry.pObject,
    0,
    0);
  Scaleform::GFx::AMP::MessageTypeRegistry::AddMessageType<Scaleform::GFx::AMP::MessageCompressed>(
    this->MsgTypeRegistry.pObject,
    0,
    0);
  Scaleform::GFx::AMP::MessageTypeRegistry::AddMessageType<Scaleform::GFx::AMP::MessagePort>(
    this->MsgTypeRegistry.pObject,
    0,
    0);
  Scaleform::GFx::AMP::MessageTypeRegistry::AddMessageType<Scaleform::GFx::AMP::MessageLog>(
    this->MsgTypeRegistry.pObject,
    0,
    0);
  if ( msgTypeRegistry )
    Scaleform::GFx::AMP::MessageTypeRegistry::AddMessageTypeRegistry(this->MsgTypeRegistry.pObject, msgTypeRegistry);
}
