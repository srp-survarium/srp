void __thiscall Scaleform::GFx::MovieDefImpl::MovieDefImpl(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::GFx::MovieDataDef *pdataDef,
        Scaleform::GFx::Resource *pstates,
        Scaleform::GFx::Resource *ploaderImpl,
        unsigned int loadConstantFlags,
        Scaleform::GFx::Resource *pdelegateState,
        Scaleform::MemoryHeap *pargHeap,
        bool fullyLoaded,
        unsigned int memoryArena)
{
  Scaleform::MemoryHeap *v9; // ebx
  const __m128i *ShortFilename; // eax
  Scaleform::MemoryHeap *v12; // eax
  void *v13; // edi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v14; // eax
  Scaleform::GFx::MovieDefImpl::BindTaskData *v15; // eax
  Scaleform::GFx::MovieDefImpl::BindTaskData *v16; // ebp
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v18; // ecx
  Scaleform::RefCountVImpl *v19; // ecx
  Scaleform::GFx::StateBagImpl *v20; // eax
  Scaleform::GFx::StateBagImpl *v21; // eax
  Scaleform::GFx::StateBagImpl *v22; // ebx
  Scaleform::RefCountVImpl *v23; // ecx
  Scaleform::String v24; // [esp+10h] [ebp-24h] BYREF
  _DWORD v25[8]; // [esp+14h] [ebp-20h] BYREF

  v9 = pargHeap;
  this->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::__vftable = (Scaleform::GFx::MovieDefImpl_vtbl *)&Scaleform::GFx::Resource::`vftable';
  this->RefCount.Value = 1;
  this->pLib = 0;
  this->Scaleform::GFx::MovieDef::Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::StateBag::`vftable';
  this->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::__vftable = (Scaleform::GFx::MovieDefImpl_vtbl *)&Scaleform::GFx::MovieDefImpl::`vftable'{for `Scaleform::GFx::Resource'};
  this->Scaleform::GFx::MovieDef::Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::MovieDefImpl::`vftable'{for `Scaleform::GFx::StateBag'};
  this->pStateBag.pObject = 0;
  this->pLoaderImpl.pObject = 0;
  this->pBindStates.pObject = 0;
  this->pBindData.pObject = 0;
  if ( !pargHeap )
  {
    ShortFilename = (const __m128i *)Scaleform::GetShortFilename((const char *)((pdataDef->pData.pObject->FileURL.HeapTypeBits
                                                                               & 0xFFFFFFFC)
                                                                              + 8));
    Scaleform::String::String(&v24, (const __m128i *)"MovieDef  \"", ShortFilename, (const __m128i *)"\"");
    v25[2] = 4096;
    v25[3] = 4096;
    v25[7] = memoryArena;
    v25[5] = 0;
    v25[0] = HIWORD(loadConstantFlags) & 0x1000;
    v25[1] = 16;
    v25[4] = -1;
    v25[6] = 2;
    v12 = Scaleform::Memory::pGlobalHeap->CreateHeap(
            Scaleform::Memory::pGlobalHeap,
            (v24.HeapTypeBits & 0xFFFFFFFC) + 8,
            v25);
    v13 = (void *)(v24.HeapTypeBits & 0xFFFFFFFC);
    v9 = v12;
    if ( InterlockedExchangeAdd((volatile LONG *)((v24.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
  }
  v14 = (Scaleform::GFx::MovieDefImpl::BindTaskData *)v9->Alloc(v9, 140u, 0);
  if ( v14 )
  {
    Scaleform::GFx::MovieDefImpl::BindTaskData::BindTaskData(v14, v9, pdataDef, this, loadConstantFlags, fullyLoaded);
    v16 = v15;
  }
  else
  {
    v16 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->pBindData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pBindData.pObject = v16;
  if ( !pargHeap )
    Scaleform::MemoryHeap::ReleaseOnFree(v9, v16);
  if ( ploaderImpl )
    Scaleform::RefCountImpl::AddRef(ploaderImpl);
  v18 = (Scaleform::RefCountVImpl *)this->pLoaderImpl.pObject;
  if ( v18 )
    Scaleform::RefCountImpl::Release(v18);
  this->pLoaderImpl.pObject = (Scaleform::GFx::LoaderImpl *)ploaderImpl;
  if ( pstates )
    Scaleform::RefCountImpl::AddRef(pstates);
  v19 = (Scaleform::RefCountVImpl *)this->pBindStates.pObject;
  if ( v19 )
    Scaleform::RefCountImpl::Release(v19);
  this->pBindStates.pObject = (Scaleform::GFx::MovieDefBindStates *)pstates;
  v20 = (Scaleform::GFx::StateBagImpl *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 48, 0);
  if ( v20 )
  {
    Scaleform::GFx::StateBagImpl::StateBagImpl(v20, pdelegateState);
    v22 = v21;
  }
  else
  {
    v22 = 0;
  }
  v23 = (Scaleform::RefCountVImpl *)this->pStateBag.pObject;
  if ( v23 )
    Scaleform::RefCountImpl::Release(v23);
  this->pStateBag.pObject = v22;
}
