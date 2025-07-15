Scaleform::HeapPT::DualTNode *__thiscall Scaleform::HeapPT::Granulator::Alloc(
        Scaleform::HeapPT::Granulator *this,
        unsigned int size,
        unsigned int alignSize)
{
  unsigned int v3; // esi
  Scaleform::HeapPT::AllocLite *p_Allocator; // ebx
  Scaleform::HeapPT::DualTNode *result; // eax

  v3 = alignSize;
  p_Allocator = &this->Allocator;
  result = Scaleform::HeapPT::AllocLite::Alloc(
             &this->Allocator,
             size,
             alignSize,
             (Scaleform::HeapPT::TreeSeg **)&alignSize);
  if ( result )
    goto LABEL_7;
  if ( !Scaleform::HeapPT::Granulator::allocSegment(this, size, v3) )
    return 0;
  result = Scaleform::HeapPT::AllocLite::Alloc(p_Allocator, size, v3, (Scaleform::HeapPT::TreeSeg **)&alignSize);
  if ( result )
    goto LABEL_7;
  if ( !Scaleform::HeapPT::Granulator::allocSegment(this, size, v3) )
    return 0;
  result = Scaleform::HeapPT::AllocLite::Alloc(p_Allocator, size, v3, (Scaleform::HeapPT::TreeSeg **)&alignSize);
  if ( result )
LABEL_7:
    ++*(_DWORD *)(alignSize + 24);
  return result;
}
