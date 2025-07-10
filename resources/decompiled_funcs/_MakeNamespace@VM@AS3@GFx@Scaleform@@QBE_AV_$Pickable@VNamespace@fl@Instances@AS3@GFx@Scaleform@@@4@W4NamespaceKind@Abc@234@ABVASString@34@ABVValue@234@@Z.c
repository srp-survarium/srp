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
