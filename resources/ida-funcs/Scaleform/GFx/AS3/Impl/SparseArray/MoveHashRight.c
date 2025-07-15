void __thiscall Scaleform::GFx::AS3::Impl::SparseArray::MoveHashRight(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        unsigned int first_ind,
        unsigned int offset)
{
  unsigned int v3; // ebp
  __int16 Flags; // dx
  unsigned int v5; // eax
  Scaleform::HashDH<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>,2,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> > *p_ValueH; // edi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> > v7; // esi
  unsigned int v8; // ebx
  int v9; // ecx
  int v10; // eax
  int v11; // edx
  signed int Index; // eax
  int v13; // eax
  void *pHeap; // edx
  Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef key; // [esp+4h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+Ch] [ebp-10h] BYREF
  _UNKNOWN *retaddr; // [esp+1Ch] [ebp+0h]

  v3 = first_ind;
  Flags = 0;
  v5 = this->ValueHHighInd + 1;
  v.Flags = 0;
  v.Bonus.pWeakProxy = 0;
  if ( v5 > first_ind )
  {
    p_ValueH = &this->ValueH;
    do
    {
      v7.pTable = p_ValueH->mHash.pTable;
      v8 = v5 - 1;
      first_ind = v5 - 1;
      if ( v7.pTable )
      {
        v9 = 5381;
        v10 = 4;
        do
        {
          v11 = *((unsigned __int8 *)&retaddr + v10-- + 3);
          v9 = v11 + 65599 * v9;
        }
        while ( v10 );
        Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::findIndexCore<unsigned int>(
                  &p_ValueH->mHash,
                  &first_ind,
                  v9 & v7.pTable->SizeMask);
        if ( Index >= 0 )
        {
          v13 = (int)&v7.pTable[4 * Index + 2];
          if ( v13 )
          {
            Scaleform::GFx::AS3::Value::Assign(&v, (const Scaleform::GFx::AS3::Value *)(v13 + 8));
            Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::RemoveAlt<unsigned int>(
              &p_ValueH->mHash,
              &first_ind);
            key.pFirst = &first_ind;
            pHeap = p_ValueH->mHash.pHeap;
            first_ind += offset;
            key.pSecond = &v;
            Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
              &p_ValueH->mHash,
              pHeap,
              &key);
          }
        }
      }
      v5 = v8;
    }
    while ( v8 > v3 );
    Flags = v.Flags;
  }
  if ( (Flags & 0x1Fu) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
}
