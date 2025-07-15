void __userpurge PPM_CONTEXT::decodeSymbol1(ppmd_compressor_impl *impl@<esi>, PPM_CONTEXT *this)
{
  unsigned int v2; // eax
  PPM_CONTEXT::STATE *Stats; // edi
  unsigned int Freq; // ecx
  unsigned int v5; // ebp
  unsigned int v6; // eax
  unsigned int v7; // eax
  bool v8; // cf
  PPM_CONTEXT *v9; // ecx
  int NumStats; // ebp
  PPM_CONTEXT::STATE *v11; // edi
  unsigned int v12; // ecx
  int v13; // edx
  unsigned __int8 EscCount; // dl
  unsigned __int8 v15; // bl
  int v16; // eax
  int Symbol; // ecx

  v2 = impl->m_range / this->SummFreq;
  Stats = this->Stats;
  Freq = Stats->Freq;
  impl->m_SubRange.scale = this->SummFreq;
  v5 = v2;
  v6 = impl->m_code - impl->m_low;
  impl->m_range = v5;
  v7 = v6 / v5;
  if ( v7 >= Freq )
  {
    NumStats = this->NumStats;
    v11 = Stats + 1;
    impl->PrevSuccess = 0;
    v12 = v11->Freq + Freq;
    if ( v12 > v7 )
    {
LABEL_8:
      impl->m_SubRange.high = v12;
      impl->m_SubRange.low = v12 - v11->Freq;
      PPM_CONTEXT::update1(impl, v11, this);
    }
    else
    {
      while ( --NumStats )
      {
        v13 = v11[1].Freq;
        ++v11;
        v12 += v13;
        if ( v12 > v7 )
          goto LABEL_8;
      }
      EscCount = impl->EscCount;
      impl->m_SubRange.low = v12;
      impl->CharMask[v11->Symbol] = EscCount;
      v15 = this->NumStats;
      impl->NumMasked = this->NumStats;
      v16 = v15;
      impl->FoundState = 0;
      do
      {
        Symbol = v11[-1].Symbol;
        --v11;
        --v16;
        impl->CharMask[Symbol] = impl->EscCount;
      }
      while ( v16 );
      impl->m_SubRange.high = impl->m_SubRange.scale;
    }
  }
  else
  {
    v8 = 2 * Freq < impl->m_SubRange.scale;
    impl->m_SubRange.high = Freq;
    impl->PrevSuccess = !v8;
    v9 = (PPM_CONTEXT *)(Freq + 4);
    impl->FoundState = Stats;
    Stats->Freq = (unsigned __int8)v9;
    this->SummFreq += 4;
    impl->RunLength += impl->PrevSuccess;
    if ( (unsigned int)v9 > 0x7C )
      PPM_CONTEXT::rescale(v9, (ppmd_compressor_impl *)this);
    impl->m_SubRange.low = 0;
  }
}
