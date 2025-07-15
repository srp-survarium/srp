void __thiscall Scaleform::GFx::AS3::Impl::SparseArray::Set(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  unsigned int v4; // ecx
  unsigned int Size; // eax
  unsigned int v6; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *pTable; // edi
  void *pHeap; // [esp-Ch] [ebp-18h]
  Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef key; // [esp+4h] [ebp-8h] BYREF

  v4 = ind;
  if ( ind >= this->Length )
  {
    Scaleform::GFx::AS3::Impl::SparseArray::Resize(this, ind + 1);
    v4 = ind;
  }
  Size = this->ValueA.Data.Size;
  if ( v4 >= Size )
  {
    if ( v4 == Size )
    {
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &this->ValueA.Data,
        v);
      Scaleform::GFx::AS3::Impl::SparseArray::Optimize(this);
    }
    else
    {
      key.pFirst = &ind;
      pHeap = this->ValueH.mHash.pHeap;
      key.pSecond = v;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
        &this->ValueH.mHash,
        pHeap,
        &key);
      v6 = ind;
      if ( ind < this->ValueHLowInd || (pTable = this->ValueH.mHash.pTable) != 0 && pTable->EntryCount == 1 )
        this->ValueHLowInd = ind;
      if ( v6 > this->ValueHHighInd )
        this->ValueHHighInd = v6;
    }
  }
  else
  {
    Scaleform::GFx::AS3::Value::Assign(&this->ValueA.Data.Data[v4], v);
  }
}
