void __thiscall Scaleform::GFx::AS2::AvmTextField::OnScroll(Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::InteractiveObject *v2; // edi
  int v3; // esi
  Scaleform::GFx::AS2::MovieRoot::ActionQueueType *v4; // ecx
  Scaleform::GFx::ASStringManager *v5; // ecx
  Scaleform::GFx::ASStringNode *ConstStringNode; // esi
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v10; // esi
  Scaleform::RefCountNTSImpl *v11; // ecx
  Scaleform::RefCountNTSImpl *v12; // ecx
  Scaleform::GFx::AS2::Value *Data; // esi
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > a; // [esp+10h] [ebp-60h] BYREF
  Scaleform::GFx::AS2::Value v; // [esp+1Ch] [ebp-54h] BYREF
  Scaleform::GFx::AS2::MovieRoot::ActionEntry entry; // [esp+2Ch] [ebp-44h] BYREF

  v2 = (Scaleform::GFx::InteractiveObject *)*((_DWORD *)&this[-1].VariableVal.NV + 3);
  v3 = ((int (__thiscall *)(Scaleform::GFx::ASString *))this[-1].VariableName.pNode[5].pManager)(&this[-1].VariableName);
  memset((void *)&entry.mEventId, 0, 13);
  entry.mEventId.RollOverCnt = 0;
  memset(&entry.mEventId.KeysState, 0, 11);
  entry.mEventId.ControllerIndex = -1;
  memset(&entry.FunctionParams, 0, 16);
  entry.pNextEntry = 0;
  entry.Type = Entry_CFunction;
  if ( v2 )
    ++v2->RefCount;
  v4 = (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)(*(_DWORD *)(*((_DWORD *)&this[-1].VariableVal.NV + 3) + 16)
                                                         + 68);
  entry.pCharacter.pObject = v2;
  entry.pActionBuffer.pObject = 0;
  entry.CFunction = Scaleform::GFx::AS2::AvmTextField::BroadcastMessage;
  if ( !Scaleform::GFx::AS2::MovieRoot::ActionQueueType::FindEntry(v4, AP_Frame, &entry) )
  {
    v5 = *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v3 + 116) + 20) + 12) + 788);
    memset(&a, 0, sizeof(a));
    ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v5, "onScroller", 0xAu, 0);
    ++ConstStringNode->RefCount;
    ++ConstStringNode->RefCount;
    v.T.Type = 5;
    v.NV.Int32Value = (int)ConstStringNode;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &a.Data,
      &a,
      1u);
    if ( &a.Data.Data[a.Data.Size] == (Scaleform::GFx::AS2::Value *)16
      || (Scaleform::GFx::AS2::Value::Value(&a.Data.Data[a.Data.Size - 1], &v), v.T.Type >= 5u) )
    {
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    }
    if ( ConstStringNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
    v.T.Type = 7;
    if ( v2 )
    {
      pObject = v2->pNameHandle.pObject;
      if ( !pObject )
        pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v2);
      v.NV.Int32Value = (int)pObject;
      if ( pObject )
        ++pObject->RefCount;
    }
    else
    {
      v.NV.Int32Value = 0;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &a.Data,
      &a,
      a.Data.Size + 1);
    if ( &a.Data.Data[a.Data.Size] == (Scaleform::GFx::AS2::Value *)16
      || (Scaleform::GFx::AS2::Value::Value(&a.Data.Data[a.Data.Size - 1], &v), v.T.Type >= 5u) )
    {
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    }
    inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                 (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)(*(_DWORD *)(*((_DWORD *)&this[-1].VariableVal.NV + 3)
                                                                               + 16)
                                                                   + 68),
                 AP_Frame);
    v10 = inserted;
    inserted->Type = Entry_CFunction;
    if ( v2 )
      ++v2->RefCount;
    v11 = inserted->pCharacter.pObject;
    if ( v11 )
      Scaleform::RefCountNTSImpl::Release(v11);
    v10->pCharacter.pObject = v2;
    v12 = v10->pActionBuffer.pObject;
    if ( v12 )
      Scaleform::RefCountNTSImpl::Release(v12);
    v10->pActionBuffer.pObject = 0;
    v10->CFunction = Scaleform::GFx::AS2::AvmTextField::BroadcastMessage;
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
      &v10->FunctionParams,
      &a);
    Data = a.Data.Data;
    Scaleform::ConstructorMov<Scaleform::GFx::AS2::Value>::DestructArray(a.Data.Data, a.Data.Size);
    if ( Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  }
  Scaleform::GFx::AS2::MovieRoot::ActionEntry::~ActionEntry(&entry);
}
