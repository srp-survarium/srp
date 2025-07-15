void __thiscall Scaleform::HeapPT::AllocEngine::VisitMem(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::MemVisitor *visitor,
        unsigned int flags)
{
  Scaleform::Heap::HeapSegment *j; // esi
  unsigned int v5; // ebp
  unsigned int v6; // edx
  Scaleform::List<Scaleform::HeapPT::AllocEngine::TinyBlock,Scaleform::HeapPT::AllocEngine::TinyBlock> *TinyBlocks; // ebp
  unsigned int k; // esi
  unsigned int i; // [esp+24h] [ebp+8h]

  if ( (flags & 1) != 0 )
    this->pSysAlloc->VisitMem(this->pSysAlloc, visitor);
  if ( (flags & 2) != 0 )
    Scaleform::HeapPT::Starter::VisitMem(Scaleform::HeapPT::GlobalPageTable->pStarter, visitor);
  if ( (flags & 4) != 0 )
    Scaleform::HeapPT::Bookkeeper::VisitMem(this->pBookkeeper, visitor, flags);
  if ( (flags & 0x10) != 0 )
  {
    for ( j = this->SegmentList.Root.pNext; j != (Scaleform::Heap::HeapSegment *)&this->SegmentList; j = j->pNext )
    {
      switch ( j->SegType )
      {
        case 0u:
        case 1u:
        case 2u:
        case 3u:
        case 4u:
        case 5u:
        case 6u:
        case 7u:
          visitor->Visit(visitor, j, (unsigned int)j->pData, j->DataSize, Cat_AllocTiny);
          v5 = (j->SegType + 1) << this->MinAlignShift;
          v6 = j->DataSize % v5;
          if ( v6 )
            visitor->Visit(visitor, j, (unsigned int)&j->pData[v5 * (j->DataSize / v5)], v6, Cat_AllocTinyFree);
          break;
        case 9u:
          visitor->Visit(visitor, j, (unsigned int)j->pData, j->DataSize, Cat_SystemDirect);
          break;
        case 0xAu:
          visitor->Visit(visitor, j, (unsigned int)j->pData, j->DataSize, Cat_AllocBitSet);
          break;
        default:
          continue;
      }
    }
    if ( (flags & 0x20) != 0 )
    {
      Scaleform::HeapPT::FreeBin::VisitMem(
        &this->Allocator.Bin,
        visitor,
        this->Allocator.MinAlignShift,
        Cat_AllocBitSetFree);
      i = 0;
      TinyBlocks = this->TinyBlocks;
      do
      {
        for ( k = (unsigned int)TinyBlocks->Root.pNext;
              (Scaleform::List<Scaleform::HeapPT::AllocEngine::TinyBlock,Scaleform::HeapPT::AllocEngine::TinyBlock> *)k != TinyBlocks;
              k = *(_DWORD *)(k + 4) )
        {
          visitor->Visit(
            visitor,
            *(const Scaleform::Heap::HeapSegment **)(k + 8),
            k,
            (i + 1) << this->MinAlignShift,
            Cat_AllocTinyFree);
        }
        ++TinyBlocks;
        ++i;
      }
      while ( i < 8 );
    }
  }
}
