unsigned int __thiscall Scaleform::HeapPT::AllocEngine::calcDynaSize(Scaleform::HeapPT::AllocEngine *this)
{
  unsigned int Granularity; // edi
  unsigned int v2; // edx

  if ( !this->AllowDynaSize )
    return this->Granularity;
  Granularity = this->Granularity;
  v2 = 1 << Scaleform::Alg::UpperBit(
              Granularity
            * ((((this->Footprint
                - (this->Allocator.Bin.FreeBlocks << this->Allocator.MinAlignShift)
                - this->TinyFreeSpace
                + 16) >> 4)
              + Granularity
              - 1)
             / Granularity));
  if ( v2 < Granularity )
    v2 = Granularity;
  if ( v2 > 4 * Granularity )
    return 4 * Granularity;
  return v2;
}
