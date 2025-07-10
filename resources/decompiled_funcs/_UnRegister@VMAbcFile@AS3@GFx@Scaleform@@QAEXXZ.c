void __thiscall Scaleform::GFx::AS3::VMAbcFile::UnRegister(Scaleform::GFx::AS3::VMAbcFile *this)
{
  Scaleform::GFx::AS3::VMAbcFile *v1; // ebp
  int v2; // edi
  unsigned int Size; // ebx
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *v4; // esi
  unsigned int v5; // eax
  void **p_Data; // esi
  void **v7; // edi
  unsigned int v8; // ebx
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > >::TableType *pTable; // eax
  Scaleform::HashSetLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > > *p_GlobalObjects; // edi
  unsigned int v11; // esi
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > >::TableType *v12; // ecx
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > >::TableType *v13; // eax
  unsigned int SizeMask; // eax
  unsigned int *v15; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> **v16; // esi
  unsigned int v17; // eax
  void **v18; // esi
  void **v19; // edi
  unsigned int v20; // ebx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> **p_IntNamespaceSets; // esi
  unsigned int v22; // eax
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,340,Scaleform::ArrayDefaultPolicy> *p_IntStrings; // esi
  Scaleform::GFx::ASStringNode **p_pObject; // edi
  unsigned int v25; // ebx
  Scaleform::GFx::ASStringNode *v26; // ecx

  v1 = this;
  if ( Scaleform::GFx::AS3::VM::RemoveVMAbcFileWeak(this->VMRef, this) )
  {
    Scaleform::GFx::AS3::VMAbcFile::UnregisterUserDefinedClassTraits(v1);
    if ( v1->OpCodeArray.Data.Size )
    {
      v2 = 0;
      Size = v1->OpCodeArray.Data.Size;
      do
      {
        v4 = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)&v1->OpCodeArray.Data.Data[v2];
        if ( v4->Size )
        {
          if ( (v4->Policy.Capacity & 0xFFFFFFFE) != 0 )
          {
            if ( v4->Data )
            {
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4->Data);
              v4->Data = 0;
            }
            v4->Policy.Capacity = 0;
          }
        }
        else if ( !v4->Policy.Capacity )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v4,
            v4,
            0);
        }
        ++v2;
        --Size;
        v4->Size = 0;
      }
      while ( Size );
    }
    v5 = v1->OpCodeArray.Data.Size;
    p_Data = (void **)&v1->OpCodeArray.Data.Data;
    if ( v5 )
    {
      v7 = (void **)((char *)*p_Data + 12 * v5 - 12);
      v8 = v1->OpCodeArray.Data.Size;
      do
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *v7);
        v7 -= 3;
        --v8;
      }
      while ( v8 );
      if ( (v1->OpCodeArray.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
      {
        if ( *p_Data )
        {
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *p_Data);
          *p_Data = 0;
        }
        v1->OpCodeArray.Data.Policy.Capacity = 0;
      }
    }
    else if ( !v1->OpCodeArray.Data.Policy.Capacity )
    {
      Scaleform::ArrayDataBase<Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy>,Scaleform::AllocatorLH<Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy>,340>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception,340>,Scaleform::ArrayDefaultPolicy> *)&v1->OpCodeArray,
        &v1->OpCodeArray,
        0);
    }
    v1->OpCodeArray.Data.Size = 0;
    Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>>>>::Clear((Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > > *)&v1->AbsObjects);
    pTable = v1->GlobalObjects.pTable;
    if ( pTable )
    {
      v11 = 0;
      v12 = pTable + 1;
      do
      {
        if ( v12->EntryCount != -2 )
          break;
        ++v11;
        v12 = (Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > >::TableType *)((char *)v12 + 12);
      }
      while ( v11 <= pTable->SizeMask );
      p_GlobalObjects = &v1->GlobalObjects;
    }
    else
    {
      p_GlobalObjects = 0;
      v11 = 0;
    }
    while ( p_GlobalObjects )
    {
      v13 = p_GlobalObjects->pTable;
      if ( !p_GlobalObjects->pTable || (signed int)v11 > (signed int)v13->SizeMask )
        break;
      Scaleform::GFx::AS3::VM::UnregisterGlobalObject(
        v1->VMRef,
        *((Scaleform::GFx::AS3::Instances::fl::GlobalObject **)&v13[2].EntryCount + 3 * v11));
      SizeMask = p_GlobalObjects->pTable->SizeMask;
      if ( (int)v11 <= (int)SizeMask && ++v11 <= SizeMask )
      {
        v15 = &p_GlobalObjects->pTable[1].EntryCount + 3 * v11;
        do
        {
          if ( *v15 != -2 )
            break;
          ++v11;
          v15 += 3;
        }
        while ( v11 <= SizeMask );
      }
    }
    Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>>>>::Clear(&v1->GlobalObjects);
    v16 = &v1->Children.Data.Data;
    if ( v1->Children.Data.Size )
    {
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
        *v16,
        v1->Children.Data.Size);
      if ( (v1->Children.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
      {
        if ( *v16 )
        {
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *v16);
          *v16 = 0;
        }
        v1->Children.Data.Policy.Capacity = 0;
      }
    }
    else if ( !v1->Children.Data.Policy.Capacity )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,340>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,340>,Scaleform::ArrayDefaultPolicy> *)&v1->Children,
        &v1->Children,
        0);
    }
    v1->Children.Data.Size = 0;
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>(&v1->FunctionTraitsCache.mHash);
    v17 = v1->Exceptions.Data.Size;
    v18 = (void **)&v1->Exceptions.Data.Data;
    if ( v17 )
    {
      v19 = (void **)((char *)*v18 + 12 * v17 - 12);
      v20 = v1->Exceptions.Data.Size;
      do
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *v19);
        v19 -= 3;
        --v20;
      }
      while ( v20 );
      if ( (v1->Exceptions.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
      {
        if ( *v18 )
        {
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *v18);
          *v18 = 0;
        }
        v1->Exceptions.Data.Policy.Capacity = 0;
      }
    }
    else if ( !v1->Exceptions.Data.Policy.Capacity )
    {
      Scaleform::ArrayDataBase<Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy>,Scaleform::AllocatorLH<Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy>,340>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &v1->Exceptions.Data,
        &v1->Exceptions,
        0);
    }
    v1->Exceptions.Data.Size = 0;
    __1__HashSetBase_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12_UNodeAltHashF_12_U__AllocatorLH_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___0BFE__2_V__HashsetCachedNodeEntry_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12__2__Scaleform__QAE_XZ(&v1->IntNamespaces.Entries.mHash);
    p_IntNamespaceSets = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> **)&v1->IntNamespaceSets;
    if ( v1->IntNamespaceSets.Data.Size )
    {
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
        *p_IntNamespaceSets,
        v1->IntNamespaceSets.Data.Size);
      if ( (v1->IntNamespaceSets.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
      {
        if ( *p_IntNamespaceSets )
        {
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *p_IntNamespaceSets);
          *p_IntNamespaceSets = 0;
        }
        v1->IntNamespaceSets.Data.Policy.Capacity = 0;
      }
    }
    else if ( !v1->IntNamespaceSets.Data.Policy.Capacity )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,340>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &v1->IntNamespaceSets.Data,
        &v1->IntNamespaceSets,
        0);
    }
    v1->IntNamespaceSets.Data.Size = 0;
    v22 = v1->IntStrings.Data.Size;
    p_IntStrings = &v1->IntStrings;
    if ( v22 )
    {
      p_pObject = &p_IntStrings->Data.Data[v22 - 1].pObject;
      v25 = v1->IntStrings.Data.Size;
      do
      {
        v26 = *p_pObject;
        if ( *p_pObject )
        {
          if ( ((unsigned __int8)v26 & 1) != 0 )
          {
            *p_pObject = (Scaleform::GFx::ASStringNode *)((char *)v26 - 1);
          }
          else if ( v26->RefCount-- == 1 )
          {
            Scaleform::GFx::ASStringNode::ReleaseNode(v26);
          }
        }
        --p_pObject;
        --v25;
      }
      while ( v25 );
      if ( (v1->IntStrings.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
      {
        if ( p_IntStrings->Data.Data )
        {
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_IntStrings->Data.Data);
          p_IntStrings->Data.Data = 0;
        }
        v1->IntStrings.Data.Policy.Capacity = 0;
      }
      v1 = this;
      goto LABEL_72;
    }
    if ( v1->IntStrings.Data.Policy.Capacity )
    {
LABEL_72:
      p_IntStrings->Data.Size = 0;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *)&v1->ActivationTraitsCache);
      return;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,340>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,340>,Scaleform::ArrayDefaultPolicy> *)&v1->IntStrings,
      &v1->IntStrings,
      0);
    v1->IntStrings.Data.Size = 0;
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *)&v1->ActivationTraitsCache);
  }
}
