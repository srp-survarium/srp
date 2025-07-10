// local variable allocation has failed, the output may be wrong!
void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::AS3sort(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v5; // eax
  Scaleform::GFx::AS3::Traits *pObject; // eax
  unsigned int v7; // edx
  double *v8; // edi
  int v9; // edi
  unsigned int Size; // esi
  unsigned int Length; // eax
  int v12; // edi
  unsigned int v13; // ebx
  const Scaleform::GFx::AS3::Value *First; // ecx
  unsigned int v15; // eax
  unsigned int v16; // esi
  unsigned int v17; // ebp
  int v18; // edi
  int v19; // edi
  unsigned int v20; // ebx
  unsigned int v21; // eax
  int v22; // edi
  unsigned int v23; // ebx
  const Scaleform::GFx::AS3::Value *v24; // ecx
  char *v25; // edi
  unsigned int v26; // ebx
  Scaleform::GFx::ASStringNode *v27; // ecx
  unsigned int v29; // ebp
  int v30; // edi
  unsigned int v31; // edi
  unsigned int v32; // eax
  const Scaleform::GFx::AS3::Value *v33; // ecx
  unsigned int v34; // edi
  Scaleform::GFx::AS3::Impl::SparseArray *v35; // esi
  Scaleform::HashDH<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>,2,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> > *p_ValueH; // edi
  Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // esi
  unsigned int v38; // edi
  Scaleform::Pair<double,unsigned long> *Data; // ebx
  unsigned int v40; // ebp
  Scaleform::Pair<double,unsigned long> *v41; // eax
  unsigned int i; // ebp
  unsigned int v43; // ebx
  int v44; // edi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> > *v45; // esi
  unsigned int ValueHLowInd; // eax
  unsigned int ValueHHighInd; // ecx
  void *pHeap; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> > *v49; // edi
  unsigned int v50; // eax
  Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *v51; // esi
  unsigned int v52; // edi
  Scaleform::Pair<double,unsigned long> *v53; // ebx
  unsigned int v54; // ebp
  Scaleform::Pair<double,unsigned long> *v55; // eax
  unsigned int j; // ebp
  unsigned int v57; // ebx
  int v58; // edi
  Scaleform::GFx::AS3::Impl::CompareAsString v59; // [esp-4h] [ebp-A4h]
  int flags; // [esp+10h] [ebp-90h] BYREF
  Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2,Scaleform::ArrayDefaultPolicy> pairs; // [esp+14h] [ebp-8Ch] BYREF
  Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef key; // [esp+24h] [ebp-7Ch] BYREF
  unsigned int functor; // [esp+2Ch] [ebp-74h] OVERLAPPED BYREF
  Scaleform::GFx::AS3::Impl::SparseArray *p_SA; // [esp+30h] [ebp-70h]
  Scaleform::GFx::AS3::CheckResult v65[4]; // [esp+34h] [ebp-6Ch] BYREF
  Scaleform::GFx::AS3::Impl::SparseArray newSA; // [esp+38h] [ebp-68h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> newArr; // [esp+70h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value compareFunction; // [esp+74h] [ebp-2Ch] BYREF
  Scaleform::GFx::AS3::Value val; // [esp+84h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::Impl::ValuePtrCollector vc; // [esp+94h] [ebp-Ch] BYREF
  Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *p_pairs; // [esp+9Ch] [ebp-4h]

  newArr.pV = this;
  compareFunction.Flags = 0;
  compareFunction.Bonus.pWeakProxy = 0;
  flags = 0;
  if ( argc )
  {
    v5 = argv->Flags & 0x1F;
    if ( v5 > 0xF || v5 == 14 || v5 == 5 || v5 == 15 || v5 == 6 || v5 == 7 || v5 == 12 || v5 == 13 )
    {
      Scaleform::GFx::AS3::Value::Assign(&compareFunction, argv);
    }
    else if ( !Scaleform::GFx::AS3::Value::Convert2Int32(argv, &v65[3], &flags)->Result )
    {
      goto LABEL_151;
    }
  }
  if ( argc <= 1 || Scaleform::GFx::AS3::Value::Convert2Int32(argv + 1, &v65[3], &flags)->Result )
  {
    pObject = this->pTraits.pObject;
    newSA.ValueA.Data.pHeap = pObject->pVM->MHeap;
    newSA.ValueH.mHash.pHeap = (void *)newSA.ValueA.Data.pHeap;
    memset(&newSA, 0, 12);
    newSA.DefaultValue.Flags = 0;
    newSA.DefaultValue.Bonus.pWeakProxy = 0;
    memset(&newSA.ValueA, 0, 12);
    newSA.ValueH.mHash.pTable = 0;
    if ( (compareFunction.Flags & 0x1F) == 0
      || (compareFunction.Flags & 0x1F) - 12 <= 3 && !compareFunction.value.VS._1.VInt )
    {
      if ( (flags & 0x10) != 0 )
      {
        pairs.Data.pHeap = pObject->pVM->MHeap;
        memset(&pairs, 0, 12);
        vc.__vftable = (Scaleform::GFx::AS3::Impl::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::Impl::Value2NumberCollector::`vftable';
        vc.Pairs = &pairs;
        p_SA = &this->SA;
        Scaleform::GFx::AS3::Impl::SparseArray::ForEach(&this->SA, &vc);
        LOBYTE(functor) = (flags & 2) != 0;
        Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::GFx::AS3::Impl::Triple<double,Scaleform::GFx::AS3::Value const *,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareAsNumber>(
          (Scaleform::ArrayDH<Scaleform::GFx::AS3::Impl::Triple<double,Scaleform::GFx::AS3::Value const *,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *)&pairs,
          0,
          pairs.Data.Size,
          (Scaleform::GFx::AS3::Impl::CompareAsNumber)functor);
        functor = pairs.Data.Size;
        if ( (flags & 4) != 0 )
        {
          v7 = 1;
          if ( pairs.Data.Size > 1 )
          {
            v8 = (double *)&pairs.Data.Data[3];
            while ( *v8 != *(v8 - 3) )
            {
              ++v7;
              v8 += 3;
              if ( v7 >= pairs.Data.Size )
                goto LABEL_23;
            }
LABEL_28:
            Scaleform::GFx::AS3::Value::SetNull(result);
            vc.__vftable = (Scaleform::GFx::AS3::Impl::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pairs.Data.Data);
            goto LABEL_29;
          }
        }
LABEL_23:
        if ( (flags & 8) != 0 )
        {
          if ( pairs.Data.Size )
          {
            v9 = 0;
            Size = pairs.Data.Size;
            do
            {
              val.value.VS._1.VInt = (int)pairs.Data.Data[v9 + 2].First;
              val.Flags = 3;
              val.Bonus.pWeakProxy = 0;
              if ( newSA.Length == newSA.ValueA.Data.Size )
              {
                Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
                  &newSA.ValueA.Data,
                  &val);
              }
              else
              {
                newSA.ValueHHighInd = newSA.Length;
                key.pFirst = &newSA.ValueHHighInd;
                key.pSecond = &val;
                Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
                  &newSA.ValueH.mHash,
                  newSA.ValueH.mHash.pHeap,
                  &key);
              }
              ++newSA.Length;
              if ( (val.Flags & 0x1F) > 9 )
              {
                if ( (val.Flags & 0x200) != 0 )
                  Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
                else
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
              }
              v9 += 3;
              --Size;
            }
            while ( Size );
          }
        }
        else if ( pairs.Data.Size )
        {
          Length = newSA.Length;
          v12 = 0;
          v13 = pairs.Data.Size;
          do
          {
            First = pairs.Data.Data[v12 + 1].First;
            if ( Length == newSA.ValueA.Data.Size )
            {
              Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
                &newSA.ValueA.Data,
                (Scaleform::GFx::AS3::Value *)pairs.Data.Data[v12 + 1].First);
            }
            else
            {
              newSA.ValueHHighInd = Length;
              key.pSecond = First;
              key.pFirst = &newSA.ValueHHighInd;
              Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
                &newSA.ValueH.mHash,
                newSA.ValueH.mHash.pHeap,
                &key);
            }
            Length = newSA.Length + 1;
            v12 += 3;
            --v13;
            ++newSA.Length;
          }
          while ( v13 );
        }
        if ( functor < p_SA->Length )
          Scaleform::GFx::AS3::Impl::SparseArray::Resize(&newSA, p_SA->Length);
        vc.__vftable = (Scaleform::GFx::AS3::Impl::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        goto LABEL_81;
      }
      pairs.Data.pHeap = pObject->pVM->MHeap;
      memset(&pairs, 0, 12);
      vc.Pairs = (Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *)pObject->pVM;
      vc.__vftable = (Scaleform::GFx::AS3::Impl::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::Impl::Value2StrCollector::`vftable';
      p_pairs = &pairs;
      p_SA = &this->SA;
      Scaleform::GFx::AS3::Impl::SparseArray::ForEach(&this->SA, &vc);
      LOBYTE(functor) = (flags & 2) != 0;
      BYTE1(functor) = flags & 1;
      *(_WORD *)&v59.Desc = functor;
      v59.UseLocale = (flags & 0x400) != 0;
      BYTE2(functor) = v59.UseLocale;
      Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareAsString>(
        (Scaleform::ArrayDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *)&pairs,
        0,
        pairs.Data.Size,
        v59);
      v15 = pairs.Data.Size;
      v16 = pairs.Data.Size;
      if ( (flags & 4) != 0 )
      {
        v17 = 1;
        if ( pairs.Data.Size > 1 )
        {
          v18 = 12;
          while ( Scaleform::GFx::AS3::Impl::CompareAsString::Compare(
                    (Scaleform::GFx::AS3::Impl::CompareAsStringInd *)&functor,
                    (const Scaleform::GFx::ASString *)((char *)&pairs.Data.Data[-1] + v18 - 4),
                    (const Scaleform::GFx::ASString *)((char *)pairs.Data.Data + v18)) )
          {
            ++v17;
            v18 += 12;
            if ( v17 >= v16 )
            {
              v15 = pairs.Data.Size;
              goto LABEL_54;
            }
          }
          Scaleform::GFx::AS3::Value::SetNull(result);
          vc.__vftable = (Scaleform::GFx::AS3::Impl::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&pairs);
LABEL_29:
          Scaleform::GFx::AS3::Impl::SparseArray::~SparseArray(&newSA);
          if ( (compareFunction.Flags & 0x1F) <= 9 )
            return;
          if ( (compareFunction.Flags & 0x200) != 0 )
            goto LABEL_31;
          goto LABEL_153;
        }
      }
LABEL_54:
      if ( (flags & 8) != 0 )
      {
        if ( v16 )
        {
          v19 = 0;
          v20 = v16;
          do
          {
            val.value.VS._1.VInt = *(int *)((char *)&pairs.Data.Data[1].First + v19);
            val.Flags = 3;
            val.Bonus.pWeakProxy = 0;
            if ( newSA.Length == newSA.ValueA.Data.Size )
            {
              Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
                &newSA.ValueA.Data,
                &val);
            }
            else
            {
              newSA.ValueHHighInd = newSA.Length;
              key.pFirst = &newSA.ValueHHighInd;
              key.pSecond = &val;
              Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
                &newSA.ValueH.mHash,
                newSA.ValueH.mHash.pHeap,
                &key);
            }
            ++newSA.Length;
            if ( (val.Flags & 0x1F) > 9 )
            {
              if ( (val.Flags & 0x200) != 0 )
                Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
              else
                Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
            }
            v19 += 12;
            --v20;
          }
          while ( v20 );
          goto LABEL_73;
        }
      }
      else if ( v16 )
      {
        v21 = newSA.Length;
        v22 = 0;
        v23 = v16;
        do
        {
          v24 = *(const Scaleform::GFx::AS3::Value **)((char *)&pairs.Data.Data->Second + v22);
          if ( v21 == newSA.ValueA.Data.Size )
          {
            Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
              &newSA.ValueA.Data,
              *(Scaleform::GFx::AS3::Value **)((char *)&pairs.Data.Data->Second + v22));
          }
          else
          {
            newSA.ValueHHighInd = v21;
            key.pSecond = v24;
            key.pFirst = &newSA.ValueHHighInd;
            Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
              &newSA.ValueH.mHash,
              newSA.ValueH.mHash.pHeap,
              &key);
          }
          v21 = newSA.Length + 1;
          v22 += 12;
          --v23;
          ++newSA.Length;
        }
        while ( v23 );
LABEL_73:
        v15 = pairs.Data.Size;
      }
      if ( v16 < p_SA->Length )
      {
        Scaleform::GFx::AS3::Impl::SparseArray::Resize(&newSA, p_SA->Length);
        v15 = pairs.Data.Size;
      }
      vc.__vftable = (Scaleform::GFx::AS3::Impl::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
      v25 = (char *)&pairs.Data.Data[-1] + 12 * v15 - 4;
      if ( v15 )
      {
        v26 = v15;
        do
        {
          v27 = *(Scaleform::GFx::ASStringNode **)v25;
          if ( (*(_DWORD *)(*(_DWORD *)v25 + 12))-- == 1 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v27);
          v25 -= 12;
          --v26;
        }
        while ( v26 );
      }
LABEL_81:
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pairs.Data.Data);
LABEL_116:
      if ( (flags & 8) != 0 )
      {
        Scaleform::GFx::AS3::VM::MakeArray(newArr.pV->pTraits.pObject->pVM, &newArr);
        Scaleform::GFx::AS3::Value::Pick(result, newArr.pV);
        v35 = &newArr.pV->SA;
        if ( &newArr.pV->SA != &newSA )
        {
          v35->Length = newSA.Length;
          v35->ValueHLowInd = newSA.ValueHLowInd;
          v35->ValueHHighInd = newSA.ValueHHighInd;
          p_ValueH = &v35->ValueH;
          Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Assign(
            &v35->ValueH.mHash,
            newSA.ValueH.mHash.pHeap,
            &newSA.ValueH.mHash);
          p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&v35->ValueA;
          p_ValueH->mHash.pHeap = newSA.ValueH.mHash.pHeap;
          v38 = p_ValueA->Size;
          Data = p_ValueA[1].Data;
          v40 = newSA.ValueA.Data.Size;
          if ( newSA.ValueA.Data.Size >= v38 )
          {
            if ( newSA.ValueA.Data.Size >= p_ValueA->Policy.Capacity )
              Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                p_ValueA,
                Data,
                newSA.ValueA.Data.Size + (newSA.ValueA.Data.Size >> 2));
          }
          else
          {
            Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
              (Scaleform::GFx::AS3::Value *)&p_ValueA->Data[newSA.ValueA.Data.Size],
              v38 - newSA.ValueA.Data.Size);
            if ( v40 < p_ValueA->Policy.Capacity >> 1 )
              Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                p_ValueA,
                Data,
                v40);
          }
          p_ValueA->Size = v40;
          if ( v40 > v38 )
          {
            v41 = &p_ValueA->Data[v38];
            for ( i = v40 - v38; i; --i )
            {
              if ( v41 )
              {
                LODWORD(v41->First) = 0;
                HIDWORD(v41->First) = 0;
              }
              ++v41;
            }
          }
          v43 = 0;
          if ( p_ValueA->Size )
          {
            v44 = 0;
            do
            {
              Scaleform::GFx::AS3::Value::Assign(
                (Scaleform::GFx::AS3::Value *)&p_ValueA->Data[v44],
                &newSA.ValueA.Data.Data[v44]);
              ++v43;
              ++v44;
            }
            while ( v43 < p_ValueA->Size );
          }
        }
      }
      else
      {
        if ( p_SA != &newSA )
        {
          v45 = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> > *)p_SA;
          ValueHLowInd = newSA.ValueHLowInd;
          ValueHHighInd = newSA.ValueHHighInd;
          p_SA->Length = newSA.Length;
          v45[1].pTable = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *)ValueHLowInd;
          pHeap = newSA.ValueH.mHash.pHeap;
          v45[2].pTable = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *)ValueHHighInd;
          v49 = v45 + 12;
          Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Assign(
            v45 + 12,
            pHeap,
            &newSA.ValueH.mHash);
          v50 = newSA.ValueA.Data.Size;
          v51 = (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&v45[8];
          v49[1].pTable = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *)newSA.ValueH.mHash.pHeap;
          v52 = v51->Size;
          v53 = v51[1].Data;
          v54 = v50;
          if ( v50 >= v52 )
          {
            if ( v50 >= v51->Policy.Capacity )
              Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                v51,
                v53,
                v50 + (v50 >> 2));
          }
          else
          {
            Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
              (Scaleform::GFx::AS3::Value *)&v51->Data[v50],
              v52 - v50);
            if ( v54 < v51->Policy.Capacity >> 1 )
              Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                v51,
                v53,
                v54);
          }
          v51->Size = v54;
          if ( v54 > v52 )
          {
            v55 = &v51->Data[v52];
            for ( j = v54 - v52; j; --j )
            {
              if ( v55 )
              {
                LODWORD(v55->First) = 0;
                HIDWORD(v55->First) = 0;
              }
              ++v55;
            }
          }
          v57 = 0;
          if ( v51->Size )
          {
            v58 = 0;
            do
            {
              Scaleform::GFx::AS3::Value::Assign(
                (Scaleform::GFx::AS3::Value *)&v51->Data[v58],
                &newSA.ValueA.Data.Data[v58]);
              ++v57;
              ++v58;
            }
            while ( v57 < v51->Size );
          }
        }
        Scaleform::GFx::AS3::Value::Assign(result, newArr.pV);
      }
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>(&newSA.ValueH.mHash);
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
        newSA.ValueA.Data.Data,
        newSA.ValueA.Data.Size);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, newSA.ValueA.Data.Data);
      if ( (newSA.DefaultValue.Flags & 0x1F) > 9 )
      {
        if ( (newSA.DefaultValue.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&newSA.DefaultValue);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&newSA.DefaultValue);
      }
      goto LABEL_151;
    }
    pairs.Data.pHeap = pObject->pVM->MHeap;
    memset(&pairs, 0, 12);
    vc.__vftable = (Scaleform::GFx::AS3::Impl::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::Impl::ValuePtrCollector::`vftable';
    vc.Pairs = &pairs;
    p_SA = &this->SA;
    Scaleform::GFx::AS3::Impl::SparseArray::ForEach(&this->SA, &vc);
    key.pFirst = (const unsigned int *)this->pTraits.pObject->pVM;
    key.pSecond = &compareFunction;
    Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareValuePtr>(
      &pairs,
      0,
      pairs.Data.Size,
      (Scaleform::GFx::AS3::Impl::CompareValuePtr)__PAIR64__(&compareFunction, (unsigned int)key.pFirst));
    v29 = pairs.Data.Size;
    if ( (flags & 4) != 0 )
    {
      v30 = 1;
      if ( pairs.Data.Size > 1 )
      {
        while ( Scaleform::GFx::AS3::Impl::CompareValuePtr::Compare(
                  (Scaleform::GFx::AS3::Impl::CompareValuePtr *)&key,
                  (Scaleform::GFx::AS3::Value *)pairs.Data.Data[v30 - 1].First,
                  (Scaleform::GFx::AS3::Value *)pairs.Data.Data[v30].First) )
        {
          if ( ++v30 >= v29 )
            goto LABEL_86;
        }
        goto LABEL_28;
      }
    }
LABEL_86:
    v31 = 0;
    if ( (flags & 8) != 0 )
    {
      if ( v29 )
      {
        do
        {
          val.value.VS._1.VInt = pairs.Data.Data[v31].Second;
          val.Flags = 3;
          val.Bonus.pWeakProxy = 0;
          if ( newSA.Length == newSA.ValueA.Data.Size )
          {
            Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
              &newSA.ValueA.Data,
              &val);
          }
          else
          {
            newSA.ValueHHighInd = newSA.Length;
            key.pFirst = &newSA.ValueHHighInd;
            key.pSecond = &val;
            Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
              &newSA.ValueH.mHash,
              newSA.ValueH.mHash.pHeap,
              &key);
          }
          ++newSA.Length;
          if ( (val.Flags & 0x1F) > 9 )
          {
            if ( (val.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
          }
          ++v31;
        }
        while ( v31 < v29 );
      }
    }
    else if ( v29 )
    {
      v32 = newSA.Length;
      do
      {
        v33 = pairs.Data.Data[v31].First;
        if ( v32 == newSA.ValueA.Data.Size )
        {
          Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
            &newSA.ValueA.Data,
            (Scaleform::GFx::AS3::Value *)pairs.Data.Data[v31].First);
        }
        else
        {
          newSA.ValueHHighInd = v32;
          key.pSecond = v33;
          key.pFirst = &newSA.ValueHHighInd;
          Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
            &newSA.ValueH.mHash,
            newSA.ValueH.mHash.pHeap,
            &key);
        }
        v32 = newSA.Length + 1;
        ++v31;
        ++newSA.Length;
      }
      while ( v31 < v29 );
    }
    v34 = p_SA->Length;
    if ( v29 >= p_SA->Length )
    {
LABEL_115:
      vc.__vftable = (Scaleform::GFx::AS3::Impl::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pairs.Data.Data);
      goto LABEL_116;
    }
    if ( v34 )
    {
      if ( v34 <= newSA.ValueA.Data.Size && newSA.ValueA.Data.Size )
      {
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
          &newSA.ValueA.Data,
          p_SA->Length);
      }
      else if ( v34 >= newSA.ValueHLowInd )
      {
        if ( v34 < newSA.ValueHHighInd )
          Scaleform::GFx::AS3::Impl::SparseArray::CutHash(&newSA, v34, newSA.ValueHHighInd - v34 + 1, 0);
        goto LABEL_114;
      }
    }
    else
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &newSA.ValueA.Data,
        newSA.ValueA.Data.pHeap,
        0);
    }
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>(&newSA.ValueH.mHash);
    newSA.ValueHLowInd = 0;
    newSA.ValueHHighInd = 0;
LABEL_114:
    newSA.Length = v34;
    goto LABEL_115;
  }
LABEL_151:
  if ( (compareFunction.Flags & 0x1F) <= 9 )
    return;
  if ( (compareFunction.Flags & 0x200) != 0 )
  {
LABEL_31:
    Scaleform::GFx::AS3::Value::ReleaseWeakRef(&compareFunction);
    return;
  }
LABEL_153:
  Scaleform::GFx::AS3::Value::ReleaseInternal(&compareFunction);
}
