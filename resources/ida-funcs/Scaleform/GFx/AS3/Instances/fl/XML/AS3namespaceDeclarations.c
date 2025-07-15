void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3namespaceDeclarations(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v2; // ebp
  Scaleform::GFx::AS3::VM *pVM; // ebx
  Scaleform::GFx::AS3::Instances::fl::Array *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // edi
  unsigned int RefCount; // eax
  int v7; // eax
  const Scaleform::MemoryHeap *MHeap; // ecx
  _DWORD *v9; // ebx
  int v10; // eax
  _DWORD *v11; // ebp
  unsigned int v12; // edi
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // esi
  Scaleform::GFx::AS3::Instances::fl::XML_vtbl *v18; // eax
  unsigned int v19; // edi
  const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *(__thiscall *GetInScopeNamespaces)(Scaleform::GFx::AS3::Instances::fl::XML *); // edx
  int v21; // eax
  _DWORD *v22; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v23; // eax
  unsigned int Size; // ecx
  unsigned int v25; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v26; // eax
  unsigned int Length; // ecx
  Scaleform::GFx::AS3::Impl::SparseArray *p_SA; // ebp
  unsigned int v29; // eax
  const Scaleform::MemoryHeap *pHeap; // ebx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v32; // esi
  Scaleform::GFx::AS3::Value *Data; // eax
  Scaleform::GFx::AS3::Value *v34; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v35; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v36; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> a; // [esp+10h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Instances::fl::XML *v38; // [esp+14h] [ebp-3Ch]
  Scaleform::GFx::AS3::VM *vm[2]; // [esp+18h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value v40; // [esp+20h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::NamespaceArray ancestorNS; // [esp+30h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::NamespaceArray declaredNS; // [esp+40h] [ebp-10h] BYREF
  unsigned int i; // [esp+54h] [ebp+4h]

  v2 = this;
  pVM = this->pTraits.pObject->pVM;
  v38 = this;
  vm[0] = pVM;
  Scaleform::GFx::AS3::VM::MakeArray(pVM, &a);
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
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    result->pObject = pV;
  }
  v7 = v2->GetKind(v2);
  if ( v7 != 2 && v7 != 3 && v7 != 4 && v7 != 5 )
  {
    MHeap = pVM->MHeap;
    v9 = &v2->Parent.pObject->__vftable;
    memset((void *)&ancestorNS, 0, 12);
    ancestorNS.Namespaces.Data.pHeap = MHeap;
    if ( v9 )
    {
      do
      {
        v10 = (*(int (__thiscall **)(_DWORD *))(*v9 + 80))(v9);
        v11 = (_DWORD *)v10;
        if ( v10 )
        {
          v12 = 0;
          if ( *(_DWORD *)(v10 + 4) )
          {
            do
            {
              v13 = *(_DWORD *)(*v11 + 4 * v12);
              v14 = *(_DWORD *)(v13 + 40);
              v15 = v13 + 40;
              v16 = v14 & 0x1F;
              if ( v16 && ((unsigned int)(v16 - 12) > 3 || *(_DWORD *)(v15 + 8)) )
              {
                v17 = 0;
                if ( ancestorNS.Namespaces.Data.Size )
                {
                  while ( !Scaleform::GFx::AS3::StrictEqual(
                             &ancestorNS.Namespaces.Data.Data[v17].pObject->Prefix,
                             (const Scaleform::GFx::AS3::Value *)(*(_DWORD *)(*v11 + 4 * v12) + 40)) )
                  {
                    if ( ++v17 >= ancestorNS.Namespaces.Data.Size )
                      goto LABEL_21;
                  }
                }
                else
                {
LABEL_21:
                  Scaleform::GFx::AS3::NamespaceArray::Add(
                    &ancestorNS,
                    *(Scaleform::GFx::AS3::Instances::fl::Namespace **)(*v11 + 4 * v12),
                    1);
                }
              }
              ++v12;
            }
            while ( v12 < v11[1] );
          }
        }
        v9 = (_DWORD *)v9[9];
      }
      while ( v9 );
      v2 = v38;
    }
    v18 = v2->__vftable;
    v19 = 0;
    declaredNS.Namespaces.Data.pHeap = vm[0]->MHeap;
    GetInScopeNamespaces = v18->GetInScopeNamespaces;
    memset((void *)&declaredNS, 0, 12);
    v21 = (int)GetInScopeNamespaces(v2);
    v22 = (_DWORD *)v21;
    if ( v21 && *(_DWORD *)(v21 + 4) )
    {
      do
      {
        v23 = *(Scaleform::GFx::AS3::Instances::fl::Namespace **)(*v22 + 4 * v19);
        if ( (v23->Prefix.Flags & 0x1F) != 0 && ((v23->Prefix.Flags & 0x1F) - 12 > 3 || v23->Prefix.value.VS._1.VInt) )
          Scaleform::GFx::AS3::NamespaceArray::Add(&declaredNS, v23, 1);
        ++v19;
      }
      while ( v19 < v22[1] );
    }
    Size = declaredNS.Namespaces.Data.Size;
    v25 = 0;
    for ( i = 0; v25 < declaredNS.Namespaces.Data.Size; i = v25 )
    {
      v26 = declaredNS.Namespaces.Data.Data[v25].pObject;
      v40.Flags = 11;
      v40.Bonus.pWeakProxy = 0;
      v40.value.VS._1.VInt = (int)v26;
      if ( v26 )
        v26->RefCount = (v26->RefCount + 1) & 0x8FBFFFFF;
      Length = a.pV->SA.Length;
      p_SA = &a.pV->SA;
      if ( Length == a.pV->SA.ValueA.Data.Size )
      {
        v29 = a.pV->SA.ValueA.Data.Size;
        pHeap = a.pV->SA.ValueA.Data.pHeap;
        p_ValueA = &a.pV->SA.ValueA;
        v32 = v29 + 1;
        if ( v29 + 1 >= v29 )
        {
          if ( v32 >= a.pV->SA.ValueA.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)p_ValueA,
              pHeap,
              v32 + (v32 >> 2));
        }
        else
        {
          Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
            &p_ValueA->Data.Data[v29 + 1],
            0xFFFFFFFF);
          if ( v32 < p_SA->ValueA.Data.Policy.Capacity >> 1 )
            Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)p_ValueA,
              pHeap,
              v32);
        }
        Data = p_ValueA->Data.Data;
        p_SA->ValueA.Data.Size = v32;
        v34 = &Data[v32 - 1];
        if ( v34 )
        {
          *v34 = v40;
          if ( (v40.Flags & 0x1F) > 9 )
          {
            if ( (v40.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::AddRefWeakRef(&v40);
            else
              Scaleform::GFx::AS3::Value::AddRefInternal(&v40);
          }
        }
      }
      else
      {
        a.pV->SA.ValueHHighInd = Length;
        vm[0] = (Scaleform::GFx::AS3::VM *)&p_SA->ValueHHighInd;
        vm[1] = (Scaleform::GFx::AS3::VM *)&v40;
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
          &p_SA->ValueH.mHash,
          p_SA->ValueH.mHash.pHeap,
          (const Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef *)vm);
      }
      ++p_SA->Length;
      if ( (v40.Flags & 0x1F) > 9 )
      {
        if ( (v40.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v40);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v40);
      }
      Size = declaredNS.Namespaces.Data.Size;
      v25 = i + 1;
    }
    v35 = declaredNS.Namespaces.Data.Data;
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)declaredNS.Namespaces.Data.Data,
      Size);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v35);
    v36 = ancestorNS.Namespaces.Data.Data;
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)ancestorNS.Namespaces.Data.Data,
      ancestorNS.Namespaces.Data.Size);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v36);
  }
}
