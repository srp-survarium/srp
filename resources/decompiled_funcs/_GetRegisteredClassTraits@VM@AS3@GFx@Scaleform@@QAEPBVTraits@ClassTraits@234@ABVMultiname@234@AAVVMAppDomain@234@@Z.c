Scaleform::GFx::AS3::ClassTraits::ClassClass *__thiscall Scaleform::GFx::AS3::VM::GetRegisteredClassTraits(
        Scaleform::GFx::AS3::VM *this,
        const Scaleform::GFx::AS3::Multiname *mn,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::VMAppDomain *ParentDomain; // ecx
  Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // eax

  if ( Scaleform::GFx::AS3::Multiname::IsAnyType(mn) )
    return this->TraitsClassClass.pObject;
  ParentDomain = appDomain->ParentDomain;
  if ( ParentDomain )
  {
    ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(ParentDomain, mn);
    if ( ClassTrait )
      return (Scaleform::GFx::AS3::ClassTraits::ClassClass *)*ClassTrait;
  }
  ClassTrait = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
                 &appDomain->ClassTraitsSet,
                 mn);
  if ( ClassTrait )
    return (Scaleform::GFx::AS3::ClassTraits::ClassClass *)*ClassTrait;
  else
    return 0;
}
