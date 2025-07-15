char __thiscall Scaleform::GFx::AS3::AvmDisplayObj::OnEvent(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        const Scaleform::GFx::EventId *id)
{
  unsigned int v2; // eax
  Scaleform::GFx::DisplayObject *v4; // ebp
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v5; // edi
  Scaleform::RefCountNTSImpl *v6; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v7; // ecx
  unsigned int v8; // eax
  Scaleform::GFx::AS3::Value *v9; // esi
  Scaleform::GFx::AS3::WeakProxy *v10; // eax
  bool v11; // zf
  Scaleform::RefCountVImpl *v12; // ecx
  Scaleform::GFx::DisplayObject *pDispObj; // ebp
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *inserted; // edi
  Scaleform::RefCountNTSImpl *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v17; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value *p_Function; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::RefCountVImpl *v21; // ecx
  Scaleform::GFx::AS3::MovieRoot::ActionLevel v22; // [esp-4h] [ebp-14h]

  v2 = id->Id;
  if ( id->Id > 0x1000013 )
  {
    if ( v2 - 16777237 > 1 )
      return 0;
    if ( this->pAS3RawPtr || this->pAS3CollectiblePtr.pObject )
    {
      v22 = AL_Frame;
      goto LABEL_34;
    }
    return 1;
  }
  if ( id->Id == 16777235 )
  {
    if ( this->pAS3RawPtr || this->pAS3CollectiblePtr.pObject )
    {
      v22 = AL_Render;
LABEL_34:
      pDispObj = this->pDispObj;
      inserted = Scaleform::GFx::AS3::MovieRoot::InsertEmptyAction(
                   (Scaleform::GFx::AS3::MovieRoot *)pDispObj->pASRoot,
                   v22);
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
      v17 = inserted->pAS3Obj.pObject;
      if ( v17 )
      {
        if ( ((unsigned __int8)v17 & 1) != 0 )
        {
          inserted->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v17 - 1);
        }
        else
        {
          RefCount = v17->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v17->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v17);
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
          v11 = pWeakProxy->RefCount-- == 1;
          if ( v11 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
          inserted->Function.Bonus.pWeakProxy = 0;
          inserted->Function.value.VS._1.VInt = 0;
          inserted->Function.value.VS._2.VObj = 0;
          p_Function->Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&inserted->Function);
        }
      }
      p_Function->Flags &= 0xFFFFFFE0;
      v21 = (Scaleform::RefCountVImpl *)inserted->pNLoadInitCL.pObject;
      if ( v21 )
        Scaleform::RefCountImpl::Release(v21);
      inserted->pNLoadInitCL.pObject = 0;
      return 1;
    }
    return 1;
  }
  if ( v2 != 2 )
    return 0;
  if ( (this->pAS3RawPtr || this->pAS3CollectiblePtr.pObject) && (this->Flags & 2) != 0 )
  {
    v4 = this->pDispObj;
    v5 = Scaleform::GFx::AS3::MovieRoot::InsertEmptyAction((Scaleform::GFx::AS3::MovieRoot *)v4->pASRoot, AL_EnterFrame);
    v5->Type = Entry_Buffer;
    if ( v4 )
      ++v4->RefCount;
    v6 = v5->pCharacter.pObject;
    if ( v6 )
      Scaleform::RefCountNTSImpl::Release(v6);
    v5->pCharacter.pObject = v4;
    v5->mEventId.Id = id->Id;
    v5->mEventId.WcharCode = id->WcharCode;
    v5->mEventId.KeyCode = id->KeyCode;
    v5->mEventId.AsciiCode = id->AsciiCode;
    v5->mEventId.RollOverCnt = id->RollOverCnt;
    v5->mEventId.ControllerIndex = id->ControllerIndex;
    v5->mEventId.KeysState.States = id->KeysState.States;
    v5->mEventId.MouseWheelDelta = id->MouseWheelDelta;
    v5->CFunction = 0;
    v7 = v5->pAS3Obj.pObject;
    if ( v7 )
    {
      if ( ((unsigned __int8)v7 & 1) != 0 )
      {
        v5->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v7 - 1);
      }
      else
      {
        v8 = v7->RefCount;
        if ( (v8 & 0x3FFFFF) != 0 )
        {
          v7->RefCount = v8 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
        }
      }
      v5->pAS3Obj.pObject = 0;
    }
    v9 = &v5->Function;
    if ( (v5->Function.Flags & 0x1F) > 9 )
    {
      if ( (v5->Function.Flags & 0x200) != 0 )
      {
        v10 = v5->Function.Bonus.pWeakProxy;
        v11 = v10->RefCount-- == 1;
        if ( v11 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
        v9->Flags &= 0xFFFFFDE0;
        v5->Function.Bonus.pWeakProxy = 0;
        v5->Function.value.VS._1.VInt = 0;
        v5->Function.value.VS._2.VObj = 0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v5->Function);
      }
    }
    v9->Flags &= 0xFFFFFFE0;
    v12 = (Scaleform::RefCountVImpl *)v5->pNLoadInitCL.pObject;
    if ( v12 )
      Scaleform::RefCountImpl::Release(v12);
    v5->pNLoadInitCL.pObject = 0;
  }
  this->Flags |= 2u;
  return 1;
}
