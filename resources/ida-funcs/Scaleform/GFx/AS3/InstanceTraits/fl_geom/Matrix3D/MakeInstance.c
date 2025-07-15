Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D> *__cdecl Scaleform::GFx::AS3::InstanceTraits::fl_geom::Matrix3D::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_geom::Matrix3D *t)
{
  Scaleform::GFx::AS3::Instances::fl::Object *v2; // eax
  Scaleform::GFx::AS3::Instances::fl::Object *v3; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D> *v4; // eax

  v2 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v3 = v2;
  if ( v2 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v2, t);
    v3->__vftable = (Scaleform::GFx::AS3::Instances::fl::Object_vtbl *)&Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::`vftable';
    memset((int)&v3[1], 0, 128);
    v4 = result;
    *(double *)&v3[1].__vftable = 1.0;
    *(double *)&v3[2].pNext = 1.0;
    *(double *)&v3[3].RefCount = 1.0;
    result->pV = (Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *)v3;
    *(double *)&v3[4].DynAttrs.mHash.pTable = 1.0;
    v3[5].__vftable = 0;
  }
  else
  {
    v4 = result;
    result->pV = 0;
  }
  return v4;
}
