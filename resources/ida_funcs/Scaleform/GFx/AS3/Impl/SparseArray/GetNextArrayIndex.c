Scaleform::GFx::AS3::AbsoluteIndex *__thiscall Scaleform::GFx::AS3::Impl::SparseArray::GetNextArrayIndex(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        Scaleform::GFx::AS3::AbsoluteIndex *result,
        Scaleform::GFx::AS3::AbsoluteIndex ind)
{
  Scaleform::GFx::AS3::AbsoluteIndex *v3; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *pTable; // eax
  unsigned int Size; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *v6; // eax
  unsigned int ValueHHighInd; // ebx
  unsigned int v8; // edi
  Scaleform::HashDH<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>,2,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> > *p_ValueH; // esi
  signed int Index; // eax
  unsigned int i; // [esp+Ch] [ebp-4h] BYREF

  if ( ind.Index < 0 )
  {
    if ( this->ValueA.Data.Size )
    {
      v3 = result;
      result->Index = 0;
      return v3;
    }
    pTable = this->ValueH.mHash.pTable;
    if ( pTable && pTable->EntryCount )
    {
      v3 = result;
      result->Index = this->ValueHLowInd;
      return v3;
    }
LABEL_20:
    v3 = result;
    result->Index = -1;
    return v3;
  }
  Size = this->ValueA.Data.Size;
  if ( ind.Index < Size )
  {
    if ( ind.Index != Size - 1 )
    {
      v3 = result;
      result->Index = ind.Index + 1;
      return v3;
    }
    v6 = this->ValueH.mHash.pTable;
    if ( v6 && v6->EntryCount )
    {
      v3 = result;
      result->Index = this->ValueHLowInd;
      return v3;
    }
  }
  if ( ind.Index < this->ValueHLowInd )
    goto LABEL_20;
  ValueHHighInd = this->ValueHHighInd;
  if ( ind.Index > ValueHHighInd )
    goto LABEL_20;
  v8 = ind.Index + 1;
  i = ind.Index + 1;
  if ( ind.Index + 1 > ValueHHighInd )
    goto LABEL_20;
  p_ValueH = &this->ValueH;
  while ( 1 )
  {
    Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::findIndexAlt<unsigned int>(
              &p_ValueH->mHash,
              &i);
    if ( Index >= 0
      && &p_ValueH->mHash.pTable[4 * Index] != (Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *)-16 )
    {
      break;
    }
    i = ++v8;
    if ( v8 > ValueHHighInd )
      goto LABEL_20;
  }
  v3 = result;
  result->Index = v8;
  return v3;
}
