Scaleform::GFx::MovieDefImpl *__cdecl Scaleform::GFx::LoaderImpl::CreateMovieDefImpl(
        Scaleform::String pls,
        Scaleform::GFx::MovieDataDef *pmd,
        unsigned int loadConstants,
        Scaleform::GFx::MovieBindProcess **ppbindProcess,
        bool checkCreate,
        Scaleform::GFx::LoaderImpl::LoadStackItem *ploadStack,
        unsigned int memoryArena)
{
  Scaleform::GFx::MovieDataDef *v7; // ebp
  Scaleform::GFx::LoadStates *pData; // esi
  Scaleform::GFx::MovieDefBindStates *v9; // edi
  Scaleform::GFx::MovieDefImpl *v10; // eax
  Scaleform::GFx::MovieDefImpl *v11; // eax
  Scaleform::GFx::MovieDefImpl *v12; // edi
  Scaleform::GFx::MovieBindProcess **v13; // ebx
  Scaleform::GFx::MovieBindProcess *v14; // eax
  Scaleform::GFx::MovieBindProcess *v15; // eax
  void *v16; // esi
  Scaleform::GFx::ResourceKey::KeyInterface *pKeyInterface; // ecx
  const char *Error; // eax
  Scaleform::GFx::ResourceLib::BindHandle phandle; // [esp+18h] [ebp-10h] BYREF
  Scaleform::GFx::ResourceKey movieImplKey; // [esp+20h] [ebp-8h] BYREF

  v7 = pmd;
  pData = (Scaleform::GFx::LoadStates *)pls.pData;
  v9 = *(Scaleform::GFx::MovieDefBindStates **)pls.pData->Data;
  phandle.State = RS_Unbound;
  phandle.pResource = 0;
  Scaleform::GFx::MovieDefImpl::CreateMovieKey(&movieImplKey, pmd, v9);
  if ( Scaleform::GFx::ResourceWeakLib::BindResourceKey(pData->pWeakResourceLib.pObject, &phandle, &movieImplKey) == 3 )
  {
    v10 = (Scaleform::GFx::MovieDefImpl *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 32, 0);
    if ( v10 )
    {
      Scaleform::GFx::MovieDefImpl::MovieDefImpl(
        v10,
        v7,
        v9,
        pData->pLoaderImpl.pObject,
        loadConstants,
        pData->pLoaderImpl.pObject->pStateBag.pObject,
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
        Scaleform::GFx::MovieBindProcess::MovieBindProcess(v14, pData, v12, ploadStack);
      else
        v15 = 0;
      *v13 = v15;
      if ( !v15 )
      {
        if ( v12 )
          Scaleform::GFx::Resource::Release(v12);
LABEL_12:
        Scaleform::String::String(
          &pls,
          "Failed to bind SWF file \"",
          (char *)((v7->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFC) + 8),
          "\"\n");
        Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
          phandle.pSlot,
          (char *)((pls.HeapTypeBits & 0xFFFFFFFC) + 8));
        v16 = (void *)(pls.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((pls.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16);
        pKeyInterface = movieImplKey.pKeyInterface;
        if ( !movieImplKey.pKeyInterface )
          goto LABEL_16;
        goto LABEL_15;
      }
    }
    if ( !v12 )
      goto LABEL_12;
    Scaleform::GFx::ResourceLib::ResourceSlot::Resolve(phandle.pSlot, v12);
  }
  else
  {
    v12 = (Scaleform::GFx::MovieDefImpl *)Scaleform::GFx::ResourceLib::BindHandle::WaitForResolve(&phandle);
    if ( !v12 )
    {
      if ( pData->pLog.pObject )
      {
        if ( phandle.State < RS_WaitingResolve )
          Error = (const char *)&buf;
        else
          Error = Scaleform::GFx::ResourceLib::ResourceSlot::GetError(phandle.pSlot);
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
          &pData->pLog.pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
          "%s",
          Error);
      }
      pKeyInterface = movieImplKey.pKeyInterface;
      if ( !movieImplKey.pKeyInterface )
        goto LABEL_16;
LABEL_15:
      movieImplKey.pKeyInterface->Release(pKeyInterface, movieImplKey.hKeyData);
LABEL_16:
      if ( phandle.State == RS_Available )
      {
        Scaleform::GFx::Resource::Release(phandle.pResource);
        return 0;
      }
      else
      {
        if ( phandle.State >= RS_WaitingResolve )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)phandle.pResource);
        return 0;
      }
    }
  }
  if ( movieImplKey.pKeyInterface )
    movieImplKey.pKeyInterface->Release(movieImplKey.pKeyInterface, movieImplKey.hKeyData);
  if ( phandle.State == RS_Available )
  {
    Scaleform::GFx::Resource::Release(phandle.pResource);
    return v12;
  }
  else
  {
    if ( phandle.State >= RS_WaitingResolve )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)phandle.pResource);
    return v12;
  }
}
