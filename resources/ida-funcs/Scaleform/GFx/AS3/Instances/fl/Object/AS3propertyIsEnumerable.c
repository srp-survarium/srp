void __cdecl Scaleform::GFx::AS3::Instances::fl::Object::AS3propertyIsEnumerable(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASString argc,
        Scaleform::GFx::AS3::Value *argv)
{
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int v8; // eax
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  Scaleform::GFx::AS3::Value *v10; // ebp
  unsigned int v11; // eax
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ecx
  const Scaleform::GFx::AS3::SlotInfo *FixedSlot; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // ecx
  Scaleform::Hash<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > > *v17; // ecx
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::ASStringNode *v19; // edi
  unsigned int *p_RefCount; // esi
  bool v21; // zf
  Scaleform::GFx::ASStringNode *v22; // eax
  Scaleform::GFx::ASStringNode *v23; // eax
  Scaleform::GFx::ASStringNode *v24; // ecx
  Scaleform::GFx::ASStringNode *VStr; // esi
  Scaleform::StringDataPtr v26; // [esp-14h] [ebp-40h]
  Scaleform::GFx::AS3::Object *VObj; // [esp-4h] [ebp-30h]
  Scaleform::GFx::ASString str_name; // [esp+10h] [ebp-1Ch] BYREF
  unsigned int ind; // [esp+14h] [ebp-18h] BYREF
  unsigned int index; // [esp+18h] [ebp-14h] BYREF
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::ConstIterator it; // [esp+1Ch] [ebp-10h] BYREF
  Scaleform::GFx::AS3::VM::Error v32; // [esp+24h] [ebp-8h] BYREF

  index = 0;
  if ( !argc.pNode )
  {
    v26.pStr = "Object::AS3propertyIsEnumerable";
    v26.Size = 31;
    Scaleform::GFx::AS3::VM::Error::Error(&v32, eWrongArgumentCountError, vm, v26, 1, 1, 0);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(vm, v6);
    pNode = v32.Message.pNode;
    --v32.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  v8 = _this->Flags & 0x1F;
  if ( v8 - 12 <= 3 && _this->value.VS._1.VInt )
  {
    ind = 0;
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, _this);
    v10 = argv;
    if ( ValueTraits->TraitsType == Traits_Array && (ValueTraits->Flags & 0x20) == 0 )
    {
      v11 = argv->Flags & 0x1F;
      if ( v11 - 2 <= 2
        || v11 == 10
        && Scaleform::GFx::AS3::GetArrayInd((Scaleform::GFx::AS3::CheckResult *)&argc, argv->value.VS._1.VStr, &ind)->Result )
      {
        Scaleform::GFx::AS3::Value::SetBool(result, 1);
        return;
      }
    }
    pStringManager = vm->StringManagerRef->pStringManager;
    str_name.pNode = &pStringManager->EmptyStringNode;
    ++pStringManager->EmptyStringNode.RefCount;
    if ( !Scaleform::GFx::AS3::Value::Convert2String(v10, (Scaleform::GFx::AS3::CheckResult *)&argc, &str_name)->Result )
    {
LABEL_15:
      v15 = str_name.pNode;
      --str_name.pNode->RefCount;
      v16 = v15;
      if ( v15->RefCount )
        return;
      goto LABEL_16;
    }
    pObject = vm->PublicNamespace.pObject;
    VObj = _this->value.VS._1.VObj;
    index = 0;
    FixedSlot = Scaleform::GFx::AS3::FindFixedSlot(VObj->pTraits.pObject, &str_name, pObject, &index, VObj);
    if ( FixedSlot )
    {
      Scaleform::GFx::AS3::Value::SetBool(result, (*(_DWORD *)FixedSlot & 2) == 0);
      goto LABEL_15;
    }
    v17 = (Scaleform::Hash<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > > *)(_this->value.VS._1.VInt + 24);
    if ( _this->value.VS._1.VInt != -24 )
    {
      v18 = str_name.pNode;
      ++str_name.pNode->RefCount;
      v19 = v18;
      p_RefCount = &v18->RefCount;
      v32.ID = 0;
      v32.Message.pNode = v18;
      Scaleform::Hash<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>>::Find(
        v17,
        &it,
        (const Scaleform::GFx::AS3::Object::DynAttrsKey *)&v32);
      v21 = (*p_RefCount)-- == 1;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v19);
      if ( !Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::ConstIterator::IsEnd(&it) )
      {
        Scaleform::GFx::AS3::Value::SetBool(result, (it.pHash->pTable[4 * it.Index + 2].EntryCount & 1) == 0);
        v22 = str_name.pNode;
        --str_name.pNode->RefCount;
        v16 = v22;
        if ( v22->RefCount )
          return;
LABEL_16:
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
        return;
      }
    }
    v23 = str_name.pNode;
    --str_name.pNode->RefCount;
    v24 = v23;
    if ( v23->RefCount )
    {
LABEL_25:
      Scaleform::GFx::AS3::Value::SetBool(result, 0);
      return;
    }
LABEL_24:
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
    goto LABEL_25;
  }
  if ( v8 != 11 || (argv->Flags & 0x1F) != 0xA )
    goto LABEL_25;
  VStr = argv->value.VS._1.VStr;
  ++VStr->RefCount;
  v21 = ++VStr->RefCount == 1;
  --VStr->RefCount;
  argc.pNode = VStr;
  if ( v21 )
    Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
  if ( !Scaleform::GFx::ASString::operator==(&argc, "prefix") && !Scaleform::GFx::ASString::operator==(&argc, "uri") )
  {
    v21 = VStr->RefCount-- == 1;
    if ( !v21 )
      goto LABEL_25;
    v24 = VStr;
    goto LABEL_24;
  }
  Scaleform::GFx::AS3::Value::SetBool(result, 1);
  v21 = VStr->RefCount-- == 1;
  if ( v21 )
    Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
}
