void __thiscall Scaleform::GFx::LoadQueueEntryMT_LoadBinary::LoadQueueEntryMT_LoadBinary(
        Scaleform::GFx::LoadQueueEntryMT_LoadBinary *this,
        Scaleform::GFx::LoadQueueEntry *pqueueEntry,
        Scaleform::String pmovieRoot)
{
  Scaleform::GFx::LoadStates *v4; // edi
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  Scaleform::GFx::Resource *pObject; // ebx
  Scaleform::GFx::StateBag *v7; // eax
  Scaleform::GFx::LoadStates *v8; // eax
  Scaleform::GFx::LoadStates *v9; // edi
  Scaleform::RefCountVImpl *v10; // ecx
  Scaleform::GFx::LoadBinaryTask *v11; // eax
  Scaleform::GFx::LoadBinaryTask *v12; // eax
  Scaleform::GFx::LoadBinaryTask *v13; // edi
  Scaleform::RefCountVImpl *v14; // ecx
  Scaleform::RefCountVImpl *v15; // edi
  void *v16; // edi

  this->pMovieImpl = (Scaleform::GFx::MovieImpl *)pmovieRoot.pData;
  this->pNext = 0;
  this->pPrev = 0;
  this->pQueueEntry = pqueueEntry;
  this->__vftable = (Scaleform::GFx::LoadQueueEntryMT_LoadBinary_vtbl *)&Scaleform::GFx::LoadQueueEntryMT_LoadBinary::`vftable';
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
  Scaleform::GFx::MovieImpl::GetMainMoviePath(this->pMovieImpl, &pmovieRoot);
  v11 = (Scaleform::GFx::LoadBinaryTask *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 52, 0);
  if ( v11 )
  {
    Scaleform::GFx::LoadBinaryTask::LoadBinaryTask(
      v11,
      (Scaleform::GFx::Resource *)this->pLoadStates.pObject,
      &pmovieRoot,
      &pqueueEntry->URL);
    v13 = v12;
  }
  else
  {
    v13 = 0;
  }
  v14 = (Scaleform::RefCountVImpl *)this->pTask.pObject;
  if ( v14 )
    Scaleform::RefCountImpl::Release(v14);
  this->pTask.pObject = v13;
  v15 = (Scaleform::RefCountVImpl *)this->pMovieImpl->GetStateAddRef(&this->pMovieImpl->Scaleform::GFx::StateBag, 21);
  ((void (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::GFx::LoadBinaryTask *))v15->AddRef)(
    v15,
    this->pTask.pObject);
  Scaleform::RefCountImpl::Release(v15);
  v16 = (void *)(pmovieRoot.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((pmovieRoot.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16);
}
