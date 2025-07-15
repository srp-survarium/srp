char __thiscall Scaleform::GFx::AMP::Server::HandleSourceRequest(Scaleform::GFx::AMP::Server *this, int msg)
{
  Scaleform::Lock *p_LoaderLock; // ebp
  int v4; // ebx
  Scaleform::GFx::Loader *v5; // ecx
  Scaleform::GFx::Resource *v6; // eax
  Scaleform::RefCountVImpl *v7; // edi
  Scaleform::GFx::AMP::MessageObjectsReportRequest *v8; // ebx
  unsigned __int64 FileHandle; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *pTable; // edi
  int v11; // eax
  int v12; // edx
  int v13; // ebp
  int Index; // eax
  Scaleform::String::DataDesc *pData; // eax
  void (__thiscall *AddRef)(Scaleform::RefCountVImpl *); // eax
  int v17; // eax
  Scaleform::RefCountVImpl *v18; // edi
  unsigned int v19; // eax
  unsigned __int8 *Data; // ebx
  int v21; // ebp
  Scaleform::GFx::AMP::MessageSourceFile *v22; // eax
  Scaleform::RefCountVImpl *v23; // eax
  Scaleform::GFx::AMP::MessageSourceFile *v24; // eax
  Scaleform::RefCountVImpl *v25; // eax
  void *v26; // esi
  Scaleform::String result; // [esp+28h] [ebp-20h] BYREF
  Scaleform::RefCountVImpl *v29; // [esp+2Ch] [ebp-1Ch]
  LPCRITICAL_SECTION lpCriticalSection; // [esp+30h] [ebp-18h]
  unsigned __int64 key; // [esp+34h] [ebp-14h] BYREF
  Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> bufferData; // [esp+3Ch] [ebp-Ch] BYREF

  p_LoaderLock = &this->LoaderLock;
  v4 = 0;
  v29 = 0;
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
      v29 = v7;
      if ( v7 )
        break;
      if ( ++v4 >= this->Loaders.Data.Size )
        goto LABEL_8;
    }
    Scaleform::RefCountImpl::Release(v7);
  }
LABEL_8:
  LeaveCriticalSection(&p_LoaderLock->cs);
  if ( v29 )
  {
    lpCriticalSection = &this->SourceFileLock.cs;
    EnterCriticalSection(&this->SourceFileLock.cs);
    v8 = (Scaleform::GFx::AMP::MessageObjectsReportRequest *)msg;
    FileHandle = Scaleform::GFx::AMP::MessageSourceRequest::GetFileHandle((Scaleform::GFx::AMP::MessageSourceRequest *)msg);
    pTable = this->HandleToSourceFileMap.mHash.pTable;
    key = FileHandle;
    if ( pTable )
    {
      v11 = 5381;
      v12 = 8;
      do
      {
        v13 = *((unsigned __int8 *)&lpCriticalSection + v12-- + 3);
        v11 = v13 + 65599 * v11;
      }
      while ( v12 );
      Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexCore<unsigned __int64>(
                (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&this->HandleToSourceFileMap,
                &key,
                pTable->SizeMask & v11);
      if ( Index >= 0 && Index <= (signed int)pTable->SizeMask )
      {
        Scaleform::GFx::AMP::Server::GetSourceFilename(this, &result, key);
        pData = result.pData;
        if ( (*(_DWORD *)(result.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF) != 0 )
        {
          if ( Scaleform::GFx::AMP::MessageObjectsReportRequest::IsSuppressMovieDefsStats(v8) )
          {
            AddRef = v29->AddRef;
            LOBYTE(msg) = 0;
            v17 = ((int (__thiscall *)(Scaleform::RefCountVImpl *, unsigned int, int, int))AddRef)(
                    v29,
                    (result.HeapTypeBits & 0xFFFFFFFC) + 8,
                    33,
                    438);
            v18 = (Scaleform::RefCountVImpl *)v17;
            if ( !v17 || (*(int (__thiscall **)(int))(*(_DWORD *)v17 + 24))(v17) <= 0 )
              goto LABEL_26;
            v19 = ((int (__thiscall *)(Scaleform::RefCountVImpl *))v18->__vftable[2].~Scaleform::RefCountVImpl)(v18);
            Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>(
              &bufferData,
              v19);
            Data = bufferData.Data;
            v21 = ((int (__thiscall *)(Scaleform::RefCountVImpl *, unsigned __int8 *, unsigned int))v18->__vftable[3].AddRef)(
                    v18,
                    bufferData.Data,
                    bufferData.Size);
            if ( v21 == ((int (__thiscall *)(Scaleform::RefCountVImpl *))v18->__vftable[2].~Scaleform::RefCountVImpl)(v18) )
            {
              v22 = (Scaleform::GFx::AMP::MessageSourceFile *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,580>::operator new(
                                                                0x30u,
                                                                (Scaleform::MemAddressStub *)this);
              if ( v22 )
                Scaleform::GFx::AMP::MessageSourceFile::MessageSourceFile(
                  v22,
                  key,
                  Data,
                  bufferData.Size,
                  (char *)((result.HeapTypeBits & 0xFFFFFFFC) + 8));
              else
                v23 = 0;
              Scaleform::GFx::AMP::ThreadMgr::SendAmpMessage(this->SocketThreadMgr.pObject, v23);
              LOBYTE(msg) = 1;
            }
            v18->__vftable[6].AddRef(v18);
            if ( Data )
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
            if ( !(_BYTE)msg )
            {
LABEL_26:
              msg = 580;
              v24 = (Scaleform::GFx::AMP::MessageSourceFile *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                Scaleform::Memory::pGlobalHeap,
                                                                this,
                                                                48,
                                                                &msg);
              if ( v24 )
                Scaleform::GFx::AMP::MessageSourceFile::MessageSourceFile(
                  v24,
                  key,
                  0,
                  0,
                  (char *)((result.HeapTypeBits & 0xFFFFFFFC) + 8));
              else
                v25 = 0;
              Scaleform::GFx::AMP::ThreadMgr::SendAmpMessage(this->SocketThreadMgr.pObject, v25);
            }
            if ( v18 )
              Scaleform::RefCountImpl::Release(v18);
          }
          pData = result.pData;
        }
        v26 = (void *)((unsigned int)pData & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)pData & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v26);
      }
    }
    LeaveCriticalSection(lpCriticalSection);
    Scaleform::RefCountImpl::Release(v29);
  }
  return 1;
}
