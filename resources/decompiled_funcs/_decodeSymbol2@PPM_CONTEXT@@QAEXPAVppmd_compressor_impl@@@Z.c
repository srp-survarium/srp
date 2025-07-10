void __userpurge PPM_CONTEXT::decodeSymbol2(ppmd_compressor_impl *impl@<eax>, PPM_CONTEXT *this)
{
  SEE2_CONTEXT *EscFreq2; // eax
  unsigned __int8 EscCount; // bl
  int v5; // ebp
  unsigned int v6; // ecx
  PPM_CONTEXT::STATE **v7; // edx
  PPM_CONTEXT::STATE *v8; // eax
  int Symbol; // esi
  int Freq; // esi
  unsigned int scale; // ebx
  unsigned int v12; // esi
  unsigned int v13; // eax
  unsigned int v14; // eax
  PPM_CONTEXT::STATE *v15; // edx
  PPM_CONTEXT::STATE **v16; // esi
  unsigned int i; // ecx
  unsigned int v18; // ecx
  unsigned __int8 v20; // al
  int InitRL; // ecx
  int v22; // eax
  int v23; // edx
  SEE2_CONTEXT *psee2c; // [esp+10h] [ebp-404h]
  PPM_CONTEXT::STATE *ps[256]; // [esp+14h] [ebp-400h] BYREF

  EscFreq2 = PPM_CONTEXT::makeEscFreq2(this, impl);
  EscCount = impl->EscCount;
  psee2c = EscFreq2;
  v5 = this->NumStats - impl->NumMasked;
  v6 = 0;
  v7 = ps;
  v8 = this->Stats - 1;
  do
  {
    do
    {
      Symbol = v8[1].Symbol;
      ++v8;
    }
    while ( impl->CharMask[Symbol] == EscCount );
    Freq = v8->Freq;
    *v7 = v8;
    v6 += Freq;
    ++v7;
    --v5;
  }
  while ( v5 );
  impl->m_SubRange.scale += v6;
  scale = impl->m_SubRange.scale;
  v12 = impl->m_range / scale;
  v13 = impl->m_code - impl->m_low;
  impl->m_range = v12;
  v14 = v13 / v12;
  v15 = ps[0];
  v16 = ps;
  if ( v14 >= v6 )
  {
    impl->m_SubRange.low = v6;
    impl->m_SubRange.high = scale;
    v22 = this->NumStats - impl->NumMasked;
    impl->NumMasked = this->NumStats;
    do
    {
      v23 = (*v16++)->Symbol;
      --v22;
      impl->CharMask[v23] = impl->EscCount;
    }
    while ( v22 );
    psee2c->Summ += LOWORD(impl->m_SubRange.scale);
  }
  else
  {
    for ( i = ps[0]->Freq; i <= v14; i += v15->Freq )
    {
      v15 = v16[1];
      ++v16;
    }
    impl->m_SubRange.high = i;
    v18 = i - v15->Freq;
    impl->m_SubRange.low = v18;
    LOBYTE(v18) = psee2c->Shift;
    if ( (unsigned __int8)v18 < 7u && psee2c->Count-- == 1 )
    {
      psee2c->Summ *= 2;
      v20 = 3 << v18;
      LOBYTE(v18) = v18 + 1;
      psee2c->Shift = v18;
      psee2c->Count = v20;
    }
    impl->FoundState = v15;
    v15->Freq += 4;
    this->SummFreq += 4;
    if ( v15->Freq > 0x7Cu )
      PPM_CONTEXT::rescale((PPM_CONTEXT *)v18, (ppmd_compressor_impl *)this);
    InitRL = impl->InitRL;
    ++impl->EscCount;
    impl->RunLength = InitRL;
  }
}
