void __thiscall Scaleform::HeapPT::Bookkeeper::Free(
        Scaleform::HeapPT::Bookkeeper *this,
        unsigned int ptr,
        unsigned int size)
{
  Scaleform::HeapPT::HeapHeader1 *pTable; // eax
  Scaleform::Heap::HeapSegment *pSegment; // esi
  unsigned int v6; // edi

  pTable = Scaleform::HeapPT::GlobalPageTable->RootTable[ptr >> 20].pTable;
  if ( pTable )
    pSegment = pTable[(unsigned __int8)(ptr >> 12)].pSegment;
  else
    pSegment = 0;
  v6 = size;
  if ( size < 0x10 )
    v6 = 16;
  Scaleform::HeapPT::AllocBitSet1::Free(
    &this->Allocator,
    pSegment,
    (void *)ptr,
    ~this->Allocator.MinAlignMask & (this->Allocator.MinAlignMask + v6));
  if ( pSegment->UseCount-- == 1 )
    Scaleform::HeapPT::Bookkeeper::freeSegment(this, pSegment);
}
