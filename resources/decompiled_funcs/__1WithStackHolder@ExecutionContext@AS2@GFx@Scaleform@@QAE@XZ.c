void __thiscall Scaleform::GFx::AS2::ExecutionContext::WithStackHolder::~WithStackHolder(
        Scaleform::GFx::AS2::ExecutionContext::WithStackHolder *this)
{
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pWithStackArray; // esi

  pWithStackArray = this->pWithStackArray;
  if ( pWithStackArray )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWithStackArray->Data.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWithStackArray);
  }
}
