void __userpurge PPM_CONTEXT::encodeSymbol1(PPM_CONTEXT *this@<eax>, ppmd_compressor_impl *impl@<edi>, int symbol)
{
  PPM_CONTEXT::STATE *Stats; // eax
  unsigned int SummFreq; // edx
  bool v6; // zf
  unsigned int Freq; // ecx
  PPM_CONTEXT *PrevSuccess; // ecx
  int NumStats; // edx
  int EscCount; // edx
  int v11; // ecx

  Stats = this->Stats;
  SummFreq = this->SummFreq;
  v6 = Stats->Symbol == symbol;
  impl->m_SubRange.scale = SummFreq;
  Freq = Stats->Freq;
  if ( v6 )
  {
    impl->m_SubRange.high = Freq;
    impl->PrevSuccess = 2 * Freq >= SummFreq;
    impl->FoundState = Stats;
    Stats->Freq += 4;
    this->SummFreq += 4;
    PrevSuccess = (PPM_CONTEXT *)impl->PrevSuccess;
    impl->RunLength += (int)PrevSuccess;
    if ( Stats->Freq > 0x7Cu )
      PPM_CONTEXT::rescale(PrevSuccess, &this->NumStats, impl);
    impl->m_SubRange.low = 0;
  }
  else
  {
    NumStats = this->NumStats;
    impl->PrevSuccess = 0;
    do
    {
      ++Stats;
      if ( Stats->Symbol == symbol )
      {
        impl->m_SubRange.low = Freq;
        impl->m_SubRange.high = Freq + Stats->Freq;
        PPM_CONTEXT::update1(Stats, this, impl);
        return;
      }
      Freq += Stats->Freq;
      --NumStats;
    }
    while ( NumStats );
    EscCount = impl->EscCount;
    impl->m_SubRange.low = Freq;
    impl->CharMask[Stats->Symbol] = EscCount;
    LOBYTE(v11) = this->NumStats;
    impl->FoundState = 0;
    impl->NumMasked = v11;
    v11 = (unsigned __int8)v11;
    do
    {
      --Stats;
      --v11;
      impl->CharMask[Stats->Symbol] = impl->EscCount;
    }
    while ( v11 );
    impl->m_SubRange.high = impl->m_SubRange.scale;
  }
}
