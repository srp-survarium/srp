void __thiscall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::NetStatusEvent(
        Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  Scaleform::GFx::AS3::Traits *v5; // edx
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // eax

  Scaleform::GFx::AS3::Instances::fl::Object::Object(this, t);
  pObject = this->pTraits.pObject;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent_vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::Event::`vftable';
  p_EmptyStringNode = &pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->Type.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  this->CurrentTarget.pObject = 0;
  this->Target.pObject = 0;
  *((_BYTE *)&this->Scaleform::GFx::AS3::Instances::fl_events::Event + 48) &= 0xC0u;
  v5 = this->pTraits.pObject;
  this->Phase = 2;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent_vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::`vftable';
  v6 = &v5->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->Code.pNode = v6;
  ++v6->RefCount;
  v7 = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->Level.pNode = v7;
  ++v7->RefCount;
}
