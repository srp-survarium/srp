void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_geom::Matrix::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_geom::Matrix *this,
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
    *(double *)&v4[1].__vftable = 0.0;
    *(double *)&v4[1].pNext = 0.0;
    *(double *)&v4[1].RefCount = 0.0;
    v4->__vftable = (Scaleform::GFx::AS3::Instances::fl::Object_vtbl *)&Scaleform::GFx::AS3::Instances::fl_geom::Matrix::`vftable';
    *(double *)&v4[1].DynAttrs.mHash.pTable = 0.0;
    *(double *)&v4[2].__vftable = 0.0;
    *(double *)&v4[2].pNext = 0.0;
    Scaleform::GFx::AS3::Value::Pick(result, v4);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Pick(result, 0);
  }
}
