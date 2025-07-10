void __thiscall Scaleform::HeapPT::AllocBitSet2::AllocBitSet2(
        Scaleform::HeapPT::AllocBitSet2 *this,
        unsigned int minAlignShift)
{
  this->MinAlignShift = minAlignShift;
  this->MinAlignMask = (1 << minAlignShift) - 1;
  Scaleform::HeapPT::FreeBin::FreeBin(&this->Bin);
}
