void *__thiscall Scaleform::HeapPT::AllocEngine::allocBitSet(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::HeapSegment *size)
{
  unsigned int v2; // ebx
  Scaleform::HeapPT::AllocBitSet2 *p_Allocator; // ebp
  void *result; // eax
  unsigned int v6; // esi
  unsigned int v7; // eax
  bool limHandlerOK; // [esp+13h] [ebp-1h] BYREF

  v2 = (unsigned int)size;
  limHandlerOK = 0;
  p_Allocator = &this->Allocator;
  while ( 1 )
  {
    result = Scaleform::HeapPT::AllocBitSet2::Alloc(p_Allocator, v2, &size);
    if ( result )
      break;
    v6 = this->MinAlignMask + 1;
    v7 = Scaleform::HeapPT::AllocEngine::calcDynaSize(this);
    if ( !Scaleform::HeapPT::AllocEngine::allocSegmentBitSet(this, v2, v6, v7, &limHandlerOK) )
    {
      if ( !limHandlerOK )
        return 0;
      Scaleform::HeapPT::AllocEngine::allocSegmentBitSet(this, v2, v6, this->Granularity, &limHandlerOK);
    }
    if ( !limHandlerOK )
      return 0;
  }
  ++size->UseCount;
  return result;
}


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
