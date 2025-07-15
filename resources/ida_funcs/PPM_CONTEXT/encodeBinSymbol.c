void __userpurge PPM_CONTEXT::encodeBinSymbol(PPM_CONTEXT *this@<ecx>, ppmd_compressor_impl *impl@<eax>, int symbol)
{
  PPM_CONTEXT::STATE *p_SummFreq; // edi
  int v4; // ecx
  int v5; // edx
  unsigned __int16 *v6; // esi
  unsigned int m_range; // ecx
  unsigned int v8; // ebp
  int v9; // ebx
  unsigned __int16 v10; // cx

  p_SummFreq = (PPM_CONTEXT::STATE *)&this->SummFreq;
  v4 = ((impl->RunLength >> 26) & 0x20)
     + (impl->NS2BSIndx[HIBYTE(this->SummFreq) + 255] << 6)
     + (unsigned __int8)(impl->PrevSuccess + this->Flags + impl->NS2BSIndx[this->Suffix->NumStats]);
  v5 = impl->BinSumm[0][v4];
  impl->m_range >>= 14;
  v6 = &impl->BinSumm[0][v4];
  m_range = impl->m_range;
  v8 = v5 * m_range;
  if ( p_SummFreq->Symbol == symbol )
  {
    impl->FoundState = p_SummFreq;
    p_SummFreq->Freq += p_SummFreq->Freq < 0xC4u;
    impl->m_range = v8;
    *v6 = *v6 - ((*v6 + 32) >> 7) + 128;
    ++impl->RunLength;
    impl->PrevSuccess = 1;
  }
  else
  {
    v9 = *v6;
    impl->m_low += v8;
    impl->m_range = (0x4000 - v9) * m_range;
    v10 = *v6 - ((*v6 + 32) >> 7);
    *v6 = v10;
    impl->InitEsc = ExpEscape[v10 >> 10];
    impl->CharMask[p_SummFreq->Symbol] = impl->EscCount;
    impl->NumMasked = 0;
    impl->FoundState = 0;
    impl->PrevSuccess = 0;
  }
}
