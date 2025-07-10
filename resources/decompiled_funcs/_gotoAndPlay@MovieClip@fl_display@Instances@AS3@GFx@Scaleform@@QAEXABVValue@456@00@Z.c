void __userpurge Scaleform::GFx::AS3::Instances::fl_display::MovieClip::gotoAndPlay(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip *this@<ecx>,
        int a2@<edi>,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *frame,
        Scaleform::GFx::AS3::Value *scene,
        int a6)
{
  Scaleform::GFx::DisplayObject *pObject; // esi
  unsigned int v8; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::AS3::VM *v12; // edi
  int v13; // eax
  Scaleform::GFx::AS3::VM_vtbl *v14; // eax
  unsigned int r; // [esp+8h] [ebp-8h] BYREF
  Scaleform::GFx::ASStringNode *v17; // [esp+Ch] [ebp-4h]

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
      v8 = ((int (__thiscall *)(Scaleform::GFx::DisplayObject *))pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].GetY)(pObject);
      Scaleform::GFx::AS3::Instances::fl_display::MovieClip::GetSceneInfo(this, v8);
      pVM = this->pTraits.pObject->pVM;
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&r, eFrameLabelNotFoundInScene, pVM);
      Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v10);
      v11 = v17;
      --v17->RefCount;
      if ( !v11->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      return;
    }
  }
  else
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(frame, (Scaleform::GFx::AS3::CheckResult *)&frame, &r)->Result )
      return;
    scene = (Scaleform::GFx::AS3::Value *)(r - 1);
  }
  v12 = this->pTraits.pObject->pVM;
  v13 = ((int (__thiscall *)(Scaleform::GFx::DisplayObject *, int))pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].GetY)(
          pObject,
          a2);
  if ( a6 != v13 )
  {
    Scaleform::GFx::AS3::MovieRoot::RemoveActionQueueEntriesFor(
      (Scaleform::GFx::AS3::MovieRoot *)v12[1].__vftable,
      AL_Frame,
      this->pDispObj.pObject);
    ((void (__thiscall *)(Scaleform::GFx::DisplayObject *, int))pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].SetXScale)(
      pObject,
      a6);
  }
  ((void (__thiscall *)(Scaleform::GFx::DisplayObject *, _DWORD))pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].SetZScale)(
    pObject,
    0);
  Scaleform::GFx::AS3::MovieRoot::QueueFrameActions((Scaleform::GFx::AS3::MovieRoot *)v12[1].__vftable);
  v14 = v12[1].__vftable;
  if ( ((int)v14[212].GetAdvanceStats & 1) == 0 )
  {
    LOBYTE(v14[212].GetAdvanceStats) |= 1u;
    Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue((Scaleform::GFx::AS3::MovieRoot *)v12[1].__vftable, AL_Highest);
    Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue((Scaleform::GFx::AS3::MovieRoot *)v12[1].__vftable, AL_High);
    Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue((Scaleform::GFx::AS3::MovieRoot *)v12[1].__vftable, AL_Frame);
    LOBYTE(v12[1].__vftable[212].GetAdvanceStats) &= ~1u;
  }
}
