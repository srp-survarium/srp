void __thiscall Scaleform::GFx::AS3::SocketThreadMgr::~SocketThreadMgr(Scaleform::GFx::AS3::SocketThreadMgr *this)
{
  volatile LONG *v2; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::RefCountVImpl *v5; // ecx

  this->__vftable = (Scaleform::GFx::AS3::SocketThreadMgr_vtbl *)&Scaleform::GFx::AS3::SocketThreadMgr::`vftable';
  Scaleform::GFx::AS3::SocketThreadMgr::Uninit(this);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo>::DestructArray(
    this->EventQueue.Data.Data,
    this->EventQueue.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->EventQueue.Data.Data);
  Scaleform::Lock::~Lock(&this->EventQueueLock);
  Scaleform::Lock::~Lock(&this->StatusLock);
  Scaleform::GFx::AMP::Socket::~Socket(&this->Sock);
  Scaleform::Lock::~Lock(&this->SocketLock);
  v2 = (volatile LONG *)(this->IpAddress.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v2 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
  pObject = (Scaleform::RefCountVImpl *)this->SendingBuffer.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::Lock::~Lock(&this->SendingBufferLock);
  v4 = (Scaleform::RefCountVImpl *)this->ReceivedBuffer.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  Scaleform::Lock::~Lock(&this->ReceivedBufferLock);
  v5 = (Scaleform::RefCountVImpl *)this->SocketThread.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
