void __thiscall Scaleform::GFx::MoviePreloadTask::MoviePreloadTask(
        Scaleform::GFx::MoviePreloadTask *this,
        Scaleform::GFx::MovieImpl *pmovieRoot,
        const Scaleform::String *url,
        bool stripped,
        bool quietOpen)
{
  Scaleform::GFx::LoadStates *v6; // edi
  Scaleform::GFx::StateBag *v7; // eax
  Scaleform::GFx::LoadStates *v8; // eax
  Scaleform::GFx::LoadStates *v9; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  unsigned int v11; // eax
  const Scaleform::String *UrlStrGfx; // eax
  void *v13; // edi
  Scaleform::String result; // [esp+10h] [ebp-4h] BYREF
  Scaleform::String *src; // [esp+1Ch] [ebp+8h]

  this->__vftable = (Scaleform::GFx::MoviePreloadTask_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->__vftable = (Scaleform::GFx::MoviePreloadTask_vtbl *)&Scaleform::GFx::Task::`vftable';
  this->RefCount = 1;
  this->ThisTaskId = Id_MovieDataLoad;
  this->CurrentState = State_Idle;
  this->__vftable = (Scaleform::GFx::MoviePreloadTask_vtbl *)&Scaleform::GFx::MoviePreloadTask::`vftable';
  this->pLoadStates.pObject = 0;
  Scaleform::String::String(&this->Level0Path);
  Scaleform::String::String(&this->Url, url);
  Scaleform::String::String(&this->UrlStrGfx);
  this->pDefImpl.pObject = 0;
  this->Done = 0;
  v6 = (Scaleform::GFx::LoadStates *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 80, 0);
  if ( v6 )
  {
    src = (Scaleform::String *)pmovieRoot->pMainMovieDef.pObject->pLoaderImpl.pObject;
    v7 = (Scaleform::GFx::StateBag *)pmovieRoot->GetStateBagImpl(&pmovieRoot->Scaleform::GFx::StateBag);
    Scaleform::GFx::LoadStates::LoadStates(v6, (Scaleform::GFx::Resource *)src, v7, 0);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->pLoadStates.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pLoadStates.pObject = v9;
  v11 = (unsigned int)&_sbh_sizeHeaderList
      | pmovieRoot->pMainMovieDef.pObject->pBindData.pObject->LoadFlags & 0xFFFFFFFC;
  this->LoadFlags = v11;
  if ( quietOpen )
    this->LoadFlags = (unsigned int)&loc_200000 | v11;
  Scaleform::GFx::MovieImpl::GetMainMoviePath(pmovieRoot, &this->Level0Path);
  if ( stripped )
  {
    UrlStrGfx = Scaleform::GFx::GetUrlStrGfx(&result, &this->Url);
    Scaleform::String::operator=(&this->UrlStrGfx, UrlStrGfx);
    v13 = (void *)(result.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((result.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
  }
}
