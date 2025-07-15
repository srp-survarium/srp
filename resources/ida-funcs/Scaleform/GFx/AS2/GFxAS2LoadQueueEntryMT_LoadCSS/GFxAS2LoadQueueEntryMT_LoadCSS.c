void __thiscall Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadCSS::GFxAS2LoadQueueEntryMT_LoadCSS(
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadCSS *this,
        Scaleform::GFx::LoadQueueEntry *pqueueEntry,
        Scaleform::String pmovieRoot)
{
  Scaleform::GFx::LoadStates *v4; // edi
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  Scaleform::GFx::Resource *pObject; // ebp
  Scaleform::GFx::StateBag *v7; // eax
  Scaleform::GFx::LoadStates *v8; // eax
  Scaleform::GFx::LoadStates *v9; // edi
  Scaleform::RefCountVImpl *v10; // ecx
  Scaleform::GFx::AS2::GFxAS2LoadCSSTask *v11; // ebp
  Scaleform::GFx::Resource *EntryTime; // ecx
  Scaleform::GFx::AS2::GFxAS2LoadCSSTask *v13; // eax
  Scaleform::GFx::AS2::GFxAS2LoadCSSTask *v14; // edi
  Scaleform::RefCountVImpl *v15; // ecx
  Scaleform::RefCountVImpl *v16; // edi
  void *v17; // edi
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::CSSHolderType v18; // [esp-14h] [ebp-24h] BYREF

  Scaleform::GFx::LoadQueueEntryMT::LoadQueueEntryMT(
    this,
    pqueueEntry,
    *(Scaleform::GFx::MovieImpl **)pmovieRoot.pData->Data);
  this->__vftable = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadCSS_vtbl *)&Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadCSS::`vftable';
  this->pTask.pObject = 0;
  this->pLoadStates.pObject = 0;
  v4 = (Scaleform::GFx::LoadStates *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 80, 0);
  if ( v4 )
  {
    pMovieImpl = this->pMovieImpl;
    pObject = (Scaleform::GFx::Resource *)pMovieImpl->pMainMovieDef.pObject->pLoaderImpl.pObject;
    v7 = (Scaleform::GFx::StateBag *)pMovieImpl->GetStateBagImpl(&pMovieImpl->Scaleform::GFx::StateBag);
    Scaleform::GFx::LoadStates::LoadStates(v4, pObject, v7, 0);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  v10 = (Scaleform::RefCountVImpl *)this->pLoadStates.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  this->pLoadStates.pObject = v9;
  Scaleform::String::String(&pmovieRoot);
  Scaleform::GFx::AS2::MovieRoot::GetLevel0Path(
    (Scaleform::GFx::AS2::MovieRoot *)this->pMovieImpl->pASMovieRoot.pObject,
    &pmovieRoot);
  v11 = (Scaleform::GFx::AS2::GFxAS2LoadCSSTask *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    36,
                                                    0);
  if ( v11 )
  {
    Scaleform::GFx::AS2::Value::Value(&v18.ASObj, (const Scaleform::GFx::AS2::Value *)&pqueueEntry[3].pNext);
    EntryTime = (Scaleform::GFx::Resource *)pqueueEntry[3].EntryTime;
    if ( EntryTime )
      Scaleform::RefCountImpl::AddRef(EntryTime);
    v18.Loader.pObject = (Scaleform::GFx::AS2::ASCSSFileLoader *)pqueueEntry[3].EntryTime;
    Scaleform::GFx::AS2::GFxAS2LoadCSSTask::GFxAS2LoadCSSTask(
      v11,
      (Scaleform::GFx::Resource *)this->pLoadStates.pObject,
      &pmovieRoot,
      &pqueueEntry->URL,
      v18);
    v14 = v13;
  }
  else
  {
    v14 = 0;
  }
  v15 = (Scaleform::RefCountVImpl *)this->pTask.pObject;
  if ( v15 )
    Scaleform::RefCountImpl::Release(v15);
  this->pTask.pObject = v14;
  v16 = (Scaleform::RefCountVImpl *)this->pMovieImpl->GetStateAddRef(&this->pMovieImpl->Scaleform::GFx::StateBag, 21);
  ((void (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::GFx::AS2::GFxAS2LoadCSSTask *))v16->AddRef)(
    v16,
    this->pTask.pObject);
  Scaleform::RefCountImpl::Release(v16);
  v17 = (void *)(pmovieRoot.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((pmovieRoot.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v17);
}
