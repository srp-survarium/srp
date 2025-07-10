void __thiscall Scaleform::GFx::AS3::MovieRoot::ProcessLoadQueueEntry(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::LoadQueueEntry *pentry,
        Scaleform::GFx::LoadStates *pls)
{
  Scaleform::File *v4; // esi
  void *v5; // esi
  void *v6; // esi
  bool IsLoadingText; // al
  Scaleform::GFx::LoadQueueEntry *pNext; // ecx
  void *v9; // esi
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  Scaleform::GFx::MovieDefImpl::BindTaskData *pObject; // ecx
  Scaleform::GFx::InteractiveObject *pMainMovie; // eax
  Scaleform::GFx::Resource *LoadFlags; // ecx
  Scaleform::GFx::MovieDefImpl *Movie_LoadState; // ebp
  Scaleform::GFx::MovieDefImpl *v15; // eax
  const Scaleform::String *v16; // eax
  Scaleform::String::DataDesc *v17; // edx
  Scaleform::Log *v18; // ecx
  Scaleform::GFx::MovieDefBindStates *v19; // eax
  Scaleform::GFx::LogState *v20; // eax
  Scaleform::Log *GlobalLog; // eax
  Scaleform::GFx::ImageResource *v22; // eax
  Scaleform::GFx::AS3::AvmSprite *v23; // eax
  unsigned int v24; // ecx
  Scaleform::GFx::AS3::AvmDisplayObj *v25; // esi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v26; // eax
  Scaleform::GFx::ASSupport *v27; // ecx
  Scaleform::GFx::AS3::AvmBitmap *v28; // edi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v29; // eax
  Scaleform::GFx::Resource *Resource; // eax
  unsigned int v31; // ecx
  int v32; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v33; // ecx
  bool v34; // zf
  const Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Method; // eax
  unsigned int EntryTime; // ebx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v38; // ecx
  Scaleform::GFx::Sprite *v39; // esi
  Scaleform::RefCountNTSImpl *v40; // ecx
  Scaleform::GFx::AS3::ASVM *v41; // eax
  Scaleform::GFx::ASSupport *v42; // ecx
  Scaleform::GFx::MovieDataDef *v43; // edx
  void (__thiscall *OnEventLoad)(Scaleform::GFx::DisplayObjectBase *); // eax
  Scaleform::GFx::LoadQueueEntry_vtbl *v45; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *ContentLoaderInfo; // eax
  Scaleform::GFx::AS3::VMAppDomain *CursorPos; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v48; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v49; // ecx
  int v50; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v51; // ecx
  Scaleform::GFx::Resource *v52; // ecx
  unsigned int v53; // ecx
  void *v54; // esi
  void *v55; // esi
  unsigned int v56; // ebx
  char v57; // [esp+34h] [ebp-48Ch]
  char v58; // [esp+47h] [ebp-479h]
  char IsProtocolImage; // [esp+47h] [ebp-479h]
  Scaleform::GFx::AS3::AvmSprite *avmSpr; // [esp+48h] [ebp-478h] BYREF
  Scaleform::String url; // [esp+4Ch] [ebp-474h] BYREF
  unsigned int lf; // [esp+50h] [ebp-470h] BYREF
  Scaleform::String rootPath; // [esp+54h] [ebp-46Ch] BYREF
  Scaleform::String urlStrGfx; // [esp+58h] [ebp-468h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> appDomain; // [esp+5Ch] [ebp-464h] BYREF
  Scaleform::GFx::Resource *v66; // [esp+60h] [ebp-460h]
  int v67; // [esp+64h] [ebp-45Ch]
  Scaleform::GFx::Resource *pres; // [esp+68h] [ebp-458h]
  Scaleform::GFx::CharacterCreateInfo ccinfo; // [esp+6Ch] [ebp-454h] BYREF
  BOOL bilinearImage; // [esp+78h] [ebp-448h] BYREF
  Scaleform::GFx::ImageCreateInfo icinfo; // [esp+7Ch] [ebp-444h] BYREF
  _DWORD v72[3]; // [esp+9Ch] [ebp-424h] BYREF
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [esp+A8h] [ebp-418h] BYREF
  Scaleform::GFx::URLBuilder::LocationInfo v74; // [esp+B4h] [ebp-40Ch] BYREF
  char buf[1024]; // [esp+C0h] [ebp-400h] BYREF

  if ( pentry->Canceled )
    return;
  if ( (pentry->Type & 0x24) != 0 )
  {
    v58 = 0;
    Scaleform::String::String(&urlStrGfx);
    appDomain.pObject = 0;
    v66 = 0;
    v67 = 0;
    avmSpr = 0;
    Scaleform::String::String(&rootPath);
    Scaleform::GFx::AS3::MovieRoot::GetRootFilePath(this, &rootPath);
    ccinfo.pCharDef = (Scaleform::GFx::CharacterDef *)4;
    Scaleform::String::String((Scaleform::String *)&ccinfo.pBindDefImpl, &pentry->URL);
    Scaleform::String::String((Scaleform::String *)&ccinfo.pResource, &rootPath);
    Scaleform::String::String((Scaleform::String *)&lf);
    Scaleform::GFx::LoadStates::BuildURL(
      pls,
      (Scaleform::String *)&lf,
      (const Scaleform::GFx::URLBuilder::LocationInfo *)&ccinfo);
    v4 = Scaleform::GFx::LoadStates::OpenFile(pls, (const char *)((lf & 0xFFFFFFFC) + 8), 0);
    if ( v4 )
    {
      if ( Scaleform::GFx::AS3::Instances::fl_net::URLLoader::IsLoadingVariables((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext) )
      {
        Scaleform::GFx::MovieImpl::ReadTextData((int)v4, &urlStrGfx, (Scaleform::String)v4, (int *)&avmSpr, 1, v57);
      }
      else if ( Scaleform::GFx::AS3::Instances::fl_net::URLLoader::IsLoadingText((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext) )
      {
        Scaleform::GFx::MovieImpl::ReadTextData((int)v4, &urlStrGfx, (Scaleform::String)v4, (int *)&avmSpr, 0, v57);
      }
      else if ( Scaleform::GFx::AS3::Instances::fl_net::URLLoader::IsLoadingBinary((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext) )
      {
        Scaleform::GFx::MovieImpl::ReadBinaryData(
          (Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)&appDomain,
          v4,
          (int *)&avmSpr);
      }
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v4);
    }
    else
    {
      Scaleform::SFsprintf(buf, 0x400u, "Can't open %s", (const char *)((lf & 0xFFFFFFFC) + 8));
      Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
        (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext,
        buf);
      v58 = 1;
    }
    v5 = (void *)(lf & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((lf & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
    Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo((Scaleform::GFx::URLBuilder::LocationInfo *)&ccinfo);
    v6 = (void *)(rootPath.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((rootPath.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
    if ( !v58 )
    {
      if ( Scaleform::GFx::AS3::Instances::fl_net::URLLoader::IsLoadingVariables((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext) )
      {
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetVariablesDataString(
          (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext,
          (char *)((urlStrGfx.HeapTypeBits & 0xFFFFFFFC) + 8));
      }
      else
      {
        IsLoadingText = Scaleform::GFx::AS3::Instances::fl_net::URLLoader::IsLoadingText((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext);
        pNext = pentry[1].pNext;
        if ( IsLoadingText )
        {
          Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetTextString(
            (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pNext,
            (char *)((urlStrGfx.HeapTypeBits & 0xFFFFFFFC) + 8));
        }
        else if ( Scaleform::GFx::AS3::Instances::fl_net::URLLoader::IsLoadingBinary((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pNext) )
        {
          Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetBinaryData(
            (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext,
            (const Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)&appDomain);
        }
      }
      Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteOpenEvent((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext);
      Scaleform::GFx::AS3::Instances::fl_net::URLLoader::ExecuteProgressEvent(
        (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext,
        (unsigned int)avmSpr,
        (unsigned int)avmSpr);
      Scaleform::GFx::AS3::Instances::fl_net::URLLoader::ExecuteCompleteEvent((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext);
    }
    if ( appDomain.pObject )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, appDomain.pObject);
    v9 = (void *)(urlStrGfx.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((urlStrGfx.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
    return;
  }
  Scaleform::String::String(&url, &pentry->URL);
  Scaleform::String::String(&urlStrGfx);
  pMovieImpl = this->pMovieImpl;
  pObject = pMovieImpl->pMainMovieDef.pObject->pBindData.pObject;
  pMainMovie = pMovieImpl->pMainMovie;
  LoadFlags = (Scaleform::GFx::Resource *)pObject->LoadFlags;
  Movie_LoadState = 0;
  avmSpr = (Scaleform::GFx::AS3::AvmSprite *)pls->pLog.pObject;
  pres = LoadFlags;
  if ( pMainMovie )
  {
    v15 = this->pMovieImpl->pMainMovie->GetResourceMovieDef(this->pMovieImpl->pMainMovie);
    if ( (v15->GetSWFFlags(v15) & 0x10) != 0 )
    {
      v16 = Scaleform::GFx::GetUrlStrGfx((Scaleform::String *)&appDomain, &url);
      Scaleform::String::operator=(&urlStrGfx, v16);
      rootPath.pData = (Scaleform::String::DataDesc *)((unsigned int)appDomain.pObject & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)appDomain.pObject & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, rootPath.pData);
    }
  }
  LOBYTE(bilinearImage) = 0;
  IsProtocolImage = Scaleform::GFx::LoaderImpl::IsProtocolImage(&url, (bool *)&bilinearImage, 0);
  if ( !IsProtocolImage )
  {
    v34 = !pentry->QuietOpen;
    lf = (unsigned int)pres | 0x10001;
    if ( !v34 )
      lf |= 0x200000u;
    Method = (const Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)pentry[1].Method;
    if ( Method )
    {
      Movie_LoadState = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(pls, Method, lf, 0, 0);
    }
    else
    {
      Scaleform::String::String(&rootPath);
      Scaleform::GFx::AS3::MovieRoot::GetRootFilePath(this, &rootPath);
      if ( !Scaleform::String::GetLength(&urlStrGfx)
        || (Scaleform::GFx::URLBuilder::LocationInfo::LocationInfo(&loc, File_LoadMovie, &urlStrGfx, &rootPath),
            Movie_LoadState = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(pls, &loc, lf, 0, 0),
            Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&loc),
            !Movie_LoadState) )
      {
        Scaleform::GFx::URLBuilder::LocationInfo::LocationInfo(&v74, File_LoadMovie, &url, &rootPath);
        Movie_LoadState = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(pls, &v74, lf, 0, 0);
        Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&v74);
      }
      Scaleform::String::~String(&rootPath);
    }
    if ( Movie_LoadState )
    {
      if ( Movie_LoadState->GetVersion(Movie_LoadState) == -1
        || Movie_LoadState->GetVersion(Movie_LoadState) >= 9
        && (char)((Movie_LoadState->pBindData.pObject->pDataDef.pObject->pData.pObject->FileAttributes & 8 | 0x10) >> 3) >= 3 )
      {
LABEL_43:
        if ( Movie_LoadState )
          Scaleform::GFx::AS3::MovieRoot::AddLoadedMovieDef(this, Movie_LoadState);
        goto LABEL_45;
      }
      if ( avmSpr && !pentry->QuietOpen )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
          (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&avmSpr->pDispObj,
          "Failed loading SWF \"%s\": ActionScript version mismatch",
          (const char *)((url.HeapTypeBits & 0xFFFFFFFC) + 8));
      Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteErrorEvent(
        (Scaleform::GFx::AS3::Instances::fl_display::Loader *)pentry[1].__vftable,
        (const char *)((url.HeapTypeBits & 0xFFFFFFFC) + 8));
      EntryTime = pentry[1].EntryTime;
      if ( EntryTime )
        (*(void (__thiscall **)(unsigned int))(*(_DWORD *)EntryTime + 12))(EntryTime);
      Scaleform::GFx::Resource::Release(Movie_LoadState);
    }
    else
    {
      if ( avmSpr && !pentry->QuietOpen )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
          (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&avmSpr->pDispObj,
          "Failed loading URL \"%s\"",
          (const char *)((url.HeapTypeBits & 0xFFFFFFFC) + 8));
      Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteErrorEvent(
        (Scaleform::GFx::AS3::Instances::fl_display::Loader *)pentry[1].__vftable,
        (const char *)((url.HeapTypeBits & 0xFFFFFFFC) + 8));
      v56 = pentry[1].EntryTime;
      if ( v56 )
        (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v56 + 12))(v56);
    }
LABEL_139:
    Scaleform::String::~String(&urlStrGfx);
    Scaleform::String::~String(&url);
    return;
  }
  pres = (Scaleform::GFx::Resource *)Scaleform::GFx::LoadStates::GetImageCreator(pls);
  if ( pres )
  {
    v17 = (Scaleform::String::DataDesc *)pls->pImageFileHandlerRegistry.pObject;
    icinfo.pHeap = this->pMovieImpl->pHeap;
    v18 = 0;
    icinfo.Use = 1;
    icinfo.RUse = Use_Bitmap;
    v19 = pls->pBindStates.pObject;
    icinfo.Type = Create_Protocol;
    memset(&icinfo.pLog, 0, 16);
    appDomain.pObject = (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)v19->pFileOpener.pObject;
    v20 = pls->pLog.pObject;
    rootPath.pData = v17;
    if ( v20 )
    {
      GlobalLog = v20->pLog.pObject;
      if ( !GlobalLog )
        GlobalLog = Scaleform::Log::GetGlobalLog();
      v18 = GlobalLog;
    }
    icinfo.pIFHRegistry = (Scaleform::GFx::ImageFileHandlerRegistry *)rootPath.pData;
    icinfo.pLog = v18;
    icinfo.pMovie = this->pMovieImpl;
    icinfo.pFileOpener = (Scaleform::GFx::FileOpener *)appDomain.pObject;
    Scaleform::String::String((Scaleform::String *)&lf, (char *)((url.HeapTypeBits & 0xFFFFFFFC) + 8));
    rootPath.pData = (Scaleform::String::DataDesc *)((int (__thiscall *)(Scaleform::GFx::Resource *, Scaleform::GFx::ImageCreateInfo *, unsigned int *))pres->GetKey)(
                                                      pres,
                                                      &icinfo,
                                                      &lf);
    Scaleform::String::~String((Scaleform::String *)&lf);
    if ( rootPath.pData )
    {
      v22 = (Scaleform::GFx::ImageResource *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 52, 0);
      if ( v22 )
      {
        Scaleform::GFx::ImageResource::ImageResource(v22, (Scaleform::Render::Image *)rootPath.pData, Use_Bitmap);
        avmSpr = v23;
        if ( v23 )
        {
          Movie_LoadState = Scaleform::GFx::MovieImpl::CreateImageMovieDef(
                              this->pMovieImpl,
                              (Scaleform::GFx::ImageResource *)avmSpr,
                              bilinearImage,
                              (const char *)((url.HeapTypeBits & 0xFFFFFFFC) + 8),
                              pls);
          Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)avmSpr);
        }
      }
      (*(void (__thiscall **)(Scaleform::String::DataDesc *))(*(_DWORD *)rootPath.HeapTypeBits + 8))(rootPath.pData);
      goto LABEL_43;
    }
    if ( !avmSpr )
      goto LABEL_45;
    Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
      (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&avmSpr->pDispObj,
      "ImageCreator::LoadProtocolImage failed to load image \"%s\"",
      (const char *)((url.HeapTypeBits & 0xFFFFFFFC) + 8));
    Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteErrorEvent(
      (Scaleform::GFx::AS3::Instances::fl_display::Loader *)pentry[1].__vftable,
      (const char *)((url.HeapTypeBits & 0xFFFFFFFC) + 8));
    goto LABEL_139;
  }
  if ( avmSpr )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
      (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&avmSpr->pDispObj,
      "ImageCreator is not installed, failed to load image \"%s\"",
      (const char *)((url.HeapTypeBits & 0xFFFFFFFC) + 8));
    Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteErrorEvent(
      (Scaleform::GFx::AS3::Instances::fl_display::Loader *)pentry[1].__vftable,
      (const char *)((url.HeapTypeBits & 0xFFFFFFFC) + 8));
  }
LABEL_45:
  Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteOpenEvent((Scaleform::GFx::AS3::Instances::fl_display::Loader *)pentry[1].__vftable);
  v24 = pentry[1].EntryTime;
  v25 = 0;
  if ( v24 )
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v24 + 4))(v24);
  lf = (unsigned int)pentry[1].__vftable[12].~Scaleform::GFx::LoadQueueEntry;
  if ( Movie_LoadState && (v26 = Movie_LoadState->pBindData.pObject, v26->pDataDef.pObject->MovieType == MT_Image) )
  {
    ccinfo.pCharDef = v26->pDataDef.pObject;
    v27 = this->pASSupport.pObject;
    ccinfo.pBindDefImpl = Movie_LoadState;
    ccinfo.pResource = 0;
    v28 = (Scaleform::GFx::AS3::AvmBitmap *)((int (__thiscall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::CharacterCreateInfo *, _DWORD, int, int))v27->CreateCharacterInstance)(
                                              v27,
                                              this->pMovieImpl,
                                              &ccinfo,
                                              0,
                                              0x40000,
                                              8);
    v29 = Movie_LoadState->pBindData.pObject;
    appDomain.pObject = 0;
    v66 = 0;
    if ( Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
           v29->pDataDef.pObject->pData.pObject,
           (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType *)&appDomain,
           0) )
    {
      Resource = Scaleform::GFx::ResourceHandle::GetResource(
                   (Scaleform::GFx::ResourceHandle *)&appDomain,
                   &Movie_LoadState->pBindData.pObject->ResourceBinding);
      pres = Resource;
      if ( Resource )
      {
        if ( (Resource->GetResourceTypeCode(Resource) & 0xFF00) == 0x100 )
          Scaleform::GFx::AS3::AvmBitmap::SetImage(v28, (Scaleform::GFx::ImageResource *)pres);
      }
    }
    if ( lf
      && (v31 = lf + 4 * *(unsigned __int8 *)(lf + 65),
          (v32 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v31 + 20))(v31)) != 0) )
    {
      v33 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v32 - 36);
    }
    else
    {
      v33 = 0;
    }
    Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChild(v33, (Scaleform::GFx::InteractiveObject *)v28);
    if ( v28 )
      v25 = (Scaleform::GFx::AS3::AvmDisplayObj *)(&v28->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                 + v28->AvmObjOffset);
    if ( !Scaleform::GFx::AS3::AvmDisplayObj::HasAS3Obj(v25)
      && Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor(v25, (int)Movie_LoadState, (int)v28) )
    {
      pAS3RawPtr = v25->pAS3RawPtr;
      if ( !pAS3RawPtr )
        pAS3RawPtr = v25->pAS3CollectiblePtr.pObject;
      v38 = pAS3RawPtr;
      if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
        v38 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
      Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::SetLoaderInfo(
        v38,
        (const Scaleform::GFx::AS3::Instances::fl_display::Loader *)pentry[1].__vftable);
      Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(v25, 1);
    }
    if ( v28 )
      ++v28->RefCount;
    v39 = (Scaleform::GFx::Sprite *)v28;
    if ( !appDomain.pObject && v66 )
      Scaleform::GFx::Resource::Release(v66);
    if ( !v28 )
      goto LABEL_119;
    v40 = v28;
  }
  else
  {
    v39 = 0;
    if ( Movie_LoadState )
    {
      v41 = this->pAVM.pObject;
      if ( v41 )
        Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(
          v41->GC.GC,
          (Scaleform::GFx::Resource *)this->pMovieImpl->AdvanceStats.pObject,
          0);
      Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteProgressEvent(
        (Scaleform::GFx::AS3::Instances::fl_display::Loader *)pentry[1].__vftable,
        Movie_LoadState->pBindData.pObject->pDataDef.pObject->pData.pObject->Header.FileLength,
        Movie_LoadState->pBindData.pObject->pDataDef.pObject->pData.pObject->Header.FileLength);
      v42 = this->pASSupport.pObject;
      v43 = Movie_LoadState->pBindData.pObject->pDataDef.pObject;
      v72[2] = 0;
      v72[0] = v43;
      v72[1] = Movie_LoadState;
      v39 = (Scaleform::GFx::Sprite *)((int (__thiscall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, _DWORD *, _DWORD, _DWORD, int))v42->CreateCharacterInstance)(
                                        v42,
                                        this->pMovieImpl,
                                        v72,
                                        0,
                                        0,
                                        3);
      Scaleform::GFx::Sprite::SetLoadedSeparately(v39, (int)pentry, (int)this, 1);
      OnEventLoad = v39->OnEventLoad;
      v39->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Flags |= 1u;
      OnEventLoad(v39);
      Scaleform::GFx::InteractiveObject::AddToPlayList(v39);
      v45 = pentry[1].__vftable;
      avmSpr = (Scaleform::GFx::AS3::AvmSprite *)(&v39->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                + v39->AvmObjOffset);
      if ( v45 )
      {
        ContentLoaderInfo = Scaleform::GFx::AS3::Instances::fl_display::Loader::GetContentLoaderInfo((Scaleform::GFx::AS3::Instances::fl_display::Loader *)v45);
        if ( ContentLoaderInfo )
        {
          Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::applicationDomainGet(ContentLoaderInfo, &appDomain);
          if ( appDomain.pObject )
          {
            CursorPos = Scaleform::GFx::Text::EditorKit::GetCursorPos(appDomain.pObject);
            Scaleform::GFx::AS3::AvmDisplayObj::SetAppDomain(avmSpr, CursorPos);
          }
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&appDomain);
        }
      }
      avmSpr->ExecuteInitActionFrameTags(avmSpr, 0);
      ((void (__thiscall *)(Scaleform::GFx::Sprite *, _DWORD, _DWORD))v39->SetFOV)(
        v39,
        COERCE_UNSIGNED_INT64(55.0),
        HIDWORD(COERCE_UNSIGNED_INT64(55.0)));
      if ( !avmSpr->pAS3RawPtr
        && !avmSpr->pAS3CollectiblePtr.pObject
        && Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor(avmSpr, (int)Movie_LoadState, (int)this) )
      {
        v48 = avmSpr->pAS3RawPtr;
        if ( !v48 )
          v48 = avmSpr->pAS3CollectiblePtr.pObject;
        v49 = v48;
        if ( ((unsigned __int8)v48 & 1) != 0 )
          v49 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v48 - 1);
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::SetLoaderInfo(
          v49,
          (const Scaleform::GFx::AS3::Instances::fl_display::Loader *)pentry[1].__vftable);
        Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(avmSpr, 1);
      }
      if ( lf
        && (v50 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)(lf + 4 * *(unsigned __int8 *)(lf + 65)) + 20))(lf + 4 * *(unsigned __int8 *)(lf + 65))) != 0 )
      {
        v51 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v50 - 36);
      }
      else
      {
        v51 = 0;
      }
      Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChild(v51, v39);
      this->ResolveStickyVariables(this, v39);
      Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::Sprite>(v39);
      this->DoActions(this);
      ++v39->RefCount;
    }
    if ( !v39 )
      goto LABEL_119;
    v40 = v39;
  }
  Scaleform::RefCountNTSImpl::Release(v40);
LABEL_119:
  if ( IsProtocolImage )
  {
    Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteInitEvent(
      (Scaleform::GFx::AS3::Instances::fl_display::Loader *)pentry[1].__vftable,
      v39);
    v53 = pentry[1].EntryTime;
    if ( v53 )
      (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v53 + 8))(v53);
    Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteCompleteEvent((Scaleform::GFx::AS3::Instances::fl_display::Loader *)pentry[1].__vftable);
  }
  else
  {
    v52 = (Scaleform::GFx::Resource *)pentry[1].EntryTime;
    if ( v52 )
      Scaleform::RefCountImpl::AddRef(v52);
    Scaleform::GFx::AS3::Instances::fl_display::Loader::QueueInitEvent(
      (Scaleform::GFx::AS3::Instances::fl_display::Loader *)pentry[1].__vftable,
      v39,
      (Scaleform::Ptr<Scaleform::GFx::AS3::NotifyLoadInitC>)pentry[1].EntryTime);
    Scaleform::GFx::AS3::Instances::fl_display::Loader::QueueCompleteEvent((Scaleform::GFx::AS3::Instances::fl_display::Loader *)pentry[1].__vftable);
  }
  if ( v39 )
    Scaleform::RefCountNTSImpl::Release(v39);
  if ( Movie_LoadState )
    Scaleform::GFx::Resource::Release(Movie_LoadState);
  v54 = (void *)(urlStrGfx.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((urlStrGfx.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v54);
  v55 = (void *)(url.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((url.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v55);
}
