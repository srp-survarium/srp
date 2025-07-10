void __thiscall Scaleform::GFx::AS3::Impl::SparseArray::RemoveMultipleAt(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        unsigned int pos,
        unsigned int count,
        Scaleform::GFx::AS3::Impl::SparseArray::OP op)
{
  unsigned int v4; // ebp
  unsigned int v6; // ebx
  unsigned int Size; // edi
  unsigned int v8; // ecx
  unsigned int v9; // eax
  unsigned int v10; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *pTable; // eax
  unsigned int ValueHLowInd; // eax
  unsigned int v13; // edi
  unsigned int ValueHHighInd; // edx
  unsigned int RightEqualInd; // eax
  unsigned int count_a; // [esp+8h] [ebp-Ch]
  Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef key; // [esp+Ch] [ebp-8h] BYREF

  v4 = count;
  if ( !count )
    return;
  v6 = pos;
  Size = this->ValueA.Data.Size;
  if ( pos < Size )
  {
    v8 = Size - pos;
    v9 = pos + count;
    count_a = Size - pos;
    if ( pos + count < Size )
    {
      pos += count;
      key.pFirst = &pos;
      do
      {
        if ( !this->ValueHLowInd )
          this->ValueHLowInd = v9;
        key.pSecond = &this->ValueA.Data.Data[v9];
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
          &this->ValueH.mHash,
          this->ValueH.mHash.pHeap,
          &key);
        v10 = pos;
        if ( this->ValueHHighInd < pos )
          this->ValueHHighInd = pos;
        v9 = v10 + 1;
        pos = v9;
      }
      while ( v9 < Size );
      v8 = count_a;
      v4 = count;
    }
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::RemoveMultipleAt(
      &this->ValueA,
      v6,
      v8);
  }
  pTable = this->ValueH.mHash.pTable;
  if ( pTable )
  {
    if ( pTable->EntryCount )
    {
      ValueHLowInd = this->ValueHLowInd;
      v13 = v6 + v4;
      if ( ValueHLowInd < v6 + v4 )
      {
        ValueHHighInd = this->ValueHHighInd;
        if ( ValueHHighInd >= v6 )
        {
          if ( ValueHLowInd < v6 )
            goto LABEL_20;
          if ( ValueHHighInd < v13 )
          {
            Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>(&this->ValueH.mHash);
            RightEqualInd = 0;
            this->ValueHHighInd = 0;
LABEL_25:
            this->ValueHLowInd = RightEqualInd;
            goto LABEL_26;
          }
          if ( ValueHLowInd < v6 )
LABEL_20:
            ValueHLowInd = v6;
          Scaleform::GFx::AS3::Impl::SparseArray::RemoveHash(this, ValueHLowInd, v4);
          if ( this->ValueHHighInd < v13 )
            this->ValueHHighInd = Scaleform::GFx::AS3::Impl::SparseArray::GetLeftEqualInd(this, v6);
          if ( this->ValueHLowInd < v6 )
            goto LABEL_26;
          RightEqualInd = Scaleform::GFx::AS3::Impl::SparseArray::GetRightEqualInd(this, v6 + v4, this->ValueHHighInd);
          goto LABEL_25;
        }
      }
    }
  }
LABEL_26:
  if ( op == opCut && this->Length <= v6 + v4 )
    this->Length = v6;
}
