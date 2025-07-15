Scaleform::GFx::AS3::Class *__thiscall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::GetEventClass(
        Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *this)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::StringDataPtr gname; // [esp+0h] [ebp-8h] BYREF

  pObject = this->pTraits.pObject;
  gname.pStr = "flash.events.NetStatusEvent";
  gname.Size = 27;
  return Scaleform::GFx::AS3::VM::GetClass(pObject->pVM, &gname, pObject->pVM->CurrentDomain);
}
