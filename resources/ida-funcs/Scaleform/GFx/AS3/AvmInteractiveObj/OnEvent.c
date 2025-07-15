char __thiscall Scaleform::GFx::AS3::AvmInteractiveObj::OnEvent(
        Scaleform::GFx::AS3::AvmInteractiveObj *this,
        const Scaleform::GFx::EventId *id)
{
  unsigned int v2; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // eax
  Scaleform::GFx::DisplayObject *v5; // edx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v6; // ecx
  Scaleform::GFx::DisplayObject *pDispObj; // ebp
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *inserted; // esi
  Scaleform::RefCountNTSImpl *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v10; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value *p_Function; // edi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::RefCountVImpl *v15; // ecx

  v2 = id->Id;
  if ( id->Id > 0x2000 )
  {
    if ( v2 > 0x100000E )
    {
      if ( v2 != 16777236 )
        return Scaleform::GFx::AS3::AvmDisplayObj::OnEvent(this, id);
      pDispObj = this->pDispObj;
      inserted = Scaleform::GFx::AS3::MovieRoot::InsertEmptyAction(
                   (Scaleform::GFx::AS3::MovieRoot *)pDispObj->pASRoot,
                   AL_ControllerEvents);
      inserted->Type = Entry_Buffer;
      if ( pDispObj )
        ++pDispObj->RefCount;
      pObject = inserted->pCharacter.pObject;
      if ( pObject )
        Scaleform::RefCountNTSImpl::Release(pObject);
      inserted->pCharacter.pObject = pDispObj;
      inserted->mEventId.Id = id->Id;
      inserted->mEventId.WcharCode = id->WcharCode;
      inserted->mEventId.KeyCode = id->KeyCode;
      inserted->mEventId.AsciiCode = id->AsciiCode;
      inserted->mEventId.RollOverCnt = id->RollOverCnt;
      inserted->mEventId.ControllerIndex = id->ControllerIndex;
      inserted->mEventId.KeysState.States = id->KeysState.States;
      inserted->mEventId.MouseWheelDelta = id->MouseWheelDelta;
      inserted->CFunction = 0;
      v10 = inserted->pAS3Obj.pObject;
      if ( v10 )
      {
        if ( ((unsigned __int8)v10 & 1) != 0 )
        {
          inserted->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v10 - 1);
        }
        else
        {
          RefCount = v10->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v10->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
          }
        }
        inserted->pAS3Obj.pObject = 0;
      }
      p_Function = &inserted->Function;
      if ( (inserted->Function.Flags & 0x1F) > 9 )
      {
        if ( (inserted->Function.Flags & 0x200) != 0 )
        {
          pWeakProxy = inserted->Function.Bonus.pWeakProxy;
          if ( pWeakProxy->RefCount-- == 1 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
          p_Function->Flags &= 0xFFFFFDE0;
          inserted->Function.Bonus.pWeakProxy = 0;
          inserted->Function.value.VS._1.VInt = 0;
          inserted->Function.value.VS._2.VObj = 0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&inserted->Function);
        }
      }
      p_Function->Flags &= 0xFFFFFFE0;
      v15 = (Scaleform::RefCountVImpl *)inserted->pNLoadInitCL.pObject;
      if ( v15 )
        Scaleform::RefCountImpl::Release(v15);
      inserted->pNLoadInitCL.pObject = 0;
      return 1;
    }
    if ( v2 < 0x100000A && v2 != 0x4000 )
      return Scaleform::GFx::AS3::AvmDisplayObj::OnEvent(this, id);
  }
  else if ( id->Id != 0x2000 && v2 != 8 && v2 != 16 && v2 != 32 )
  {
    return Scaleform::GFx::AS3::AvmDisplayObj::OnEvent(this, id);
  }
  pAS3RawPtr = this->pAS3RawPtr;
  if ( !pAS3RawPtr && !this->pAS3CollectiblePtr.pObject )
    return 1;
  v5 = this->pDispObj;
  if ( pAS3RawPtr )
    v6 = this->pAS3RawPtr;
  else
    v6 = this->pAS3CollectiblePtr.pObject;
  if ( ((unsigned __int8)v6 & 1) != 0 )
    v6 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v6 - 1);
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(v6, id, v5);
  return 1;
}
