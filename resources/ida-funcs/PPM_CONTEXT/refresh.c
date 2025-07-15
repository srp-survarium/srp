void __userpurge PPM_CONTEXT::refresh(
        PPM_CONTEXT *this@<esi>,
        unsigned int OldNU@<ecx>,
        ppmd_compressor_impl *impl,
        unsigned int Scale)
{
  PPM_CONTEXT::STATE *v5; // eax
  int SummFreq; // edi
  char v7; // cl
  int Freq; // ecx
  int v9; // edi
  unsigned int v10; // edx
  int v11; // ecx
  unsigned int v12; // edx
  int NumStats; // [esp+14h] [ebp+Ch]

  NumStats = this->NumStats;
  v5 = (PPM_CONTEXT::STATE *)ppmd_allocator::ShrinkUnits(
                               &impl->m_allocator,
                               OldNU,
                               (char *)this->Stats,
                               (NumStats + 2) >> 1);
  SummFreq = this->SummFreq;
  v7 = this->Flags & (4 * (Scale + 4));
  this->Stats = v5;
  this->Flags = 8 * (v5->Symbol >= 0x40u) + v7;
  Freq = v5->Freq;
  v9 = SummFreq - Freq;
  v10 = (Freq + Scale) >> Scale;
  v5->Freq = v10;
  this->SummFreq = (unsigned __int8)v10;
  do
  {
    v11 = v5[1].Freq;
    ++v5;
    v9 -= v11;
    v12 = (v11 + Scale) >> Scale;
    v5->Freq = v12;
    this->SummFreq += (unsigned __int8)v12;
    this->Flags |= 8 * (v5->Symbol >= 0x40u);
    --NumStats;
  }
  while ( NumStats );
  this->SummFreq += (Scale + v9) >> Scale;
}
