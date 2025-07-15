void __thiscall Scaleform::GFx::AMP::ThreadMgr::~ThreadMgr(Scaleform::GFx::AMP::ThreadMgr *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  volatile LONG *v3; // edi
  volatile LONG *v4; // edi
  volatile LONG *v5; // edi
  Scaleform::RefCountVImpl *v6; // ecx
  Scaleform::RefCountVImpl *v7; // ecx
  Scaleform::RefCountVImpl *v8; // ecx
  Scaleform::RefCountVImpl *v9; // ecx

  this->__vftable = (Scaleform::GFx::AMP::ThreadMgr_vtbl *)&Scaleform::GFx::AMP::ThreadMgr::`vftable';
  Scaleform::GFx::AMP::ThreadMgr::UninitAmp(this);
  pObject = (Scaleform::RefCountVImpl *)this->MsgTypeRegistry.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::Lock::~Lock(&this->MsgCompressedQueue.QueueLock);
  Scaleform::Lock::~Lock(&this->MsgUncompressedQueue.QueueLock);
  Scaleform::Lock::~Lock(&this->MsgSendQueue.QueueLock);
  Scaleform::Lock::~Lock(&this->MsgReceivedQueue.QueueLock);
  Scaleform::Lock::~Lock(&this->StatusLock);
  Scaleform::Lock::~Lock(&this->InitLock);
  Scaleform::GFx::AMP::Socket::~Socket(&this->Sock);
  Scaleform::Lock::~Lock(&this->SocketLock);
  v3 = (volatile LONG *)(this->IpAddress.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  v4 = (volatile LONG *)(this->BroadcastFile.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
  v5 = (volatile LONG *)(this->BroadcastApp.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v5 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v5);
  Scaleform::Lock::~Lock(&this->BroadcastInfoLock);
  v6 = (Scaleform::RefCountVImpl *)this->CompressThread.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  v7 = (Scaleform::RefCountVImpl *)this->BroadcastRecvThread.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  v8 = (Scaleform::RefCountVImpl *)this->BroadcastThread.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  v9 = (Scaleform::RefCountVImpl *)this->SocketThread.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
