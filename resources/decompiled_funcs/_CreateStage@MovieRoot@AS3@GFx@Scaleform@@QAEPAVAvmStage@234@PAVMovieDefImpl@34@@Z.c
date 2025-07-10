Scaleform::GFx::AS3::AvmStage *__thiscall Scaleform::GFx::AS3::MovieRoot::CreateStage(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::MovieDefImpl *pdefImpl)
{
  char *v3; // edi
  Scaleform::GFx::AS3::Stage *v4; // eax
  Scaleform::GFx::AS3::Stage *v5; // ebp
  Scaleform::GFx::AS3::Stage *pObject; // ecx
  Scaleform::GFx::AS3::AvmStage *v7; // eax
  Scaleform::GFx::AS3::ASVM *v8; // ecx
  Scaleform::GFx::AS3::VMAppDomain *AppDomain; // ecx
  Scaleform::GFx::AS3::Stage *v10; // ebp
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *p_ActionQueue; // edi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *NewEntry; // esi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pInsertEntry; // eax
  Scaleform::RefCountNTSImpl *v14; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v15; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value *p_Function; // edi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::RefCountVImpl *v20; // ecx
  Scaleform::GFx::AS3::AvmStage *result; // eax
  Scaleform::GFx::AS3::AvmStage *avmStage; // [esp+14h] [ebp+4h]

  v3 = (char *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 208, 0);
  if ( v3 )
  {
    Scaleform::GFx::AS3::Stage::Stage(
      (Scaleform::GFx::AS3::Stage *)v3,
      pdefImpl,
      this,
      0,
      (Scaleform::GFx::ResourceId)0x40000);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  pObject = this->pStage.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pStage.pObject = v5;
  if ( v3 == (char *)-168 )
  {
    avmStage = 0;
  }
  else
  {
    Scaleform::GFx::AS3::AvmStage::AvmStage((Scaleform::GFx::AS3::AvmStage *)(v3 + 168), v5);
    avmStage = v7;
  }
  v8 = this->pAVM.pObject;
  if ( v8->CallStack.Size && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    AppDomain = v8->CallStack.Pages[(v8->CallStack.Size - 1) >> 6][(v8->CallStack.Size - 1) & 0x3F].pFile->AppDomain;
  else
    AppDomain = v8->CurrentDomain;
  if ( Scaleform::GFx::AS3::VMAppDomain::Enabled )
    avmStage->AppDomain = AppDomain;
  v10 = this->pStage.pObject;
  p_ActionQueue = &this->ActionQueue;
  NewEntry = Scaleform::GFx::AS3::MovieRoot::ActionQueueType::GetNewEntry(&this->ActionQueue);
  pInsertEntry = p_ActionQueue->Entries[0].pInsertEntry;
  if ( pInsertEntry )
  {
    NewEntry->pNextEntry = pInsertEntry->pNextEntry;
    p_ActionQueue->Entries[0].pInsertEntry->pNextEntry = NewEntry;
  }
  else
  {
    NewEntry->pNextEntry = p_ActionQueue->Entries[0].pActionRoot;
    p_ActionQueue->Entries[0].pActionRoot = NewEntry;
  }
  p_ActionQueue->Entries[0].pInsertEntry = NewEntry;
  if ( !NewEntry->pNextEntry )
    p_ActionQueue->Entries[0].pLastEntry = NewEntry;
  ++p_ActionQueue->ModId;
  NewEntry->Type = Entry_Buffer;
  if ( v10 )
    ++v10->RefCount;
  v14 = NewEntry->pCharacter.pObject;
  if ( v14 )
    Scaleform::RefCountNTSImpl::Release(v14);
  NewEntry->pCharacter.pObject = v10;
  NewEntry->mEventId.Id = 1;
  NewEntry->mEventId.WcharCode = 0;
  NewEntry->mEventId.KeyCode = 0;
  NewEntry->mEventId.AsciiCode = 0;
  NewEntry->mEventId.RollOverCnt = 0;
  NewEntry->mEventId.ControllerIndex = -1;
  NewEntry->mEventId.KeysState.States = 0;
  NewEntry->mEventId.MouseWheelDelta = 0;
  NewEntry->CFunction = 0;
  v15 = NewEntry->pAS3Obj.pObject;
  if ( v15 )
  {
    if ( ((unsigned __int8)v15 & 1) != 0 )
    {
      NewEntry->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v15 - 1);
    }
    else
    {
      RefCount = v15->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        v15->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v15);
      }
    }
    NewEntry->pAS3Obj.pObject = 0;
  }
  p_Function = &NewEntry->Function;
  if ( (NewEntry->Function.Flags & 0x1F) > 9 )
  {
    if ( (NewEntry->Function.Flags & 0x200) != 0 )
    {
      pWeakProxy = NewEntry->Function.Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      p_Function->Flags &= 0xFFFFFDE0;
      NewEntry->Function.Bonus.pWeakProxy = 0;
      NewEntry->Function.value.VS._1.VInt = 0;
      NewEntry->Function.value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&NewEntry->Function);
    }
  }
  p_Function->Flags &= 0xFFFFFFE0;
  v20 = (Scaleform::RefCountVImpl *)NewEntry->pNLoadInitCL.pObject;
  if ( v20 )
    Scaleform::RefCountImpl::Release(v20);
  result = avmStage;
  NewEntry->pNLoadInitCL.pObject = 0;
  return result;
}
