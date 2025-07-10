void __thiscall Scaleform::GFx::AS3::Impl::SparseArray::Append(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v4; // ebx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int Size; // eax
  unsigned int v7; // esi
  Scaleform::GFx::AS3::Value *Data; // eax
  unsigned int *p_Flags; // eax
  const Scaleform::GFx::AS3::Value *v10; // esi
  unsigned int *p_ValueHHighInd; // ebx
  void *pHeap; // [esp-8h] [ebp-20h]
  Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef key; // [esp+10h] [ebp-8h] BYREF
  const Scaleform::MemoryHeap *argva; // [esp+20h] [ebp+8h]

  if ( this->Length == this->ValueA.Data.Size )
  {
    if ( argc )
    {
      v4 = argv;
      p_ValueA = &this->ValueA;
      do
      {
        Size = this->ValueA.Data.Size;
        v7 = Size + 1;
        argva = this->ValueA.Data.pHeap;
        if ( Size + 1 >= Size )
        {
          if ( v7 >= this->ValueA.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA,
              this->ValueA.Data.pHeap,
              v7 + (v7 >> 2));
        }
        else
        {
          Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
            &p_ValueA->Data.Data[Size + 1],
            0xFFFFFFFF);
          if ( v7 < this->ValueA.Data.Policy.Capacity >> 1 )
            Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA,
              argva,
              v7);
        }
        Data = p_ValueA->Data.Data;
        this->ValueA.Data.Size = v7;
        p_Flags = &Data[v7 - 1].Flags;
        if ( p_Flags )
        {
          *p_Flags = v4->Flags;
          p_Flags[1] = (unsigned int)v4->Bonus.pWeakProxy;
          p_Flags[2] = v4->value.VS._1.VUInt;
          p_Flags[3] = (unsigned int)v4->value.VS._2.VObj;
          if ( (v4->Flags & 0x1F) > 9 )
          {
            if ( (v4->Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::AddRefWeakRef(v4);
            else
              Scaleform::GFx::AS3::Value::AddRefInternal(v4);
          }
        }
        ++v4;
        --argc;
      }
      while ( argc );
    }
    this->Length = this->ValueA.Data.Size;
  }
  else if ( argc )
  {
    v10 = argv;
    p_ValueHHighInd = &this->ValueHHighInd;
    key.pFirst = &this->ValueHHighInd;
    do
    {
      *p_ValueHHighInd = this->Length;
      pHeap = this->ValueH.mHash.pHeap;
      key.pSecond = v10;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
        &this->ValueH.mHash,
        pHeap,
        &key);
      ++this->Length;
      ++v10;
      --argc;
    }
    while ( argc );
  }
}
