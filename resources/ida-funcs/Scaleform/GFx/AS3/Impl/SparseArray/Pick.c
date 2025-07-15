void __thiscall Scaleform::GFx::AS3::Impl::SparseArray::Pick(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        Scaleform::GFx::AS3::ValueStack *x,
        unsigned int num)
{
  unsigned int Size; // esi
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // ebx
  unsigned int v6; // ebx
  Scaleform::GFx::AS3::Value *pCurrent; // ecx
  void *pHeap; // [esp-10h] [ebp-24h]
  unsigned int ind; // [esp+8h] [ebp-Ch] BYREF
  Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef key; // [esp+Ch] [ebp-8h] BYREF

  if ( num )
  {
    Size = this->ValueA.Data.Size;
    if ( this->Length == Size )
    {
      p_ValueA = &this->ValueA;
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->ValueA.Data,
        Size + num);
      memcpy((int)&p_ValueA->Data.Data[Size], (const __m128i *)&x->pCurrent[-(unsigned __int16)(num - 1)], 16 * num);
      x->pCurrent -= num;
      this->Length = this->ValueA.Data.Size;
    }
    else
    {
      ind = num + this->ValueHHighInd;
      v6 = num;
      key.pFirst = &ind;
      do
      {
        pHeap = this->ValueH.mHash.pHeap;
        key.pSecond = x->pCurrent;
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
          &this->ValueH.mHash,
          pHeap,
          &key);
        pCurrent = x->pCurrent;
        if ( (x->pCurrent->Flags & 0x1F) > 9 )
        {
          if ( (x->pCurrent->Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(pCurrent);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(pCurrent);
        }
        --x->pCurrent;
        --ind;
        --v6;
      }
      while ( v6 );
      this->ValueHHighInd += num;
      this->Length += num;
    }
  }
}
