void __thiscall Scaleform::GFx::AS3::Impl::SparseArray::Optimize(Scaleform::GFx::AS3::Impl::SparseArray *this)
{
  Scaleform::GFx::AS3::Impl::SparseArray *v1; // edi
  unsigned int *p_ValueHLowInd; // ebx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *pTable; // ebp
  int v4; // eax
  int v5; // ecx
  int v6; // edx
  signed int Index; // eax
  int v8; // eax
  unsigned int Size; // esi
  unsigned int v10; // eax
  const Scaleform::MemoryHeap *pHeap; // ebp
  Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v13; // esi
  Scaleform::Pair<double,unsigned long> *Data; // ecx
  int v15; // esi
  Scaleform::GFx::AS3::Value hv; // [esp+Ch] [ebp-10h] BYREF

  v1 = this;
  hv.Flags = 0;
  hv.Bonus.pWeakProxy = 0;
  p_ValueHLowInd = &this->ValueHLowInd;
  if ( this->ValueA.Data.Size == this->ValueHLowInd )
  {
    while ( *p_ValueHLowInd <= v1->ValueHHighInd )
    {
      pTable = v1->ValueH.mHash.pTable;
      if ( !pTable )
        goto LABEL_22;
      v4 = 4;
      v5 = 5381;
      do
      {
        v6 = *((unsigned __int8 *)p_ValueHLowInd + --v4);
        v5 = v6 + 65599 * v5;
      }
      while ( v4 );
      Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::findIndexCore<unsigned int>(
                &v1->ValueH.mHash,
                p_ValueHLowInd,
                v5 & pTable->SizeMask);
      if ( Index >= 0 && (v8 = (int)&pTable[4 * Index + 2]) != 0 )
      {
        Scaleform::GFx::AS3::Value::Assign(&hv, (const Scaleform::GFx::AS3::Value *)(v8 + 8));
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::RemoveAlt<unsigned int>(
          &v1->ValueH.mHash,
          p_ValueHLowInd);
        ++*p_ValueHLowInd;
        if ( (hv.Flags & 0x1F) == 0 )
        {
          Scaleform::GFx::AS3::Impl::SparseArray::AdjustValueHLowInd(v1);
          break;
        }
        Size = v1->ValueA.Data.Size;
        v10 = Size;
        pHeap = v1->ValueA.Data.pHeap;
        p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&v1->ValueA;
        v13 = Size + 1;
        if ( v13 >= v10 )
        {
          if ( v13 >= p_ValueA->Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              pHeap,
              v13 + (v13 >> 2));
        }
        else
        {
          Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
            (Scaleform::GFx::AS3::Value *)&p_ValueA->Data[v13],
            v10 - v13);
          if ( v13 < p_ValueA->Policy.Capacity >> 1 )
            Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              pHeap,
              v13);
        }
        Data = p_ValueA->Data;
        p_ValueA->Size = v13;
        v15 = v13;
        if ( &Data[v15] != (Scaleform::Pair<double,unsigned long> *)16 )
        {
          Data[v15 - 1] = (Scaleform::Pair<double,unsigned long>)hv;
          if ( (hv.Flags & 0x1F) > 9 )
          {
            if ( (hv.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::AddRefWeakRef(&hv);
            else
              Scaleform::GFx::AS3::Value::AddRefInternal(&hv);
          }
        }
        v1 = this;
      }
      else
      {
LABEL_22:
        ++*p_ValueHLowInd;
        Scaleform::GFx::AS3::Impl::SparseArray::AdjustValueHLowInd(v1);
      }
      if ( v1->ValueA.Data.Size != *p_ValueHLowInd )
        break;
    }
  }
  if ( *p_ValueHLowInd > v1->ValueHHighInd )
  {
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>(&v1->ValueH.mHash);
    *p_ValueHLowInd = 0;
    v1->ValueHHighInd = 0;
  }
  if ( (hv.Flags & 0x1F) > 9 )
  {
    if ( (hv.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&hv);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&hv);
  }
}
