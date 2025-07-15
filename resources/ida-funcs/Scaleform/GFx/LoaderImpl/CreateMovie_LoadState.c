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


Scaleform::GFx::MovieDefImpl *__cdecl Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(
        Scaleform::GFx::LoadStates *pls,
        const Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *bytes,
        unsigned int loadConstants,
        Scaleform::GFx::LoaderImpl::LoadStackItem *ploadStack,
        unsigned int memoryArena)
{
  __int64 ProfileTicks; // kr00_8
  Scaleform::GFx::MovieDefBindStates *pObject; // ecx
  Scaleform::GFx::LogState *v7; // ebp
  Scaleform::MemoryFile *v8; // eax
  Scaleform::File *v9; // eax
  Scaleform::File *v10; // edi
  Scaleform::GFx::MovieDataDef::MovieDataType v12; // esi
  Scaleform::GFx::MovieDataDef *v13; // eax
  Scaleform::String::DataDesc *v14; // eax
  Scaleform::GFx::MovieDataDef *v15; // ebp
  Scaleform::GFx::LoadProcess *v16; // eax
  Scaleform::GFx::LoadProcess *v17; // eax
  Scaleform::GFx::LoadProcess *v18; // esi
  void *v19; // esi
  Scaleform::Ptr<Scaleform::GFx::MovieBindProcess> *p_pbp; // eax
  Scaleform::GFx::MovieDefImpl *MovieDefImpl; // edi
  Scaleform::RefCountVImpl *v22; // esi
  Scaleform::GFx::LoadProcess *v23; // ebp
  Scaleform::File *v24; // ebp
  Scaleform::GFx::MovieImageLoadTask *v25; // eax
  Scaleform::File *v26; // ebp
  Scaleform::RefCountVImpl *v27; // eax
  Scaleform::RefCountVImpl *v28; // esi
  Scaleform::GFx::MovieDefImpl *v29; // edi
  void *v30; // esi
  Scaleform::GFx::MovieBindProcess *ploadBind; // [esp+18h] [ebp-ACh] BYREF
  Scaleform::String s; // [esp+1Ch] [ebp-A8h] BYREF
  Scaleform::GFx::ResourceLib::BindHandle phandle; // [esp+20h] [ebp-A4h] BYREF
  Scaleform::Ptr<Scaleform::GFx::LoadProcess> plp; // [esp+28h] [ebp-9Ch]
  Scaleform::File *pfile; // [esp+2Ch] [ebp-98h]
  Scaleform::Ptr<Scaleform::GFx::MovieBindProcess> pbp; // [esp+30h] [ebp-94h] BYREF
  Scaleform::GFx::ResourceKey fileDataKey; // [esp+34h] [ebp-90h] BYREF
  Scaleform::Ptr<Scaleform::File> pin; // [esp+3Ch] [ebp-88h] BYREF
  Scaleform::GFx::FileTypeConstants::FileFormatType format; // [esp+40h] [ebp-84h]
  char fileName[128]; // [esp+44h] [ebp-80h] BYREF

  ProfileTicks = Scaleform::Timer::GetProfileTicks();
  Scaleform::SFsprintf(fileName, 0x80u, "*Bytes@%p*", (const void *)ProfileTicks);
  pObject = pls->pBindStates.pObject;
  v7 = pls->pLog.pObject;
  phandle.State = RS_Unbound;
  phandle.pResource = 0;
  pbp.pObject = 0;
  plp.pObject = 0;
  if ( pObject->pImagePackParams.pObject )
    loadConstants |= 0x11u;
  Scaleform::GFx::MovieDataDef::CreateMovieFileKey(&fileDataKey, fileName, ProfileTicks, 0, 0);
  Scaleform::GFx::ResourceWeakLib::BindResourceKey(pls->pWeakResourceLib.pObject, &phandle, &fileDataKey);
  v8 = (Scaleform::MemoryFile *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 28, 0);
  if ( v8 )
  {
    Scaleform::MemoryFile::MemoryFile(v8, fileName, bytes->Data.Data, bytes->Data.Size);
    v10 = v9;
    pfile = v9;
  }
  else
  {
    pfile = 0;
    v10 = 0;
  }
  pin.pObject = v10;
  format = Scaleform::GFx::LoaderImpl::DetectFileFormat(v10);
  switch ( format )
  {
    case File_SWF:
      if ( (loadConstants & 0x80000) == 0 )
        goto $LN25_17;
      Scaleform::String::String(&s, "Failed loading SWF file \"", fileName, "\" - GFX file format expected");
      if ( v7 )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
          &v7->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
          "%s",
          (const char *)((s.HeapTypeBits & 0xFFFFFFFC) + 8));
      Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
        phandle.pSlot,
        (char *)((s.HeapTypeBits & 0xFFFFFFFC) + 8));
      Scaleform::String::~String(&s);
      if ( fileDataKey.pKeyInterface )
        fileDataKey.pKeyInterface->Release(fileDataKey.pKeyInterface, fileDataKey.hKeyData);
      if ( v10 )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v10);
      Scaleform::GFx::ResourceLib::BindHandle::~BindHandle(&phandle);
      return 0;
    case File_GFX:
$LN25_17:
      v12 = MT_Flash;
      ploadBind = (Scaleform::GFx::MovieBindProcess *)1;
      goto LABEL_18;
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
      if ( ((unsigned int)&_sbh_sizeHeaderList & loadConstants) == 0 )
        goto LABEL_93;
      ploadBind = (Scaleform::GFx::MovieBindProcess *)2;
      v12 = MT_Image;
LABEL_18:
      v13 = (Scaleform::GFx::MovieDataDef *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 36, 0);
      if ( v13 )
      {
        Scaleform::GFx::MovieDataDef::MovieDataDef(
          v13,
          &fileDataKey,
          v12,
          fileName,
          0,
          (loadConstants & 0x10000000) != 0,
          memoryArena);
        v15 = (Scaleform::GFx::MovieDataDef *)v14;
        s.pData = v14;
      }
      else
      {
        s.pData = 0;
        v15 = 0;
      }
      if ( !v15 )
        goto LABEL_30;
      Scaleform::GFx::LoadStates::SetRelativePathForDataDef(pls, v15);
      if ( v12 == MT_Flash )
      {
        v16 = (Scaleform::GFx::LoadProcess *)Scaleform::Memory::pGlobalHeap->Alloc(
                                               Scaleform::Memory::pGlobalHeap,
                                               864,
                                               0);
        if ( v16 )
        {
          Scaleform::GFx::LoadProcess::LoadProcess(v16, v15, pls, loadConstants);
          v18 = v17;
        }
        else
        {
          v18 = 0;
        }
        plp.pObject = v18;
        if ( !v18 )
        {
LABEL_29:
          Scaleform::GFx::Resource::Release(v15);
LABEL_30:
          Scaleform::String::String((Scaleform::String *)&pin, "Failed to load SWF file \"", fileName, "\"\n");
          Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
            phandle.pSlot,
            (char *)(((unsigned int)pin.pObject & 0xFFFFFFFC) + 8));
          v19 = (void *)((unsigned int)pin.pObject & 0xFFFFFFFC);
          if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)pin.pObject & 0xFFFFFFFC) + 4), -1) == 1 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v19);
          if ( fileDataKey.pKeyInterface )
            fileDataKey.pKeyInterface->Release(fileDataKey.pKeyInterface, fileDataKey.hKeyData);
          if ( pfile )
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pfile);
          goto LABEL_101;
        }
        if ( !Scaleform::GFx::LoadProcess::BeginSWFLoading(v18, pfile) )
        {
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v18);
          goto LABEL_29;
        }
        v12 = (Scaleform::GFx::MovieDataDef::MovieDataType)ploadBind;
        p_pbp = &pbp;
      }
      else
      {
        p_pbp = 0;
      }
      MovieDefImpl = Scaleform::GFx::LoaderImpl::CreateMovieDefImpl(
                       (Scaleform::String)pls,
                       v15,
                       loadConstants,
                       &p_pbp->pObject,
                       1,
                       ploadStack,
                       memoryArena);
      Scaleform::GFx::ResourceLib::ResourceSlot::Resolve(phandle.pSlot, v15);
      if ( !MovieDefImpl )
      {
        if ( fileDataKey.pKeyInterface )
          fileDataKey.pKeyInterface->Release(fileDataKey.pKeyInterface, fileDataKey.hKeyData);
        if ( pfile )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pfile);
        if ( plp.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)plp.pObject);
        if ( pbp.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pbp.pObject);
        Scaleform::GFx::Resource::Release(v15);
LABEL_101:
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
      if ( v12 == MT_Flash )
      {
        v22 = (Scaleform::RefCountVImpl *)pbp.pObject;
        v23 = plp.pObject;
        if ( (loadConstants & 0x10) != 0 )
        {
          ploadBind = 0;
        }
        else
        {
          ploadBind = pbp.pObject;
          if ( !pbp.pObject )
          {
LABEL_56:
            if ( (loadConstants & 1) != 0 || !Scaleform::GFx::LoadStates::SubmitBackgroundTask(pls, v23) )
              v23->Execute(v23);
            if ( ploadBind )
            {
              if ( v22 )
                Scaleform::RefCountImpl::Release(v22);
              v22 = 0;
            }
            if ( v23 )
              Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v23);
            plp.pObject = 0;
            if ( pfile )
              Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pfile);
            v24 = 0;
LABEL_84:
            v29 = Scaleform::GFx::LoaderImpl::BindMovieAndWait(
                    MovieDefImpl,
                    (Scaleform::GFx::MovieBindProcess *)v22,
                    pls,
                    loadConstants,
                    ploadStack);
            if ( fileDataKey.pKeyInterface )
              fileDataKey.pKeyInterface->Release(fileDataKey.pKeyInterface, fileDataKey.hKeyData);
            if ( v24 )
              Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v24);
            if ( plp.pObject )
              Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)plp.pObject);
            if ( v22 )
              Scaleform::RefCountImpl::Release(v22);
            Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)s.pData);
            Scaleform::GFx::ResourceLib::BindHandle::~BindHandle(&phandle);
            return v29;
          }
          Scaleform::GFx::LoadProcess::SetBindProcess(plp.pObject, (Scaleform::GFx::Resource *)pbp.pObject);
        }
        if ( v22 )
          v23->pTempBindData = (Scaleform::GFx::TempBindData *)v22[6].__vftable;
        goto LABEL_56;
      }
      v25 = (Scaleform::GFx::MovieImageLoadTask *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::operator new(0x28u);
      v26 = pfile;
      if ( v25 )
      {
        Scaleform::GFx::MovieImageLoadTask::MovieImageLoadTask(
          v25,
          (Scaleform::GFx::MovieDataDef *)s.pData,
          MovieDefImpl,
          (Scaleform::GFx::Resource *)pfile,
          format,
          (Scaleform::GFx::Resource *)pls);
        v28 = v27;
      }
      else
      {
        v28 = 0;
      }
      if ( (loadConstants & 0x11) == 0
        && Scaleform::GFx::LoadStates::SubmitBackgroundTask(pls, (Scaleform::GFx::LoaderTask *)v28)
        || (v28->AddRef(v28), v28[4].RefCount) )
      {
        if ( v28 )
          Scaleform::RefCountImpl::Release(v28);
        v24 = pin.pObject;
        v22 = (Scaleform::RefCountVImpl *)pbp.pObject;
        goto LABEL_84;
      }
      Scaleform::GFx::Resource::Release(MovieDefImpl);
      Scaleform::RefCountImpl::Release(v28);
      Scaleform::GFx::ResourceKey::~ResourceKey(&fileDataKey);
      if ( v26 )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v26);
      if ( plp.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)plp.pObject);
      if ( pbp.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pbp.pObject);
      Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)s.pData);
      Scaleform::GFx::ResourceLib::BindHandle::~BindHandle(&phandle);
      return 0;
    default:
LABEL_93:
      Scaleform::String::String((Scaleform::String *)&ploadBind, "Unknown file format at URL \"", fileName, "\"");
      if ( v7 )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
          &v7->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
          "%s",
          (const char *)(((unsigned int)ploadBind & 0xFFFFFFFC) + 8));
      Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
        phandle.pSlot,
        (char *)(((unsigned int)ploadBind & 0xFFFFFFFC) + 8));
      v30 = (void *)((unsigned int)ploadBind & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)ploadBind & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v30);
      if ( fileDataKey.pKeyInterface )
        fileDataKey.pKeyInterface->Release(fileDataKey.pKeyInterface, fileDataKey.hKeyData);
      if ( v10 )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v10);
      goto LABEL_101;
  }
}
