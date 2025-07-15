void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_display::Scene::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_display::Scene *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl::Catch *v3; // eax
  Scaleform::GFx::AS3::Object *v4; // esi

  v3 = (Scaleform::GFx::AS3::Instances::fl::Catch *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v4 = v3;
  if ( v3 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v3, t);
    v4->__vftable = (Scaleform::GFx::AS3::Object_vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::Scene::`vftable';
    v4[1].__vftable = 0;
    v4[1].pRCCRaw = 0;
    Scaleform::GFx::AS3::Value::Pick(result, v4);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Pick(result, 0);
  }
}
