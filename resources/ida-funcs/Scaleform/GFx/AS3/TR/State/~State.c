void __thiscall Scaleform::GFx::AS3::TR::State::~State(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->RegistersAlive.pData);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
    this->ScopeStack.Data.Data,
    this->ScopeStack.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->ScopeStack.Data.Data);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(this->OpStack.Data.Data, this->OpStack.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->OpStack.Data.Data);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
    this->Registers.Data.Data,
    this->Registers.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Registers.Data.Data);
}
