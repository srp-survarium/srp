void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::AddDynamicSlotValuePair(
        Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this,
        Scaleform::GFx::AS3::Value *prop_name,
        const Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::SlotInfo::Attribute a)
{
  Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *v4; // edi
  unsigned int Flags; // eax
  int v6; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *p_mHash; // ebp
  const Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *v8; // ebx
  int v9; // esi
  int v10; // edi
  unsigned int v11; // eax
  long double num; // [esp+1Ch] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value strong_key; // [esp+24h] [ebp-10h] BYREF

  v4 = this;
  Flags = prop_name->Flags;
  strong_key.Bonus.pWeakProxy = prop_name->Bonus.pWeakProxy;
  strong_key.value.VNumber = prop_name->value.VNumber;
  strong_key.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(prop_name);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(prop_name);
  }
  v6 = strong_key.Flags & 0x1F;
  if ( v6 == 10 )
  {
    if ( Scaleform::GFx::AS3::GetStrNumber(
           (Scaleform::GFx::AS3::CheckResult *)&prop_name,
           strong_key.value.VS._1.VStr,
           &num)->Result )
      Scaleform::GFx::AS3::Value::SetNumber(&strong_key, num);
  }
  else if ( v6 == 2 || v6 == 3 )
  {
    Scaleform::GFx::AS3::Value::ToNumberValue(&strong_key, (Scaleform::GFx::AS3::CheckResult *)&prop_name);
  }
  p_mHash = &v4->ValueH.mHash;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::FindAlt<Scaleform::GFx::AS3::Value>(
    &v4->ValueH.mHash,
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::Iterator *)&num,
    &strong_key);
  v8 = (const Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *)LODWORD(num);
  if ( LODWORD(num) )
  {
    if ( *(_DWORD *)LODWORD(num) )
    {
      v9 = HIDWORD(num);
      if ( SHIDWORD(num) <= *(_DWORD *)(*(_DWORD *)LODWORD(num) + 4) )
      {
        if ( !v4->WeakKeys
          || (v10 = 5 * HIDWORD(num),
              Scaleform::GFx::AS3::Value::IsValidWeakRef((Scaleform::GFx::AS3::Value *)(40 * HIDWORD(num)
                                                                                      + *(_DWORD *)LODWORD(num)
                                                                                      + 16))) )
        {
          Scaleform::GFx::AS3::Value::Assign((Scaleform::GFx::AS3::Value *)&v8->pTable[5 * v9 + 4], value);
          if ( (strong_key.Flags & 0x1F) <= 9 )
            return;
          if ( (strong_key.Flags & 0x200) != 0 )
            goto LABEL_21;
          goto LABEL_24;
        }
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::Iterator::RemoveAlt<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>>(
          (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::Iterator *)&num,
          (const Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *)&v8->pTable[v10 + 2]);
        v4 = this;
      }
    }
  }
  if ( v4->WeakKeys )
    Scaleform::GFx::AS3::Value::MakeWeakRef(&strong_key);
  HIDWORD(num) = value;
  LODWORD(num) = &strong_key;
  LOBYTE(value) = 0;
  v11 = Scaleform::GFx::AS3::Value::HashFunctor::operator()(
          (Scaleform::GFx::AS3::Value::HashFunctor *)&value,
          &strong_key);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeRef>(
    p_mHash,
    p_mHash,
    (const Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeRef *)&num,
    v11);
  if ( (strong_key.Flags & 0x1F) > 9 )
  {
    if ( (strong_key.Flags & 0x200) != 0 )
    {
LABEL_21:
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&strong_key);
      return;
    }
LABEL_24:
    Scaleform::GFx::AS3::Value::ReleaseInternal(&strong_key);
  }
}
