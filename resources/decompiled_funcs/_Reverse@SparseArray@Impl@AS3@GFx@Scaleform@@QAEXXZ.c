void __thiscall Scaleform::GFx::AS3::Impl::SparseArray::Reverse(Scaleform::GFx::AS3::Impl::SparseArray *this)
{
  unsigned int Size; // edx
  unsigned int Length; // eax
  unsigned int v3; // esi
  unsigned int v4; // ebx
  unsigned int v5; // edi
  Scaleform::GFx::AS3::Value *Data; // ecx
  unsigned int v7; // eax
  Scaleform::GFx::AS3::Value *v8; // ecx
  Scaleform::GFx::AS3::Value *p_DefaultValue; // eax
  signed int Index; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *v11; // eax
  Scaleform::HashDH<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>,2,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> > *p_ValueH; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> > v13; // ebp
  int v14; // ecx
  int v15; // eax
  int v16; // edx
  signed int v17; // eax
  int v18; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> > v19; // edi
  int v20; // ecx
  int v21; // eax
  BOOL v22; // edx
  signed int v23; // eax
  int v24; // eax
  const Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef *p_tmp; // edx
  void *pHeap; // edx
  int v27; // ecx
  int v28; // eax
  BOOL v29; // edx
  signed int v30; // eax
  int v31; // eax
  Scaleform::GFx::AS3::Impl::SparseArray *v32; // esi
  unsigned int LeftEqualInd; // eax
  void *v34; // [esp-8h] [ebp-78h]
  void *v35; // [esp-8h] [ebp-78h]
  bool range_changed; // [esp+17h] [ebp-59h]
  unsigned int to; // [esp+18h] [ebp-58h] BYREF
  Scaleform::GFx::AS3::Impl::SparseArray *v38; // [esp+1Ch] [ebp-54h]
  unsigned int v39; // [esp+20h] [ebp-50h] BYREF
  Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef key; // [esp+24h] [ebp-4Ch] BYREF
  unsigned int v41; // [esp+2Ch] [ebp-44h] BYREF
  Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef v42; // [esp+30h] [ebp-40h] BYREF
  Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef v43; // [esp+38h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value tmp; // [esp+40h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value value_to; // [esp+50h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value value_from; // [esp+60h] [ebp-10h] BYREF

  Size = this->ValueA.Data.Size;
  Length = this->Length;
  v38 = this;
  v41 = Size;
  if ( Length == Size )
  {
    Scaleform::Alg::ReverseArray<Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy>>(&this->ValueA);
    return;
  }
  v3 = 0;
  v4 = 0;
  v5 = Length - 1;
  to = Length - 1;
  if ( Size )
  {
    v39 = 0;
    do
    {
      Data = this->ValueA.Data.Data;
      v7 = *(unsigned int *)((char *)&Data->Flags + v3);
      v8 = (Scaleform::GFx::AS3::Value *)((char *)Data + v3);
      tmp.Flags = v7;
      tmp.Bonus.pWeakProxy = v8->Bonus.pWeakProxy;
      tmp.value.VNumber = v8->value.VNumber;
      if ( (v8->Flags & 0x1F) > 9 )
      {
        if ( (v8->Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::AddRefWeakRef(v8);
        else
          Scaleform::GFx::AS3::Value::AddRefInternal(v8);
        v5 = to;
      }
      key.pFirst = (const unsigned int *)v5;
      if ( v5 >= v38->ValueA.Data.Size )
      {
        if ( v5 < v38->ValueHLowInd
          || v5 > v38->ValueHHighInd
          || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::findIndexAlt<unsigned int>(
                        &v38->ValueH.mHash,
                        (const unsigned int *)&key),
              Index < 0)
          || (v11 = &v38->ValueH.mHash.pTable[4 * Index + 2]) == 0
          || (p_DefaultValue = (Scaleform::GFx::AS3::Value *)&v11[1]) == 0 )
        {
          p_DefaultValue = (Scaleform::GFx::AS3::Value *)&v38->DefaultValue;
        }
      }
      else
      {
        p_DefaultValue = &v38->ValueA.Data.Data[v5];
      }
      Scaleform::GFx::AS3::Impl::SparseArray::Set(v38, v4, p_DefaultValue);
      Scaleform::GFx::AS3::Impl::SparseArray::Set(v38, to, &tmp);
      if ( (tmp.Flags & 0x1F) > 9 )
      {
        if ( (tmp.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&tmp);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&tmp);
      }
      ++v4;
      v3 = v39 + 16;
      v5 = to - 1;
      v39 += 16;
      --to;
      this = v38;
    }
    while ( v4 < v41 );
  }
  value_from.Flags = 0;
  value_from.Bonus.pWeakProxy = 0;
  value_to.Flags = 0;
  value_to.Bonus.pWeakProxy = 0;
  range_changed = 0;
  if ( v4 < v5 )
  {
    p_ValueH = &this->ValueH;
    while ( 1 )
    {
      v13.pTable = p_ValueH->mHash.pTable;
      v39 = v4;
      if ( v13.pTable )
        break;
LABEL_44:
      --v5;
      ++v4;
      to = v5;
      if ( v4 >= v5 )
      {
        if ( range_changed )
        {
          v32 = v38;
          LeftEqualInd = Scaleform::GFx::AS3::Impl::SparseArray::GetLeftEqualInd(v38, v38->ValueHHighInd);
          v32->ValueHHighInd = LeftEqualInd;
          v32->ValueHLowInd = Scaleform::GFx::AS3::Impl::SparseArray::GetRightEqualInd(v32, 0, LeftEqualInd);
        }
        goto LABEL_47;
      }
    }
    v14 = 5381;
    v15 = 4;
    do
    {
      v16 = *((unsigned __int8 *)&v38 + v15-- + 3);
      v14 = v16 + 65599 * v14;
    }
    while ( v15 );
    v17 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::findIndexCore<unsigned int>(
            &p_ValueH->mHash,
            &v39,
            v14 & v13.pTable->SizeMask);
    if ( v17 >= 0 && (v18 = (int)&v13.pTable[4 * v17 + 2]) != 0 )
    {
      Scaleform::GFx::AS3::Value::Assign(&value_from, (const Scaleform::GFx::AS3::Value *)(v18 + 8));
      v19.pTable = p_ValueH->mHash.pTable;
      if ( !p_ValueH->mHash.pTable )
        goto LABEL_36;
      v20 = 5381;
      v21 = 4;
      do
      {
        v22 = *(&range_changed + v21--);
        v20 = v22 + 65599 * v20;
      }
      while ( v21 );
      v23 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::findIndexCore<unsigned int>(
              &p_ValueH->mHash,
              &to,
              v20 & v19.pTable->SizeMask);
      if ( v23 < 0 || (v24 = (int)&v19.pTable[4 * v23 + 2]) == 0 )
      {
LABEL_36:
        range_changed = 1;
        v41 = v4;
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::RemoveAlt<unsigned int>(
          &p_ValueH->mHash,
          &v41);
        v43.pFirst = &to;
        pHeap = p_ValueH->mHash.pHeap;
        v43.pSecond = &value_from;
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
          &p_ValueH->mHash,
          pHeap,
          &v43);
LABEL_43:
        v5 = to;
        goto LABEL_44;
      }
      Scaleform::GFx::AS3::Value::Assign(&value_to, (const Scaleform::GFx::AS3::Value *)(v24 + 8));
      key.pFirst = &to;
      v34 = p_ValueH->mHash.pHeap;
      key.pSecond = &value_from;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
        &p_ValueH->mHash,
        v34,
        &key);
      v42.pFirst = &v41;
      v42.pSecond = &value_to;
      p_tmp = &v42;
    }
    else
    {
      v27 = 5381;
      v28 = 4;
      do
      {
        v29 = *(&range_changed + v28--);
        v27 = v29 + 65599 * v27;
      }
      while ( v28 );
      v30 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::findIndexCore<unsigned int>(
              &p_ValueH->mHash,
              &to,
              v27 & v13.pTable->SizeMask);
      if ( v30 < 0 )
        goto LABEL_44;
      v31 = (int)&v13.pTable[4 * v30 + 2];
      if ( !v31 )
        goto LABEL_44;
      Scaleform::GFx::AS3::Value::Assign(&value_to, (const Scaleform::GFx::AS3::Value *)(v31 + 8));
      range_changed = 1;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::RemoveAlt<unsigned int>(
        &p_ValueH->mHash,
        &to);
      tmp.Flags = (unsigned int)&v41;
      tmp.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)&value_to;
      p_tmp = (const Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef *)&tmp;
    }
    v35 = p_ValueH->mHash.pHeap;
    v41 = v4;
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
      &p_ValueH->mHash,
      v35,
      p_tmp);
    goto LABEL_43;
  }
LABEL_47:
  if ( (value_to.Flags & 0x1F) > 9 )
  {
    if ( (value_to.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&value_to);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value_to);
  }
  if ( (value_from.Flags & 0x1F) > 9 )
  {
    if ( (value_from.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&value_from);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value_from);
  }
}
