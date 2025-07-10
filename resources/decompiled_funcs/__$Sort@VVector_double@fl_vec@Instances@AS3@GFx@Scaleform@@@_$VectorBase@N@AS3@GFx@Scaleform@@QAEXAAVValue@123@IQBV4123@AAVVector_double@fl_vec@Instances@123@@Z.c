// local variable allocation has failed, the output may be wrong!
void __thiscall Scaleform::GFx::AS3::VectorBase<double>::Sort<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *currObj)
{
  unsigned int v6; // eax
  Scaleform::GFx::AS3::VM *v7; // eax
  unsigned int v8; // edi
  unsigned int Size; // eax
  unsigned int v10; // ecx
  double *v11; // edx
  unsigned int v12; // esi
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  __int16 v16; // ax
  bool v17; // cc
  int v18; // esi
  unsigned int v19; // eax
  unsigned int k; // ebx
  unsigned int v21; // esi
  const long double **v22; // esi
  unsigned int v23; // ebx
  Scaleform::GFx::ASStringNode *v24; // ecx
  const Scaleform::MemoryHeap *MHeap; // eax
  int v27; // esi
  unsigned int j; // ebx
  unsigned int v29; // esi
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // edi
  Scaleform::GFx::AS3::Instances::fl::Catch *v31; // eax
  Scaleform::GFx::AS3::Instances::fl::Catch *v32; // esi
  Scaleform::GFx::AS3::VM *pVM; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v34; // ecx
  Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *Data; // eax
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *v36; // esi
  unsigned int v37; // eax
  Scaleform::GFx::AS3::Impl::CompareAsStringInd v38; // [esp-4h] [ebp-6Ch]
  Scaleform::GFx::AS3::CheckResult v39; // [esp+13h] [ebp-55h] BYREF
  int functor; // [esp+14h] [ebp-54h] OVERLAPPED BYREF
  int flags; // [esp+18h] [ebp-50h] BYREF
  unsigned int i; // [esp+1Ch] [ebp-4Ch]
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *v43; // [esp+20h] [ebp-48h]
  Scaleform::GFx::AS3::VectorBase<double>::CompareValuePtr v44; // [esp+24h] [ebp-44h] BYREF
  Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector vc; // [esp+2Ch] [ebp-3Ch] BYREF
  Scaleform::ArrayDH<double const *,2,Scaleform::ArrayDefaultPolicy> *p_ptrs; // [esp+34h] [ebp-34h]
  Scaleform::ArrayDH<double,2,Scaleform::ArrayDefaultPolicy> newSA; // [esp+38h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value compareFunction; // [esp+48h] [ebp-20h] BYREF
  Scaleform::ArrayDH<double const *,2,Scaleform::ArrayDefaultPolicy> ptrs; // [esp+58h] [ebp-10h] BYREF

  v43 = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this;
  compareFunction.Flags = 0;
  compareFunction.Bonus.pWeakProxy = 0;
  flags = 0;
  if ( argc )
  {
    v6 = argv->Flags & 0x1F;
    if ( v6 > 0xF || v6 == 14 || v6 == 5 || v6 == 15 || v6 == 6 || v6 == 7 || v6 == 12 || v6 == 13 )
    {
      Scaleform::GFx::AS3::Value::Assign(&compareFunction, argv);
    }
    else if ( !Scaleform::GFx::AS3::Value::Convert2Int32(argv, &v39, (Scaleform::GFx::AS3::Value::V1U *)&flags)->Result )
    {
LABEL_28:
      VMRef = this->VMRef;
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&vc, eCheckTypeFailedError, VMRef);
      Scaleform::GFx::AS3::VM::ThrowTypeError(VMRef, v14);
      v15 = (Scaleform::GFx::ASStringNode *)vc.Ptrs;
      --vc.Ptrs->Data.pHeap;
      if ( !v15->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      v16 = compareFunction.Flags;
      v17 = (compareFunction.Flags & 0x1F) <= 9;
LABEL_31:
      if ( v17 )
        return;
      if ( (v16 & 0x200) != 0 )
        goto LABEL_33;
LABEL_92:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&compareFunction);
      return;
    }
  }
  if ( argc > 1
    && !Scaleform::GFx::AS3::Value::Convert2Int32(argv + 1, &v39, (Scaleform::GFx::AS3::Value::V1U *)&flags)->Result )
  {
    goto LABEL_28;
  }
  v7 = this->VMRef;
  v8 = 0;
  newSA.Data.pHeap = v7->MHeap;
  memset(&newSA, 0, 12);
  if ( (compareFunction.Flags & 0x1F) != 0
    && ((compareFunction.Flags & 0x1F) - 12 > 3 || compareFunction.value.VS._1.VInt) )
  {
    MHeap = v7->MHeap;
    vc.Ptrs = &ptrs;
    memset(&ptrs, 0, 12);
    ptrs.Data.pHeap = MHeap;
    vc.__vftable = (Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector::`vftable';
    Scaleform::GFx::AS3::VectorBase<double>::ForEach(this, &vc);
    v44.Vm = this->VMRef;
    v44.Func = &compareFunction;
    Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<double const *,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::VectorBase<double>::CompareValuePtr>(
      &ptrs,
      0,
      ptrs.Data.Size,
      (Scaleform::GFx::AS3::VectorBase<double>::CompareValuePtr)__PAIR64__(&compareFunction, (unsigned int)v44.Vm));
    if ( (flags & 4) != 0 )
    {
      v27 = 1;
      if ( ptrs.Data.Size > 1 )
      {
        while ( !Scaleform::GFx::AS3::VectorBase<double>::CompareValuePtr::Equal(
                   &v44,
                   (long double *)ptrs.Data.Data[v27 - 1],
                   (long double *)ptrs.Data.Data[v27]) )
        {
          if ( ++v27 >= ptrs.Data.Size )
            goto LABEL_66;
        }
        Scaleform::GFx::AS3::Value::SetNull(result);
        vc.__vftable = (Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, 0);
        goto LABEL_35;
      }
    }
LABEL_66:
    for ( j = 0; j < ptrs.Data.Size; ++j )
    {
      v29 = v8 + 1;
      v44.Vm = (Scaleform::GFx::AS3::VM *)ptrs.Data.Data[j];
      if ( v8 + 1 >= v8 )
      {
        if ( v29 >= newSA.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
            newSA.Data.pHeap,
            v29 + (v29 >> 2));
      }
      else if ( v29 < newSA.Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
          newSA.Data.pHeap,
          v8 + 1);
      }
      ++v8;
      newSA.Data.Size = v29;
      if ( &newSA.Data.Data[v29] != (long double *)8 )
        newSA.Data.Data[v29 - 1] = *(double *)&v44.Vm->__vftable;
    }
LABEL_76:
    vc.__vftable = (Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
    goto LABEL_77;
  }
  if ( (flags & 0x10) != 0 )
  {
    ptrs.Data.pHeap = v7->MHeap;
    memset(&ptrs, 0, 12);
    vc.__vftable = (Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<double>::Value2NumberCollector::`vftable';
    vc.Ptrs = &ptrs;
    Scaleform::GFx::AS3::VectorBase<double>::ForEach(this, &vc);
    LOBYTE(i) = (flags & 2) != 0;
    Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareAsNumberInd>(
      (Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *)&ptrs,
      0,
      ptrs.Data.Size,
      (Scaleform::GFx::AS3::Impl::CompareAsNumberInd)i);
    Size = ptrs.Data.Size;
    if ( (flags & 4) != 0 )
    {
      v10 = 1;
      if ( ptrs.Data.Size > 1 )
      {
        v11 = (double *)(ptrs.Data.Data + 4);
        while ( *v11 != *(v11 - 2) )
        {
          Size = ptrs.Data.Size;
          ++v10;
          v11 += 2;
          if ( v10 >= ptrs.Data.Size )
            goto LABEL_22;
        }
        Scaleform::GFx::AS3::Value::SetSInt32(result, 0);
        vc.__vftable = (Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, 0);
LABEL_35:
        v16 = compareFunction.Flags;
        v17 = (compareFunction.Flags & 0x1F) <= 9;
        goto LABEL_31;
      }
    }
LABEL_22:
    i = 0;
    if ( Size )
    {
      functor = 0;
      do
      {
        v12 = v8 + 1;
        v44.Vm = (Scaleform::GFx::AS3::VM *)&this->ValueA.Data.Data[*(int *)((char *)ptrs.Data.Data + functor + 8)];
        if ( v8 + 1 >= v8 )
        {
          if ( v12 >= newSA.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
              newSA.Data.pHeap,
              v12 + (v12 >> 2));
        }
        else if ( v12 < newSA.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
            newSA.Data.pHeap,
            v8 + 1);
        }
        ++v8;
        newSA.Data.Size = v12;
        if ( &newSA.Data.Data[v12] != (long double *)8 )
          newSA.Data.Data[v12 - 1] = *(double *)&v44.Vm->__vftable;
        functor += 16;
        ++i;
      }
      while ( i < ptrs.Data.Size );
    }
    goto LABEL_76;
  }
  ptrs.Data.pHeap = v7->MHeap;
  vc.Ptrs = (Scaleform::ArrayDH<double const *,2,Scaleform::ArrayDefaultPolicy> *)v7;
  memset(&ptrs, 0, 12);
  vc.__vftable = (Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<double>::Value2StrCollector::`vftable';
  p_ptrs = &ptrs;
  Scaleform::GFx::AS3::VectorBase<double>::ForEach(this, &vc);
  BYTE1(functor) = flags & 1;
  LOBYTE(functor) = (flags & 2) != 0;
  *(_WORD *)&v38.Desc = functor;
  v38.UseLocale = (flags & 0x400) != 0;
  BYTE2(functor) = v38.UseLocale;
  Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareAsStringInd>(
    (Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *)&ptrs,
    0,
    ptrs.Data.Size,
    v38);
  if ( (flags & 4) != 0 )
  {
    v18 = 1;
    if ( ptrs.Data.Size > 1 )
    {
      while ( Scaleform::GFx::AS3::Impl::CompareAsString::Compare(
                (Scaleform::GFx::AS3::Impl::CompareAsStringInd *)&functor,
                (const Scaleform::GFx::ASString *)&ptrs.Data.Data[2 * v18 - 2],
                (const Scaleform::GFx::ASString *)&ptrs.Data.Data[2 * v18]) )
      {
        if ( ++v18 >= ptrs.Data.Size )
          goto LABEL_46;
      }
      Scaleform::GFx::AS3::Value::SetNull(result);
      vc.__vftable = (Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
      Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&ptrs);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, 0);
      goto LABEL_35;
    }
  }
LABEL_46:
  v19 = ptrs.Data.Size;
  for ( k = 0; k < ptrs.Data.Size; ++k )
  {
    v21 = v8 + 1;
    v44.Vm = (Scaleform::GFx::AS3::VM *)&v43[1].Data[(int)ptrs.Data.Data[2 * k + 1]];
    if ( v8 + 1 >= v8 )
    {
      if ( v21 >= newSA.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
          newSA.Data.pHeap,
          v21 + (v21 >> 2));
    }
    else if ( v21 < newSA.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
        newSA.Data.pHeap,
        v8 + 1);
    }
    ++v8;
    newSA.Data.Size = v21;
    if ( &newSA.Data.Data[v21] != (long double *)8 )
      newSA.Data.Data[v21 - 1] = *(double *)&v44.Vm->__vftable;
    v19 = ptrs.Data.Size;
  }
  vc.__vftable = (Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  v22 = &ptrs.Data.Data[2 * v19 - 2];
  if ( v19 )
  {
    v23 = v19;
    do
    {
      v24 = (Scaleform::GFx::ASStringNode *)*v22;
      if ( (*((_DWORD *)*v22 + 3))-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      v22 -= 2;
      --v23;
    }
    while ( v23 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
LABEL_77:
  if ( (flags & 8) != 0 )
  {
    pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)currObj->pTraits.pObject;
    v31 = (Scaleform::GFx::AS3::Instances::fl::Catch *)Scaleform::GFx::AS3::Traits::Alloc(pObject);
    v32 = v31;
    if ( v31 )
    {
      Scaleform::GFx::AS3::Instances::fl::Object::Object(v31, pObject);
      v32->__vftable = (Scaleform::GFx::AS3::Instances::fl::Catch_vtbl *)&Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::`vftable';
      pVM = pObject->pVM;
      v34 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *)pVM->MHeap;
      LOBYTE(v32[1]._pRCC) = 0;
      v32[1].pNext = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)pVM;
      v32[1].__vftable = (Scaleform::GFx::AS3::Instances::fl::Catch_vtbl *)&Scaleform::GFx::AS3::VectorBase<double>::`vftable';
      v32[1].pPrev = 0;
      v32[1].RefCount = 0;
      v32[1].pTraits.pObject = 0;
      v32[1].DynAttrs.mHash.pTable = v34;
    }
    else
    {
      v32 = 0;
    }
    Scaleform::GFx::AS3::VectorBase<double>::Append((Scaleform::GFx::AS3::VectorBase<double> *)&v32[1], &newSA);
    Scaleform::GFx::AS3::Value::Pick(result, v32);
  }
  else
  {
    Data = v43[2].Data;
    v36 = v43 + 1;
    if ( v8 >= v43[1].Size )
    {
      if ( v8 >= v43[1].Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v43 + 1,
          Data,
          v8 + (v8 >> 2));
    }
    else if ( v8 < v43[1].Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v43 + 1,
        Data,
        v8);
    }
    v37 = 0;
    for ( v36->Size = v8; v37 < v36->Size; ++v37 )
      *(double *)&v36->Data[v37] = newSA.Data.Data[v37];
    Scaleform::GFx::AS3::Value::Assign(result, currObj);
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, newSA.Data.Data);
  if ( (compareFunction.Flags & 0x1F) > 9 )
  {
    if ( (compareFunction.Flags & 0x200) != 0 )
    {
LABEL_33:
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&compareFunction);
      return;
    }
    goto LABEL_92;
  }
}
