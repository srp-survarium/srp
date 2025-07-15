void __thiscall Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase(Scaleform::GFx::AS3::GASRefCountBase *this)
{
  unsigned int v2; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *v3; // edi
  int Index; // eax
  int v5; // eax
  _DWORD *v6; // eax
  bool v7; // zf
  Scaleform::GFx::AS3::GASRefCountBase *key; // [esp+4h] [ebp-4h] BYREF

  v2 = this->RefCount >> 26;
  this->__vftable = (Scaleform::GFx::AS3::GASRefCountBase_vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable';
  if ( (v2 & 1) != 0 )
  {
    v3 = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *)((this->pRCCRaw & 0xFFFFFFFC) + 68);
    key = this;
    Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>::findIndexAlt<unsigned long>(
              v3,
              (unsigned int *)&key);
    if ( Index >= 0 )
    {
      v5 = (int)&v3->pTable[2 * Index + 2];
      if ( v5 )
      {
        v6 = *(_DWORD **)(v5 + 4);
        if ( v6 )
        {
          v7 = (*v6)-- == 1;
          v6[1] = 0;
          if ( v7 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
          key = this;
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF>>::RemoveAlt<Scaleform::GFx::AS3::GASRefCountBase *>(
            (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> > *)v3,
            &key);
        }
      }
    }
  }
  this->__vftable = (Scaleform::GFx::AS3::GASRefCountBase_vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable';
}
