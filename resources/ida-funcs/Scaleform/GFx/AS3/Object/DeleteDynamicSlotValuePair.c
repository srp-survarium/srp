Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Object::DeleteDynamicSlotValuePair(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Multiname *mn)
{
  bool v4; // zf
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult *v6; // esi
  unsigned int *p_RefCount; // edi
  Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *p_DynAttrs; // ebp
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *pTable; // esi
  Scaleform::GFx::ASStringNode *v10; // ebx
  signed int v11; // eax
  int v12; // eax
  int v13; // esi
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // edi
  unsigned int *v16; // esi
  Scaleform::GFx::ASString str_name; // [esp+4h] [ebp-Ch] BYREF
  Scaleform::GFx::AS3::Object::DynAttrsKey key; // [esp+8h] [ebp-8h] BYREF

  str_name.pNode = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  ++str_name.pNode->RefCount;
  v4 = !Scaleform::GFx::AS3::Value::Convert2String(&mn->Name, (Scaleform::GFx::AS3::CheckResult *)&mn, &str_name)->Result;
  pNode = str_name.pNode;
  if ( v4 )
  {
    v6 = result;
    result->Result = 0;
  }
  else
  {
    ++str_name.pNode->RefCount;
    p_RefCount = &pNode->RefCount;
    p_DynAttrs = &this->DynAttrs;
    pTable = this->DynAttrs.mHash.pTable;
    v10 = pNode;
    LOBYTE(mn) = 1;
    key.Flags = 0;
    key.Name.pNode = pNode;
    if ( pTable
      && (v11 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::Object::DynAttrsKey>(
                  &p_DynAttrs->mHash,
                  &key,
                  pNode->HashFlags & pTable->SizeMask & 0xFFFFFF),
          v11 >= 0)
      && (v12 = (int)&pTable[4 * v11 + 2]) != 0 )
    {
      v13 = v12 + 8;
    }
    else
    {
      v13 = 0;
    }
    v4 = (*p_RefCount)-- == 1;
    if ( v4 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    if ( v13 )
    {
      v14 = str_name.pNode;
      ++str_name.pNode->RefCount;
      v15 = v14;
      v16 = &v14->RefCount;
      key.Flags = 0;
      key.Name.pNode = v14;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::AS3::Object::DynAttrsKey>(
        &p_DynAttrs->mHash,
        &key);
      v4 = (*v16)-- == 1;
      if ( v4 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    }
    else
    {
      LOBYTE(mn) = 0;
    }
    v6 = result;
    pNode = str_name.pNode;
    result->Result = (char)mn;
  }
  if ( !--pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return v6;
}
