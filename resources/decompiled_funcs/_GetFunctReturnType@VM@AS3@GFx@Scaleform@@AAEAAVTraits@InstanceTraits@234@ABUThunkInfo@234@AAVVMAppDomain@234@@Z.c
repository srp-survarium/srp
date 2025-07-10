Scaleform::GFx::AS3::InstanceTraits::Traits *__thiscall Scaleform::GFx::AS3::VM::GetFunctReturnType(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::ASStringNode *thunk,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  const Scaleform::GFx::AS3::TypeInfo *pManager; // edi
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *v6; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // esi
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::ASStringNode *v10; // eax

  pManager = (const Scaleform::GFx::AS3::TypeInfo *)thunk->pManager;
  if ( !pManager )
    return this->TraitsObject.pObject->ITraits.pObject;
  thunk = Scaleform::GFx::ASStringManager::CreateConstStringNode(
            this->StringManagerRef->pStringManager,
            (char *)pManager->Name,
            strlen(pManager->Name),
            0);
  ++thunk->RefCount;
  InternedNamespace = Scaleform::GFx::AS3::VM::GetInternedNamespace(
                        this,
                        NS_Public,
                        (Scaleform::GFx::ASStringNode *)pManager->PkgName);
  v6 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
         this,
         (const Scaleform::GFx::ASString *)&thunk,
         InternedNamespace,
         appDomain);
  if ( !v6 )
  {
    v10 = thunk;
    --thunk->RefCount;
    if ( !v10->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    return this->TraitsObject.pObject->ITraits.pObject;
  }
  pObject = v6->ITraits.pObject;
  v8 = thunk;
  --thunk->RefCount;
  if ( !v8->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  return pObject;
}
