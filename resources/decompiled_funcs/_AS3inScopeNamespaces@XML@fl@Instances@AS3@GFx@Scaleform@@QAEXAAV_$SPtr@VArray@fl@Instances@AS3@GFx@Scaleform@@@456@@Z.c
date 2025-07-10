void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3inScopeNamespaces(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *v4; // esi
  Scaleform::GFx::AS3::Instances::fl::Array *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // edi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *v8; // esi
  const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *v9; // eax
  const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *v10; // ebp
  unsigned int v11; // ebx
  unsigned int v12; // edi
  Scaleform::GFx::AS3::Value::V1U v13; // esi
  Scaleform::GFx::AS3::Value *v14; // ecx
  unsigned int v15; // eax
  signed int v16; // eax
  unsigned int Length; // ecx
  Scaleform::GFx::AS3::Impl::SparseArray *p_SA; // ebp
  unsigned int v19; // eax
  const Scaleform::MemoryHeap *pHeap; // ebx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v22; // esi
  Scaleform::GFx::AS3::Value *Data; // eax
  Scaleform::GFx::AS3::Value *v24; // eax
  unsigned int v25; // eax
  Scaleform::GFx::AS3::Value::V1U v26; // eax
  unsigned int v27; // ecx
  Scaleform::GFx::AS3::Impl::SparseArray *v28; // esi
  Scaleform::HashSet<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> > dupeCheck; // [esp+10h] [ebp-44h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> a; // [esp+14h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Instances::fl::XML *xml; // [esp+18h] [ebp-3Ch]
  unsigned int i; // [esp+1Ch] [ebp-38h]
  unsigned int size; // [esp+20h] [ebp-34h]
  const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *pnsh; // [esp+24h] [ebp-30h]
  Scaleform::GFx::AS3::Instances::fl::XML *v35; // [esp+28h] [ebp-2Ch]
  Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef key; // [esp+2Ch] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Value v37; // [esp+34h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value prefix; // [esp+44h] [ebp-10h] BYREF

  pVM = this->pTraits.pObject->pVM;
  v35 = this;
  Scaleform::GFx::AS3::VM::MakeArray(pVM, &a);
  v4 = result;
  pObject = result->pObject;
  pV = a.pV;
  if ( a.pV != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    v4->pObject = pV;
  }
  dupeCheck.pTable = 0;
  xml = this;
  do
  {
    v8 = xml;
    v9 = xml->GetInScopeNamespaces(xml);
    v10 = v9;
    pnsh = v9;
    if ( v9 )
    {
      v11 = v9->Data.Size;
      v12 = 0;
      size = v11;
      i = 0;
      if ( v11 )
      {
        do
        {
          v13 = (Scaleform::GFx::AS3::Value::V1U)v10->Data.Data[v12].pObject;
          v14 = (Scaleform::GFx::AS3::Value *)(v13.VInt + 40);
          prefix = *(Scaleform::GFx::AS3::Value *)(v13.VInt + 40);
          if ( (*(_BYTE *)(v13.VInt + 40) & 0x1Fu) > 9 )
          {
            if ( (*(_DWORD *)(v13.VInt + 40) & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::AddRefWeakRef(v14);
            else
              Scaleform::GFx::AS3::Value::AddRefInternal(v14);
          }
          if ( !dupeCheck.pTable
            || (LOBYTE(result) = 0,
                v15 = Scaleform::GFx::AS3::Value::HashFunctor::operator()(
                        (Scaleform::GFx::AS3::Value::HashFunctor *)&result,
                        &prefix),
                v16 = Scaleform::HashSetBase<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>>::findIndexCore<Scaleform::GFx::AS3::Value>(
                        &dupeCheck,
                        &prefix,
                        dupeCheck.pTable->SizeMask & v15),
                v16 < 0)
            || &dupeCheck.pTable[3 * v16] == (Scaleform::HashSetBase<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> >::TableType *)-16 )
          {
            v37.Flags = 11;
            v37.Bonus.pWeakProxy = 0;
            v37.value.VS._1 = v13;
            if ( v13.VInt )
              *(_DWORD *)(v13.VInt + 16) = (*(_DWORD *)(v13.VInt + 16) + 1) & 0x8FBFFFFF;
            Length = a.pV->SA.Length;
            p_SA = &a.pV->SA;
            if ( Length == a.pV->SA.ValueA.Data.Size )
            {
              v19 = a.pV->SA.ValueA.Data.Size;
              pHeap = a.pV->SA.ValueA.Data.pHeap;
              p_ValueA = &a.pV->SA.ValueA;
              v22 = v19 + 1;
              if ( v19 + 1 >= v19 )
              {
                if ( v22 >= a.pV->SA.ValueA.Data.Policy.Capacity )
                  Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                    (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)p_ValueA,
                    pHeap,
                    v22 + (v22 >> 2));
              }
              else
              {
                Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
                  &p_ValueA->Data.Data[v19 + 1],
                  0xFFFFFFFF);
                if ( v22 < p_SA->ValueA.Data.Policy.Capacity >> 1 )
                  Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                    (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)p_ValueA,
                    pHeap,
                    v22);
              }
              Data = p_ValueA->Data.Data;
              p_SA->ValueA.Data.Size = v22;
              v24 = &Data[v22 - 1];
              if ( v24 )
              {
                *v24 = v37;
                if ( (v37.Flags & 0x1F) > 9 )
                {
                  if ( (v37.Flags & 0x200) != 0 )
                    Scaleform::GFx::AS3::Value::AddRefWeakRef(&v37);
                  else
                    Scaleform::GFx::AS3::Value::AddRefInternal(&v37);
                }
              }
            }
            else
            {
              a.pV->SA.ValueHHighInd = Length;
              key.pFirst = &p_SA->ValueHHighInd;
              key.pSecond = &v37;
              Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
                &p_SA->ValueH.mHash,
                p_SA->ValueH.mHash.pHeap,
                &key);
            }
            ++p_SA->Length;
            if ( (v37.Flags & 0x1F) > 9 )
            {
              if ( (v37.Flags & 0x200) != 0 )
                Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v37);
              else
                Scaleform::GFx::AS3::Value::ReleaseInternal(&v37);
            }
            LOBYTE(result) = 0;
            v25 = Scaleform::GFx::AS3::Value::HashFunctor::operator()(
                    (Scaleform::GFx::AS3::Value::HashFunctor *)&result,
                    &prefix);
            Scaleform::HashSetBase<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>>::add<Scaleform::GFx::AS3::Value>(
              &dupeCheck,
              &dupeCheck,
              &prefix,
              v25);
            v12 = i;
            v11 = size;
            v10 = pnsh;
          }
          if ( (prefix.Flags & 0x1F) > 9 )
          {
            if ( (prefix.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&prefix);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&prefix);
          }
          i = ++v12;
        }
        while ( v12 < v11 );
        v8 = xml;
      }
    }
    xml = v8->Parent.pObject;
  }
  while ( xml );
  if ( !a.pV->SA.Length )
  {
    v26 = (Scaleform::GFx::AS3::Value::V1U)v35->pTraits.pObject->pVM->PublicNamespace.pObject;
    prefix.Flags = 11;
    prefix.Bonus.pWeakProxy = 0;
    prefix.value.VS._1 = v26;
    if ( v26.VInt )
      *(_DWORD *)(v26.VInt + 16) = (*(_DWORD *)(v26.VInt + 16) + 1) & 0x8FBFFFFF;
    v27 = a.pV->SA.Length;
    v28 = &a.pV->SA;
    if ( v27 == a.pV->SA.ValueA.Data.Size )
    {
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &a.pV->SA.ValueA.Data,
        &prefix);
    }
    else
    {
      a.pV->SA.ValueHHighInd = v27;
      key.pFirst = &v28->ValueHHighInd;
      key.pSecond = &prefix;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
        &v28->ValueH.mHash,
        v28->ValueH.mHash.pHeap,
        &key);
    }
    ++v28->Length;
    if ( (prefix.Flags & 0x1F) > 9 )
    {
      if ( (prefix.Flags & 0x200) != 0 )
      {
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&prefix);
        Scaleform::HashSetBase<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>>::Clear(&dupeCheck);
        return;
      }
      Scaleform::GFx::AS3::Value::ReleaseInternal(&prefix);
    }
  }
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>>::Clear(&dupeCheck);
}
