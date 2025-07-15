Scaleform::Heap::HeapSegment *__thiscall Scaleform::HeapPT::Bookkeeper::Alloc(
        Scaleform::HeapPT::Bookkeeper *this,
        Scaleform::Heap::HeapSegment *size)
{
  int v3; // ecx
  Scaleform::HeapPT::AllocBitSet1 *p_Allocator; // edi
  unsigned int v5; // esi
  Scaleform::Heap::HeapSegment *result; // eax
  unsigned int v7; // eax
  unsigned int Granularity; // edx
  unsigned int MinAlignMask; // ebx
  Scaleform::HeapPT::Bookkeeper *v10; // [esp+Ch] [ebp-8h]
  Scaleform::Heap::HeapSegment *t; // [esp+10h] [ebp-4h] BYREF

  v3 = (int)size;
  v10 = this;
  if ( (unsigned int)size < 0x10 )
    v3 = 16;
  p_Allocator = &this->Allocator;
  v5 = ~this->Allocator.MinAlignMask & (this->Allocator.MinAlignMask + v3);
  result = (Scaleform::Heap::HeapSegment *)Scaleform::HeapPT::AllocBitSet1::Alloc(&this->Allocator, v5, &size);
  if ( result )
    goto LABEL_10;
  v7 = this->Granularity * ((this->Granularity + v5 - 1) / this->Granularity);
  if ( v7 < v5
          + ((4 * ((((v7 + this->Allocator.MinAlignMask) >> this->Allocator.MinAlignShift) + 31) >> 5) + 47) & 0xFFFFFFF0) )
  {
    Granularity = this->Granularity;
    MinAlignMask = this->Allocator.MinAlignMask;
    do
      v7 += Granularity;
    while ( v7 < v5 + ((4 * ((((MinAlignMask + v7) >> p_Allocator->MinAlignShift) + 31) >> 5) + 47) & 0xFFFFFFF0) );
    this = v10;
  }
  result = Scaleform::HeapPT::Bookkeeper::allocSegment(this, v7);
  size = result;
  if ( result )
  {
    result = (Scaleform::Heap::HeapSegment *)Scaleform::HeapPT::AllocBitSet1::Alloc(p_Allocator, v5, &t);
LABEL_10:
    ++size->UseCount;
  }
  return result;
}
