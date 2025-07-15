void __thiscall Scaleform::GFx::AS3::VMAppDomain::AddClassTrait(
        Scaleform::GFx::AS3::VMAppDomain *this,
        const Scaleform::GFx::ASString *name,
        const Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        Scaleform::GFx::AS3::ClassTraits::Traits *val)
{
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &this->ClassTraitsSet,
    name,
    ns,
    &val);
}
