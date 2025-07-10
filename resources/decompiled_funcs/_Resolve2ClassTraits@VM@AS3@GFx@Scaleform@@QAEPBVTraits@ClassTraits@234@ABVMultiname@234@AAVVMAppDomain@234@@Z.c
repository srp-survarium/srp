Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
        Scaleform::GFx::AS3::VM *this,
        const Scaleform::GFx::AS3::Multiname *mn,
        Scaleform::GFx::ASStringNode *appDomain)
{
  const Scaleform::GFx::AS3::Multiname *v3; // esi
  Scaleform::GFx::AS3::ClassTraits::ClassClass *pObject; // eax
  Scaleform::GFx::ASStringNode *v6; // edi
  Scaleform::GFx::AS3::VMAppDomain *RefCount; // ecx
  Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // eax
  Scaleform::GFx::ASString *ClassTraits; // edi
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *p_ClassTraitsSet; // ecx
  Scaleform::GFx::ASStringNode *v13; // eax
  const Scaleform::GFx::AS3::Instances::fl::Namespace *v14; // [esp-8h] [ebp-14h]

  v3 = mn;
  if ( Scaleform::GFx::AS3::Multiname::IsAnyType(mn) )
  {
    pObject = this->TraitsClassClass.pObject;
  }
  else
  {
    v6 = appDomain;
    RefCount = (Scaleform::GFx::AS3::VMAppDomain *)appDomain->RefCount;
    if ( RefCount && (ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(RefCount, v3)) != 0
      || (ClassTrait = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
                         (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *)&v6->pManager,
                         v3)) != 0 )
    {
      pObject = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)*ClassTrait;
    }
    else
    {
      pObject = 0;
    }
  }
  ClassTraits = (Scaleform::GFx::ASString *)pObject;
  if ( pObject )
    return ClassTraits;
  appDomain = &this->StringManagerRef->pStringManager->EmptyStringNode;
  ++appDomain->RefCount;
  if ( Scaleform::GFx::AS3::Value::Convert2String(
         &v3->Name,
         (Scaleform::GFx::AS3::CheckResult *)&mn,
         (Scaleform::GFx::ASString *)&appDomain)->Result )
  {
    ClassTraits = Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GetClassTraits(
                    this->GlobalObject.pObject,
                    (const Scaleform::GFx::ASString *)&appDomain,
                    (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v3->Obj.pObject);
    if ( ClassTraits )
    {
      v14 = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v3->Obj.pObject;
      p_ClassTraitsSet = &this->SystemDomain->ClassTraitsSet;
      mn = (const Scaleform::GFx::AS3::Multiname *)ClassTraits;
      Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
        p_ClassTraitsSet,
        (const Scaleform::GFx::ASString *)&appDomain,
        v14,
        (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&mn);
    }
    v13 = appDomain;
    --appDomain->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    return ClassTraits;
  }
  v10 = appDomain;
  --appDomain->RefCount;
  if ( !v10->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  return 0;
}
