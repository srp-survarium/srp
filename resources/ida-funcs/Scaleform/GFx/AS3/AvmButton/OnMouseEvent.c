char __thiscall Scaleform::GFx::AS3::AvmButton::OnMouseEvent(
        Scaleform::GFx::AS3::AvmButton *this,
        const Scaleform::GFx::EventId *evt)
{
  unsigned int TouchID; // edx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *pDispObj; // eax
  Scaleform::GFx::EventId e; // [esp+0h] [ebp-14h] BYREF

  if ( evt->Id != 1024 )
    return ((int (__thiscall *)(Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *, const Scaleform::GFx::EventId *))this[-1].pAS3CollectiblePtr.pObject->VMRef)(
             &this[-1].pAS3CollectiblePtr,
             evt);
  if ( this[-1].pDispObj || this[-1].pAS3RawPtr )
  {
    e.Id = evt->Id;
    e.WcharCode = evt->WcharCode;
    e.KeyCode = evt->KeyCode;
    TouchID = evt->TouchID;
    *(_DWORD *)&e.RollOverCnt = *(_DWORD *)&evt->RollOverCnt;
    pDispObj = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)this[-1].pDispObj;
    e.TouchID = TouchID;
    e.Id = 16777228;
    if ( !pDispObj )
      pDispObj = this[-1].pAS3RawPtr;
    if ( ((unsigned __int8)pDispObj & 1) != 0 )
      pDispObj = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)pDispObj - 1);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
      pDispObj,
      &e,
      (Scaleform::GFx::DisplayObject *)this[-1].pClassName);
  }
  return 1;
}
