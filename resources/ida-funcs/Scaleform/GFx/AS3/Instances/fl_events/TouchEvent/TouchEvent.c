void __thiscall Scaleform::GFx::AS3::Instances::fl_events::TouchEvent::TouchEvent(
        Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax

  Scaleform::GFx::AS3::Instances::fl::Object::Object(this, t);
  pObject = this->pTraits.pObject;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent_vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::Event::`vftable';
  p_EmptyStringNode = &pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->Type.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  this->CurrentTarget.pObject = 0;
  this->Target.pObject = 0;
  *((_BYTE *)&this->Scaleform::GFx::AS3::Instances::fl_events::Event + 48) &= 0xC0u;
  this->Phase = 2;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent_vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::TouchEvent::`vftable';
  this->RelatedObj.pObject = 0;
  this->SizeY = 0.0;
  this->SizeX = 0.0;
  this->ControlKey = 0;
  this->LocalY = 0.0;
  this->CommandKey = 0;
  this->LocalX = 0.0;
  this->ShiftKey = 0;
  this->StageY = 0.0;
  this->CtrlKey = 0;
  this->StageX = 0.0;
  this->AltKey = 0;
  this->TouchPointID = 0;
  this->PrimaryPoint = 0;
  this->Pressure = 1.0;
  this->LocalInitialized = 0;
}
