bool __thiscall Scaleform::GFx::AS3::AvmTextField::OnKeyEvent(
        Scaleform::GFx::AS3::AvmTextField *this,
        const Scaleform::GFx::EventId *e,
        int *__formal)
{
  Scaleform::GFx::DisplayObject *v3; // edx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *AppDomain; // ecx

  if ( this[-1].AppDomain || this[-1].pClassName )
  {
    v3 = *(Scaleform::GFx::DisplayObject **)&this[-1].Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Flags;
    if ( this[-1].AppDomain )
      AppDomain = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)this[-1].AppDomain;
    else
      AppDomain = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)this[-1].pClassName;
    if ( ((unsigned __int8)AppDomain & 1) != 0 )
      AppDomain = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)AppDomain - 1);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(AppDomain, e, v3);
  }
  return 0;
}
