void __thiscall Scaleform::GFx::AS3::Traits::~Traits(Scaleform::GFx::AS3::Traits *this)
{
  Scaleform::GFx::AS3::VTable *pObject; // ecx
  const Scaleform::GFx::AS3::Traits *v3; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Class *v5; // ecx
  unsigned int v6; // eax

  this->__vftable = (Scaleform::GFx::AS3::Traits_vtbl *)&Scaleform::GFx::AS3::Traits::`vftable';
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
    this->InitScope.Data.Data,
    this->InitScope.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->InitScope.Data.Data);
  pObject = this->pVTable.pObject;
  if ( pObject )
  {
    if ( this->pVTable.Owner )
    {
      this->pVTable.Owner = 0;
      Scaleform::GFx::AS3::VTable::`scalar deleting destructor'(pObject, 1);
    }
    this->pVTable.pObject = 0;
  }
  this->pVTable.Owner = 0;
  v3 = this->pParent.pObject;
  if ( v3 )
  {
    if ( ((unsigned __int8)v3 & 1) != 0 )
    {
      this->pParent.pObject = (const Scaleform::GFx::AS3::Traits *)((char *)v3 - 1);
    }
    else
    {
      RefCount = v3->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v3->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v3);
      }
    }
  }
  v5 = this->pConstructor.pObject;
  if ( v5 )
  {
    if ( ((unsigned __int8)v5 & 1) != 0 )
    {
      this->pConstructor.pObject = (Scaleform::GFx::AS3::Class *)((char *)v5 - 1);
    }
    else
    {
      v6 = v5->RefCount;
      if ( (v6 & 0x3FFFFF) != 0 )
      {
        v5->RefCount = v6 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v5);
      }
    }
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF>>::Clear(&this->Set.mHash);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Slots::Pair>::DestructArray(
    this->VArray.Data.Data,
    this->VArray.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->VArray.Data.Data);
  Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase(&this->Scaleform::GFx::AS3::GASRefCountBase);
}
