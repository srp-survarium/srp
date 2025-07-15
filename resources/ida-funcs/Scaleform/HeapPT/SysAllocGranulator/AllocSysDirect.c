void *__thiscall Scaleform::HeapPT::SysAllocGranulator::AllocSysDirect(
        Scaleform::HeapPT::SysAllocGranulator *this,
        unsigned int size,
        unsigned int alignment,
        unsigned int *actualSize,
        unsigned int *actualAlign)
{
  unsigned int MinAlign; // eax
  unsigned int v6; // esi
  unsigned int v7; // edx

  MinAlign = alignment;
  v6 = alignment;
  if ( alignment < 0x1000 )
    v6 = 4096;
  if ( alignment < this->MinAlign )
    MinAlign = this->MinAlign;
  if ( MinAlign > this->MaxAlign )
    MinAlign = this->MaxAlign;
  v7 = size;
  if ( MinAlign < v6 )
    v7 = v6 + size;
  *actualSize = v7;
  *actualAlign = MinAlign;
  this->SysDirectFootprint += v7;
  return this->pGranulator->pSysAlloc->Alloc(this->pGranulator->pSysAlloc, v7, MinAlign);
}
