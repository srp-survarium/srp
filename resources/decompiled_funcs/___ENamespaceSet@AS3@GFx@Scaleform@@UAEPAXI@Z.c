Scaleform::GFx::AS3::NamespaceSet *__thiscall Scaleform::GFx::AS3::NamespaceSet::`vector deleting destructor'(
        Scaleform::GFx::AS3::NamespaceSet *this,
        char a2)
{
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)this->Namespaces.Data.Data,
    this->Namespaces.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Namespaces.Data.Data);
  Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
