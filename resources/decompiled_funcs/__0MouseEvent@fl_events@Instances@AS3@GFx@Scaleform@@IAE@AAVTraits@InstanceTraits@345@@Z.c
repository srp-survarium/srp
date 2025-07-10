void __thiscall Scaleform::GFx::AS3::Instances::fl_events::MouseEvent::MouseEvent(
        Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax

  Scaleform::GFx::AS3::Instances::fl::Object::Object((Scaleform::GFx::AS3::Instances::fl::Catch *)this, t);
  pObject = this->pTraits.pObject;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent_vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::Event::`vftable';
  p_EmptyStringNode = &pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->Type.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  this->CurrentTarget.pObject = 0;
  this->Target.pObject = 0;
  *((_BYTE *)&this->Scaleform::GFx::AS3::Instances::fl_events::Event + 48) &= 0xC0u;
  this->Phase = 2;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent_vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::MouseEvent::`vftable';
  this->RelatedObj.pObject = 0;
  this->LocalY = 0.0;
  this->ShiftKey = 0;
  this->LocalX = 0.0;
  this->CtrlKey = 0;
  this->AltKey = 0;
  this->Delta = 0;
  this->ButtonsMask = 0;
}
