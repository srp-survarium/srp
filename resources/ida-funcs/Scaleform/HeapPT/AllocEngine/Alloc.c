unsigned __int8 *__thiscall Scaleform::HeapPT::AllocEngine::Alloc(
        Scaleform::HeapPT::AllocEngine *this,
        unsigned int size)
{
  unsigned int v3; // ecx
  unsigned int v4; // edi
  unsigned int MinAlignShift; // ecx
  unsigned __int8 *result; // eax

  v3 = size;
  if ( size < 0x10 )
    v3 = 16;
  v4 = ~this->MinAlignMask & (this->MinAlignMask + v3);
  if ( !this->AllowTinyBlocks
    || (MinAlignShift = this->MinAlignShift, v4 > 8 << MinAlignShift)
    || (result = (unsigned __int8 *)Scaleform::HeapPT::AllocEngine::allocTiny(this, (v4 - 1) >> MinAlignShift)) == 0
    && (result = (unsigned __int8 *)Scaleform::HeapPT::AllocEngine::allocTiny(this, (v4 - 1) >> this->MinAlignShift)) == 0 )
  {
    if ( v4 >= this->Threshold )
      return Scaleform::HeapPT::AllocEngine::allocSysDirect(this, v4, 0x1000u);
    else
      return (unsigned __int8 *)Scaleform::HeapPT::AllocEngine::allocBitSet(this, v4);
  }
  return result;
}


unsigned __int8 *__thiscall Scaleform::HeapPT::AllocEngine::Alloc(
        Scaleform::HeapPT::AllocEngine *this,
        unsigned int size,
        unsigned int alignSize)
{
  unsigned int v3; // ebp
  unsigned int MinAlignMask; // ecx
  unsigned __int8 *result; // eax
  unsigned int v7; // eax
  unsigned int v8; // ecx
  unsigned int v9; // edi
  unsigned int MinAlignShift; // ecx

  v3 = alignSize;
  MinAlignMask = this->MinAlignMask;
  if ( alignSize - 1 <= MinAlignMask )
    return Scaleform::HeapPT::AllocEngine::Alloc(this, size);
  v7 = size;
  if ( size < 0x10 )
    v7 = 16;
  v8 = MinAlignMask + 1;
  if ( alignSize < v8 )
    v3 = v8;
  if ( v7 < v3 )
    v7 = v3;
  v9 = ~(v3 - 1) & (v7 + v3 - 1);
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
      return Scaleform::HeapPT::AllocEngine::allocSysDirect(this, v9, v3);
    else
      return Scaleform::HeapPT::AllocEngine::allocBitSet(this, v9, v3);
  }
  return result;
}
