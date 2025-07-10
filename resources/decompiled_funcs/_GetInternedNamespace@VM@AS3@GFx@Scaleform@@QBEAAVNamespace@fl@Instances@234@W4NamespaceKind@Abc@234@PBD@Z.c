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
