Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__thiscall Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInternedInstance(
        Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        Scaleform::GFx::ASString *uri,
        Scaleform::GFx::AS3::Value *prefix)
{
  Scaleform::GFx::AS3::NamespaceInstanceFactory::MakeNamespace(
    this->pNamespaceFactory.pObject,
    result,
    kind,
    uri,
    prefix);
  return result;
}
