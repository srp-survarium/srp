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
    if ( (_S15 & 1) == 0 )
    {
      _S15 |= 1u;
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


Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__thiscall Scaleform::GFx::AS3::VM::MakeInternedNamespace(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        Scaleform::GFx::ASStringNode *uri)
{
  Scaleform::GFx::ASStringNode *v5; // eax

  uri = Scaleform::GFx::ASStringManager::CreateStringNode(
          this->StringManagerRef->pStringManager,
          (__m128i *)uri->pData,
          (unsigned int)uri->pManager);
  ++uri->RefCount;
  Scaleform::GFx::AS3::VM::MakeInternedNamespace(this, result, kind, (Scaleform::GFx::ASString *)&uri);
  v5 = uri;
  --uri->RefCount;
  if ( !v5->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  return result;
}


Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__thiscall Scaleform::GFx::AS3::VM::MakeInternedNamespace(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        Scaleform::GFx::ASStringNode *name)
{
  __m128i *v4; // eax
  Scaleform::GFx::ASStringNode *v6; // eax

  v4 = (__m128i *)name;
  if ( !name )
    v4 = (__m128i *)uri;
  name = Scaleform::GFx::ASStringManager::CreateStringNode(this->StringManagerRef->pStringManager, v4);
  ++name->RefCount;
  Scaleform::GFx::AS3::VM::MakeInternedNamespace(this, result, kind, (Scaleform::GFx::ASString *)&name);
  v6 = name;
  --name->RefCount;
  if ( !v6->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  return result;
}
