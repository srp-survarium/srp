void __thiscall Scaleform::GFx::AS2::MovieRoot::ProcessLoadMovieClip(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::LoadQueueEntry *p_entry,
        Scaleform::GFx::LoadStates *pls)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  Scaleform::GFx::LoadStates *v5; // edi
  unsigned int v6; // ecx
  Scaleform::GFx::Sprite *v7; // ebp
  Scaleform::GFx::LoadQueueEntry *pNext; // ecx
  bool v9; // bl
  Scaleform::GFx::InteractiveObject *v10; // eax
  Scaleform::GFx::InteractiveObject *v11; // edi
  void *v12; // esi
  void *v13; // esi
  void *v14; // esi
  int v15; // eax
  char v16; // al
  unsigned int Id; // ecx
  Scaleform::GFx::Sprite *LevelMovie; // eax
  int v19; // eax
  const Scaleform::String *v20; // eax
  void *v21; // ebx
  Scaleform::GFx::MovieDefBindStates *v22; // eax
  Scaleform::Log *Log; // eax
  Scaleform::GFx::MovieImpl *v24; // ecx
  Scaleform::GFx::ImageResource *v25; // eax
  Scaleform::String::DataDesc *v26; // eax
  Scaleform::GFx::MovieDefImpl *ImageMovieDef; // ebx
  Scaleform::GFx::LogState *v28; // edi
  Scaleform::GFx::InteractiveObject *pObject; // esi
  int v30; // eax
  Scaleform::GFx::AS2::Environment *v31; // edi
  Scaleform::GFx::AS2::Object *v32; // eax
  Scaleform::GFx::InteractiveObject *v33; // ecx
  bool v34; // zf
  Scaleform::GFx::LoadQueueEntryMT *i; // edi
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // eax
  void *v37; // edx
  void *v38; // ecx
  Scaleform::GFx::LoadQueueEntry_vtbl *v39; // eax
  Scaleform::GFx::InteractiveObject *v40; // edi
  Scaleform::GFx::MovieDefImpl *v41; // eax
  Scaleform::GFx::InteractiveObject *v42; // edi
  Scaleform::GFx::Sprite_vtbl *v43; // ebx
  Scaleform::GFx::ASString *Name; // eax
  Scaleform::GFx::ASStringNode *pData; // eax
  Scaleform::GFx::InteractiveObject *v46; // eax
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
  Scaleform::GFx::InteractiveObject *v58; // edi
  volatile LONG *v59; // [esp+20h] [ebp-A0h]
  Scaleform::GFx::ResourceBinding *v60; // [esp+28h] [ebp-98h]
  Scaleform::GFx::ResourceId v61; // [esp+2Ch] [ebp-94h]
  Scaleform::String url; // [esp+38h] [ebp-88h] BYREF
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> pmovieDef; // [esp+3Ch] [ebp-84h]
  unsigned int lf; // [esp+40h] [ebp-80h]
  Scaleform::String urlStrGfx; // [esp+44h] [ebp-7Ch] BYREF
  Scaleform::String level0Path; // [esp+48h] [ebp-78h] BYREF
  Scaleform::String result; // [esp+4Ch] [ebp-74h] BYREF
  Scaleform::GFx::LogState *plog; // [esp+50h] [ebp-70h]
  bool charIsLoadedSuccessfully; // [esp+57h] [ebp-69h]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> poldChar; // [esp+58h] [ebp-68h]
  unsigned int loadFlags; // [esp+5Ch] [ebp-64h] BYREF
  Scaleform::GFx::InteractiveObject *pparent; // [esp+60h] [ebp-60h]
  Scaleform::GFx::ResourceId newCharId; // [esp+64h] [ebp-5Ch]
  int filelength; // [esp+68h] [ebp-58h]
  BOOL bilinearImage; // [esp+6Ch] [ebp-54h] BYREF
  Scaleform::GFx::ImageCreateInfo icinfo; // [esp+70h] [ebp-50h] BYREF
  Scaleform::GFx::CharacterCreateInfo ccinfo; // [esp+90h] [ebp-30h] BYREF
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [esp+9Ch] [ebp-24h] BYREF
  Scaleform::GFx::URLBuilder::LocationInfo v79; // [esp+A8h] [ebp-18h] BYREF
  char v80[8]; // [esp+B4h] [ebp-Ch] BYREF
  char v81[4]; // [esp+BCh] [ebp-4h] BYREF

  Scaleform::String::String(&level0Path);
  Scaleform::GFx::AS2::MovieRoot::GetLevel0Path(this, &level0Path);
  Scaleform::String::String(&url, &p_entry->URL);
  Scaleform::String::String(&urlStrGfx);
  pMovieImpl = this->pMovieImpl;
  v5 = pls;
  v6 = pMovieImpl->pMainMovieDef.pObject->pBindData.pObject->LoadFlags;
  plog = pls->pLog.pObject;
  v7 = 0;
  loadFlags = v6;
  pNext = p_entry[1].pNext;
  v9 = 0;
  poldChar.pObject = 0;
  pparent = 0;
  pmovieDef.pObject = 0;
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
        newCharId.Id = 0x40000;
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
  poldChar.pObject = v10;
  if ( v10 )
  {
    pparent = v10->pParent;
    if ( !pparent )
    {
      Scaleform::RefCountNTSImpl::Release(v10);
LABEL_8:
      v12 = (void *)(urlStrGfx.HeapTypeBits & 0xFFFFFFFC);
      v59 = (volatile LONG *)((urlStrGfx.HeapTypeBits & 0xFFFFFFFC) + 4);
      goto LABEL_9;
    }
    v15 = (int)v10->GetResourceMovieDef(v10);
    v16 = (*(int (__thiscall **)(int))(*(_DWORD *)v15 + 44))(v15);
    Id = v11->Id.Id;
    v5 = pls;
    v9 = (v16 & 0x10) != 0;
    newCharId.Id = Id;
LABEL_24:
    filelength = 0;
    if ( v9 )
    {
      v20 = Scaleform::GFx::GetUrlStrGfx(&result, &url);
      Scaleform::String::operator=(&urlStrGfx, v20);
      v21 = (void *)(result.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((result.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v21);
    }
    if ( Scaleform::String::GetLength(&url) )
    {
      LOBYTE(bilinearImage) = 0;
      if ( !Scaleform::GFx::LoaderImpl::IsProtocolImage(&url, (bool *)&bilinearImage, 0) )
      {
        v34 = !p_entry->QuietOpen;
        lf = loadFlags | 0x10001;
        if ( !v34 )
          lf |= 0x200000u;
        if ( !Scaleform::String::GetLength(&urlStrGfx)
          || (Scaleform::GFx::URLBuilder::LocationInfo::LocationInfo(&loc, File_LoadMovie, &urlStrGfx, &level0Path),
              ImageMovieDef = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(v5, &loc, lf, 0, 0),
              pmovieDef.pObject = ImageMovieDef,
              Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&loc),
              !ImageMovieDef) )
        {
          Scaleform::GFx::URLBuilder::LocationInfo::LocationInfo(&v79, File_LoadMovie, &url, &level0Path);
          ImageMovieDef = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(v5, &v79, lf, 0, 0);
          pmovieDef.pObject = ImageMovieDef;
          Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&v79);
          if ( !ImageMovieDef )
          {
            v28 = plog;
            if ( plog && !p_entry->QuietOpen )
              Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
                &plog->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
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
                    &v28->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
                    "Failed loading SWF \"%s\": ActionScript version mismatch",
                    (const char *)((url.HeapTypeBits & 0xFFFFFFFC) + 8));
                pObject = poldChar.pObject;
                if ( poldChar.pObject )
                {
                  v30 = (*(int (__thiscall **)(char *))(*((_DWORD *)&poldChar.pObject->__vftable
                                                        + poldChar.pObject->AvmObjOffset)
                                                      + 4))((char *)&poldChar.pObject->__vftable + 4
                                                                                                 * poldChar.pObject->AvmObjOffset);
                  v31 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v30 + 124))(v30);
                  v32 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&p_entry[1].Type, v31);
                  if ( v32 )
                    ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::InteractiveObject *, const char *, _DWORD))v32->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].SetValue)(
                      v32,
                      v31,
                      pObject,
                      "ActionScriptMismatch",
                      0);
                }
                Scaleform::GFx::Resource::Release(ImageMovieDef);
                if ( !pObject )
                  goto LABEL_52;
                v33 = pObject;
LABEL_51:
                Scaleform::RefCountNTSImpl::Release(v33);
LABEL_52:
                Scaleform::String::~String(&urlStrGfx);
                Scaleform::String::~String(&url);
                Scaleform::String::~String(&level0Path);
                return;
              }
              ccinfo.pCharDef = ImageMovieDef->pBindData.pObject->pDataDef.pObject;
              v47 = this->Scaleform::GFx::ASMovieRootBase::pASSupport.pObject;
              ccinfo.pResource = 0;
              ccinfo.pBindDefImpl = ImageMovieDef;
              v7 = (Scaleform::GFx::Sprite *)((int (__thiscall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::CharacterCreateInfo *, Scaleform::GFx::InteractiveObject *, unsigned int, int))v47->CreateCharacterInstance)(
                                               v47,
                                               this->pMovieImpl,
                                               &ccinfo,
                                               pparent,
                                               newCharId.Id,
                                               3);
              Scaleform::GFx::Sprite::SetLoadedSeparately(v7, (int)ImageMovieDef, (int)v28, 1);
            }
LABEL_75:
            v39 = p_entry[1].__vftable;
            charIsLoadedSuccessfully = v7 != 0;
            if ( v39 == (Scaleform::GFx::LoadQueueEntry_vtbl *)-1 )
            {
              if ( v7
                || (v40 = pparent,
                    v41 = (Scaleform::GFx::MovieDefImpl *)((int (__thiscall *)(Scaleform::GFx::InteractiveObject *, char *, int))pparent->GetResourceMovieDef)(
                                                            pparent,
                                                            v80,
                                                            65537),
                    Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(v41, v60, v61),
                    (v7 = (Scaleform::GFx::Sprite *)((int (__thiscall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, char *, Scaleform::GFx::InteractiveObject *))this->pASSupport.pObject->CreateCharacterInstance)(
                                                      this->pASSupport.pObject,
                                                      this->pMovieImpl,
                                                      v81,
                                                      v40)) != 0) )
              {
                Scaleform::GFx::InteractiveObject::AddToPlayList(v7);
                v42 = poldChar.pObject;
                v7->CreateFrame = poldChar.pObject->CreateFrame;
                v7->Depth = v42->Depth;
                if ( (v42->Scaleform::GFx::DisplayObject::Flags & 2) == 0 )
                {
                  v43 = v7->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
                  Name = Scaleform::GFx::DisplayObject::GetName(v42, (Scaleform::GFx::ASString *)&result);
                  v43->SetName(v7, Name);
                  pData = (Scaleform::GFx::ASStringNode *)result.pData;
                  --result.pData[1].Size;
                  if ( !pData->RefCount )
                    Scaleform::GFx::ASStringNode::ReleaseNode(pData);
                }
                v46 = pparent;
                if ( pparent )
                  v46 = (Scaleform::GFx::InteractiveObject *)(*(int (__thiscall **)(char *))(*((_DWORD *)&pparent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                                             + pparent->AvmObjOffset)
                                                                                           + 4))(
                                                               (char *)&pparent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                             + 4 * pparent->AvmObjOffset);
                ((void (__thiscall *)(Scaleform::GFx::InteractiveObject *, Scaleform::GFx::InteractiveObject *, Scaleform::GFx::Sprite *))v46->SetZScale)(
                  v46,
                  v42,
                  v7);
                v42->pParent = 0;
                this->ResolveStickyVariables(this, v7);
                Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::Sprite>(v7);
              }
            }
            else
            {
              if ( v7 )
              {
                Scaleform::GFx::AS2::AvmSprite::SetLevel(
                  (Scaleform::GFx::AS2::AvmSprite *)(&v7->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                   + v7->AvmObjOffset),
                  (int)v39);
                Scaleform::GFx::MovieImpl::SetLevelMovie(this->pMovieImpl, (int)p_entry[1].__vftable, v7);
                this->pMovieImpl->Flags &= ~0x100u;
                this->ResolveStickyVariables(this, v7);
              }
              if ( !Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(this, 0) && v28 )
              {
                Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
                  &v28->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
                  "_level0 unloaded - no further playback possible");
                if ( v7 )
                  Scaleform::RefCountNTSImpl::Release(v7);
                if ( ImageMovieDef )
                  Scaleform::GFx::Resource::Release(ImageMovieDef);
                v33 = poldChar.pObject;
                if ( !poldChar.pObject )
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
            if ( charIsLoadedSuccessfully )
            {
              if ( v55 )
              {
                v55->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].ExecuteForEachChild_GC(
                  v55,
                  (Scaleform::GFx::AS2::RefCountCollector<323> *)v54,
                  (Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC)v7);
                ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::Sprite *, int, int))v56->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].GetValue)(
                  v56,
                  v54,
                  v7,
                  filelength,
                  filelength);
                ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::Sprite *, _DWORD))v56->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].Finalize_GC)(
                  v56,
                  v54,
                  v7,
                  0);
              }
              v7->ExecuteFrame0Events(v7);
              this->DoActions(this);
              if ( v56 )
                ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::Sprite *))v56->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].~Scaleform::GFx::AS2::Object)(
                  v56,
                  v54,
                  v7);
            }
            else if ( v55 )
            {
              v34 = Scaleform::String::GetLength(&url) == 0;
              SetValue = v56->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].SetValue;
              if ( v34 )
                ((void (__stdcall *)(Scaleform::GFx::AS2::Environment *, Scaleform::GFx::Sprite *, const char *, _DWORD))SetValue)(
                  v54,
                  v7,
                  "Unknown error",
                  0);
              else
                ((void (__stdcall *)(Scaleform::GFx::AS2::Environment *, Scaleform::GFx::Sprite *, const char *, _DWORD))SetValue)(
                  v54,
                  v7,
                  "URLNotFound",
                  0);
            }
            if ( Scaleform::String::GetLength(&url) )
            {
              v58 = poldChar.pObject;
            }
            else
            {
              if ( poldChar.pObject )
                Scaleform::RefCountNTSImpl::Release(poldChar.pObject);
              v58 = 0;
              Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit::Collect(
                &this->MemContext.pObject->LimHandler,
                this->pMovieImpl->pHeap);
            }
            if ( v7 )
              Scaleform::RefCountNTSImpl::Release(v7);
            if ( pmovieDef.pObject )
              Scaleform::GFx::Resource::Release(pmovieDef.pObject);
            if ( v58 )
              Scaleform::RefCountNTSImpl::Release(v58);
            v12 = (void *)(urlStrGfx.HeapTypeBits & 0xFFFFFFFC);
            v59 = (volatile LONG *)((urlStrGfx.HeapTypeBits & 0xFFFFFFFC) + 4);
            goto LABEL_9;
          }
        }
        filelength = ImageMovieDef->pBindData.pObject->pDataDef.pObject->pData.pObject->Header.FileLength;
LABEL_38:
        v28 = plog;
        goto LABEL_39;
      }
      lf = (unsigned int)Scaleform::GFx::LoadStates::GetImageCreator(v5);
      if ( lf )
      {
        icinfo.pHeap = this->pMovieImpl->pHeap;
        icinfo.Use = 1;
        icinfo.RUse = Use_Bitmap;
        loadFlags = (unsigned int)v5->pImageFileHandlerRegistry.pObject;
        v22 = v5->pBindStates.pObject;
        icinfo.Type = Create_Protocol;
        memset(&icinfo.pLog, 0, 16);
        result.pData = (Scaleform::String::DataDesc *)v22->pFileOpener.pObject;
        Log = Scaleform::GFx::LoadStates::GetLog(v5);
        v24 = this->pMovieImpl;
        icinfo.pLog = Log;
        icinfo.pIFHRegistry = (Scaleform::GFx::ImageFileHandlerRegistry *)loadFlags;
        icinfo.pMovie = v24;
        icinfo.pFileOpener = (Scaleform::GFx::FileOpener *)result.pData;
        Scaleform::String::String((Scaleform::String *)&loadFlags, (char *)((url.HeapTypeBits & 0xFFFFFFFC) + 8));
        lf = (*(int (__thiscall **)(unsigned int, Scaleform::GFx::ImageCreateInfo *, unsigned int *))(*(_DWORD *)lf + 4))(
               lf,
               &icinfo,
               &loadFlags);
        Scaleform::String::~String((Scaleform::String *)&loadFlags);
        if ( lf )
        {
          v25 = (Scaleform::GFx::ImageResource *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 52, 0);
          if ( v25
            && (Scaleform::GFx::ImageResource::ImageResource(v25, (Scaleform::Render::Image *)lf, Use_Bitmap),
                (result.pData = v26) != 0) )
          {
            ImageMovieDef = Scaleform::GFx::MovieImpl::CreateImageMovieDef(
                              this->pMovieImpl,
                              (Scaleform::GFx::ImageResource *)result.pData,
                              bilinearImage,
                              (const char *)((url.HeapTypeBits & 0xFFFFFFFC) + 8),
                              v5);
            pmovieDef.pObject = ImageMovieDef;
            Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)result.pData);
          }
          else
          {
            ImageMovieDef = 0;
          }
          (*(void (__thiscall **)(unsigned int))(*(_DWORD *)lf + 8))(lf);
          goto LABEL_38;
        }
        v28 = plog;
        if ( plog )
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
            &plog->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
            "ImageCreator::LoadProtocolImage failed to load image \"%s\"",
            (const char *)((url.HeapTypeBits & 0xFFFFFFFC) + 8));
      }
      else
      {
        v28 = plog;
        if ( plog )
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
            &plog->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
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
      v28 = plog;
    }
    ImageMovieDef = 0;
    goto LABEL_75;
  }
  v12 = (void *)(urlStrGfx.HeapTypeBits & 0xFFFFFFFC);
  v59 = (volatile LONG *)((urlStrGfx.HeapTypeBits & 0xFFFFFFFC) + 4);
LABEL_9:
  if ( InterlockedExchangeAdd(v59, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v12);
  v13 = (void *)(url.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((url.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
  v14 = (void *)(level0Path.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((level0Path.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
}
