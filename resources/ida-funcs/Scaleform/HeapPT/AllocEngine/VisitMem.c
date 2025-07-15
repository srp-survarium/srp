void __thiscall Scaleform::HeapPT::AllocEngine::VisitMem(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::MemVisitor *visitor,
        char flags)
{
  Scaleform::Heap::HeapSegment *i; // esi
  unsigned int v5; // ebp
  unsigned int v6; // edx
  Scaleform::List<Scaleform::HeapPT::AllocEngine::TinyBlock,Scaleform::HeapPT::AllocEngine::TinyBlock> *TinyBlocks; // ebp
  unsigned int j; // esi
  unsigned int flagsa; // [esp+24h] [ebp+8h]

  if ( (flags & 1) != 0 )
    this->pSysAlloc->VisitMem(this->pSysAlloc, visitor);
  if ( (flags & 2) != 0 )
    Scaleform::HeapPT::Starter::VisitMem(Scaleform::HeapPT::GlobalPageTable->pStarter, visitor);
  if ( (flags & 4) != 0 )
    Scaleform::HeapPT::Bookkeeper::VisitMem(this->pBookkeeper, visitor, flags);
  if ( (flags & 0x10) != 0 )
  {
    for ( i = this->SegmentList.Root.pNext; i != (Scaleform::Heap::HeapSegment *)&this->SegmentList; i = i->pNext )
    {
      switch ( i->SegType )
      {
        case 0u:
        case 1u:
        case 2u:
        case 3u:
        case 4u:
        case 5u:
        case 6u:
        case 7u:
          visitor->Visit(visitor, i, (unsigned int)i->pData, i->DataSize, Cat_AllocTiny);
          v5 = (i->SegType + 1) << this->MinAlignShift;
          v6 = i->DataSize % v5;
          if ( v6 )
            visitor->Visit(visitor, i, (unsigned int)&i->pData[v5 * (i->DataSize / v5)], v6, Cat_AllocTinyFree);
          break;
        case 9u:
          visitor->Visit(visitor, i, (unsigned int)i->pData, i->DataSize, Cat_SystemDirect);
          break;
        case 0xAu:
          visitor->Visit(visitor, i, (unsigned int)i->pData, i->DataSize, Cat_AllocBitSet);
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
      flagsa = 0;
      TinyBlocks = this->TinyBlocks;
      do
      {
        for ( j = (unsigned int)TinyBlocks->Root.pNext;
              (Scaleform::List<Scaleform::HeapPT::AllocEngine::TinyBlock,Scaleform::HeapPT::AllocEngine::TinyBlock> *)j != TinyBlocks;
              j = *(_DWORD *)(j + 4) )
        {
          visitor->Visit(
            visitor,
            *(const Scaleform::Heap::HeapSegment **)(j + 8),
            j,
            (flagsa + 1) << this->MinAlignShift,
            Cat_AllocTinyFree);
        }
        ++TinyBlocks;
        ++flagsa;
      }
      while ( flagsa < 8 );
    }
  }
}
