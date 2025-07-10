bool __thiscall Scaleform::GFx::AS3::AvmDisplayObj::OnUnloading(Scaleform::GFx::AS3::AvmDisplayObj *this, bool m)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // eax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v4; // ebx
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *p_AVMVersion; // edi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *NewEntry; // esi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pInsertEntry; // eax
  Scaleform::GFx::DisplayObject *pDispObj; // edi
  Scaleform::RefCountNTSImpl *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v10; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value *p_Function; // edi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  bool v14; // zf
  Scaleform::RefCountVImpl *v15; // ecx
  bool result; // al

  pAS3RawPtr = this->pAS3RawPtr;
  if ( !pAS3RawPtr )
    pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
  v4 = pAS3RawPtr;
  if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
    v4 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
  if ( !v4
    || !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::HasEventHandler(
          v4,
          (const Scaleform::GFx::ASString *)&this->pDispObj->pASRoot[15].pMovieImpl,
          0)
    && !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::HasEventHandler(
          v4,
          (const Scaleform::GFx::ASString *)&this->pDispObj->pASRoot[15].pASSupport,
          0) )
  {
    return m;
  }
  p_AVMVersion = (Scaleform::GFx::AS3::MovieRoot::ActionQueueType *)&this->pDispObj->pASRoot[3].AVMVersion;
  NewEntry = Scaleform::GFx::AS3::MovieRoot::ActionQueueType::GetNewEntry(p_AVMVersion);
  pInsertEntry = p_AVMVersion->Entries[2].pInsertEntry;
  if ( pInsertEntry )
  {
    NewEntry->pNextEntry = pInsertEntry->pNextEntry;
    p_AVMVersion->Entries[2].pInsertEntry->pNextEntry = NewEntry;
  }
  else
  {
    NewEntry->pNextEntry = p_AVMVersion->Entries[2].pActionRoot;
    p_AVMVersion->Entries[2].pActionRoot = NewEntry;
  }
  p_AVMVersion->Entries[2].pInsertEntry = NewEntry;
  if ( !NewEntry->pNextEntry )
    p_AVMVersion->Entries[2].pLastEntry = NewEntry;
  ++p_AVMVersion->ModId;
  pDispObj = this->pDispObj;
  NewEntry->Type = Entry_Buffer;
  if ( pDispObj )
    ++pDispObj->RefCount;
  pObject = NewEntry->pCharacter.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  NewEntry->pCharacter.pObject = pDispObj;
  NewEntry->mEventId.Id = (unsigned int)&vostok::memory::s_CRT_arena[5574216];
  NewEntry->mEventId.WcharCode = 0;
  NewEntry->mEventId.KeyCode = 0;
  NewEntry->mEventId.AsciiCode = 0;
  NewEntry->mEventId.RollOverCnt = 0;
  NewEntry->mEventId.ControllerIndex = -1;
  NewEntry->mEventId.KeysState.States = 0;
  NewEntry->mEventId.MouseWheelDelta = 0;
  NewEntry->CFunction = 0;
  v10 = NewEntry->pAS3Obj.pObject;
  if ( v10 )
  {
    if ( ((unsigned __int8)v10 & 1) != 0 )
    {
      NewEntry->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v10 - 1);
    }
    else
    {
      RefCount = v10->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        v10->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
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
      v14 = pWeakProxy->RefCount-- == 1;
      if ( v14 )
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
  v15 = (Scaleform::RefCountVImpl *)NewEntry->pNLoadInitCL.pObject;
  if ( v15 )
    Scaleform::RefCountImpl::Release(v15);
  NewEntry->pNLoadInitCL.pObject = 0;
  this->pDispObj->Depth = -2;
  v14 = Scaleform::GFx::AS3::AvmDisplayObj::IsStageAccessible(this) == 0;
  result = m;
  if ( !v14 )
    this->Flags |= 1u;
  return result;
}
