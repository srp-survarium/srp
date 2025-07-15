void __thiscall PPM_CONTEXT::read(
        PPM_CONTEXT *this,
        ppmd_compressor_impl *impl,
        compression::ppmd::stream *fp,
        unsigned int PrevSym)
{
  PPM_CONTEXT *v4; // esi
  unsigned __int8 v5; // al
  unsigned __int8 v6; // al
  char SummFreq_high; // al
  unsigned __int8 *v8; // eax
  unsigned int SummFreq_low; // edi
  unsigned __int8 *v10; // edi
  unsigned __int8 *v11; // ecx
  unsigned __int8 v12; // al
  PPM_CONTEXT::STATE *Stats; // edi
  int v14; // ebx
  int NumStats; // eax
  bool v16; // cl
  unsigned int i; // eax
  char Freq; // al
  PPM_CONTEXT *v19; // eax
  unsigned __int8 v20; // al
  PPM_CONTEXT::STATE *v21; // eax
  int v22; // ecx
  unsigned int j; // ecx
  unsigned __int8 v24; // cl
  unsigned int Symbol; // [esp-4h] [ebp-10h]

  v4 = this;
  this->Suffix = 0;
  v5 = compression::ppmd::stream::get_char(fp);
  v4->NumStats = v5;
  v4->Flags = 16 * (PrevSym >= 0x40);
  if ( v5 )
  {
LABEL_4:
    v10 = ppmd_allocator::AllocUnits(&impl->m_allocator, (v4->NumStats + 2) >> 1);
    v11 = &v10[6 * v4->NumStats];
    v4->Stats = (PPM_CONTEXT::STATE *)v10;
    if ( v10 <= v11 )
    {
      do
      {
        v10[1] = compression::ppmd::stream::get_char(fp);
        v12 = compression::ppmd::stream::get_char(fp);
        *v10 = v12;
        v4->Flags |= 8 * (v12 >= 0x40u);
        v10 += 6;
      }
      while ( (PPM_CONTEXT::STATE *)v10 <= &v4->Stats[v4->NumStats] );
    }
    Stats = v4->Stats;
    v14 = Stats->Freq & 0x7F;
    v4->SummFreq = Stats->Freq & 0x7F;
    NumStats = v4->NumStats;
    v16 = v14 < NumStats && v14 < 127;
    v4->Flags |= 4 * v16;
    for ( i = (unsigned int)&Stats[NumStats]; (unsigned int)Stats <= i; i = (unsigned int)&v4->Stats[v4->NumStats] )
    {
      Freq = Stats->Freq;
      if ( Freq >= 0 )
      {
        Stats->Successor = 0;
      }
      else
      {
        Stats->Freq = Freq & 0x7F;
        v19 = (PPM_CONTEXT *)ppmd_allocator::AllocContext(&impl->m_allocator);
        Symbol = Stats->Symbol;
        Stats->Successor = v19;
        PPM_CONTEXT::read(v19, impl, fp, Symbol);
      }
      if ( Stats == v4->Stats )
        v20 = 64;
      else
        v20 = Stats[-1].Freq - Stats->Freq;
      Stats->Freq = v20;
      v4->SummFreq += v20;
      ++Stats;
    }
    if ( v14 > 32 )
    {
      v21 = v4->Stats;
      v22 = v4->NumStats;
      v4->SummFreq = v14 >> 1;
      for ( j = (unsigned int)&v21[v22]; (unsigned int)v21 <= j; j = (unsigned int)&v4->Stats[v4->NumStats] )
      {
        v24 = v21->Freq - ((3 * v21->Freq) >> 2);
        v21->Freq = v24;
        v4->SummFreq += v24;
        ++v21;
      }
    }
  }
  else
  {
    while ( 1 )
    {
      HIBYTE(v4->SummFreq) = compression::ppmd::stream::get_char(fp);
      v6 = compression::ppmd::stream::get_char(fp);
      LOBYTE(v4->SummFreq) = v6;
      v4->Flags |= 8 * (v6 >= 0x40u);
      SummFreq_high = HIBYTE(v4->SummFreq);
      if ( SummFreq_high >= 0 )
        break;
      HIBYTE(v4->SummFreq) = SummFreq_high & 0x7F;
      v8 = ppmd_allocator::AllocContext(&impl->m_allocator);
      SummFreq_low = LOBYTE(v4->SummFreq);
      v4->Stats = (PPM_CONTEXT::STATE *)v8;
      v4 = (PPM_CONTEXT *)v8;
      *((_DWORD *)v8 + 2) = 0;
      *v8 = compression::ppmd::stream::get_char(fp);
      v4->Flags = 16 * (SummFreq_low >= 0x40);
      if ( v4->NumStats )
        goto LABEL_4;
    }
    v4->Stats = 0;
  }
}
