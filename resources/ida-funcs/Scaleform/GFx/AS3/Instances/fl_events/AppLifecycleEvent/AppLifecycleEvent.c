void __thiscall Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent::AppLifecycleEvent(
        Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  Scaleform::GFx::AS3::Value *p_Status; // edi
  Scaleform::GFx::AS3::Value *v6; // ecx
  unsigned int v7; // edx
  Scaleform::GFx::AS3::Value::V2U v8; // [esp+10h] [ebp-4h]

  Scaleform::GFx::AS3::Instances::fl::Object::Object(this, t);
  pObject = this->pTraits.pObject;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent_vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::Event::`vftable';
  p_EmptyStringNode = &pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->Type.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  this->CurrentTarget.pObject = 0;
  this->Target.pObject = 0;
  *((_BYTE *)&this->Scaleform::GFx::AS3::Instances::fl_events::Event + 48) &= 0xC0u;
  p_Status = &this->Status;
  this->Phase = 2;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent_vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent::`vftable';
  this->Status.Flags = 0;
  this->Status.Bonus.pWeakProxy = 0;
  if ( (this->Status.Flags & 0x1F) > 9 )
  {
    v6 = &this->Status;
    if ( (this->Status.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(v6);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(v6);
  }
  v7 = p_Status->Flags & 0xFFFFFFE0 | 0xC;
  this->Status.value.VS._1.VInt = 0;
  this->Status.value.VS._2 = v8;
  p_Status->Flags = v7;
}
