void __thiscall Scaleform::GFx::AS2::MovieRoot::ProcessLoadMovieClip(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::LoadQueueEntry *p_entry,
        Scaleform::GFx::LoadStates *pls)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  Scaleform::GFx::LoadStates *v5; // edi
  Scaleform::String::DataDesc *LoadFlags; // ecx
  int v7; // ebp
  Scaleform::GFx::LoadQueueEntry *pNext; // ecx
  bool v9; // bl
  Scaleform::GFx::InteractiveObject *v10; // eax
  Scaleform::GFx::InteractiveObject *v11; // edi
  void *v12; // esi
  void *v13; // esi
  void *v14; // esi
  int v15; // eax
  char v16; // al
  int Id; // ecx
  Scaleform::GFx::Sprite *LevelMovie; // eax
  int v19; // eax
  const Scaleform::String *UrlStrGfx; // eax
  void *v21; // ebx
  Scaleform::GFx::MovieDefBindStates *v22; // eax
  Scaleform::Log *Log; // eax
  Scaleform::GFx::MovieImpl *v24; // ecx
  Scaleform::GFx::ImageResource *v25; // eax
  Scaleform::String::DataDesc *v26; // eax
  Scaleform::GFx::MovieDefImpl *ImageMovieDef; // ebx
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v28; // edi
  Scaleform::RefCountNTSImpl *v29; // esi
  int v30; // eax
  Scaleform::GFx::AS2::Environment *v31; // edi
  Scaleform::GFx::AS2::Object *v32; // eax
  Scaleform::RefCountNTSImpl *v33; // ecx
  bool v34; // zf
  Scaleform::GFx::LoadQueueEntryMT *i; // edi
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // eax
  void *v37; // edx
  void *v38; // ecx
  Scaleform::GFx::LoadQueueEntry_vtbl *v39; // eax
  unsigned __int8 *v40; // edi
  Scaleform::GFx::MovieDefImpl *v41; // eax
  Scaleform::RefCountNTSImpl *v42; // edi
  int v43; // ebx
  Scaleform::GFx::ASString *Name; // eax
  Scaleform::GFx::ASStringNode *pData; // eax
  int v46; // eax
  Scaleform::GFx::ASSupport *v47; // ecx
  Scaleform::GFx::MovieImpl *v48; // ecx
  unsigned int Size; // edx
  unsigned int v50; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // edi
  Scaleform::GFx::MovieImpl::LevelInfo *v52; // ecx
  Scaleform::GFx::InteractiveObject *v53; // eax
  Scaleform::GFx::AS2::Environment *v54; // ebx
  Scaleform::GFx::AS2::Object *v55; // eax
  Scaleform::GFx::AS2::Object *v56; // edi
  void (__thiscall *SetValue)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::AS2::Value *); // eax
  Scaleform::RefCountNTSImpl *v58; // edi
  volatile LONG *v59; // [esp+20h] [ebp-A0h]
  Scaleform::GFx::ResourceBinding *v60; // [esp+28h] [ebp-98h]
  Scaleform::GFx::ResourceId v61; // [esp+2Ch] [ebp-94h]
  Scaleform::String url; // [esp+38h] [ebp-88h] BYREF
  Scaleform::GFx::Resource *v63; // [esp+3Ch] [ebp-84h]
  Scaleform::Render::Image *pimage; // [esp+40h] [ebp-80h]
  Scaleform::String filename; // [esp+44h] [ebp-7Ch] BYREF
  Scaleform::String path; // [esp+48h] [ebp-78h] BYREF
  Scaleform::String result; // [esp+4Ch] [ebp-74h] BYREF
  Scaleform::GFx::LogState *pObject; // [esp+50h] [ebp-70h]
  bool v69; // [esp+57h] [ebp-69h]
  Scaleform::RefCountNTSImpl *v70; // [esp+58h] [ebp-68h]
  Scaleform::String v71; // [esp+5Ch] [ebp-64h] BYREF
  unsigned __int8 *pParent; // [esp+60h] [ebp-60h]
  int v73; // [esp+64h] [ebp-5Ch]
  unsigned int FileLength; // [esp+68h] [ebp-58h]
  BOOL v75; // [esp+6Ch] [ebp-54h] BYREF
  _DWORD v76[4]; // [esp+70h] [ebp-50h] BYREF
  Scaleform::Log *v77; // [esp+80h] [ebp-40h]
  Scaleform::String::DataDesc *v78; // [esp+84h] [ebp-3Ch]
  Scaleform::String::DataDesc *v79; // [esp+88h] [ebp-38h]
  Scaleform::GFx::MovieImpl *v80; // [esp+8Ch] [ebp-34h]
  _DWORD v81[3]; // [esp+90h] [ebp-30h] BYREF
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [esp+9Ch] [ebp-24h] BYREF
  Scaleform::GFx::URLBuilder::LocationInfo v83; // [esp+A8h] [ebp-18h] BYREF
  char v84[8]; // [esp+B4h] [ebp-Ch] BYREF
  char v85[4]; // [esp+BCh] [ebp-4h] BYREF

  Scaleform::String::String(&path);
  Scaleform::GFx::AS2::MovieRoot::GetLevel0Path(this, &path);
  Scaleform::String::String(&url, &p_entry->URL);
  Scaleform::String::String(&filename);
  pMovieImpl = this->pMovieImpl;
  v5 = pls;
  LoadFlags = (Scaleform::String::DataDesc *)pMovieImpl->pMainMovieDef.pObject->pBindData.pObject->LoadFlags;
  pObject = pls->pLog.pObject;
  v7 = 0;
  v71.pData = LoadFlags;
  pNext = p_entry[1].pNext;
  v9 = 0;
  v70 = 0;
  pParent = 0;
  v63 = 0;
  if ( !pNext )
  {
    if ( p_entry[1].__vftable == (Scaleform::GFx::LoadQueueEntry_vtbl *)-1 )
      goto LABEL_8;
    if ( Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(this, (int)p_entry[1].__vftable) )
    {
      LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(this, (int)p_entry[1].__vftable);
    }
    else
    {
      if ( !Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(this, 0) )
      {
LABEL_23:
        Scaleform::GFx::MovieImpl::ReleaseLevelMovie(this->pMovieImpl, (int)p_entry[1].__vftable);
        v73 = 0x40000;
        goto LABEL_24;
      }
      LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(this, 0);
    }
    v19 = (int)LevelMovie->GetResourceMovieDef(LevelMovie);
    v9 = ((*(int (__thiscall **)(int))(*(_DWORD *)v19 + 44))(v19) & 0x10) != 0;
    goto LABEL_23;
  }
  v10 = Scaleform::GFx::CharacterHandle::ForceResolveCharacter((Scaleform::GFx::CharacterHandle *)pNext, pMovieImpl);
  v11 = v10;
  if ( v10 )
    ++v10->RefCount;
  v70 = v10;
  if ( v10 )
  {
    pParent = (unsigned __int8 *)v10->pParent;
    if ( !pParent )
    {
      Scaleform::RefCountNTSImpl::Release(v10);
LABEL_8:
      v12 = (void *)(filename.HeapTypeBits & 0xFFFFFFFC);
      v59 = (volatile LONG *)((filename.HeapTypeBits & 0xFFFFFFFC) + 4);
      goto LABEL_9;
    }
    v15 = (int)v10->GetResourceMovieDef(v10);
    v16 = (*(int (__thiscall **)(int))(*(_DWORD *)v15 + 44))(v15);
    Id = v11->Id.Id;
    v5 = pls;
    v9 = (v16 & 0x10) != 0;
    v73 = Id;
LABEL_24:
    FileLength = 0;
    if ( v9 )
    {
      UrlStrGfx = Scaleform::GFx::GetUrlStrGfx(&result, &url);
      Scaleform::String::operator=(&filename, UrlStrGfx);
      v21 = (void *)(result.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((result.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v21);
    }
    if ( Scaleform::String::GetLength(&url) )
    {
      LOBYTE(v75) = 0;
      if ( !Scaleform::GFx::LoaderImpl::IsProtocolImage(&url, (bool *)&v75, 0) )
      {
        v34 = !p_entry->QuietOpen;
        pimage = (Scaleform::Render::Image *)(v71.HeapTypeBits | 0x10001);
        if ( !v34 )
          pimage = (Scaleform::Render::Image *)((unsigned int)&loc_200000 | (unsigned int)pimage);
        if ( !Scaleform::String::GetLength(&filename)
          || (Scaleform::GFx::URLBuilder::LocationInfo::LocationInfo(&loc, File_LoadMovie, &filename, &path),
              ImageMovieDef = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(v5, &loc, (unsigned int)pimage, 0, 0),
              v63 = ImageMovieDef,
              Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&loc),
              !ImageMovieDef) )
        {
          Scaleform::GFx::URLBuilder::LocationInfo::LocationInfo(&v83, File_LoadMovie, &url, &path);
          ImageMovieDef = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(v5, &v83, (unsigned int)pimage, 0, 0);
          v63 = ImageMovieDef;
          Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&v83);
          if ( !ImageMovieDef )
          {
            v28 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)pObject;
            if ( pObject && !p_entry->QuietOpen )
              Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
                &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
                "Failed loading URL \"%s\"",
                (const char *)((url.HeapTypeBits & 0xFFFFFFFC) + 8));
LABEL_39:
            if ( ImageMovieDef )
            {
              if ( ImageMovieDef->GetVersion(ImageMovieDef) != -1
                && ImageMovieDef->GetVersion(ImageMovieDef) >= 9
                && (char)((ImageMovieDef->pBindData.pObject->pDataDef.pObject->pData.pObject->FileAttributes & 8 | 0x10) >> 3) > 2 )
              {
                if ( v28 && !p_entry->QuietOpen )
                  Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
                    v28 + 3,
                    "Failed loading SWF \"%s\": ActionScript version mismatch",
                    (const char *)((url.HeapTypeBits & 0xFFFFFFFC) + 8));
                v29 = v70;
                if ( v70 )
                {
                  v30 = ((int (__thiscall *)(char *))(&v70->__vftable)[BYTE1(v70[8].__vftable)][1].~Scaleform::RefCountNTSImpl)((char *)v70 + 4 * BYTE1(v70[8].__vftable));
                  v31 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v30 + 124))(v30);
                  v32 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&p_entry[1].Type, v31);
                  if ( v32 )
                    ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, Scaleform::RefCountNTSImpl *, const char *, _DWORD))v32->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].SetValue)(
                      v32,
                      v31,
                      v29,
                      "ActionScriptMismatch",
                      0);
                }
                Scaleform::GFx::Resource::Release(ImageMovieDef);
                if ( !v29 )
                  goto LABEL_52;
                v33 = v29;
LABEL_51:
                Scaleform::RefCountNTSImpl::Release(v33);
LABEL_52:
                Scaleform::String::~String(&filename);
                Scaleform::String::~String(&url);
                Scaleform::String::~String(&path);
                return;
              }
              v81[0] = ImageMovieDef->pBindData.pObject->pDataDef.pObject;
              v47 = this->Scaleform::GFx::ASMovieRootBase::pASSupport.pObject;
              v81[2] = 0;
              v81[1] = ImageMovieDef;
              v7 = ((int (__thiscall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, _DWORD *, unsigned __int8 *, int, int))v47->CreateCharacterInstance)(
                     v47,
                     this->pMovieImpl,
                     v81,
                     pParent,
                     v73,
                     3);
              Scaleform::GFx::Sprite::SetLoadedSeparately((Scaleform::GFx::Sprite *)v7, (int)ImageMovieDef, (int)v28, 1);
            }
LABEL_75:
            v39 = p_entry[1].__vftable;
            v69 = v7 != 0;
            if ( v39 == (Scaleform::GFx::LoadQueueEntry_vtbl *)-1 )
            {
              if ( v7
                || (v40 = pParent,
                    v41 = (Scaleform::GFx::MovieDefImpl *)(*(int (__thiscall **)(unsigned __int8 *, char *, int))(*(_DWORD *)pParent + 256))(
                                                            pParent,
                                                            v84,
                                                            65537),
                    Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(v41, v60, v61),
                    (v7 = ((int (__thiscall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, char *, unsigned __int8 *))this->pASSupport.pObject->CreateCharacterInstance)(
                            this->pASSupport.pObject,
                            this->pMovieImpl,
                            v85,
                            v40)) != 0) )
              {
                Scaleform::GFx::InteractiveObject::AddToPlayList((Scaleform::GFx::InteractiveObject *)v7);
                v42 = v70;
                *(Scaleform::RefCountNTSImpl *)(v7 + 24) = v70[3];
                if ( ((int)v42[10].__vftable & 2) == 0 )
                {
                  v43 = *(_DWORD *)v7;
                  Name = Scaleform::GFx::DisplayObject::GetName(
                           (Scaleform::GFx::DisplayObject *)v42,
                           (Scaleform::GFx::ASString *)&result);
                  (*(void (__thiscall **)(int, Scaleform::GFx::ASString *))(v43 + 500))(v7, Name);
                  pData = (Scaleform::GFx::ASStringNode *)result.pData;
                  --result.pData[1].Size;
                  if ( !pData->RefCount )
                    Scaleform::GFx::ASStringNode::ReleaseNode(pData);
                }
                v46 = (int)pParent;
                if ( pParent )
                  v46 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)&pParent[4 * pParent[65]] + 4))(&pParent[4 * pParent[65]]);
                (*(void (__thiscall **)(int, Scaleform::RefCountNTSImpl *, int))(*(_DWORD *)v46 + 116))(v46, v42, v7);
                v42[4].__vftable = 0;
                this->ResolveStickyVariables(this, (Scaleform::GFx::InteractiveObject *)v7);
                Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::Sprite>((Scaleform::GFx::InteractiveObject *)v7);
              }
            }
            else
            {
              if ( v7 )
              {
                Scaleform::GFx::AS2::AvmSprite::SetLevel(
                  (Scaleform::GFx::AS2::AvmSprite *)(v7 + 4 * *(unsigned __int8 *)(v7 + 65)),
                  (int)v39);
                Scaleform::GFx::MovieImpl::SetLevelMovie(
                  this->pMovieImpl,
                  (int)p_entry[1].__vftable,
                  (Scaleform::GFx::DisplayObjContainer *)v7);
                this->pMovieImpl->Flags &= ~0x100u;
                this->ResolveStickyVariables(this, (Scaleform::GFx::InteractiveObject *)v7);
              }
              if ( !Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(this, 0) && v28 )
              {
                Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
                  v28 + 3,
                  "_level0 unloaded - no further playback possible");
                if ( v7 )
                  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v7);
                if ( ImageMovieDef )
                  Scaleform::GFx::Resource::Release(ImageMovieDef);
                v33 = v70;
                if ( !v70 )
                  goto LABEL_52;
                goto LABEL_51;
              }
            }
            v48 = this->pMovieImpl;
            Size = v48->MovieLevels.Data.Size;
            v50 = 0;
            if ( Size )
            {
              Data = v48->MovieLevels.Data.Data;
              v52 = Data;
              while ( v52->Level )
              {
                ++v50;
                ++v52;
                if ( v50 >= Size )
                  goto LABEL_90;
              }
              v53 = Data[v50].pSprite.pObject;
            }
            else
            {
LABEL_90:
              v53 = 0;
            }
            v54 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*((_DWORD *)&v53->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                                   + v53->AvmObjOffset)
                                                                                 + 124))((int)v53 + 4 * v53->AvmObjOffset);
            v55 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&p_entry[1].Type, v54);
            v56 = v55;
            if ( v69 )
            {
              if ( v55 )
              {
                v55->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].ExecuteForEachChild_GC(
                  v55,
                  (Scaleform::GFx::AS2::RefCountCollector<323> *)v54,
                  (Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC)v7);
                ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, int, unsigned int, unsigned int))v56->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].GetValue)(
                  v56,
                  v54,
                  v7,
                  FileLength,
                  FileLength);
                ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, int, _DWORD))v56->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].Finalize_GC)(
                  v56,
                  v54,
                  v7,
                  0);
              }
              (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 440))(v7);
              this->DoActions(this);
              if ( v56 )
                ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, int))v56->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].~Scaleform::GFx::AS2::Object)(
                  v56,
                  v54,
                  v7);
            }
            else if ( v55 )
            {
              v34 = Scaleform::String::GetLength(&url) == 0;
              SetValue = v56->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].SetValue;
              if ( v34 )
                ((void (__stdcall *)(Scaleform::GFx::AS2::Environment *, int, const char *, _DWORD))SetValue)(
                  v54,
                  v7,
                  "Unknown error",
                  0);
              else
                ((void (__stdcall *)(Scaleform::GFx::AS2::Environment *, int, const char *, _DWORD))SetValue)(
                  v54,
                  v7,
                  "URLNotFound",
                  0);
            }
            if ( Scaleform::String::GetLength(&url) )
            {
              v58 = v70;
            }
            else
            {
              if ( v70 )
                Scaleform::RefCountNTSImpl::Release(v70);
              v58 = 0;
              Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit::Collect(
                &this->MemContext.pObject->LimHandler,
                this->pMovieImpl->pHeap);
            }
            if ( v7 )
              Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v7);
            if ( v63 )
              Scaleform::GFx::Resource::Release(v63);
            if ( v58 )
              Scaleform::RefCountNTSImpl::Release(v58);
            v12 = (void *)(filename.HeapTypeBits & 0xFFFFFFFC);
            v59 = (volatile LONG *)((filename.HeapTypeBits & 0xFFFFFFFC) + 4);
            goto LABEL_9;
          }
        }
        FileLength = ImageMovieDef->pBindData.pObject->pDataDef.pObject->pData.pObject->Header.FileLength;
LABEL_38:
        v28 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)pObject;
        goto LABEL_39;
      }
      pimage = (Scaleform::Render::Image *)Scaleform::GFx::LoadStates::GetImageCreator(v5);
      if ( pimage )
      {
        v76[1] = this->pMovieImpl->pHeap;
        v76[2] = 1;
        v76[3] = 1;
        v71.pData = (Scaleform::String::DataDesc *)v5->pImageFileHandlerRegistry.pObject;
        v22 = v5->pBindStates.pObject;
        v76[0] = 0;
        v77 = 0;
        v78 = 0;
        v79 = 0;
        v80 = 0;
        result.pData = (Scaleform::String::DataDesc *)v22->pFileOpener.pObject;
        Log = Scaleform::GFx::LoadStates::GetLog(v5);
        v24 = this->pMovieImpl;
        v77 = Log;
        v79 = v71.pData;
        v80 = v24;
        v78 = result.pData;
        Scaleform::String::String(&v71, (const __m128i *)((url.HeapTypeBits & 0xFFFFFFFC) + 8));
        pimage = (Scaleform::Render::Image *)((int (__thiscall *)(Scaleform::Render::Image *, _DWORD *, Scaleform::String *))pimage->AddRef)(
                                               pimage,
                                               v76,
                                               &v71);
        Scaleform::String::~String(&v71);
        if ( pimage )
        {
          v25 = (Scaleform::GFx::ImageResource *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 52, 0);
          if ( v25 && (Scaleform::GFx::ImageResource::ImageResource(v25, pimage, Use_Bitmap), (result.pData = v26) != 0) )
          {
            ImageMovieDef = Scaleform::GFx::MovieImpl::CreateImageMovieDef(
                              this->pMovieImpl,
                              (Scaleform::GFx::ImageResource *)result.pData,
                              v75,
                              (char *)((url.HeapTypeBits & 0xFFFFFFFC) + 8),
                              (Scaleform::Log *)v5);
            v63 = ImageMovieDef;
            Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)result.pData);
          }
          else
          {
            ImageMovieDef = 0;
          }
          pimage->Release(pimage);
          goto LABEL_38;
        }
        v28 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)pObject;
        if ( pObject )
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
            &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
            "ImageCreator::LoadProtocolImage failed to load image \"%s\"",
            (const char *)((url.HeapTypeBits & 0xFFFFFFFC) + 8));
      }
      else
      {
        v28 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)pObject;
        if ( pObject )
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
            &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
            "ImageCreator is not installed,failed to load image \"%s\"",
            (const char *)((url.HeapTypeBits & 0xFFFFFFFC) + 8));
      }
    }
    else
    {
      for ( i = this->pMovieImpl->pLoadQueueMTHead; i; i = i->pNext )
      {
        pQueueEntry = i->pQueueEntry;
        if ( pQueueEntry->EntryTime < p_entry->EntryTime )
        {
          if ( (v37 = p_entry[1].__vftable, v37 != (void *)-1) && (v38 = pQueueEntry[1].__vftable, v38 != (void *)-1)
            || (v37 = p_entry[1].pNext) != 0 && (v38 = pQueueEntry[1].pNext) != 0 )
          {
            if ( v37 == v38 )
              pQueueEntry->Canceled = 1;
          }
        }
      }
      v28 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)pObject;
    }
    ImageMovieDef = 0;
    goto LABEL_75;
  }
  v12 = (void *)(filename.HeapTypeBits & 0xFFFFFFFC);
  v59 = (volatile LONG *)((filename.HeapTypeBits & 0xFFFFFFFC) + 4);
LABEL_9:
  if ( InterlockedExchangeAdd(v59, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v12);
  v13 = (void *)(url.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((url.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
  v14 = (void *)(path.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((path.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
}
