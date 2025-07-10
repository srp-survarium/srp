Scaleform::GFx::AS3::PropRef *__thiscall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::FindDynamicSlot(
        Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this,
        Scaleform::GFx::AS3::PropRef *result,
        const Scaleform::GFx::AS3::Multiname *prop_name)
{
  const Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *pHash; // ebx
  int Index; // edi
  int v6; // esi
  Scaleform::GFx::AS3::PropRef *v7; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::Iterator it; // [esp+10h] [ebp-8h] BYREF

  if ( !Scaleform::GFx::AS3::Multiname::ContainsNamespace(
          prop_name,
          this->pTraits.pObject->pVM->PublicNamespace.pObject) )
    goto LABEL_8;
  Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::FindKey(this, &it, prop_name);
  pHash = it.pHash;
  if ( !it.pHash )
    goto LABEL_8;
  if ( !it.pHash->pTable )
    goto LABEL_8;
  Index = it.Index;
  if ( it.Index > (signed int)it.pHash->pTable->SizeMask )
    goto LABEL_8;
  if ( this->WeakKeys )
  {
    v6 = 5 * it.Index;
    if ( !Scaleform::GFx::AS3::Value::IsValidWeakRef((Scaleform::GFx::AS3::Value *)&it.pHash->pTable[5 * it.Index + 2]) )
    {
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::Iterator::RemoveAlt<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>>(
        &it,
        (const Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *)&pHash->pTable[v6 + 2]);
LABEL_8:
      v7 = result;
      result->pSI = 0;
      result->SlotIndex = 0;
      result->This.Flags = 0;
      result->This.Bonus.pWeakProxy = 0;
      return v7;
    }
  }
  result->pSI = (const Scaleform::GFx::AS3::SlotInfo *)((int)&pHash->pTable[5 * Index + 4] | 1);
  Scaleform::GFx::AS3::Value::Value(&result->This, this);
  return result;
}
