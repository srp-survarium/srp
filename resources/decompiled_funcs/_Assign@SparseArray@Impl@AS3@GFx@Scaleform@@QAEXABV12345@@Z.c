void __thiscall Scaleform::GFx::AS3::Impl::SparseArray::Assign(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        const Scaleform::GFx::AS3::Impl::SparseArray *other)
{
  if ( this != other )
  {
    this->Length = other->Length;
    this->ValueHLowInd = other->ValueHLowInd;
    this->ValueHHighInd = other->ValueHHighInd;
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Assign(
      &this->ValueH.mHash,
      other->ValueH.mHash.pHeap,
      &other->ValueH.mHash);
    this->ValueH.mHash.pHeap = other->ValueH.mHash.pHeap;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
      &this->ValueA,
      &other->ValueA);
  }
}
