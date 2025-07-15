BOOL __usercall Scaleform::GFx::AMP::ThreadMgr::SendReceiveLoop@<eax>(
        Scaleform::GFx::AMP::ThreadMgr *this@<ecx>,
        _DWORD *a2@<ebp>)
{
  Scaleform::Event *SendQueueWaitEvent; // ecx
  Scaleform::Event *RcvQueueWaitEvent; // ecx
  Scaleform::GFx::AMP::Message *v5; // eax
  Scaleform::GFx::AMP::Message *v6; // ebp
  Scaleform::MemoryHeap *v7; // eax
  Scaleform::GFx::AMP::AmpStream *v8; // eax
  Scaleform::Thread *v9; // eax
  Scaleform::Thread *v10; // eax
  Scaleform::Thread *v11; // ebx
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::AMP::AmpStream *v13; // eax
  Scaleform::GFx::AS3::SoundObject *v14; // eax
  unsigned int UsedSpace; // ebp
  bool Exiting; // bl
  Scaleform::RefCountVImpl *v17; // ebx
  bool v18; // bl
  Scaleform::GFx::AMP::SendInterface *SendCallback; // ecx
  bool v21; // zf
  Scaleform::RefCountVImpl *MessageForSending; // ebp
  Scaleform::GFx::AMP::AmpStream *v23; // eax
  Scaleform::GFx::AS3::SoundObject *v24; // eax
  Scaleform::GFx::AS3::SoundObject *v25; // edi
  unsigned int v26; // eax
  int v27; // eax
  signed int v28; // eax
  unsigned int v29; // edi
  Scaleform::GFx::AMP::Message *Message; // ebp
  Scaleform::MemoryHeap *v31; // eax
  Scaleform::RefCountVImpl *ProfileTicks; // ebp
  unsigned int v33; // edi
  bool v34; // bl
  bool v36; // [esp+37h] [ebp-235h]
  Scaleform::RefCountVImpl *v37; // [esp+38h] [ebp-234h]
  char *dataBuffer; // [esp+3Ch] [ebp-230h]
  int v39; // [esp+40h] [ebp-22Ch]
  int v40; // [esp+44h] [ebp-228h]
  int v41; // [esp+48h] [ebp-224h]
  Scaleform::RefCountVImpl *v42; // [esp+4Ch] [ebp-220h]
  Scaleform::RefCountVImpl *v43; // [esp+50h] [ebp-21Ch]
  _DWORD v44[2]; // [esp+5Ch] [ebp-210h] BYREF
  int v45; // [esp+64h] [ebp-208h] BYREF
  int v46; // [esp+68h] [ebp-204h] BYREF
  char v47[512]; // [esp+6Ch] [ebp-200h] BYREF

  SendQueueWaitEvent = this->SendQueueWaitEvent;
  if ( SendQueueWaitEvent )
    Scaleform::Event::SetEvent(SendQueueWaitEvent);
  RcvQueueWaitEvent = this->RcvQueueWaitEvent;
  if ( RcvQueueWaitEvent )
    Scaleform::Event::SetEvent(RcvQueueWaitEvent);
  if ( Scaleform::GFx::AMP::ThreadMgr::SocketConnect(this, 0) )
  {
    while ( !Scaleform::GFx::AMP::Socket::Accept(&this->Sock, 1) )
    {
LABEL_32:
      if ( !Scaleform::GFx::AMP::ThreadMgr::SocketConnect(this, 0) )
        goto LABEL_33;
    }
    Scaleform::GFx::AMP::Socket::SetBlocking(&this->Sock, 0);
    this->LastRcvdHeartbeat = Scaleform::Timer::GetTicks();
    InterlockedExchange((volatile LONG *)&this->ValidConnection, 1);
    InterlockedExchange((volatile LONG *)&this->MsgVersion, 33);
    v46 = 580;
    v5 = (Scaleform::GFx::AMP::Message *)((int (__thiscall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AMP::ThreadMgr *, int, int *, _DWORD *))Scaleform::Memory::pGlobalHeap->AllocAutoHeap)(
                                           Scaleform::Memory::pGlobalHeap,
                                           this,
                                           24,
                                           &v46,
                                           a2);
    v6 = v5;
    if ( v5 )
    {
      Scaleform::GFx::AMP::Message::Message(v5);
      v6->__vftable = (Scaleform::GFx::AMP::Message_vtbl *)&Scaleform::GFx::AMP::MessageHeartbeat::`vftable';
    }
    else
    {
      v6 = 0;
    }
    if ( this->ValidConnection.Value )
    {
      EnterCriticalSection(&this->MsgSendQueue.QueueLock.cs);
      v6->pPrev = this->MsgSendQueue.Queue.Root.pPrev;
      v6->pNext = (Scaleform::GFx::AMP::Message *)&this->MsgSendQueue.QueueLock.cs.LockSemaphore;
      this->MsgSendQueue.Queue.Root.pPrev->pNext = v6;
      this->MsgSendQueue.Queue.Root.pPrev = v6;
      InterlockedExchangeAdd((volatile LONG *)&this->MsgSendQueue.QueueSize, 1);
      v7 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v6);
      Scaleform::GFx::AMP::ThreadMgr::MsgQueue::CheckSize(&this->MsgSendQueue, v7);
      LeaveCriticalSection(&this->MsgSendQueue.QueueLock.cs);
    }
    else
    {
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v6);
    }
    v46 = 2;
    v8 = (Scaleform::GFx::AMP::AmpStream *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                             Scaleform::Memory::pGlobalHeap,
                                             this,
                                             24,
                                             &v46);
    if ( v8 )
      Scaleform::GFx::AMP::AmpStream::AmpStream(v8);
    if ( !this->CompressThread.pObject )
    {
      v45 = 2;
      v9 = (Scaleform::Thread *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                  Scaleform::Memory::pGlobalHeap,
                                  this,
                                  56,
                                  &v45);
      if ( v9 )
      {
        Scaleform::Thread::Thread(
          v9,
          (int (__cdecl *)(Scaleform::Thread *, void *))Scaleform::GFx::AMP::ThreadMgr::CompressThreadLoop,
          this,
          (unsigned int)&loc_20000,
          -1,
          NotRunning);
        v11 = v10;
      }
      else
      {
        v11 = 0;
      }
      pObject = (Scaleform::RefCountVImpl *)this->CompressThread.pObject;
      if ( pObject )
        Scaleform::RefCountImpl::Release(pObject);
      this->CompressThread.pObject = v11;
      if ( v11->Start(v11, Running) )
        this->CompressThread.pObject->SetThreadName(this->CompressThread.pObject, "Scaleform AMP Compress");
    }
    Scaleform::Timer::GetProfileTicks();
    a2 = v44;
    v44[0] = 2;
    v13 = (Scaleform::GFx::AMP::AmpStream *)((int (__thiscall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AMP::ThreadMgr *, int))Scaleform::Memory::pGlobalHeap->AllocAutoHeap)(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              24);
    if ( v13 )
      Scaleform::GFx::AMP::AmpStream::AmpStream(v13);
    else
      v14 = 0;
    v42 = (Scaleform::RefCountVImpl *)v14;
    dataBuffer = 0;
    UsedSpace = Scaleform::SysAllocPagedMalloc::GetUsedSpace(v14);
    v40 = UsedSpace;
    EnterCriticalSection(&this->StatusLock.cs);
    Exiting = this->Exiting;
    LeaveCriticalSection(&this->StatusLock.cs);
    if ( Exiting )
    {
LABEL_27:
      v17 = v37;
LABEL_28:
      if ( v42 )
        Scaleform::RefCountImpl::Release(v42);
      if ( v17 )
        Scaleform::RefCountImpl::Release(v17);
      goto LABEL_32;
    }
    while ( 1 )
    {
      if ( (unsigned __int8)Scaleform::GFx::AMP::Socket::CheckAbort(&this->Sock) )
        goto LABEL_27;
      SendCallback = this->SendCallback;
      v36 = 0;
      if ( SendCallback )
        v36 = SendCallback->OnSendLoop(SendCallback);
      v21 = UsedSpace == 0;
      if ( !UsedSpace )
      {
        MessageForSending = (Scaleform::RefCountVImpl *)Scaleform::GFx::AMP::ThreadMgr::RetrieveMessageForSending(this);
        if ( !MessageForSending )
          goto LABEL_51;
        v44[0] = 2;
        v23 = (Scaleform::GFx::AMP::AmpStream *)((int (__thiscall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AMP::ThreadMgr *, int, _DWORD *, _DWORD *))Scaleform::Memory::pGlobalHeap->AllocAutoHeap)(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  this,
                                                  24,
                                                  v44,
                                                  a2);
        if ( v23 )
        {
          Scaleform::GFx::AMP::AmpStream::AmpStream(v23);
          v25 = v24;
        }
        else
        {
          v25 = 0;
        }
        if ( v43 )
          Scaleform::RefCountImpl::Release(v43);
        a2 = &v25->Scaleform::RefCountBase<Scaleform::GFx::AS3::SoundObject,323>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
        v43 = (Scaleform::RefCountVImpl *)v25;
        MessageForSending->Release(MessageForSending);
        v40 = Scaleform::SysAllocPagedMalloc::GetUsedSpace(v25);
        dataBuffer = (char *)Scaleform::Render::Renderer2D::GetContextNotify(v25);
        Scaleform::RefCountImpl::Release(MessageForSending);
        UsedSpace = v40;
        v21 = v40 == 0;
      }
      if ( !v21 )
      {
        v26 = UsedSpace;
        if ( UsedSpace > 0x200 )
          v26 = 512;
        v27 = Scaleform::GFx::AMP::Socket::Send(&this->Sock, dataBuffer, v26);
        if ( v27 > 0 )
        {
          v39 += v27;
          dataBuffer += v27;
          v40 = UsedSpace - v27;
          v36 = 1;
        }
      }
LABEL_51:
      v28 = Scaleform::GFx::AMP::Socket::Receive(&this->Sock, v47, 512);
      v17 = v37;
      if ( v28 > 0 )
      {
        v41 += v28;
        v36 = 1;
        Scaleform::GFx::AMP::AmpStream::Append((Scaleform::GFx::AMP::AmpStream *)v37, (unsigned __int8 *)v47, v28);
        this->LastRcvdHeartbeat = Scaleform::Timer::GetTicks();
        InterlockedExchange((volatile LONG *)&this->ValidConnection, 1);
      }
      v29 = Scaleform::SysAllocPagedMalloc::GetUsedSpace((Scaleform::GFx::AS3::SoundObject *)v37);
      if ( v29 )
      {
        if ( v29 >= Scaleform::GFx::AMP::AmpStream::FirstMessageSize((Scaleform::GFx::AMP::AmpStream *)v37) )
        {
          Message = Scaleform::GFx::AMP::ThreadMgr::CreateAndReadMessage(this, (Scaleform::String)v37);
          Scaleform::GFx::AMP::AmpStream::PopFirstMessage((Scaleform::GFx::AMP::AmpStream *)v37);
          if ( Message )
          {
            EnterCriticalSection(&this->MsgReceivedQueue.QueueLock.cs);
            Message->pPrev = this->MsgReceivedQueue.Queue.Root.pPrev;
            Message->pNext = (Scaleform::GFx::AMP::Message *)&this->MsgReceivedQueue.QueueLock.cs.LockSemaphore;
            this->MsgReceivedQueue.Queue.Root.pPrev->pNext = Message;
            this->MsgReceivedQueue.Queue.Root.pPrev = Message;
            InterlockedExchangeAdd((volatile LONG *)&this->MsgReceivedQueue.QueueSize, 1);
            v31 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, Message);
            Scaleform::GFx::AMP::ThreadMgr::MsgQueue::CheckSize(&this->MsgReceivedQueue, v31);
            LeaveCriticalSection(&this->MsgReceivedQueue.QueueLock.cs);
          }
        }
      }
      Scaleform::GFx::AMP::ThreadMgr::UpdateValidConnection(this);
      if ( !this->ValidConnection.Value )
      {
        Scaleform::GFx::AMP::ThreadMgr::MsgQueue::Clear(&this->MsgSendQueue);
        goto LABEL_28;
      }
      if ( !v36 )
        Scaleform::Thread::MSleep(0xAu);
      ProfileTicks = (Scaleform::RefCountVImpl *)Scaleform::Timer::GetProfileTicks();
      v33 = (char *)ProfileTicks - (char *)v43;
      if ( (char *)ProfileTicks - (char *)v43 > (unsigned int)&loc_F4240 )
      {
        InterlockedExchange((volatile LONG *)&this->SendRate, 1000000 * v39 / v33);
        InterlockedExchange((volatile LONG *)&this->ReceiveRate, 1000000 * v41 / v33);
        v43 = ProfileTicks;
        v39 = 0;
        v41 = 0;
      }
      EnterCriticalSection(&this->StatusLock.cs);
      v34 = this->Exiting;
      LeaveCriticalSection(&this->StatusLock.cs);
      if ( v34 )
        goto LABEL_27;
      UsedSpace = v40;
    }
  }
LABEL_33:
  EnterCriticalSection(&this->StatusLock.cs);
  v18 = this->Exiting;
  LeaveCriticalSection(&this->StatusLock.cs);
  return !v18;
}
