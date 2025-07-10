void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_net::SharedObject::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_net::SharedObject *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v3; // eax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v4; // esi

  v3 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v4 = v3;
  if ( v3 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcher(v3, t);
    v4->__vftable = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher_vtbl *)&Scaleform::GFx::AS3::Instances::fl_net::SharedObject::`vftable';
    v4[1].__vftable = 0;
    Scaleform::String::String((Scaleform::String *)&v4[1].4);
    Scaleform::String::String((Scaleform::String *)&v4[1].8);
    Scaleform::GFx::AS3::Value::Pick(result, v4);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Pick(result, 0);
  }
}
