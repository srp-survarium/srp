char __thiscall Scaleform::GFx::AMP::ThreadMgr::SocketConnect(
        Scaleform::GFx::AMP::ThreadMgr *this,
        Scaleform::String *errorMsg)
{
  Scaleform::Lock *p_StatusLock; // edi
  Scaleform::GFx::AMP::ConnStatusInterface::StatusType ConnectionStatus; // eax
  Scaleform::GFx::AMP::ConnStatusInterface *ConnectionChangedCallback; // ecx
  Scaleform::Thread *v7; // eax
  Scaleform::Thread *v8; // eax
  Scaleform::Thread *v9; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  bool Exiting; // [esp+13h] [ebp-5h]

  p_StatusLock = &this->StatusLock;
  EnterCriticalSection(&this->StatusLock.cs);
  ConnectionStatus = this->ConnectionStatus;
  if ( ConnectionStatus != CS_Connecting )
  {
    ConnectionChangedCallback = this->ConnectionChangedCallback;
    this->ConnectionStatus = CS_Connecting;
    if ( ConnectionChangedCallback )
      ConnectionChangedCallback->OnStatusChanged(ConnectionChangedCallback, CS_Connecting, ConnectionStatus, uri);
  }
  LeaveCriticalSection(&p_StatusLock->cs);
  EnterCriticalSection(&p_StatusLock->cs);
  EnterCriticalSection(&p_StatusLock->cs);
  Exiting = this->Exiting;
  LeaveCriticalSection(&p_StatusLock->cs);
  if ( Exiting )
  {
    Scaleform::GFx::AMP::Socket::Destroy(&this->Sock);
LABEL_6:
    LeaveCriticalSection(&p_StatusLock->cs);
    return 0;
  }
  if ( this->Server )
  {
    if ( !Scaleform::GFx::AMP::Socket::CreateServer(&this->Sock, this->Port, errorMsg) )
    {
      EnterCriticalSection(&p_StatusLock->cs);
      this->Exiting = 1;
      LeaveCriticalSection(&p_StatusLock->cs);
      Scaleform::GFx::AMP::Socket::Destroy(&this->Sock);
      LeaveCriticalSection(&p_StatusLock->cs);
      return 0;
    }
  }
  else
  {
    Scaleform::GFx::AMP::Socket::Destroy(&this->Sock);
    if ( !Scaleform::GFx::AMP::Socket::CreateClient(
            &this->Sock,
            (const char *)((this->IpAddress.HeapTypeBits & 0xFFFFFFFC) + 8),
            this->Port,
            errorMsg) )
      goto LABEL_6;
  }
  LeaveCriticalSection(&p_StatusLock->cs);
  if ( this->BroadcastPort && !this->BroadcastThread.pObject )
  {
    v7 = (Scaleform::Thread *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::operator new(
                                0x38u,
                                (Scaleform::MemAddressStub *)this);
    if ( v7 )
    {
      Scaleform::Thread::Thread(
        v7,
        (int (__cdecl *)(Scaleform::Thread *, void *))Scaleform::GFx::AMP::ThreadMgr::BroadcastThreadLoop,
        this,
        (unsigned int)&loc_20000,
        -1,
        NotRunning);
      v9 = v8;
    }
    else
    {
      v9 = 0;
    }
    pObject = (Scaleform::RefCountVImpl *)this->BroadcastThread.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->BroadcastThread.pObject = v9;
    if ( v9 )
    {
      if ( v9->Start(v9, Running) )
        this->BroadcastThread.pObject->SetThreadName(this->BroadcastThread.pObject, "Scaleform AMP Broadcast Thread");
    }
  }
  return 1;
}
