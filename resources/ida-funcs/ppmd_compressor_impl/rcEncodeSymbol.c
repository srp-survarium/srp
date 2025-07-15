void __thiscall ppmd_compressor_impl::rcEncodeSymbol(ppmd_compressor_impl *this)
{
  unsigned int v1; // eax
  unsigned int low; // edx

  v1 = this->m_range / this->m_SubRange.scale;
  low = this->m_SubRange.low;
  this->m_low += v1 * low;
  this->m_range = v1 * (this->m_SubRange.high - low);
}
