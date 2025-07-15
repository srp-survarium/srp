bool __thiscall Scaleform::SysAllocMapper::ReallocInPlace(
        Scaleform::SysAllocMapper *this,
        unsigned __int8 *oldPtr,
        unsigned int oldSize,
        unsigned int newSize,
        unsigned int alignment)
{
  unsigned int v5; // eax
  unsigned int PageSize; // ebp
  int v8; // edx
  unsigned int v9; // ecx
  unsigned int v10; // edi
  bool result; // al
  unsigned int Segment; // eax
  unsigned int v13; // edx
  unsigned __int8 *Memory; // ecx
  unsigned int PageShift; // eax
  unsigned int *v16; // esi
  unsigned int v17; // edi
  int start; // [esp+10h] [ebp+4h]
  unsigned int v19; // [esp+18h] [ebp+Ch]
  unsigned int v20; // [esp+18h] [ebp+Ch]
  Scaleform::SysAllocMapper::Segment *v21; // [esp+1Ch] [ebp+10h]

  v5 = alignment;
  PageSize = this->PageSize;
  if ( alignment < PageSize )
    v5 = this->PageSize;
  v8 = ~(v5 - 1);
  v9 = v8 & (newSize + v5 - 1);
  v10 = v8 & (oldSize + v5 - 1);
  v19 = v9;
  if ( v9 == v10 )
    return 1;
  if ( v9 <= v10 )
    return this->Free(this, &oldPtr[v9], v10 - v9, v5);
  Segment = Scaleform::SysAllocMapper::findSegment(this, oldPtr);
  v13 = Segment;
  Memory = this->Segments[Segment].Memory;
  PageShift = this->PageShift;
  v21 = &this->Segments[v13];
  start = (int)(v10 + oldPtr - Memory) >> PageShift;
  v16 = (unsigned int *)&Memory[this->Segments[v13].Size
                              - (~(PageSize - 1)
                               & (((this->Segments[v13].Size + 8 * PageSize - 1) >> (PageShift + 3)) + PageSize - 1))];
  v20 = v19 - v10;
  v17 = v20 >> PageShift;
  if ( Scaleform::HeapPT::BitSet1::FindFreeSize(v16, start) < v20 >> PageShift
    || !this->pMapper->MapPages(this->pMapper, &v21->Memory[start * PageSize], v20) )
  {
    return 0;
  }
  Scaleform::HeapPT::BitSet1::SetUsed(v16, start, v17);
  v21->PageCount += v17;
  result = 1;
  this->Footprint += v17 << this->PageShift;
  return result;
}
