void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Sort<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object>(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *currObj)
{
  Scaleform::GFx::AS3::Value *v5; // esi
  unsigned int v6; // edi
  unsigned int v8; // eax
  Scaleform::GFx::AS3::VM *v9; // eax
  unsigned int v10; // ebp
  unsigned int v11; // ecx
  Scaleform::Pair<double,unsigned long> *v12; // edx
  Scaleform::GFx::AS3::Value *v13; // edi
  unsigned int v14; // esi
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v16; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  __int16 v18; // ax
  bool v19; // cc
  unsigned int v20; // esi
  Scaleform::GFx::AS3::Value *v21; // eax
  int v22; // esi
  unsigned int Size; // edi
  unsigned int j; // ebx
  Scaleform::GFx::AS3::Value *v25; // edi
  unsigned int v26; // esi
  unsigned int v27; // esi
  Scaleform::GFx::AS3::Value *v28; // eax
  const Scaleform::GFx::AS3::Value **k; // esi
  Scaleform::GFx::ASStringNode *v30; // ecx
  const Scaleform::MemoryHeap *MHeap; // eax
  Scaleform::GFx::AS3::VM *v33; // edi
  int v34; // esi
  unsigned int i; // edi
  Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *v36; // ecx
  unsigned int v37; // esi
  unsigned int v38; // esi
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // edi
  Scaleform::GFx::AS3::Instances::fl::Catch *v40; // eax
  Scaleform::GFx::AS3::Instances::fl::Catch *v41; // esi
  Scaleform::GFx::AS3::VM *pVM; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v43; // ecx
  unsigned int v44; // edi
  const Scaleform::MemoryHeap *pHeap; // ebx
  Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // esi
  Scaleform::Pair<double,unsigned long> *v47; // eax
  unsigned int v48; // ecx
  unsigned int v49; // ebx
  int v50; // edi
  Scaleform::GFx::AS3::Value *Data; // esi
  Scaleform::GFx::AS3::Impl::CompareAsStringInd v52; // [esp-4h] [ebp-68h]
  int flags; // [esp+10h] [ebp-54h] BYREF
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *v54; // [esp+14h] [ebp-50h]
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ValuePtrCollector vc; // [esp+18h] [ebp-4Ch] BYREF
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value const *,2,Scaleform::ArrayDefaultPolicy> *p_ptrs; // [esp+20h] [ebp-44h]
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> newSA; // [esp+24h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value compareFunction; // [esp+34h] [ebp-30h] BYREF
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value const *,2,Scaleform::ArrayDefaultPolicy> ptrs; // [esp+44h] [ebp-20h] BYREF
  Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy> pairs; // [esp+54h] [ebp-10h] BYREF

  v5 = argv;
  v6 = argc;
  v54 = this;
  compareFunction.Flags = 0;
  compareFunction.Bonus.pWeakProxy = 0;
  flags = 0;
  if ( argc )
  {
    v8 = argv->Flags & 0x1F;
    if ( v8 > 0xF || v8 == 14 || v8 == 5 || v8 == 15 || v8 == 6 || v8 == 7 || v8 == 12 || v8 == 13 )
    {
      Scaleform::GFx::AS3::Value::Assign(&compareFunction, argv);
    }
    else if ( !Scaleform::GFx::AS3::Value::Convert2Int32(
                 argv,
                 (Scaleform::GFx::AS3::CheckResult *)&argc,
                 (Scaleform::GFx::AS3::Value::V1U *)&flags)->Result )
    {
LABEL_28:
      VMRef = this->VMRef;
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&vc, eCheckTypeFailedError, VMRef);
      Scaleform::GFx::AS3::VM::ThrowTypeError(VMRef, v16);
      v17 = (Scaleform::GFx::ASStringNode *)vc.Ptrs;
      --vc.Ptrs->Data.pHeap;
      if ( !v17->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      v18 = compareFunction.Flags;
      v19 = (compareFunction.Flags & 0x1F) <= 9;
LABEL_31:
      if ( v19 )
        return;
      if ( (v18 & 0x200) != 0 )
        goto LABEL_33;
      goto LABEL_116;
    }
  }
  if ( v6 > 1
    && !Scaleform::GFx::AS3::Value::Convert2Int32(
          v5 + 1,
          (Scaleform::GFx::AS3::CheckResult *)&argc,
          (Scaleform::GFx::AS3::Value::V1U *)&flags)->Result )
  {
    goto LABEL_28;
  }
  v9 = this->VMRef;
  v10 = 0;
  newSA.Data.pHeap = v9->MHeap;
  memset(&newSA, 0, 12);
  if ( (compareFunction.Flags & 0x1F) != 0
    && ((compareFunction.Flags & 0x1F) - 12 > 3 || compareFunction.value.VS._1.VInt) )
  {
    MHeap = v9->MHeap;
    vc.Ptrs = &ptrs;
    memset(&ptrs, 0, 12);
    ptrs.Data.pHeap = MHeap;
    vc.__vftable = (Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector::`vftable';
    Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ForEach(this, &vc);
    v33 = this->VMRef;
    Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::GFx::AS3::Value const *,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::CompareValuePtr>(
      &ptrs,
      0,
      ptrs.Data.Size,
      (Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::CompareValuePtr)__PAIR64__(
                                                                                      &compareFunction,
                                                                                      (unsigned int)v33));
    if ( (flags & 4) != 0 )
    {
      v34 = 1;
      if ( ptrs.Data.Size > 1 )
      {
        while ( Scaleform::GFx::AS3::Impl::CompareFunct(
                  v33,
                  &compareFunction,
                  (Scaleform::GFx::AS3::Value *)ptrs.Data.Data[v34 - 1],
                  (Scaleform::GFx::AS3::Value *)ptrs.Data.Data[v34]) )
        {
          if ( ++v34 >= ptrs.Data.Size )
            goto LABEL_71;
        }
        Scaleform::GFx::AS3::Value::SetNull(result);
        vc.__vftable = (Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(0, 0);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, 0);
        goto LABEL_114;
      }
    }
LABEL_71:
    for ( i = 0; i < ptrs.Data.Size; ++i )
    {
      v36 = (Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *)ptrs.Data.Data[i];
      pairs = *v36;
      if ( ((int)v36->Data.Data & 0x1F) > 9u )
      {
        if ( ((int)v36->Data.Data & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::AddRefWeakRef((Scaleform::GFx::AS3::Value *)v36);
        else
          Scaleform::GFx::AS3::Value::AddRefInternal((Scaleform::GFx::AS3::Value *)v36);
      }
      v37 = v10 + 1;
      if ( v10 + 1 >= v10 )
      {
        if ( v37 >= newSA.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
            newSA.Data.pHeap,
            v37 + (v37 >> 2));
      }
      else
      {
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(&newSA.Data.Data[v37], 0xFFFFFFFF);
        if ( v37 < newSA.Data.Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
            newSA.Data.pHeap,
            v37);
      }
      ++v10;
      v38 = v37;
      newSA.Data.Size = v10;
      if ( &newSA.Data.Data[v38] != (Scaleform::GFx::AS3::Value *)16 )
      {
        newSA.Data.Data[v38 - 1] = (Scaleform::GFx::AS3::Value)pairs;
        if ( ((int)pairs.Data.Data & 0x1F) > 9u )
        {
          if ( ((int)pairs.Data.Data & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::AddRefWeakRef((Scaleform::GFx::AS3::Value *)&pairs);
          else
            Scaleform::GFx::AS3::Value::AddRefInternal((Scaleform::GFx::AS3::Value *)&pairs);
        }
      }
      if ( ((int)pairs.Data.Data & 0x1F) > 9u )
      {
        if ( ((int)pairs.Data.Data & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&pairs);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&pairs);
      }
    }
    vc.__vftable = (Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  }
  else
  {
    if ( (flags & 0x10) != 0 )
    {
      pairs.Data.pHeap = v9->MHeap;
      memset(&pairs, 0, 12);
      vc.__vftable = (Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Value2NumberCollector::`vftable';
      vc.Ptrs = (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value const *,2,Scaleform::ArrayDefaultPolicy> *)&pairs;
      Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ForEach(this, &vc);
      LOBYTE(argc) = (flags & 2) != 0;
      Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareAsNumberInd>(
        &pairs,
        0,
        pairs.Data.Size,
        (Scaleform::GFx::AS3::Impl::CompareAsNumberInd)argc);
      if ( (flags & 4) != 0 )
      {
        v11 = 1;
        if ( pairs.Data.Size > 1 )
        {
          v12 = pairs.Data.Data + 1;
          while ( v12->First != v12[-1].First )
          {
            ++v11;
            ++v12;
            if ( v11 >= pairs.Data.Size )
              goto LABEL_22;
          }
          Scaleform::GFx::AS3::Value::SetSInt32(result, 0);
          vc.__vftable = (Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pairs.Data.Data);
LABEL_35:
          Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(0, 0);
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, 0);
          v18 = compareFunction.Flags;
          v19 = (compareFunction.Flags & 0x1F) <= 9;
          goto LABEL_31;
        }
      }
LABEL_22:
      argv = 0;
      if ( pairs.Data.Size )
      {
        argc = 0;
        do
        {
          v13 = &this->ValueA.Data.Data[*(unsigned int *)((char *)&pairs.Data.Data->Second + argc)];
          v14 = v10 + 1;
          if ( v10 + 1 >= v10 )
          {
            if ( v14 >= newSA.Data.Policy.Capacity )
              Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
                newSA.Data.pHeap,
                v14 + (v14 >> 2));
          }
          else
          {
            Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(&newSA.Data.Data[v14], 0xFFFFFFFF);
            if ( v14 < newSA.Data.Policy.Capacity >> 1 )
              Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
                newSA.Data.pHeap,
                v14);
          }
          ++v10;
          v20 = v14;
          v21 = &newSA.Data.Data[v20 - 1];
          newSA.Data.Size = v10;
          if ( &newSA.Data.Data[v20] != (Scaleform::GFx::AS3::Value *)16 )
          {
            v21->Flags = v13->Flags;
            v21->Bonus.pWeakProxy = v13->Bonus.pWeakProxy;
            v21->value.VS._1.VInt = v13->value.VS._1.VInt;
            v21->value.VS._2.VObj = v13->value.VS._2.VObj;
            if ( (v13->Flags & 0x1F) > 9 )
            {
              if ( (v13->Flags & 0x200) != 0 )
                Scaleform::GFx::AS3::Value::AddRefWeakRef(v13);
              else
                Scaleform::GFx::AS3::Value::AddRefInternal(v13);
            }
          }
          argc += 16;
          argv = (Scaleform::GFx::AS3::Value *)((char *)argv + 1);
        }
        while ( (unsigned int)argv < pairs.Data.Size );
      }
      vc.__vftable = (Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pairs.Data.Data);
      goto LABEL_94;
    }
    ptrs.Data.pHeap = v9->MHeap;
    vc.Ptrs = (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value const *,2,Scaleform::ArrayDefaultPolicy> *)v9;
    memset(&ptrs, 0, 12);
    vc.__vftable = (Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Value2StrCollector::`vftable';
    p_ptrs = &ptrs;
    Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ForEach(this, &vc);
    BYTE1(argc) = flags & 1;
    LOBYTE(argc) = (flags & 2) != 0;
    *(_WORD *)&v52.Desc = argc;
    v52.UseLocale = (flags & 0x400) != 0;
    BYTE2(argc) = v52.UseLocale;
    Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareAsStringInd>(
      (Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *)&ptrs,
      0,
      ptrs.Data.Size,
      v52);
    if ( (flags & 4) != 0 )
    {
      v22 = 1;
      if ( ptrs.Data.Size > 1 )
      {
        while ( Scaleform::GFx::AS3::Impl::CompareAsString::Compare(
                  (Scaleform::GFx::AS3::Impl::CompareAsStringInd *)&argc,
                  (const Scaleform::GFx::ASString *)&ptrs.Data.Data[2 * v22 - 2],
                  (const Scaleform::GFx::ASString *)&ptrs.Data.Data[2 * v22]) )
        {
          if ( ++v22 >= ptrs.Data.Size )
            goto LABEL_49;
        }
        Scaleform::GFx::AS3::Value::SetNull(result);
        vc.__vftable = (Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&ptrs);
        goto LABEL_35;
      }
    }
LABEL_49:
    Size = ptrs.Data.Size;
    for ( j = 0; j < ptrs.Data.Size; ++j )
    {
      v25 = &v54->ValueA.Data.Data[(int)ptrs.Data.Data[2 * j + 1]];
      v26 = v10 + 1;
      if ( v10 + 1 >= v10 )
      {
        if ( v26 >= newSA.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
            newSA.Data.pHeap,
            v26 + (v26 >> 2));
      }
      else
      {
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(&newSA.Data.Data[v26], 0xFFFFFFFF);
        if ( v26 < newSA.Data.Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
            newSA.Data.pHeap,
            v26);
      }
      ++v10;
      v27 = v26;
      v28 = &newSA.Data.Data[v27 - 1];
      newSA.Data.Size = v10;
      if ( &newSA.Data.Data[v27] != (Scaleform::GFx::AS3::Value *)16 )
      {
        v28->Flags = v25->Flags;
        v28->Bonus.pWeakProxy = v25->Bonus.pWeakProxy;
        v28->value.VS._1.VInt = v25->value.VS._1.VInt;
        v28->value.VS._2.VObj = v25->value.VS._2.VObj;
        if ( (v25->Flags & 0x1F) > 9 )
        {
          if ( (v25->Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::AddRefWeakRef(v25);
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(v25);
        }
      }
      Size = ptrs.Data.Size;
    }
    vc.__vftable = (Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
    for ( k = &ptrs.Data.Data[2 * Size - 2]; Size; --Size )
    {
      v30 = (Scaleform::GFx::ASStringNode *)*k;
      if ( (*k)->value.VS._2.VObj-- == (Scaleform::GFx::AS3::Object *)1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v30);
      k -= 2;
    }
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
LABEL_94:
  if ( (flags & 8) != 0 )
  {
    pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)currObj->pTraits.pObject;
    v40 = (Scaleform::GFx::AS3::Instances::fl::Catch *)Scaleform::GFx::AS3::Traits::Alloc(pObject);
    v41 = v40;
    if ( v40 )
    {
      Scaleform::GFx::AS3::Instances::fl::Object::Object(v40, pObject);
      v41->__vftable = (Scaleform::GFx::AS3::Instances::fl::Catch_vtbl *)&Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::`vftable';
      pVM = pObject->pVM;
      v43 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *)pVM->MHeap;
      LOBYTE(v41[1]._pRCC) = 0;
      v41[1].pNext = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)pVM;
      v41[1].__vftable = (Scaleform::GFx::AS3::Instances::fl::Catch_vtbl *)&Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::`vftable';
      v41[1].pPrev = 0;
      v41[1].RefCount = 0;
      v41[1].pTraits.pObject = 0;
      v41[1].DynAttrs.mHash.pTable = v43;
    }
    else
    {
      v41 = 0;
    }
    Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Append(
      (Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *)&v41[1],
      &newSA);
    Scaleform::GFx::AS3::Value::Pick(result, v41);
  }
  else
  {
    v44 = v54->ValueA.Data.Size;
    pHeap = v54->ValueA.Data.pHeap;
    p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&v54->ValueA;
    if ( v10 >= v44 )
    {
      if ( v10 >= v54->ValueA.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_ValueA,
          pHeap,
          v10 + (v10 >> 2));
    }
    else
    {
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
        (Scaleform::GFx::AS3::Value *)&p_ValueA->Data[v10],
        v44 - v10);
      if ( v10 < p_ValueA->Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_ValueA,
          pHeap,
          v10);
    }
    p_ValueA->Size = v10;
    if ( v10 > v44 )
    {
      v47 = &p_ValueA->Data[v44];
      v48 = v10 - v44;
      if ( v10 != v44 )
      {
        do
        {
          if ( v47 )
          {
            LODWORD(v47->First) = 0;
            HIDWORD(v47->First) = 0;
          }
          ++v47;
          --v48;
        }
        while ( v48 );
      }
    }
    v49 = 0;
    if ( p_ValueA->Size )
    {
      v50 = 0;
      do
      {
        Scaleform::GFx::AS3::Value::Assign((Scaleform::GFx::AS3::Value *)&p_ValueA->Data[v50], &newSA.Data.Data[v50]);
        ++v49;
        ++v50;
      }
      while ( v49 < p_ValueA->Size );
    }
    Scaleform::GFx::AS3::Value::Assign(result, currObj);
  }
  Data = newSA.Data.Data;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(newSA.Data.Data, v10);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
LABEL_114:
  if ( (compareFunction.Flags & 0x1F) <= 9 )
    return;
  if ( (compareFunction.Flags & 0x200) != 0 )
  {
LABEL_33:
    Scaleform::GFx::AS3::Value::ReleaseWeakRef(&compareFunction);
    return;
  }
LABEL_116:
  Scaleform::GFx::AS3::Value::ReleaseInternal(&compareFunction);
}
