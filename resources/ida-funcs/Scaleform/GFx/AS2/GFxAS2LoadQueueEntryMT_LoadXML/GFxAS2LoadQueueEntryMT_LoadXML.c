void __thiscall Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML::GFxAS2LoadQueueEntryMT_LoadXML(
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML *this,
        Scaleform::GFx::LoadQueueEntry *pqueueEntry,
        Scaleform::String pmovieRoot)
{
  Scaleform::String::DataDesc *pData; // edi
  Scaleform::GFx::LoadStates *v5; // edi
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  Scaleform::GFx::Resource *pObject; // ebp
  Scaleform::GFx::StateBag *v8; // eax
  Scaleform::GFx::LoadStates *v9; // eax
  Scaleform::GFx::LoadStates *v10; // edi
  Scaleform::RefCountVImpl *v11; // ecx
  Scaleform::GFx::AS2::GFxAS2LoadXMLTask *v12; // ebp
  Scaleform::GFx::Resource *v13; // ecx
  Scaleform::GFx::AS2::GFxAS2LoadXMLTask *v14; // eax
  Scaleform::GFx::AS2::GFxAS2LoadXMLTask *v15; // edi
  Scaleform::RefCountVImpl *v16; // ecx
  Scaleform::RefCountVImpl *v17; // edi
  void *v18; // edi
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::XMLHolderType v19; // [esp-14h] [ebp-24h] BYREF

  pData = pmovieRoot.pData;
  Scaleform::GFx::LoadQueueEntryMT::LoadQueueEntryMT(
    this,
    pqueueEntry,
    *(Scaleform::GFx::MovieImpl **)pmovieRoot.pData->Data);
  this->__vftable = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML_vtbl *)&Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML::`vftable';
  this->pTask.pObject = 0;
  this->pLoadStates.pObject = 0;
  this->pASMovieRoot = (Scaleform::GFx::AS2::MovieRoot *)pData;
  v5 = (Scaleform::GFx::LoadStates *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 80, 0);
  if ( v5 )
  {
    pMovieImpl = this->pMovieImpl;
    pObject = (Scaleform::GFx::Resource *)pMovieImpl->pMainMovieDef.pObject->pLoaderImpl.pObject;
    v8 = (Scaleform::GFx::StateBag *)pMovieImpl->GetStateBagImpl(&pMovieImpl->Scaleform::GFx::StateBag);
    Scaleform::GFx::LoadStates::LoadStates(v5, pObject, v8, 0);
    v10 = v9;
  }
  else
  {
    v10 = 0;
  }
  v11 = (Scaleform::RefCountVImpl *)this->pLoadStates.pObject;
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  this->pLoadStates.pObject = v10;
  Scaleform::String::String(&pmovieRoot);
  Scaleform::GFx::AS2::MovieRoot::GetLevel0Path(this->pASMovieRoot, &pmovieRoot);
  v12 = (Scaleform::GFx::AS2::GFxAS2LoadXMLTask *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    36,
                                                    0);
  if ( v12 )
  {
    Scaleform::GFx::AS2::Value::Value(&v19.ASObj, (const Scaleform::GFx::AS2::Value *)&pqueueEntry[2].Method);
    v13 = (Scaleform::GFx::Resource *)pqueueEntry[3].__vftable;
    if ( v13 )
      Scaleform::RefCountImpl::AddRef(v13);
    v19.Loader.pObject = (Scaleform::GFx::AS2::XMLFileLoader *)pqueueEntry[3].__vftable;
    Scaleform::GFx::AS2::GFxAS2LoadXMLTask::GFxAS2LoadXMLTask(
      v12,
      (Scaleform::GFx::Resource *)this->pLoadStates.pObject,
      &pmovieRoot,
      &pqueueEntry->URL,
      v19);
    v15 = v14;
  }
  else
  {
    v15 = 0;
  }
  v16 = (Scaleform::RefCountVImpl *)this->pTask.pObject;
  if ( v16 )
    Scaleform::RefCountImpl::Release(v16);
  this->pTask.pObject = v15;
  v17 = (Scaleform::RefCountVImpl *)this->pMovieImpl->GetStateAddRef(&this->pMovieImpl->Scaleform::GFx::StateBag, 21);
  ((void (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::GFx::AS2::GFxAS2LoadXMLTask *))v17->AddRef)(
    v17,
    this->pTask.pObject);
  Scaleform::RefCountImpl::Release(v17);
  v18 = (void *)(pmovieRoot.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((pmovieRoot.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v18);
}
