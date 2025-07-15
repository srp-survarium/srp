void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl::Date::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl::Date *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instance *v3; // eax
  Scaleform::GFx::AS3::Instance *v4; // esi

  v3 = (Scaleform::GFx::AS3::Instance *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v4 = v3;
  if ( v3 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v3, t);
    *(double *)&v4[1].pNext = 0.0;
    v4->__vftable = (Scaleform::GFx::AS3::Instance_vtbl *)&Scaleform::GFx::AS3::Instances::fl::Date::`vftable';
    v4[1].__vftable = 0;
    LOBYTE(v4[1]._pRCC) = 0;
    Scaleform::GFx::AS3::Value::Pick(result, v4);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Pick(result, 0);
  }
}
