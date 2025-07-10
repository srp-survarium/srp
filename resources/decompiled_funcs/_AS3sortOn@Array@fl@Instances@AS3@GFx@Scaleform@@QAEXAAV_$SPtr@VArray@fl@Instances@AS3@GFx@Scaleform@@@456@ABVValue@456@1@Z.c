void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::AS3sortOn(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result,
        Scaleform::GFx::AS3::Value *fieldName,
        Scaleform::GFx::AS3::Value *options)
{
  Scaleform::GFx::AS3::VM *pVM; // eax
  Scaleform::MemoryHeap *MHeap; // ebx
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  unsigned int v8; // esi
  Scaleform::GFx::AS3::Impl::SparseArray *v9; // edi
  Scaleform::GFx::AS3::Value *v10; // eax
  unsigned int v11; // esi
  unsigned int v12; // eax
  Scaleform::GFx::AS3::Traits *v13; // eax
  Scaleform::GFx::AS3::Value::V1U v14; // esi
  int v15; // eax
  Scaleform::GFx::AS3::Impl::SparseArray *v16; // edi
  unsigned int v17; // esi
  Scaleform::GFx::AS3::Value *v18; // eax
  unsigned int i; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *v20; // esi
  Scaleform::GFx::AS3::Traits *v21; // eax
  unsigned int v22; // ebx
  Scaleform::GFx::AS3::Instances::fl::Array_vtbl *v23; // ebp
  int v24; // esi
  int v25; // ebx
  unsigned int v26; // eax
  const Scaleform::MemoryHeap *pHeap; // edi
  unsigned int v28; // esi
  Scaleform::GFx::AS3::Instances::fl::Array *v29; // ecx
  unsigned int RefCount; // eax
  unsigned int v31; // esi
  Scaleform::GFx::AS3::Impl::CompareOn *v32; // ecx
  int v33; // ebp
  Scaleform::GFx::AS3::Value *First; // edi
  const Scaleform::MemoryHeap *v35; // ebx
  unsigned int v36; // esi
  unsigned int v37; // esi
  Scaleform::GFx::AS3::Value *v38; // ecx
  unsigned int v39; // esi
  const Scaleform::MemoryHeap *v40; // ebx
  unsigned int v41; // edi
  Scaleform::GFx::AS3::Value *v42; // eax
  unsigned int v43; // ecx
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *v45; // ecx
  Scaleform::GFx::AS3::Instances::fl::Array *v46; // edi
  unsigned int v47; // edx
  Scaleform::GFx::AS3::Impl::SparseArray *p_SA; // esi
  Scaleform::HashDH<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>,2,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> > *p_ValueH; // edi
  Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // esi
  unsigned int v51; // edi
  Scaleform::Pair<double,unsigned long> *Data; // ebx
  unsigned int v53; // ebp
  Scaleform::Pair<double,unsigned long> *v54; // eax
  unsigned int j; // ebp
  unsigned int v56; // ebp
  int v57; // edi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> > *v58; // edi
  unsigned int ValueHLowInd; // eax
  unsigned int ValueHHighInd; // ecx
  void *v61; // eax
  unsigned int v62; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *pTable; // ebx
  Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *v64; // esi
  unsigned int v65; // edi
  unsigned int v66; // ebp
  Scaleform::Pair<double,unsigned long> *v67; // eax
  unsigned int k; // ebp
  unsigned int v69; // ebp
  int v70; // edi
  Scaleform::GFx::AS3::Instances::fl::Array *v71; // edi
  Scaleform::GFx::AS3::Instances::fl::Array *v72; // ecx
  unsigned int v73; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Impl::CompareOn v75; // [esp-Ch] [ebp-B8h]
  Scaleform::GFx::AS3::CheckResult v76; // [esp+13h] [ebp-99h] BYREF
  Scaleform::GFx::ASString tmp; // [esp+14h] [ebp-98h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> newArr; // [esp+18h] [ebp-94h] BYREF
  Scaleform::GFx::AS3::Impl::SparseArray newSA; // [esp+1Ch] [ebp-90h] BYREF
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> fields; // [esp+54h] [ebp-58h] BYREF
  Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> flags; // [esp+64h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::Instances::fl::Array *v82; // [esp+74h] [ebp-38h]
  Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2,Scaleform::ArrayDefaultPolicy> pairs; // [esp+78h] [ebp-34h] BYREF
  Scaleform::GFx::AS3::Impl::CompareOn functor; // [esp+88h] [ebp-24h] BYREF
  Scaleform::GFx::AS3::VM *v85; // [esp+94h] [ebp-18h]
  unsigned int size[2]; // [esp+98h] [ebp-14h] BYREF
  Scaleform::GFx::AS3::Impl::ValuePtrCollector vc; // [esp+A0h] [ebp-Ch] BYREF
  int v88; // [esp+A8h] [ebp-4h]

  pVM = this->pTraits.pObject->pVM;
  MHeap = pVM->MHeap;
  tmp.pNode = &pVM->StringManagerRef->pStringManager->EmptyStringNode;
  ++tmp.pNode->RefCount;
  pObject = this->pTraits.pObject;
  v82 = this;
  memset(&fields, 0, 12);
  fields.Data.pHeap = MHeap;
  memset(&flags, 0, 12);
  flags.Data.pHeap = MHeap;
  ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(pObject->pVM, fieldName);
  if ( ValueTraits->TraitsType != Traits_Array || (ValueTraits->Flags & 0x20) != 0 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2String(fieldName, &v76, &tmp)->Result )
      goto LABEL_168;
    Scaleform::GFx::AS3::Value::Value((Scaleform::GFx::AS3::Value *)&pairs, &tmp);
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &fields.Data,
      (Scaleform::GFx::AS3::Value *)&pairs);
    if ( ((int)pairs.Data.Data & 0x1F) > 9u )
    {
      if ( ((int)pairs.Data.Data & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&pairs);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&pairs);
    }
    goto LABEL_17;
  }
  v8 = 0;
  v9 = (Scaleform::GFx::AS3::Impl::SparseArray *)(fieldName->value.VS._1.VInt + 32);
  if ( !v9->Length )
  {
LABEL_17:
    v11 = fields.Data.Size;
    if ( fields.Data.Size >= flags.Data.Size )
    {
      if ( fields.Data.Size >= flags.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&flags,
          flags.Data.pHeap,
          fields.Data.Size + (fields.Data.Size >> 2));
    }
    else if ( fields.Data.Size < flags.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&flags,
        flags.Data.pHeap,
        fields.Data.Size);
    }
    v12 = 0;
    for ( flags.Data.Size = v11; v12 < flags.Data.Size; ++v12 )
      flags.Data.Data[v12] = 0;
    if ( (options->Flags & 0x1F) != 0 && ((options->Flags & 0x1F) - 12 > 3 || options->value.VS._1.VInt) )
    {
      v13 = Scaleform::GFx::AS3::VM::GetValueTraits(v82->pTraits.pObject->pVM, options);
      if ( v13->TraitsType != Traits_Array || (v13->Flags & 0x20) != 0 )
      {
        if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(options, &v76, (unsigned int *)&newArr)->Result )
          goto LABEL_168;
        for ( i = 0; i < flags.Data.Size; ++i )
          flags.Data.Data[i] = (unsigned int)newArr.pV;
      }
      else
      {
        v14 = options->value.VS._1;
        v15 = *(_DWORD *)(v14.VInt + 32);
        v16 = (Scaleform::GFx::AS3::Impl::SparseArray *)(v14.VInt + 32);
        if ( v15 == fields.Data.Size )
        {
          v17 = 0;
          if ( v15 )
          {
            do
            {
              if ( v17 >= flags.Data.Size )
                break;
              v18 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Impl::SparseArray::At(v16, v17);
              if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(v18, &v76, (unsigned int *)&newArr)->Result )
                goto LABEL_168;
              flags.Data.Data[v17++] = (unsigned int)newArr.pV;
            }
            while ( v17 < v16->Length );
          }
        }
      }
    }
    v20 = v82;
    v21 = v82->pTraits.pObject;
    memset(&newSA, 0, 12);
    newSA.DefaultValue.Flags = 0;
    newSA.DefaultValue.Bonus.pWeakProxy = 0;
    memset(&newSA.ValueA, 0, 12);
    newSA.ValueA.Data.pHeap = MHeap;
    newSA.ValueH.mHash.pTable = 0;
    newSA.ValueH.mHash.pHeap = MHeap;
    pairs.Data.pHeap = v21->pVM->MHeap;
    memset(&pairs, 0, 12);
    vc.__vftable = (Scaleform::GFx::AS3::Impl::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::Impl::ValuePtrCollector::`vftable';
    vc.Pairs = &pairs;
    newArr.pV = (Scaleform::GFx::AS3::Instances::fl::Array *)&v82->SA;
    Scaleform::GFx::AS3::Impl::SparseArray::ForEach(&v82->SA, &vc);
    v75.Vm = v20->pTraits.pObject->pVM;
    v75.Fields = &fields;
    functor.Fields = &fields;
    v75.Flags = &flags;
    functor.Vm = v75.Vm;
    functor.Flags = &flags;
    Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareOn>(
      &pairs,
      0,
      pairs.Data.Size,
      v75);
    v22 = *flags.Data.Data;
    v23 = (Scaleform::GFx::AS3::Instances::fl::Array_vtbl *)pairs.Data.Size;
    size[0] = pairs.Data.Size;
    if ( (v22 & 4) != 0 )
    {
      v24 = 1;
      if ( pairs.Data.Size > 1 )
      {
        while ( Scaleform::GFx::AS3::Impl::CompareOn::Compare(
                  &functor,
                  pairs.Data.Data[v24 - 1].First,
                  pairs.Data.Data[v24].First) != 0.0 )
        {
          if ( ++v24 >= (unsigned int)v23 )
            goto LABEL_42;
        }
        v29 = result->pObject;
        if ( result->pObject )
        {
          if ( ((unsigned __int8)v29 & 1) != 0 )
          {
            result->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v29 - 1);
          }
          else
          {
            RefCount = v29->RefCount;
            if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
            {
              v29->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v29);
            }
          }
          result->pObject = 0;
        }
        vc.__vftable = (Scaleform::GFx::AS3::Impl::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pairs.Data.Data);
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>(&newSA.ValueH.mHash);
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
          newSA.ValueA.Data.Data,
          newSA.ValueA.Data.Size);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, newSA.ValueA.Data.Data);
        if ( (newSA.DefaultValue.Flags & 0x1F) <= 9 )
          goto LABEL_168;
        if ( (newSA.DefaultValue.Flags & 0x200) == 0 )
        {
LABEL_167:
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&newSA.DefaultValue);
          goto LABEL_168;
        }
LABEL_166:
        Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&newSA.DefaultValue);
        goto LABEL_168;
      }
    }
LABEL_42:
    v88 = v22 & 8;
    if ( (v22 & 8) != 0 )
    {
      v25 = 0;
      if ( v23 )
      {
        v26 = newSA.ValueA.Data.Size;
        while ( 1 )
        {
          functor.Flags = (const Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> *)pairs.Data.Data[v25].Second;
          functor.Vm = (Scaleform::GFx::AS3::VM *)3;
          functor.Fields = 0;
          if ( newSA.Length == v26 )
          {
            pHeap = newSA.ValueA.Data.pHeap;
            v28 = v26 + 1;
            if ( v26 + 1 >= v26 )
            {
              if ( v28 >= newSA.ValueA.Data.Policy.Capacity )
                Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA.ValueA,
                  newSA.ValueA.Data.pHeap,
                  v28 + (v28 >> 2));
            }
            else
            {
              Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
                &newSA.ValueA.Data.Data[v28],
                0xFFFFFFFF);
              if ( v28 < newSA.ValueA.Data.Policy.Capacity >> 1 )
                Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA.ValueA,
                  pHeap,
                  v28);
            }
            v26 = v28;
            v31 = v28;
            v32 = (Scaleform::GFx::AS3::Impl::CompareOn *)&newSA.ValueA.Data.Data[v31 - 1];
            newSA.ValueA.Data.Size = v26;
            if ( &newSA.ValueA.Data.Data[v31] == (Scaleform::GFx::AS3::Value *)16 )
              goto LABEL_67;
            *v32 = functor;
            v32[1].Vm = v85;
            if ( ((int)functor.Vm & 0x1F) > 9u )
            {
              if ( ((int)functor.Vm & 0x200) != 0 )
                Scaleform::GFx::AS3::Value::AddRefWeakRef((Scaleform::GFx::AS3::Value *)&functor);
              else
                Scaleform::GFx::AS3::Value::AddRefInternal((Scaleform::GFx::AS3::Value *)&functor);
            }
          }
          else
          {
            newSA.ValueHHighInd = newSA.Length;
            size[0] = (unsigned int)&newSA.ValueHHighInd;
            size[1] = (unsigned int)&functor;
            Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
              &newSA.ValueH.mHash,
              newSA.ValueH.mHash.pHeap,
              (const Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef *)size);
          }
          v26 = newSA.ValueA.Data.Size;
LABEL_67:
          ++newSA.Length;
          if ( ((int)functor.Vm & 0x1F) > 9u )
          {
            if ( ((int)functor.Vm & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&functor);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&functor);
            v26 = newSA.ValueA.Data.Size;
          }
          if ( ++v25 >= (unsigned int)v23 )
            goto LABEL_93;
        }
      }
LABEL_91:
      v26 = newSA.ValueA.Data.Size;
LABEL_92:
      v23 = (Scaleform::GFx::AS3::Instances::fl::Array_vtbl *)size[0];
LABEL_93:
      v39 = (unsigned int)newArr.pV->__vftable;
      if ( v23 >= newArr.pV->__vftable )
      {
LABEL_120:
        if ( v88 )
        {
          Scaleform::GFx::AS3::VM::MakeArray(v82->pTraits.pObject->pVM, &newArr);
          pV = newArr.pV;
          v45 = result->pObject;
          v46 = newArr.pV;
          if ( newArr.pV != result->pObject )
          {
            if ( v45 )
            {
              if ( ((unsigned __int8)v45 & 1) != 0 )
              {
                result->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v45 - 1);
              }
              else
              {
                v47 = v45->RefCount;
                if ( ((unsigned int)&byte_3FFFFF & v47) != 0 )
                {
                  v45->RefCount = v47 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v45);
                  pV = newArr.pV;
                }
              }
            }
            result->pObject = v46;
          }
          p_SA = &pV->SA;
          if ( &pV->SA != &newSA )
          {
            p_SA->Length = newSA.Length;
            pV->SA.ValueHLowInd = newSA.ValueHLowInd;
            pV->SA.ValueHHighInd = newSA.ValueHHighInd;
            p_ValueH = &pV->SA.ValueH;
            Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Assign(
              &pV->SA.ValueH.mHash,
              newSA.ValueH.mHash.pHeap,
              &newSA.ValueH.mHash);
            p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&p_SA->ValueA;
            p_ValueH->mHash.pHeap = newSA.ValueH.mHash.pHeap;
            v51 = p_ValueA->Size;
            Data = p_ValueA[1].Data;
            v53 = newSA.ValueA.Data.Size;
            if ( newSA.ValueA.Data.Size >= v51 )
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
                v51 - newSA.ValueA.Data.Size);
              if ( v53 < p_ValueA->Policy.Capacity >> 1 )
                Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  p_ValueA,
                  Data,
                  v53);
            }
            p_ValueA->Size = v53;
            if ( v53 > v51 )
            {
              v54 = &p_ValueA->Data[v51];
              for ( j = v53 - v51; j; --j )
              {
                if ( v54 )
                {
                  LODWORD(v54->First) = 0;
                  HIDWORD(v54->First) = 0;
                }
                ++v54;
              }
            }
            v56 = 0;
            if ( p_ValueA->Size )
            {
              v57 = 0;
              do
              {
                Scaleform::GFx::AS3::Value::Assign(
                  (Scaleform::GFx::AS3::Value *)&p_ValueA->Data[v57],
                  &newSA.ValueA.Data.Data[v57]);
                ++v56;
                ++v57;
              }
              while ( v56 < p_ValueA->Size );
            }
          }
        }
        else
        {
          if ( (Scaleform::GFx::AS3::Impl::SparseArray *)newArr.pV != &newSA )
          {
            v58 = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> > *)newArr.pV;
            ValueHLowInd = newSA.ValueHLowInd;
            ValueHHighInd = newSA.ValueHHighInd;
            newArr.pV->__vftable = (Scaleform::GFx::AS3::Instances::fl::Array_vtbl *)newSA.Length;
            v58[1].pTable = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *)ValueHLowInd;
            v61 = newSA.ValueH.mHash.pHeap;
            v58[2].pTable = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *)ValueHHighInd;
            Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Assign(
              v58 + 12,
              v61,
              &newSA.ValueH.mHash);
            v62 = newSA.ValueA.Data.Size;
            v58[13].pTable = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *)newSA.ValueH.mHash.pHeap;
            pTable = v58[11].pTable;
            v64 = (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&v58[8];
            v65 = (unsigned int)v58[9].pTable;
            v66 = v62;
            if ( v62 >= v65 )
            {
              if ( v62 >= v64->Policy.Capacity )
                Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  v64,
                  pTable,
                  v62 + (v62 >> 2));
            }
            else
            {
              Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
                (Scaleform::GFx::AS3::Value *)&v64->Data[v62],
                v65 - v62);
              if ( v66 < v64->Policy.Capacity >> 1 )
                Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  v64,
                  pTable,
                  v66);
            }
            v64->Size = v66;
            if ( v66 > v65 )
            {
              v67 = &v64->Data[v65];
              for ( k = v66 - v65; k; --k )
              {
                if ( v67 )
                {
                  LODWORD(v67->First) = 0;
                  HIDWORD(v67->First) = 0;
                }
                ++v67;
              }
            }
            v69 = 0;
            if ( v64->Size )
            {
              v70 = 0;
              do
              {
                Scaleform::GFx::AS3::Value::Assign(
                  (Scaleform::GFx::AS3::Value *)&v64->Data[v70],
                  &newSA.ValueA.Data.Data[v70]);
                ++v69;
                ++v70;
              }
              while ( v69 < v64->Size );
            }
          }
          if ( v82 != result->pObject )
          {
            v71 = v82;
            v82->RefCount = (v82->RefCount + 1) & 0x8FBFFFFF;
            v72 = result->pObject;
            if ( result->pObject )
            {
              if ( ((unsigned __int8)v72 & 1) != 0 )
              {
                result->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v72 - 1);
              }
              else
              {
                v73 = v72->RefCount;
                if ( ((unsigned int)&byte_3FFFFF & v73) != 0 )
                {
                  v72->RefCount = v73 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v72);
                }
              }
            }
            result->pObject = v71;
          }
        }
        vc.__vftable = (Scaleform::GFx::AS3::Impl::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pairs.Data.Data);
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>(&newSA.ValueH.mHash);
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
          newSA.ValueA.Data.Data,
          newSA.ValueA.Data.Size);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, newSA.ValueA.Data.Data);
        if ( (newSA.DefaultValue.Flags & 0x1F) <= 9 )
          goto LABEL_168;
        if ( (newSA.DefaultValue.Flags & 0x200) == 0 )
          goto LABEL_167;
        goto LABEL_166;
      }
      if ( v39 )
      {
        if ( v39 <= v26 && v26 )
        {
          v40 = newSA.ValueA.Data.pHeap;
          v41 = v26;
          if ( v39 >= v26 )
          {
            if ( v39 >= newSA.ValueA.Data.Policy.Capacity )
              Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA.ValueA,
                newSA.ValueA.Data.pHeap,
                v39 + (v39 >> 2));
          }
          else
          {
            Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
              &newSA.ValueA.Data.Data[v39],
              v26 - v39);
            if ( v39 < newSA.ValueA.Data.Policy.Capacity >> 1 )
              Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA.ValueA,
                v40,
                v39);
          }
          newSA.ValueA.Data.Size = v39;
          if ( v39 > v41 )
          {
            v42 = &newSA.ValueA.Data.Data[v41];
            v43 = v39 - v41;
            if ( v39 != v41 )
            {
              do
              {
                if ( v42 )
                {
                  v42->Flags = 0;
                  v42->Bonus.pWeakProxy = 0;
                }
                ++v42;
                --v43;
              }
              while ( v43 );
            }
          }
        }
        else if ( v39 >= newSA.ValueHLowInd )
        {
          if ( v39 < newSA.ValueHHighInd )
            Scaleform::GFx::AS3::Impl::SparseArray::CutHash(&newSA, v39, newSA.ValueHHighInd - v39 + 1, 0);
          goto LABEL_119;
        }
      }
      else
      {
        if ( v26 )
        {
          Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(newSA.ValueA.Data.Data, v26);
          if ( (newSA.ValueA.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
          {
            if ( newSA.ValueA.Data.Data )
            {
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, newSA.ValueA.Data.Data);
              newSA.ValueA.Data.Data = 0;
            }
            newSA.ValueA.Data.Policy.Capacity = 0;
            newSA.ValueA.Data.Size = 0;
            goto LABEL_115;
          }
        }
        else if ( !newSA.ValueA.Data.Policy.Capacity )
        {
          Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA.ValueA,
            newSA.ValueA.Data.pHeap,
            0);
        }
        newSA.ValueA.Data.Size = 0;
      }
LABEL_115:
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>(&newSA.ValueH.mHash);
      newSA.ValueHLowInd = 0;
      newSA.ValueHHighInd = 0;
LABEL_119:
      newSA.Length = v39;
      goto LABEL_120;
    }
    v33 = 0;
    if ( !size[0] )
      goto LABEL_91;
    v26 = newSA.ValueA.Data.Size;
    while ( 1 )
    {
      First = (Scaleform::GFx::AS3::Value *)pairs.Data.Data[v33].First;
      if ( newSA.Length == v26 )
      {
        v35 = newSA.ValueA.Data.pHeap;
        v36 = v26 + 1;
        if ( v26 + 1 >= v26 )
        {
          if ( v36 >= newSA.ValueA.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA.ValueA,
              newSA.ValueA.Data.pHeap,
              v36 + (v36 >> 2));
        }
        else
        {
          Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(&newSA.ValueA.Data.Data[v36], 0xFFFFFFFF);
          if ( v36 < newSA.ValueA.Data.Policy.Capacity >> 1 )
            Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&newSA.ValueA,
              v35,
              v36);
        }
        v26 = v36;
        v37 = v36;
        v38 = &newSA.ValueA.Data.Data[v37 - 1];
        newSA.ValueA.Data.Size = v26;
        if ( &newSA.ValueA.Data.Data[v37] == (Scaleform::GFx::AS3::Value *)16 )
          goto LABEL_89;
        v38->Flags = First->Flags;
        v38->Bonus.pWeakProxy = First->Bonus.pWeakProxy;
        v38->value.VS._1.VInt = First->value.VS._1.VInt;
        v38->value.VS._2.VObj = First->value.VS._2.VObj;
        if ( (First->Flags & 0x1F) > 9 )
        {
          if ( (First->Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::AddRefWeakRef(First);
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(First);
        }
      }
      else
      {
        newSA.ValueHHighInd = newSA.Length;
        functor.Vm = (Scaleform::GFx::AS3::VM *)&newSA.ValueHHighInd;
        functor.Fields = (const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)First;
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
          &newSA.ValueH.mHash,
          newSA.ValueH.mHash.pHeap,
          (const Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef *)&functor);
      }
      v26 = newSA.ValueA.Data.Size;
LABEL_89:
      ++newSA.Length;
      if ( ++v33 >= size[0] )
        goto LABEL_92;
    }
  }
  while ( 1 )
  {
    v10 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Impl::SparseArray::At(v9, v8);
    if ( !Scaleform::GFx::AS3::Value::Convert2String(v10, &v76, &tmp)->Result )
      break;
    Scaleform::GFx::AS3::Value::Value((Scaleform::GFx::AS3::Value *)&pairs, &tmp);
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &fields.Data,
      (Scaleform::GFx::AS3::Value *)&pairs);
    if ( ((int)pairs.Data.Data & 0x1F) > 9u )
    {
      if ( ((int)pairs.Data.Data & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&pairs);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&pairs);
    }
    if ( ++v8 >= v9->Length )
      goto LABEL_17;
  }
LABEL_168:
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, flags.Data.Data);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(fields.Data.Data, fields.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, fields.Data.Data);
  pNode = tmp.pNode;
  --tmp.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
