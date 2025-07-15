Scaleform::MemoryHeapPT *__thiscall Scaleform::MemoryHeapPT::GetAllocHeap(
        Scaleform::MemoryHeapPT *this,
        unsigned int thisPtr)
{
  return Scaleform::HeapPT::GlobalPageTable->RootTable[thisPtr >> 20].pTable[(unsigned __int8)(thisPtr >> 12)].pSegment->pHeap;
}
