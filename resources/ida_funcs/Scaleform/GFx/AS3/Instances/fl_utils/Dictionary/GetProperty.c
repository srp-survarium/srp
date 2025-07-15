Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::GetProperty(
        Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  bool v5; // bl
  const Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *pHash; // ebp
  int Index; // edi
  int v8; // esi
  Scaleform::GFx::AS3::CheckResult *v9; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::Iterator it; // [esp+Ch] [ebp-8h] BYREF

  v5 = 0;
  if ( Scaleform::GFx::AS3::Multiname::ContainsNamespace(prop_name, this->pTraits.pObject->pVM->PublicNamespace.pObject) )
  {
    Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::FindKey(this, &it, prop_name);
    pHash = it.pHash;
    if ( it.pHash )
    {
      if ( it.pHash->pTable )
      {
        Index = it.Index;
        if ( it.Index <= (signed int)it.pHash->pTable->SizeMask )
        {
          if ( this->WeakKeys )
          {
            v8 = 5 * it.Index;
            if ( !Scaleform::GFx::AS3::Value::IsValidWeakRef((Scaleform::GFx::AS3::Value *)&it.pHash->pTable[5 * it.Index + 2]) )
            {
              Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::Iterator::RemoveAlt<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>>(
                &it,
                (const Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *)&pHash->pTable[v8 + 2]);
              v9 = result;
              result->Result = 0;
              return v9;
            }
          }
          Scaleform::GFx::AS3::Value::Assign(value, (const Scaleform::GFx::AS3::Value *)&pHash->pTable[5 * Index + 4]);
          v5 = 1;
        }
      }
    }
  }
  v9 = result;
  result->Result = v5;
  return v9;
}
