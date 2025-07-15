Scaleform::GFx::AS3::Instances::fl_system::Domain *__thiscall Scaleform::GFx::AS3::Instances::fl_system::Domain::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_system::Domain *this,
        char a2)
{
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->FileData.Data.Data);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
    this->Files.Data.Data,
    this->Files.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Files.Data.Data);
  Scaleform::GFx::AS3::Instance::~Instance(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
