Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__thiscall Scaleform::GFx::AS3::VM::MakeInternedNamespace(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        Scaleform::GFx::ASString *uri)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *v4; // ecx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *v5; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *pObject; // edi

  if ( uri->pNode->Size || kind )
  {
    pObject = (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)this->TraitsNamespace.pObject->ITraits.pObject;
    if ( (_S10_0 & 1) == 0 )
    {
      _S10_0 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInternedInstance(pObject, result, kind, uri, &v);
    return result;
  }
  else
  {
    v4 = this->PublicNamespace.pObject;
    v5 = result;
    result->pV = v4;
    if ( v4 )
      v4->RefCount = (v4->RefCount + 1) & 0x8FBFFFFF;
  }
  return v5;
}
