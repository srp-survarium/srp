char __thiscall Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie::LoadFinished(
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie *this)
{
  bool IsDone; // al
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // edi
  Scaleform::GFx::MovieImpl *pMovieImpl; // edx
  Scaleform::GFx::AS2::MovieRoot *pObject; // ebx
  Scaleform::GFx::CharacterHandle *pNext; // ecx
  Scaleform::GFx::InteractiveObject *v7; // eax
  Scaleform::GFx::Sprite *LevelMovie; // eax
  Scaleform::GFx::AS2::Environment *v9; // esi
  Scaleform::GFx::AS2::Object *v10; // eax
  Scaleform::GFx::InteractiveObject *v12; // edi
  Scaleform::GFx::InteractiveObject *v13; // ecx
  Scaleform::GFx::Sprite *v14; // eax
  Scaleform::GFx::Sprite_vtbl **v15; // ecx
  Scaleform::GFx::AS2::Environment *v16; // edi
  Scaleform::GFx::AS2::Object *v17; // ebx
  Scaleform::GFx::AS3::MemoryContextImpl *Name; // ebp
  Scaleform::GFx::LoadQueueEntry *v19; // ebp
  Scaleform::GFx::InteractiveObject *pParent; // ebp
  Scaleform::GFx::MovieDefImpl *v21; // eax
  Scaleform::GFx::InteractiveObject *v22; // edi
  Scaleform::GFx::InteractiveObject *v23; // ecx
  void (__thiscall **p_GetProjectionMatrix3D)(Scaleform::GFx::InteractiveObject *, Scaleform::GFx::ASString *); // ebx
  Scaleform::GFx::ASString *v25; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  int v27; // eax
  Scaleform::GFx::InteractiveObject *v28; // ecx
  Scaleform::GFx::Sprite *v29; // eax
  Scaleform::GFx::InteractiveObject *v30; // edi
  Scaleform::GFx::InteractiveObject *v31; // ecx
  Scaleform::GFx::InteractiveObject *v32; // eax
  int v33; // eax
  int v34; // eax
  Scaleform::GFx::InteractiveObject *v35; // ecx
  Scaleform::GFx::LogState *v36; // edi
  unsigned int v37; // edi
  Scaleform::GFx::LogState *v38; // ebp
  Scaleform::GFx::InteractiveObject *v39; // eax
  Scaleform::GFx::InteractiveObject_vtbl **v40; // ecx
  int v41; // eax
  int v42; // eax
  int v43; // eax
  Scaleform::GFx::ASStringNode *v44; // ebx
  Scaleform::GFx::ASSupport *v45; // ecx
  unsigned int Id; // edi
  Scaleform::GFx::Sprite *v47; // edi
  Scaleform::GFx::InteractiveObject *v48; // ecx
  void (__thiscall **p_SetName)(Scaleform::GFx::Sprite *, Scaleform::GFx::ASString *); // ebx
  Scaleform::GFx::ASString *v50; // eax
  Scaleform::GFx::ASStringNode *v51; // eax
  int v52; // eax
  Scaleform::GFx::InteractiveObject *v53; // ecx
  int v54; // eax
  unsigned int v55; // eax
  void (__thiscall *ExecuteForEachChild_GC)(struct Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::RefCountCollector<323> *, Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC); // edx
  unsigned int LastCollectionFootprint; // eax
  Scaleform::GFx::InteractiveObject *v58; // eax
  int v59; // eax
  unsigned int v60; // ecx
  Scaleform::GFx::Sprite *v61; // edi
  Scaleform::GFx::Sprite *v62; // eax
  Scaleform::GFx::AS3::MemoryContextImpl_vtbl *v63; // edx
  unsigned int v64; // eax
  int v65; // eax
  Scaleform::GFx::Sprite *v66; // edi
  Scaleform::GFx::Sprite *v67; // eax
  int v68; // eax
  void (__thiscall *v69)(struct Scaleform::GFx::AS3::MemoryContextImpl *); // eax
  unsigned int v70; // eax
  int v71; // eax
  Scaleform::GFx::InteractiveObject *v72; // eax
  int v73; // eax
  void (__thiscall *SetValue)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::AS2::Value *); // edx
  Scaleform::GFx::InteractiveObject *v75; // ecx
  Scaleform::GFx::InteractiveObject *v76; // [esp+40h] [ebp-50h]
  Scaleform::GFx::ResourceBinding *v77; // [esp+44h] [ebp-4Ch]
  Scaleform::GFx::ResourceId v78; // [esp+48h] [ebp-48h]
  bool v79; // [esp+57h] [ebp-39h]
  Scaleform::GFx::LoadQueueEntry *v80; // [esp+58h] [ebp-38h]
  Scaleform::GFx::AS2::MovieRoot *v81; // [esp+5Ch] [ebp-34h]
  Scaleform::GFx::AS2::Object *v82; // [esp+60h] [ebp-30h]
  Scaleform::GFx::ASString result; // [esp+64h] [ebp-2Ch] BYREF
  Scaleform::Ptr<Scaleform::GFx::LogState> v84; // [esp+68h] [ebp-28h] BYREF
  Scaleform::Ptr<Scaleform::GFx::LogState> v85; // [esp+6Ch] [ebp-24h] BYREF
  Scaleform::GFx::ASString v86; // [esp+70h] [ebp-20h] BYREF
  unsigned int bytesLoaded; // [esp+74h] [ebp-1Ch]
  _DWORD v88[3]; // [esp+78h] [ebp-18h] BYREF
  char v89[8]; // [esp+84h] [ebp-Ch] BYREF
  char v90[4]; // [esp+8Ch] [ebp-4h] BYREF

  IsDone = Scaleform::GFx::MoviePreloadTask::IsDone(this->pPreloadTask.pObject);
  pQueueEntry = this->pQueueEntry;
  v80 = pQueueEntry;
  if ( pQueueEntry->Canceled && IsDone )
    return 1;
  pMovieImpl = this->pMovieImpl;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)pMovieImpl->pASMovieRoot.pObject;
  v81 = pObject;
  if ( !IsDone )
    return 0;
  if ( !this->pOldChar.pObject )
  {
    pNext = (Scaleform::GFx::CharacterHandle *)pQueueEntry[1].pNext;
    if ( pNext )
    {
      v7 = Scaleform::GFx::CharacterHandle::ForceResolveCharacter(pNext, pMovieImpl);
      if ( !v7 )
      {
        LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pObject, 0);
        if ( LevelMovie )
        {
          v9 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*((_DWORD *)&LevelMovie->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                                + LevelMovie->AvmObjOffset)
                                                                              + 124))((int)LevelMovie + 4 * LevelMovie->AvmObjOffset);
          v10 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&pQueueEntry[1].Type, v9);
          if ( v10 )
            ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, _DWORD, const char *, _DWORD))v10->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].SetValue)(
              v10,
              v9,
              0,
              "Error",
              0);
        }
        return 1;
      }
      v12 = LOBYTE(v7->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0 ? v7 : 0;
      if ( v12 )
        ++v12->RefCount;
      v13 = this->pOldChar.pObject;
      if ( v13 )
        Scaleform::RefCountNTSImpl::Release(v13);
      this->pOldChar.pObject = v12;
      this->NewCharId.Id = v12->Id.Id;
    }
  }
  v14 = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pObject, 0);
  if ( !v14 )
    return 1;
  v15 = &v14->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
      + v14->AvmObjOffset;
  v16 = (Scaleform::GFx::AS2::Environment *)((int (__thiscall *)(Scaleform::GFx::Sprite_vtbl **))(*v15)->SetRotation)(v15);
  v17 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&v80[1].Type, v16);
  v82 = v17;
  v79 = v16->StringContext.pContext->GFxExtensions.Value == 1;
  Name = Scaleform::GFx::FontData::GetName((Scaleform::GFx::AS3::MovieRoot *)this->pPreloadTask.pObject);
  if ( !Name )
  {
    v19 = v80;
    if ( !v80[1].pNext )
    {
      if ( v80[1].__vftable != (Scaleform::GFx::LoadQueueEntry_vtbl *)-1 )
      {
        v29 = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(v81, (int)v80[1].__vftable);
        v30 = v29;
        if ( v29 )
          ++v29->RefCount;
        v31 = this->pOldChar.pObject;
        if ( v31 )
          Scaleform::RefCountNTSImpl::Release(v31);
        this->pOldChar.pObject = v30;
      }
      goto LABEL_33;
    }
    pParent = this->pOldChar.pObject->pParent;
    if ( pParent )
    {
      v21 = (Scaleform::GFx::MovieDefImpl *)((int (__thiscall *)(Scaleform::GFx::InteractiveObject *, char *, int))pParent->GetResourceMovieDef)(
                                              pParent,
                                              v89,
                                              65537);
      Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(v21, v77, v78);
      v22 = (Scaleform::GFx::InteractiveObject *)(*(int (__thiscall **)(const char *, Scaleform::GFx::MovieImpl *, char *, Scaleform::GFx::InteractiveObject *))(*(_DWORD *)result.pNode[1].pData + 16))(
                                                   result.pNode[1].pData,
                                                   this->pMovieImpl,
                                                   v90,
                                                   pParent);
      v22->CreateFrame = this->pOldChar.pObject->CreateFrame;
      v22->Depth = this->pOldChar.pObject->Depth;
      v23 = this->pOldChar.pObject;
      if ( (v23->Scaleform::GFx::DisplayObject::Flags & 2) == 0 )
      {
        p_GetProjectionMatrix3D = (void (__thiscall **)(Scaleform::GFx::InteractiveObject *, Scaleform::GFx::ASString *))&v22->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].GetProjectionMatrix3D;
        v25 = Scaleform::GFx::DisplayObject::GetName(v23, &result);
        (*p_GetProjectionMatrix3D)(v22, v25);
        pNode = result.pNode;
        --result.pNode->RefCount;
        if ( !pNode->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        v17 = v82;
      }
      Scaleform::GFx::InteractiveObject::AddToPlayList(v22);
      v27 = (*(int (__thiscall **)(int))(*((_DWORD *)&pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + pParent->AvmObjOffset)
                                       + 4))((int)pParent + 4 * pParent->AvmObjOffset);
      (*(void (__thiscall **)(int, Scaleform::GFx::InteractiveObject *, Scaleform::GFx::InteractiveObject *))(*(_DWORD *)v27 + 112))(
        v27,
        this->pOldChar.pObject,
        v22);
      this->pOldChar.pObject->pParent = 0;
      ++v22->RefCount;
      v28 = this->pOldChar.pObject;
      if ( v28 )
        Scaleform::RefCountNTSImpl::Release(v28);
      this->pOldChar.pObject = v22;
      Scaleform::RefCountNTSImpl::Release(v22);
      v19 = v80;
LABEL_33:
      v32 = this->pOldChar.pObject;
      if ( v32 && v17 )
      {
        v33 = (*(int (__thiscall **)(int))(*((_DWORD *)&v32->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                           + v32->AvmObjOffset)
                                         + 4))((int)v32 + 4 * v32->AvmObjOffset);
        v34 = (*(int (__thiscall **)(int))(*(_DWORD *)v33 + 124))(v33);
        ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, int, Scaleform::GFx::InteractiveObject *, const char *, _DWORD))v17->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].SetValue)(
          v17,
          v34,
          this->pOldChar.pObject,
          "URLNotFound",
          0);
      }
      if ( v19[1].__vftable != (Scaleform::GFx::LoadQueueEntry_vtbl *)-1 )
        Scaleform::GFx::MovieImpl::ReleaseLevelMovie(this->pMovieImpl, (int)v19[1].__vftable);
      return 1;
    }
    return 1;
  }
  v35 = this->pOldChar.pObject;
  if ( v35
    && ((v35->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x10) != 0
     || Scaleform::GFx::DisplayObjectBase::IsUnloading(v35)) )
  {
    return 1;
  }
  if ( ((int (__thiscall *)(Scaleform::GFx::AS3::MemoryContextImpl *))Name->__vftable[4].~Scaleform::GFx::AS3::MemoryContextImpl)(Name) != -1
    && (unsigned int)((int (__thiscall *)(Scaleform::GFx::AS3::MemoryContextImpl *))Name->__vftable[4].~Scaleform::GFx::AS3::MemoryContextImpl)(Name) >= 9
    && (char)((*((_DWORD *)Name->LimHandler.MemContext->StringMgr.pObject->EmptyStringNode.pData + 36) & 8 | 0x10u) >> 3) > 2 )
  {
    this->pQueueEntry->Canceled = 1;
    v36 = Scaleform::GFx::StateBag::GetLogState(&v81->pMovieImpl->Scaleform::GFx::StateBag, &v84)->pObject;
    if ( v84.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v84.pObject);
    if ( v36 && !v80->QuietOpen )
    {
      v37 = v80->URL.HeapTypeBits & 0xFFFFFFFC;
      v38 = Scaleform::GFx::StateBag::GetLogState(&v81->pMovieImpl->Scaleform::GFx::StateBag, &v85)->pObject;
      if ( v85.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v85.pObject);
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
        &v38->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "Failed loading SWF \"%s\": ActionScript version mismatch",
        (const char *)(v37 + 8));
    }
    v39 = this->pOldChar.pObject;
    if ( v39 && v17 )
    {
      v40 = &v39->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
          + v39->AvmObjOffset;
      v41 = ((int (__thiscall *)(Scaleform::GFx::InteractiveObject_vtbl **))(*v40)->CreateRenderNode)(v40);
      v42 = (*(int (__thiscall **)(int))(*(_DWORD *)v41 + 124))(v41);
      ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, int, Scaleform::GFx::InteractiveObject *, const char *, _DWORD))v17->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].SetValue)(
        v17,
        v42,
        this->pOldChar.pObject,
        "ActionScriptMismatch",
        0);
    }
    return 1;
  }
  if ( !this->CharSwitched )
  {
    v43 = (int)v80[1].__vftable;
    v44 = 0;
    result.pNode = 0;
    if ( v43 == -1 )
    {
      if ( v80[1].pNext )
      {
        v44 = (Scaleform::GFx::ASStringNode *)this->pOldChar.pObject->pParent;
        result.pNode = v44;
        if ( !v44 )
          return 1;
      }
    }
    else
    {
      Scaleform::GFx::MovieImpl::ReleaseLevelMovie(this->pMovieImpl, v43);
      this->NewCharId.Id = 0x40000;
    }
    v45 = v81->Scaleform::GFx::ASMovieRootBase::pASSupport.pObject;
    Id = this->NewCharId.Id;
    v88[0] = Name->LimHandler.MemContext->StringMgr.pObject;
    v88[1] = Name;
    v88[2] = 0;
    v47 = (Scaleform::GFx::Sprite *)((int (__thiscall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, _DWORD *, Scaleform::GFx::ASStringNode *, unsigned int, int))v45->CreateCharacterInstance)(
                                      v45,
                                      v81->pMovieImpl,
                                      v88,
                                      v44,
                                      Id,
                                      3);
    Scaleform::GFx::Sprite::SetLoadedSeparately(v47, (int)v44, (int)v47, 1);
    if ( !v79 )
      v47->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags |= 4u;
    if ( v80[1].pNext )
    {
      Scaleform::GFx::InteractiveObject::AddToPlayList(v47);
      v47->CreateFrame = this->pOldChar.pObject->CreateFrame;
      v47->Depth = this->pOldChar.pObject->Depth;
      v48 = this->pOldChar.pObject;
      if ( (v48->Scaleform::GFx::DisplayObject::Flags & 2) == 0 )
      {
        p_SetName = (void (__thiscall **)(Scaleform::GFx::Sprite *, Scaleform::GFx::ASString *))&v47->SetName;
        v50 = Scaleform::GFx::DisplayObject::GetName(v48, &v86);
        (*p_SetName)(v47, v50);
        v51 = v86.pNode;
        --v86.pNode->RefCount;
        if ( !v51->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v51);
        v44 = result.pNode;
      }
      if ( v44 )
        v52 = (*(int (__thiscall **)(int))(*((_DWORD *)&v44->pData + BYTE1(v44[2].HashFlags)) + 4))((int)v44 + 4 * BYTE1(v44[2].HashFlags));
      else
        v52 = 0;
      (*(void (__thiscall **)(int, Scaleform::GFx::InteractiveObject *, Scaleform::GFx::Sprite *))(*(_DWORD *)v52 + 116))(
        v52,
        this->pOldChar.pObject,
        v47);
      this->pOldChar.pObject->pParent = 0;
    }
    else
    {
      Scaleform::GFx::AS2::AvmSprite::SetLevel(
        (Scaleform::GFx::AS2::AvmSprite *)(&v47->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + v47->AvmObjOffset),
        (int)v80[1].__vftable);
      Scaleform::GFx::MovieImpl::SetLevelMovie(this->pMovieImpl, (int)v80[1].__vftable, v47);
      this->pMovieImpl->Flags &= ~0x100u;
    }
    v47->SetPlayState(v47, State_Stopped);
    ++v47->RefCount;
    v53 = this->pOldChar.pObject;
    if ( v53 )
      Scaleform::RefCountNTSImpl::Release(v53);
    this->pOldChar.pObject = v47;
    if ( v82 )
    {
      v54 = (int)v47;
      if ( v47 )
        v54 = (*(int (__thiscall **)(int))(*((_DWORD *)&v47->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                           + v47->AvmObjOffset)
                                         + 4))((int)v47 + 4 * v47->AvmObjOffset);
      v55 = (*(int (__thiscall **)(int))(*(_DWORD *)v54 + 124))(v54);
      ExecuteForEachChild_GC = v82->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].ExecuteForEachChild_GC;
      v76 = this->pOldChar.pObject;
      bytesLoaded = v55;
      ExecuteForEachChild_GC(
        v82,
        (Scaleform::GFx::AS2::RefCountCollector<323> *)v55,
        (Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC)v76);
      LastCollectionFootprint = Name->LimHandler.MemContext[2].LimHandler.LastCollectionFootprint;
      this->BytesLoaded = LastCollectionFootprint;
      ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, unsigned int, Scaleform::GFx::InteractiveObject *, unsigned int, _DWORD))v82->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].GetValue)(
        v82,
        bytesLoaded,
        this->pOldChar.pObject,
        LastCollectionFootprint,
        *((_DWORD *)Name->LimHandler.MemContext->StringMgr.pObject->EmptyStringNode.pData + 12));
    }
    this->CharSwitched = 1;
    Scaleform::RefCountNTSImpl::Release(v47);
    v17 = v82;
  }
  if ( this->BytesLoaded != Name->LimHandler.MemContext[2].LimHandler.LastCollectionFootprint && v17 )
  {
    v58 = this->pOldChar.pObject;
    if ( v58 )
      v58 = (Scaleform::GFx::InteractiveObject *)(*(int (__thiscall **)(int))(*((_DWORD *)&v58->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                              + v58->AvmObjOffset)
                                                                            + 4))((int)v58 + 4 * v58->AvmObjOffset);
    v59 = ((int (__thiscall *)(Scaleform::GFx::InteractiveObject *))v58->SetRotation)(v58);
    v60 = Name->LimHandler.MemContext[2].LimHandler.LastCollectionFootprint;
    this->BytesLoaded = v60;
    ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, int, Scaleform::GFx::InteractiveObject *, unsigned int, _DWORD))v17->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].GetValue)(
      v17,
      v59,
      this->pOldChar.pObject,
      v60,
      *((_DWORD *)Name->LimHandler.MemContext->StringMgr.pObject->EmptyStringNode.pData + 12));
  }
  if ( v79 && !this->FirstFrameLoaded && ((int)Name->LimHandler.MemContext[2].LimHandler.__vftable & 0x100) != 0 )
  {
    if ( v80[1].__vftable == (Scaleform::GFx::LoadQueueEntry_vtbl *)-1 )
    {
      v61 = (this->pOldChar.pObject->Flags & 0x400) != 0 ? (Scaleform::GFx::Sprite *)this->pOldChar.pObject : 0;
      if ( v61 )
        ++v61->RefCount;
    }
    else
    {
      v62 = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(v81, (int)v80[1].__vftable);
      if ( v62 )
        ++v62->RefCount;
      v61 = v62;
    }
    if ( v61 )
    {
      v61->SetPlayState(v61, State_Playing);
      v63 = Name->__vftable;
      bytesLoaded = Name->LimHandler.MemContext[2].LimHandler.LastCollectionFootprint;
      v64 = ((int (__thiscall *)(Scaleform::GFx::AS3::MemoryContextImpl *))v63[5].~Scaleform::GFx::AS3::MemoryContextImpl)(Name);
      Scaleform::GFx::Sprite::SetRootNodeLoadingStat(v61, bytesLoaded, v64);
      v61->ExecuteFrame0Events(v61);
      v81->DoActions(v81);
      if ( v17 )
      {
        v65 = (*(int (__thiscall **)(int))(*((_DWORD *)&v61->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                           + v61->AvmObjOffset)
                                         + 124))((int)v61 + 4 * v61->AvmObjOffset);
        ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, int, Scaleform::GFx::Sprite *))v17->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].~Scaleform::GFx::AS2::Object)(
          v17,
          v65,
          v61);
      }
    }
    this->FirstFrameLoaded = 1;
    if ( v61 )
      Scaleform::RefCountNTSImpl::Release(v61);
  }
  if ( ((int)Name->LimHandler.MemContext[2].LimHandler.__vftable & 3u) < 2 )
    return 0;
  if ( ((int)Name->LimHandler.MemContext[2].LimHandler.__vftable & 2) == 0 )
  {
    if ( v17 )
    {
      v72 = this->pOldChar.pObject;
      if ( v72 )
        v72 = (Scaleform::GFx::InteractiveObject *)(*(int (__thiscall **)(int))(*((_DWORD *)&v72->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                                + v72->AvmObjOffset)
                                                                              + 4))((int)v72 + 4 * v72->AvmObjOffset);
      v73 = ((int (__thiscall *)(Scaleform::GFx::InteractiveObject *))v72->SetRotation)(v72);
      SetValue = v17->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].SetValue;
      v75 = this->pOldChar.pObject;
      if ( *((_DWORD *)Name->LimHandler.MemContext->StringMgr.pObject->EmptyStringNode.pData + 39) == 4 )
      {
        ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, int, Scaleform::GFx::InteractiveObject *, const char *))SetValue)(
          v17,
          v73,
          v75,
          "Error");
        return 1;
      }
      ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, int, Scaleform::GFx::InteractiveObject *, const char *))SetValue)(
        v17,
        v73,
        v75,
        "Canceled");
    }
    return 1;
  }
  if ( v80[1].__vftable == (Scaleform::GFx::LoadQueueEntry_vtbl *)-1 )
  {
    v66 = (this->pOldChar.pObject->Flags & 0x400) != 0 ? (Scaleform::GFx::Sprite *)this->pOldChar.pObject : 0;
    if ( v66 )
      ++v66->RefCount;
    v81->ResolveStickyVariables(v81, this->pOldChar.pObject);
  }
  else
  {
    v67 = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(v81, (int)v80[1].__vftable);
    if ( v67 )
      ++v67->RefCount;
    v66 = v67;
  }
  if ( !v66 )
    return 1;
  if ( !v79 )
    v66->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags &= ~4u;
  if ( v17 )
  {
    v68 = (*(int (__thiscall **)(int))(*((_DWORD *)&v66->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                       + v66->AvmObjOffset)
                                     + 124))((int)v66 + 4 * v66->AvmObjOffset);
    ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, int, Scaleform::GFx::Sprite *, _DWORD))v17->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].Finalize_GC)(
      v17,
      v68,
      v66,
      0);
  }
  if ( !this->FirstFrameLoaded )
  {
    v66->SetPlayState(v66, State_Playing);
    v69 = Name->__vftable[5].~Scaleform::GFx::AS3::MemoryContextImpl;
    bytesLoaded = Name->LimHandler.MemContext[2].LimHandler.LastCollectionFootprint;
    v70 = ((int (__thiscall *)(Scaleform::GFx::AS3::MemoryContextImpl *))v69)(Name);
    Scaleform::GFx::Sprite::SetRootNodeLoadingStat(v66, bytesLoaded, v70);
    v66->ExecuteFrame0Events(v66);
    v81->DoActions(v81);
    if ( v17 )
    {
      v71 = (*(int (__thiscall **)(int))(*((_DWORD *)&v66->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + v66->AvmObjOffset)
                                       + 124))((int)v66 + 4 * v66->AvmObjOffset);
      ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, int, Scaleform::GFx::Sprite *))v17->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].~Scaleform::GFx::AS2::Object)(
        v17,
        v71,
        v66);
    }
  }
  this->FirstFrameLoaded = 1;
  Scaleform::RefCountNTSImpl::Release(v66);
  return 1;
}
