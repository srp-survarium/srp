void __thiscall Scaleform::StatBag::StatBag(Scaleform::StatBag *this, const Scaleform::StatBag *source)
{
  this->pMem = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 0x2000, 0);
  this->MemSize = 0x2000;
  if ( this != source )
  {
    this->MemAllocOffset = 0;
    memset(this->IdPageTable, 0xFFu, sizeof(this->IdPageTable));
    Scaleform::StatBag::CombineStatBags(
      this,
      source,
      (bool (__thiscall *)(Scaleform::StatBag *, unsigned int, Scaleform::Stat *))Scaleform::StatBag::Add);
  }
}


void __thiscall Scaleform::StatBag::StatBag(
        Scaleform::StatBag *this,
        Scaleform::MemoryHeap *pheap,
        unsigned int memReserve)
{
  Scaleform::MemoryHeap *v4; // ecx

  v4 = pheap;
  if ( !pheap )
    v4 = Scaleform::Memory::pGlobalHeap;
  this->pMem = (unsigned __int8 *)v4->Alloc(v4, memReserve, 0);
  this->MemSize = memReserve;
  this->MemAllocOffset = 0;
  memset(this->IdPageTable, 0xFFu, sizeof(this->IdPageTable));
}
