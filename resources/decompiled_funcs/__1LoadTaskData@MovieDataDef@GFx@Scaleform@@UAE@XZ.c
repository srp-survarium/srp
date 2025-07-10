void __thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::~LoadTaskData(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *v2; // ebp
  bool v3; // cc
  unsigned int i; // edi
  unsigned int j; // edi
  Scaleform::GFx::PathAllocator *pPathAllocator; // edi
  Scaleform::GFx::SoundStreamDef *pSoundStream; // ecx
  Scaleform::ArrayLH<Scaleform::GFx::MovieDataDef::SceneInfo,2,Scaleform::ArrayDefaultPolicy> *pObject; // edi
  Scaleform::GFx::MovieDef *v9; // ecx
  Scaleform::RefCountVImpl *v10; // ecx
  volatile LONG *v11; // edi
  volatile LONG *v12; // edi
  volatile LONG *v13; // edi
  Scaleform::MemoryHeap *v14; // ecx
  Scaleform::GFx::DataAllocator::Block *pNext; // edi

  v2 = 0;
  v3 = this->LoadState < LS_LoadFinished;
  this->__vftable = (Scaleform::GFx::MovieDataDef::LoadTaskData_vtbl *)&Scaleform::GFx::MovieDataDef::LoadTaskData::`vftable';
  if ( v3 )
  {
    v2 = this;
    EnterCriticalSection(&this->ResourceLock.cs);
  }
  for ( i = 0; i < this->Playlist.Data.Size; ++i )
    Scaleform::GFx::TimelineDef::Frame::DestroyTags(&this->Playlist.Data.Data[i]);
  for ( j = 0; j < this->InitActionList.Data.Size; ++j )
    Scaleform::GFx::TimelineDef::Frame::DestroyTags(&this->InitActionList.Data.Data[j]);
  pPathAllocator = this->pPathAllocator;
  if ( pPathAllocator )
  {
    Scaleform::GFx::PathAllocator::~PathAllocator(this->pPathAllocator);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pPathAllocator);
  }
  if ( this->pMetadata )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pMetadata);
    this->pMetadata = 0;
  }
  pSoundStream = this->pSoundStream;
  if ( pSoundStream )
    Scaleform::RefCountNTSImpl::Release(pSoundStream);
  if ( v2 )
    LeaveCriticalSection(&v2->ResourceLock.cs);
  pObject = this->Scenes.pObject;
  if ( pObject )
  {
    if ( this->Scenes.Owner )
    {
      this->Scenes.Owner = 0;
      Scaleform::ConstructorMov<Scaleform::GFx::MovieDataDef::SceneInfo>::DestructArray(
        pObject->Data.Data,
        pObject->Data.Size);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject->Data.Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
    this->Scenes.pObject = 0;
  }
  this->Scenes.Owner = 0;
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&this->NamedFrames);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this->InitActionList.Data.Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this->Playlist.Data.Data);
  Scaleform::Lock::~Lock(&this->PlaylistLock);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF>>(&this->InvExports.mHash);
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>(&this->Exports.mHash);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF>>::Clear(&this->Resources.mHash);
  v9 = this->pExtMovieDef.pObject;
  if ( v9 )
    Scaleform::GFx::Resource::Release(v9);
  Scaleform::Lock::~Lock(&this->ResourceLock);
  Scaleform::GFx::MovieDataDef::DefBindingData::~DefBindingData(&this->BindData);
  v10 = (Scaleform::RefCountVImpl *)this->pFrameUpdate.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  if ( this->Header.mExporterInfo.CodeOffsets.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(
      Scaleform::Memory::pGlobalHeap,
      this->Header.mExporterInfo.CodeOffsets.Data.Data);
  v11 = (volatile LONG *)(this->Header.mExporterInfo.SWFName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v11 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v11);
  v12 = (volatile LONG *)(this->Header.mExporterInfo.Prefix.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v12 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v12);
  v13 = (volatile LONG *)(this->FileURL.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v13 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v13);
  v14 = this->pImageHeap.pObject;
  if ( v14 )
    v14->Release(v14);
  if ( this->TagMemAllocator.pAllocations )
  {
    do
    {
      pNext = this->TagMemAllocator.pAllocations->pNext;
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->TagMemAllocator.pAllocations);
      this->TagMemAllocator.pAllocations = pNext;
    }
    while ( pNext );
  }
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
