void __userpurge PPM_CONTEXT::decodeSymbol2(ppmd_compressor_impl *impl@<eax>, PPM_CONTEXT *this)
{
  SEE2_CONTEXT *EscFreq2; // eax
  int NumStats; // ecx
  unsigned __int8 EscCount; // dl
  int v6; // ecx
  unsigned int v7; // edi
  PPM_CONTEXT::STATE *v8; // eax
  _DWORD *v9; // ebx
  unsigned int scale; // ebx
  unsigned __int8 **v11; // edx
  PPM_CONTEXT::STATE *v12; // eax
  unsigned int i; // ecx
  SEE2_CONTEXT *v14; // edi
  unsigned __int8 Shift; // cl
  int NumMasked; // edi
  int v18; // eax
  int v19; // ecx
  _DWORD v20[256]; // [esp+Ch] [ebp-408h] BYREF
  SEE2_CONTEXT *v21; // [esp+40Ch] [ebp-8h]
  unsigned int v22; // [esp+410h] [ebp-4h]

  EscFreq2 = PPM_CONTEXT::makeEscFreq2(this, impl);
  NumStats = this->NumStats;
  EscCount = impl->EscCount;
  v21 = EscFreq2;
  v6 = NumStats - impl->NumMasked;
  v22 = (unsigned int)v20;
  v7 = 0;
  v8 = this->Stats - 1;
  do
  {
    do
      ++v8;
    while ( impl->CharMask[v8->Symbol] == EscCount );
    v7 += v8->Freq;
    v9 = (_DWORD *)v22;
    v22 += 4;
    --v6;
    *v9 = v8;
  }
  while ( v6 );
  impl->m_SubRange.scale += v7;
  scale = impl->m_SubRange.scale;
  v22 = impl->m_range / scale;
  impl->m_range = v22;
  v11 = (unsigned __int8 **)v20;
  v22 = (impl->m_code - impl->m_low) / v22;
  v12 = (PPM_CONTEXT::STATE *)v20[0];
  if ( v22 >= v7 )
  {
    impl->m_SubRange.low = v7;
    NumMasked = impl->NumMasked;
    impl->m_SubRange.high = scale;
    v18 = this->NumStats - NumMasked;
    impl->NumMasked = this->NumStats;
    do
    {
      v19 = **v11++;
      --v18;
      impl->CharMask[v19] = impl->EscCount;
    }
    while ( v18 );
    v21->Summ += LOWORD(impl->m_SubRange.scale);
  }
  else
  {
    for ( i = *(unsigned __int8 *)(v20[0] + 1); i <= v22; i += (*v11)[1] )
      v12 = (PPM_CONTEXT::STATE *)*++v11;
    v14 = v21;
    impl->m_SubRange.high = i;
    impl->m_SubRange.low = i - v12->Freq;
    Shift = v14->Shift;
    if ( Shift < 7u && v14->Count-- == 1 )
    {
      v14->Summ *= 2;
      v14->Shift = Shift + 1;
      v14->Count = 3 << Shift;
    }
    PPM_CONTEXT::update2(this, impl, v12);
  }
}
