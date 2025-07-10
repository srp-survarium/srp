const Scaleform::GFx::CharacterCreateInfo *__thiscall Scaleform::GFx::AS2::AvmSprite::OnAddingDisplayObject(
        Scaleform::GFx::AS2::AvmSprite *this,
        const Scaleform::GFx::CharacterCreateInfo *ccinfo,
        Scaleform::GFx::InteractiveObject *pscriptCh,
        const Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *peventHandlers,
        Scaleform::GFx::AS2::ObjectInterface *pinitSource,
        bool placeObject)
{
  const Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v7; // edi
  Scaleform::GFx::InteractiveObject *v8; // ebp
  unsigned int v9; // ebx
  Scaleform::GFx::AS2::MovieClipObject *MovieClipObject; // eax
  Scaleform::GFx::SwfEvent *v11; // eax
  Scaleform::GFx::AS2::ActionBufferData *pObject; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // edi
  Scaleform::RefCountNTSImpl *v14; // ecx
  Scaleform::RefCountNTSImpl *v15; // ecx
  __int64 v16; // kr00_8
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // edx
  unsigned __int8 Flags; // al
  unsigned __int8 v19; // cl
  unsigned __int8 v20; // al
  char v21; // cl
  Scaleform::GFx::AS2::GlobalContext *v22; // eax
  unsigned int Id; // ecx
  Scaleform::GFx::AS2::GlobalContext *v24; // ebx
  Scaleform::GFx::MovieDefImpl *v25; // eax
  const Scaleform::String *NameOfExportedResource; // eax
  Scaleform::GFx::AS2::MovieRoot *v27; // edi
  unsigned int CurrentSessionId; // ecx
  Scaleform::GFx::AS2::MovieRoot::ActionQueueType *p_ActionQueue; // edi
  unsigned int *v30; // ebp
  const Scaleform::GFx::CharacterCreateInfo *LastSessionId; // eax
  Scaleform::GFx::AS2::Environment *v32; // eax
  Scaleform::GFx::AS2::Environment *v33; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v34; // ebp
  Scaleform::RefCountNTSImpl *v35; // ecx
  Scaleform::RefCountNTSImpl *v36; // ecx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v37; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v38; // ebp
  Scaleform::RefCountNTSImpl *v39; // ecx
  Scaleform::RefCountNTSImpl *v40; // ecx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v41; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v42; // ebp
  Scaleform::RefCountNTSImpl *v43; // ecx
  Scaleform::RefCountNTSImpl *v44; // ecx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v45; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v46; // ebp
  Scaleform::RefCountNTSImpl *v47; // ecx
  Scaleform::RefCountNTSImpl *v48; // ecx
  Scaleform::GFx::AS2::Value *Data; // ebp
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v51; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v52; // ebx
  Scaleform::RefCountNTSImpl *v53; // ecx
  Scaleform::RefCountNTSImpl *v54; // ecx
  Scaleform::GFx::AS2::Value *v55; // ebx
  Scaleform::GFx::ASStringNode *v56; // eax
  Scaleform::GFx::AS2::FunctionObject *Function; // ebp
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v58; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v59; // edi
  Scaleform::RefCountNTSImpl *v60; // ecx
  Scaleform::RefCountNTSImpl *v61; // ecx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v62; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v63; // edi
  Scaleform::RefCountNTSImpl *v64; // ecx
  Scaleform::RefCountNTSImpl *v65; // ecx
  bool v66; // zf
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::LocalFrame *v68; // ecx
  unsigned int v69; // eax
  Scaleform::GFx::ResourceId v71; // [esp-4h] [ebp-50h]
  Scaleform::GFx::ASString symbolName; // [esp+14h] [ebp-38h] BYREF
  Scaleform::GFx::AS2::MovieRoot *asroot; // [esp+18h] [ebp-34h]
  unsigned int oldSessionId; // [esp+1Ch] [ebp-30h]
  Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> params; // [esp+20h] [ebp-2Ch] BYREF
  Scaleform::GFx::AS2::FunctionRef ctorFunc; // [esp+2Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v; // [esp+38h] [ebp-14h] BYREF
  unsigned __int8 v79; // [esp+48h] [ebp-4h]
  char v80; // [esp+49h] [ebp-3h]
  unsigned __int8 v81; // [esp+4Ah] [ebp-2h]
  char v82; // [esp+4Bh] [ebp-1h]
  const Scaleform::GFx::CharacterCreateInfo *ccinfoa; // [esp+50h] [ebp+4h]
  char hasConstructEvent; // [esp+54h] [ebp+8h]
  char initSourceUsed; // [esp+58h] [ebp+Ch]

  v7 = peventHandlers;
  v8 = (pscriptCh->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 ? pscriptCh : 0;
  hasConstructEvent = 1;
  asroot = (Scaleform::GFx::AS2::MovieRoot *)this->pDispObj->pASRoot;
  if ( peventHandlers )
  {
    v9 = 0;
    symbolName.pNode = (Scaleform::GFx::ASStringNode *)peventHandlers->Data.Size;
    if ( symbolName.pNode )
    {
      do
      {
        Scaleform::GFx::AS2::AvmSwfEvent::AttachTo(v7->Data.Data[v9], (int)v7, (int)pscriptCh, pscriptCh);
        if ( v8 )
        {
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[5311032] & v7->Data.Data[v9]->Event.Id) != 0 )
          {
            MovieClipObject = Scaleform::GFx::AS2::AvmSprite::GetMovieClipObject((Scaleform::GFx::AS2::AvmSprite *)(&v8->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable + v8->AvmObjOffset));
            if ( MovieClipObject )
              MovieClipObject->HasButtonHandlers = 1;
          }
        }
        if ( placeObject )
        {
          v11 = v7->Data.Data[v9];
          if ( v11->Event.Id == 512 )
          {
            pObject = v11->pActionOpData.pObject;
            if ( pObject )
            {
              if ( pObject->BufferLen && *pObject->pBuffer )
              {
                inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                             &asroot->ActionQueue,
                             AP_Initialize);
                if ( inserted )
                {
                  Scaleform::GFx::EventId::EventId((Scaleform::GFx::EventId *)&v, 0x200u);
                  inserted->Type = Entry_Event;
                  ++pscriptCh->RefCount;
                  v14 = inserted->pCharacter.pObject;
                  if ( v14 )
                    Scaleform::RefCountNTSImpl::Release(v14);
                  inserted->pCharacter.pObject = pscriptCh;
                  v15 = inserted->pActionBuffer.pObject;
                  if ( v15 )
                    Scaleform::RefCountNTSImpl::Release(v15);
                  v16 = *(_QWORD *)&v.T.Type;
                  pLocalFrame = v.V.FunctionValue.pLocalFrame;
                  inserted->pActionBuffer.pObject = 0;
                  inserted->mEventId.Id = v16;
                  Flags = v.V.FunctionValue.Flags;
                  inserted->mEventId.WcharCode = HIDWORD(v16);
                  v19 = v79;
                  inserted->mEventId.AsciiCode = Flags;
                  v20 = v81;
                  inserted->mEventId.RollOverCnt = v19;
                  v21 = v82;
                  inserted->mEventId.KeyCode = (unsigned int)pLocalFrame;
                  inserted->mEventId.ControllerIndex = v80;
                  inserted->mEventId.KeysState.States = v20;
                  inserted->mEventId.MouseWheelDelta = v21;
                }
                v7 = peventHandlers;
              }
            }
          }
        }
        ++v9;
      }
      while ( v9 < (unsigned int)symbolName.pNode );
    }
  }
  v22 = this->GetGC(this);
  Id = ccinfo->pCharDef->Id.Id;
  v24 = v22;
  memset(&ctorFunc, 0, 9);
  v71.Id = Id;
  v25 = pscriptCh->GetResourceMovieDef(pscriptCh);
  NameOfExportedResource = Scaleform::GFx::MovieDefImpl::GetNameOfExportedResource(v25, v71);
  v27 = asroot;
  ++asroot->ActionQueue.LastSessionId;
  CurrentSessionId = v27->ActionQueue.CurrentSessionId;
  p_ActionQueue = &v27->ActionQueue;
  v30 = (unsigned int *)NameOfExportedResource;
  LastSessionId = (const Scaleform::GFx::CharacterCreateInfo *)p_ActionQueue->LastSessionId;
  oldSessionId = CurrentSessionId;
  ccinfoa = LastSessionId;
  p_ActionQueue->CurrentSessionId = (unsigned int)LastSessionId;
  initSourceUsed = 0;
  if ( v30 )
  {
    v32 = this->GetASEnvironment(this);
    symbolName.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                         (Scaleform::GFx::ASStringManager *)v32->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                         (char *)((*v30 & 0xFFFFFFFC) + 8),
                         *(_DWORD *)(*v30 & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++symbolName.pNode->RefCount;
    v33 = this->GetASEnvironment(this);
    if ( Scaleform::GFx::AS2::GlobalContext::FindRegisteredClass(v24, &v33->StringContext, &symbolName, &ctorFunc) )
    {
      v34 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(p_ActionQueue, AP_Initialize);
      memset(&params, 0, sizeof(params));
      Scaleform::GFx::AS2::Value::Value(&v, &ctorFunc);
      Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &params.Data,
        &params,
        1u);
      if ( &params.Data.Data[params.Data.Size] != (Scaleform::GFx::AS2::Value *)16 )
        Scaleform::GFx::AS2::Value::Value(&params.Data.Data[params.Data.Size - 1], &v);
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      if ( v34 )
      {
        v34->Type = Entry_CFunction;
        ++pscriptCh->RefCount;
        v35 = v34->pCharacter.pObject;
        if ( v35 )
          Scaleform::RefCountNTSImpl::Release(v35);
        v34->pCharacter.pObject = pscriptCh;
        v36 = v34->pActionBuffer.pObject;
        if ( v36 )
          Scaleform::RefCountNTSImpl::Release(v36);
        v34->pActionBuffer.pObject = 0;
        v34->CFunction = Scaleform::GFx::AS2::AvmSprite::InitializeClassInstance;
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
          &v34->FunctionParams,
          &params);
      }
      v37 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(p_ActionQueue, AP_Construct);
      v38 = v37;
      if ( v37 )
      {
        v37->Type = Entry_Event;
        ++pscriptCh->RefCount;
        v39 = v37->pCharacter.pObject;
        if ( v39 )
          Scaleform::RefCountNTSImpl::Release(v39);
        v38->pCharacter.pObject = pscriptCh;
        v40 = v38->pActionBuffer.pObject;
        if ( v40 )
          Scaleform::RefCountNTSImpl::Release(v40);
        v38->pActionBuffer.pObject = 0;
        v38->mEventId.Id = 0x40000;
        v38->mEventId.WcharCode = 0;
        v38->mEventId.KeyCode = 0;
        v38->mEventId.AsciiCode = 0;
        v38->mEventId.RollOverCnt = 0;
        v38->mEventId.ControllerIndex = -1;
        v38->mEventId.KeysState.States = 0;
        v38->mEventId.MouseWheelDelta = 0;
      }
      hasConstructEvent = 0;
      if ( (unsigned int)Scaleform::GFx::DisplayObjectBase::GetVersion(this->pDispObj) >= 6 && pinitSource )
      {
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
          &params,
          0);
        v.T.Type = 0;
        Scaleform::GFx::AS2::Value::SetAsObjectInterface(&v, pinitSource);
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          &params,
          &v);
        v41 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(p_ActionQueue, AP_Construct);
        v42 = v41;
        if ( v41 )
        {
          v41->Type = Entry_CFunction;
          ++pscriptCh->RefCount;
          v43 = v41->pCharacter.pObject;
          if ( v43 )
            Scaleform::RefCountNTSImpl::Release(v43);
          v42->pCharacter.pObject = pscriptCh;
          v44 = v42->pActionBuffer.pObject;
          if ( v44 )
            Scaleform::RefCountNTSImpl::Release(v44);
          v42->pActionBuffer.pObject = 0;
          v42->CFunction = Scaleform::GFx::AS2::AvmSprite::InitObjectMembers;
          Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
            &v42->FunctionParams,
            &params);
        }
        if ( v.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v);
      }
      initSourceUsed = 1;
      v45 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(p_ActionQueue, AP_Construct);
      v46 = v45;
      if ( v45 )
      {
        v45->Type = Entry_Function;
        ++pscriptCh->RefCount;
        v47 = v45->pCharacter.pObject;
        if ( v47 )
          Scaleform::RefCountNTSImpl::Release(v47);
        v46->pCharacter.pObject = pscriptCh;
        v48 = v46->pActionBuffer.pObject;
        if ( v48 )
          Scaleform::RefCountNTSImpl::Release(v48);
        v46->pActionBuffer.pObject = 0;
        Scaleform::GFx::AS2::FunctionRefBase::Assign(&v46->Function, &ctorFunc);
      }
      Data = params.Data.Data;
      Scaleform::ConstructorMov<Scaleform::GFx::AS2::Value>::DestructArray(params.Data.Data, params.Data.Size);
      if ( Data )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
    }
    else if ( placeObject )
    {
      pNode = symbolName.pNode;
      ++symbolName.pNode->RefCount;
      v.NV.Int32Value = (int)pNode;
      memset(&params, 0, sizeof(params));
      v.T.Type = 5;
      Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &params.Data,
        &params,
        1u);
      if ( &params.Data.Data[params.Data.Size] == (Scaleform::GFx::AS2::Value *)16
        || (Scaleform::GFx::AS2::Value::Value(&params.Data.Data[params.Data.Size - 1], &v), v.T.Type >= 5u) )
      {
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      }
      v51 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(p_ActionQueue, AP_Construct);
      v52 = v51;
      if ( v51 )
      {
        v51->Type = Entry_CFunction;
        ++pscriptCh->RefCount;
        v53 = v51->pCharacter.pObject;
        if ( v53 )
          Scaleform::RefCountNTSImpl::Release(v53);
        v52->pCharacter.pObject = pscriptCh;
        v54 = v52->pActionBuffer.pObject;
        if ( v54 )
          Scaleform::RefCountNTSImpl::Release(v54);
        v52->pActionBuffer.pObject = 0;
        v52->CFunction = Scaleform::GFx::AS2::AvmSprite::FindClassAndInitializeClassInstance;
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
          &v52->FunctionParams,
          &params);
      }
      v55 = params.Data.Data;
      hasConstructEvent = 0;
      Scaleform::ConstructorMov<Scaleform::GFx::AS2::Value>::DestructArray(params.Data.Data, params.Data.Size);
      if ( v55 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v55);
    }
    v56 = symbolName.pNode;
    --symbolName.pNode->RefCount;
    if ( !v56->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v56);
  }
  Function = ctorFunc.Function;
  if ( placeObject )
  {
    if ( hasConstructEvent )
    {
      v58 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(p_ActionQueue, AP_Construct);
      v59 = v58;
      if ( v58 )
      {
        v58->Type = Entry_Event;
        ++pscriptCh->RefCount;
        v60 = v58->pCharacter.pObject;
        if ( v60 )
          Scaleform::RefCountNTSImpl::Release(v60);
        v59->pCharacter.pObject = pscriptCh;
        v61 = v59->pActionBuffer.pObject;
        if ( v61 )
          Scaleform::RefCountNTSImpl::Release(v61);
        v59->pActionBuffer.pObject = 0;
        v59->mEventId.Id = 0x40000;
        v59->mEventId.WcharCode = 0;
        v59->mEventId.KeyCode = 0;
        v59->mEventId.AsciiCode = 0;
        v59->mEventId.RollOverCnt = 0;
        v59->mEventId.ControllerIndex = -1;
        v59->mEventId.KeysState.States = 0;
        v59->mEventId.MouseWheelDelta = 0;
      }
    }
  }
  else if ( !initSourceUsed
         && (unsigned int)Scaleform::GFx::DisplayObjectBase::GetVersion(this->pDispObj) >= 6
         && pinitSource )
  {
    memset(&params, 0, sizeof(params));
    v.T.Type = 0;
    Scaleform::GFx::AS2::Value::SetAsObjectInterface(&v, pinitSource);
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      &params,
      &v);
    v62 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(p_ActionQueue, AP_Construct);
    v63 = v62;
    if ( v62 )
    {
      v62->Type = Entry_CFunction;
      ++pscriptCh->RefCount;
      v64 = v62->pCharacter.pObject;
      if ( v64 )
        Scaleform::RefCountNTSImpl::Release(v64);
      v63->pCharacter.pObject = pscriptCh;
      v65 = v63->pActionBuffer.pObject;
      if ( v65 )
        Scaleform::RefCountNTSImpl::Release(v65);
      v63->pActionBuffer.pObject = 0;
      v63->CFunction = Scaleform::GFx::AS2::AvmSprite::InitObjectMembers;
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
        &v63->FunctionParams,
        &params);
    }
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy>::~Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy>(&params);
  }
  v66 = (ctorFunc.Flags & 2) == 0;
  asroot->ActionQueue.CurrentSessionId = oldSessionId;
  if ( v66 )
  {
    if ( Function )
    {
      RefCount = Function->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  if ( (ctorFunc.Flags & 1) == 0 )
  {
    v68 = ctorFunc.pLocalFrame;
    if ( ctorFunc.pLocalFrame )
    {
      v69 = ctorFunc.pLocalFrame->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v69) != 0 )
      {
        ctorFunc.pLocalFrame->RefCount = v69 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v68);
      }
    }
  }
  return ccinfoa;
}
