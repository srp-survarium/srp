void __thiscall Scaleform::GFx::AS2::AvmButton::ConstructCharacter(
        Scaleform::GFx::AS2::AvmButton *this,
        Scaleform::GFx::ASStringNode *pscriptCh,
        const Scaleform::GFx::ButtonRecord *rec)
{
  Scaleform::GFx::ASStringNode *v3; // edi
  Scaleform::GFx::AS2::GlobalContext *v5; // ebx
  unsigned int Id; // edx
  Scaleform::GFx::MovieDefImpl *v7; // eax
  const Scaleform::String *NameOfExportedResource; // ebp
  Scaleform::GFx::AS2::Environment *v9; // eax
  Scaleform::GFx::AS2::Environment *v10; // eax
  Scaleform::GFx::AS2::ObjectInterface *v11; // ebp
  Scaleform::GFx::AS2::AvmCharacter *v12; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v14; // ebp
  Scaleform::RefCountNTSImpl *pObject; // ecx
  Scaleform::RefCountNTSImpl *v16; // ecx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v17; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v18; // esi
  Scaleform::RefCountNTSImpl *v19; // ecx
  Scaleform::RefCountNTSImpl *v20; // ecx
  Scaleform::GFx::ASStringNode *v21; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v22; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v23; // esi
  Scaleform::RefCountNTSImpl *v24; // ecx
  Scaleform::RefCountNTSImpl *v25; // ecx
  Scaleform::GFx::AS2::Value *Data; // esi
  Scaleform::GFx::ASStringNode *v27; // eax
  unsigned __int8 Flags; // bl
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v32; // eax
  Scaleform::GFx::ResourceId v33; // [esp-4h] [ebp-3Ch]
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > a; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::FunctionRefBase orig; // [esp+1Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value v; // [esp+28h] [ebp-10h] BYREF

  v3 = pscriptCh;
  if ( (pscriptCh[2].RefCount & 0x4000000) != 0 )
  {
    v5 = this->GetGC(this);
    Id = rec->CharacterId.Id;
    memset(&orig, 0, 9);
    v33.Id = Id;
    v7 = (Scaleform::GFx::MovieDefImpl *)(*((int (__thiscall **)(Scaleform::GFx::ASStringNode *))v3->pData + 64))(v3);
    NameOfExportedResource = Scaleform::GFx::MovieDefImpl::GetNameOfExportedResource(v7, v33);
    if ( NameOfExportedResource )
    {
      v9 = this->GetASEnvironment(this);
      pscriptCh = Scaleform::GFx::ASStringManager::CreateStringNode(
                    (Scaleform::GFx::ASStringManager *)v9->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                    (__m128i *)((NameOfExportedResource->HeapTypeBits & 0xFFFFFFFC) + 8),
                    *(_DWORD *)(NameOfExportedResource->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
      ++pscriptCh->RefCount;
      v10 = this->GetASEnvironment(this);
      if ( Scaleform::GFx::AS2::GlobalContext::FindRegisteredClass(
             v5,
             &v10->StringContext,
             (const Scaleform::GFx::ASString *)&pscriptCh,
             (Scaleform::GFx::AS2::FunctionRef *)&orig) )
      {
        if ( orig.Function )
          v11 = &orig.Function->Scaleform::GFx::AS2::ObjectInterface;
        else
          v11 = 0;
        v12 = (Scaleform::GFx::AS2::AvmCharacter *)(*(int (__thiscall **)(int))(*((_DWORD *)&v3->pData
                                                                                + BYTE1(v3[2].HashFlags))
                                                                              + 4))((int)v3 + 4 * BYTE1(v3[2].HashFlags));
        Scaleform::GFx::AS2::AvmCharacter::SetProtoToPrototypeOf(v12, v11);
        inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                     (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&this->pDispObj->pASRoot[3].pMovieImpl,
                     AP_Construct);
        v14 = inserted;
        if ( inserted )
        {
          inserted->Type = Entry_Event;
          ++v3->pManager;
          pObject = inserted->pCharacter.pObject;
          if ( pObject )
            Scaleform::RefCountNTSImpl::Release(pObject);
          v14->pCharacter.pObject = (Scaleform::GFx::InteractiveObject *)v3;
          v16 = v14->pActionBuffer.pObject;
          if ( v16 )
            Scaleform::RefCountNTSImpl::Release(v16);
          v14->pActionBuffer.pObject = 0;
          v14->mEventId.Id = 0x40000;
          v14->mEventId.WcharCode = 0;
          v14->mEventId.KeyCode = 0;
          v14->mEventId.AsciiCode = 0;
          v14->mEventId.RollOverCnt = 0;
          v14->mEventId.ControllerIndex = -1;
          v14->mEventId.KeysState.States = 0;
          v14->mEventId.MouseWheelDelta = 0;
        }
        v17 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&this->pDispObj->pASRoot[3].pMovieImpl,
                AP_Construct);
        v18 = v17;
        if ( v17 )
        {
          v17->Type = Entry_Function;
          ++v3->pManager;
          v19 = v17->pCharacter.pObject;
          if ( v19 )
            Scaleform::RefCountNTSImpl::Release(v19);
          v18->pCharacter.pObject = (Scaleform::GFx::InteractiveObject *)v3;
          v20 = v18->pActionBuffer.pObject;
          if ( v20 )
            Scaleform::RefCountNTSImpl::Release(v20);
          v18->pActionBuffer.pObject = 0;
          Scaleform::GFx::AS2::FunctionRefBase::Assign(&v18->Function, &orig);
        }
      }
      else
      {
        v21 = pscriptCh;
        ++pscriptCh->RefCount;
        memset(&a, 0, sizeof(a));
        v.T.Type = 5;
        v.NV.Int32Value = (int)v21;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &a.Data,
          &a,
          1u);
        if ( &a.Data.Data[a.Data.Size] == (Scaleform::GFx::AS2::Value *)16
          || (Scaleform::GFx::AS2::Value::Value(&a.Data.Data[a.Data.Size - 1], &v), v.T.Type >= 5u) )
        {
          Scaleform::GFx::AS2::Value::DropRefs(&v);
        }
        v22 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&this->pDispObj->pASRoot[3].pMovieImpl,
                AP_Construct);
        v23 = v22;
        if ( v22 )
        {
          v22->Type = Entry_CFunction;
          ++v3->pManager;
          v24 = v22->pCharacter.pObject;
          if ( v24 )
            Scaleform::RefCountNTSImpl::Release(v24);
          v23->pCharacter.pObject = (Scaleform::GFx::InteractiveObject *)v3;
          v25 = v23->pActionBuffer.pObject;
          if ( v25 )
            Scaleform::RefCountNTSImpl::Release(v25);
          v23->pActionBuffer.pObject = 0;
          v23->CFunction = Scaleform::GFx::AS2::AvmSprite::FindClassAndInitializeClassInstance;
          Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
            &v23->FunctionParams,
            &a);
        }
        Data = a.Data.Data;
        Scaleform::ConstructorMov<Scaleform::GFx::AS2::Value>::DestructArray(a.Data.Data, a.Data.Size);
        if ( Data )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
      }
      v27 = pscriptCh;
      --pscriptCh->RefCount;
      if ( !v27->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v27);
    }
    Flags = orig.Flags;
    if ( (orig.Flags & 2) == 0 )
    {
      Function = orig.Function;
      if ( orig.Function )
      {
        RefCount = orig.Function->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          orig.Function->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
        }
      }
    }
    if ( (Flags & 1) == 0 )
    {
      pLocalFrame = orig.pLocalFrame;
      if ( orig.pLocalFrame )
      {
        v32 = orig.pLocalFrame->RefCount;
        if ( (v32 & 0x3FFFFFF) != 0 )
        {
          orig.pLocalFrame->RefCount = v32 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
        }
      }
    }
  }
}
