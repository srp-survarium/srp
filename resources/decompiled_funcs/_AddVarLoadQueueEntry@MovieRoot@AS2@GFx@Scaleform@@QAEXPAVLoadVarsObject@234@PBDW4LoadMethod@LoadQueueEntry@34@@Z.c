void __thiscall Scaleform::GFx::AS2::MovieRoot::AddVarLoadQueueEntry(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::AS2::LoadVarsObject *ploadVars,
        char *purl,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  char v5; // bl
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v6; // esi
  int v7; // eax
  int v8; // esi
  void *v9; // ebx
  Scaleform::RefCountVImpl *v10; // eax
  Scaleform::String url; // [esp+Ch] [ebp-4h] BYREF

  v5 = 0;
  url.pData = 0;
  v6 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 108, 0);
  if ( v6 )
  {
    Scaleform::String::String(&url, purl);
    v5 = 1;
    Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(v6, &url, method, 1, 0);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  if ( (v5 & 1) != 0 )
  {
    v9 = (void *)(url.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((url.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
  }
  if ( v8 )
  {
    Scaleform::GFx::AS2::Value::SetAsObject((Scaleform::GFx::AS2::Value *)(v8 + 52), ploadVars);
    v10 = (Scaleform::RefCountVImpl *)this->pMovieImpl->GetStateAddRef(&this->pMovieImpl->Scaleform::GFx::StateBag, 21);
    if ( v10 )
    {
      Scaleform::RefCountImpl::Release(v10);
      Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntryMT(this, (Scaleform::GFx::LoadQueueEntry *)v8);
    }
    else
    {
      Scaleform::GFx::MovieImpl::AddLoadQueueEntry(this->pMovieImpl, (Scaleform::GFx::LoadQueueEntry *)v8);
    }
  }
}
