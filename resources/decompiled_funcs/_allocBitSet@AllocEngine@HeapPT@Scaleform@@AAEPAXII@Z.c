void *__thiscall Scaleform::HeapPT::AllocEngine::allocBitSet(
        Scaleform::HeapPT::AllocEngine *this,
        unsigned int size,
        Scaleform::Heap::HeapSegment *alignSize)
{
  unsigned int v4; // edi
  Scaleform::HeapPT::AllocBitSet2 *p_Allocator; // ebp
  void *result; // eax
  unsigned int v7; // eax
  bool limHandlerOK; // [esp+13h] [ebp-1h] BYREF

  v4 = (unsigned int)alignSize;
  limHandlerOK = 0;
  p_Allocator = &this->Allocator;
  while ( 1 )
  {
    result = Scaleform::HeapPT::AllocBitSet2::Alloc(p_Allocator, size, v4, &alignSize);
    if ( result )
      break;
    v7 = Scaleform::HeapPT::AllocEngine::calcDynaSize(this);
    if ( !Scaleform::HeapPT::AllocEngine::allocSegmentBitSet(this, size, v4, v7, &limHandlerOK) )
    {
      if ( !limHandlerOK )
        return 0;
      Scaleform::HeapPT::AllocEngine::allocSegmentBitSet(this, size, v4, this->Granularity, &limHandlerOK);
    }
    if ( !limHandlerOK )
      return 0;
  }
  ++alignSize->UseCount;
  return result;
}
