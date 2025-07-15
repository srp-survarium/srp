unsigned __int8 *__thiscall Scaleform::HeapPT::Granulator::Alloc(
        Scaleform::HeapPT::Granulator *this,
        unsigned int size,
        Scaleform::HeapPT::TreeSeg *alignSize)
{
  unsigned int v3; // esi
  Scaleform::HeapPT::AllocLite *p_Allocator; // ebx
  unsigned __int8 *result; // eax

  v3 = (unsigned int)alignSize;
  p_Allocator = &this->Allocator;
  result = Scaleform::HeapPT::AllocLite::Alloc(&this->Allocator, size, (unsigned int)alignSize, &alignSize);
  if ( result )
    goto LABEL_7;
  if ( !Scaleform::HeapPT::Granulator::allocSegment(this, size, v3) )
    return 0;
  result = Scaleform::HeapPT::AllocLite::Alloc(p_Allocator, size, v3, &alignSize);
  if ( result )
    goto LABEL_7;
  if ( !Scaleform::HeapPT::Granulator::allocSegment(this, size, v3) )
    return 0;
  result = Scaleform::HeapPT::AllocLite::Alloc(p_Allocator, size, v3, &alignSize);
  if ( result )
LABEL_7:
    ++alignSize->UseCount;
  return result;
}
