const Scaleform::GFx::AS3::ClassTraits::Traits *__thiscall Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
        Scaleform::GFx::AS3::VM *this,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::VMAppDomain *v4; // esi
  Scaleform::GFx::AS3::VMAppDomain *ParentDomain; // ecx
  const Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *result; // eax
  Scaleform::GFx::ASString *ClassTraits; // esi
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *p_ClassTraitsSet; // ecx

  v4 = appDomain;
  ParentDomain = appDomain->ParentDomain;
  if ( (!ParentDomain || (ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(ParentDomain, name, ns)) == 0)
    && (ClassTrait = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
                       &v4->ClassTraitsSet,
                       name,
                       ns)) == 0
    || (result = *ClassTrait) == 0 )
  {
    ClassTraits = Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GetClassTraits(
                    this->GlobalObject.pObject,
                    name,
                    ns);
    if ( ClassTraits )
    {
      p_ClassTraitsSet = &this->SystemDomain->ClassTraitsSet;
      appDomain = (Scaleform::GFx::AS3::VMAppDomain *)ClassTraits;
      Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
        p_ClassTraitsSet,
        name,
        ns,
        (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&appDomain);
    }
    return (const Scaleform::GFx::AS3::ClassTraits::Traits *)ClassTraits;
  }
  return result;
}
