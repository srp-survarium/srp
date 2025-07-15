Scaleform::GFx::AS3::ClassTraits::ClassClass *__thiscall Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  const Scaleform::GFx::AS3::Abc::Multiname *v3; // ebx
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *pObject; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *v9; // ebp
  unsigned int NextIndex; // ebx
  Scaleform::GFx::AS3::ClassTraits::fl::String *v11; // eax
  const Scaleform::GFx::AS3::Abc::Multiname *v12; // eax
  Scaleform::GFx::AS3::Classes::fl_vec::Vector *Class; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *v15; // [esp-Ch] [ebp-14h]

  v3 = mn;
  if ( mn->Kind == MN_QName && !mn->NameIndex && !mn->Ind )
    return this->TraitsClassClass.pObject;
  Scaleform::GFx::AS3::VMFile::GetInternedString(
    file,
    (Scaleform::GFx::ASString *)&mn,
    (Scaleform::GFx::ASStringNode *)mn->NameIndex);
  v6 = (Scaleform::GFx::ASStringNode *)mn;
  if ( mn == (Scaleform::GFx::AS3::Abc::Multiname *)this->StringManagerRef->Builtins[3].pNode )
  {
    pObject = this->TraitsObject.pObject;
    --mn->Kind;
    if ( !v6->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    return (Scaleform::GFx::AS3::ClassTraits::ClassClass *)pObject;
  }
  else
  {
    InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(
                          file,
                          (Scaleform::GFx::AS3::Instances::fl::Namespace *)v3->Ind);
    v9 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
                                                               this,
                                                               (const Scaleform::GFx::ASString *)&mn,
                                                               InternedNamespace,
                                                               file->AppDomain);
    if ( v9 == this->TraitsVector.pObject )
    {
      NextIndex = v3->NextIndex;
      if ( NextIndex )
      {
        v12 = file->GetMultiname(file, NextIndex);
        v11 = (Scaleform::GFx::AS3::ClassTraits::fl::String *)Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
                                                                this,
                                                                file,
                                                                v12);
      }
      else
      {
        v11 = (Scaleform::GFx::AS3::ClassTraits::fl::String *)this->TraitsObject.pObject;
      }
      if ( v11 )
      {
        if ( v11 == (Scaleform::GFx::AS3::ClassTraits::fl::String *)this->TraitsInt.pObject )
        {
          v9 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)this->TraitsVector_int.pObject;
        }
        else if ( v11 == (Scaleform::GFx::AS3::ClassTraits::fl::String *)this->TraitsUint.pObject )
        {
          v9 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)this->TraitsVector_uint.pObject;
        }
        else if ( v11 == (Scaleform::GFx::AS3::ClassTraits::fl::String *)this->TraitsNumber.pObject )
        {
          v9 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)this->TraitsVector_Number.pObject;
        }
        else if ( v11 == this->TraitsString.pObject )
        {
          v9 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)this->TraitsVector_String.pObject;
        }
        else if ( v11->ITraits.pObject )
        {
          v15 = v11;
          Class = (Scaleform::GFx::AS3::Classes::fl_vec::Vector *)Scaleform::GFx::AS3::Traits::GetClass(v9->ITraits.pObject);
          v9 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)Scaleform::GFx::AS3::Classes::fl_vec::Vector::Resolve2Vector(
                                                                     Class,
                                                                     v15);
        }
      }
    }
    v14 = (Scaleform::GFx::ASStringNode *)mn;
    --mn->Kind;
    if ( !v14->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    return (Scaleform::GFx::AS3::ClassTraits::ClassClass *)v9;
  }
}


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


const Scaleform::GFx::AS3::ClassTraits::Traits *__thiscall Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
        Scaleform::GFx::AS3::VM *this,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::VMAppDomain *v4; // esi
  Scaleform::GFx::AS3::VMAppDomain *ParentDomain; // ecx
  const Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *result; // eax
  Scaleform::GFx::ASString *ClassTraits; // esi
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *p_ClassTraitsSet; // ecx

  v4 = appDomain;
  ParentDomain = appDomain->ParentDomain;
  if ( (!ParentDomain || (ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(ParentDomain, name, ns)) == 0)
    && (ClassTrait = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
                       &v4->ClassTraitsSet,
                       name,
                       ns)) == 0
    || (result = *ClassTrait) == 0 )
  {
    ClassTraits = Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GetClassTraits(
                    this->GlobalObject.pObject,
                    name,
                    ns);
    if ( ClassTraits )
    {
      p_ClassTraitsSet = &this->SystemDomain->ClassTraitsSet;
      appDomain = (Scaleform::GFx::AS3::VMAppDomain *)ClassTraits;
      Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
        p_ClassTraitsSet,
        name,
        ns,
        (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&appDomain);
    }
    return (const Scaleform::GFx::AS3::ClassTraits::Traits *)ClassTraits;
  }
  return result;
}


Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
        Scaleform::GFx::AS3::VM *this,
        const Scaleform::GFx::AS3::Multiname *mn,
        Scaleform::GFx::ASStringNode *appDomain)
{
  const Scaleform::GFx::AS3::Multiname *v3; // esi
  Scaleform::GFx::AS3::ClassTraits::ClassClass *pObject; // eax
  Scaleform::GFx::ASStringNode *v6; // edi
  Scaleform::GFx::AS3::VMAppDomain *RefCount; // ecx
  Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // eax
  Scaleform::GFx::ASString *ClassTraits; // edi
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *p_ClassTraitsSet; // ecx
  Scaleform::GFx::ASStringNode *v13; // eax
  const Scaleform::GFx::AS3::Instances::fl::Namespace *v14; // [esp-8h] [ebp-14h]

  v3 = mn;
  if ( Scaleform::GFx::AS3::Multiname::IsAnyType(mn) )
  {
    pObject = this->TraitsClassClass.pObject;
  }
  else
  {
    v6 = appDomain;
    RefCount = (Scaleform::GFx::AS3::VMAppDomain *)appDomain->RefCount;
    if ( RefCount && (ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(RefCount, v3)) != 0
      || (ClassTrait = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
                         (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *)&v6->pManager,
                         v3)) != 0 )
    {
      pObject = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)*ClassTrait;
    }
    else
    {
      pObject = 0;
    }
  }
  ClassTraits = (Scaleform::GFx::ASString *)pObject;
  if ( pObject )
    return ClassTraits;
  appDomain = &this->StringManagerRef->pStringManager->EmptyStringNode;
  ++appDomain->RefCount;
  if ( Scaleform::GFx::AS3::Value::Convert2String(
         &v3->Name,
         (Scaleform::GFx::AS3::CheckResult *)&mn,
         (Scaleform::GFx::ASString *)&appDomain)->Result )
  {
    ClassTraits = Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GetClassTraits(
                    this->GlobalObject.pObject,
                    (const Scaleform::GFx::ASString *)&appDomain,
                    (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v3->Obj.pObject);
    if ( ClassTraits )
    {
      v14 = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v3->Obj.pObject;
      p_ClassTraitsSet = &this->SystemDomain->ClassTraitsSet;
      mn = (const Scaleform::GFx::AS3::Multiname *)ClassTraits;
      Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
        p_ClassTraitsSet,
        (const Scaleform::GFx::ASString *)&appDomain,
        v14,
        (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&mn);
    }
    v13 = appDomain;
    --appDomain->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    return ClassTraits;
  }
  v10 = appDomain;
  --appDomain->RefCount;
  if ( !v10->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  return 0;
}
