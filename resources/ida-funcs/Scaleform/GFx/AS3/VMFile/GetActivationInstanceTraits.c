Scaleform::GFx::AS3::InstanceTraits::Traits *__thiscall Scaleform::GFx::AS3::VMFile::GetActivationInstanceTraits(
        Scaleform::GFx::AS3::VMFile *this,
        const Scaleform::GFx::AS3::Abc::MbiInd mbi_ind,
        Scaleform::GFx::AS3::InstanceTraits::Traits *name)
{
  Scaleform::HashLH<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>,340,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> > *p_ActivationTraitsCache; // esi
  int Index; // eax
  int v6; // eax
  int v7; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v9; // ecx
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> t; // [esp+Ch] [ebp-4h] BYREF

  p_ActivationTraitsCache = &this->ActivationTraitsCache;
  Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>::findIndexAlt<unsigned long>(
            (Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *)&this->ActivationTraitsCache,
            (unsigned int *)&mbi_ind);
  if ( Index >= 0 )
  {
    v6 = (int)&p_ActivationTraitsCache->mHash.pTable[2 * Index + 2];
    if ( v6 )
    {
      v7 = v6 + 4;
      if ( v7 )
        return *(Scaleform::GFx::AS3::InstanceTraits::Traits **)v7;
    }
  }
  ((void (__thiscall *)(Scaleform::GFx::AS3::VMFile *, Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> *, int, Scaleform::GFx::AS3::InstanceTraits::Traits *))this->MakeActivationInstanceTraits)(
    this,
    &t,
    mbi_ind.Ind,
    name);
  name = t.pV;
  Scaleform::Hash<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF>>>::Add(
    p_ActivationTraitsCache,
    &mbi_ind,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> *)&name);
  if ( name && ((unsigned __int8)name & 1) == 0 )
  {
    RefCount = name->RefCount;
    v9 = name;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      name->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
    }
  }
  return t.pV;
}
