Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__thiscall Scaleform::GFx::AS3::VM::MakeInternedNamespace(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        Scaleform::GFx::ASStringNode *name)
{
  char *v4; // eax
  Scaleform::GFx::ASStringNode *v6; // eax

  v4 = (char *)name;
  if ( !name )
    v4 = (char *)&buf;
  name = Scaleform::GFx::ASStringManager::CreateStringNode(this->StringManagerRef->pStringManager, v4);
  ++name->RefCount;
  Scaleform::GFx::AS3::VM::MakeInternedNamespace(this, result, kind, (Scaleform::GFx::ASString *)&name);
  v6 = name;
  --name->RefCount;
  if ( !v6->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  return result;
}
