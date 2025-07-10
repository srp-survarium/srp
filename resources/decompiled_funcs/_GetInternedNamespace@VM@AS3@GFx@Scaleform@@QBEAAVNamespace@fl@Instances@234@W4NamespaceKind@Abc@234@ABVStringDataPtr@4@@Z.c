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
