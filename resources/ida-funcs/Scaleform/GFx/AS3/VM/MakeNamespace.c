Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__thiscall Scaleform::GFx::AS3::VM::MakeNamespace(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind)
{
  const Scaleform::GFx::AS3::Value *Undefined; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString uri; // [esp+8h] [ebp-4h] BYREF

  uri.pNode = &this->StringManagerRef->pStringManager->EmptyStringNode;
  ++uri.pNode->RefCount;
  Undefined = Scaleform::GFx::AS3::Value::GetUndefined();
  Scaleform::GFx::AS3::VM::MakeNamespace(this, result, kind, &uri, Undefined);
  pNode = uri.pNode;
  --uri.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return result;
}


Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__thiscall Scaleform::GFx::AS3::VM::MakeNamespace(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        const Scaleform::GFx::ASString *uri,
        Scaleform::GFx::AS3::Value *prefix)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(
    (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)this->TraitsNamespace.pObject->ITraits.pObject,
    result,
    kind,
    uri,
    prefix);
  return result;
}
