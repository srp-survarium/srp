void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::~GlobalObjectCPP(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this)
{
  Scaleform::GFx::AS3::Value *p_undefined; // ecx

  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP_vtbl *)&Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::`vftable';
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)this->CTraits.Data.Data,
    this->CTraits.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->CTraits.Data.Data);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(this->Values.Data.Data, this->Values.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Values.Data.Data);
  p_undefined = (Scaleform::GFx::AS3::Value *)&this->undefined;
  if ( (this->undefined.Flags & 0x1F) > 9 )
  {
    if ( (this->undefined.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_undefined);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_undefined);
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,328>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,328>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeHashF>>(&this->CIRegistrationHash.mHash);
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP_vtbl *)&Scaleform::GFx::AS3::Instances::fl::GlobalObject::`vftable';
  Scaleform::GFx::AS3::Instance::~Instance(this);
}
