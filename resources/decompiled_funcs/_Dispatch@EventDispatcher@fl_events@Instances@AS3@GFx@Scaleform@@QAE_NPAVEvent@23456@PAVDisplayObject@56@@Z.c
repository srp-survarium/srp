BOOL __thiscall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::Instances::fl_events::Event *evtObj,
        Scaleform::GFx::DisplayObject *dispObject)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&evtObj->Target,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(this, evtObj, dispObject);
  return (*((_BYTE *)evtObj + 48) & 4) == 0;
}
