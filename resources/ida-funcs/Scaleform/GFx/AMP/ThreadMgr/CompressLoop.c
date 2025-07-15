char __thiscall Scaleform::GFx::AMP::ThreadMgr::CompressLoop(Scaleform::GFx::AMP::ThreadMgr *this)
{
  Scaleform::Lock *p_StatusLock; // esi
  bool Exiting; // bl
  Scaleform::Event *RcvQueueWaitEvent; // ecx
  Scaleform::GFx::AMP::Message *pNext; // edi
  Scaleform::GFx::AMP::Message *p_LockSemaphore; // ecx
  Scaleform::MemoryHeap *v7; // eax
  Scaleform::MemoryHeap *v8; // ebx
  bool (__thiscall *Uncompress)(Scaleform::GFx::AMP::Message *, Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *); // edx
  Scaleform::GFx::AMP::AmpStream *v10; // eax
  Scaleform::RefCountVImpl *v11; // eax
  Scaleform::RefCountVImpl *v12; // esi
  unsigned __int8 GFxVersion; // al
  Scaleform::GFx::AMP::ConnStatusInterface *ConnectionChangedCallback; // ecx
  Scaleform::GFx::AMP::ConnStatusInterface *v15; // ecx
  Scaleform::GFx::AMP::MessageTypeRegistry *pObject; // esi
  const Scaleform::String *v17; // eax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *p_DescriptorMap; // esi
  const Scaleform::String *v19; // ebx
  unsigned int v20; // eax
  int v21; // eax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > v22; // esi
  unsigned int SizeMask; // ebx
  void *v24; // esi
  int v25; // ecx
  Scaleform::MemoryHeap *v26; // eax
  Scaleform::RefCountVImpl *v27; // esi
  Scaleform::GFx::AMP::Message *v28; // eax
  Scaleform::MemoryHeap *v29; // eax
  Scaleform::MemoryHeap *v30; // ebx
  Scaleform::GFx::AMP::Message *v31; // edi
  void (__thiscall *AddRef)(Scaleform::RefCountVImpl *); // edx
  Scaleform::GFx::AMP::MessageTypeRegistry *v33; // edi
  Scaleform::GFx::AMP::Message *v34; // eax
  void *v35; // edi
  Scaleform::GFx::AMP::MessageCompressed *v36; // ebx
  Scaleform::MemoryHeap *v37; // eax
  Scaleform::AmpServer *Instance; // eax
  Scaleform::GFx::AMP::MessageProfileFrame *v39; // eax
  Scaleform::GFx::AMP::Message *v40; // eax
  Scaleform::GFx::AMP::Message *v41; // esi
  bool v42; // bl
  char v44; // [esp+4Dh] [ebp-2Dh]
  Scaleform::String messageTypeName; // [esp+4Eh] [ebp-2Ch] BYREF
  int v46; // [esp+52h] [ebp-28h] BYREF
  int v47; // [esp+56h] [ebp-24h] BYREF
  Scaleform::List<Scaleform::GFx::AMP::Message,Scaleform::GFx::AMP::Message> *p_Queue; // [esp+5Ah] [ebp-20h]
  int v49; // [esp+5Eh] [ebp-1Ch] BYREF
  unsigned __int8 *buffer; // [esp+62h] [ebp-18h] BYREF
  unsigned int bufferSize; // [esp+66h] [ebp-14h]
  int v52; // [esp+6Ah] [ebp-10h]
  unsigned __int8 *data; // [esp+6Eh] [ebp-Ch] BYREF
  unsigned int dataSize; // [esp+72h] [ebp-8h]
  int v55; // [esp+76h] [ebp-4h]

  p_StatusLock = &this->StatusLock;
  EnterCriticalSection(&this->StatusLock.cs);
  Exiting = this->Exiting;
  LeaveCriticalSection(&p_StatusLock->cs);
  if ( !Exiting )
  {
    p_Queue = &this->MsgSendQueue.Queue;
    do
    {
      RcvQueueWaitEvent = this->RcvQueueWaitEvent;
      v44 = 0;
      if ( RcvQueueWaitEvent && !RcvQueueWaitEvent->IsSignaled(RcvQueueWaitEvent) )
      {
        Scaleform::GFx::AMP::ThreadMgr::MsgQueue::Clear(&this->MsgReceivedQueue);
        v44 = 1;
      }
      pNext = 0;
      EnterCriticalSection(&this->MsgReceivedQueue.QueueLock.cs);
      if ( this == (Scaleform::GFx::AMP::ThreadMgr *)-232 )
        p_LockSemaphore = 0;
      else
        p_LockSemaphore = (Scaleform::GFx::AMP::Message *)&this->MsgReceivedQueue.QueueLock.cs.LockSemaphore;
      if ( this->MsgReceivedQueue.Queue.Root.pNext != p_LockSemaphore )
      {
        pNext = this->MsgReceivedQueue.Queue.Root.pNext;
        v7 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, pNext);
        pNext->pPrev->pNext = pNext->pNext;
        v8 = v7;
        pNext->pNext->pPrev = pNext->pPrev;
        InterlockedExchangeAdd((volatile LONG *)&this->MsgReceivedQueue.QueueSize, -1);
        Scaleform::GFx::AMP::ThreadMgr::MsgQueue::CheckSize(&this->MsgReceivedQueue, v8);
      }
      LeaveCriticalSection(&this->MsgReceivedQueue.QueueLock.cs);
      if ( pNext )
      {
        Uncompress = pNext->Uncompress;
        buffer = 0;
        bufferSize = 0;
        v52 = 0;
        if ( Uncompress(pNext, (Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)&buffer) )
        {
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pNext);
          v46 = 2;
          v10 = (Scaleform::GFx::AMP::AmpStream *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    this,
                                                    24,
                                                    &v46);
          if ( v10 )
          {
            Scaleform::GFx::AMP::AmpStream::AmpStream(v10, buffer, bufferSize);
            v12 = v11;
          }
          else
          {
            v12 = 0;
          }
          pNext = Scaleform::GFx::AMP::ThreadMgr::CreateAndReadMessage(this, (Scaleform::String)v12);
          if ( v12 )
            Scaleform::RefCountImpl::Release(v12);
        }
        GFxVersion = pNext->GFxVersion;
        if ( GFxVersion != this->LastGFxVersion )
        {
          ConnectionChangedCallback = this->ConnectionChangedCallback;
          this->LastGFxVersion = GFxVersion;
          if ( ConnectionChangedCallback )
            ConnectionChangedCallback->OnMsgGFxVersionChanged(ConnectionChangedCallback, pNext->GFxVersion);
        }
        if ( pNext->Version < this->MsgVersion.Value )
        {
          InterlockedExchange((volatile LONG *)&this->MsgVersion, pNext->Version);
          v15 = this->ConnectionChangedCallback;
          if ( v15 )
            v15->OnMsgVersionMismatch(v15, pNext->Version);
        }
        pObject = this->MsgTypeRegistry.pObject;
        v17 = pNext->GetMessageName(pNext, (Scaleform::String *)&v47);
        p_DescriptorMap = (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&pObject->DescriptorMap;
        v19 = v17;
        if ( !p_DescriptorMap->pTable
          || (v20 = Scaleform::String::BernsteinHashFunctionCIS(
                      (char *)((v17->HeapTypeBits & 0xFFFFFFFC) + 8),
                      *(_DWORD *)(v17->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
                      0x1505u),
              v21 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::String>(
                      p_DescriptorMap,
                      v19,
                      v20 & p_DescriptorMap->pTable->SizeMask),
              v21 < 0) )
        {
          p_DescriptorMap = 0;
          v21 = 0;
        }
        if ( p_DescriptorMap && (v22.pTable = p_DescriptorMap->pTable) != 0 && v21 <= (signed int)v22.pTable->SizeMask )
          SizeMask = v22.pTable[2 * v21 + 2].SizeMask;
        else
          SizeMask = 0;
        v24 = (void *)(v47 & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((v47 & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v24);
        if ( SizeMask && (v25 = *(_DWORD *)(SizeMask + 8)) != 0 && *(_BYTE *)(SizeMask + 16) )
        {
          (*(void (__thiscall **)(int, Scaleform::GFx::AMP::Message *))(*(_DWORD *)v25 + 4))(v25, pNext);
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pNext);
        }
        else
        {
          EnterCriticalSection(&this->MsgUncompressedQueue.QueueLock.cs);
          pNext->pPrev = this->MsgUncompressedQueue.Queue.Root.pPrev;
          pNext->pNext = (Scaleform::GFx::AMP::Message *)&this->MsgUncompressedQueue.QueueLock.cs.LockSemaphore;
          this->MsgUncompressedQueue.Queue.Root.pPrev->pNext = pNext;
          this->MsgUncompressedQueue.Queue.Root.pPrev = pNext;
          InterlockedExchangeAdd((volatile LONG *)&this->MsgUncompressedQueue.QueueSize, 1);
          v26 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, pNext);
          Scaleform::GFx::AMP::ThreadMgr::MsgQueue::CheckSize(&this->MsgUncompressedQueue, v26);
          LeaveCriticalSection(&this->MsgUncompressedQueue.QueueLock.cs);
        }
        v44 = 1;
        if ( buffer )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, buffer);
      }
      v27 = 0;
      EnterCriticalSection(&this->MsgSendQueue.QueueLock.cs);
      if ( p_Queue )
        v28 = (Scaleform::GFx::AMP::Message *)&p_Queue[-1];
      else
        v28 = 0;
      if ( p_Queue->Root.pNext != v28 )
      {
        v27 = (Scaleform::RefCountVImpl *)this->MsgSendQueue.Queue.Root.pNext;
        v29 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v27);
        v27[1].__vftable[1].~Scaleform::RefCountVImpl = (void (__thiscall *)(struct Scaleform::RefCountVImpl *))v27[1].RefCount;
        v30 = v29;
        *(_DWORD *)(v27[1].RefCount + 8) = v27[1].__vftable;
        InterlockedExchangeAdd((volatile LONG *)&this->MsgSendQueue.QueueSize, -1);
        Scaleform::GFx::AMP::ThreadMgr::MsgQueue::CheckSize(&this->MsgSendQueue, v30);
      }
      LeaveCriticalSection(&this->MsgSendQueue.QueueLock.cs);
      v31 = (Scaleform::GFx::AMP::Message *)v27;
      if ( v27 )
      {
        if ( this->MsgVersion.Value >= 0x12 )
        {
          AddRef = v27->__vftable[1].AddRef;
          v27[2].__vftable = (Scaleform::RefCountVImpl_vtbl *)this->MsgVersion.Value;
          data = 0;
          dataSize = 0;
          v55 = 0;
          if ( ((unsigned __int8 (__thiscall *)(Scaleform::RefCountVImpl *, unsigned __int8 **))AddRef)(v27, &data) )
          {
            v33 = this->MsgTypeRegistry.pObject;
            Scaleform::String::String(&messageTypeName, (const __m128i *)"Compressed");
            v34 = Scaleform::GFx::AMP::MessageTypeRegistry::CreateMessage(v33, &messageTypeName);
            v35 = (void *)(messageTypeName.HeapTypeBits & 0xFFFFFFFC);
            v36 = (Scaleform::GFx::AMP::MessageCompressed *)v34;
            if ( InterlockedExchangeAdd((volatile LONG *)((messageTypeName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v35);
            v36->Version = this->MsgVersion.Value;
            Scaleform::GFx::AMP::MessageCompressed::AddCompressedData(v36, data, dataSize);
            Scaleform::RefCountImpl::Release(v27);
            v31 = v36;
          }
          if ( data )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, data);
        }
        EnterCriticalSection(&this->MsgCompressedQueue.QueueLock.cs);
        v31->pPrev = this->MsgCompressedQueue.Queue.Root.pPrev;
        v31->pNext = (Scaleform::GFx::AMP::Message *)&this->MsgCompressedQueue.QueueLock.cs.LockSemaphore;
        this->MsgCompressedQueue.Queue.Root.pPrev->pNext = v31;
        this->MsgCompressedQueue.Queue.Root.pPrev = v31;
        InterlockedExchangeAdd((volatile LONG *)&this->MsgCompressedQueue.QueueSize, 1);
        v37 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v31);
        Scaleform::GFx::AMP::ThreadMgr::MsgQueue::CheckSize(&this->MsgCompressedQueue, v37);
        LeaveCriticalSection(&this->MsgCompressedQueue.QueueLock.cs);
        v44 = 1;
      }
      Instance = Scaleform::AmpServer::GetInstance();
      if ( !Instance->IsProfiling(Instance) )
      {
        v49 = 580;
        v39 = (Scaleform::GFx::AMP::MessageProfileFrame *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                            Scaleform::Memory::pGlobalHeap,
                                                            this,
                                                            28,
                                                            &v49);
        if ( v39 )
        {
          Scaleform::GFx::AMP::MessageProfileFrame::MessageProfileFrame(v39, 0);
          v41 = v40;
        }
        else
        {
          v41 = 0;
        }
        Scaleform::GFx::AMP::ThreadMgr::MsgQueue::ClearMsgType(&this->MsgCompressedQueue, v41);
        if ( v41 )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v41);
      }
      if ( !v44 )
        Scaleform::Thread::MSleep(0x64u);
      EnterCriticalSection(&this->StatusLock.cs);
      v42 = this->Exiting;
      LeaveCriticalSection(&this->StatusLock.cs);
    }
    while ( !v42 );
  }
  return 1;
}
