void __userpurge PPM_CONTEXT::encodeBinSymbol(PPM_CONTEXT *this@<ecx>, ppmd_compressor_impl *impl@<eax>, int symbol)
{
  unsigned __int16 *p_SummFreq; // edi
  unsigned __int16 *v4; // esi
  int v5; // ebx
  unsigned int v6; // edx
  unsigned int v7; // ecx
  unsigned __int8 EscCount; // dl

  p_SummFreq = &this->SummFreq;
  v4 = &impl->BinSumm[impl->NS2BSIndx[HIBYTE(this->SummFreq) + 255]][((impl->RunLength >> 26) & 0x20)
                                                                   + (unsigned __int8)(impl->PrevSuccess
                                                                                     + this->Flags
                                                                                     + impl->NS2BSIndx[this->Suffix->NumStats])];
  v5 = *v4;
  impl->m_range >>= 14;
  v6 = v5 * impl->m_range;
  if ( LOBYTE(this->SummFreq) == symbol )
  {
    impl->FoundState = (PPM_CONTEXT::STATE *)p_SummFreq;
    HIBYTE(this->SummFreq) += HIBYTE(this->SummFreq) < 0xC4u;
    impl->m_range = v6;
    *v4 = *v4 - ((*v4 + 32) >> 7) + 128;
    ++impl->RunLength;
    impl->PrevSuccess = 1;
  }
  else
  {
    v7 = (0x4000 - *v4) * impl->m_range;
    impl->m_low += v5 * impl->m_range;
    impl->m_range = v7;
    LOWORD(v7) = *v4 - ((*v4 + 32) >> 7);
    *v4 = v7;
    EscCount = impl->EscCount;
    impl->InitEsc = ExpEscape[(unsigned __int16)v7 >> 10];
    impl->CharMask[*(unsigned __int8 *)p_SummFreq] = EscCount;
    impl->PrevSuccess = 0;
    impl->NumMasked = 0;
    impl->FoundState = 0;
  }
}
