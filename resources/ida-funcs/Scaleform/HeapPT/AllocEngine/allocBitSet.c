Scaleform::HeapPT::BinTNode *__thiscall Scaleform::HeapPT::AllocEngine::allocBitSet(
        Scaleform::HeapPT::AllocEngine *this,
        unsigned int size)
{
  unsigned int v2; // ebx
  Scaleform::HeapPT::AllocBitSet2 *p_Allocator; // ebp
  Scaleform::HeapPT::BinTNode *result; // eax
  unsigned int v6; // esi
  unsigned int v7; // eax
  bool limHandlerOK; // [esp+13h] [ebp-1h] BYREF

  v2 = size;
  limHandlerOK = 0;
  p_Allocator = &this->Allocator;
  while ( 1 )
  {
    result = Scaleform::HeapPT::AllocBitSet2::Alloc(p_Allocator, v2, (Scaleform::Heap::HeapSegment **)&size);
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
  ++*(_DWORD *)(size + 16);
  return result;
}


unsigned __int8 *__thiscall Scaleform::HeapPT::AllocEngine::allocBitSet(
        Scaleform::HeapPT::AllocEngine *this,
        unsigned int size,
        unsigned int alignSize)
{
  unsigned int v4; // edi
  Scaleform::HeapPT::AllocBitSet2 *p_Allocator; // ebp
  unsigned __int8 *result; // eax
  unsigned int v7; // eax
  bool limHandlerOK; // [esp+13h] [ebp-1h] BYREF

  v4 = alignSize;
  limHandlerOK = 0;
  p_Allocator = &this->Allocator;
  while ( 1 )
  {
    result = Scaleform::HeapPT::AllocBitSet2::Alloc(p_Allocator, size, v4, (Scaleform::Heap::HeapSegment **)&alignSize);
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
  ++*(_DWORD *)(alignSize + 16);
  return result;
}
