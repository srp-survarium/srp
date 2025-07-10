void __thiscall Scaleform::GFx::AS2::PlaceObject2EHa::Trace(
        Scaleform::GFx::AS2::PlaceObject2EHa *this,
        const char *str)
{
  Scaleform::GFx::AS2::Object::SetValue(
    (Scaleform::GFx::AS3::Instances::fl_geom::Transform *)this,
    (unsigned int)str,
    (const Scaleform::GFx::AS3::Value *)3);
}
