void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_gfx::FocusEventEx::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_gfx::FocusEventEx *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *v3; // eax
  Scaleform::GFx::AS3::Object *v4; // esi

  v3 = (Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v4 = v3;
  if ( v3 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::FocusEvent::FocusEvent(v3, t);
    v4->__vftable = (Scaleform::GFx::AS3::Object_vtbl *)&Scaleform::GFx::AS3::Instances::fl_gfx::FocusEventEx::`vftable';
    v4[2].__vftable = 0;
    Scaleform::GFx::AS3::Value::Pick(result, v4);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Pick(result, 0);
  }
}
