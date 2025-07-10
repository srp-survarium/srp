char __thiscall Scaleform::GFx::AS3ValueObjectInterface::SetMember(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::String pdata,
        char *name,
        Scaleform::GFx::ASStringNode *value,
        bool isdobj)
{
  char *v5; // ebp
  Scaleform::GFx::AS3::MovieRoot *pObject; // edi
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASStringNode *v8; // esi
  Scaleform::GFx::ASStringManager *pManager; // edx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v10; // eax
  void *pWeakProxy; // eax
  bool v12; // zf
  Scaleform::String v13; // esi
  int v14; // eax
  unsigned int Size; // ecx
  unsigned int v16; // eax
  int v17; // ecx
  int v18; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v19; // esi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v20; // esi
  int v21; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *Flags; // ecx
  void *v23; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v26; // eax
  Scaleform::GFx::ASString propName; // [esp+10h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::VM *vm; // [esp+14h] [ebp-3Ch]
  Scaleform::GFx::AS3::Value nameVal; // [esp+18h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value asval; // [esp+28h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+38h] [ebp-18h] BYREF

  v5 = name;
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  vm = pObject->pAVM.pObject;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(pObject->BuiltinsMgr.pStringManager, name);
  v8 = StringNode;
  pManager = StringNode->pManager;
  ++StringNode->RefCount;
  nameVal.Flags = 10;
  nameVal.Bonus.pWeakProxy = 0;
  nameVal.value.VS._1.VInt = (int)StringNode;
  if ( StringNode == &pManager->NullStringNode )
  {
    nameVal.value.VS._1.VInt = 0;
    nameVal.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)nameVal.Bonus.pWeakProxy;
    nameVal.Flags = 12;
  }
  else
  {
    ++StringNode->RefCount;
  }
  v10 = vm->PublicNamespace.pObject;
  mn.Kind = MN_QName;
  mn.Obj.pObject = v10;
  if ( v10 )
    v10->RefCount = (v10->RefCount + 1) & 0x8FBFFFFF;
  mn.Name.Flags = 0;
  mn.Name.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(&mn, &nameVal);
  if ( (nameVal.Flags & 0x1F) > 9 )
  {
    if ( (nameVal.Flags & 0x200) != 0 )
    {
      pWeakProxy = nameVal.Bonus.pWeakProxy;
      v12 = nameVal.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&nameVal);
    }
  }
  v12 = v8->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  v13.pData = pdata.pData;
  v14 = *(_DWORD *)pdata.pData[1].Data;
  if ( (unsigned int)(*(_DWORD *)(v14 + 60) - 23) < 6 && (*(_DWORD *)(v14 + 56) & 0x20) == 0 )
  {
    Size = pdata.pData[4].Size;
    v16 = (*(_WORD *)(Size + 62) & 0x200) != 0 ? Size : 0;
    if ( v16
      && (v17 = *(unsigned __int8 *)((*(_WORD *)(Size + 62) & 0x200) != 0 ? Size + 0x41 : 65),
          (v18 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)(v16 + 4 * v17) + 20))(v16 + 4 * v17)) != 0) )
    {
      v19 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v18 - 36);
    }
    else
    {
      v19 = 0;
    }
    propName.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(pObject->BuiltinsMgr.pStringManager, v5);
    ++propName.pNode->RefCount;
    v20 = Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildByName(
            v19,
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *)&nameVal,
            &propName)->pObject;
    if ( nameVal.Flags )
    {
      if ( (nameVal.Flags & 1) == 0 )
      {
        v21 = *(_DWORD *)(nameVal.Flags + 16);
        Flags = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)nameVal.Flags;
        if ( ((unsigned int)&byte_3FFFFF & v21) != 0 )
        {
          *(_DWORD *)(nameVal.Flags + 16) = v21 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(Flags);
        }
      }
    }
    if ( v20 )
    {
      Scaleform::String::String(&pdata);
      nameVal.Flags = 0;
      nameVal.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)&pdata;
      Scaleform::Format<char const *>(
        (const Scaleform::MsgFormat::Sink *)&nameVal,
        "Property '{0}' already exists as a DisplayObject. SetMember aborted.",
        (const char **)&name);
      pObject->Output(
        &pObject->Scaleform::GFx::AS3::FlashUI,
        Output_Error,
        (const char *)((pdata.HeapTypeBits & 0xFFFFFFFC) + 8));
      v23 = (void *)(pdata.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((pdata.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v23);
      pNode = propName.pNode;
      --propName.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
      return 0;
    }
    v26 = propName.pNode;
    --propName.pNode->RefCount;
    if ( !v26->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v26);
    v13.pData = pdata.pData;
  }
  asval.Flags = 0;
  asval.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(pObject, value, &asval);
  if ( *(_BYTE *)(*(int (__thiscall **)(Scaleform::String, Scaleform::String *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(*(_DWORD *)v13.HeapTypeBits + 12))(
                   v13,
                   &pdata,
                   &mn,
                   &asval) )
  {
    Scaleform::GFx::AS3::Value::~Value(&asval);
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    return 1;
  }
  else
  {
    if ( vm->HandleException )
      Scaleform::GFx::AS3::VM::OutputAndIgnoreException(vm);
    Scaleform::GFx::AS3::Value::~Value(&asval);
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    return 0;
  }
}
