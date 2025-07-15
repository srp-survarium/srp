void __usercall PPM_CONTEXT::decodeBinSymbol(PPM_CONTEXT *this@<ecx>, ppmd_compressor_impl *impl@<eax>)
{
  unsigned __int16 *p_SummFreq; // edi
  unsigned __int16 *v3; // esi
  int v4; // ebx
  unsigned int v5; // edx
  unsigned int m_low; // edx
  unsigned __int16 v7; // cx
  unsigned int v8; // [esp+10h] [ebp-4h]

  p_SummFreq = &this->SummFreq;
  v3 = &impl->BinSumm[impl->NS2BSIndx[HIBYTE(this->SummFreq) + 255]][((impl->RunLength >> 26) & 0x20)
                                                                   + (unsigned __int8)(impl->PrevSuccess
                                                                                     + this->Flags
                                                                                     + impl->NS2BSIndx[this->Suffix->NumStats])];
  v4 = *v3;
  impl->m_range >>= 14;
  v5 = v4 * impl->m_range;
  v8 = v5;
  if ( impl->m_code - impl->m_low >= v5 )
  {
    m_low = impl->m_low;
    impl->m_range *= 0x4000 - *v3;
    impl->m_low = v8 + m_low;
    v7 = *v3 - ((*v3 + 32) >> 7);
    *v3 = v7;
    LOBYTE(m_low) = impl->EscCount;
    impl->InitEsc = ExpEscape[v7 >> 10];
    impl->CharMask[*(unsigned __int8 *)p_SummFreq] = m_low;
    impl->PrevSuccess = 0;
    impl->NumMasked = 0;
    impl->FoundState = 0;
  }
  else
  {
    impl->FoundState = (PPM_CONTEXT::STATE *)p_SummFreq;
    HIBYTE(this->SummFreq) += HIBYTE(this->SummFreq) < 0xC4u;
    impl->m_range = v5;
    *v3 = *v3 - ((*v3 + 32) >> 7) + 128;
    ++impl->RunLength;
    impl->PrevSuccess = 1;
  }
}
