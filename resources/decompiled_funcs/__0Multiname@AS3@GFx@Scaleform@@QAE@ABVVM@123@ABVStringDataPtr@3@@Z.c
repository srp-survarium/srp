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
