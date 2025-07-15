void __thiscall Scaleform::GFx::AMP::ThreadMgr::UninitAmp(Scaleform::GFx::AMP::ThreadMgr *this)
{
  Scaleform::Thread *pObject; // ecx
  Scaleform::RefCountVImpl *v3; // ecx
  Scaleform::Thread *v4; // ecx
  Scaleform::RefCountVImpl *v5; // ecx
  Scaleform::Thread *v6; // ecx
  Scaleform::RefCountVImpl *v7; // ecx
  Scaleform::Thread *v8; // ecx
  Scaleform::RefCountVImpl *v9; // ecx
  Scaleform::GFx::AMP::ConnStatusInterface::StatusType ConnectionStatus; // eax
  Scaleform::GFx::AMP::ConnStatusInterface *ConnectionChangedCallback; // ecx
  Scaleform::Lock *lpCriticalSection; // [esp+10h] [ebp-4h]

  lpCriticalSection = &this->InitLock;
  EnterCriticalSection(&this->InitLock.cs);
  EnterCriticalSection(&this->StatusLock.cs);
  this->Exiting = 1;
  LeaveCriticalSection(&this->StatusLock.cs);
  pObject = this->BroadcastThread.pObject;
  if ( pObject )
  {
    Scaleform::Waitable::Wait(pObject, 0xFFFFFFFF);
    v3 = (Scaleform::RefCountVImpl *)this->BroadcastThread.pObject;
    if ( v3 )
      Scaleform::RefCountImpl::Release(v3);
    this->BroadcastThread.pObject = 0;
  }
  v4 = this->BroadcastRecvThread.pObject;
  if ( v4 )
  {
    Scaleform::Waitable::Wait(v4, 0xFFFFFFFF);
    v5 = (Scaleform::RefCountVImpl *)this->BroadcastRecvThread.pObject;
    if ( v5 )
      Scaleform::RefCountImpl::Release(v5);
    this->BroadcastRecvThread.pObject = 0;
  }
  v6 = this->CompressThread.pObject;
  if ( v6 )
  {
    Scaleform::Waitable::Wait(v6, 0xFFFFFFFF);
    v7 = (Scaleform::RefCountVImpl *)this->CompressThread.pObject;
    if ( v7 )
      Scaleform::RefCountImpl::Release(v7);
    this->CompressThread.pObject = 0;
  }
  v8 = this->SocketThread.pObject;
  if ( v8 )
  {
    Scaleform::Waitable::Wait(v8, 0xFFFFFFFF);
    v9 = (Scaleform::RefCountVImpl *)this->SocketThread.pObject;
    if ( v9 )
      Scaleform::RefCountImpl::Release(v9);
    this->SocketThread.pObject = 0;
  }
  Scaleform::GFx::AMP::ThreadMgr::MsgQueue::Clear(&this->MsgSendQueue);
  Scaleform::GFx::AMP::ThreadMgr::MsgQueue::Clear(&this->MsgReceivedQueue);
  Scaleform::GFx::AMP::ThreadMgr::MsgQueue::Clear(&this->MsgUncompressedQueue);
  Scaleform::GFx::AMP::ThreadMgr::MsgQueue::Clear(&this->MsgCompressedQueue);
  InterlockedExchange((volatile LONG *)&this->SendRate, 0);
  InterlockedExchange((volatile LONG *)&this->ReceiveRate, 0);
  EnterCriticalSection(&this->StatusLock.cs);
  ConnectionStatus = this->ConnectionStatus;
  if ( ConnectionStatus )
  {
    ConnectionChangedCallback = this->ConnectionChangedCallback;
    this->ConnectionStatus = CS_Idle;
    if ( ConnectionChangedCallback )
      ConnectionChangedCallback->OnStatusChanged(ConnectionChangedCallback, CS_Idle, ConnectionStatus, "Disconnected");
  }
  LeaveCriticalSection(&this->StatusLock.cs);
  LeaveCriticalSection(&lpCriticalSection->cs);
}
