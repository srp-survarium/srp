void __thiscall Scaleform::GFx::AS3::Impl::SparseArray::Append(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        Scaleform::GFx::AS3::Impl::SparseArray *other,
        unsigned int ind,
        unsigned int num)
{
  unsigned int v5; // ebp
  unsigned int v6; // ebx
  Scaleform::GFx::AS3::Value *v7; // eax
  unsigned int v8; // ebx
  unsigned int sizeO; // [esp+10h] [ebp-Ch]
  Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef key; // [esp+14h] [ebp-8h] BYREF

  v5 = 0;
  sizeO = other->Length;
  if ( this->Length == this->ValueA.Data.Size )
  {
    if ( num )
    {
      v6 = ind;
      do
      {
        if ( v6 >= sizeO )
          break;
        v7 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Impl::SparseArray::At(other, v6);
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
          &this->ValueA.Data,
          v7);
        ++v5;
        ++v6;
      }
      while ( v5 < num );
    }
    this->Length = this->ValueA.Data.Size;
  }
  else if ( num )
  {
    v8 = ind;
    do
    {
      if ( v8 >= sizeO )
        break;
      this->ValueHHighInd = this->Length;
      key.pFirst = &this->ValueHHighInd;
      key.pSecond = Scaleform::GFx::AS3::Impl::SparseArray::At(other, v8);
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
        &this->ValueH.mHash,
        this->ValueH.mHash.pHeap,
        &key);
      ++this->Length;
      ++v5;
      ++v8;
    }
    while ( v5 < num );
  }
}
