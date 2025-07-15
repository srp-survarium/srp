Scaleform::GFx::Movie *__thiscall Scaleform::GFx::MovieDefImpl::CreateInstance(
        Scaleform::GFx::MovieDefImpl *this,
        const Scaleform::GFx::MemoryParams *memParams,
        BOOL initFirstFrame,
        Scaleform::GFx::ActionControl *actionControl,
        Scaleform::Render::ThreadCommandQueue *queue)
{
  const char *v6; // eax
  const __m128i *ShortFilename; // eax
  Scaleform::GFx::MemoryContext *v8; // edi
  Scaleform::GFx::Movie *v9; // ebx
  const __m128i *v11; // [esp+14h] [ebp-Ch]
  int v12; // [esp+1Ch] [ebp-4h]
  Scaleform::String retaddr; // [esp+20h] [ebp+0h] BYREF

  v6 = (const char *)((int (__thiscall *)(Scaleform::GFx::MovieDefImpl *, const char *))this->GetFileURL)(this, "\"");
  ShortFilename = (const __m128i *)Scaleform::GetShortFilename(v6);
  Scaleform::String::String(&retaddr, (const __m128i *)"MovieView \"", ShortFilename, v11);
  v8 = (Scaleform::GFx::MemoryContext *)((int (__thiscall *)(Scaleform::GFx::MovieDefImpl *, unsigned int, BOOL))this->CreateMemoryContext)(
                                          this,
                                          (retaddr.HeapTypeBits & 0xFFFFFFFC) + 8,
                                          initFirstFrame);
  if ( v8 )
  {
    v9 = this->CreateInstance(this, v8, initFirstFrame, actionControl, queue);
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v8);
    if ( InterlockedExchangeAdd((volatile LONG *)((v12 & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)(v12 & 0xFFFFFFFC));
    return v9;
  }
  else
  {
    if ( InterlockedExchangeAdd((volatile LONG *)((v12 & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)(v12 & 0xFFFFFFFC));
    return 0;
  }
}


Scaleform::GFx::Movie *__thiscall Scaleform::GFx::MovieDefImpl::CreateInstance(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::GFx::MemoryContext *memContext,
        bool initFirstFrame,
        Scaleform::GFx::ActionControl *actionControl,
        Scaleform::GFx::Movie_vtbl *queue)
{
  Scaleform::GFx::ASSupport *pObject; // esi
  Scaleform::GFx::Movie *v7; // esi
  Scaleform::GFx::AMP::ViewStats *v9; // edi
  Scaleform::GFx::MovieDef *v10; // eax
  Scaleform::Ptr<Scaleform::GFx::ASSupport> result; // [esp+24h] [ebp-4h] BYREF

  pObject = Scaleform::GFx::MovieDefImpl::GetASSupport(this, &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result.pObject);
  if ( !pObject )
    return 0;
  v7 = pObject->CreateMovie(pObject, memContext);
  if ( !v7 )
    return 0;
  if ( actionControl )
    v7->SetState(&v7->Scaleform::GFx::StateBag, State_ActionControl, actionControl);
  if ( !v7->pASMovieRoot.pObject->Init(v7->pASMovieRoot.pObject, this) )
  {
    Scaleform::GFx::Movie::Release(v7, (int)this);
    return 0;
  }
  v9 = (Scaleform::GFx::AMP::ViewStats *)v7[1].Scaleform::GFx::StateBag::__vftable;
  if ( v9 )
  {
    v10 = v7->GetMovieDef(v7);
    Scaleform::GFx::AMP::ViewStats::SetMovieDef(v9, v10);
  }
  v7[1029].Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = queue;
  if ( initFirstFrame )
    ((void (__thiscall *)(Scaleform::GFx::Movie *, _DWORD, _DWORD, int))v7->Advance)(v7, 0.0, 0, 1);
  return v7;
}
