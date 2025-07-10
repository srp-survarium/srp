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
