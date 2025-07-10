Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__thiscall Scaleform::GFx::AS3::VMAbcFile::MakeInternedNamespace(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result,
        unsigned int nsIndex)
{
  const Scaleform::GFx::AS3::Abc::NamespaceInfo *p_any_namespace; // eax

  if ( nsIndex )
    p_any_namespace = &this->File.pObject->Const_Pool.ConstNamespace.Data.Data[nsIndex];
  else
    p_any_namespace = &this->File.pObject->Const_Pool.any_namespace;
  Scaleform::GFx::AS3::VM::MakeInternedNamespace(
    this->VMRef,
    result,
    p_any_namespace->Kind,
    (Scaleform::GFx::ASStringNode *)&p_any_namespace->NameURI);
  return result;
}
