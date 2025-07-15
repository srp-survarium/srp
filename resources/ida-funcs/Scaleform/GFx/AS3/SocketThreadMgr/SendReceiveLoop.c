bool __thiscall Scaleform::GFx::AS3::SocketThreadMgr::SendReceiveLoop(Scaleform::GFx::AS3::SocketThreadMgr *this)
{
  Scaleform::Lock *p_StatusLock; // edi
  DWORD TicksMs; // ebp
  bool Exiting; // bl
  bool v5; // bl
  bool v6; // bl
  Scaleform::GFx::AS3::SocketBuffer *pObject; // eax
  unsigned int Size; // edi
  const char *i; // ebp
  unsigned int v10; // eax
  int v11; // eax
  Scaleform::GFx::AS3::SocketBuffer *v12; // ebp
  void *v13; // esi
  unsigned int v15; // ebp
  Scaleform::GFx::AS3::SocketBuffer *v16; // edi
  unsigned int v17; // ebx
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,327>,Scaleform::ArrayConstPolicy<0,4,1> > *p_Data; // edi
  unsigned int v19; // ebp
  unsigned int v20; // ecx
  char *v21; // edi
  char *j; // eax
  bool v23; // bl
  bool v24; // bl
  bool v25; // bl
  void *v26; // esi
  bool actionPerformed; // [esp+13h] [ebp-209h]
  Scaleform::String errorMsg; // [esp+14h] [ebp-208h] BYREF
  unsigned int packetSize; // [esp+18h] [ebp-204h] BYREF
  char bufferReceived[512]; // [esp+1Ch] [ebp-200h] BYREF

  Scaleform::String::String(&errorMsg);
  p_StatusLock = &this->StatusLock;
  TicksMs = Scaleform::Timer::GetTicksMs();
  EnterCriticalSection(&this->StatusLock.cs);
  Exiting = this->Exiting;
  LeaveCriticalSection(&this->StatusLock.cs);
  if ( Exiting )
  {
LABEL_5:
    Scaleform::GFx::AS3::SocketThreadMgr::QueueEvent(this, EventConnect, 0, 0);
    Scaleform::GFx::AMP::Socket::SetBlocking(&this->Sock, 0);
    EnterCriticalSection(&this->StatusLock.cs);
    v6 = this->Exiting;
    LeaveCriticalSection(&this->StatusLock.cs);
    if ( v6 )
    {
LABEL_36:
      EnterCriticalSection(&p_StatusLock->cs);
      v24 = this->Exiting;
      LeaveCriticalSection(&p_StatusLock->cs);
      v25 = !v24;
      v26 = (void *)(errorMsg.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((errorMsg.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v26);
      return v25;
    }
    while ( 1 )
    {
      if ( (unsigned __int8)Scaleform::GFx::AMP::Socket::CheckAbort(&this->Sock) )
        goto LABEL_36;
      actionPerformed = 0;
      EnterCriticalSection(&this->SendingBufferLock.cs);
      pObject = this->SendingBuffer.pObject;
      Size = pObject->Data.Data.Size;
      for ( i = (const char *)pObject->Data.Data.Data; Size; actionPerformed = 1 )
      {
        v10 = Size;
        if ( Size > 0x200 )
          v10 = 512;
        v11 = Scaleform::GFx::AMP::Socket::Send(&this->Sock, i, v10);
        if ( v11 <= 0 )
          break;
        i += v11;
        Size -= v11;
      }
      v12 = this->SendingBuffer.pObject;
      if ( v12->Data.Data.Size )
      {
        if ( (v12->Data.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
          goto LABEL_19;
      }
      else if ( !v12->Data.Data.Policy.Capacity )
      {
LABEL_19:
        Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,327>,Scaleform::ArrayConstPolicy<0,4,1>>::Reserve(
          &v12->Data.Data,
          &v12->Data,
          0);
      }
      v12->Data.Data.Size = 0;
      v12->SeekToBegin(v12);
      LeaveCriticalSection(&this->SendingBufferLock.cs);
      v15 = Scaleform::GFx::AMP::Socket::Receive(&this->Sock, bufferReceived, 512);
      packetSize = v15;
      if ( v15 )
      {
        actionPerformed = 1;
        EnterCriticalSection(&this->ReceivedBufferLock.cs);
        v16 = this->ReceivedBuffer.pObject;
        v17 = v16->Data.Data.Size;
        p_Data = &v16->Data.Data;
        v19 = v17 + v15;
        if ( v19 >= v17 )
        {
          if ( v19 >= p_Data->Policy.Capacity )
            Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,327>,Scaleform::ArrayConstPolicy<0,4,1>>::Reserve(
              p_Data,
              p_Data,
              v19 + (v19 >> 2));
        }
        else if ( v19 < p_Data->Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,327>,Scaleform::ArrayConstPolicy<0,4,1>>::Reserve(
            p_Data,
            p_Data,
            v19);
        }
        v20 = packetSize;
        p_Data->Size = v19;
        v21 = (char *)&p_Data->Data[v17];
        for ( j = bufferReceived; v20; --v20 )
        {
          if ( v21 )
            *v21 = *j;
          ++j;
          ++v21;
        }
        Scaleform::GFx::AS3::SocketBuffer::DiscardReadBytes(this->ReceivedBuffer.pObject);
        Scaleform::GFx::AS3::SocketThreadMgr::QueueEvent(this, EventSocketData, &packetSize, 1u);
        LeaveCriticalSection(&this->ReceivedBufferLock.cs);
      }
      if ( !Scaleform::GFx::AMP::Socket::IsConnected(&this->Sock) )
      {
        EnterCriticalSection(&this->StatusLock.cs);
        this->Exiting = 1;
        LeaveCriticalSection(&this->StatusLock.cs);
        Scaleform::GFx::AS3::SocketThreadMgr::QueueEvent(this, EventClose, 0, 0);
      }
      if ( !actionPerformed )
        Scaleform::Thread::MSleep(0xAu);
      p_StatusLock = &this->StatusLock;
      EnterCriticalSection(&this->StatusLock.cs);
      v23 = this->Exiting;
      LeaveCriticalSection(&this->StatusLock.cs);
      if ( v23 )
        goto LABEL_36;
    }
  }
  while ( 1 )
  {
    if ( Scaleform::GFx::AMP::Socket::CreateClient(
           &this->Sock,
           (const char *)((this->IpAddress.HeapTypeBits & 0xFFFFFFFC) + 8),
           this->Port,
           &errorMsg) )
    {
      goto LABEL_5;
    }
    if ( Scaleform::Timer::GetTicksMs() - (unsigned __int64)TicksMs > this->ConnectTimeout )
      break;
    Scaleform::Thread::MSleep(0xAu);
    EnterCriticalSection(&this->StatusLock.cs);
    v5 = this->Exiting;
    LeaveCriticalSection(&this->StatusLock.cs);
    if ( v5 )
      goto LABEL_5;
  }
  v13 = (void *)(errorMsg.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((errorMsg.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
  return 0;
}
