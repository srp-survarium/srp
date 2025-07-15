void __thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::gotoAndPlay(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *frame,
        Scaleform::GFx::AS3::Value *scene)
{
  const Scaleform::GFx::AS3::Value *v4; // esi
  Scaleform::GFx::DisplayObject *pObject; // edi
  unsigned int v7; // eax
  const Scaleform::GFx::MovieDataDef::SceneInfo *SceneInfo; // eax
  const char *v9; // ecx
  unsigned int v10; // eax
  const Scaleform::GFx::AS3::VM::Error *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::Value *v14; // eax
  Scaleform::GFx::AS3::VM_vtbl *v15; // eax
  Scaleform::StringDataPtr v16; // [esp-8h] [ebp-1Ch]
  unsigned int r; // [esp+Ch] [ebp-8h] BYREF
  Scaleform::GFx::ASStringNode *v18; // [esp+10h] [ebp-4h]

  v4 = frame;
  pObject = this->pDispObj.pObject;
  if ( (frame->Flags & 0x1F) == 0xA )
  {
    if ( !Scaleform::GFx::AS3::Instances::fl_display::MovieClip::GetLabeledFrame(
            this,
            (Scaleform::GFx::ASStringNode *)pObject,
            frame,
            scene,
            (unsigned int *)&scene) )
    {
      v7 = ((int (__thiscall *)(Scaleform::GFx::DisplayObject *))pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].GetY)(pObject);
      SceneInfo = Scaleform::GFx::AS3::Instances::fl_display::MovieClip::GetSceneInfo(this, v7);
      v9 = "unknown";
      if ( SceneInfo )
        v9 = (const char *)((SceneInfo->Name.HeapTypeBits & 0xFFFFFFFC) + 8);
      v16.pStr = v9;
      if ( v9 )
        v10 = strlen(v9);
      else
        v10 = 0;
      v16.Size = v10;
      Scaleform::GFx::AS3::VM::Error::Error(
        (Scaleform::GFx::AS3::VM::Error *)&r,
        eFrameLabelNotFoundInScene,
        this->pTraits.pObject->pVM,
        v4,
        v16);
      Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v11);
      v12 = v18;
      --v18->RefCount;
      if ( !v12->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      return;
    }
  }
  else
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(frame, (Scaleform::GFx::AS3::CheckResult *)&frame, &r)->Result )
      return;
    scene = (Scaleform::GFx::AS3::Value *)(r - 1);
  }
  pVM = this->pTraits.pObject->pVM;
  v14 = (const Scaleform::GFx::AS3::Value *)((int (__thiscall *)(Scaleform::GFx::DisplayObject *))pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].GetY)(pObject);
  if ( scene != v14 )
  {
    Scaleform::GFx::AS3::MovieRoot::RemoveActionQueueEntriesFor(
      (Scaleform::GFx::AS3::MovieRoot *)pVM[1].__vftable,
      AL_Frame,
      this->pDispObj.pObject);
    ((void (__thiscall *)(Scaleform::GFx::DisplayObject *, Scaleform::GFx::AS3::Value *))pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].SetXScale)(
      pObject,
      scene);
  }
  ((void (__thiscall *)(Scaleform::GFx::DisplayObject *, _DWORD))pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].SetZScale)(
    pObject,
    0);
  Scaleform::GFx::AS3::MovieRoot::QueueFrameActions((Scaleform::GFx::AS3::MovieRoot *)pVM[1].__vftable);
  v15 = pVM[1].__vftable;
  if ( ((int)v15[212].GetAdvanceStats & 1) == 0 )
  {
    LOBYTE(v15[212].GetAdvanceStats) |= 1u;
    Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue((Scaleform::GFx::AS3::MovieRoot *)pVM[1].__vftable, AL_Highest);
    Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue((Scaleform::GFx::AS3::MovieRoot *)pVM[1].__vftable, AL_High);
    Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue((Scaleform::GFx::AS3::MovieRoot *)pVM[1].__vftable, AL_Frame);
    LOBYTE(pVM[1].__vftable[212].GetAdvanceStats) &= ~1u;
  }
}
