Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *__cdecl Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String *t)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v2; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v3; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *v4; // eax

  v2 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)Scaleform::GFx::AS3::Traits::Alloc(t);
  if ( v2 )
  {
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::Vector_String(v2, t);
    result->pV = v3;
    return result;
  }
  else
  {
    v4 = result;
    result->pV = 0;
  }
  return v4;
}
