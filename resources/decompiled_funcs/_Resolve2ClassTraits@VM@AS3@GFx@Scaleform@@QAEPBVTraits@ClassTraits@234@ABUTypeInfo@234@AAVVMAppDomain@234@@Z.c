const Scaleform::GFx::AS3::ClassTraits::Traits *__thiscall Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
        Scaleform::GFx::AS3::VM *this,
        const Scaleform::GFx::AS3::TypeInfo *ti,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // esi
  const Scaleform::GFx::AS3::TypeInfo *v4; // edi
  const Scaleform::GFx::AS3::TypeInfo *v5; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *pObject; // esi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // ebx
  const Scaleform::GFx::AS3::ClassTraits::Traits *v8; // esi
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::ASString ns_name; // [esp+14h] [ebp-8h] BYREF
  Scaleform::GFx::ASString name; // [esp+18h] [ebp-4h] BYREF

  StringManagerRef = this->StringManagerRef;
  v4 = ti;
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 StringManagerRef->pStringManager,
                 (char *)ti->Name,
                 strlen(ti->Name),
                 0);
  ++name.pNode->RefCount;
  ns_name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                    StringManagerRef->pStringManager,
                    (char *)v4->PkgName,
                    strlen(v4->PkgName),
                    0);
  ++ns_name.pNode->RefCount;
  if ( ns_name.pNode->Size )
  {
    pObject = (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)this->TraitsNamespace.pObject->ITraits.pObject;
    if ( (_S10_0 & 1) == 0 )
    {
      _S10_0 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInternedInstance(
      pObject,
      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&ti,
      NS_Public,
      &ns_name,
      &v);
    goto LABEL_7;
  }
  v5 = (const Scaleform::GFx::AS3::TypeInfo *)this->PublicNamespace.pObject;
  ti = v5;
  if ( v5 )
  {
    ++v5->Implements;
    v5->Implements = (const Scaleform::GFx::AS3::TypeInfo **)((int)v5->Implements & 0x8FBFFFFF);
LABEL_7:
    v5 = ti;
  }
  v7 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v5;
  v8 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
         this,
         &name,
         (Scaleform::GFx::AS3::Instances::fl::Namespace *)v5,
         appDomain);
  if ( v7 )
  {
    if ( ((unsigned __int8)v7 & 1) == 0 )
    {
      RefCount = v7->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        v7->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
      }
    }
  }
  pNode = ns_name.pNode;
  --ns_name.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v11 = name.pNode;
  --name.pNode->RefCount;
  if ( !v11->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  return v8;
}
