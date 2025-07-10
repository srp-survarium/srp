Scaleform::GFx::MovieDefImpl *__cdecl Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(
        Scaleform::GFx::LoadStates *pls,
        const Scaleform::GFx::URLBuilder::LocationInfo *loc,
        unsigned int loadConstants,
        Scaleform::GFx::LoaderImpl::LoadStackItem *ploadStack,
        unsigned int memoryArena)
{
  Scaleform::GFx::MovieDefBindStates *pObject; // ecx
  Scaleform::GFx::LogState *v7; // edx
  unsigned int v8; // ebx
  Scaleform::GFx::ImageCreator *LoadTimeImageCreator; // eax
  Scaleform::GFx::FileOpener *v10; // edi
  Scaleform::GFx::ImageCreator *v11; // ebp
  __int64 v12; // rax
  Scaleform::File *v13; // eax
  Scaleform::RefCountVImpl *v14; // edi
  void *v15; // esi
  void *v16; // esi
  LONG v17; // eax
  Scaleform::GFx::MovieDataDef::MovieDataType v19; // ebp
  void *(__thiscall *Alloc)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // edx
  unsigned int v21; // edi
  Scaleform::GFx::MovieDataDef *v22; // eax
  Scaleform::GFx::MovieDataDef *v23; // eax
  Scaleform::GFx::MovieDataDef *v24; // edi
  Scaleform::GFx::LoadProcess *v25; // eax
  Scaleform::GFx::LoadProcess *v26; // eax
  Scaleform::GFx::LoadProcess *v27; // ebp
  Scaleform::GFx::MovieDataDef *v28; // ecx
  Scaleform::Ptr<Scaleform::GFx::MovieBindProcess> *p_pbp; // eax
  Scaleform::RefCountVImpl *v30; // ebp
  Scaleform::GFx::MovieDefImpl *MovieDefImpl; // eax
  void *v32; // esi
  Scaleform::GFx::Resource *v33; // eax
  Scaleform::GFx::LogState *v34; // esi
  const char *Error; // eax
  Scaleform::File *v36; // ebp
  Scaleform::RefCountVImpl *v37; // esi
  Scaleform::GFx::MovieDefImpl *v38; // edi
  Scaleform::GFx::LoadProcess *v39; // edi
  Scaleform::GFx::MovieImageLoadTask *v40; // eax
  Scaleform::RefCountVImpl *v41; // eax
  Scaleform::RefCountVImpl *v42; // edi
  void *v43; // esi
  Scaleform::GFx::LoadStates *v44; // [esp-Ch] [ebp-4Ch]
  Scaleform::String fileName; // [esp+10h] [ebp-30h] BYREF
  Scaleform::Ptr<Scaleform::GFx::MovieBindProcess> pbp; // [esp+14h] [ebp-2Ch] BYREF
  Scaleform::Ptr<Scaleform::File> pin; // [esp+18h] [ebp-28h]
  Scaleform::Ptr<Scaleform::GFx::LoadProcess> plp; // [esp+1Ch] [ebp-24h]
  Scaleform::Ptr<Scaleform::GFx::MovieDataDef> pmd; // [esp+20h] [ebp-20h]
  Scaleform::GFx::MovieDefImpl *pm; // [esp+24h] [ebp-1Ch]
  Scaleform::GFx::LogState *plog; // [esp+28h] [ebp-18h]
  Scaleform::GFx::FileTypeConstants::FileFormatType format; // [esp+2Ch] [ebp-14h]
  Scaleform::GFx::ResourceLib::BindHandle phandle; // [esp+30h] [ebp-10h] BYREF
  Scaleform::GFx::ResourceKey fileDataKey; // [esp+38h] [ebp-8h] BYREF
  char movieNeedsLoading; // [esp+44h] [ebp+4h]

  Scaleform::String::String(&fileName);
  Scaleform::GFx::LoadStates::BuildURL(pls, &fileName, loc);
  pObject = pls->pBindStates.pObject;
  v7 = pls->pLog.pObject;
  v8 = loadConstants;
  phandle.State = RS_Unbound;
  phandle.pResource = 0;
  pm = 0;
  plog = v7;
  movieNeedsLoading = 0;
  pbp.pObject = 0;
  plp.pObject = 0;
  pin.pObject = 0;
  format = File_Unopened;
  if ( pObject->pImagePackParams.pObject )
    v8 = loadConstants | 0x11;
  LOBYTE(loadConstants) = (v8 & 0x10) == 0;
  LoadTimeImageCreator = Scaleform::GFx::LoadStates::GetLoadTimeImageCreator(pls, v8);
  v10 = pls->pBindStates.pObject->pFileOpener.pObject;
  v11 = LoadTimeImageCreator;
  if ( v10 )
    LODWORD(v12) = v10->GetFileModifyTime(v10, (const char *)((fileName.HeapTypeBits & 0xFFFFFFFC) + 8));
  else
    v12 = 0;
  Scaleform::GFx::MovieDataDef::CreateMovieFileKey(
    &fileDataKey,
    (const char *)((fileName.HeapTypeBits & 0xFFFFFFFC) + 8),
    v12,
    v10,
    v11);
  if ( Scaleform::GFx::ResourceWeakLib::BindResourceKey(pls->pWeakResourceLib.pObject, &phandle, &fileDataKey) != 3 )
  {
    v33 = Scaleform::GFx::ResourceLib::BindHandle::WaitForResolve(&phandle);
    pmd.pObject = (Scaleform::GFx::MovieDataDef *)v33;
    if ( !v33 )
    {
      v34 = plog;
      if ( plog )
      {
        if ( phandle.State < RS_WaitingResolve )
          Error = (const char *)&buf;
        else
          Error = Scaleform::GFx::ResourceLib::ResourceSlot::GetError(phandle.pSlot);
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
          &v34->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
          "%s",
          Error);
      }
      if ( fileDataKey.pKeyInterface )
        fileDataKey.pKeyInterface->Release(fileDataKey.pKeyInterface, fileDataKey.hKeyData);
      if ( phandle.State != RS_Available )
      {
        if ( phandle.State >= RS_WaitingResolve )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)phandle.pResource);
        goto LABEL_16;
      }
      goto LABEL_60;
    }
    plog = (Scaleform::GFx::LogState *)v33[2].RefCount.Value;
    Scaleform::GFx::LoadStates::SetRelativePathForDataDef(pls, (Scaleform::GFx::MovieDataDef *)v33);
LABEL_49:
    MovieDefImpl = Scaleform::GFx::LoaderImpl::CreateMovieDefImpl(
                     (Scaleform::String)pls,
                     pmd.pObject,
                     v8,
                     plog == (Scaleform::GFx::LogState *)1 ? (Scaleform::GFx::MovieBindProcess **)&pbp : 0,
                     0,
                     ploadStack,
                     memoryArena);
    v30 = (Scaleform::RefCountVImpl *)pbp.pObject;
    pm = MovieDefImpl;
LABEL_50:
    if ( !pm )
    {
      if ( fileDataKey.pKeyInterface )
        fileDataKey.pKeyInterface->Release(fileDataKey.pKeyInterface, fileDataKey.hKeyData);
      if ( pin.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pin.pObject);
      if ( plp.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)plp.pObject);
      if ( v30 )
        Scaleform::RefCountImpl::Release(v30);
      Scaleform::GFx::Resource::Release(pmd.pObject);
      if ( phandle.State == RS_Available )
        goto LABEL_60;
      if ( phandle.State >= RS_WaitingResolve )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)phandle.pResource);
      goto LABEL_16;
    }
    if ( !movieNeedsLoading )
    {
      v36 = pin.pObject;
      goto LABEL_90;
    }
LABEL_101:
    if ( plog != (Scaleform::GFx::LogState *)1 )
    {
      v40 = (Scaleform::GFx::MovieImageLoadTask *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    40,
                                                    0);
      v36 = pin.pObject;
      if ( v40 )
      {
        Scaleform::GFx::MovieImageLoadTask::MovieImageLoadTask(
          v40,
          pmd.pObject,
          pm,
          (Scaleform::GFx::Resource *)pin.pObject,
          format,
          (Scaleform::GFx::Resource *)pls);
        v42 = v41;
      }
      else
      {
        v42 = 0;
      }
      if ( (v8 & 0x11) != 0 || !Scaleform::GFx::LoadStates::SubmitBackgroundTask(pls, (Scaleform::GFx::LoaderTask *)v42) )
      {
        v42->AddRef(v42);
        if ( !v42[4].RefCount )
        {
          if ( pm )
            Scaleform::GFx::Resource::Release(pm);
          Scaleform::RefCountImpl::Release(v42);
          Scaleform::GFx::ResourceKey::~ResourceKey(&fileDataKey);
          if ( v36 )
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v36);
          if ( plp.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)plp.pObject);
          if ( pbp.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pbp.pObject);
          v28 = pmd.pObject;
          goto LABEL_41;
        }
      }
      if ( v42 )
        Scaleform::RefCountImpl::Release(v42);
LABEL_90:
      v44 = pls;
      v37 = (Scaleform::RefCountVImpl *)pbp.pObject;
      v38 = Scaleform::GFx::LoaderImpl::BindMovieAndWait(pm, pbp.pObject, v44, v8, ploadStack);
      if ( fileDataKey.pKeyInterface )
        fileDataKey.pKeyInterface->Release(fileDataKey.pKeyInterface, fileDataKey.hKeyData);
      if ( v36 )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v36);
      if ( plp.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)plp.pObject);
      if ( v37 )
        Scaleform::RefCountImpl::Release(v37);
      Scaleform::GFx::Resource::Release(pmd.pObject);
      if ( phandle.State == RS_Available )
      {
        Scaleform::GFx::Resource::Release(phandle.pResource);
      }
      else if ( phandle.State >= RS_WaitingResolve )
      {
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)phandle.pResource);
      }
      v43 = (void *)(fileName.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((fileName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v43);
      return v38;
    }
    v39 = plp.pObject;
    if ( (v8 & 0x10) != 0 )
    {
      loadConstants = 0;
    }
    else
    {
      loadConstants = (unsigned int)v30;
      if ( !v30 )
      {
LABEL_108:
        if ( (v8 & 1) != 0 || !Scaleform::GFx::LoadStates::SubmitBackgroundTask(pls, v39) )
          v39->Execute(v39);
        if ( loadConstants )
        {
          if ( v30 )
            Scaleform::RefCountImpl::Release(v30);
          pbp.pObject = 0;
        }
        if ( v39 )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v39);
        plp.pObject = 0;
        if ( pin.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pin.pObject);
        v36 = 0;
        goto LABEL_90;
      }
      Scaleform::GFx::LoadProcess::SetBindProcess(plp.pObject, (Scaleform::GFx::Resource *)v30);
    }
    if ( v30 )
      v39->pTempBindData = (Scaleform::GFx::TempBindData *)v30[6].__vftable;
    goto LABEL_108;
  }
  v13 = Scaleform::GFx::LoadStates::OpenFile(pls, (const char *)((fileName.HeapTypeBits & 0xFFFFFFFC) + 8), v8);
  v14 = (Scaleform::RefCountVImpl *)v13;
  pin.pObject = v13;
  if ( v13 )
  {
    format = Scaleform::GFx::LoaderImpl::DetectFileFormat(v13);
    switch ( format )
    {
      case File_SWF:
        if ( (v8 & 0x80000) == 0 )
          goto $LN34_7;
        Scaleform::String::String(
          (Scaleform::String *)&loadConstants,
          "Failed loading SWF file \"",
          (char *)((fileName.HeapTypeBits & 0xFFFFFFFC) + 8),
          "\" - GFX file format expected");
        if ( plog )
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
            &plog->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
            "%s",
            (const char *)((loadConstants & 0xFFFFFFFC) + 8));
        Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
          phandle.pSlot,
          (char *)((loadConstants & 0xFFFFFFFC) + 8));
        Scaleform::String::~String((Scaleform::String *)&loadConstants);
        Scaleform::GFx::ResourceKey::~ResourceKey(&fileDataKey);
        Scaleform::RefCountImpl::Release(v14);
        Scaleform::GFx::ResourceLib::BindHandle::~BindHandle(&phandle);
        Scaleform::String::~String(&fileName);
        return 0;
      case File_GFX:
$LN34_7:
        v19 = MT_Flash;
        goto LABEL_28;
      case File_JPEG:
      case File_PNG:
      case File_GIF:
      case File_TGA:
      case File_DDS:
      case File_HDR:
      case File_BMP:
      case File_DIB:
      case File_PFM:
      case File_TIFF:
      case File_PVR:
      case File_ETC:
      case File_SIF:
      case File_GXT:
        if ( ((unsigned int)&_sbh_sizeHeaderList & v8) == 0 )
          goto LABEL_61;
        v19 = MT_Image;
LABEL_28:
        Alloc = Scaleform::Memory::pGlobalHeap->Alloc;
        plog = (Scaleform::GFx::LogState *)v19;
        v21 = fileName.HeapTypeBits & 0xFFFFFFFC;
        v22 = (Scaleform::GFx::MovieDataDef *)Alloc(Scaleform::Memory::pGlobalHeap, 36u, 0);
        if ( v22 )
        {
          Scaleform::GFx::MovieDataDef::MovieDataDef(
            v22,
            &fileDataKey,
            v19,
            (const char *)(v21 + 8),
            0,
            (v8 & 0x10000000) != 0,
            memoryArena);
          v24 = v23;
        }
        else
        {
          v24 = 0;
        }
        pmd.pObject = v24;
        if ( !v24 )
          goto LABEL_40;
        Scaleform::GFx::LoadStates::SetRelativePathForDataDef(pls, v24);
        if ( v19 == MT_Flash )
        {
          v25 = (Scaleform::GFx::LoadProcess *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::operator new(0x360u);
          if ( v25 )
          {
            Scaleform::GFx::LoadProcess::LoadProcess(v25, v24, pls, v8);
            v27 = v26;
          }
          else
          {
            v27 = 0;
          }
          plp.pObject = v27;
          if ( !v27 )
            goto LABEL_39;
          if ( !Scaleform::GFx::LoadProcess::BeginSWFLoading(v27, pin.pObject) )
          {
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v27);
LABEL_39:
            Scaleform::GFx::Resource::Release(v24);
            pmd.pObject = 0;
LABEL_40:
            Scaleform::String::String(
              (Scaleform::String *)&loadConstants,
              "Failed to load SWF file \"",
              (char *)((fileName.HeapTypeBits & 0xFFFFFFFC) + 8),
              "\"\n");
            Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
              phandle.pSlot,
              (char *)((loadConstants & 0xFFFFFFFC) + 8));
            Scaleform::String::~String((Scaleform::String *)&loadConstants);
            Scaleform::GFx::ResourceKey::~ResourceKey(&fileDataKey);
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pin.pObject);
            v28 = pmd.pObject;
            if ( !pmd.pObject )
              goto LABEL_42;
LABEL_41:
            Scaleform::GFx::Resource::Release(v28);
LABEL_42:
            Scaleform::GFx::ResourceLib::BindHandle::~BindHandle(&phandle);
            Scaleform::String::~String(&fileName);
            return 0;
          }
          if ( !(_BYTE)loadConstants )
          {
LABEL_47:
            v30 = (Scaleform::RefCountVImpl *)pbp.pObject;
            Scaleform::GFx::ResourceLib::ResourceSlot::Resolve(phandle.pSlot, v24);
            movieNeedsLoading = 1;
            if ( (_BYTE)loadConstants )
              goto LABEL_50;
            if ( pm )
            {
              v30 = (Scaleform::RefCountVImpl *)pbp.pObject;
              goto LABEL_101;
            }
            goto LABEL_49;
          }
          p_pbp = &pbp;
        }
        else
        {
          p_pbp = 0;
        }
        pm = Scaleform::GFx::LoaderImpl::CreateMovieDefImpl(
               (Scaleform::String)pls,
               v24,
               v8,
               &p_pbp->pObject,
               1,
               ploadStack,
               memoryArena);
        goto LABEL_47;
      default:
LABEL_61:
        Scaleform::String::String(
          (Scaleform::String *)&loadConstants,
          "Unknown file format at URL \"",
          (char *)((fileName.HeapTypeBits & 0xFFFFFFFC) + 8),
          "\"");
        if ( plog )
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
            &plog->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
            "%s",
            (const char *)((loadConstants & 0xFFFFFFFC) + 8));
        Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
          phandle.pSlot,
          (char *)((loadConstants & 0xFFFFFFFC) + 8));
        v32 = (void *)(loadConstants & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((loadConstants & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v32);
        if ( fileDataKey.pKeyInterface )
          fileDataKey.pKeyInterface->Release(fileDataKey.pKeyInterface, fileDataKey.hKeyData);
        Scaleform::RefCountImpl::Release(v14);
        if ( phandle.State == RS_Available )
        {
          Scaleform::GFx::Resource::Release(phandle.pResource);
          v16 = (void *)(fileName.HeapTypeBits & 0xFFFFFFFC);
          v17 = InterlockedExchangeAdd((volatile LONG *)((fileName.HeapTypeBits & 0xFFFFFFFC) + 4), -1);
          goto LABEL_17;
        }
        if ( phandle.State >= RS_WaitingResolve )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)phandle.pResource);
        goto LABEL_16;
    }
  }
  Scaleform::String::String(
    (Scaleform::String *)&loadConstants,
    "Loader failed to open \"",
    (char *)((fileName.HeapTypeBits & 0xFFFFFFFC) + 8),
    "\"\n");
  Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(phandle.pSlot, (char *)((loadConstants & 0xFFFFFFFC) + 8));
  v15 = (void *)(loadConstants & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((loadConstants & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
  if ( fileDataKey.pKeyInterface )
    fileDataKey.pKeyInterface->Release(fileDataKey.pKeyInterface, fileDataKey.hKeyData);
  if ( phandle.State == RS_Available )
  {
LABEL_60:
    Scaleform::GFx::Resource::Release(phandle.pResource);
    goto LABEL_16;
  }
  if ( phandle.State >= RS_WaitingResolve )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)phandle.pResource);
LABEL_16:
  v16 = (void *)(fileName.HeapTypeBits & 0xFFFFFFFC);
  v17 = InterlockedExchangeAdd((volatile LONG *)((fileName.HeapTypeBits & 0xFFFFFFFC) + 4), -1);
LABEL_17:
  if ( v17 == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16);
  return 0;
}
