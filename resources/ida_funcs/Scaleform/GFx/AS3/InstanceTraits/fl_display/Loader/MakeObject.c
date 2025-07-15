void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_display::Loader::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_display::Loader *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v3; // eax
  Scaleform::GFx::AS3::Object *v4; // esi

  v3 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v4 = v3;
  if ( v3 )
  {
    Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::DisplayObject(v3, t);
    v4[1].DynAttrs.mHash.pTable = 0;
    v4->__vftable = (Scaleform::GFx::AS3::Object_vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::Loader::`vftable';
    v4[1].pUserDataHolder = 0;
    Scaleform::GFx::AS3::Value::Pick(result, v4);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Pick(result, 0);
  }
}
