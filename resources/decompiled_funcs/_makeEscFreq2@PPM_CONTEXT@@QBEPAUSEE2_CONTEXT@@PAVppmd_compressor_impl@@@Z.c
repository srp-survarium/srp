SEE2_CONTEXT *__usercall PPM_CONTEXT::makeEscFreq2@<eax>(PPM_CONTEXT *this@<eax>, ppmd_compressor_impl *impl@<edi>)
{
  int v2; // ecx
  unsigned __int16 v3; // si
  SEE2_CONTEXT *result; // eax
  int v5; // edx

  if ( this->NumStats == 0xFF )
  {
    result = &impl->DummySEE2Cont;
    impl->m_SubRange.scale = 1;
  }
  else
  {
    v2 = this->Flags
       + (this->SummFreq > 11 * (this->NumStats + 1))
       + 2
       * (16 * impl->QTable[this->NumStats + 2]
        + (2 * (unsigned int)this->NumStats < impl->NumMasked + (unsigned int)this->Suffix->NumStats));
    v3 = *((_WORD *)&impl->m_allocator.BList[14].next + 2 * v2);
    result = (SEE2_CONTEXT *)(&impl->m_allocator.BList[14].next + v2);
    v5 = v3 >> *((_BYTE *)&impl->m_allocator.BList[14].next + 4 * v2 + 2);
    result->Summ = v3 - v5;
    impl->m_SubRange.scale = v5 + (v5 == 0);
  }
  return result;
}
