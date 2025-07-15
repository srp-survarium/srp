void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_text::TextSnapshot::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_text::TextSnapshot *this,
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
    v4->__vftable = (Scaleform::GFx::AS3::Instances::fl::Object_vtbl *)&Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot::`vftable';
    Scaleform::GFx::StaticTextSnapshotData::StaticTextSnapshotData((Scaleform::GFx::StaticTextSnapshotData *)&v4[1]);
    Scaleform::GFx::AS3::Value::Pick(result, v4);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Pick(result, 0);
  }
}
