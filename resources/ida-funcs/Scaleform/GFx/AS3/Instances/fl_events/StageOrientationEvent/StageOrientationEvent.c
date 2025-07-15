void __thiscall Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent::StageOrientationEvent(
        Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  Scaleform::GFx::AS3::Value *p_BeforeOrientation; // edi
  Scaleform::GFx::AS3::Value *p_AfterOrientation; // ebx
  Scaleform::GFx::AS3::Value *v7; // ecx
  unsigned int v8; // edx
  Scaleform::GFx::AS3::Value *v9; // ecx
  unsigned int Flags; // edx
  Scaleform::GFx::AS3::Value::V2U v11; // [esp+14h] [ebp-4h]

  Scaleform::GFx::AS3::Instances::fl::Object::Object((Scaleform::GFx::AS3::Instances::fl::Catch *)this, t);
  pObject = this->pTraits.pObject;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent_vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::Event::`vftable';
  p_EmptyStringNode = &pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->Type.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  this->CurrentTarget.pObject = 0;
  this->Target.pObject = 0;
  *((_BYTE *)&this->Scaleform::GFx::AS3::Instances::fl_events::Event + 48) &= 0xC0u;
  this->Phase = 2;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent_vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent::`vftable';
  p_BeforeOrientation = &this->BeforeOrientation;
  this->BeforeOrientation.Flags = 0;
  this->BeforeOrientation.Bonus.pWeakProxy = 0;
  p_AfterOrientation = &this->AfterOrientation;
  this->AfterOrientation.Flags = 0;
  this->AfterOrientation.Bonus.pWeakProxy = 0;
  if ( (this->BeforeOrientation.Flags & 0x1F) > 9 )
  {
    v7 = &this->BeforeOrientation;
    if ( (this->BeforeOrientation.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(v7);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(v7);
  }
  v8 = p_BeforeOrientation->Flags & 0xFFFFFFEC;
  this->BeforeOrientation.value.VS._1.VInt = 0;
  p_BeforeOrientation->Flags = v8 | 0xC;
  this->BeforeOrientation.value.VS._2 = v11;
  if ( (p_AfterOrientation->Flags & 0x1F) > 9 )
  {
    v9 = &this->AfterOrientation;
    if ( (p_AfterOrientation->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(v9);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(v9);
  }
  Flags = p_AfterOrientation->Flags;
  this->AfterOrientation.value.VS._2 = v11;
  this->AfterOrientation.value.VS._1.VInt = 0;
  p_AfterOrientation->Flags = Flags & 0xFFFFFFE0 | 0xC;
}
