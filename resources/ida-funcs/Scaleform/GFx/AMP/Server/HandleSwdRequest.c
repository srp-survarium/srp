char __thiscall Scaleform::GFx::AMP::Server::HandleSwdRequest(Scaleform::GFx::AMP::Server *this, Scaleform::String msg)
{
  Scaleform::Lock *p_LoaderLock; // ebp
  int v4; // ebx
  Scaleform::GFx::Loader *v5; // ecx
  Scaleform::GFx::Resource *v6; // eax
  Scaleform::RefCountVImpl *v7; // esi
  Scaleform::String::DataDesc *pData; // ebp
  unsigned int Flags; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::TableType *pTable; // esi
  int v11; // eax
  int v12; // edx
  int v13; // ebx
  int v14; // eax
  Scaleform::String::DataDesc *v15; // eax
  LONG (__stdcall *v16)(volatile LONG *, LONG); // ebx
  unsigned int Length; // eax
  unsigned int v18; // esi
  const Scaleform::String *v19; // eax
  void *v20; // esi
  void *v21; // esi
  void (__thiscall *AddRef)(Scaleform::RefCountVImpl *); // eax
  int v23; // eax
  Scaleform::RefCountVImpl *v24; // esi
  unsigned int v25; // eax
  unsigned __int8 *Data; // ebx
  int v27; // ebp
  Scaleform::GFx::AMP::MessageSwdFile *v28; // eax
  Scaleform::RefCountVImpl *v29; // eax
  Scaleform::GFx::AMP::MessageSwdFile *v30; // eax
  Scaleform::RefCountVImpl *v31; // eax
  void *v32; // esi
  void *v33; // esi
  Scaleform::String v35; // [esp+38h] [ebp-24h] BYREF
  unsigned int key; // [esp+3Ch] [ebp-20h] BYREF
  Scaleform::RefCountVImpl *v37; // [esp+40h] [ebp-1Ch]
  Scaleform::String src; // [esp+44h] [ebp-18h] BYREF
  Scaleform::String v39; // [esp+48h] [ebp-14h] BYREF
  LPCRITICAL_SECTION lpCriticalSection; // [esp+4Ch] [ebp-10h]
  Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> bufferData; // [esp+50h] [ebp-Ch] BYREF

  p_LoaderLock = &this->LoaderLock;
  v4 = 0;
  v37 = 0;
  EnterCriticalSection(&this->LoaderLock.cs);
  if ( this->Loaders.Data.Size )
  {
    while ( 1 )
    {
      v5 = this->Loaders.Data.Data[v4];
      v6 = (Scaleform::GFx::Resource *)v5->GetStateAddRef(v5, State_FileOpener);
      v7 = (Scaleform::RefCountVImpl *)v6;
      if ( v6 )
        Scaleform::RefCountImpl::AddRef(v6);
      v37 = v7;
      if ( v7 )
        break;
      if ( ++v4 >= this->Loaders.Data.Size )
        goto LABEL_8;
    }
    Scaleform::RefCountImpl::Release(v7);
  }
LABEL_8:
  LeaveCriticalSection(&p_LoaderLock->cs);
  if ( v37 )
  {
    lpCriticalSection = &this->SwfLock.cs;
    EnterCriticalSection(&this->SwfLock.cs);
    pData = msg.pData;
    Flags = Scaleform::GFx::AMP::MessageAppControl::GetFlags((Scaleform::Render::RawImage *)msg.pData);
    pTable = this->HandleToSwdIdMap.mHash.pTable;
    key = Flags;
    if ( pTable )
    {
      v11 = 5381;
      v12 = 4;
      do
      {
        v13 = *((unsigned __int8 *)&v35.HeapTypeBits + v12-- + 3);
        v11 = v13 + 65599 * v11;
      }
      while ( v12 );
      v14 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF>>::findIndexCore<Scaleform::GFx::ResourceId>(
              (Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *)&this->HandleToSwdIdMap,
              &key,
              pTable->SizeMask & v11);
      if ( v14 >= 0 && v14 <= (signed int)pTable->SizeMask )
      {
        this->GetSwdFilename(&this->Scaleform::AmpServer, &src, key);
        v15 = src.pData;
        v16 = InterlockedExchangeAdd;
        if ( (*(_DWORD *)(src.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF) != 0 )
        {
          if ( Scaleform::GFx::AMP::MessageObjectsReportRequest::IsShortFilenames((Scaleform::GFx::AMP::MessageObjectsReportRequest *)pData) )
          {
            Scaleform::String::String(&v35, &src);
            Length = Scaleform::String::GetLength(&v35);
            if ( Length > 4 )
            {
              v18 = Length - 4;
              Scaleform::String::Substring(&v35, &msg, Length - 4, Length);
              if ( Scaleform::String::operator==(&msg, ".swf") || Scaleform::String::operator==(&msg, ".gfx") )
              {
                v19 = Scaleform::String::Substring(&v35, &v39, 0, v18);
                Scaleform::String::operator=(&v35, v19);
                v20 = (void *)(v39.HeapTypeBits & 0xFFFFFFFC);
                if ( InterlockedExchangeAdd((volatile LONG *)((v39.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
                  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v20);
              }
              v21 = (void *)(msg.HeapTypeBits & 0xFFFFFFFC);
              if ( InterlockedExchangeAdd((volatile LONG *)((msg.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
                Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v21);
            }
            Scaleform::String::AppendString(&v35, (const __m128i *)".swd", 0xFFFFFFFF);
            AddRef = v37->AddRef;
            LOBYTE(msg.pData) = 0;
            v23 = ((int (__thiscall *)(Scaleform::RefCountVImpl *, unsigned int, int, int))AddRef)(
                    v37,
                    (v35.HeapTypeBits & 0xFFFFFFFC) + 8,
                    33,
                    438);
            v24 = (Scaleform::RefCountVImpl *)v23;
            if ( !v23 || (*(int (__thiscall **)(int))(*(_DWORD *)v23 + 24))(v23) <= 0 )
              goto LABEL_33;
            v25 = ((int (__thiscall *)(Scaleform::RefCountVImpl *))v24->__vftable[2].~Scaleform::RefCountVImpl)(v24);
            Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>(
              &bufferData,
              v25);
            Data = bufferData.Data;
            v27 = ((int (__thiscall *)(Scaleform::RefCountVImpl *, unsigned __int8 *, unsigned int))v24->__vftable[3].AddRef)(
                    v24,
                    bufferData.Data,
                    bufferData.Size);
            if ( v27 == ((int (__thiscall *)(Scaleform::RefCountVImpl *))v24->__vftable[2].~Scaleform::RefCountVImpl)(v24) )
            {
              v28 = (Scaleform::GFx::AMP::MessageSwdFile *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,580>::operator new(
                                                             0x2Cu,
                                                             (Scaleform::MemAddressStub *)this);
              if ( v28 )
                Scaleform::GFx::AMP::MessageSwdFile::MessageSwdFile(
                  v28,
                  key,
                  Data,
                  bufferData.Size,
                  (char *)((v35.HeapTypeBits & 0xFFFFFFFC) + 8));
              else
                v29 = 0;
              Scaleform::GFx::AMP::ThreadMgr::SendAmpMessage(this->SocketThreadMgr.pObject, v29);
              LOBYTE(msg.pData) = 1;
            }
            v24->__vftable[6].AddRef(v24);
            if ( Data )
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
            v16 = InterlockedExchangeAdd;
            if ( !LOBYTE(msg.pData) )
            {
LABEL_33:
              msg.pData = (Scaleform::String::DataDesc *)580;
              v30 = (Scaleform::GFx::AMP::MessageSwdFile *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             this,
                                                             44,
                                                             &msg);
              if ( v30 )
                Scaleform::GFx::AMP::MessageSwdFile::MessageSwdFile(
                  v30,
                  key,
                  0,
                  0,
                  (char *)((v35.HeapTypeBits & 0xFFFFFFFC) + 8));
              else
                v31 = 0;
              Scaleform::GFx::AMP::ThreadMgr::SendAmpMessage(this->SocketThreadMgr.pObject, v31);
            }
            if ( v24 )
              Scaleform::RefCountImpl::Release(v24);
            v32 = (void *)(v35.HeapTypeBits & 0xFFFFFFFC);
            if ( v16((volatile LONG *)((v35.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v32);
          }
          v15 = src.pData;
        }
        v33 = (void *)((unsigned int)v15 & 0xFFFFFFFC);
        if ( v16((volatile LONG *)(((unsigned int)v15 & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v33);
      }
    }
    LeaveCriticalSection(lpCriticalSection);
    Scaleform::RefCountImpl::Release(v37);
  }
  return 1;
}
