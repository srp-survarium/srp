void __thiscall Scaleform::GFx::AS3::Traits::~Traits(Scaleform::GFx::AS3::Traits *this)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Class *v4; // ecx
  unsigned int v5; // eax

  this->__vftable = (Scaleform::GFx::AS3::Traits_vtbl *)&Scaleform::GFx::AS3::Traits::`vftable';
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
    this->InitScope.Data.Data,
    this->InitScope.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->InitScope.Data.Data);
  Scaleform::AutoPtr<Scaleform::GFx::AS3::VTable>::~AutoPtr<Scaleform::GFx::AS3::VTable>(&this->pVTable);
  pObject = (Scaleform::GFx::AS3::Traits *)this->pParent.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->pParent.pObject = (Scaleform::GFx::AS3::Traits *)((char *)pObject - 1);
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
  v4 = this->pConstructor.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->pConstructor.pObject = (Scaleform::GFx::AS3::Class *)((char *)v4 - 1);
    }
    else
    {
      v5 = v4->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v5) != 0 )
      {
        v4->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
      }
    }
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF>>::Clear(&this->Set.mHash);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Slots::Pair>::DestructArray(
    this->VArray.Data.Data,
    this->VArray.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->VArray.Data.Data);
  Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase(this);
}
