Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *__thiscall Scaleform::GFx::AS3::VMAbcFile::GetFunctionInstanceTraits(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *gos,
        unsigned int method_ind)
{
  Scaleform::HashLH<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>,340,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *p_FunctionTraitsCache; // ebx
  signed int Index; // eax
  int v6; // eax
  int v7; // eax
  Scaleform::GFx::AS3::VM *VMRef; // edi
  Scaleform::GFx::AS3::InstanceTraits::Function *v9; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v10; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v11; // esi
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v14; // ecx

  p_FunctionTraitsCache = &this->FunctionTraitsCache;
  Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>::findIndexAlt<unsigned long>(
            &this->FunctionTraitsCache.mHash,
            &method_ind);
  if ( Index >= 0 )
  {
    v6 = (int)&p_FunctionTraitsCache->mHash.pTable[2 * Index + 2];
    if ( v6 )
    {
      v7 = v6 + 4;
      if ( v7 )
        return *(Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript **)v7;
    }
  }
  VMRef = this->VMRef;
  v9 = (Scaleform::GFx::AS3::InstanceTraits::Function *)VMRef->MHeap->Alloc(VMRef->MHeap, 132u, 0);
  if ( v9 )
  {
    Scaleform::GFx::AS3::InstanceTraits::Function::Function(
      v9,
      this,
      &Scaleform::GFx::AS3::fl::FunctionCI,
      method_ind,
      gos);
    v11 = v10;
  }
  else
  {
    v11 = 0;
  }
  if ( VMRef->HandleException )
    return (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)VMRef->NoFunctionTraits.pObject;
  gos = v11;
  Scaleform::Hash<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>>::Add(
    p_FunctionTraitsCache,
    &method_ind,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function> *)&gos);
  if ( gos && ((unsigned __int8)gos & 1) == 0 )
  {
    RefCount = gos->RefCount;
    v14 = gos;
    if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
    {
      gos->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v14);
    }
  }
  return v11;
}
