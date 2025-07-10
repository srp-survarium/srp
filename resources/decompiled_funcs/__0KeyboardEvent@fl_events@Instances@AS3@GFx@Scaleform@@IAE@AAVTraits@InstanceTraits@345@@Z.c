void __thiscall Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent::KeyboardEvent(
        Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax

  Scaleform::GFx::AS3::Instances::fl::Object::Object((Scaleform::GFx::AS3::Instances::fl::Catch *)this, t);
  pObject = this->pTraits.pObject;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent_vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::Event::`vftable';
  p_EmptyStringNode = &pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->Type.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  this->CurrentTarget.pObject = 0;
  this->Target.pObject = 0;
  *((_BYTE *)&this->Scaleform::GFx::AS3::Instances::fl_events::Event + 48) &= 0xC0u;
  this->Phase = 2;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent_vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent::`vftable';
  this->EvtId.Id = 0;
  this->EvtId.WcharCode = 0;
  this->EvtId.KeyCode = 0;
  this->EvtId.AsciiCode = 0;
  this->EvtId.RollOverCnt = 0;
  this->EvtId.KeysState.States = 0;
  this->EvtId.MouseWheelDelta = 0;
  this->EvtId.ControllerIndex = -1;
  this->KeyLocation = -1;
}
