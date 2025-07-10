void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_media::SoundLoaderContext::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_media::SoundLoaderContext *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl::Catch *v3; // eax
  Scaleform::GFx::AS3::Instances::fl::Catch *v4; // esi

  v3 = (Scaleform::GFx::AS3::Instances::fl::Catch *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v4 = v3;
  if ( v3 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v3, t);
    *(double *)&v4[1].__vftable = 1000.0;
    v4->__vftable = (Scaleform::GFx::AS3::Instances::fl::Catch_vtbl *)&Scaleform::GFx::AS3::Instances::fl_gfx::IMECandidateListStyle::`vftable';
    LOBYTE(v4[1].pNext) = 0;
    Scaleform::GFx::AS3::Value::Pick(result, v4);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Pick(result, 0);
  }
}
