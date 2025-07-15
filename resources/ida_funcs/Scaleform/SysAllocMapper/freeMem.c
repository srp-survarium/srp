unsigned int __thiscall Scaleform::SysAllocMapper::freeMem(
        Scaleform::SysAllocMapper *this,
        unsigned __int8 *ptr,
        unsigned int size)
{
  Scaleform::SysAllocMapper::Segment *v5; // ebp
  unsigned int PageShift; // ecx
  unsigned int v7; // ebx
  unsigned int result; // eax
  unsigned int pos; // [esp+14h] [ebp+4h]

  pos = Scaleform::SysAllocMapper::findSegment(this, ptr);
  v5 = &this->Segments[pos];
  this->pMapper->UnmapPages(this->pMapper, ptr, size);
  PageShift = this->PageShift;
  v7 = size >> PageShift;
  Scaleform::HeapPT::BitSet1::SetFree(
    (unsigned int *)&v5->Memory[v5->Size
                              - (~(this->PageSize - 1)
                               & (((v5->Size + 8 * this->PageSize - 1) >> (PageShift + 3)) + this->PageSize - 1))],
    (ptr - v5->Memory) >> PageShift,
    size >> PageShift);
  v5->PageCount -= v7;
  result = pos;
  this->Footprint -= v7 << this->PageShift;
  return result;
}
