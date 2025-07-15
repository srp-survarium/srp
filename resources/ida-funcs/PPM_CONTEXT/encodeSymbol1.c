void __usercall PPM_CONTEXT::encodeSymbol1(PPM_CONTEXT *this@<ecx>, ppmd_compressor_impl *impl@<esi>, int symbol@<edx>)
{
  PPM_CONTEXT::STATE *Stats; // eax
  unsigned int SummFreq; // ebx
  int v5; // edi
  unsigned int Freq; // edx
  unsigned int v7; // edi
  int NumStats; // ebp
  PPM_CONTEXT::STATE *v9; // eax
  int v10; // ebx
  unsigned __int8 EscCount; // bl
  int v12; // ecx
  int v13; // edx

  Stats = this->Stats;
  SummFreq = this->SummFreq;
  v5 = Stats->Symbol;
  impl->m_SubRange.scale = SummFreq;
  if ( v5 == symbol )
  {
    Freq = Stats->Freq;
    impl->m_SubRange.high = Freq;
    impl->PrevSuccess = 2 * Freq >= SummFreq;
    impl->FoundState = Stats;
    Stats->Freq += 4;
    this->SummFreq += 4;
    impl->RunLength += impl->PrevSuccess;
    if ( Stats->Freq > 0x7Cu )
      PPM_CONTEXT::rescale(this, (ppmd_compressor_impl *)this);
    impl->m_SubRange.low = 0;
  }
  else
  {
    v7 = Stats->Freq;
    NumStats = this->NumStats;
    v9 = Stats + 1;
    impl->PrevSuccess = 0;
    if ( v9->Symbol == symbol )
    {
LABEL_8:
      impl->m_SubRange.low = v7;
      impl->m_SubRange.high = v7 + v9->Freq;
      PPM_CONTEXT::update1(impl, v9, this);
    }
    else
    {
      while ( 1 )
      {
        v7 += v9->Freq;
        if ( !--NumStats )
          break;
        v10 = v9[1].Symbol;
        ++v9;
        if ( v10 == symbol )
          goto LABEL_8;
      }
      EscCount = impl->EscCount;
      impl->m_SubRange.low = v7;
      impl->CharMask[v9->Symbol] = EscCount;
      LOBYTE(v12) = this->NumStats;
      impl->NumMasked = v12;
      v12 = (unsigned __int8)v12;
      impl->FoundState = 0;
      do
      {
        v13 = v9[-1].Symbol;
        --v9;
        --v12;
        impl->CharMask[v13] = impl->EscCount;
      }
      while ( v12 );
      impl->m_SubRange.high = impl->m_SubRange.scale;
    }
  }
}
