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
