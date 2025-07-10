void __thiscall Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::~PagedStack<Scaleform::GFx::AS2::Value,32>(
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *this)
{
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v2; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *pNext; // edi

  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(
    this,
    32 * (this->Pages.Data.Size - 1) + this->pCurrent - this->pPageStart);
  if ( this->pCurrent->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this->pCurrent);
  v2 = this->Pages.Data.Data[this->Pages.Data.Size - 1];
  v2->pNext = this->pReserved;
  this->pReserved = v2;
  do
  {
    pNext = this->pReserved->pNext;
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pReserved);
    this->pReserved = pNext;
  }
  while ( pNext );
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Pages.Data.Data);
}
