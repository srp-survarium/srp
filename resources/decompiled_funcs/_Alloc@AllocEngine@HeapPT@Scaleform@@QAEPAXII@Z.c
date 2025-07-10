unsigned __int8 *__thiscall Scaleform::HeapPT::AllocEngine::Alloc(
        Scaleform::HeapPT::AllocEngine *this,
        unsigned int size,
        Scaleform::Heap::HeapSegment *alignSize)
{
  Scaleform::Heap::HeapSegment *v3; // ebp
  unsigned int MinAlignMask; // ecx
  unsigned __int8 *result; // eax
  unsigned int v7; // eax
  unsigned int v8; // ecx
  unsigned int v9; // edi
  unsigned int MinAlignShift; // ecx

  v3 = alignSize;
  MinAlignMask = this->MinAlignMask;
  if ( (unsigned int)&alignSize[-1].pData + 3 <= MinAlignMask )
    return Scaleform::HeapPT::AllocEngine::Alloc(this, size);
  v7 = size;
  if ( size < 0x10 )
    v7 = 16;
  v8 = MinAlignMask + 1;
  if ( (unsigned int)alignSize < v8 )
    v3 = (Scaleform::Heap::HeapSegment *)v8;
  if ( v7 < (unsigned int)v3 )
    v7 = (unsigned int)v3;
  v9 = ~((unsigned int)&v3[-1].pData + 3) & ((unsigned int)v3 + v7 - 1);
  if ( !this->AllowTinyBlocks
    || (MinAlignShift = this->MinAlignShift, v9 > 8 << MinAlignShift)
    || (result = (unsigned __int8 *)Scaleform::HeapPT::AllocEngine::allocTiny(
                                      this,
                                      TinyPow2AllocType[(v9 - 1) >> MinAlignShift])) == 0
    && (result = (unsigned __int8 *)Scaleform::HeapPT::AllocEngine::allocTiny(
                                      this,
                                      TinyPow2AllocType[(v9 - 1) >> this->MinAlignShift])) == 0 )
  {
    if ( v9 >= this->Threshold )
      return Scaleform::HeapPT::AllocEngine::allocSysDirect(this, v9, (unsigned int)v3);
    else
      return (unsigned __int8 *)Scaleform::HeapPT::AllocEngine::allocBitSet(this, v9, v3);
  }
  return result;
}
