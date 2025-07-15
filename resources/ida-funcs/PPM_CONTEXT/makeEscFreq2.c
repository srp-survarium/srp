SEE2_CONTEXT *__usercall PPM_CONTEXT::makeEscFreq2@<eax>(PPM_CONTEXT *this@<ecx>, ppmd_compressor_impl *impl@<esi>)
{
  SEE2_CONTEXT *result; // eax
  int v3; // edi

  if ( this->NumStats == 0xFF )
  {
    result = &impl->DummySEE2Cont;
    impl->m_SubRange.scale = 1;
  }
  else
  {
    result = (SEE2_CONTEXT *)(&impl->m_allocator.BList[16 * impl->QTable[this->NumStats + 2]
                                                     + 14
                                                     + (2 * (unsigned int)this->NumStats < impl->NumMasked
                                                                                         + (unsigned int)this->Suffix->NumStats)].next
                            + this->Flags
                            + (this->SummFreq > 11 * (this->NumStats + 1)));
    v3 = result->Summ >> *((_BYTE *)&impl->m_allocator.BList[16 * impl->QTable[this->NumStats + 2]
                                                           + 14
                                                           + (2 * (unsigned int)this->NumStats < impl->NumMasked
                                                                                               + (unsigned int)this->Suffix->NumStats)].next
                         + 4 * this->Flags
                         + 4 * (this->SummFreq > 11 * (this->NumStats + 1))
                         + 2);
    result->Summ -= v3;
    impl->m_SubRange.scale = v3 + (v3 == 0);
  }
  return result;
}
