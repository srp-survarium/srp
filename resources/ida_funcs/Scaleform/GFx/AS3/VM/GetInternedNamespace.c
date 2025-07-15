Scaleform::GFx::AS3::Instances::fl::Namespace *__thiscall Scaleform::GFx::AS3::VM::GetInternedNamespace(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        const Scaleform::GFx::ASString *uri)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *pObject; // esi

  if ( !uri->pNode->Size && kind == NS_Public )
    return this->PublicNamespace.pObject;
  pObject = (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)this->TraitsNamespace.pObject->ITraits.pObject;
  if ( (_S10_0 & 1) == 0 )
  {
    _S10_0 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  return Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::GetInternedInstance(pObject, kind, uri, &v);
}


Scaleform::GFx::AS3::Instances::fl::Namespace *__thiscall Scaleform::GFx::AS3::VM::GetInternedNamespace(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        Scaleform::GFx::ASStringNode *uri)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // esi
  Scaleform::GFx::ASStringNode *v5; // eax

  uri = Scaleform::GFx::ASStringManager::CreateStringNode(
          this->StringManagerRef->pStringManager,
          (char *)uri->pData,
          (unsigned int)uri->pManager);
  ++uri->RefCount;
  InternedNamespace = Scaleform::GFx::AS3::VM::GetInternedNamespace(this, kind, (const Scaleform::GFx::ASString *)&uri);
  v5 = uri;
  --uri->RefCount;
  if ( !v5->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  return InternedNamespace;
}


Scaleform::GFx::AS3::Instances::fl::Namespace *__thiscall Scaleform::GFx::AS3::VM::GetInternedNamespace(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        Scaleform::GFx::ASStringNode *name)
{
  char *v3; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // esi
  Scaleform::GFx::ASStringNode *v6; // eax

  v3 = (char *)name;
  if ( !name )
    v3 = (char *)&buf;
  name = Scaleform::GFx::ASStringManager::CreateStringNode(this->StringManagerRef->pStringManager, v3);
  ++name->RefCount;
  InternedNamespace = Scaleform::GFx::AS3::VM::GetInternedNamespace(this, kind, (const Scaleform::GFx::ASString *)&name);
  v6 = name;
  --name->RefCount;
  if ( !v6->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  return InternedNamespace;
}
