Scaleform::GFx::AS3::ClassTraits::Traits **__thiscall Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(
        Scaleform::GFx::AS3::VMAppDomain *this,
        const Scaleform::GFx::AS3::Multiname *mn)
{
  Scaleform::GFx::AS3::VMAppDomain *ParentDomain; // ecx
  Scaleform::GFx::AS3::ClassTraits::Traits **result; // eax

  ParentDomain = this->ParentDomain;
  if ( !ParentDomain )
    return Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
             &this->ClassTraitsSet,
             mn);
  result = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(ParentDomain, mn);
  if ( !result )
    return Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
             &this->ClassTraitsSet,
             mn);
  return result;
}
