void __thiscall Scaleform::StatsUpdate::SummaryMemoryVisitor::Visit(
        Scaleform::StatsUpdate::SummaryMemoryVisitor *this,
        Scaleform::MemoryHeap *parent,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap_vtbl *v4; // edx

  if ( ((heap->Info.Desc.Flags & 0x1000) != 0) == this->Debug )
  {
    v4 = heap->__vftable;
    switch ( heap->Info.Desc.HeapId )
    {
      case 3u:
        this->MovieViewMemory += v4->GetUsedSpace(heap);
        break;
      case 4u:
        this->MovieDataMemory += ((int (__fastcall *)(Scaleform::MemoryHeap *))v4->GetUsedSpace)(heap);
        Scaleform::MemoryHeap::VisitChildHeaps(heap, this);
        return;
      case 8u:
        this->VideoMemory += ((int (__fastcall *)(Scaleform::MemoryHeap *))v4->GetTotalUsedSpace)(heap);
        break;
      default:
        this->OtherMemory += ((int (__fastcall *)(Scaleform::MemoryHeap *))v4->GetUsedSpace)(heap);
        break;
    }
  }
  Scaleform::MemoryHeap::VisitChildHeaps(heap, this);
}
