void __thiscall Scaleform::GFx::AS2::Environment::~Environment(Scaleform::GFx::AS2::Environment *this)
{
  Scaleform::GFx::AS2::Value *p_LocalRegister; // edi
  int i; // ebx

  this->__vftable = (Scaleform::GFx::AS2::Environment_vtbl *)&Scaleform::GFx::AS2::Environment::`vftable';
  Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::AS2::Object>>::DestructArray(
    this->LocalFrames.Data.Data,
    this->LocalFrames.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->LocalFrames.Data.Data);
  if ( this->ThrowingValue.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&this->ThrowingValue);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->TryBlocks.Data.Data);
  Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::~PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>(&this->CallStack);
  Scaleform::ConstructorMov<Scaleform::GFx::AS2::Value>::DestructArray(
    this->LocalRegister.Data.Data,
    this->LocalRegister.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->LocalRegister.Data.Data);
  p_LocalRegister = (Scaleform::GFx::AS2::Value *)&this->LocalRegister;
  for ( i = 3; i >= 0; --i )
  {
    --p_LocalRegister;
    if ( p_LocalRegister->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(p_LocalRegister);
  }
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::~PagedStack<Scaleform::GFx::AS2::Value,32>(&this->Stack);
  this->__vftable = (Scaleform::GFx::AS2::Environment_vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
}
