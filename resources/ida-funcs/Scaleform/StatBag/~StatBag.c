void __thiscall Scaleform::StatBag::~StatBag(Scaleform::StatBag *this)
{
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pMem);
}
