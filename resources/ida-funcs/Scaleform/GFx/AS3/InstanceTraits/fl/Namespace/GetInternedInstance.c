Scaleform::GFx::AS3::Instances::fl::Namespace *__thiscall Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::GetInternedInstance(
        Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *this,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        const Scaleform::GFx::ASString *uri,
        const Scaleform::GFx::AS3::Value *prefix)
{
  return Scaleform::GFx::AS3::NamespaceInstanceFactory::GetNamespace(this->pNamespaceFactory.pObject, kind, uri, prefix);
}
