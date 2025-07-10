Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__thiscall Scaleform::GFx::AS3::VM::MakeInternedNamespace(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        Scaleform::GFx::ASStringNode *uri)
{
  Scaleform::GFx::ASStringNode *v5; // eax

  uri = Scaleform::GFx::ASStringManager::CreateStringNode(
          this->StringManagerRef->pStringManager,
          (char *)uri->pData,
          (unsigned int)uri->pManager);
  ++uri->RefCount;
  Scaleform::GFx::AS3::VM::MakeInternedNamespace(this, result, kind, (Scaleform::GFx::ASString *)&uri);
  v5 = uri;
  --uri->RefCount;
  if ( !v5->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  return result;
}
