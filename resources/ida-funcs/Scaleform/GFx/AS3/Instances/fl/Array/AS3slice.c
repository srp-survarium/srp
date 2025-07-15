void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::AS3slice(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result,
        int startIndex,
        int endIndex)
{
  Scaleform::GFx::AS3::Instances::fl::Array *v4; // ebx
  Scaleform::GFx::AS3::Instances::fl::Array *v5; // ecx
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // edi
  unsigned int RefCount; // eax
  int v8; // eax
  int v9; // edx
  unsigned int v10; // ecx
  int v11; // eax
  Scaleform::GFx::AS3::Value *p_DefaultValue; // ebp
  signed int Index; // eax
  int v14; // eax
  unsigned int Length; // ecx
  unsigned int Size; // esi
  unsigned int v17; // eax
  const Scaleform::MemoryHeap *pHeap; // ebx
  Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v20; // esi
  Scaleform::Pair<double,unsigned long> *Data; // edx
  int v22; // esi
  unsigned int *v23; // eax
  void *v24; // [esp-Ch] [ebp-2Ch]
  Scaleform::GFx::AS3::InstanceTraits::fl::Array *pObject; // [esp-4h] [ebp-24h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> r; // [esp+Ch] [ebp-14h] BYREF
  Scaleform::GFx::AS3::Instances::fl::Array *v27; // [esp+10h] [ebp-10h]
  unsigned int key; // [esp+14h] [ebp-Ch] BYREF
  Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef v29; // [esp+18h] [ebp-8h] BYREF
  int i; // [esp+24h] [ebp+4h]
  int startIndexa; // [esp+28h] [ebp+8h]

  v4 = this;
  pObject = (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pTraits.pObject;
  v27 = this;
  Scaleform::GFx::AS3::InstanceTraits::MakeInstance<Scaleform::GFx::AS3::InstanceTraits::fl::Array>(&r, pObject);
  v5 = result->pObject;
  pV = r.pV;
  if ( r.pV != result->pObject )
  {
    if ( v5 )
    {
      if ( ((unsigned __int8)v5 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v5 - 1);
      }
      else
      {
        RefCount = v5->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v5->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v5);
        }
      }
    }
    result->pObject = pV;
  }
  v8 = startIndex;
  if ( startIndex < 0 )
  {
    v8 = v4->SA.Length + startIndex;
    if ( v8 < 0 )
      v8 = 0;
  }
  v9 = endIndex;
  if ( endIndex < 0 )
  {
    v9 = v4->SA.Length + endIndex;
    endIndex = v9;
  }
  if ( (signed int)v4->SA.Length < v9 )
    endIndex = v4->SA.Length;
  v10 = v8;
  i = v8;
  if ( v8 < endIndex )
  {
    v11 = 16 * v8;
    startIndexa = v11;
    do
    {
      key = v10;
      if ( v10 >= v4->SA.ValueA.Data.Size )
      {
        if ( v10 < v4->SA.ValueHLowInd
          || v10 > v4->SA.ValueHHighInd
          || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::findIndexAlt<unsigned int>(
                        &v4->SA.ValueH.mHash,
                        &key),
              Index < 0)
          || (v14 = (int)&v4->SA.ValueH.mHash.pTable[4 * Index + 2]) == 0
          || (p_DefaultValue = (Scaleform::GFx::AS3::Value *)(v14 + 8), v14 == -8) )
        {
          p_DefaultValue = (Scaleform::GFx::AS3::Value *)&v4->SA.DefaultValue;
        }
      }
      else
      {
        p_DefaultValue = (Scaleform::GFx::AS3::Value *)((char *)v4->SA.ValueA.Data.Data + v11);
      }
      Length = pV->SA.Length;
      if ( Length == pV->SA.ValueA.Data.Size )
      {
        Size = pV->SA.ValueA.Data.Size;
        v17 = Size;
        pHeap = pV->SA.ValueA.Data.pHeap;
        p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&pV->SA.ValueA;
        v20 = Size + 1;
        if ( v20 >= v17 )
        {
          if ( v20 >= p_ValueA->Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              pHeap,
              v20 + (v20 >> 2));
        }
        else
        {
          Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
            (Scaleform::GFx::AS3::Value *)&p_ValueA->Data[v20],
            v17 - v20);
          if ( v20 < p_ValueA->Policy.Capacity >> 1 )
            Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              pHeap,
              v20);
        }
        Data = p_ValueA->Data;
        p_ValueA->Size = v20;
        v22 = v20;
        v23 = (unsigned int *)&Data[v22 - 1];
        if ( &Data[v22] != (Scaleform::Pair<double,unsigned long> *)16 )
        {
          *v23 = p_DefaultValue->Flags;
          v23[1] = (unsigned int)p_DefaultValue->Bonus.pWeakProxy;
          v23[2] = p_DefaultValue->value.VS._1.VUInt;
          v23[3] = (unsigned int)p_DefaultValue->value.VS._2.VObj;
          if ( (p_DefaultValue->Flags & 0x1F) > 9 )
          {
            if ( (p_DefaultValue->Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::AddRefWeakRef(p_DefaultValue);
            else
              Scaleform::GFx::AS3::Value::AddRefInternal(p_DefaultValue);
          }
        }
        v4 = v27;
        pV = r.pV;
      }
      else
      {
        pV->SA.ValueHHighInd = Length;
        v29.pFirst = &pV->SA.ValueHHighInd;
        v24 = pV->SA.ValueH.mHash.pHeap;
        v29.pSecond = p_DefaultValue;
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
          &pV->SA.ValueH.mHash,
          v24,
          &v29);
      }
      ++pV->SA.Length;
      v10 = i + 1;
      v11 = startIndexa + 16;
      i = v10;
      startIndexa += 16;
    }
    while ( (int)v10 < endIndex );
  }
}
