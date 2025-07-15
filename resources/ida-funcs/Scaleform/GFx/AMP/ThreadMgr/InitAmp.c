char __thiscall Scaleform::GFx::AMP::ThreadMgr::InitAmp(
        Scaleform::GFx::AMP::ThreadMgr *this,
        const __m128i *address,
        unsigned int port,
        unsigned int broadcastPort,
        int initMsg)
{
  Scaleform::GFx::AMP::Message *v6; // eax
  Scaleform::GFx::AMP::Message *v7; // edi
  Scaleform::Thread *pObject; // ecx
  BOOL v9; // eax
  Scaleform::Thread *v10; // eax
  Scaleform::Thread *v11; // eax
  Scaleform::Thread *v12; // edi
  Scaleform::RefCountVImpl *v13; // ecx

  if ( initMsg )
  {
    Scaleform::GFx::AMP::ThreadMgr::MsgQueue::PushBack(&this->MsgSendQueue, (Scaleform::GFx::AMP::Message *)initMsg);
  }
  else
  {
    initMsg = 580;
    v6 = (Scaleform::GFx::AMP::Message *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                           Scaleform::Memory::pGlobalHeap,
                                           this,
                                           24,
                                           &initMsg);
    v7 = v6;
    if ( v6 )
    {
      Scaleform::GFx::AMP::Message::Message(v6);
      v7->__vftable = (Scaleform::GFx::AMP::Message_vtbl *)&Scaleform::GFx::AMP::MessageHeartbeat::`vftable';
    }
    else
    {
      v7 = 0;
    }
    Scaleform::GFx::AMP::ThreadMgr::MsgQueue::PushBack(&this->MsgSendQueue, v7);
  }
  EnterCriticalSection(&this->InitLock.cs);
  pObject = this->SocketThread.pObject;
  if ( pObject && !(unsigned __int8)Scaleform::Thread::IsSignaled(pObject) )
  {
    if ( this->Server )
      v9 = address == 0;
    else
      v9 = Scaleform::String::operator==(&this->IpAddress, address->m128i_i8);
    if ( v9 && port == this->Port )
      goto LABEL_27;
    Scaleform::GFx::AMP::ThreadMgr::UninitAmp(this);
  }
  this->Exiting = 0;
  this->Port = port;
  this->BroadcastPort = broadcastPort;
  this->Server = address == 0;
  if ( address )
    Scaleform::String::operator=(&this->IpAddress, address);
  if ( !this->Port )
  {
LABEL_26:
    Scaleform::GFx::AMP::ThreadMgr::StartBroadcastRecv(this, this->BroadcastRecvPort);
LABEL_27:
    LeaveCriticalSection(&this->InitLock.cs);
    return 1;
  }
  initMsg = 2;
  v10 = (Scaleform::Thread *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                               Scaleform::Memory::pGlobalHeap,
                               this,
                               56,
                               &initMsg);
  if ( v10 )
  {
    Scaleform::Thread::Thread(
      v10,
      (int (__cdecl *)(Scaleform::Thread *, void *))Scaleform::GFx::AMP::ThreadMgr::SocketThreadLoop,
      this,
      (unsigned int)&loc_20000,
      -1,
      NotRunning);
    v12 = v11;
  }
  else
  {
    v12 = 0;
  }
  v13 = (Scaleform::RefCountVImpl *)this->SocketThread.pObject;
  if ( v13 )
    Scaleform::RefCountImpl::Release(v13);
  this->SocketThread.pObject = v12;
  if ( v12 && v12->Start(v12, Running) )
  {
    this->SocketThread.pObject->SetThreadName(this->SocketThread.pObject, "Scaleform AMP Socket");
    goto LABEL_26;
  }
  LeaveCriticalSection(&this->InitLock.cs);
  return 0;
}
