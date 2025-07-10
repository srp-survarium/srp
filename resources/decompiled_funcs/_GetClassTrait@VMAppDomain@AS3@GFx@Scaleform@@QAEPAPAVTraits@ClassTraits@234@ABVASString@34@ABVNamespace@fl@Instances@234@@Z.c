Scaleform::GFx::AS3::ClassTraits::Traits **__thiscall Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(
        Scaleform::GFx::AS3::VMAppDomain *this,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::AS3::VMAppDomain *ParentDomain; // ecx
  Scaleform::GFx::AS3::ClassTraits::Traits **result; // eax

  ParentDomain = this->ParentDomain;
  if ( !ParentDomain )
    return Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
             &this->ClassTraitsSet,
             name,
             ns);
  result = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(ParentDomain, name, ns);
  if ( !result )
    return Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
             &this->ClassTraitsSet,
             name,
             ns);
  return result;
}
