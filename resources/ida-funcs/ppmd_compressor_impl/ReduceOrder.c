PPM_CONTEXT *__usercall ppmd_compressor_impl::ReduceOrder@<eax>(
        ppmd_compressor_impl *this@<esi>,
        PPM_CONTEXT::STATE *p@<ecx>,
        PPM_CONTEXT *pc@<eax>)
{
  PPM_CONTEXT::STATE *FoundState; // edx
  PPM_CONTEXT *pText; // ecx
  PPM_CONTEXT *Suffix; // edx
  unsigned __int8 Freq; // dl
  unsigned __int8 v8; // bl
  PPM_CONTEXT::STATE *v9; // edx
  PPM_CONTEXT::STATE *v10; // ecx
  PPM_CONTEXT::STATE *v11; // [esp+8h] [ebp-4Ch] BYREF
  char v12; // [esp+Ch] [ebp-48h] BYREF
  PPM_CONTEXT *v13; // [esp+48h] [ebp-Ch]
  PPM_CONTEXT::STATE *v14; // [esp+4Ch] [ebp-8h]
  unsigned __int8 Symbol; // [esp+52h] [ebp-2h]
  unsigned __int8 v16; // [esp+53h] [ebp-1h]

  FoundState = this->FoundState;
  pText = (PPM_CONTEXT *)this->m_allocator.pText;
  Symbol = FoundState->Symbol;
  FoundState->Successor = pText;
  ++this->OrderFall;
  v13 = pc;
  v11 = FoundState;
  v14 = (PPM_CONTEXT::STATE *)&v12;
  if ( !p )
    goto LABEL_3;
  pc = pc->Suffix;
  while ( !p->Successor )
  {
    v9 = v14;
    v14 = (PPM_CONTEXT::STATE *)((char *)v14 + 4);
    p->Successor = pText;
    ++this->OrderFall;
    *(_DWORD *)&v9->Symbol = p;
LABEL_3:
    Suffix = pc->Suffix;
    if ( !Suffix )
    {
      if ( this->MRMethod <= model_restoration_freeze )
        return pc;
      goto FROZEN;
    }
    pc = pc->Suffix;
    if ( Suffix->NumStats )
    {
      for ( p = Suffix->Stats; p->Symbol != Symbol; ++p )
        ;
      Freq = p->Freq;
      v8 = 2 * (Freq < 0x73u);
      p->Freq = v8 + Freq;
      pc->SummFreq += v8;
      v16 = v8;
    }
    else
    {
      p = (PPM_CONTEXT::STATE *)&Suffix->SummFreq;
      HIBYTE(pc->SummFreq) = HIBYTE(Suffix->SummFreq) + (HIBYTE(Suffix->SummFreq) < 0x20u);
    }
  }
  if ( this->MRMethod > model_restoration_freeze )
  {
    pc = p->Successor;
FROZEN:
    v10 = v14;
    do
    {
      v10 = (PPM_CONTEXT::STATE *)((char *)v10 - 4);
      *(_DWORD *)(*(_DWORD *)&v10->Symbol + 2) = pc;
    }
    while ( v10 != (PPM_CONTEXT::STATE *)&v11 );
    this->m_allocator.pText = this->m_allocator.HeapStart + 1;
    this->OrderFall = 1;
    return pc;
  }
  if ( p->Successor <= pText )
  {
    v14 = this->FoundState;
    this->FoundState = p;
    p->Successor = ppmd_compressor_impl::CreateSuccessors(0, pc, this, 0);
    this->FoundState = v14;
  }
  if ( this->OrderFall == 1 && v13 == this->MaxContext )
  {
    this->FoundState->Successor = p->Successor;
    --this->m_allocator.pText;
  }
  return p->Successor;
}
