void __usercall PPM_CONTEXT::decodeSymbol1(PPM_CONTEXT *this@<eax>, ppmd_compressor_impl *impl@<edi>)
{
  PPM_CONTEXT::STATE *Stats; // eax
  unsigned int Freq; // ecx
  unsigned int SummFreq; // ebx
  unsigned int v6; // eax
  unsigned int v7; // ebx
  unsigned int v8; // eax
  unsigned int v9; // edx
  bool v10; // cf
  PPM_CONTEXT *v11; // ecx
  PPM_CONTEXT::STATE *v12; // eax
  int v13; // ebx
  unsigned __int8 EscCount; // dl
  int v15; // ecx
  int NumStats; // [esp+8h] [ebp-8h]
  PPM_CONTEXT::STATE *v17; // [esp+Ch] [ebp-4h]

  Stats = this->Stats;
  Freq = Stats->Freq;
  SummFreq = this->SummFreq;
  v17 = Stats;
  v6 = impl->m_range / SummFreq;
  impl->m_SubRange.scale = SummFreq;
  v7 = v6;
  v8 = impl->m_code - impl->m_low;
  impl->m_range = v7;
  v9 = v8 / v7;
  if ( v8 / v7 >= Freq )
  {
    NumStats = this->NumStats;
    v12 = v17;
    impl->PrevSuccess = 0;
    do
    {
      v13 = v12[1].Freq;
      ++v12;
      Freq += v13;
      if ( Freq > v9 )
      {
        impl->m_SubRange.high = Freq;
        impl->m_SubRange.low = Freq - v12->Freq;
        PPM_CONTEXT::update1(v12, this, impl);
        return;
      }
      --NumStats;
    }
    while ( NumStats );
    EscCount = impl->EscCount;
    impl->m_SubRange.low = Freq;
    impl->CharMask[v12->Symbol] = EscCount;
    LOBYTE(v15) = this->NumStats;
    impl->FoundState = 0;
    impl->NumMasked = v15;
    v15 = (unsigned __int8)v15;
    do
    {
      --v12;
      --v15;
      impl->CharMask[v12->Symbol] = impl->EscCount;
    }
    while ( v15 );
    impl->m_SubRange.high = impl->m_SubRange.scale;
  }
  else
  {
    v10 = 2 * Freq < impl->m_SubRange.scale;
    impl->m_SubRange.high = Freq;
    impl->PrevSuccess = 1 - v10;
    v11 = (PPM_CONTEXT *)(Freq + 4);
    impl->FoundState = v17;
    v17->Freq = (unsigned __int8)v11;
    this->SummFreq += 4;
    impl->RunLength += impl->PrevSuccess;
    if ( (unsigned int)v11 > 0x7C )
      PPM_CONTEXT::rescale(v11, &this->NumStats, impl);
    impl->m_SubRange.low = 0;
  }
}
