Scaleform::GFx::MovieDefImpl *__cdecl Scaleform::GFx::LoaderImpl::CreateMovieDefImpl(
        Scaleform::GFx::LoadStates *pls,
        Scaleform::GFx::MovieDataDef *pmd,
        unsigned int loadConstants,
        Scaleform::GFx::MovieBindProcess **ppbindProcess,
        bool checkCreate,
        Scaleform::GFx::LoaderImpl::LoadStackItem *ploadStack,
        unsigned int memoryArena)
{
  Scaleform::GFx::MovieDataDef *v7; // ebp
  Scaleform::GFx::LoadStates *v8; // esi
  Scaleform::GFx::Resource *pObject; // edi
  Scaleform::GFx::MovieDefImpl *v10; // eax
  Scaleform::GFx::MovieDefImpl *v11; // eax
  Scaleform::GFx::MovieDefImpl *v12; // edi
  Scaleform::GFx::MovieBindProcess **v13; // ebx
  Scaleform::GFx::MovieBindProcess *v14; // eax
  Scaleform::GFx::MovieBindProcess *v15; // eax
  void *v16; // esi
  Scaleform::GFx::ResourceKey::KeyInterface *pKeyInterface; // ecx
  const char *Error; // eax
  Scaleform::GFx::ResourceLib::BindHandle v20; // [esp+18h] [ebp-10h] BYREF
  Scaleform::GFx::ResourceKey result; // [esp+20h] [ebp-8h] BYREF

  v7 = pmd;
  v8 = pls;
  pObject = (Scaleform::GFx::Resource *)pls->pBindStates.pObject;
  v20.State = RS_Unbound;
  v20.pResource = 0;
  Scaleform::GFx::MovieDefImpl::CreateMovieKey(&result, pmd, pObject);
  if ( Scaleform::GFx::ResourceWeakLib::BindResourceKey(v8->pWeakResourceLib.pObject, &v20, &result) == RS_NeedsResolve )
  {
    v10 = (Scaleform::GFx::MovieDefImpl *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 32, 0);
    if ( v10 )
    {
      Scaleform::GFx::MovieDefImpl::MovieDefImpl(
        v10,
        v7,
        pObject,
        (Scaleform::GFx::Resource *)v8->pLoaderImpl.pObject,
        loadConstants,
        (Scaleform::GFx::Resource *)v8->pLoaderImpl.pObject->pStateBag.pObject,
        Scaleform::Memory::pGlobalHeap,
        0,
        memoryArena);
      v12 = v11;
    }
    else
    {
      v12 = 0;
    }
    v13 = ppbindProcess;
    if ( ppbindProcess )
    {
      v14 = (Scaleform::GFx::MovieBindProcess *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  52,
                                                  0);
      if ( v14 )
        Scaleform::GFx::MovieBindProcess::MovieBindProcess(v14, (Scaleform::GFx::Resource *)v8, v12, ploadStack);
      else
        v15 = 0;
      *v13 = v15;
      if ( !v15 )
      {
        if ( v12 )
          Scaleform::GFx::Resource::Release(v12);
LABEL_12:
        Scaleform::String::String(
          (Scaleform::String *)&pls,
          (const __m128i *)"Failed to bind SWF file \"",
          (const __m128i *)((v7->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFC) + 8),
          (const __m128i *)"\"\n");
        Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
          v20.pSlot,
          (const __m128i *)(((unsigned int)pls & 0xFFFFFFFC) + 8));
        v16 = (void *)((unsigned int)pls & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)pls & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16);
        pKeyInterface = result.pKeyInterface;
        if ( !result.pKeyInterface )
          goto LABEL_16;
        goto LABEL_15;
      }
    }
    if ( !v12 )
      goto LABEL_12;
    Scaleform::GFx::ResourceLib::ResourceSlot::Resolve(v20.pSlot, v12);
  }
  else
  {
    v12 = (Scaleform::GFx::MovieDefImpl *)Scaleform::GFx::ResourceLib::BindHandle::WaitForResolve(&v20);
    if ( !v12 )
    {
      if ( v8->pLog.pObject )
      {
        if ( v20.State < RS_WaitingResolve )
          Error = uri;
        else
          Error = Scaleform::GFx::ResourceLib::ResourceSlot::GetError(v20.pSlot);
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
          &v8->pLog.pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
          (const char *)&stru_7F9BE8.allocator,
          Error);
      }
      pKeyInterface = result.pKeyInterface;
      if ( !result.pKeyInterface )
        goto LABEL_16;
LABEL_15:
      result.pKeyInterface->Release(pKeyInterface, result.hKeyData);
LABEL_16:
      if ( v20.State == RS_Available )
      {
        Scaleform::GFx::Resource::Release(v20.pResource);
        return 0;
      }
      else
      {
        if ( v20.State >= RS_WaitingResolve )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v20.pResource);
        return 0;
      }
    }
  }
  if ( result.pKeyInterface )
    result.pKeyInterface->Release(result.pKeyInterface, result.hKeyData);
  if ( v20.State == RS_Available )
  {
    Scaleform::GFx::Resource::Release(v20.pResource);
    return v12;
  }
  else
  {
    if ( v20.State >= RS_WaitingResolve )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v20.pResource);
    return v12;
  }
}
