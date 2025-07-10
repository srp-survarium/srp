unsigned __int8 *__thiscall Scaleform::HeapPT::AllocEngine::Alloc(
        Scaleform::HeapPT::AllocEngine *this,
        unsigned int size)
{
  unsigned int v3; // ecx
  Scaleform::Heap::HeapSegment *v4; // edi
  unsigned int MinAlignShift; // ecx
  unsigned __int8 *result; // eax

  v3 = size;
  if ( size < 0x10 )
    v3 = 16;
  v4 = (Scaleform::Heap::HeapSegment *)(~this->MinAlignMask & (this->MinAlignMask + v3));
  if ( !this->AllowTinyBlocks
    || (MinAlignShift = this->MinAlignShift, (unsigned int)v4 > 8 << MinAlignShift)
    || (result = (unsigned __int8 *)Scaleform::HeapPT::AllocEngine::allocTiny(
                                      this,
                                      ((unsigned int)&v4[-1].pData + 3) >> MinAlignShift)) == 0
    && (result = (unsigned __int8 *)Scaleform::HeapPT::AllocEngine::allocTiny(
                                      this,
                                      ((unsigned int)&v4[-1].pData + 3) >> this->MinAlignShift)) == 0 )
  {
    if ( (unsigned int)v4 >= this->Threshold )
      return Scaleform::HeapPT::AllocEngine::allocSysDirect(this, (unsigned int)v4, 0x1000u);
    else
      return (unsigned __int8 *)Scaleform::HeapPT::AllocEngine::allocBitSet(this, v4);
  }
  return result;
}
