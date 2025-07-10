void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseEventEx::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseEventEx *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v3; // eax
  Scaleform::GFx::AS3::Object *v4; // esi

  v3 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v4 = v3;
  if ( v3 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::MouseEvent::MouseEvent(v3, t);
    v4->__vftable = (Scaleform::GFx::AS3::Object_vtbl *)&Scaleform::GFx::AS3::Instances::fl_gfx::MouseEventEx::`vftable';
    v4[2].DynAttrs.mHash.pTable = 0;
    v4[2].pUserDataHolder = 0;
    v4[3].__vftable = 0;
    Scaleform::GFx::AS3::Value::Pick(result, v4);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Pick(result, 0);
  }
}
