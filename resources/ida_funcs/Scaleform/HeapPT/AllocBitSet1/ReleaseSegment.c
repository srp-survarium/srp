void __thiscall Scaleform::HeapPT::AllocBitSet1::ReleaseSegment(
        Scaleform::HeapPT::AllocBitSet2 *this,
        Scaleform::Heap::HeapSegment *seg)
{
  Scaleform::HeapPT::FreeBin::Pull(&this->Bin, (Scaleform::HeapPT::BinTNode *)seg->pData);
}
