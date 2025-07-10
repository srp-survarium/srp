char __thiscall Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie::LoadFinished(
        Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie *this)
{
  Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie *v1; // esi
  Scaleform::GFx::MoviePreloadTask *pObject; // ecx
  bool IsDone; // al
  int pQueueEntry; // ebp
  Scaleform::GFx::AS3::MovieRoot *v5; // ebx
  Scaleform::GFx::AS3::MemoryContextImpl *Name; // eax
  Scaleform::GFx::MovieDefImpl *Resource; // edi
  const Scaleform::GFx::ASString *v8; // eax
  int v9; // ecx
  Scaleform::GFx::LogState *v11; // esi
  const char *pData; // esi
  Scaleform::GFx::LogState *v13; // edi
  const Scaleform::GFx::ASString *v14; // eax
  int v15; // ebp
  int v16; // ecx
  unsigned int BytesLoaded; // eax
  Scaleform::GFx::AS3::ASVM *v18; // eax
  int v19; // ebx
  Scaleform::GFx::Sprite *v20; // esi
  void (__thiscall *OnEventLoad)(Scaleform::GFx::DisplayObjectBase *); // eax
  Scaleform::GFx::AS3::AvmDisplayObj *v22; // ebx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v24; // ecx
  int v25; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v26; // ecx
  Scaleform::GFx::Resource *v27; // ecx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v28; // ecx
  int v29; // esi
  Scaleform::GFx::ASSupport *v30; // ecx
  Scaleform::GFx::AS3::AvmBitmap *v31; // ebx
  int v32; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v33; // ecx
  Scaleform::GFx::AS3::AvmDisplayObj *v34; // esi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v35; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v36; // ecx
  Scaleform::GFx::Resource *v37; // ecx
  const Scaleform::GFx::ASString *v38; // eax
  Scaleform::GFx::AS3::MovieRoot *root; // [esp+30h] [ebp-30h]
  Scaleform::Ptr<Scaleform::GFx::LogState> result; // [esp+34h] [ebp-2Ch] BYREF
  Scaleform::GFx::DisplayObjContainer *pparent; // [esp+38h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie *v42; // [esp+3Ch] [ebp-24h]
  Scaleform::GFx::ResourceHandle rh; // [esp+40h] [ebp-20h] BYREF
  Scaleform::GFx::CharacterCreateInfo ccinfo; // [esp+48h] [ebp-18h] BYREF
  _DWORD v45[3]; // [esp+54h] [ebp-Ch] BYREF

  v1 = this;
  pObject = this->pPreloadTask.pObject;
  v42 = v1;
  IsDone = Scaleform::GFx::MoviePreloadTask::IsDone(pObject);
  pQueueEntry = (int)v1->pQueueEntry;
  if ( *(_BYTE *)(pQueueEntry + 25) && IsDone )
    return 1;
  v5 = (Scaleform::GFx::AS3::MovieRoot *)v1->pMovieImpl->pASMovieRoot.pObject;
  root = v5;
  if ( !IsDone )
  {
    if ( *(_BYTE *)(pQueueEntry + 52) )
    {
      Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteOpenEvent(*(Scaleform::GFx::AS3::Instances::fl_display::Loader **)(pQueueEntry + 28));
      *(_BYTE *)(pQueueEntry + 52) = 0;
    }
    return 0;
  }
  Name = Scaleform::GFx::FontData::GetName((Scaleform::GFx::AS3::MovieRoot *)v1->pPreloadTask.pObject);
  Resource = (Scaleform::GFx::MovieDefImpl *)Name;
  if ( !Name )
  {
    v8 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(*(Scaleform::GFx::AS3::Instances::fl_net::URLRequest **)(pQueueEntry + 36));
    Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteErrorEvent(
      *(Scaleform::GFx::AS3::Instances::fl_display::Loader **)(pQueueEntry + 28),
      v8->pNode->pData);
    v9 = *(_DWORD *)(pQueueEntry + 48);
    if ( v9 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 12))(v9);
      *(_BYTE *)(pQueueEntry + 52) = 0;
      return 1;
    }
    goto LABEL_77;
  }
  if ( *(_BYTE *)(pQueueEntry + 52) )
  {
    if ( ((int (__thiscall *)(Scaleform::GFx::AS3::MemoryContextImpl *))Name->__vftable[4].~Scaleform::GFx::AS3::MemoryContextImpl)(Name) != -1
      && (Resource->GetVersion(Resource) < 9
       || (char)((Resource->pBindData.pObject->pDataDef.pObject->pData.pObject->FileAttributes & 8 | 0x10) >> 3) < 3) )
    {
      v1->pQueueEntry->Canceled = 1;
      v11 = Scaleform::GFx::StateBag::GetLogState(&v5->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
      if ( result.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result.pObject);
      if ( v11 && !*(_BYTE *)(pQueueEntry + 24) )
      {
        pData = Scaleform::GFx::AS3::Instances::fl::XML::GetName(*(Scaleform::GFx::AS3::Instances::fl_net::URLRequest **)(pQueueEntry + 36))->pNode->pData;
        v13 = Scaleform::GFx::StateBag::GetLogState(
                &v5->pMovieImpl->Scaleform::GFx::StateBag,
                (Scaleform::Ptr<Scaleform::GFx::LogState> *)&pparent)->pObject;
        if ( pparent )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pparent);
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
          &v13->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
          "Failed loading SWF \"%s\": ActionScript version mismatch",
          pData);
      }
      v14 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(*(Scaleform::GFx::AS3::Instances::fl_net::URLRequest **)(pQueueEntry + 36));
      Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteErrorEvent(
        *(Scaleform::GFx::AS3::Instances::fl_display::Loader **)(pQueueEntry + 28),
        v14->pNode->pData);
      v15 = *(_DWORD *)(pQueueEntry + 48);
      if ( v15 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v15 + 12))(v15);
        return 1;
      }
      return 1;
    }
    Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteOpenEvent(*(Scaleform::GFx::AS3::Instances::fl_display::Loader **)(pQueueEntry + 28));
    v16 = *(_DWORD *)(pQueueEntry + 48);
    if ( v16 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v16 + 4))(v16);
    *(_BYTE *)(pQueueEntry + 52) = 0;
    Scaleform::GFx::AS3::MovieRoot::AddLoadedMovieDef(v5, Resource);
  }
  if ( !v1->CharSwitched )
    v1->CharSwitched = 1;
  if ( v1->BytesLoaded != Resource->pBindData.pObject->BytesLoaded )
  {
    BytesLoaded = Resource->pBindData.pObject->BytesLoaded;
    v1->BytesLoaded = BytesLoaded;
    Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteProgressEvent(
      *(Scaleform::GFx::AS3::Instances::fl_display::Loader **)(pQueueEntry + 28),
      BytesLoaded,
      Resource->pBindData.pObject->pDataDef.pObject->pData.pObject->Header.FileLength);
  }
  if ( !v1->FirstFrameLoaded && (Resource->pBindData.pObject->BindState & 0x100) != 0 )
  {
    if ( Resource->pBindData.pObject->pDataDef.pObject->MovieType == MT_Flash )
    {
      pparent = *(Scaleform::GFx::DisplayObjContainer **)(*(_DWORD *)(pQueueEntry + 28) + 48);
      v18 = v5->pAVM.pObject;
      if ( v18 )
        Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(
          v18->GC.GC,
          (Scaleform::GFx::Resource *)v1->pMovieImpl->AdvanceStats.pObject,
          0);
      v19 = (int)v5->pASSupport.pObject;
      ccinfo.pCharDef = Resource->pBindData.pObject->pDataDef.pObject;
      ccinfo.pBindDefImpl = Resource;
      ccinfo.pResource = 0;
      v20 = (Scaleform::GFx::Sprite *)(*(int (__thiscall **)(int, Scaleform::GFx::MovieImpl *, Scaleform::GFx::CharacterCreateInfo *, _DWORD, _DWORD, int))(*(_DWORD *)v19 + 16))(
                                        v19,
                                        v1->pMovieImpl,
                                        &ccinfo,
                                        0,
                                        0,
                                        3);
      Scaleform::GFx::Sprite::SetLoadedSeparately(v20, v19, (int)Resource, 1);
      OnEventLoad = v20->OnEventLoad;
      v20->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Flags |= 1u;
      OnEventLoad(v20);
      Scaleform::GFx::InteractiveObject::AddToPlayList(v20);
      v22 = (Scaleform::GFx::AS3::AvmDisplayObj *)(&v20->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                 + v20->AvmObjOffset);
      v22->__vftable[1].GetAbsolutePath(v22, 0);
      ((void (__thiscall *)(Scaleform::GFx::Sprite *, _DWORD, _DWORD))v20->SetFOV)(
        v20,
        COERCE_UNSIGNED_INT64(55.0),
        HIDWORD(COERCE_UNSIGNED_INT64(55.0)));
      if ( !Scaleform::GFx::AS3::AvmDisplayObj::HasAS3Obj(v22)
        && Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor(v22, pQueueEntry, (int)Resource) )
      {
        pAS3RawPtr = v22->pAS3RawPtr;
        if ( !pAS3RawPtr )
          pAS3RawPtr = v22->pAS3CollectiblePtr.pObject;
        v24 = pAS3RawPtr;
        if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
          v24 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::SetLoaderInfo(
          v24,
          *(const Scaleform::GFx::AS3::Instances::fl_display::Loader **)(pQueueEntry + 28));
        Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(v22, 1);
      }
      if ( pparent
        && (v25 = (*(int (__thiscall **)(char *))(*((_DWORD *)&pparent->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                  + pparent->AvmObjOffset)
                                                + 20))(
                    (char *)&pparent->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                  + 4 * pparent->AvmObjOffset)) != 0 )
      {
        v26 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v25 - 36);
      }
      else
      {
        v26 = 0;
      }
      Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChild(v26, v20);
      root->ResolveStickyVariables(root, v20);
      Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::Sprite>(v20);
      root->DoActions(root);
      v27 = *(Scaleform::GFx::Resource **)(pQueueEntry + 48);
      if ( v27 )
        Scaleform::RefCountImpl::AddRef(v27);
      Scaleform::GFx::AS3::Instances::fl_display::Loader::QueueInitEvent(
        *(Scaleform::GFx::AS3::Instances::fl_display::Loader **)(pQueueEntry + 28),
        v20,
        *(Scaleform::Ptr<Scaleform::GFx::AS3::NotifyLoadInitC> *)(pQueueEntry + 48));
      Scaleform::RefCountNTSImpl::Release(v20);
      v5 = root;
      v1 = v42;
    }
    v1->FirstFrameLoaded = 1;
  }
  if ( (Resource->pBindData.pObject->BindState & 3) < 2 )
    return 0;
  if ( (Resource->pBindData.pObject->BindState & 2) == 0 )
  {
    v38 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(*(Scaleform::GFx::AS3::Instances::fl_net::URLRequest **)(pQueueEntry + 36));
    Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteErrorEvent(
      *(Scaleform::GFx::AS3::Instances::fl_display::Loader **)(pQueueEntry + 28),
      v38->pNode->pData);
LABEL_77:
    *(_BYTE *)(pQueueEntry + 52) = 0;
    return 1;
  }
  v28 = Resource->pBindData.pObject;
  if ( v28->pDataDef.pObject->MovieType == MT_Image )
  {
    v29 = *(_DWORD *)(*(_DWORD *)(pQueueEntry + 28) + 48);
    v45[0] = v28->pDataDef.pObject;
    v30 = v5->pASSupport.pObject;
    v45[1] = Resource;
    v45[2] = 0;
    v31 = (Scaleform::GFx::AS3::AvmBitmap *)((int (__thiscall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, _DWORD *, _DWORD, int, int))v30->CreateCharacterInstance)(
                                              v30,
                                              v5->pMovieImpl,
                                              v45,
                                              0,
                                              0x40000,
                                              8);
    rh.HType = RH_Pointer;
    rh.BindIndex = 0;
    if ( Scaleform::GFx::MovieDataDef::GetResourceHandle(
           Resource->pBindData.pObject->pDataDef.pObject,
           (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType *)&rh,
           0) )
    {
      Resource = (Scaleform::GFx::MovieDefImpl *)Scaleform::GFx::ResourceHandle::GetResource(
                                                   &rh,
                                                   &Resource->pBindData.pObject->ResourceBinding);
      if ( Resource )
      {
        if ( (Resource->GetResourceTypeCode(Resource) & 0xFF00) == 0x100 )
          Scaleform::GFx::AS3::AvmBitmap::SetImage(v31, (Scaleform::GFx::ImageResource *)Resource);
      }
    }
    if ( v29
      && (v32 = (*(int (__thiscall **)(int))(*(_DWORD *)(v29 + 4 * *(unsigned __int8 *)(v29 + 65)) + 20))(v29 + 4 * *(unsigned __int8 *)(v29 + 65))) != 0 )
    {
      v33 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v32 - 36);
    }
    else
    {
      v33 = 0;
    }
    Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChild(v33, (Scaleform::GFx::InteractiveObject *)v31);
    if ( v31 )
      v34 = (Scaleform::GFx::AS3::AvmDisplayObj *)(&v31->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                 + v31->AvmObjOffset);
    else
      v34 = 0;
    if ( !Scaleform::GFx::AS3::AvmDisplayObj::HasAS3Obj(v34)
      && Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor(v34, pQueueEntry, (int)Resource) )
    {
      v35 = v34->pAS3RawPtr;
      if ( !v35 )
        v35 = v34->pAS3CollectiblePtr.pObject;
      v36 = v35;
      if ( ((unsigned __int8)v35 & 1) != 0 )
        v36 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v35 - 1);
      Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::SetLoaderInfo(
        v36,
        *(const Scaleform::GFx::AS3::Instances::fl_display::Loader **)(pQueueEntry + 28));
      Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(v34, 1);
    }
    v37 = *(Scaleform::GFx::Resource **)(pQueueEntry + 48);
    if ( v37 )
      Scaleform::RefCountImpl::AddRef(v37);
    Scaleform::GFx::AS3::Instances::fl_display::Loader::QueueInitEvent(
      *(Scaleform::GFx::AS3::Instances::fl_display::Loader **)(pQueueEntry + 28),
      v31,
      *(Scaleform::Ptr<Scaleform::GFx::AS3::NotifyLoadInitC> *)(pQueueEntry + 48));
    if ( rh.HType == RH_Pointer && rh.BindIndex )
      Scaleform::GFx::Resource::Release(rh.pResource);
    if ( v31 )
      Scaleform::RefCountNTSImpl::Release(v31);
  }
  Scaleform::GFx::AS3::Instances::fl_display::Loader::QueueCompleteEvent(*(Scaleform::GFx::AS3::Instances::fl_display::Loader **)(pQueueEntry + 28));
  return 1;
}
