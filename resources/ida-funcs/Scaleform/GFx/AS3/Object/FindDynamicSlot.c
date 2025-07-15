Scaleform::GFx::AS3::PropRef *__thiscall Scaleform::GFx::AS3::Object::FindDynamicSlot(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::PropRef *result,
        const Scaleform::GFx::AS3::Multiname *mn)
{
  bool v4; // zf
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v6; // ecx
  unsigned int *p_RefCount; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *pTable; // ebp
  unsigned int *v10; // edi
  signed int v11; // eax
  int v12; // eax
  int v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASString name; // [esp+8h] [ebp-Ch] BYREF
  Scaleform::GFx::AS3::Object::DynAttrsKey key; // [esp+Ch] [ebp-8h] BYREF

  name.pNode = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  ++name.pNode->RefCount;
  v4 = !Scaleform::GFx::AS3::Value::Convert2String(&mn->Name, (Scaleform::GFx::AS3::CheckResult *)&mn, &name)->Result;
  pNode = name.pNode;
  if ( v4 )
  {
    result->pSI = 0;
    result->SlotIndex = 0;
    result->This.Flags = 0;
    v6 = pNode;
    p_RefCount = &pNode->RefCount;
    result->This.Bonus.pWeakProxy = 0;
    if ( !--*p_RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    return result;
  }
  else
  {
    ++name.pNode->RefCount;
    pTable = this->DynAttrs.mHash.pTable;
    v10 = &pNode->RefCount;
    key.Flags = 0;
    key.Name.pNode = pNode;
    if ( pTable
      && (v11 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::Object::DynAttrsKey>(
                  &this->DynAttrs.mHash,
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
    result->pSI = (const Scaleform::GFx::AS3::SlotInfo *)(v13 | 1);
    result->This.Flags = 12;
    result->This.Bonus.pWeakProxy = 0;
    result->This.value.VS._1.VInt = (int)this;
    this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
    v4 = (*v10)-- == 1;
    if ( v4 )
      Scaleform::GFx::ASStringNode::ReleaseNode(key.Name.pNode);
    v14 = name.pNode;
    --name.pNode->RefCount;
    if ( !v14->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    return result;
  }
}
