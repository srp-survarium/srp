void __thiscall Scaleform::GFx::AS3::VMFile::ForEachChild_GC(
        Scaleform::GFx::AS3::VMFile *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  unsigned int Size; // ebx
  unsigned int i; // edi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet> *Data; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> >::TableType *pTable; // ecx
  Scaleform::HashLH<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>,340,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> > *p_ActivationTraitsCache; // esi
  unsigned int v9; // eax
  unsigned int SizeMask; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> >::TableType *v11; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> >::TableType *v12; // edi
  signed int v13; // esi
  unsigned int EntryCount; // eax
  bool v15; // zf
  const Scaleform::GFx::AS3::RefCountBaseGC<328> **v16; // eax
  unsigned int v17; // eax
  _DWORD *v18; // ecx

  Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::ForEachChild_GC(
    &this->IntNamespaces,
    prcc,
    op);
  Size = this->IntNamespaceSets.Data.Size;
  for ( i = 0; i < Size; ++i )
  {
    Data = this->IntNamespaceSets.Data.Data;
    if ( Data[i].pObject )
      op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&Data[i].pObject);
  }
  pTable = this->ActivationTraitsCache.mHash.pTable;
  p_ActivationTraitsCache = &this->ActivationTraitsCache;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v9 = 0;
    v11 = pTable + 1;
    do
    {
      if ( v11->EntryCount != -2 )
        break;
      ++v9;
      v11 += 2;
    }
    while ( v9 <= SizeMask );
    pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> >::TableType *)p_ActivationTraitsCache;
  }
  else
  {
    v9 = 0;
  }
  v12 = pTable;
  v13 = v9;
  while ( v12 )
  {
    EntryCount = v12->EntryCount;
    if ( !v12->EntryCount || v13 > *(_DWORD *)(EntryCount + 4) )
      break;
    v15 = *(_DWORD *)(16 * v13 + EntryCount + 20) == 0;
    v16 = (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)(16 * v13 + EntryCount + 20);
    if ( !v15 )
      op(prcc, v16);
    v17 = *(_DWORD *)(v12->EntryCount + 4);
    if ( v13 <= (int)v17 && ++v13 <= v17 )
    {
      v18 = (_DWORD *)(16 * v13 + v12->EntryCount + 8);
      do
      {
        if ( *v18 != -2 )
          break;
        ++v13;
        v18 += 4;
      }
      while ( v13 <= v17 );
    }
  }
}
