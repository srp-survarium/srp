char __thiscall Scaleform::GFx::AMP::ThreadMgr::BroadcastRecvLoop(Scaleform::GFx::AMP::ThreadMgr *this)
{
  Scaleform::GFx::AMP::ThreadMgr *v1; // ebp
  bool Exiting; // bl
  signed int v4; // esi
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // eax
  Scaleform::GFx::AMP::AmpStream *v6; // eax
  Scaleform::GFx::AMP::AmpStream *v7; // eax
  Scaleform::GFx::AMP::AmpStream *v8; // ebp
  Scaleform::GFx::AMP::ThreadMgr *v9; // ebx
  Scaleform::RefCountVImpl *Message; // esi
  void (__thiscall *Release)(Scaleform::RefCountVImpl *); // edx
  Scaleform::GFx::AMP::AmpStream *v12; // eax
  Scaleform::RefCountVImpl *v13; // eax
  Scaleform::RefCountVImpl *v14; // edi
  Scaleform::GFx::AMP::Message *v15; // ebx
  Scaleform::GFx::AMP::MessageTypeRegistry *pObject; // edi
  const Scaleform::String *v17; // eax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::Iterator *v18; // eax
  const Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *pHash; // ecx
  int Index; // eax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *pTable; // ecx
  unsigned int SizeMask; // ebx
  void *v23; // edi
  unsigned __int64 Ticks; // kr08_8
  Scaleform::Lock *p_StatusLock; // esi
  bool v26; // bl
  int v27; // eax
  char *v28; // esi
  _BYTE *v29; // eax
  char *v30; // ebx
  int v31; // edi
  Scaleform::GFx::AMP::ThreadMgr *v32; // ebp
  Scaleform::GFx::AMP::MessagePort *v33; // eax
  Scaleform::GFx::AMP::MessagePort *v34; // eax
  Scaleform::GFx::AMP::MessagePort *v35; // esi
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v36; // edi
  const Scaleform::String *v37; // eax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::Iterator *v38; // eax
  const Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v39; // ecx
  int v40; // eax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v41; // ecx
  unsigned int v42; // ebp
  void *v43; // edi
  int v44; // ecx
  int v45; // edx
  bool InitSocketLib; // [esp+16h] [ebp-590h]
  Scaleform::GFx::AMP::SocketImplFactory *SocketFactory; // [esp+1Ah] [ebp-58Ch]
  int v48; // [esp+1Eh] [ebp-588h] BYREF
  char v49; // [esp+35h] [ebp-571h]
  int v50; // [esp+36h] [ebp-570h] BYREF
  Scaleform::GFx::AMP::ThreadMgr *v51; // [esp+3Ah] [ebp-56Ch]
  __int64 v52; // [esp+3Eh] [ebp-568h]
  unsigned __int8 *buffer[2]; // [esp+4Ah] [ebp-55Ch] BYREF
  unsigned int address[2]; // [esp+52h] [ebp-554h] BYREF
  Scaleform::GFx::AMP::Socket v55; // [esp+5Ah] [ebp-54Ch] BYREF
  int v56; // [esp+6Ah] [ebp-53Ch] BYREF
  int v57; // [esp+6Eh] [ebp-538h] BYREF
  Scaleform::GFx::AMP::BroadcastSocket v58; // [esp+72h] [ebp-534h] BYREF
  __int64 v59; // [esp+7Eh] [ebp-528h]
  unsigned __int64 v60; // [esp+86h] [ebp-520h]
  unsigned int port; // [esp+92h] [ebp-514h] BYREF
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::Iterator result; // [esp+96h] [ebp-510h] BYREF
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::Iterator v63; // [esp+9Eh] [ebp-508h] BYREF
  char name[256]; // [esp+A6h] [ebp-500h] BYREF
  char v65[512]; // [esp+1A6h] [ebp-400h] BYREF
  char dataBuffer[512]; // [esp+3A6h] [ebp-200h] BYREF

  v1 = this;
  SocketFactory = this->SocketFactory;
  InitSocketLib = this->InitSocketLib;
  v51 = this;
  Scaleform::GFx::AMP::Socket::Socket(&v55, InitSocketLib, SocketFactory);
  Scaleform::GFx::AMP::BroadcastSocket::BroadcastSocket(&v58, v1->InitSocketLib, v1->SocketFactory);
  if ( !Scaleform::GFx::AMP::BroadcastSocket::Create(&v58, v1->BroadcastRecvPort, 0) )
  {
    Scaleform::GFx::AMP::BroadcastSocket::~BroadcastSocket(&v58);
    Scaleform::GFx::AMP::Socket::~Socket(&v55);
    return 0;
  }
  v52 = 0;
  EnterCriticalSection(&v1->StatusLock.cs);
  Exiting = v1->Exiting;
  LeaveCriticalSection(&v1->StatusLock.cs);
  if ( !Exiting )
  {
    do
    {
      v49 = 0;
      v4 = Scaleform::GFx::AMP::BroadcastSocket::Receive(&v58, dataBuffer, 512);
      if ( v4 > 0 )
      {
        v50 = 2;
        AllocAutoHeap = Scaleform::Memory::pGlobalHeap->AllocAutoHeap;
        v49 = 1;
        v6 = (Scaleform::GFx::AMP::AmpStream *)AllocAutoHeap(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 v1,
                                                 24u,
                                                 (const Scaleform::AllocInfo *)&v50);
        if ( v6 )
        {
          Scaleform::GFx::AMP::AmpStream::AmpStream(v6, (unsigned __int8 *)dataBuffer, v4);
          v8 = v7;
        }
        else
        {
          v8 = 0;
        }
        if ( Scaleform::GFx::AMP::AmpStream::FirstMessageSize(v8) == v4 )
        {
          v9 = v51;
          Message = (Scaleform::RefCountVImpl *)Scaleform::GFx::AMP::ThreadMgr::CreateAndReadMessage(
                                                  v51,
                                                  (Scaleform::String)v8);
          if ( Message )
          {
            Release = Message->__vftable[1].Release;
            buffer[0] = 0;
            buffer[1] = 0;
            address[0] = 0;
            if ( ((unsigned __int8 (__thiscall *)(Scaleform::RefCountVImpl *, unsigned __int8 **))Release)(
                   Message,
                   buffer) )
            {
              v50 = 2;
              v12 = (Scaleform::GFx::AMP::AmpStream *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        v9,
                                                        24,
                                                        &v50);
              if ( v12 )
              {
                Scaleform::GFx::AMP::AmpStream::AmpStream(v12, buffer[0], (unsigned int)buffer[1]);
                v14 = v13;
              }
              else
              {
                v14 = 0;
              }
              v15 = Scaleform::GFx::AMP::ThreadMgr::CreateAndReadMessage(v9, (Scaleform::String)v14);
              Scaleform::RefCountImpl::Release(Message);
              Message = (Scaleform::RefCountVImpl *)v15;
              if ( v14 )
                Scaleform::RefCountImpl::Release(v14);
            }
            if ( buffer[0] )
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, buffer[0]);
            if ( Message )
            {
              pObject = v51->MsgTypeRegistry.pObject;
              v17 = (const Scaleform::String *)((int (__thiscall *)(Scaleform::RefCountVImpl *, int *))Message->__vftable[1].~Scaleform::RefCountVImpl)(
                                                 Message,
                                                 &v57);
              v18 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::FindAlt<Scaleform::String>(
                      (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&pObject->DescriptorMap,
                      &result,
                      v17);
              pHash = v18->pHash;
              Index = v18->Index;
              if ( pHash && (pTable = pHash->pTable) != 0 && Index <= (signed int)pTable->SizeMask )
                SizeMask = pTable[2 * Index + 2].SizeMask;
              else
                SizeMask = 0;
              v23 = (void *)(v57 & 0xFFFFFFFC);
              if ( InterlockedExchangeAdd((volatile LONG *)((v57 & 0xFFFFFFFC) + 4), -1) == 1 )
                Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v23);
              if ( SizeMask && *(_DWORD *)(SizeMask + 8) )
              {
                Scaleform::GFx::AMP::BroadcastSocket::GetName(&v58, &port, &address[1], name, 0x100u);
                ((void (__thiscall *)(Scaleform::RefCountVImpl *, char *))Message->__vftable[2].~Scaleform::RefCountVImpl)(
                  Message,
                  name);
                ((void (__thiscall *)(Scaleform::RefCountVImpl *, unsigned int))Message->__vftable[2].AddRef)(
                  Message,
                  address[1]);
                (*(void (__thiscall **)(_DWORD, Scaleform::RefCountVImpl *))(**(_DWORD **)(SizeMask + 8) + 4))(
                  *(_DWORD *)(SizeMask + 8),
                  Message);
              }
              Scaleform::RefCountImpl::Release(Message);
            }
          }
        }
        if ( v8 )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v8);
      }
      if ( (unsigned __int8)Scaleform::GFx::AMP::Socket::IsValid(&v55) )
      {
        v27 = Scaleform::GFx::AMP::Socket::Receive(&v55, v65, 512);
        if ( v27 > 0 )
        {
          v28 = v65;
          v65[v27] = 0;
          if ( &v48 != (int *)-392 )
          {
            do
            {
              strchr(v28, 0x3Au);
              if ( !v29 )
                break;
              v30 = v29 + 1;
              *v29 = 0;
              v31 = atoi((int)(v29 + 1), v29 + 1);
              if ( v31 > 6000 && !strcmp(v28, "+AMP") )
              {
                v32 = v51;
                v50 = 580;
                v33 = (Scaleform::GFx::AMP::MessagePort *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                            Scaleform::Memory::pGlobalHeap,
                                                            v51,
                                                            48,
                                                            &v50);
                if ( v33 )
                {
                  Scaleform::GFx::AMP::MessagePort::MessagePort(v33, v31, 0, 0);
                  v35 = v34;
                }
                else
                {
                  v35 = 0;
                }
                v35->SetPeerAddress(v35, 2130706433u);
                v35->SetPeerName(v35, "localhost");
                Scaleform::GFx::AMP::MessagePort::SetPlatform(v35, PlatformWiiU);
                v36 = (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)v32->MsgTypeRegistry.pObject;
                v37 = v35->GetMessageName(v35, (Scaleform::String *)&v56);
                v38 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::FindAlt<Scaleform::String>(
                        v36 + 2,
                        &v63,
                        v37);
                v39 = v38->pHash;
                v40 = v38->Index;
                if ( v39 && (v41 = v39->pTable) != 0 && v40 <= (signed int)v41->SizeMask )
                  v42 = v41[2 * v40 + 2].SizeMask;
                else
                  v42 = 0;
                v43 = (void *)(v56 & 0xFFFFFFFC);
                if ( InterlockedExchangeAdd((volatile LONG *)((v56 & 0xFFFFFFFC) + 4), -1) == 1 )
                  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v43);
                if ( v42 )
                {
                  v44 = *(_DWORD *)(v42 + 8);
                  if ( v44 )
                    (*(void (__thiscall **)(int, Scaleform::GFx::AMP::MessagePort *))(*(_DWORD *)v44 + 4))(v44, v35);
                }
                Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v35);
              }
              else if ( !strcmp(v28, "-AMP") )
              {
                goto LABEL_38;
              }
              v28 = v30;
              if ( isdigit(*v30) )
              {
                do
                  v45 = *++v28;
                while ( isdigit(v45) );
              }
            }
            while ( *v28 );
          }
          goto LABEL_38;
        }
      }
      else
      {
        Ticks = Scaleform::Timer::GetTicks();
        v59 = (v52 - Ticks) & 0x7FFFFFFFFFFFFFFFLL;
        v60 = (v52 - Ticks) & 0x8000000000000000uLL;
        if ( (double)(v52 - Ticks) * 0.000001 > 1.0 )
        {
          Scaleform::GFx::AMP::Socket::Destroy(&v55);
          if ( Scaleform::GFx::AMP::Socket::CreateClient(&v55, "127.0.0.1", 0x1773u, 0) )
            Scaleform::GFx::AMP::Socket::SetBlocking(&v55, 0);
          else
            v52 = Ticks;
        }
      }
      if ( !v49 )
        Scaleform::Thread::MSleep(0x64u);
LABEL_38:
      v1 = v51;
      p_StatusLock = &v51->StatusLock;
      EnterCriticalSection(&v51->StatusLock.cs);
      v26 = v1->Exiting;
      LeaveCriticalSection(&p_StatusLock->cs);
    }
    while ( !v26 );
  }
  Scaleform::GFx::AMP::BroadcastSocket::~BroadcastSocket(&v58);
  Scaleform::GFx::AMP::Socket::~Socket(&v55);
  return 1;
}
