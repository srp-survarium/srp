void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_events::AppLifecycleEvent::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_events::AppLifecycleEvent *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *v3; // eax
  Scaleform::GFx::AS3::Object *v4; // eax

  v3 = (Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *)Scaleform::GFx::AS3::Traits::Alloc(t);
  if ( v3 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent::AppLifecycleEvent(v3, t);
    Scaleform::GFx::AS3::Value::Pick(result, v4);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Pick(result, 0);
  }
}
