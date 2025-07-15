Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> **__cdecl Scaleform::GFx::AS3::InstanceTraits::fl::String::StringSplit(
        Scaleform::String result,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::ASString *str,
        Scaleform::GFx::ASStringNode *delimiters,
        unsigned int limit)
{
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> **pData; // ebx
  Scaleform::GFx::AS3::VM *v6; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  const char *v8; // esi
  const char *v9; // eax
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *v10; // esi
  Scaleform::GFx::AS3::Value *v11; // eax
  Scaleform::GFx::AS3::Value *Data; // ecx
  Scaleform::GFx::AS3::Value *v14; // ecx
  int v15; // esi
  unsigned int v16; // esi
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *v17; // esi
  Scaleform::GFx::AS3::Value *v18; // eax
  Scaleform::GFx::AS3::Value *v19; // ecx
  Scaleform::GFx::ASStringNode *v20; // eax
  void *v21; // esi
  __m128i *v22; // ebp
  const char *v23; // esi
  unsigned int v24; // edi
  unsigned int v25; // ebx
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // edx
  const char *v27; // eax
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  Scaleform::String::DataDesc *v29; // ecx
  unsigned int Size; // esi
  Scaleform::GFx::AS3::Value *v31; // eax
  int v32; // ecx
  Scaleform::GFx::ASStringNode *v33; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *v34; // edi
  Scaleform::GFx::ASString *v35; // eax
  Scaleform::GFx::AS3::Value *v36; // eax
  unsigned int v37; // ecx
  Scaleform::GFx::ASString *v38; // eax
  unsigned int Length; // ecx
  Scaleform::GFx::ASStringNode *v40; // eax
  const char *pstr; // [esp+Ch] [ebp-38h] BYREF
  const char *s2; // [esp+10h] [ebp-34h] BYREF
  Scaleform::GFx::ASString v; // [esp+14h] [ebp-30h] BYREF
  const char *end; // [esp+18h] [ebp-2Ch]
  const char *prev; // [esp+1Ch] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Value *p_val; // [esp+20h] [ebp-24h]
  Scaleform::GFx::AS3::Value val; // [esp+24h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value v48; // [esp+34h] [ebp-10h] BYREF

  pData = (Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> **)result.pData;
  v6 = vm;
  Scaleform::GFx::AS3::VM::MakeArray(vm, (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *)result.pData);
  pNode = str->pNode;
  v8 = (const char *)delimiters;
  v9 = str->pNode->pData;
  pstr = v9;
  if ( !delimiters )
  {
    v10 = *pData;
    Scaleform::GFx::AS3::Value::Value(&val, str);
    Data = v10[2].Data;
    if ( Data == (Scaleform::GFx::AS3::Value *)v10[4].Size )
    {
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        v10 + 4,
        v11);
    }
    else
    {
      v10[2].Policy.Capacity = (unsigned int)Data;
      p_val = v11;
      prev = (const char *)&v10[2].Policy;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
        (Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> > *)&v10[5],
        (void *)v10[5].Size,
        (const Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef *)&prev);
    }
    ++v10[2].Data;
    if ( (val.Flags & 0x1F) > 9 )
    {
      if ( (val.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
      return pData;
    }
    return pData;
  }
  if ( LOBYTE(delimiters->pData) )
  {
    str = 0;
    v22 = (__m128i *)v9;
    while ( 2 )
    {
      s2 = v8;
      end = v9;
      v23 = 0;
      while ( 1 )
      {
        prev = v9;
        v24 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&pstr);
        if ( !v24 )
          --pstr;
        v25 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&s2);
        if ( !v25 )
          --s2;
        v9 = pstr;
        if ( !v23 )
          v23 = pstr;
        if ( !v24 )
          break;
        if ( !v25 )
          goto LABEL_47;
        if ( v24 != v25 )
        {
          v9 = v23;
          pstr = v23;
          break;
        }
      }
      if ( v25 )
        goto LABEL_64;
LABEL_47:
      if ( (unsigned int)str >= limit )
        return (Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> **)result.pData;
      StringManagerRef = vm->StringManagerRef;
      if ( end )
        v27 = (const char *)(end - (const char *)v22);
      else
        v27 = (const char *)strlen(v22->m128i_i8);
      if ( (int)v27 <= 0 )
        p_EmptyStringNode = &StringManagerRef->pStringManager->EmptyStringNode;
      else
        p_EmptyStringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                              StringManagerRef->pStringManager,
                              v22,
                              (unsigned int)v27);
      v29 = result.pData;
      v.pNode = p_EmptyStringNode;
      ++p_EmptyStringNode->RefCount;
      Size = v29->Size;
      Scaleform::GFx::AS3::Value::Value(&v48, &v);
      v32 = *(_DWORD *)(Size + 32);
      if ( v32 == *(_DWORD *)(Size + 68) )
      {
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
          (Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)(Size + 64),
          v31);
      }
      else
      {
        *(_DWORD *)(Size + 40) = v32;
        val.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v31;
        val.Flags = Size + 40;
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
          (Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> > *)(Size + 80),
          *(void **)(Size + 84),
          (const Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef *)&val);
      }
      ++*(_DWORD *)(Size + 32);
      if ( (v48.Flags & 0x1F) > 9 )
      {
        if ( (v48.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v48);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v48);
      }
      v33 = v.pNode;
      --v.pNode->RefCount;
      if ( !v33->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v33);
      v9 = prev;
      str = (const Scaleform::GFx::ASString *)((char *)str + 1);
      v22 = (__m128i *)prev;
      pstr = prev;
LABEL_64:
      if ( v24 )
      {
        v8 = (const char *)delimiters;
        continue;
      }
      break;
    }
    if ( (unsigned int)str >= limit )
      return (Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> **)result.pData;
    if ( v25 )
    {
      v34 = (Scaleform::GFx::AS3::Instances::fl::Array *)result.pData->Size;
      v38 = Scaleform::GFx::AS3::InstanceTraits::fl::CreateStringFromCStr(v22, 0, &delimiters, vm->StringManagerRef);
      Scaleform::GFx::AS3::Value::Value(&v48, v38);
      Length = v34->SA.Length;
      if ( Length == v34->SA.ValueA.Data.Size )
        goto LABEL_68;
      v34->SA.ValueHHighInd = Length;
      val.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v36;
      val.Flags = (unsigned int)&v34->SA.ValueHHighInd;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
        &v34->SA.ValueH.mHash,
        v34->SA.ValueH.mHash.pHeap,
        (const Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef *)&val);
    }
    else
    {
      v34 = (Scaleform::GFx::AS3::Instances::fl::Array *)result.pData->Size;
      v35 = Scaleform::GFx::AS3::InstanceTraits::fl::CreateStringFromCStr(v22, end, &delimiters, vm->StringManagerRef);
      Scaleform::GFx::AS3::Value::Value(&v48, v35);
      v37 = v34->SA.Length;
      if ( v37 == v34->SA.ValueA.Data.Size )
      {
LABEL_68:
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
          &v34->SA.ValueA.Data,
          v36);
        goto LABEL_72;
      }
      v34->SA.ValueHHighInd = v37;
      val.Flags = (unsigned int)&v34->SA.ValueHHighInd;
      val.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v36;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
        &v34->SA.ValueH.mHash,
        v34->SA.ValueH.mHash.pHeap,
        (const Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef *)&val);
    }
LABEL_72:
    ++v34->SA.Length;
    Scaleform::GFx::AS3::Value::~Value(&v48);
    v40 = delimiters;
    --delimiters->RefCount;
    if ( !v40->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v40);
    return (Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> **)result.pData;
  }
  if ( pNode->Size )
  {
    Scaleform::String::String(&result);
    while ( 1 )
    {
      v16 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&pstr);
      if ( !v16 )
        break;
      Scaleform::String::Clear(&result);
      Scaleform::String::AppendChar(&result, v16);
      delimiters = Scaleform::GFx::ASStringManager::CreateStringNode(
                     v6->StringManagerRef->pStringManager,
                     (__m128i *)((result.HeapTypeBits & 0xFFFFFFFC) + 8),
                     *(_DWORD *)(result.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
      ++delimiters->RefCount;
      v17 = *pData;
      Scaleform::GFx::AS3::Value::Value(&val, (const Scaleform::GFx::ASString *)&delimiters);
      v19 = v17[2].Data;
      if ( v19 == (Scaleform::GFx::AS3::Value *)v17[4].Size )
      {
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
          v17 + 4,
          v18);
      }
      else
      {
        v17[2].Policy.Capacity = (unsigned int)v19;
        prev = (const char *)&v17[2].Policy;
        p_val = v18;
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
          (Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> > *)&v17[5],
          (void *)v17[5].Size,
          (const Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef *)&prev);
      }
      ++v17[2].Data;
      if ( (val.Flags & 0x1F) > 9 )
      {
        if ( (val.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
      }
      v20 = delimiters;
      --delimiters->RefCount;
      if ( !v20->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v20);
    }
    --pstr;
    v21 = (void *)(result.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((result.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v21);
      return pData;
    }
    return pData;
  }
  Scaleform::GFx::AS3::Value::Value(&val, str);
  v14 = (*pData)[2].Data;
  v15 = (int)&(*pData)[2];
  if ( v14 == (Scaleform::GFx::AS3::Value *)(*pData)[4].Size )
  {
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      *pData + 4,
      &val);
  }
  else
  {
    (*pData)[2].Policy.Capacity = (unsigned int)v14;
    prev = (const char *)(v15 + 8);
    p_val = &val;
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> > *)(v15 + 48),
      *(void **)(v15 + 52),
      (const Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef *)&prev);
  }
  ++*(_DWORD *)v15;
  if ( (val.Flags & 0x1F) <= 9 )
    return pData;
  if ( (val.Flags & 0x200) != 0 )
    Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
  else
    Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
  return pData;
}
