Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::RegExp> *__cdecl Scaleform::GFx::AS3::InstanceTraits::fl::RegExp::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::RegExp> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl::RegExp *t)
{
  Scaleform::GFx::AS3::Instance *v2; // eax
  Scaleform::GFx::AS3::Instances::fl::RegExp *v3; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::RegExp> *v4; // eax

  v2 = (Scaleform::GFx::AS3::Instance *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v3 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)v2;
  if ( v2 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v2, t);
    v3->__vftable = (Scaleform::GFx::AS3::Instances::fl::RegExp_vtbl *)&Scaleform::GFx::AS3::Instances::fl::RegExp::`vftable';
    v3->CompRegExp = 0;
    v3->MatchOffset = -1;
    v3->MatchLength = 0;
    Scaleform::String::String(&v3->Pattern);
    v4 = result;
    v3->IsGlobal = 0;
    v3->LastIndex = 0;
    v3->HasNamedGroups = 0;
    v3->OptionFlags = 2048;
    result->pV = v3;
  }
  else
  {
    v4 = result;
    result->pV = 0;
  }
  return v4;
}
