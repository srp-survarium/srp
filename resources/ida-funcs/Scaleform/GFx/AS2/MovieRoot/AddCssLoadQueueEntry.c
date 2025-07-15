void __thiscall Scaleform::GFx::AS2::MovieRoot::AddCssLoadQueueEntry(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::AS2::Object *pobj,
        Scaleform::GFx::Resource *pLoader,
        const __m128i *purl,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  char v6; // bl
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v7; // esi
  int v8; // eax
  int v9; // esi
  void *v10; // ebx
  Scaleform::RefCountVImpl *v11; // ecx
  Scaleform::RefCountVImpl *v12; // eax
  Scaleform::String url; // [esp+Ch] [ebp-4h] BYREF

  v6 = 0;
  url.pData = 0;
  v7 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 108, 0);
  if ( v7 )
  {
    Scaleform::String::String(&url, purl);
    v6 = 1;
    Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(v7, &url, method, 0, 0);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  if ( (v6 & 1) != 0 )
  {
    v10 = (void *)(url.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((url.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
  }
  if ( v9 )
  {
    *(_DWORD *)(v9 + 8) = 16;
    Scaleform::GFx::AS2::Value::SetAsObject((Scaleform::GFx::AS2::Value *)(v9 + 88), pobj);
    if ( pLoader )
      Scaleform::RefCountImpl::AddRef(pLoader);
    v11 = *(Scaleform::RefCountVImpl **)(v9 + 104);
    if ( v11 )
      Scaleform::RefCountImpl::Release(v11);
    *(_DWORD *)(v9 + 104) = pLoader;
    v12 = (Scaleform::RefCountVImpl *)this->pMovieImpl->GetStateAddRef(&this->pMovieImpl->Scaleform::GFx::StateBag, 21);
    if ( v12 )
    {
      Scaleform::RefCountImpl::Release(v12);
      Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntryMT(this, (Scaleform::GFx::LoadQueueEntry *)v9);
    }
    else
    {
      Scaleform::GFx::MovieImpl::AddLoadQueueEntry(this->pMovieImpl, (Scaleform::GFx::LoadQueueEntry *)v9);
    }
  }
}
