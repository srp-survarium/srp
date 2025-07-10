const Scaleform::GFx::AS3::Value *__thiscall Scaleform::GFx::AS3::Impl::SparseArray::At(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        unsigned int ind)
{
  const Scaleform::GFx::AS3::Value *result; // eax
  Scaleform::HashDH<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>,2,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> > *p_ValueH; // edi
  signed int Index; // eax
  int v6; // eax

  if ( ind < this->ValueA.Data.Size )
    return &this->ValueA.Data.Data[ind];
  if ( ind < this->ValueHLowInd || ind > this->ValueHHighInd )
    return &this->DefaultValue;
  p_ValueH = &this->ValueH;
  Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::findIndexAlt<unsigned int>(
            &this->ValueH.mHash,
            &ind);
  if ( Index < 0 )
    return &this->DefaultValue;
  v6 = (int)&p_ValueH->mHash.pTable[4 * Index + 2];
  if ( !v6 )
    return &this->DefaultValue;
  result = (const Scaleform::GFx::AS3::Value *)(v6 + 8);
  if ( !result )
    return &this->DefaultValue;
  return result;
}
