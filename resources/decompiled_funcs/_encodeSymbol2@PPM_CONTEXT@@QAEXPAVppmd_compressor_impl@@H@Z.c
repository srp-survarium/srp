void __userpurge PPM_CONTEXT::encodeSymbol2(ppmd_compressor_impl *impl@<eax>, PPM_CONTEXT *this, int symbol)
{
  PPM_CONTEXT *v3; // esi
  unsigned int v5; // ebp
  int v6; // ebx
  PPM_CONTEXT::STATE *v7; // edx
  unsigned __int8 EscCount; // al
  int v9; // ecx
  unsigned int scale; // eax
  unsigned int v11; // ebp
  int v12; // ebx
  PPM_CONTEXT *v13; // ecx
  int v14; // esi
  unsigned __int8 v16; // al
  int InitRL; // ecx
  SEE2_CONTEXT *psee2c; // [esp+10h] [ebp-4h]

  v3 = this;
  psee2c = PPM_CONTEXT::makeEscFreq2(this, impl);
  v5 = 0;
  v6 = this->NumStats - impl->NumMasked;
  v7 = this->Stats - 1;
  while ( 1 )
  {
    EscCount = impl->EscCount;
    do
    {
      v9 = v7[1].Symbol;
      ++v7;
    }
    while ( impl->CharMask[v9] == EscCount );
    impl->CharMask[v9] = EscCount;
    if ( v9 == symbol )
      break;
    v5 += v7->Freq;
    if ( !--v6 )
    {
      impl->m_SubRange.scale += v5;
      scale = impl->m_SubRange.scale;
      impl->m_SubRange.low = v5;
      impl->m_SubRange.high = scale;
      psee2c->Summ += scale;
      impl->NumMasked = this->NumStats;
      return;
    }
  }
  impl->m_SubRange.low = v5;
  v11 = v7->Freq + v5;
  v12 = v6 - 1;
  impl->m_SubRange.high = v11;
  v13 = (PPM_CONTEXT *)v7;
  if ( v12 )
  {
    do
    {
      do
      {
        v14 = BYTE2(v13->Stats);
        v13 = (PPM_CONTEXT *)((char *)v13 + 6);
      }
      while ( impl->CharMask[v14] == impl->EscCount );
      v11 += v13->Flags;
      --v12;
    }
    while ( v12 );
    v3 = this;
  }
  impl->m_SubRange.scale += v11;
  LOBYTE(v13) = psee2c->Shift;
  if ( (unsigned __int8)v13 < 7u && psee2c->Count-- == 1 )
  {
    psee2c->Summ *= 2;
    v16 = 3 << (char)v13;
    LOBYTE(v13) = (_BYTE)v13 + 1;
    psee2c->Shift = (unsigned __int8)v13;
    psee2c->Count = v16;
    v3 = this;
  }
  impl->FoundState = v7;
  v7->Freq += 4;
  v3->SummFreq += 4;
  if ( v7->Freq > 0x7Cu )
    PPM_CONTEXT::rescale(v13, (ppmd_compressor_impl *)v3);
  InitRL = impl->InitRL;
  ++impl->EscCount;
  impl->RunLength = InitRL;
}
