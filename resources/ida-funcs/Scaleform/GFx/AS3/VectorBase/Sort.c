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


void __thiscall Scaleform::GFx::AS3::VectorBase<long>::Sort<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int>(
        Scaleform::GFx::AS3::VectorBase<long> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *currObj)
{
  Scaleform::GFx::AS3::Value *v5; // esi
  unsigned int v6; // ebp
  unsigned int v7; // edi
  unsigned int v9; // eax
  Scaleform::GFx::AS3::VM *VMRef; // eax
  unsigned int v11; // edi
  unsigned int v12; // ecx
  double *v13; // edx
  int v14; // ebp
  unsigned int v15; // esi
  int *v16; // ebx
  Scaleform::GFx::AS3::VM *v17; // esi
  const Scaleform::GFx::AS3::VM::Error *v18; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  int v20; // esi
  Scaleform::ArrayDH<long const *,2,Scaleform::ArrayDefaultPolicy> *v21; // eax
  unsigned int v22; // esi
  int *v23; // ebx
  Scaleform::GFx::AS3::VectorBase<long>::ValuePtrCollector_vtbl *v24; // esi
  Scaleform::ArrayDH<long const *,2,Scaleform::ArrayDefaultPolicy> *v25; // ebp
  Scaleform::GFx::ASStringNode *v26; // ecx
  int v28; // esi
  int *v29; // ebx
  unsigned int v30; // esi
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // edi
  Scaleform::GFx::AS3::Instances::fl::Catch *v32; // eax
  Scaleform::GFx::AS3::Instances::fl::Catch *v33; // esi
  Scaleform::GFx::AS3::VM *pVM; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *MHeap; // ecx
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **Data; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *v37; // esi
  unsigned int v38; // eax
  Scaleform::GFx::AS3::Impl::CompareAsStringInd v39; // [esp-4h] [ebp-68h]
  int flags; // [esp+10h] [ebp-54h] BYREF
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *v41; // [esp+14h] [ebp-50h]
  Scaleform::GFx::AS3::VectorBase<long>::ValuePtrCollector vc; // [esp+18h] [ebp-4Ch] BYREF
  int v43; // [esp+20h] [ebp-44h]
  Scaleform::MemoryHeap *v44; // [esp+24h] [ebp-40h]
  Scaleform::GFx::AS3::VM::Error v45; // [esp+28h] [ebp-3Ch] BYREF
  Scaleform::GFx::AS3::VectorBase<long>::ValuePtrCollector *p_vc; // [esp+30h] [ebp-34h]
  Scaleform::ArrayDH<long,2,Scaleform::ArrayDefaultPolicy> newSA; // [esp+34h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value compareFunction; // [esp+44h] [ebp-20h] BYREF
  Scaleform::ArrayDH<long const *,2,Scaleform::ArrayDefaultPolicy> ptrs; // [esp+54h] [ebp-10h] BYREF

  v5 = argv;
  v6 = 0;
  v7 = argc;
  v41 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)this;
  compareFunction.Flags = 0;
  compareFunction.Bonus.pWeakProxy = 0;
  flags = 0;
  if ( argc )
  {
    v9 = argv->Flags & 0x1F;
    if ( v9 > 0xF || v9 == 14 || v9 == 5 || v9 == 15 || v9 == 6 || v9 == 7 || v9 == 12 || v9 == 13 )
    {
      Scaleform::GFx::AS3::Value::Assign(&compareFunction, argv);
    }
    else if ( !Scaleform::GFx::AS3::Value::Convert2Int32(
                 argv,
                 (Scaleform::GFx::AS3::CheckResult *)&argc,
                 (Scaleform::GFx::AS3::Value::V1U *)&flags)->Result )
    {
      goto LABEL_28;
    }
  }
  if ( v7 <= 1
    || Scaleform::GFx::AS3::Value::Convert2Int32(
         v5 + 1,
         (Scaleform::GFx::AS3::CheckResult *)&argc,
         (Scaleform::GFx::AS3::Value::V1U *)&flags)->Result )
  {
    VMRef = this->VMRef;
    newSA.Data.pHeap = VMRef->MHeap;
    v11 = 0;
    memset(&newSA, 0, 12);
    if ( (compareFunction.Flags & 0x1F) != 0
      && ((compareFunction.Flags & 0x1F) - 12 > 3 || compareFunction.value.VS._1.VInt) )
    {
      ptrs.Data.pHeap = VMRef->MHeap;
      memset(&ptrs, 0, 12);
      vc.__vftable = (Scaleform::GFx::AS3::VectorBase<long>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector::`vftable';
      vc.Ptrs = &ptrs;
      Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::ForEach(
        (Scaleform::GFx::AS3::VectorBase<unsigned long> *)this,
        (Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc *)&vc);
      v45.ID = (Scaleform::GFx::AS3::VM::ErrorID)this->VMRef;
      v45.Message.pNode = (Scaleform::GFx::ASStringNode *)&compareFunction;
      Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<long const *,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::VectorBase<long>::CompareValuePtr>(
        &ptrs,
        0,
        ptrs.Data.Size,
        (Scaleform::GFx::AS3::VectorBase<long>::CompareValuePtr)__PAIR64__(&compareFunction, v45.ID));
      if ( (flags & 4) == 0 || (v28 = 1, ptrs.Data.Size <= 1) )
      {
LABEL_64:
        if ( ptrs.Data.Size )
        {
          do
          {
            v29 = (int *)ptrs.Data.Data[v6];
            v30 = v11 + 1;
            if ( v11 + 1 >= v11 )
            {
              if ( v30 >= newSA.Data.Policy.Capacity )
                Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
                  newSA.Data.pHeap,
                  v30 + (v30 >> 2));
            }
            else if ( v30 < newSA.Data.Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
                newSA.Data.pHeap,
                v11 + 1);
            }
            ++v11;
            newSA.Data.Size = v30;
            if ( &newSA.Data.Data[v30] != (int *)4 )
              newSA.Data.Data[v30 - 1] = *v29;
            ++v6;
          }
          while ( v6 < ptrs.Data.Size );
        }
LABEL_74:
        vc.__vftable = (Scaleform::GFx::AS3::VectorBase<long>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
LABEL_75:
        if ( (flags & 8) != 0 )
        {
          pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)currObj->pTraits.pObject;
          v32 = (Scaleform::GFx::AS3::Instances::fl::Catch *)Scaleform::GFx::AS3::Traits::Alloc(pObject);
          v33 = v32;
          if ( v32 )
          {
            Scaleform::GFx::AS3::Instances::fl::Object::Object(v32, pObject);
            v33->__vftable = (Scaleform::GFx::AS3::Instances::fl::Catch_vtbl *)&Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::`vftable';
            pVM = pObject->pVM;
            MHeap = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *)pVM->MHeap;
            LOBYTE(v33[1]._pRCC) = 0;
            v33[1].pNext = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)pVM;
            v33[1].__vftable = (Scaleform::GFx::AS3::Instances::fl::Catch_vtbl *)&Scaleform::GFx::AS3::VectorBase<long>::`vftable';
            v33[1].pPrev = 0;
            v33[1].RefCount = 0;
            v33[1].pTraits.pObject = 0;
            v33[1].DynAttrs.mHash.pTable = MHeap;
          }
          else
          {
            v33 = 0;
          }
          Scaleform::GFx::AS3::VectorBase<unsigned long>::Append(
            (Scaleform::GFx::AS3::VectorBase<unsigned long> *)&v33[1],
            (const Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> *)&newSA);
          Scaleform::GFx::AS3::Value::Pick(result, v33);
        }
        else
        {
          Data = v41[2].Data;
          v37 = v41 + 1;
          if ( v11 >= v41[1].Size )
          {
            if ( v11 >= v41[1].Policy.Capacity )
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                v41 + 1,
                Data,
                v11 + (v11 >> 2));
          }
          else if ( v11 < v41[1].Policy.Capacity >> 1 )
          {
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              v41 + 1,
              Data,
              v11);
          }
          v38 = 0;
          for ( v37->Size = v11; v38 < v37->Size; ++v38 )
            v37->Data[v38] = (const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)newSA.Data.Data[v38];
          Scaleform::GFx::AS3::Value::Assign(result, currObj);
        }
        ((void (__stdcall *)(int *))Scaleform::Memory::pGlobalHeap->Free)(newSA.Data.Data);
        goto LABEL_89;
      }
      while ( !Scaleform::GFx::AS3::VectorBase<long>::CompareValuePtr::Equal(
                 (Scaleform::GFx::AS3::VectorBase<long>::CompareValuePtr *)&v45,
                 (Scaleform::GFx::AS3::Value::V1U *)ptrs.Data.Data[v28 - 1],
                 (Scaleform::GFx::AS3::Value::V1U *)ptrs.Data.Data[v28]) )
      {
        if ( ++v28 >= ptrs.Data.Size )
          goto LABEL_64;
      }
      Scaleform::GFx::AS3::Value::SetNull(result);
      vc.__vftable = (Scaleform::GFx::AS3::VectorBase<long>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, 0);
    }
    else
    {
      if ( (flags & 0x10) != 0 )
      {
        ptrs.Data.pHeap = VMRef->MHeap;
        memset(&ptrs, 0, 12);
        vc.__vftable = (Scaleform::GFx::AS3::VectorBase<long>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<long>::Value2NumberCollector::`vftable';
        vc.Ptrs = &ptrs;
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::ForEach(
          (Scaleform::GFx::AS3::VectorBase<unsigned long> *)this,
          (Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc *)&vc);
        LOBYTE(argc) = (flags & 2) != 0;
        Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareAsNumberInd>(
          (Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *)&ptrs,
          0,
          ptrs.Data.Size,
          (Scaleform::GFx::AS3::Impl::CompareAsNumberInd)argc);
        if ( (flags & 4) != 0 )
        {
          v12 = 1;
          if ( ptrs.Data.Size > 1 )
          {
            v13 = (double *)(ptrs.Data.Data + 4);
            while ( *v13 != *(v13 - 2) )
            {
              ++v12;
              v13 += 2;
              if ( v12 >= ptrs.Data.Size )
                goto LABEL_22;
            }
            Scaleform::GFx::AS3::Value::SetSInt32(result, 0);
            vc.__vftable = (Scaleform::GFx::AS3::VectorBase<long>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
            ((void (__stdcall *)(_DWORD))Scaleform::Memory::pGlobalHeap->Free)(0);
            goto LABEL_89;
          }
        }
LABEL_22:
        argc = 0;
        if ( ptrs.Data.Size )
        {
          v14 = 0;
          do
          {
            v15 = v11 + 1;
            v16 = (int *)&v41[1].Data[(int)ptrs.Data.Data[v14 + 2]];
            if ( v11 + 1 >= v11 )
            {
              if ( v15 >= newSA.Data.Policy.Capacity )
                Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
                  newSA.Data.pHeap,
                  v15 + (v15 >> 2));
            }
            else if ( v15 < newSA.Data.Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
                newSA.Data.pHeap,
                v11 + 1);
            }
            ++v11;
            newSA.Data.Size = v15;
            if ( &newSA.Data.Data[v15] != (int *)4 )
              newSA.Data.Data[v15 - 1] = *v16;
            v14 += 4;
            ++argc;
          }
          while ( argc < ptrs.Data.Size );
        }
        goto LABEL_74;
      }
      v44 = VMRef->MHeap;
      p_vc = &vc;
      vc.__vftable = 0;
      vc.Ptrs = 0;
      v43 = 0;
      v45.ID = (Scaleform::GFx::AS3::VM::ErrorID)&Scaleform::GFx::AS3::VectorBase<long>::Value2StrCollector::`vftable';
      v45.Message.pNode = (Scaleform::GFx::ASStringNode *)VMRef;
      Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::ForEach(
        (Scaleform::GFx::AS3::VectorBase<unsigned long> *)this,
        (Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc *)&v45);
      LOBYTE(argc) = (flags & 2) != 0;
      BYTE1(argc) = flags & 1;
      *(_WORD *)&v39.Desc = argc;
      v39.UseLocale = (flags & 0x400) != 0;
      BYTE2(argc) = v39.UseLocale;
      Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareAsStringInd>(
        (Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *)&vc,
        0,
        (unsigned int)vc.Ptrs,
        v39);
      if ( (flags & 4) == 0
        || (v20 = 1, vc.Ptrs <= (Scaleform::ArrayDH<long const *,2,Scaleform::ArrayDefaultPolicy> *)1) )
      {
LABEL_44:
        v21 = vc.Ptrs;
        if ( vc.Ptrs )
        {
          do
          {
            v22 = v11 + 1;
            v23 = (int *)&v41[1].Data[(int)vc.__vftable[v6].operator()];
            if ( v11 + 1 >= v11 )
            {
              if ( v22 >= newSA.Data.Policy.Capacity )
                Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
                  newSA.Data.pHeap,
                  v22 + (v22 >> 2));
            }
            else if ( v22 < newSA.Data.Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
                newSA.Data.pHeap,
                v11 + 1);
            }
            ++v11;
            newSA.Data.Size = v22;
            if ( &newSA.Data.Data[v22] != (int *)4 )
              newSA.Data.Data[v22 - 1] = *v23;
            v21 = vc.Ptrs;
            ++v6;
          }
          while ( (Scaleform::ArrayDH<long const *,2,Scaleform::ArrayDefaultPolicy> *)v6 < vc.Ptrs );
        }
        v45.ID = (Scaleform::GFx::AS3::VM::ErrorID)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        v24 = &vc.__vftable[(int)v21 - 1];
        if ( v21 )
        {
          v25 = v21;
          do
          {
            v26 = (Scaleform::GFx::ASStringNode *)v24->~Scaleform::GFx::AS3::VectorBase<long>::ValuePtrCollector;
            if ( (*((_DWORD *)v24->~Scaleform::GFx::AS3::VectorBase<long>::ValuePtrCollector + 3))-- == 1 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v26);
            --v24;
            v25 = (Scaleform::ArrayDH<long const *,2,Scaleform::ArrayDefaultPolicy> *)((char *)v25 - 1);
          }
          while ( v25 );
        }
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, vc.__vftable);
        goto LABEL_75;
      }
      while ( Scaleform::GFx::AS3::Impl::CompareAsString::Compare(
                (Scaleform::GFx::AS3::Impl::CompareAsStringInd *)&argc,
                (const Scaleform::GFx::ASString *)&vc.__vftable[v20 - 1],
                (const Scaleform::GFx::ASString *)&vc.__vftable[v20]) )
      {
        if ( (Scaleform::ArrayDH<long const *,2,Scaleform::ArrayDefaultPolicy> *)++v20 >= vc.Ptrs )
          goto LABEL_44;
      }
      Scaleform::GFx::AS3::Value::SetNull(result);
      v45.ID = (Scaleform::GFx::AS3::VM::ErrorID)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
      Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&vc);
      ((void (__stdcall *)(_DWORD))Scaleform::Memory::pGlobalHeap->Free)(0);
    }
LABEL_89:
    if ( (compareFunction.Flags & 0x1F) <= 9 )
      return;
    if ( (compareFunction.Flags & 0x200) == 0 )
      goto LABEL_91;
    goto LABEL_32;
  }
LABEL_28:
  v17 = this->VMRef;
  Scaleform::GFx::AS3::VM::Error::Error(&v45, eCheckTypeFailedError, v17);
  Scaleform::GFx::AS3::VM::ThrowTypeError(v17, v18);
  pNode = v45.Message.pNode;
  --v45.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( (compareFunction.Flags & 0x1F) > 9 )
  {
    if ( (compareFunction.Flags & 0x200) == 0 )
    {
LABEL_91:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&compareFunction);
      return;
    }
LABEL_32:
    Scaleform::GFx::AS3::Value::ReleaseWeakRef(&compareFunction);
  }
}


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


void __thiscall Scaleform::GFx::AS3::VectorBase<unsigned long>::Sort<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *currObj)
{
  Scaleform::GFx::AS3::Value *v5; // esi
  unsigned int v6; // ebp
  unsigned int v7; // edi
  unsigned int v9; // eax
  Scaleform::GFx::AS3::VM *VMRef; // eax
  unsigned int v11; // edi
  unsigned int v12; // ecx
  double *v13; // edx
  int v14; // ebp
  unsigned int v15; // esi
  unsigned int *v16; // ebx
  Scaleform::GFx::AS3::VM *v17; // esi
  const Scaleform::GFx::AS3::VM::Error *v18; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  int v20; // esi
  Scaleform::ArrayDH<unsigned long const *,2,Scaleform::ArrayDefaultPolicy> *v21; // eax
  unsigned int v22; // esi
  unsigned int *v23; // ebx
  Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector_vtbl *v24; // esi
  Scaleform::ArrayDH<unsigned long const *,2,Scaleform::ArrayDefaultPolicy> *v25; // ebp
  Scaleform::GFx::ASStringNode *v26; // ecx
  int v28; // esi
  unsigned int *v29; // ebx
  unsigned int v30; // esi
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // edi
  Scaleform::GFx::AS3::Instances::fl::Catch *v32; // eax
  Scaleform::GFx::AS3::Instances::fl::Catch *v33; // esi
  Scaleform::GFx::AS3::VM *pVM; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *MHeap; // ecx
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **Data; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *v37; // esi
  unsigned int v38; // eax
  Scaleform::GFx::AS3::Impl::CompareAsStringInd v39; // [esp-4h] [ebp-68h]
  int flags; // [esp+10h] [ebp-54h] BYREF
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *v41; // [esp+14h] [ebp-50h]
  Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector vc; // [esp+18h] [ebp-4Ch] BYREF
  int v43; // [esp+20h] [ebp-44h]
  Scaleform::MemoryHeap *v44; // [esp+24h] [ebp-40h]
  Scaleform::GFx::AS3::VM::Error v45; // [esp+28h] [ebp-3Ch] BYREF
  Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector *p_vc; // [esp+30h] [ebp-34h]
  Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> newSA; // [esp+34h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value compareFunction; // [esp+44h] [ebp-20h] BYREF
  Scaleform::ArrayDH<unsigned long const *,2,Scaleform::ArrayDefaultPolicy> ptrs; // [esp+54h] [ebp-10h] BYREF

  v5 = argv;
  v6 = 0;
  v7 = argc;
  v41 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)this;
  compareFunction.Flags = 0;
  compareFunction.Bonus.pWeakProxy = 0;
  flags = 0;
  if ( argc )
  {
    v9 = argv->Flags & 0x1F;
    if ( v9 > 0xF || v9 == 14 || v9 == 5 || v9 == 15 || v9 == 6 || v9 == 7 || v9 == 12 || v9 == 13 )
    {
      Scaleform::GFx::AS3::Value::Assign(&compareFunction, argv);
    }
    else if ( !Scaleform::GFx::AS3::Value::Convert2Int32(
                 argv,
                 (Scaleform::GFx::AS3::CheckResult *)&argc,
                 (Scaleform::GFx::AS3::Value::V1U *)&flags)->Result )
    {
      goto LABEL_28;
    }
  }
  if ( v7 <= 1
    || Scaleform::GFx::AS3::Value::Convert2Int32(
         v5 + 1,
         (Scaleform::GFx::AS3::CheckResult *)&argc,
         (Scaleform::GFx::AS3::Value::V1U *)&flags)->Result )
  {
    VMRef = this->VMRef;
    newSA.Data.pHeap = VMRef->MHeap;
    v11 = 0;
    memset(&newSA, 0, 12);
    if ( (compareFunction.Flags & 0x1F) != 0
      && ((compareFunction.Flags & 0x1F) - 12 > 3 || compareFunction.value.VS._1.VInt) )
    {
      ptrs.Data.pHeap = VMRef->MHeap;
      memset(&ptrs, 0, 12);
      vc.__vftable = (Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector::`vftable';
      vc.Ptrs = &ptrs;
      Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::ForEach(this, &vc);
      v45.ID = (Scaleform::GFx::AS3::VM::ErrorID)this->VMRef;
      v45.Message.pNode = (Scaleform::GFx::ASStringNode *)&compareFunction;
      Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<unsigned long const *,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::VectorBase<unsigned long>::CompareValuePtr>(
        &ptrs,
        0,
        ptrs.Data.Size,
        (Scaleform::GFx::AS3::VectorBase<unsigned long>::CompareValuePtr)__PAIR64__(&compareFunction, v45.ID));
      if ( (flags & 4) == 0 || (v28 = 1, ptrs.Data.Size <= 1) )
      {
LABEL_64:
        if ( ptrs.Data.Size )
        {
          do
          {
            v29 = (unsigned int *)ptrs.Data.Data[v6];
            v30 = v11 + 1;
            if ( v11 + 1 >= v11 )
            {
              if ( v30 >= newSA.Data.Policy.Capacity )
                Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
                  newSA.Data.pHeap,
                  v30 + (v30 >> 2));
            }
            else if ( v30 < newSA.Data.Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
                newSA.Data.pHeap,
                v11 + 1);
            }
            ++v11;
            newSA.Data.Size = v30;
            if ( &newSA.Data.Data[v30] != (unsigned int *)4 )
              newSA.Data.Data[v30 - 1] = *v29;
            ++v6;
          }
          while ( v6 < ptrs.Data.Size );
        }
LABEL_74:
        vc.__vftable = (Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
LABEL_75:
        if ( (flags & 8) != 0 )
        {
          pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)currObj->pTraits.pObject;
          v32 = (Scaleform::GFx::AS3::Instances::fl::Catch *)Scaleform::GFx::AS3::Traits::Alloc(pObject);
          v33 = v32;
          if ( v32 )
          {
            Scaleform::GFx::AS3::Instances::fl::Object::Object(v32, pObject);
            v33->__vftable = (Scaleform::GFx::AS3::Instances::fl::Catch_vtbl *)&Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::`vftable';
            pVM = pObject->pVM;
            MHeap = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *)pVM->MHeap;
            LOBYTE(v33[1]._pRCC) = 0;
            v33[1].pNext = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)pVM;
            v33[1].__vftable = (Scaleform::GFx::AS3::Instances::fl::Catch_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::`vftable';
            v33[1].pPrev = 0;
            v33[1].RefCount = 0;
            v33[1].pTraits.pObject = 0;
            v33[1].DynAttrs.mHash.pTable = MHeap;
          }
          else
          {
            v33 = 0;
          }
          Scaleform::GFx::AS3::VectorBase<unsigned long>::Append(
            (Scaleform::GFx::AS3::VectorBase<unsigned long> *)&v33[1],
            &newSA);
          Scaleform::GFx::AS3::Value::Pick(result, v33);
        }
        else
        {
          Data = v41[2].Data;
          v37 = v41 + 1;
          if ( v11 >= v41[1].Size )
          {
            if ( v11 >= v41[1].Policy.Capacity )
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                v41 + 1,
                Data,
                v11 + (v11 >> 2));
          }
          else if ( v11 < v41[1].Policy.Capacity >> 1 )
          {
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              v41 + 1,
              Data,
              v11);
          }
          v38 = 0;
          for ( v37->Size = v11; v38 < v37->Size; ++v38 )
            v37->Data[v38] = (const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)newSA.Data.Data[v38];
          Scaleform::GFx::AS3::Value::Assign(result, currObj);
        }
        ((void (__stdcall *)(unsigned int *))Scaleform::Memory::pGlobalHeap->Free)(newSA.Data.Data);
        goto LABEL_89;
      }
      while ( !Scaleform::GFx::AS3::VectorBase<unsigned long>::CompareValuePtr::Equal(
                 (Scaleform::GFx::AS3::VectorBase<unsigned long>::CompareValuePtr *)&v45,
                 (Scaleform::GFx::AS3::Value::V1U *)ptrs.Data.Data[v28 - 1],
                 (Scaleform::GFx::AS3::Value::V1U *)ptrs.Data.Data[v28]) )
      {
        if ( ++v28 >= ptrs.Data.Size )
          goto LABEL_64;
      }
      Scaleform::GFx::AS3::Value::SetNull(result);
      vc.__vftable = (Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, 0);
    }
    else
    {
      if ( (flags & 0x10) != 0 )
      {
        ptrs.Data.pHeap = VMRef->MHeap;
        memset(&ptrs, 0, 12);
        vc.__vftable = (Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::Value2NumberCollector::`vftable';
        vc.Ptrs = &ptrs;
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::ForEach(this, &vc);
        LOBYTE(argc) = (flags & 2) != 0;
        Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareAsNumberInd>(
          (Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *)&ptrs,
          0,
          ptrs.Data.Size,
          (Scaleform::GFx::AS3::Impl::CompareAsNumberInd)argc);
        if ( (flags & 4) != 0 )
        {
          v12 = 1;
          if ( ptrs.Data.Size > 1 )
          {
            v13 = (double *)(ptrs.Data.Data + 4);
            while ( *v13 != *(v13 - 2) )
            {
              ++v12;
              v13 += 2;
              if ( v12 >= ptrs.Data.Size )
                goto LABEL_22;
            }
            Scaleform::GFx::AS3::Value::SetSInt32(result, 0);
            vc.__vftable = (Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
            ((void (__stdcall *)(_DWORD))Scaleform::Memory::pGlobalHeap->Free)(0);
            goto LABEL_89;
          }
        }
LABEL_22:
        argc = 0;
        if ( ptrs.Data.Size )
        {
          v14 = 0;
          do
          {
            v15 = v11 + 1;
            v16 = (unsigned int *)&v41[1].Data[(int)ptrs.Data.Data[v14 + 2]];
            if ( v11 + 1 >= v11 )
            {
              if ( v15 >= newSA.Data.Policy.Capacity )
                Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
                  newSA.Data.pHeap,
                  v15 + (v15 >> 2));
            }
            else if ( v15 < newSA.Data.Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
                newSA.Data.pHeap,
                v11 + 1);
            }
            ++v11;
            newSA.Data.Size = v15;
            if ( &newSA.Data.Data[v15] != (unsigned int *)4 )
              newSA.Data.Data[v15 - 1] = *v16;
            v14 += 4;
            ++argc;
          }
          while ( argc < ptrs.Data.Size );
        }
        goto LABEL_74;
      }
      v44 = VMRef->MHeap;
      p_vc = &vc;
      vc.__vftable = 0;
      vc.Ptrs = 0;
      v43 = 0;
      v45.ID = (Scaleform::GFx::AS3::VM::ErrorID)&Scaleform::GFx::AS3::VectorBase<unsigned long>::Value2StrCollector::`vftable';
      v45.Message.pNode = (Scaleform::GFx::ASStringNode *)VMRef;
      Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::ForEach(
        this,
        (Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc *)&v45);
      LOBYTE(argc) = (flags & 2) != 0;
      BYTE1(argc) = flags & 1;
      *(_WORD *)&v39.Desc = argc;
      v39.UseLocale = (flags & 0x400) != 0;
      BYTE2(argc) = v39.UseLocale;
      Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareAsStringInd>(
        (Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *)&vc,
        0,
        (unsigned int)vc.Ptrs,
        v39);
      if ( (flags & 4) == 0
        || (v20 = 1, vc.Ptrs <= (Scaleform::ArrayDH<unsigned long const *,2,Scaleform::ArrayDefaultPolicy> *)1) )
      {
LABEL_44:
        v21 = vc.Ptrs;
        if ( vc.Ptrs )
        {
          do
          {
            v22 = v11 + 1;
            v23 = (unsigned int *)&v41[1].Data[(int)vc.__vftable[v6].operator()];
            if ( v11 + 1 >= v11 )
            {
              if ( v22 >= newSA.Data.Policy.Capacity )
                Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
                  newSA.Data.pHeap,
                  v22 + (v22 >> 2));
            }
            else if ( v22 < newSA.Data.Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
                newSA.Data.pHeap,
                v11 + 1);
            }
            ++v11;
            newSA.Data.Size = v22;
            if ( &newSA.Data.Data[v22] != (unsigned int *)4 )
              newSA.Data.Data[v22 - 1] = *v23;
            v21 = vc.Ptrs;
            ++v6;
          }
          while ( (Scaleform::ArrayDH<unsigned long const *,2,Scaleform::ArrayDefaultPolicy> *)v6 < vc.Ptrs );
        }
        v45.ID = (Scaleform::GFx::AS3::VM::ErrorID)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        v24 = &vc.__vftable[(int)v21 - 1];
        if ( v21 )
        {
          v25 = v21;
          do
          {
            v26 = (Scaleform::GFx::ASStringNode *)v24->~Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector;
            if ( (*((_DWORD *)v24->~Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector + 3))-- == 1 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v26);
            --v24;
            v25 = (Scaleform::ArrayDH<unsigned long const *,2,Scaleform::ArrayDefaultPolicy> *)((char *)v25 - 1);
          }
          while ( v25 );
        }
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, vc.__vftable);
        goto LABEL_75;
      }
      while ( Scaleform::GFx::AS3::Impl::CompareAsString::Compare(
                (Scaleform::GFx::AS3::Impl::CompareAsStringInd *)&argc,
                (const Scaleform::GFx::ASString *)&vc.__vftable[v20 - 1],
                (const Scaleform::GFx::ASString *)&vc.__vftable[v20]) )
      {
        if ( (Scaleform::ArrayDH<unsigned long const *,2,Scaleform::ArrayDefaultPolicy> *)++v20 >= vc.Ptrs )
          goto LABEL_44;
      }
      Scaleform::GFx::AS3::Value::SetNull(result);
      v45.ID = (Scaleform::GFx::AS3::VM::ErrorID)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
      Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&vc);
      ((void (__stdcall *)(_DWORD))Scaleform::Memory::pGlobalHeap->Free)(0);
    }
LABEL_89:
    if ( (compareFunction.Flags & 0x1F) <= 9 )
      return;
    if ( (compareFunction.Flags & 0x200) == 0 )
      goto LABEL_91;
    goto LABEL_32;
  }
LABEL_28:
  v17 = this->VMRef;
  Scaleform::GFx::AS3::VM::Error::Error(&v45, eCheckTypeFailedError, v17);
  Scaleform::GFx::AS3::VM::ThrowTypeError(v17, v18);
  pNode = v45.Message.pNode;
  --v45.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( (compareFunction.Flags & 0x1F) > 9 )
  {
    if ( (compareFunction.Flags & 0x200) == 0 )
    {
LABEL_91:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&compareFunction);
      return;
    }
LABEL_32:
    Scaleform::GFx::AS3::Value::ReleaseWeakRef(&compareFunction);
  }
}
