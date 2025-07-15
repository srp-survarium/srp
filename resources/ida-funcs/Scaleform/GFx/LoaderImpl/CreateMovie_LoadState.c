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
  Scaleform::GFx::Resource *v10; // edi
  Scaleform::GFx::Resource *v11; // ebp
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
  Scaleform::RefCountVImpl *v26; // eax
  Scaleform::RefCountVImpl *v27; // ebp
  Scaleform::GFx::Resource *v28; // ecx
  Scaleform::GFx::MovieBindProcess **p_ppbindProcess; // eax
  Scaleform::RefCountVImpl *v30; // ebp
  Scaleform::GFx::MovieDefImpl *MovieDefImpl; // eax
  void *v32; // esi
  Scaleform::GFx::Resource *v33; // eax
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v34; // esi
  const char *Error; // eax
  Scaleform::RefCountVImpl *v36; // ebp
  Scaleform::RefCountVImpl *v37; // esi
  Scaleform::GFx::MovieDefImpl *v38; // edi
  Scaleform::GFx::LoaderTask *v39; // edi
  Scaleform::GFx::MovieImageLoadTask *v40; // eax
  Scaleform::RefCountVImpl *v41; // eax
  Scaleform::RefCountVImpl *v42; // edi
  void *v43; // esi
  Scaleform::GFx::LoadStates *v44; // [esp-Ch] [ebp-4Ch]
  Scaleform::String pdest; // [esp+10h] [ebp-30h] BYREF
  Scaleform::GFx::MovieBindProcess *ppbindProcess; // [esp+14h] [ebp-2Ch] BYREF
  Scaleform::File *pfile; // [esp+18h] [ebp-28h]
  Scaleform::RefCountVImpl *v48; // [esp+1Ch] [ebp-24h]
  Scaleform::GFx::Resource *v49; // [esp+20h] [ebp-20h]
  Scaleform::GFx::Resource *v50; // [esp+24h] [ebp-1Ch]
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *Value; // [esp+28h] [ebp-18h]
  Scaleform::GFx::FileTypeConstants::FileFormatType v52; // [esp+2Ch] [ebp-14h]
  Scaleform::GFx::ResourceLib::BindHandle v53; // [esp+30h] [ebp-10h] BYREF
  Scaleform::GFx::ResourceKey result; // [esp+38h] [ebp-8h] BYREF
  char pstates; // [esp+44h] [ebp+4h]

  Scaleform::String::String(&pdest);
  Scaleform::GFx::LoadStates::BuildURL(pls, &pdest, loc);
  pObject = pls->pBindStates.pObject;
  v7 = pls->pLog.pObject;
  v8 = loadConstants;
  v53.State = RS_Unbound;
  v53.pResource = 0;
  v50 = 0;
  Value = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)v7;
  pstates = 0;
  ppbindProcess = 0;
  v48 = 0;
  pfile = 0;
  v52 = File_Unopened;
  if ( pObject->pImagePackParams.pObject )
    v8 = loadConstants | 0x11;
  LOBYTE(loadConstants) = (v8 & 0x10) == 0;
  LoadTimeImageCreator = Scaleform::GFx::LoadStates::GetLoadTimeImageCreator(pls, v8);
  v10 = (Scaleform::GFx::Resource *)pls->pBindStates.pObject->pFileOpener.pObject;
  v11 = (Scaleform::GFx::Resource *)LoadTimeImageCreator;
  if ( v10 )
    LODWORD(v12) = ((int (__thiscall *)(Scaleform::GFx::Resource *, unsigned int))v10->GetResourceTypeCode)(
                     v10,
                     (pdest.HeapTypeBits & 0xFFFFFFFC) + 8);
  else
    v12 = 0;
  Scaleform::GFx::MovieDataDef::CreateMovieFileKey(
    &result,
    (char *)((pdest.HeapTypeBits & 0xFFFFFFFC) + 8),
    v12,
    v10,
    v11);
  if ( Scaleform::GFx::ResourceWeakLib::BindResourceKey(pls->pWeakResourceLib.pObject, &v53, &result) != RS_NeedsResolve )
  {
    v33 = Scaleform::GFx::ResourceLib::BindHandle::WaitForResolve(&v53);
    v49 = v33;
    if ( !v33 )
    {
      v34 = Value;
      if ( Value )
      {
        if ( v53.State < RS_WaitingResolve )
          Error = uri;
        else
          Error = Scaleform::GFx::ResourceLib::ResourceSlot::GetError(v53.pSlot);
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
          v34 + 3,
          (const char *)&stru_7F9BE8.allocator,
          Error);
      }
      if ( result.pKeyInterface )
        result.pKeyInterface->Release(result.pKeyInterface, result.hKeyData);
      if ( v53.State != RS_Available )
      {
        if ( v53.State >= RS_WaitingResolve )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v53.pResource);
        goto LABEL_16;
      }
      goto LABEL_60;
    }
    Value = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)v33[2].RefCount.Value;
    Scaleform::GFx::LoadStates::SetRelativePathForDataDef(pls, (Scaleform::GFx::MovieDataDef *)v33);
LABEL_49:
    MovieDefImpl = Scaleform::GFx::LoaderImpl::CreateMovieDefImpl(
                     pls,
                     (Scaleform::GFx::MovieDataDef *)v49,
                     v8,
                     Value == (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)1 ? &ppbindProcess : 0,
                     0,
                     ploadStack,
                     memoryArena);
    v30 = (Scaleform::RefCountVImpl *)ppbindProcess;
    v50 = MovieDefImpl;
LABEL_50:
    if ( !v50 )
    {
      if ( result.pKeyInterface )
        result.pKeyInterface->Release(result.pKeyInterface, result.hKeyData);
      if ( pfile )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pfile);
      if ( v48 )
        Scaleform::RefCountImpl::Release(v48);
      if ( v30 )
        Scaleform::RefCountImpl::Release(v30);
      Scaleform::GFx::Resource::Release(v49);
      if ( v53.State == RS_Available )
        goto LABEL_60;
      if ( v53.State >= RS_WaitingResolve )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v53.pResource);
      goto LABEL_16;
    }
    if ( !pstates )
    {
      v36 = (Scaleform::RefCountVImpl *)pfile;
      goto LABEL_90;
    }
LABEL_101:
    if ( Value != (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)1 )
    {
      v40 = (Scaleform::GFx::MovieImageLoadTask *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    40,
                                                    0);
      v36 = (Scaleform::RefCountVImpl *)pfile;
      if ( v40 )
      {
        Scaleform::GFx::MovieImageLoadTask::MovieImageLoadTask(
          v40,
          (Scaleform::GFx::MovieDataDef *)v49,
          (Scaleform::GFx::MovieDefImpl *)v50,
          (Scaleform::GFx::Resource *)pfile,
          v52,
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
          if ( v50 )
            Scaleform::GFx::Resource::Release(v50);
          Scaleform::RefCountImpl::Release(v42);
          Scaleform::GFx::ResourceKey::~ResourceKey(&result);
          if ( v36 )
            Scaleform::RefCountImpl::Release(v36);
          if ( v48 )
            Scaleform::RefCountImpl::Release(v48);
          if ( ppbindProcess )
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)ppbindProcess);
          v28 = v49;
          goto LABEL_41;
        }
      }
      if ( v42 )
        Scaleform::RefCountImpl::Release(v42);
LABEL_90:
      v44 = pls;
      v37 = (Scaleform::RefCountVImpl *)ppbindProcess;
      v38 = Scaleform::GFx::LoaderImpl::BindMovieAndWait(
              (Scaleform::GFx::MovieDefImpl *)v50,
              ppbindProcess,
              v44,
              v8,
              ploadStack);
      if ( result.pKeyInterface )
        result.pKeyInterface->Release(result.pKeyInterface, result.hKeyData);
      if ( v36 )
        Scaleform::RefCountImpl::Release(v36);
      if ( v48 )
        Scaleform::RefCountImpl::Release(v48);
      if ( v37 )
        Scaleform::RefCountImpl::Release(v37);
      Scaleform::GFx::Resource::Release(v49);
      if ( v53.State == RS_Available )
      {
        Scaleform::GFx::Resource::Release(v53.pResource);
      }
      else if ( v53.State >= RS_WaitingResolve )
      {
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v53.pResource);
      }
      v43 = (void *)(pdest.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((pdest.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v43);
      return v38;
    }
    v39 = (Scaleform::GFx::LoaderTask *)v48;
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
          ppbindProcess = 0;
        }
        if ( v39 )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v39);
        v48 = 0;
        if ( pfile )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pfile);
        v36 = 0;
        goto LABEL_90;
      }
      Scaleform::GFx::LoadProcess::SetBindProcess((Scaleform::GFx::LoadProcess *)v48, (Scaleform::GFx::Resource *)v30);
    }
    if ( v30 )
      v39[38].RefCount = (volatile int)v30[6].__vftable;
    goto LABEL_108;
  }
  v13 = Scaleform::GFx::LoadStates::OpenFile(pls, (const char *)((pdest.HeapTypeBits & 0xFFFFFFFC) + 8), v8);
  v14 = (Scaleform::RefCountVImpl *)v13;
  pfile = v13;
  if ( v13 )
  {
    v52 = Scaleform::GFx::LoaderImpl::DetectFileFormat(v13);
    switch ( v52 )
    {
      case File_SWF:
        if ( (v8 & 0x80000) == 0 )
          goto $LN34_10;
        Scaleform::String::String(
          (Scaleform::String *)&loadConstants,
          (const __m128i *)"Failed loading SWF file \"",
          (const __m128i *)((pdest.HeapTypeBits & 0xFFFFFFFC) + 8),
          (const __m128i *)"\" - GFX file format expected");
        if ( Value )
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
            Value + 3,
            (const char *)&stru_7F9BE8.allocator,
            (loadConstants & 0xFFFFFFFC) + 8);
        Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
          v53.pSlot,
          (const __m128i *)((loadConstants & 0xFFFFFFFC) + 8));
        Scaleform::String::~String((Scaleform::String *)&loadConstants);
        Scaleform::GFx::ResourceKey::~ResourceKey(&result);
        Scaleform::RefCountImpl::Release(v14);
        Scaleform::GFx::ResourceLib::BindHandle::~BindHandle(&v53);
        Scaleform::String::~String(&pdest);
        return 0;
      case File_GFX:
$LN34_10:
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
        Value = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)v19;
        v21 = pdest.HeapTypeBits & 0xFFFFFFFC;
        v22 = (Scaleform::GFx::MovieDataDef *)Alloc(Scaleform::Memory::pGlobalHeap, 36u, 0);
        if ( v22 )
        {
          Scaleform::GFx::MovieDataDef::MovieDataDef(
            v22,
            &result,
            v19,
            (char *)(v21 + 8),
            0,
            (v8 & 0x10000000) != 0,
            memoryArena);
          v24 = v23;
        }
        else
        {
          v24 = 0;
        }
        v49 = v24;
        if ( !v24 )
          goto LABEL_40;
        Scaleform::GFx::LoadStates::SetRelativePathForDataDef(pls, v24);
        if ( v19 == MT_Flash )
        {
          v25 = (Scaleform::GFx::LoadProcess *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::operator new(0x360u);
          if ( v25 )
          {
            Scaleform::GFx::LoadProcess::LoadProcess(v25, v24, (int)pls, v8);
            v27 = v26;
          }
          else
          {
            v27 = 0;
          }
          v48 = v27;
          if ( !v27 )
            goto LABEL_39;
          if ( !Scaleform::GFx::LoadProcess::BeginSWFLoading(
                  (Scaleform::GFx::LoadProcess *)v27,
                  (Scaleform::GFx::Resource *)pfile) )
          {
            Scaleform::RefCountImpl::Release(v27);
LABEL_39:
            Scaleform::GFx::Resource::Release(v24);
            v49 = 0;
LABEL_40:
            Scaleform::String::String(
              (Scaleform::String *)&loadConstants,
              (const __m128i *)"Failed to load SWF file \"",
              (const __m128i *)((pdest.HeapTypeBits & 0xFFFFFFFC) + 8),
              (const __m128i *)"\"\n");
            Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
              v53.pSlot,
              (const __m128i *)((loadConstants & 0xFFFFFFFC) + 8));
            Scaleform::String::~String((Scaleform::String *)&loadConstants);
            Scaleform::GFx::ResourceKey::~ResourceKey(&result);
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pfile);
            v28 = v49;
            if ( !v49 )
              goto LABEL_42;
LABEL_41:
            Scaleform::GFx::Resource::Release(v28);
LABEL_42:
            Scaleform::GFx::ResourceLib::BindHandle::~BindHandle(&v53);
            Scaleform::String::~String(&pdest);
            return 0;
          }
          if ( !(_BYTE)loadConstants )
          {
LABEL_47:
            v30 = (Scaleform::RefCountVImpl *)ppbindProcess;
            Scaleform::GFx::ResourceLib::ResourceSlot::Resolve(v53.pSlot, v24);
            pstates = 1;
            if ( (_BYTE)loadConstants )
              goto LABEL_50;
            if ( v50 )
            {
              v30 = (Scaleform::RefCountVImpl *)ppbindProcess;
              goto LABEL_101;
            }
            goto LABEL_49;
          }
          p_ppbindProcess = &ppbindProcess;
        }
        else
        {
          p_ppbindProcess = 0;
        }
        v50 = Scaleform::GFx::LoaderImpl::CreateMovieDefImpl(pls, v24, v8, p_ppbindProcess, 1, ploadStack, memoryArena);
        goto LABEL_47;
      default:
LABEL_61:
        Scaleform::String::String(
          (Scaleform::String *)&loadConstants,
          (const __m128i *)"Unknown file format at URL \"",
          (const __m128i *)((pdest.HeapTypeBits & 0xFFFFFFFC) + 8),
          (const __m128i *)"\"");
        if ( Value )
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
            Value + 3,
            (const char *)&stru_7F9BE8.allocator,
            (loadConstants & 0xFFFFFFFC) + 8);
        Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
          v53.pSlot,
          (const __m128i *)((loadConstants & 0xFFFFFFFC) + 8));
        v32 = (void *)(loadConstants & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((loadConstants & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v32);
        if ( result.pKeyInterface )
          result.pKeyInterface->Release(result.pKeyInterface, result.hKeyData);
        Scaleform::RefCountImpl::Release(v14);
        if ( v53.State == RS_Available )
        {
          Scaleform::GFx::Resource::Release(v53.pResource);
          v16 = (void *)(pdest.HeapTypeBits & 0xFFFFFFFC);
          v17 = InterlockedExchangeAdd((volatile LONG *)((pdest.HeapTypeBits & 0xFFFFFFFC) + 4), -1);
          goto LABEL_17;
        }
        if ( v53.State >= RS_WaitingResolve )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v53.pResource);
        goto LABEL_16;
    }
  }
  Scaleform::String::String(
    (Scaleform::String *)&loadConstants,
    (const __m128i *)"Loader failed to open \"",
    (const __m128i *)((pdest.HeapTypeBits & 0xFFFFFFFC) + 8),
    (const __m128i *)"\"\n");
  Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
    v53.pSlot,
    (const __m128i *)((loadConstants & 0xFFFFFFFC) + 8));
  v15 = (void *)(loadConstants & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((loadConstants & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
  if ( result.pKeyInterface )
    result.pKeyInterface->Release(result.pKeyInterface, result.hKeyData);
  if ( v53.State == RS_Available )
  {
LABEL_60:
    Scaleform::GFx::Resource::Release(v53.pResource);
    goto LABEL_16;
  }
  if ( v53.State >= RS_WaitingResolve )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v53.pResource);
LABEL_16:
  v16 = (void *)(pdest.HeapTypeBits & 0xFFFFFFFC);
  v17 = InterlockedExchangeAdd((volatile LONG *)((pdest.HeapTypeBits & 0xFFFFFFFC) + 4), -1);
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
  Scaleform::String::DataDesc *v10; // edi
  Scaleform::GFx::MovieDataDef::MovieDataType pData; // esi
  Scaleform::GFx::MovieDataDef *v13; // eax
  Scaleform::String::DataDesc *v14; // eax
  Scaleform::GFx::MovieDataDef *v15; // ebp
  Scaleform::GFx::LoadProcess *v16; // eax
  Scaleform::RefCountVImpl *v17; // eax
  Scaleform::RefCountVImpl *v18; // esi
  void *v19; // esi
  Scaleform::GFx::MovieBindProcess **p_ppbindProcess; // eax
  Scaleform::GFx::MovieDefImpl *MovieDefImpl; // edi
  Scaleform::RefCountVImpl *v22; // esi
  Scaleform::GFx::LoaderTask *v23; // ebp
  Scaleform::RefCountVImpl *v24; // ebp
  Scaleform::GFx::MovieImageLoadTask *v25; // eax
  Scaleform::RefCountVImpl *v26; // ebp
  Scaleform::RefCountVImpl *v27; // eax
  Scaleform::RefCountVImpl *v28; // esi
  Scaleform::GFx::MovieDefImpl *v29; // edi
  void *v30; // esi
  Scaleform::String v31; // [esp+18h] [ebp-ACh] BYREF
  Scaleform::String v32; // [esp+1Ch] [ebp-A8h] BYREF
  Scaleform::GFx::ResourceLib::BindHandle v33; // [esp+20h] [ebp-A4h] BYREF
  Scaleform::RefCountVImpl *v34; // [esp+28h] [ebp-9Ch]
  Scaleform::File *pfile; // [esp+2Ch] [ebp-98h]
  Scaleform::GFx::MovieBindProcess *ppbindProcess; // [esp+30h] [ebp-94h] BYREF
  Scaleform::GFx::ResourceKey result; // [esp+34h] [ebp-90h] BYREF
  Scaleform::String v38; // [esp+3Ch] [ebp-88h] BYREF
  Scaleform::GFx::FileTypeConstants::FileFormatType v39; // [esp+40h] [ebp-84h]
  __m128i pfilename[8]; // [esp+44h] [ebp-80h] BYREF

  ProfileTicks = Scaleform::Timer::GetProfileTicks();
  Scaleform::SFsprintf(pfilename[0].m128i_i8, 0x80u, "*Bytes@%p*", (const void *)ProfileTicks);
  pObject = pls->pBindStates.pObject;
  v7 = pls->pLog.pObject;
  v33.State = RS_Unbound;
  v33.pResource = 0;
  ppbindProcess = 0;
  v34 = 0;
  if ( pObject->pImagePackParams.pObject )
    loadConstants |= 0x11u;
  Scaleform::GFx::MovieDataDef::CreateMovieFileKey(&result, pfilename[0].m128i_i8, ProfileTicks, 0, 0);
  Scaleform::GFx::ResourceWeakLib::BindResourceKey(pls->pWeakResourceLib.pObject, &v33, &result);
  v8 = (Scaleform::MemoryFile *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 28, 0);
  if ( v8 )
  {
    Scaleform::MemoryFile::MemoryFile(v8, pfilename[0].m128i_i8, bytes->Data.Data, bytes->Data.Size);
    v10 = (Scaleform::String::DataDesc *)v9;
    pfile = v9;
  }
  else
  {
    pfile = 0;
    v10 = 0;
  }
  v38.pData = v10;
  v39 = Scaleform::GFx::LoaderImpl::DetectFileFormat((Scaleform::File *)v10);
  switch ( v39 )
  {
    case File_SWF:
      if ( (loadConstants & 0x80000) == 0 )
        goto $LN25_18;
      Scaleform::String::String(
        &v32,
        (const __m128i *)"Failed loading SWF file \"",
        pfilename,
        (const __m128i *)"\" - GFX file format expected");
      if ( v7 )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
          &v7->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
          (const char *)&stru_7F9BE8.allocator,
          (v32.HeapTypeBits & 0xFFFFFFFC) + 8);
      Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
        v33.pSlot,
        (const __m128i *)((v32.HeapTypeBits & 0xFFFFFFFC) + 8));
      Scaleform::String::~String(&v32);
      if ( result.pKeyInterface )
        result.pKeyInterface->Release(result.pKeyInterface, result.hKeyData);
      if ( v10 )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v10);
      Scaleform::GFx::ResourceLib::BindHandle::~BindHandle(&v33);
      return 0;
    case File_GFX:
$LN25_18:
      pData = MT_Flash;
      v31.pData = (Scaleform::String::DataDesc *)1;
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
      v31.pData = (Scaleform::String::DataDesc *)2;
      pData = MT_Image;
LABEL_18:
      v13 = (Scaleform::GFx::MovieDataDef *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 36, 0);
      if ( v13 )
      {
        Scaleform::GFx::MovieDataDef::MovieDataDef(
          v13,
          &result,
          pData,
          pfilename[0].m128i_i8,
          0,
          (loadConstants & 0x10000000) != 0,
          memoryArena);
        v15 = (Scaleform::GFx::MovieDataDef *)v14;
        v32.pData = v14;
      }
      else
      {
        v32.pData = 0;
        v15 = 0;
      }
      if ( !v15 )
        goto LABEL_30;
      Scaleform::GFx::LoadStates::SetRelativePathForDataDef(pls, v15);
      if ( pData == MT_Flash )
      {
        v16 = (Scaleform::GFx::LoadProcess *)Scaleform::Memory::pGlobalHeap->Alloc(
                                               Scaleform::Memory::pGlobalHeap,
                                               864,
                                               0);
        if ( v16 )
        {
          Scaleform::GFx::LoadProcess::LoadProcess(v16, v15, (int)pls, loadConstants);
          v18 = v17;
        }
        else
        {
          v18 = 0;
        }
        v34 = v18;
        if ( !v18 )
        {
LABEL_29:
          Scaleform::GFx::Resource::Release(v15);
LABEL_30:
          Scaleform::String::String(
            &v38,
            (const __m128i *)"Failed to load SWF file \"",
            pfilename,
            (const __m128i *)"\"\n");
          Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
            v33.pSlot,
            (const __m128i *)((v38.HeapTypeBits & 0xFFFFFFFC) + 8));
          v19 = (void *)(v38.HeapTypeBits & 0xFFFFFFFC);
          if ( InterlockedExchangeAdd((volatile LONG *)((v38.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v19);
          if ( result.pKeyInterface )
            result.pKeyInterface->Release(result.pKeyInterface, result.hKeyData);
          if ( pfile )
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pfile);
          goto LABEL_101;
        }
        if ( !Scaleform::GFx::LoadProcess::BeginSWFLoading(
                (Scaleform::GFx::LoadProcess *)v18,
                (Scaleform::GFx::Resource *)pfile) )
        {
          Scaleform::RefCountImpl::Release(v18);
          goto LABEL_29;
        }
        pData = (Scaleform::GFx::MovieDataDef::MovieDataType)v31.pData;
        p_ppbindProcess = &ppbindProcess;
      }
      else
      {
        p_ppbindProcess = 0;
      }
      MovieDefImpl = Scaleform::GFx::LoaderImpl::CreateMovieDefImpl(
                       pls,
                       v15,
                       loadConstants,
                       p_ppbindProcess,
                       1,
                       ploadStack,
                       memoryArena);
      Scaleform::GFx::ResourceLib::ResourceSlot::Resolve(v33.pSlot, v15);
      if ( !MovieDefImpl )
      {
        if ( result.pKeyInterface )
          result.pKeyInterface->Release(result.pKeyInterface, result.hKeyData);
        if ( pfile )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pfile);
        if ( v34 )
          Scaleform::RefCountImpl::Release(v34);
        if ( ppbindProcess )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)ppbindProcess);
        Scaleform::GFx::Resource::Release(v15);
LABEL_101:
        if ( v33.State == RS_Available )
        {
          Scaleform::GFx::Resource::Release(v33.pResource);
          return 0;
        }
        else
        {
          if ( v33.State >= RS_WaitingResolve )
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v33.pResource);
          return 0;
        }
      }
      if ( pData == MT_Flash )
      {
        v22 = (Scaleform::RefCountVImpl *)ppbindProcess;
        v23 = (Scaleform::GFx::LoaderTask *)v34;
        if ( (loadConstants & 0x10) != 0 )
        {
          v31.pData = 0;
        }
        else
        {
          v31.pData = (Scaleform::String::DataDesc *)ppbindProcess;
          if ( !ppbindProcess )
          {
LABEL_56:
            if ( (loadConstants & 1) != 0 || !Scaleform::GFx::LoadStates::SubmitBackgroundTask(pls, v23) )
              v23->Execute(v23);
            if ( v31.pData )
            {
              if ( v22 )
                Scaleform::RefCountImpl::Release(v22);
              v22 = 0;
            }
            if ( v23 )
              Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v23);
            v34 = 0;
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
            if ( result.pKeyInterface )
              result.pKeyInterface->Release(result.pKeyInterface, result.hKeyData);
            if ( v24 )
              Scaleform::RefCountImpl::Release(v24);
            if ( v34 )
              Scaleform::RefCountImpl::Release(v34);
            if ( v22 )
              Scaleform::RefCountImpl::Release(v22);
            Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)v32.pData);
            Scaleform::GFx::ResourceLib::BindHandle::~BindHandle(&v33);
            return v29;
          }
          Scaleform::GFx::LoadProcess::SetBindProcess(
            (Scaleform::GFx::LoadProcess *)v34,
            (Scaleform::GFx::Resource *)ppbindProcess);
        }
        if ( v22 )
          v23[38].RefCount = (volatile int)v22[6].__vftable;
        goto LABEL_56;
      }
      v25 = (Scaleform::GFx::MovieImageLoadTask *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::operator new(0x28u);
      v26 = (Scaleform::RefCountVImpl *)pfile;
      if ( v25 )
      {
        Scaleform::GFx::MovieImageLoadTask::MovieImageLoadTask(
          v25,
          (Scaleform::GFx::MovieDataDef *)v32.pData,
          MovieDefImpl,
          (Scaleform::GFx::Resource *)pfile,
          v39,
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
        v24 = (Scaleform::RefCountVImpl *)v38.pData;
        v22 = (Scaleform::RefCountVImpl *)ppbindProcess;
        goto LABEL_84;
      }
      Scaleform::GFx::Resource::Release(MovieDefImpl);
      Scaleform::RefCountImpl::Release(v28);
      Scaleform::GFx::ResourceKey::~ResourceKey(&result);
      if ( v26 )
        Scaleform::RefCountImpl::Release(v26);
      if ( v34 )
        Scaleform::RefCountImpl::Release(v34);
      if ( ppbindProcess )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)ppbindProcess);
      Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)v32.pData);
      Scaleform::GFx::ResourceLib::BindHandle::~BindHandle(&v33);
      return 0;
    default:
LABEL_93:
      Scaleform::String::String(
        &v31,
        (const __m128i *)"Unknown file format at URL \"",
        pfilename,
        (const __m128i *)"\"");
      if ( v7 )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
          &v7->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
          (const char *)&stru_7F9BE8.allocator,
          (v31.HeapTypeBits & 0xFFFFFFFC) + 8);
      Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
        v33.pSlot,
        (const __m128i *)((v31.HeapTypeBits & 0xFFFFFFFC) + 8));
      v30 = (void *)(v31.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((v31.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v30);
      if ( result.pKeyInterface )
        result.pKeyInterface->Release(result.pKeyInterface, result.hKeyData);
      if ( v10 )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v10);
      goto LABEL_101;
  }
}
