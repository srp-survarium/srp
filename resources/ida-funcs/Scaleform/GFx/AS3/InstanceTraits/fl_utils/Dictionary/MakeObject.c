void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_utils::Dictionary::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_utils::Dictionary *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl::Object *v3; // eax
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // esi

  v3 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v4 = v3;
  if ( v3 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v3, t);
    v4->__vftable = (Scaleform::GFx::AS3::Instances::fl::Object_vtbl *)&Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::`vftable';
    LOBYTE(v4[1].__vftable) = 0;
    v4[1].pRCCRaw = 0;
    Scaleform::GFx::AS3::Value::Pick(result, v4);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Pick(result, 0);
  }
}
