PPM_CONTEXT *__userpurge ppmd_compressor_impl::CreateSuccessors@<eax>(
        PPM_CONTEXT::STATE *p@<eax>,
        PPM_CONTEXT *pc@<ecx>,
        ppmd_compressor_impl *this,
        int Skip)
{
  PPM_CONTEXT::STATE *FoundState; // ecx
  PPM_CONTEXT *Successor; // edi
  unsigned __int8 Symbol; // cl
  bool v8; // zf
  unsigned __int8 Freq; // dl
  PPM_CONTEXT::STATE **v10; // edx
  PPM_CONTEXT *result; // eax
  unsigned __int8 NumStats; // al
  unsigned __int8 v13; // bl
  unsigned __int8 v14; // cl
  PPM_CONTEXT::STATE *i; // edi
  unsigned int v16; // eax
  unsigned int v17; // edi
  char SummFreq_high; // al
  PPM_CONTEXT::STATE *v19; // ecx
  PPM_CONTEXT::STATE *v20; // [esp+Ch] [ebp-50h] BYREF
  char v21; // [esp+10h] [ebp-4Ch] BYREF
  unsigned __int16 v22; // [esp+4Eh] [ebp-Eh]
  PPM_CONTEXT::STATE *p_Flags; // [esp+50h] [ebp-Ch]
  PPM_CONTEXT::STATE **v24; // [esp+58h] [ebp-4h]

  FoundState = this->FoundState;
  Successor = FoundState->Successor;
  Symbol = FoundState->Symbol;
  v24 = &v20;
  if ( !Skip )
  {
    v8 = pc->Suffix == 0;
    v20 = this->FoundState;
    v24 = (PPM_CONTEXT::STATE **)&v21;
    if ( v8 )
      goto LABEL_16;
  }
  if ( !p )
    goto LABEL_5;
  pc = pc->Suffix;
  while ( p->Successor == Successor )
  {
    v10 = v24++;
    v8 = pc->Suffix == 0;
    *v10 = p;
    if ( v8 )
      goto LABEL_14;
LABEL_5:
    pc = pc->Suffix;
    if ( pc->NumStats )
    {
      for ( p = pc->Stats; p->Symbol != Symbol; ++p )
        ;
      Freq = p->Freq;
      p->Freq = (Freq < 0x73u) + Freq;
      pc->SummFreq += Freq < 0x73u;
    }
    else
    {
      p = (PPM_CONTEXT::STATE *)&pc->SummFreq;
      HIBYTE(pc->SummFreq) += HIBYTE(pc->SummFreq) < 0x18u && pc->Suffix->NumStats == 0;
    }
  }
  pc = p->Successor;
LABEL_14:
  if ( v24 == &v20 )
    return pc;
LABEL_16:
  NumStats = Successor->NumStats;
  v13 = (8 * (Successor->NumStats >= 0x40u)) | (16 * (Symbol >= 0x40u));
  v14 = pc->NumStats;
  LOBYTE(v22) = Successor->NumStats;
  p_Flags = (PPM_CONTEXT::STATE *)&Successor->Flags;
  if ( v14 )
  {
    for ( i = pc->Stats; i->Symbol != NumStats; ++i )
      ;
    v16 = i->Freq - 1;
    v17 = pc->SummFreq - v14 - v16;
    if ( 2 * v16 > v17 )
      v16 = (v16 + 2 * v17 - 3) / v17;
    else
      LOBYTE(v16) = v17 < 5 * v16;
    SummFreq_high = v16 + 1;
  }
  else
  {
    SummFreq_high = HIBYTE(pc->SummFreq);
  }
  HIBYTE(v22) = SummFreq_high;
  while ( 1 )
  {
    result = (PPM_CONTEXT *)ppmd_allocator::AllocContext(&this->m_allocator);
    if ( !result )
      break;
    --v24;
    result->SummFreq = v22;
    result->Stats = p_Flags;
    v19 = *v24;
    result->Suffix = pc;
    result->NumStats = 0;
    result->Flags = v13;
    v19->Successor = result;
    pc = result;
    if ( v24 == &v20 )
      return result;
  }
  return 0;
}
