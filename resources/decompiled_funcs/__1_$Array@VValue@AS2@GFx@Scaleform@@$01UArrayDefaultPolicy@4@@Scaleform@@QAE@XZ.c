void __thiscall Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy>::~Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy>(
        Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *this)
{
  Scaleform::GFx::AS2::Value *Data; // esi

  Scaleform::ConstructorMov<Scaleform::GFx::AS2::Value>::DestructArray(this->Data.Data, this->Data.Size);
  Data = this->Data.Data;
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
}
