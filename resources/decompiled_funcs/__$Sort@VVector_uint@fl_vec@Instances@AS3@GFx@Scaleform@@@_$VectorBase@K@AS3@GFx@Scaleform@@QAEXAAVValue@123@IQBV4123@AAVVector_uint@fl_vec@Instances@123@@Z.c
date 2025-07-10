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
