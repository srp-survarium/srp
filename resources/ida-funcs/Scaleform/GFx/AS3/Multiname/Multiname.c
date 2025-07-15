void __thiscall Scaleform::GFx::AS3::Multiname::Multiname(
        Scaleform::GFx::AS3::Multiname *this,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        const Scaleform::GFx::AS3::Value *name)
{
  this->Kind = MN_QName;
  this->Obj.pObject = ns;
  if ( ns )
    ns->RefCount = (ns->RefCount + 1) & 0x8FBFFFFF;
  this->Name.Flags = 0;
  this->Name.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(this, name);
}


void __thiscall Scaleform::GFx::AS3::Multiname::Multiname(
        Scaleform::GFx::AS3::Multiname *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // ebp
  Scaleform::GFx::AS3::Value *p_Name; // ecx
  Scaleform::GFx::ASStringManager *pStringManager; // esi
  Scaleform::GFx::AS3::VM *p_EmptyStringNode; // esi

  v2 = vm;
  this->Kind = MN_QName;
  this->Obj.pObject = 0;
  p_Name = &this->Name;
  p_Name->Flags = 0;
  p_Name->Bonus.pWeakProxy = 0;
  pStringManager = v2->StringManagerRef->pStringManager;
  ++pStringManager->EmptyStringNode.RefCount;
  p_EmptyStringNode = (Scaleform::GFx::AS3::VM *)&pStringManager->EmptyStringNode;
  vm = p_EmptyStringNode;
  Scaleform::GFx::AS3::Value::Assign(p_Name, (const Scaleform::GFx::ASString *)&vm);
  if ( p_EmptyStringNode->StringManagerRef-- == (Scaleform::GFx::AS3::StringManager *)1 )
    Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)p_EmptyStringNode);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->Obj,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v2->DefXMLNamespace.pObject);
  if ( !this->Obj.pObject )
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->Obj,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v2->PublicNamespace.pObject);
}


void __thiscall Scaleform::GFx::AS3::Multiname::Multiname(
        Scaleform::GFx::AS3::Multiname *this,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::VM *v3; // ebx
  const Scaleform::GFx::AS3::Value *v5; // ecx
  int v6; // eax
  Scaleform::GFx::AS3::Value::V1U v7; // edx
  int v8; // edx
  Scaleform::GFx::AS3::VM *v9; // edi
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v12; // [esp+10h] [ebp-8h] BYREF

  v3 = vm;
  v5 = v;
  this->Kind = MN_QName;
  this->Obj.pObject = 0;
  this->Name.Flags = 0;
  this->Name.Bonus.pWeakProxy = 0;
  v6 = v5->Flags & 0x1F;
  if ( (unsigned int)(v6 - 2) <= 2 || v6 == 10 )
  {
    Scaleform::GFx::AS3::Value::Assign(&this->Name, v5);
  }
  else
  {
    if ( (unsigned int)(v6 - 12) <= 3 )
    {
      v7 = v5->value.VS._1;
      if ( v7.VInt )
      {
        v8 = *(_DWORD *)(v7.VInt + 20);
        if ( *(_DWORD *)(v8 + 60) == 12 && (*(_DWORD *)(v8 + 56) & 0x20) == 0 )
        {
          Scaleform::GFx::AS3::Multiname::SetFromQName(this, v5);
          return;
        }
      }
    }
    if ( (unsigned int)(v6 - 12) > 3 )
    {
      v9 = vm;
      Scaleform::GFx::AS3::VM::Error::Error(&v12, eInvalidArgumentError, vm);
LABEL_11:
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        v9,
        v10,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
      pNode = v12.Message.pNode;
      --v12.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return;
    }
    if ( !v5->value.VS._1.VInt )
    {
      v9 = vm;
      Scaleform::GFx::AS3::VM::Error::Error(&v12, eNotImplementedError, vm);
      goto LABEL_11;
    }
    Scaleform::GFx::AS3::Value::operator=(&this->Name, v5);
    if ( !Scaleform::GFx::AS3::Value::ToStringValue(
            &this->Name,
            (Scaleform::GFx::AS3::CheckResult *)&vm,
            (Scaleform::GFx::ASStringNode *)v3->StringManagerRef)->Result )
      return;
  }
  Scaleform::GFx::AS3::Multiname::PostProcessName(this, 0);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->Obj,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v3->DefXMLNamespace.pObject);
  if ( !this->Obj.pObject )
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->Obj,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v3->PublicNamespace.pObject);
}


void __thiscall Scaleform::GFx::AS3::Multiname::Multiname(
        Scaleform::GFx::AS3::Multiname *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  const Scaleform::GFx::AS3::Abc::Multiname *v3; // esi
  Scaleform::GFx::AS3::Value *p_Name; // ebx
  Scaleform::GFx::ASString *InternedString; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  int v8; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *Ind; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *InternedNamespaceSet; // eax

  v3 = mn;
  this->Kind = mn->Kind;
  this->Obj.pObject = 0;
  p_Name = &this->Name;
  this->Name.Flags = 0;
  this->Name.Bonus.pWeakProxy = 0;
  if ( v3->Kind || v3->NameIndex || v3->Ind )
  {
    InternedString = Scaleform::GFx::AS3::VMFile::GetInternedString(
                       file,
                       (Scaleform::GFx::ASString *)&mn,
                       (Scaleform::GFx::ASStringNode *)v3->NameIndex);
    Scaleform::GFx::AS3::Value::Assign(p_Name, InternedString);
    v7 = (Scaleform::GFx::ASStringNode *)mn;
    --mn->Kind;
    if ( !v7->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    Scaleform::GFx::AS3::Multiname::PostProcessName(this, 0);
  }
  v8 = v3->Kind & 3;
  if ( v8 || (v3->Kind & 4) != 0 )
  {
    if ( v8 == 2 )
    {
      InternedNamespaceSet = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)Scaleform::GFx::AS3::VMFile::GetInternedNamespaceSet(
                                                                                        file,
                                                                                        v3->Ind);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->Obj,
        InternedNamespaceSet);
    }
  }
  else
  {
    Ind = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v3->Ind;
    if ( Ind )
    {
      InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(file, Ind);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->Obj,
        (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)InternedNamespace);
    }
  }
}


void __thiscall Scaleform::GFx::AS3::Multiname::Multiname(
        Scaleform::GFx::AS3::Multiname *this,
        const Scaleform::GFx::AS3::Multiname *__that)
{
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // eax
  Scaleform::GFx::AS3::Value *p_Name; // ecx

  this->Kind = __that->Kind;
  pObject = __that->Obj.pObject;
  this->Obj.pObject = pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  p_Name = &__that->Name;
  this->Name = __that->Name;
  if ( (__that->Name.Flags & 0x1F) > 9 )
  {
    if ( (p_Name->Flags & 0x200) != 0 )
      ++__that->Name.Bonus.pWeakProxy->RefCount;
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(p_Name);
  }
}


void __thiscall Scaleform::GFx::AS3::Multiname::Multiname(
        Scaleform::GFx::AS3::Multiname *this,
        const Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::TypeInfo *ti)
{
  const Scaleform::GFx::AS3::TypeInfo *v4; // ecx
  const Scaleform::GFx::AS3::VM *v5; // ebp
  char *PkgName; // edx
  Scaleform::GFx::ASStringManager *pStringManager; // esi
  const Scaleform::GFx::AS3::VM *v8; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *pObject; // esi
  Scaleform::GFx::AS3::GASRefCountBase *v10; // ecx
  Scaleform::GFx::AS3::GASRefCountBase *v11; // esi
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::GFx::AS3::TypeInfo *ConstStringNode; // esi
  Scaleform::GFx::ASString uri; // [esp+10h] [ebp-8h] BYREF
  Scaleform::GFx::AS3::StringManager *sm; // [esp+14h] [ebp-4h]

  v4 = ti;
  this->Obj.pObject = 0;
  this->Name.Flags = 0;
  v5 = vm;
  this->Name.Bonus.pWeakProxy = 0;
  PkgName = (char *)v4->PkgName;
  pStringManager = v5->StringManagerRef->pStringManager;
  sm = v5->StringManagerRef;
  uri.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pStringManager, PkgName, strlen(PkgName), 0);
  ++uri.pNode->RefCount;
  if ( uri.pNode->Size )
  {
    pObject = (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)v5->TraitsNamespace.pObject->ITraits.pObject;
    if ( (_S10_0 & 1) == 0 )
    {
      _S10_0 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInternedInstance(
      pObject,
      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&vm,
      NS_Public,
      &uri,
      &v);
  }
  else
  {
    v8 = (const Scaleform::GFx::AS3::VM *)v5->PublicNamespace.pObject;
    vm = v8;
    if ( !v8 )
      goto LABEL_8;
    ++v8->GC.GC;
    v8->GC.GC = (Scaleform::GFx::AS3::ASRefCountCollector *)((int)v8->GC.GC & 0x8FBFFFFF);
  }
  v8 = vm;
LABEL_8:
  v10 = this->Obj.pObject;
  v11 = (Scaleform::GFx::AS3::GASRefCountBase *)v8;
  if ( v8 != (const Scaleform::GFx::AS3::VM *)v10 )
  {
    if ( v10 )
    {
      if ( ((unsigned __int8)v10 & 1) != 0 )
      {
        this->Obj.pObject = (Scaleform::GFx::AS3::GASRefCountBase *)((char *)v10 - 1);
      }
      else
      {
        RefCount = v10->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          v10->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
        }
      }
    }
    this->Obj.pObject = v11;
  }
  pNode = uri.pNode;
  --uri.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  ConstStringNode = (const Scaleform::GFx::AS3::TypeInfo *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                             sm->pStringManager,
                                                             (char *)ti->Name,
                                                             strlen(ti->Name),
                                                             0);
  ++ConstStringNode->Parent;
  ti = ConstStringNode;
  Scaleform::GFx::AS3::Value::Assign(&this->Name, (const Scaleform::GFx::ASString *)&ti);
  if ( ConstStringNode->Parent-- == (const Scaleform::GFx::AS3::TypeInfo *)1 )
    Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)ConstStringNode);
  Scaleform::GFx::AS3::Multiname::PostProcessName(this, 0);
}


void __thiscall Scaleform::GFx::AS3::Multiname::Multiname(
        Scaleform::GFx::AS3::Multiname *this,
        const Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::ASStringNode *qname)
{
  Scaleform::StringDataPtr *v3; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> *p_Obj; // ebp
  char v5; // bl
  int LastChar; // eax
  unsigned int Size; // ecx
  unsigned int v8; // edx
  char *pStr; // esi
  const Scaleform::GFx::AS3::VM *v10; // edi
  const Scaleform::GFx::AS3::VM *v11; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *pObject; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> v13; // ecx
  Scaleform::GFx::AS3::GASRefCountBase *v14; // esi
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::AS3::VM *StringNode; // esi
  char *name; // [esp+14h] [ebp-8h]
  unsigned int name_4; // [esp+18h] [ebp-4h]

  v3 = (Scaleform::StringDataPtr *)qname;
  this->Kind = MN_QName;
  p_Obj = &this->Obj;
  this->Obj.pObject = 0;
  this->Name.Flags = 0;
  this->Name.Bonus.pWeakProxy = 0;
  v5 = 1;
  LastChar = Scaleform::StringDataPtr::FindLastChar(v3, 58, 0xFFFFFFFF);
  if ( LastChar < 0 )
  {
    v5 = 0;
    LastChar = Scaleform::StringDataPtr::FindLastChar(v3, 46, 0xFFFFFFFF);
  }
  Size = v3->Size;
  v8 = LastChar + 1;
  if ( Size < LastChar + 1 )
    v8 = v3->Size;
  pStr = (char *)v3->pStr;
  name = &pStr[v8];
  name_4 = Size - v8;
  if ( LastChar <= 0 )
  {
    v10 = vm;
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)p_Obj,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)vm->PublicNamespace.pObject);
    goto LABEL_25;
  }
  if ( v5 )
    LastChar = LastChar - 1 < 0 ? 0 : LastChar - 1;
  v10 = vm;
  qname = Scaleform::GFx::ASStringManager::CreateStringNode(vm->StringManagerRef->pStringManager, pStr, LastChar);
  ++qname->RefCount;
  if ( qname->Size )
  {
    pObject = (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)v10->TraitsNamespace.pObject->ITraits.pObject;
    if ( (_S10_0 & 1) == 0 )
    {
      _S10_0 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInternedInstance(
      pObject,
      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&vm,
      NS_Public,
      (Scaleform::GFx::ASString *)&qname,
      &v);
    goto LABEL_14;
  }
  v11 = (const Scaleform::GFx::AS3::VM *)v10->PublicNamespace.pObject;
  vm = v11;
  if ( v11 )
  {
    ++v11->GC.GC;
    v11->GC.GC = (Scaleform::GFx::AS3::ASRefCountCollector *)((int)v11->GC.GC & 0x8FBFFFFF);
LABEL_14:
    v11 = vm;
  }
  v13.pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)p_Obj->pObject;
  v14 = (Scaleform::GFx::AS3::GASRefCountBase *)v11;
  if ( v11 != (const Scaleform::GFx::AS3::VM *)p_Obj->pObject )
  {
    if ( v13.pObject )
    {
      if ( ((int)v13.pObject & 1) != 0 )
      {
        p_Obj->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)((char *)v13.pObject - 1);
      }
      else
      {
        RefCount = v13.pObject->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          v13.pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13.pObject);
        }
      }
    }
    p_Obj->pObject = v14;
  }
  v16 = qname;
  --qname->RefCount;
  if ( !v16->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
LABEL_25:
  StringNode = (Scaleform::GFx::AS3::VM *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                            v10->StringManagerRef->pStringManager,
                                            name,
                                            name_4);
  ++StringNode->StringManagerRef;
  vm = StringNode;
  Scaleform::GFx::AS3::Value::Assign(&this->Name, (const Scaleform::GFx::ASString *)&vm);
  if ( StringNode->StringManagerRef-- == (Scaleform::GFx::AS3::StringManager *)1 )
    Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)StringNode);
  Scaleform::GFx::AS3::Multiname::PostProcessName(this, 0);
}
