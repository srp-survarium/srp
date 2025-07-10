PPM_CONTEXT *__userpurge ppmd_compressor_impl::CreateSuccessors@<eax>(
        PPM_CONTEXT::STATE *p@<eax>,
        PPM_CONTEXT *pc@<ecx>,
        ppmd_compressor_impl *this,
        int Skip)
{
  PPM_CONTEXT::STATE *FoundState; // ecx
  unsigned __int8 Symbol; // bl
  PPM_CONTEXT *Successor; // esi
  unsigned __int8 v8; // cl
  unsigned __int8 Freq; // cl
  PPM_CONTEXT *result; // eax
  unsigned __int8 NumStats; // al
  unsigned __int8 v12; // bl
  PPM_CONTEXT::STATE *Stats; // ecx
  unsigned __int8 v14; // dl
  unsigned int v15; // eax
  unsigned int v16; // ecx
  unsigned __int8 *HiUnit; // eax
  PPM_CONTEXT::STATE *v18; // edx
  unsigned int ps_32; // [esp+2Eh] [ebp-20h]
  unsigned __int8 ps_51; // [esp+41h] [ebp-Dh]
  unsigned __int16 ps_54; // [esp+44h] [ebp-Ah]
  PPM_CONTEXT::STATE *v22; // [esp+4Eh] [ebp+0h]

  FoundState = this->FoundState;
  Symbol = FoundState->Symbol;
  Successor = FoundState->Successor;
  ps_51 = FoundState->Symbol;
  if ( Skip || (v22 = this->FoundState, pc->Suffix) )
  {
    if ( !p )
      goto LABEL_5;
    pc = pc->Suffix;
    while ( p->Successor == Successor )
    {
      if ( !pc->Suffix )
        return pc;
LABEL_5:
      pc = pc->Suffix;
      if ( pc->NumStats )
      {
        p = pc->Stats;
        if ( p->Symbol != Symbol )
        {
          do
          {
            v8 = p[1].Symbol;
            ++p;
          }
          while ( v8 != Symbol );
        }
        Freq = p->Freq;
        p->Freq = (Freq < 0x73u) + Freq;
        pc->SummFreq += Freq < 0x73u;
      }
      else
      {
        p = (PPM_CONTEXT::STATE *)&pc->SummFreq;
        Symbol = ps_51;
        HIBYTE(pc->SummFreq) += HIBYTE(pc->SummFreq) < 0x18u && pc->Suffix->NumStats == 0;
      }
    }
    return p->Successor;
  }
  else
  {
    NumStats = Successor->NumStats;
    v12 = (8 * (Successor->NumStats >= 0x40u)) | (16 * (Symbol >= 0x40u));
    LOBYTE(ps_54) = Successor->NumStats;
    if ( pc->NumStats )
    {
      Stats = pc->Stats;
      if ( Stats->Symbol != NumStats )
      {
        do
        {
          v14 = Stats[1].Symbol;
          ++Stats;
        }
        while ( v14 != NumStats );
      }
      v15 = Stats->Freq - 1;
      v16 = pc->SummFreq - pc->NumStats - v15;
      if ( 2 * v15 > v16 )
        v15 = (v15 + 2 * v16 - 3) / v16;
      else
        LOBYTE(v15) = v16 < 5 * v15;
      HIBYTE(ps_54) = v15 + 1;
    }
    else
    {
      HIBYTE(ps_54) = HIBYTE(pc->SummFreq);
    }
    HiUnit = this->m_allocator.HiUnit;
    if ( HiUnit == this->m_allocator.LoUnit )
    {
      if ( this->m_allocator.BList[0].next )
      {
        result = (PPM_CONTEXT *)this->m_allocator.BList[0].next;
        v18 = result->Stats;
        --this->m_allocator.BList[0].Stamp;
        this->m_allocator.BList[0].next = (BLK_NODE *)v18;
      }
      else
      {
        result = (PPM_CONTEXT *)ppmd_allocator::AllocUnitsRare(&this->m_allocator, 0, ps_32);
      }
    }
    else
    {
      result = (PPM_CONTEXT *)(HiUnit - 12);
      this->m_allocator.HiUnit = &result->NumStats;
    }
    if ( result )
    {
      result->Stats = (PPM_CONTEXT::STATE *)&Successor->Flags;
      result->SummFreq = ps_54;
      result->Suffix = pc;
      result->NumStats = 0;
      result->Flags = v12;
      v22->Successor = result;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
