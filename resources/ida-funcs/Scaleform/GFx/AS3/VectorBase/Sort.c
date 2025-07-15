// local variable allocation has failed, the output may be wrong!
void __thiscall Scaleform::GFx::AS3::VectorBase<double>::Sort<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *currObj)
{
  unsigned int v6; // eax
  Scaleform::GFx::AS3::VM *VMRef; // edi
  Scaleform::GFx::AS3::ClassTraits::fl::Number *v8; // esi
  Scaleform::GFx::AS3::Traits *v9; // ebx
  const char *v10; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Number *pObject; // esi
  Scaleform::GFx::AS3::Traits *ValueTraits; // ebx
  const char *pData; // eax
  const char *v14; // eax
  unsigned int v15; // eax
  const Scaleform::GFx::AS3::VM::Error *v16; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::ASStringNode *v19; // eax
  Scaleform::GFx::AS3::VM *v20; // eax
  const Scaleform::MemoryHeap *MHeap; // edx
  unsigned int v22; // edi
  unsigned int v23; // ecx
  double *v24; // edx
  int v25; // ebx
  unsigned int v26; // esi
  int v27; // esi
  unsigned int Size; // eax
  unsigned int j; // ebx
  unsigned int v30; // esi
  const long double **v31; // esi
  unsigned int v32; // ebx
  Scaleform::GFx::ASStringNode *v33; // ecx
  Scaleform::GFx::AS3::VM *v35; // esi
  int v36; // esi
  unsigned int i; // ebx
  unsigned int v38; // esi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v39; // edi
  Scaleform::GFx::AS3::Instances::fl::Object *v40; // eax
  Scaleform::GFx::AS3::Instances::fl::Object *v41; // esi
  Scaleform::GFx::AS3::VM *pVM; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v43; // ecx
  const char *v44; // eax
  unsigned int *p_RefCount; // esi
  unsigned int v46; // eax
  Scaleform::StringDataPtr v47; // [esp-10h] [ebp-70h]
  Scaleform::StringDataPtr v48; // [esp-8h] [ebp-68h]
  Scaleform::GFx::AS3::Impl::CompareAsStringInd v49; // [esp-4h] [ebp-64h]
  Scaleform::GFx::AS3::CheckResult v50; // [esp+Fh] [ebp-51h] BYREF
  unsigned int functor; // [esp+10h] [ebp-50h] OVERLAPPED BYREF
  int flags; // [esp+14h] [ebp-4Ch] BYREF
  Scaleform::GFx::ASStringNode *v53; // [esp+18h] [ebp-48h]
  Scaleform::StringDataPtr arg2; // [esp+1Ch] [ebp-44h] BYREF
  Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector vc; // [esp+24h] [ebp-3Ch] BYREF
  Scaleform::ArrayDH<double const *,2,Scaleform::ArrayDefaultPolicy> *p_ptrs; // [esp+2Ch] [ebp-34h]
  Scaleform::ArrayDH<double,2,Scaleform::ArrayDefaultPolicy> newSA; // [esp+30h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value compareFunction; // [esp+40h] [ebp-20h] BYREF
  Scaleform::ArrayDH<double const *,2,Scaleform::ArrayDefaultPolicy> ptrs; // [esp+50h] [ebp-10h] BYREF

  v53 = (Scaleform::GFx::ASStringNode *)this;
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
    else if ( !Scaleform::GFx::AS3::Value::Convert2Int32(argv, &v50, (Scaleform::GFx::AS3::Value::V1U *)&flags)->Result )
    {
      VMRef = this->VMRef;
      pObject = currObj->pTraits.pObject->pVM->TraitsNumber.pObject;
      ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(VMRef, argv);
      pData = pObject->GetName(pObject, (Scaleform::GFx::ASString *)&functor)->pNode->pData;
      v48.Size = (unsigned int)pData;
      if ( pData )
        strlen(pData);
      v48.pStr = (const char *)&arg2;
      v14 = **(const char ***)((int (__thiscall *)(Scaleform::GFx::AS3::Traits *))ValueTraits->GetName)(ValueTraits);
      v47.pStr = v14;
      if ( v14 )
        goto LABEL_19;
      goto LABEL_20;
    }
  }
  if ( argc <= 1
    || Scaleform::GFx::AS3::Value::Convert2Int32(argv + 1, &v50, (Scaleform::GFx::AS3::Value::V1U *)&flags)->Result )
  {
    v20 = this->VMRef;
    MHeap = v20->MHeap;
    v22 = 0;
    memset(&newSA, 0, 12);
    newSA.Data.pHeap = MHeap;
    if ( (compareFunction.Flags & 0x1F) != 0
      && ((compareFunction.Flags & 0x1F) - 12 > 3 || compareFunction.value.VS._1.VInt) )
    {
      vc.Ptrs = &ptrs;
      memset(&ptrs, 0, 12);
      ptrs.Data.pHeap = MHeap;
      vc.__vftable = (Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector::`vftable';
      Scaleform::GFx::AS3::VectorBase<double>::ForEach(this, &vc);
      v35 = this->VMRef;
      arg2.Size = (unsigned int)&compareFunction;
      arg2.pStr = (const char *)v35;
      Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<double const *,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::VectorBase<double>::CompareValuePtr>(
        &ptrs,
        0,
        ptrs.Data.Size,
        (Scaleform::GFx::AS3::VectorBase<double>::CompareValuePtr)__PAIR64__(&compareFunction, (unsigned int)v35));
      if ( (flags & 4) != 0 )
      {
        v36 = 1;
        if ( ptrs.Data.Size > 1 )
        {
          while ( !Scaleform::GFx::AS3::VectorBase<double>::CompareValuePtr::Equal(
                     (Scaleform::GFx::AS3::VectorBase<double>::CompareValuePtr *)&arg2,
                     (long double *)ptrs.Data.Data[v36 - 1],
                     (long double *)ptrs.Data.Data[v36]) )
          {
            if ( ++v36 >= ptrs.Data.Size )
              goto LABEL_77;
          }
          Scaleform::GFx::AS3::Value::SetNull(result);
          vc.__vftable = (Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, 0);
          goto LABEL_102;
        }
      }
LABEL_77:
      for ( i = 0; i < ptrs.Data.Size; ++i )
      {
        v38 = v22 + 1;
        arg2.pStr = (const char *)ptrs.Data.Data[i];
        if ( v22 + 1 >= v22 )
        {
          if ( v38 >= newSA.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
              newSA.Data.pHeap,
              v38 + (v38 >> 2));
        }
        else if ( v38 < newSA.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
            newSA.Data.pHeap,
            v22 + 1);
        }
        ++v22;
        newSA.Data.Size = v38;
        if ( &newSA.Data.Data[v38] != (long double *)8 )
          newSA.Data.Data[v38 - 1] = *(double *)arg2.pStr;
      }
    }
    else
    {
      if ( (flags & 0x10) == 0 )
      {
        ptrs.Data.pHeap = v20->MHeap;
        vc.Ptrs = (Scaleform::ArrayDH<double const *,2,Scaleform::ArrayDefaultPolicy> *)v20;
        memset(&ptrs, 0, 12);
        vc.__vftable = (Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<double>::Value2StrCollector::`vftable';
        p_ptrs = &ptrs;
        Scaleform::GFx::AS3::VectorBase<double>::ForEach(this, &vc);
        BYTE1(functor) = flags & 1;
        LOBYTE(functor) = (flags & 2) != 0;
        *(_WORD *)&v49.Desc = functor;
        v49.UseLocale = (flags & 0x400) != 0;
        BYTE2(functor) = v49.UseLocale;
        Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareAsStringInd>(
          (Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *)&ptrs,
          0,
          ptrs.Data.Size,
          v49);
        if ( (flags & 4) != 0 )
        {
          v27 = 1;
          if ( ptrs.Data.Size > 1 )
          {
            while ( Scaleform::GFx::AS3::Impl::CompareAsString::Compare(
                      (Scaleform::GFx::AS3::Impl::CompareAsStringInd *)&functor,
                      (const Scaleform::GFx::ASString *)&ptrs.Data.Data[2 * v27 - 2],
                      (const Scaleform::GFx::ASString *)&ptrs.Data.Data[2 * v27]) )
            {
              if ( ++v27 >= ptrs.Data.Size )
                goto LABEL_57;
            }
            Scaleform::GFx::AS3::Value::SetNull(result);
            vc.__vftable = (Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
            Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&ptrs);
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, 0);
            goto LABEL_102;
          }
        }
LABEL_57:
        Size = ptrs.Data.Size;
        for ( j = 0; j < ptrs.Data.Size; ++j )
        {
          v30 = v22 + 1;
          arg2.pStr = (const char *)(v53->RefCount + 8 * (int)ptrs.Data.Data[2 * j + 1]);
          if ( v22 + 1 >= v22 )
          {
            if ( v30 >= newSA.Data.Policy.Capacity )
              Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
                newSA.Data.pHeap,
                v30 + (v30 >> 2));
          }
          else if ( v30 < newSA.Data.Policy.Capacity >> 1 )
          {
            Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
              newSA.Data.pHeap,
              v22 + 1);
          }
          ++v22;
          newSA.Data.Size = v30;
          if ( &newSA.Data.Data[v30] != (long double *)8 )
            newSA.Data.Data[v30 - 1] = *(double *)arg2.pStr;
          Size = ptrs.Data.Size;
        }
        vc.__vftable = (Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        v31 = &ptrs.Data.Data[2 * Size - 2];
        if ( Size )
        {
          v32 = Size;
          do
          {
            v33 = (Scaleform::GFx::ASStringNode *)*v31;
            if ( (*((_DWORD *)*v31 + 3))-- == 1 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v33);
            v31 -= 2;
            --v32;
          }
          while ( v32 );
        }
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
        goto LABEL_88;
      }
      ptrs.Data.pHeap = MHeap;
      memset(&ptrs, 0, 12);
      vc.__vftable = (Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<double>::Value2NumberCollector::`vftable';
      vc.Ptrs = &ptrs;
      Scaleform::GFx::AS3::VectorBase<double>::ForEach(this, &vc);
      LOBYTE(functor) = (flags & 2) != 0;
      Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareAsNumberInd>(
        (Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *)&ptrs,
        0,
        ptrs.Data.Size,
        (Scaleform::GFx::AS3::Impl::CompareAsNumberInd)functor);
      if ( (flags & 4) != 0 )
      {
        v23 = 1;
        if ( ptrs.Data.Size > 1 )
        {
          v24 = (double *)(ptrs.Data.Data + 4);
          while ( *v24 != *(v24 - 2) )
          {
            ++v23;
            v24 += 2;
            if ( v23 >= ptrs.Data.Size )
              goto LABEL_41;
          }
          Scaleform::GFx::AS3::Value::SetSInt32(result, 0);
          vc.__vftable = (Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
          ((void (__stdcall *)(_DWORD))Scaleform::Memory::pGlobalHeap->Free)(0);
          goto LABEL_102;
        }
      }
LABEL_41:
      functor = 0;
      if ( ptrs.Data.Size )
      {
        v25 = 0;
        do
        {
          v26 = v22 + 1;
          arg2.pStr = (const char *)(v53->RefCount + 8 * (int)ptrs.Data.Data[v25 + 2]);
          if ( v22 + 1 >= v22 )
          {
            if ( v26 >= newSA.Data.Policy.Capacity )
              Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
                newSA.Data.pHeap,
                v26 + (v26 >> 2));
          }
          else if ( v26 < newSA.Data.Policy.Capacity >> 1 )
          {
            Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
              newSA.Data.pHeap,
              v22 + 1);
          }
          ++v22;
          newSA.Data.Size = v26;
          if ( &newSA.Data.Data[v26] != (long double *)8 )
            newSA.Data.Data[v26 - 1] = *(double *)arg2.pStr;
          v25 += 4;
          ++functor;
        }
        while ( functor < ptrs.Data.Size );
      }
    }
    vc.__vftable = (Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
LABEL_88:
    if ( (flags & 8) != 0 )
    {
      v39 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)currObj->pTraits.pObject;
      v40 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc(v39);
      v41 = v40;
      if ( v40 )
      {
        Scaleform::GFx::AS3::Instances::fl::Object::Object(v40, v39);
        v41->__vftable = (Scaleform::GFx::AS3::Instances::fl::Object_vtbl *)&Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::`vftable';
        pVM = v39->pVM;
        v43 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *)pVM->MHeap;
        LOBYTE(v41[1]._pRCC) = 0;
        v41[1].pNext = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)pVM;
        v41[1].__vftable = (Scaleform::GFx::AS3::Instances::fl::Object_vtbl *)&Scaleform::GFx::AS3::VectorBase<double>::`vftable';
        v41[1].pPrev = 0;
        v41[1].RefCount = 0;
        v41[1].pTraits.pObject = 0;
        v41[1].DynAttrs.mHash.pTable = v43;
      }
      else
      {
        v41 = 0;
      }
      Scaleform::GFx::AS3::VectorBase<double>::Append((Scaleform::GFx::AS3::VectorBase<double> *)&v41[1], &newSA);
      Scaleform::GFx::AS3::Value::Pick(result, v41);
    }
    else
    {
      v44 = v53[1].pData;
      p_RefCount = &v53->RefCount;
      if ( v22 >= v53->HashFlags )
      {
        if ( v22 >= v53->Size )
          Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&v53->RefCount,
            v44,
            v22 + (v22 >> 2));
      }
      else if ( v22 < v53->Size >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&v53->RefCount,
          v44,
          v22);
      }
      v46 = 0;
      for ( p_RefCount[1] = v22; v46 < p_RefCount[1]; ++v46 )
        *(double *)(*p_RefCount + 8 * v46) = newSA.Data.Data[v46];
      Scaleform::GFx::AS3::Value::Assign(result, currObj);
    }
    ((void (__stdcall *)(long double *))Scaleform::Memory::pGlobalHeap->Free)(newSA.Data.Data);
LABEL_102:
    if ( (compareFunction.Flags & 0x1F) <= 9 )
      return;
    if ( (compareFunction.Flags & 0x200) != 0 )
      goto LABEL_29;
    goto LABEL_104;
  }
  VMRef = this->VMRef;
  v8 = currObj->pTraits.pObject->pVM->TraitsNumber.pObject;
  v9 = Scaleform::GFx::AS3::VM::GetValueTraits(VMRef, argv + 1);
  v10 = v8->GetName(v8, (Scaleform::GFx::ASString *)&functor)->pNode->pData;
  v48.Size = (unsigned int)v10;
  if ( v10 )
    strlen(v10);
  v48.pStr = (const char *)&arg2;
  v14 = **(const char ***)((int (__thiscall *)(Scaleform::GFx::AS3::Traits *))v9->GetName)(v9);
  v47.pStr = v14;
  if ( v14 )
  {
LABEL_19:
    v15 = strlen(v14);
    goto LABEL_21;
  }
LABEL_20:
  v15 = 0;
LABEL_21:
  v47.Size = v15;
  Scaleform::GFx::AS3::VM::Error::Error(
    (Scaleform::GFx::AS3::VM::Error *)&vc,
    eCheckTypeFailedError,
    (Scaleform::String)VMRef,
    v47,
    v48);
  Scaleform::GFx::AS3::VM::ThrowTypeError(VMRef, v16);
  v17 = (Scaleform::GFx::ASStringNode *)vc.Ptrs;
  --vc.Ptrs->Data.pHeap;
  if ( !v17->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  v18 = v53;
  --v53->RefCount;
  if ( !v18->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  v19 = (Scaleform::GFx::ASStringNode *)functor;
  --*(_DWORD *)(functor + 12);
  if ( !v19->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  if ( (compareFunction.Flags & 0x1F) > 9 )
  {
    if ( (compareFunction.Flags & 0x200) != 0 )
    {
LABEL_29:
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&compareFunction);
      return;
    }
LABEL_104:
    Scaleform::GFx::AS3::Value::ReleaseInternal(&compareFunction);
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<long>::Sort<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int>(
        Scaleform::GFx::AS3::VectorBase<long> *this,
        Scaleform::GFx::ASStringNode *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::ASStringNode *currObj)
{
  const Scaleform::GFx::AS3::Value *v5; // ebp
  unsigned int v6; // esi
  Scaleform::GFx::AS3::VectorBase<long> *v7; // ebx
  unsigned int v8; // eax
  Scaleform::GFx::AS3::Value *v9; // ebp
  Scaleform::GFx::AS3::VM *VMRef; // edi
  Scaleform::GFx::AS3::ClassTraits::fl::int_ *v11; // esi
  Scaleform::GFx::AS3::Traits *v12; // ebp
  const char *v13; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::int_ *v14; // esi
  Scaleform::GFx::AS3::Traits *ValueTraits; // ebp
  const char *pData; // eax
  const char *v17; // eax
  unsigned int v18; // eax
  const Scaleform::GFx::AS3::VM::Error *v19; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v21; // eax
  Scaleform::GFx::ASStringNode *v22; // eax
  const Scaleform::MemoryHeap *pLower; // edx
  unsigned int v24; // edi
  unsigned int v25; // ecx
  double *v26; // edx
  int v27; // ebp
  unsigned int v28; // esi
  int *v29; // ebx
  int v30; // esi
  Scaleform::ArrayDH<long const *,2,Scaleform::ArrayDefaultPolicy> *v31; // eax
  Scaleform::ArrayDH<long const *,2,Scaleform::ArrayDefaultPolicy> *v32; // ebp
  unsigned int v33; // esi
  int *v34; // ebx
  Scaleform::GFx::AS3::VectorBase<long>::ValuePtrCollector_vtbl *v35; // esi
  Scaleform::ArrayDH<long const *,2,Scaleform::ArrayDefaultPolicy> *v36; // ebp
  Scaleform::GFx::ASStringNode *v37; // ecx
  int v39; // esi
  unsigned int v40; // ebp
  int *v41; // ebx
  unsigned int v42; // esi
  Scaleform::GFx::AS3::InstanceTraits::Traits *Size; // edi
  Scaleform::GFx::AS3::Instances::fl::Object *v44; // eax
  Scaleform::GFx::AS3::Instances::fl::Object *v45; // esi
  Scaleform::GFx::AS3::VM *pVM; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *MHeap; // ecx
  const Scaleform::MemoryHeap *pHeap; // eax
  unsigned int v49; // eax
  Scaleform::StringDataPtr v50; // [esp-10h] [ebp-74h]
  Scaleform::StringDataPtr v51; // [esp-8h] [ebp-6Ch]
  Scaleform::GFx::AS3::VectorBase<long>::CompareValuePtr v52; // [esp-8h] [ebp-6Ch]
  Scaleform::GFx::AS3::Impl::CompareAsStringInd v53; // [esp-4h] [ebp-68h]
  int flags; // [esp+10h] [ebp-54h] BYREF
  Scaleform::GFx::AS3::VectorBase<long> *v55; // [esp+14h] [ebp-50h]
  Scaleform::GFx::AS3::VectorBase<long>::ValuePtrCollector vc; // [esp+18h] [ebp-4Ch] BYREF
  int v57; // [esp+20h] [ebp-44h]
  Scaleform::GFx::ASStringNode *v58; // [esp+24h] [ebp-40h]
  Scaleform::GFx::AS3::VM::Error v59; // [esp+28h] [ebp-3Ch] BYREF
  Scaleform::GFx::AS3::VectorBase<long>::ValuePtrCollector *p_vc; // [esp+30h] [ebp-34h]
  Scaleform::ArrayDH<long,2,Scaleform::ArrayDefaultPolicy> newSA; // [esp+34h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value compareFunction; // [esp+44h] [ebp-20h] BYREF
  Scaleform::ArrayDH<long const *,2,Scaleform::ArrayDefaultPolicy> ptrs; // [esp+54h] [ebp-10h] BYREF

  v5 = argv;
  v6 = argc;
  v7 = this;
  v55 = this;
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
      VMRef = v7->VMRef;
      v14 = *(Scaleform::GFx::AS3::ClassTraits::fl::int_ **)(*(_DWORD *)(currObj->Size + 64) + 312);
      ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(VMRef, v5);
      pData = v14->GetName(v14, (Scaleform::GFx::ASString *)&currObj)->pNode->pData;
      v51.Size = (unsigned int)pData;
      if ( pData )
        strlen(pData);
      v51.pStr = (const char *)&argc;
      v17 = **(const char ***)((int (__thiscall *)(Scaleform::GFx::AS3::Traits *))ValueTraits->GetName)(ValueTraits);
      v50.pStr = v17;
      if ( v17 )
        goto LABEL_19;
      goto LABEL_20;
    }
  }
  if ( v6 > 1 )
  {
    v9 = (Scaleform::GFx::AS3::Value *)&v5[1];
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(
            v9,
            (Scaleform::GFx::AS3::CheckResult *)&argc,
            (Scaleform::GFx::AS3::Value::V1U *)&flags)->Result )
    {
      VMRef = v7->VMRef;
      v11 = *(Scaleform::GFx::AS3::ClassTraits::fl::int_ **)(*(_DWORD *)(currObj->Size + 64) + 312);
      v12 = Scaleform::GFx::AS3::VM::GetValueTraits(VMRef, v9);
      v13 = v11->GetName(v11, (Scaleform::GFx::ASString *)&currObj)->pNode->pData;
      v51.Size = (unsigned int)v13;
      if ( v13 )
        strlen(v13);
      v51.pStr = (const char *)&argc;
      v17 = **(const char ***)((int (__thiscall *)(Scaleform::GFx::AS3::Traits *))v12->GetName)(v12);
      v50.pStr = v17;
      if ( v17 )
      {
LABEL_19:
        v18 = strlen(v17);
LABEL_21:
        v50.Size = v18;
        Scaleform::GFx::AS3::VM::Error::Error(&v59, eCheckTypeFailedError, (Scaleform::String)VMRef, v50, v51);
        Scaleform::GFx::AS3::VM::ThrowTypeError(VMRef, v19);
        pNode = v59.Message.pNode;
        --v59.Message.pNode->RefCount;
        if ( !pNode->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        if ( !--result->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(result);
        v21 = currObj;
        --currObj->RefCount;
        if ( !v21->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v21);
        goto LABEL_27;
      }
LABEL_20:
      v18 = 0;
      goto LABEL_21;
    }
  }
  v22 = (Scaleform::GFx::ASStringNode *)v7->VMRef;
  pLower = (const Scaleform::MemoryHeap *)v22[1].pLower;
  v24 = 0;
  memset(&newSA, 0, 12);
  newSA.Data.pHeap = pLower;
  if ( (compareFunction.Flags & 0x1F) != 0
    && ((compareFunction.Flags & 0x1F) - 12 > 3 || compareFunction.value.VS._1.VInt) )
  {
    ptrs.Data.pHeap = pLower;
    memset(&ptrs, 0, 12);
    vc.__vftable = (Scaleform::GFx::AS3::VectorBase<long>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector::`vftable';
    vc.Ptrs = &ptrs;
    Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::ForEach(
      (Scaleform::GFx::AS3::VectorBase<unsigned long> *)v7,
      (Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc *)&vc);
    v52 = (Scaleform::GFx::AS3::VectorBase<long>::CompareValuePtr)__PAIR64__(&compareFunction, v7->VMRef);
    v59.ID = (Scaleform::GFx::AS3::VM::ErrorID)v7->VMRef;
    v59.Message.pNode = (Scaleform::GFx::ASStringNode *)&compareFunction;
    Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<long const *,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::VectorBase<long>::CompareValuePtr>(
      &ptrs,
      0,
      ptrs.Data.Size,
      v52);
    if ( (flags & 4) != 0 )
    {
      v39 = 1;
      if ( ptrs.Data.Size > 1 )
      {
        while ( !Scaleform::GFx::AS3::VectorBase<long>::CompareValuePtr::Equal(
                   (Scaleform::GFx::AS3::VectorBase<long>::CompareValuePtr *)&v59,
                   (Scaleform::GFx::AS3::Value::V1U *)ptrs.Data.Data[v39 - 1],
                   (Scaleform::GFx::AS3::Value::V1U *)ptrs.Data.Data[v39]) )
        {
          if ( ++v39 >= ptrs.Data.Size )
            goto LABEL_78;
        }
        Scaleform::GFx::AS3::Value::SetNull((Scaleform::GFx::AS3::Value *)result);
        vc.__vftable = (Scaleform::GFx::AS3::VectorBase<long>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, 0);
        goto LABEL_104;
      }
    }
LABEL_78:
    v40 = 0;
    if ( ptrs.Data.Size )
    {
      do
      {
        v41 = (int *)ptrs.Data.Data[v40];
        v42 = v24 + 1;
        if ( v24 + 1 >= v24 )
        {
          if ( v42 >= newSA.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
              newSA.Data.pHeap,
              v42 + (v42 >> 2));
        }
        else if ( v42 < newSA.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
            newSA.Data.pHeap,
            v24 + 1);
        }
        ++v24;
        newSA.Data.Size = v42;
        if ( &newSA.Data.Data[v42] != (int *)4 )
          newSA.Data.Data[v42 - 1] = *v41;
        ++v40;
      }
      while ( v40 < ptrs.Data.Size );
      v7 = v55;
    }
    vc.__vftable = (Scaleform::GFx::AS3::VectorBase<long>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
  }
  else if ( (flags & 0x10) != 0 )
  {
    ptrs.Data.pHeap = pLower;
    memset(&ptrs, 0, 12);
    vc.__vftable = (Scaleform::GFx::AS3::VectorBase<long>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<long>::Value2NumberCollector::`vftable';
    vc.Ptrs = &ptrs;
    Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::ForEach(
      (Scaleform::GFx::AS3::VectorBase<unsigned long> *)v7,
      (Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc *)&vc);
    LOBYTE(argc) = (flags & 2) != 0;
    Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareAsNumberInd>(
      (Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *)&ptrs,
      0,
      ptrs.Data.Size,
      (Scaleform::GFx::AS3::Impl::CompareAsNumberInd)argc);
    if ( (flags & 4) != 0 )
    {
      v25 = 1;
      if ( ptrs.Data.Size > 1 )
      {
        v26 = (double *)(ptrs.Data.Data + 4);
        while ( *v26 != *(v26 - 2) )
        {
          ++v25;
          v26 += 2;
          if ( v25 >= ptrs.Data.Size )
            goto LABEL_41;
        }
        Scaleform::GFx::AS3::Value::SetSInt32((Scaleform::GFx::AS3::Value *)result, 0);
        vc.__vftable = (Scaleform::GFx::AS3::VectorBase<long>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, 0);
LABEL_27:
        if ( (compareFunction.Flags & 0x1F) <= 9 )
          return;
        if ( (compareFunction.Flags & 0x200) != 0 )
          goto LABEL_29;
        goto LABEL_106;
      }
    }
LABEL_41:
    argc = 0;
    if ( ptrs.Data.Size )
    {
      v27 = 0;
      do
      {
        v28 = v24 + 1;
        v29 = &v55->ValueA.Data.Data[(int)ptrs.Data.Data[v27 + 2]];
        if ( v24 + 1 >= v24 )
        {
          if ( v28 >= newSA.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
              newSA.Data.pHeap,
              v28 + (v28 >> 2));
        }
        else if ( v28 < newSA.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
            newSA.Data.pHeap,
            v24 + 1);
        }
        ++v24;
        newSA.Data.Size = v28;
        if ( &newSA.Data.Data[v28] != (int *)4 )
          newSA.Data.Data[v28 - 1] = *v29;
        v27 += 4;
        ++argc;
      }
      while ( argc < ptrs.Data.Size );
    }
    vc.__vftable = (Scaleform::GFx::AS3::VectorBase<long>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
    v7 = v55;
  }
  else
  {
    v58 = v22[1].pLower;
    p_vc = &vc;
    vc.__vftable = 0;
    vc.Ptrs = 0;
    v57 = 0;
    v59.ID = (Scaleform::GFx::AS3::VM::ErrorID)&Scaleform::GFx::AS3::VectorBase<long>::Value2StrCollector::`vftable';
    v59.Message.pNode = v22;
    Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::ForEach(
      (Scaleform::GFx::AS3::VectorBase<unsigned long> *)v7,
      (Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc *)&v59);
    LOBYTE(argc) = (flags & 2) != 0;
    BYTE1(argc) = flags & 1;
    *(_WORD *)&v53.Desc = argc;
    v53.UseLocale = (flags & 0x400) != 0;
    BYTE2(argc) = v53.UseLocale;
    Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareAsStringInd>(
      (Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *)&vc,
      0,
      (unsigned int)vc.Ptrs,
      v53);
    if ( (flags & 4) != 0 )
    {
      v30 = 1;
      if ( vc.Ptrs > (Scaleform::ArrayDH<long const *,2,Scaleform::ArrayDefaultPolicy> *)1 )
      {
        while ( Scaleform::GFx::AS3::Impl::CompareAsString::Compare(
                  (Scaleform::GFx::AS3::Impl::CompareAsStringInd *)&argc,
                  (const Scaleform::GFx::ASString *)&vc.__vftable[v30 - 1],
                  (const Scaleform::GFx::ASString *)&vc.__vftable[v30]) )
        {
          if ( (Scaleform::ArrayDH<long const *,2,Scaleform::ArrayDefaultPolicy> *)++v30 >= vc.Ptrs )
            goto LABEL_57;
        }
        Scaleform::GFx::AS3::Value::SetNull((Scaleform::GFx::AS3::Value *)result);
        v59.ID = (Scaleform::GFx::AS3::VM::ErrorID)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&vc);
        ((void (__stdcall *)(_DWORD))Scaleform::Memory::pGlobalHeap->Free)(0);
        goto LABEL_104;
      }
    }
LABEL_57:
    v31 = vc.Ptrs;
    v32 = 0;
    if ( vc.Ptrs )
    {
      do
      {
        v33 = v24 + 1;
        v34 = &v55->ValueA.Data.Data[(int)vc.__vftable[(_DWORD)v32].operator()];
        if ( v24 + 1 >= v24 )
        {
          if ( v33 >= newSA.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
              newSA.Data.pHeap,
              v33 + (v33 >> 2));
        }
        else if ( v33 < newSA.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
            newSA.Data.pHeap,
            v24 + 1);
        }
        ++v24;
        newSA.Data.Size = v33;
        if ( &newSA.Data.Data[v33] != (int *)4 )
          newSA.Data.Data[v33 - 1] = *v34;
        v31 = vc.Ptrs;
        v32 = (Scaleform::ArrayDH<long const *,2,Scaleform::ArrayDefaultPolicy> *)((char *)v32 + 1);
      }
      while ( v32 < vc.Ptrs );
      v7 = v55;
    }
    v59.ID = (Scaleform::GFx::AS3::VM::ErrorID)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
    v35 = &vc.__vftable[(int)v31 - 1];
    if ( v31 )
    {
      v36 = v31;
      do
      {
        v37 = (Scaleform::GFx::ASStringNode *)v35->~Scaleform::GFx::AS3::VectorBase<long>::ValuePtrCollector;
        if ( (*((_DWORD *)v35->~Scaleform::GFx::AS3::VectorBase<long>::ValuePtrCollector + 3))-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v37);
        --v35;
        v36 = (Scaleform::ArrayDH<long const *,2,Scaleform::ArrayDefaultPolicy> *)((char *)v36 - 1);
      }
      while ( v36 );
    }
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, vc.__vftable);
  }
  if ( (flags & 8) != 0 )
  {
    Size = (Scaleform::GFx::AS3::InstanceTraits::Traits *)currObj->Size;
    v44 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc(Size);
    v45 = v44;
    if ( v44 )
    {
      Scaleform::GFx::AS3::Instances::fl::Object::Object(v44, Size);
      v45->__vftable = (Scaleform::GFx::AS3::Instances::fl::Object_vtbl *)&Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::`vftable';
      pVM = Size->pVM;
      MHeap = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *)pVM->MHeap;
      LOBYTE(v45[1]._pRCC) = 0;
      v45[1].pNext = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)pVM;
      v45[1].__vftable = (Scaleform::GFx::AS3::Instances::fl::Object_vtbl *)&Scaleform::GFx::AS3::VectorBase<long>::`vftable';
      v45[1].pPrev = 0;
      v45[1].RefCount = 0;
      v45[1].pTraits.pObject = 0;
      v45[1].DynAttrs.mHash.pTable = MHeap;
    }
    else
    {
      v45 = 0;
    }
    Scaleform::GFx::AS3::VectorBase<unsigned long>::Append(
      (Scaleform::GFx::AS3::VectorBase<unsigned long> *)&v45[1],
      (const Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> *)&newSA);
    Scaleform::GFx::AS3::Value::Pick((Scaleform::GFx::AS3::Value *)result, v45);
  }
  else
  {
    pHeap = v7->ValueA.Data.pHeap;
    if ( v24 >= v7->ValueA.Data.Size )
    {
      if ( v24 >= v7->ValueA.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&v7->ValueA,
          pHeap,
          v24 + (v24 >> 2));
    }
    else if ( v24 < v7->ValueA.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&v7->ValueA,
        pHeap,
        v24);
    }
    v49 = 0;
    for ( v7->ValueA.Data.Size = v24; v49 < v7->ValueA.Data.Size; ++v49 )
      v7->ValueA.Data.Data[v49] = newSA.Data.Data[v49];
    Scaleform::GFx::AS3::Value::Assign((Scaleform::GFx::AS3::Value *)result, (Scaleform::GFx::AS3::Object *)currObj);
  }
  ((void (__stdcall *)(int *))Scaleform::Memory::pGlobalHeap->Free)(newSA.Data.Data);
LABEL_104:
  if ( (compareFunction.Flags & 0x1F) <= 9 )
    return;
  if ( (compareFunction.Flags & 0x200) != 0 )
  {
LABEL_29:
    Scaleform::GFx::AS3::Value::ReleaseWeakRef(&compareFunction);
    return;
  }
LABEL_106:
  Scaleform::GFx::AS3::Value::ReleaseInternal(&compareFunction);
}


void __thiscall Scaleform::GFx::AS3::VectorBase<unsigned long>::Sort<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        Scaleform::GFx::ASStringNode *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::ASStringNode *currObj)
{
  const Scaleform::GFx::AS3::Value *v5; // ebp
  unsigned int v6; // esi
  Scaleform::GFx::AS3::VectorBase<unsigned long> *v7; // ebx
  unsigned int v8; // eax
  Scaleform::GFx::AS3::Value *v9; // ebp
  Scaleform::GFx::AS3::VM *VMRef; // edi
  Scaleform::GFx::AS3::ClassTraits::fl::uint *v11; // esi
  Scaleform::GFx::AS3::Traits *v12; // ebp
  const char *v13; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::uint *v14; // esi
  Scaleform::GFx::AS3::Traits *ValueTraits; // ebp
  const char *pData; // eax
  const char *v17; // eax
  unsigned int v18; // eax
  const Scaleform::GFx::AS3::VM::Error *v19; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v21; // eax
  Scaleform::GFx::ASStringNode *v22; // eax
  const Scaleform::MemoryHeap *pLower; // edx
  unsigned int v24; // edi
  unsigned int v25; // ecx
  double *v26; // edx
  int v27; // ebp
  unsigned int v28; // esi
  unsigned int *v29; // ebx
  int v30; // esi
  Scaleform::ArrayDH<unsigned long const *,2,Scaleform::ArrayDefaultPolicy> *v31; // eax
  Scaleform::ArrayDH<unsigned long const *,2,Scaleform::ArrayDefaultPolicy> *v32; // ebp
  unsigned int v33; // esi
  unsigned int *v34; // ebx
  Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector_vtbl *v35; // esi
  Scaleform::ArrayDH<unsigned long const *,2,Scaleform::ArrayDefaultPolicy> *v36; // ebp
  Scaleform::GFx::ASStringNode *v37; // ecx
  int v39; // esi
  unsigned int v40; // ebp
  unsigned int *v41; // ebx
  unsigned int v42; // esi
  Scaleform::GFx::AS3::InstanceTraits::Traits *Size; // edi
  Scaleform::GFx::AS3::Instances::fl::Object *v44; // eax
  Scaleform::GFx::AS3::Instances::fl::Object *v45; // esi
  Scaleform::GFx::AS3::VM *pVM; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *MHeap; // ecx
  const Scaleform::MemoryHeap *pHeap; // eax
  unsigned int v49; // eax
  Scaleform::StringDataPtr v50; // [esp-10h] [ebp-74h]
  Scaleform::StringDataPtr v51; // [esp-8h] [ebp-6Ch]
  Scaleform::GFx::AS3::VectorBase<unsigned long>::CompareValuePtr v52; // [esp-8h] [ebp-6Ch]
  Scaleform::GFx::AS3::Impl::CompareAsStringInd v53; // [esp-4h] [ebp-68h]
  int flags; // [esp+10h] [ebp-54h] BYREF
  Scaleform::GFx::AS3::VectorBase<unsigned long> *v55; // [esp+14h] [ebp-50h]
  Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector vc; // [esp+18h] [ebp-4Ch] BYREF
  int v57; // [esp+20h] [ebp-44h]
  Scaleform::GFx::ASStringNode *v58; // [esp+24h] [ebp-40h]
  Scaleform::GFx::AS3::VM::Error v59; // [esp+28h] [ebp-3Ch] BYREF
  Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector *p_vc; // [esp+30h] [ebp-34h]
  Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> newSA; // [esp+34h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value compareFunction; // [esp+44h] [ebp-20h] BYREF
  Scaleform::ArrayDH<unsigned long const *,2,Scaleform::ArrayDefaultPolicy> ptrs; // [esp+54h] [ebp-10h] BYREF

  v5 = argv;
  v6 = argc;
  v7 = this;
  v55 = this;
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
      VMRef = v7->VMRef;
      v14 = *(Scaleform::GFx::AS3::ClassTraits::fl::uint **)(*(_DWORD *)(currObj->Size + 64) + 316);
      ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(VMRef, v5);
      pData = v14->GetName(v14, (Scaleform::GFx::ASString *)&currObj)->pNode->pData;
      v51.Size = (unsigned int)pData;
      if ( pData )
        strlen(pData);
      v51.pStr = (const char *)&argc;
      v17 = **(const char ***)((int (__thiscall *)(Scaleform::GFx::AS3::Traits *))ValueTraits->GetName)(ValueTraits);
      v50.pStr = v17;
      if ( v17 )
        goto LABEL_19;
      goto LABEL_20;
    }
  }
  if ( v6 > 1 )
  {
    v9 = (Scaleform::GFx::AS3::Value *)&v5[1];
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(
            v9,
            (Scaleform::GFx::AS3::CheckResult *)&argc,
            (Scaleform::GFx::AS3::Value::V1U *)&flags)->Result )
    {
      VMRef = v7->VMRef;
      v11 = *(Scaleform::GFx::AS3::ClassTraits::fl::uint **)(*(_DWORD *)(currObj->Size + 64) + 316);
      v12 = Scaleform::GFx::AS3::VM::GetValueTraits(VMRef, v9);
      v13 = v11->GetName(v11, (Scaleform::GFx::ASString *)&currObj)->pNode->pData;
      v51.Size = (unsigned int)v13;
      if ( v13 )
        strlen(v13);
      v51.pStr = (const char *)&argc;
      v17 = **(const char ***)((int (__thiscall *)(Scaleform::GFx::AS3::Traits *))v12->GetName)(v12);
      v50.pStr = v17;
      if ( v17 )
      {
LABEL_19:
        v18 = strlen(v17);
LABEL_21:
        v50.Size = v18;
        Scaleform::GFx::AS3::VM::Error::Error(&v59, eCheckTypeFailedError, (Scaleform::String)VMRef, v50, v51);
        Scaleform::GFx::AS3::VM::ThrowTypeError(VMRef, v19);
        pNode = v59.Message.pNode;
        --v59.Message.pNode->RefCount;
        if ( !pNode->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        if ( !--result->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(result);
        v21 = currObj;
        --currObj->RefCount;
        if ( !v21->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v21);
        goto LABEL_27;
      }
LABEL_20:
      v18 = 0;
      goto LABEL_21;
    }
  }
  v22 = (Scaleform::GFx::ASStringNode *)v7->VMRef;
  pLower = (const Scaleform::MemoryHeap *)v22[1].pLower;
  v24 = 0;
  memset(&newSA, 0, 12);
  newSA.Data.pHeap = pLower;
  if ( (compareFunction.Flags & 0x1F) != 0
    && ((compareFunction.Flags & 0x1F) - 12 > 3 || compareFunction.value.VS._1.VInt) )
  {
    ptrs.Data.pHeap = pLower;
    memset(&ptrs, 0, 12);
    vc.__vftable = (Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector::`vftable';
    vc.Ptrs = &ptrs;
    Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::ForEach(v7, &vc);
    v52 = (Scaleform::GFx::AS3::VectorBase<unsigned long>::CompareValuePtr)__PAIR64__(&compareFunction, v7->VMRef);
    v59.ID = (Scaleform::GFx::AS3::VM::ErrorID)v7->VMRef;
    v59.Message.pNode = (Scaleform::GFx::ASStringNode *)&compareFunction;
    Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<unsigned long const *,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::VectorBase<unsigned long>::CompareValuePtr>(
      &ptrs,
      0,
      ptrs.Data.Size,
      v52);
    if ( (flags & 4) != 0 )
    {
      v39 = 1;
      if ( ptrs.Data.Size > 1 )
      {
        while ( !Scaleform::GFx::AS3::VectorBase<unsigned long>::CompareValuePtr::Equal(
                   (Scaleform::GFx::AS3::VectorBase<unsigned long>::CompareValuePtr *)&v59,
                   (Scaleform::GFx::AS3::Value::V1U *)ptrs.Data.Data[v39 - 1],
                   (Scaleform::GFx::AS3::Value::V1U *)ptrs.Data.Data[v39]) )
        {
          if ( ++v39 >= ptrs.Data.Size )
            goto LABEL_78;
        }
        Scaleform::GFx::AS3::Value::SetNull((Scaleform::GFx::AS3::Value *)result);
        vc.__vftable = (Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, 0);
        goto LABEL_104;
      }
    }
LABEL_78:
    v40 = 0;
    if ( ptrs.Data.Size )
    {
      do
      {
        v41 = (unsigned int *)ptrs.Data.Data[v40];
        v42 = v24 + 1;
        if ( v24 + 1 >= v24 )
        {
          if ( v42 >= newSA.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
              newSA.Data.pHeap,
              v42 + (v42 >> 2));
        }
        else if ( v42 < newSA.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
            newSA.Data.pHeap,
            v24 + 1);
        }
        ++v24;
        newSA.Data.Size = v42;
        if ( &newSA.Data.Data[v42] != (unsigned int *)4 )
          newSA.Data.Data[v42 - 1] = *v41;
        ++v40;
      }
      while ( v40 < ptrs.Data.Size );
      v7 = v55;
    }
    vc.__vftable = (Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
  }
  else if ( (flags & 0x10) != 0 )
  {
    ptrs.Data.pHeap = pLower;
    memset(&ptrs, 0, 12);
    vc.__vftable = (Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::Value2NumberCollector::`vftable';
    vc.Ptrs = &ptrs;
    Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::ForEach(v7, &vc);
    LOBYTE(argc) = (flags & 2) != 0;
    Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareAsNumberInd>(
      (Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *)&ptrs,
      0,
      ptrs.Data.Size,
      (Scaleform::GFx::AS3::Impl::CompareAsNumberInd)argc);
    if ( (flags & 4) != 0 )
    {
      v25 = 1;
      if ( ptrs.Data.Size > 1 )
      {
        v26 = (double *)(ptrs.Data.Data + 4);
        while ( *v26 != *(v26 - 2) )
        {
          ++v25;
          v26 += 2;
          if ( v25 >= ptrs.Data.Size )
            goto LABEL_41;
        }
        Scaleform::GFx::AS3::Value::SetSInt32((Scaleform::GFx::AS3::Value *)result, 0);
        vc.__vftable = (Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, 0);
LABEL_27:
        if ( (compareFunction.Flags & 0x1F) <= 9 )
          return;
        if ( (compareFunction.Flags & 0x200) != 0 )
          goto LABEL_29;
        goto LABEL_106;
      }
    }
LABEL_41:
    argc = 0;
    if ( ptrs.Data.Size )
    {
      v27 = 0;
      do
      {
        v28 = v24 + 1;
        v29 = &v55->ValueA.Data.Data[(int)ptrs.Data.Data[v27 + 2]];
        if ( v24 + 1 >= v24 )
        {
          if ( v28 >= newSA.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
              newSA.Data.pHeap,
              v28 + (v28 >> 2));
        }
        else if ( v28 < newSA.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
            newSA.Data.pHeap,
            v24 + 1);
        }
        ++v24;
        newSA.Data.Size = v28;
        if ( &newSA.Data.Data[v28] != (unsigned int *)4 )
          newSA.Data.Data[v28 - 1] = *v29;
        v27 += 4;
        ++argc;
      }
      while ( argc < ptrs.Data.Size );
    }
    vc.__vftable = (Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptrs.Data.Data);
    v7 = v55;
  }
  else
  {
    v58 = v22[1].pLower;
    p_vc = &vc;
    vc.__vftable = 0;
    vc.Ptrs = 0;
    v57 = 0;
    v59.ID = (Scaleform::GFx::AS3::VM::ErrorID)&Scaleform::GFx::AS3::VectorBase<unsigned long>::Value2StrCollector::`vftable';
    v59.Message.pNode = v22;
    Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::ForEach(
      v7,
      (Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc *)&v59);
    LOBYTE(argc) = (flags & 2) != 0;
    BYTE1(argc) = flags & 1;
    *(_WORD *)&v53.Desc = argc;
    v53.UseLocale = (flags & 0x400) != 0;
    BYTE2(argc) = v53.UseLocale;
    Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareAsStringInd>(
      (Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *)&vc,
      0,
      (unsigned int)vc.Ptrs,
      v53);
    if ( (flags & 4) != 0 )
    {
      v30 = 1;
      if ( vc.Ptrs > (Scaleform::ArrayDH<unsigned long const *,2,Scaleform::ArrayDefaultPolicy> *)1 )
      {
        while ( Scaleform::GFx::AS3::Impl::CompareAsString::Compare(
                  (Scaleform::GFx::AS3::Impl::CompareAsStringInd *)&argc,
                  (const Scaleform::GFx::ASString *)&vc.__vftable[v30 - 1],
                  (const Scaleform::GFx::ASString *)&vc.__vftable[v30]) )
        {
          if ( (Scaleform::ArrayDH<unsigned long const *,2,Scaleform::ArrayDefaultPolicy> *)++v30 >= vc.Ptrs )
            goto LABEL_57;
        }
        Scaleform::GFx::AS3::Value::SetNull((Scaleform::GFx::AS3::Value *)result);
        v59.ID = (Scaleform::GFx::AS3::VM::ErrorID)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&vc);
        ((void (__stdcall *)(_DWORD))Scaleform::Memory::pGlobalHeap->Free)(0);
        goto LABEL_104;
      }
    }
LABEL_57:
    v31 = vc.Ptrs;
    v32 = 0;
    if ( vc.Ptrs )
    {
      do
      {
        v33 = v24 + 1;
        v34 = &v55->ValueA.Data.Data[(int)vc.__vftable[(_DWORD)v32].operator()];
        if ( v24 + 1 >= v24 )
        {
          if ( v33 >= newSA.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
              newSA.Data.pHeap,
              v33 + (v33 >> 2));
        }
        else if ( v33 < newSA.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&newSA,
            newSA.Data.pHeap,
            v24 + 1);
        }
        ++v24;
        newSA.Data.Size = v33;
        if ( &newSA.Data.Data[v33] != (unsigned int *)4 )
          newSA.Data.Data[v33 - 1] = *v34;
        v31 = vc.Ptrs;
        v32 = (Scaleform::ArrayDH<unsigned long const *,2,Scaleform::ArrayDefaultPolicy> *)((char *)v32 + 1);
      }
      while ( v32 < vc.Ptrs );
      v7 = v55;
    }
    v59.ID = (Scaleform::GFx::AS3::VM::ErrorID)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
    v35 = &vc.__vftable[(int)v31 - 1];
    if ( v31 )
    {
      v36 = v31;
      do
      {
        v37 = (Scaleform::GFx::ASStringNode *)v35->~Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector;
        if ( (*((_DWORD *)v35->~Scaleform::GFx::AS3::VectorBase<unsigned long>::ValuePtrCollector + 3))-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v37);
        --v35;
        v36 = (Scaleform::ArrayDH<unsigned long const *,2,Scaleform::ArrayDefaultPolicy> *)((char *)v36 - 1);
      }
      while ( v36 );
    }
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, vc.__vftable);
  }
  if ( (flags & 8) != 0 )
  {
    Size = (Scaleform::GFx::AS3::InstanceTraits::Traits *)currObj->Size;
    v44 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc(Size);
    v45 = v44;
    if ( v44 )
    {
      Scaleform::GFx::AS3::Instances::fl::Object::Object(v44, Size);
      v45->__vftable = (Scaleform::GFx::AS3::Instances::fl::Object_vtbl *)&Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::`vftable';
      pVM = Size->pVM;
      MHeap = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *)pVM->MHeap;
      LOBYTE(v45[1]._pRCC) = 0;
      v45[1].pNext = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)pVM;
      v45[1].__vftable = (Scaleform::GFx::AS3::Instances::fl::Object_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::`vftable';
      v45[1].pPrev = 0;
      v45[1].RefCount = 0;
      v45[1].pTraits.pObject = 0;
      v45[1].DynAttrs.mHash.pTable = MHeap;
    }
    else
    {
      v45 = 0;
    }
    Scaleform::GFx::AS3::VectorBase<unsigned long>::Append(
      (Scaleform::GFx::AS3::VectorBase<unsigned long> *)&v45[1],
      &newSA);
    Scaleform::GFx::AS3::Value::Pick((Scaleform::GFx::AS3::Value *)result, v45);
  }
  else
  {
    pHeap = v7->ValueA.Data.pHeap;
    if ( v24 >= v7->ValueA.Data.Size )
    {
      if ( v24 >= v7->ValueA.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&v7->ValueA,
          pHeap,
          v24 + (v24 >> 2));
    }
    else if ( v24 < v7->ValueA.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&v7->ValueA,
        pHeap,
        v24);
    }
    v49 = 0;
    for ( v7->ValueA.Data.Size = v24; v49 < v7->ValueA.Data.Size; ++v49 )
      v7->ValueA.Data.Data[v49] = newSA.Data.Data[v49];
    Scaleform::GFx::AS3::Value::Assign((Scaleform::GFx::AS3::Value *)result, (Scaleform::GFx::AS3::Object *)currObj);
  }
  ((void (__stdcall *)(unsigned int *))Scaleform::Memory::pGlobalHeap->Free)(newSA.Data.Data);
LABEL_104:
  if ( (compareFunction.Flags & 0x1F) <= 9 )
    return;
  if ( (compareFunction.Flags & 0x200) != 0 )
  {
LABEL_29:
    Scaleform::GFx::AS3::Value::ReleaseWeakRef(&compareFunction);
    return;
  }
LABEL_106:
  Scaleform::GFx::AS3::Value::ReleaseInternal(&compareFunction);
}
