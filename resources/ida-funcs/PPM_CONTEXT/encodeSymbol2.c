void __userpurge PPM_CONTEXT::encodeSymbol2(ppmd_compressor_impl *impl@<eax>, PPM_CONTEXT *this, int symbol)
{
  int v4; // edi
  unsigned int v5; // ecx
  PPM_CONTEXT::STATE *v6; // eax
  unsigned __int8 EscCount; // bl
  int v8; // edx
  unsigned int scale; // eax
  unsigned int v10; // ecx
  PPM_CONTEXT::STATE *i; // edx
  unsigned __int8 Shift; // cl
  SEE2_CONTEXT *EscFreq2; // [esp+Ch] [ebp-4h]

  EscFreq2 = PPM_CONTEXT::makeEscFreq2(this, impl);
  v4 = this->NumStats - impl->NumMasked;
  v5 = 0;
  v6 = this->Stats - 1;
  while ( 1 )
  {
    EscCount = impl->EscCount;
    do
    {
      ++v6;
      v8 = v6->Symbol;
    }
    while ( impl->CharMask[v8] == EscCount );
    impl->CharMask[v8] = EscCount;
    if ( v8 == symbol )
      break;
    v5 += v6->Freq;
    if ( !--v4 )
    {
      impl->m_SubRange.scale += v5;
      scale = impl->m_SubRange.scale;
      impl->m_SubRange.low = v5;
      impl->m_SubRange.high = scale;
      EscFreq2->Summ += scale;
      impl->NumMasked = this->NumStats;
      return;
    }
  }
  impl->m_SubRange.low = v5;
  v10 = v6->Freq + v5;
  impl->m_SubRange.high = v10;
  for ( i = v6; --v4; v10 += i->Freq )
  {
    do
      ++i;
    while ( impl->CharMask[i->Symbol] == impl->EscCount );
  }
  impl->m_SubRange.scale += v10;
  Shift = EscFreq2->Shift;
  if ( Shift < 7u && EscFreq2->Count-- == 1 )
  {
    EscFreq2->Summ *= 2;
    EscFreq2->Shift = Shift + 1;
    EscFreq2->Count = 3 << Shift;
  }
  PPM_CONTEXT::update2(this, impl, v6);
}
