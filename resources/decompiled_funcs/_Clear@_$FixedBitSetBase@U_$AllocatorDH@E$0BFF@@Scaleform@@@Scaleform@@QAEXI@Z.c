void __thiscall Scaleform::FixedBitSetBase<Scaleform::AllocatorDH<unsigned char,341>>::Clear(
        Scaleform::FixedBitSetBase<Scaleform::AllocatorDH<unsigned char,341> > *this,
        unsigned int bitIndex)
{
  this->pData[bitIndex >> 3] &= ~(1 << (bitIndex & 7));
}
