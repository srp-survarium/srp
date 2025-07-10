PPM_CONTEXT *__usercall ppmd_compressor_impl::ReduceOrder@<eax>(
        ppmd_compressor_impl *this@<edi>,
        PPM_CONTEXT::STATE *p@<ecx>,
        PPM_CONTEXT *pc@<eax>)
{
  PPM_CONTEXT *pText; // ebx
  PPM_CONTEXT::STATE *FoundState; // ecx
  unsigned __int8 Symbol; // dl
  PPM_CONTEXT *Suffix; // ecx
  unsigned __int8 v8; // cl
  unsigned __int8 Freq; // cl
  unsigned __int8 v10; // dl
  PPM_CONTEXT::STATE *v11; // ebx
  PPM_CONTEXT::STATE *ps[16]; // [esp+6h] [ebp-40h] BYREF
  PPM_CONTEXT::STATE *v13; // [esp+46h] [ebp+0h] BYREF

  pText = (PPM_CONTEXT *)this->m_allocator.pText;
  FoundState = this->FoundState;
  Symbol = FoundState->Symbol;
  FoundState->Successor = pText;
  ++this->OrderFall;
  ps[14] = (PPM_CONTEXT::STATE *)pc;
  HIBYTE(ps[13]) = Symbol;
  ps[15] = FoundState;
  if ( !p )
    goto LABEL_3;
  pc = pc->Suffix;
  while ( !p->Successor )
  {
    v13 = p;
    p->Successor = pText;
    ++this->OrderFall;
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
      p = Suffix->Stats;
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
      v10 = 2 * (Freq < 0x73u);
      p->Freq = v10 + Freq;
      pc->SummFreq += v10;
    }
    else
    {
      p = (PPM_CONTEXT::STATE *)&pc->SummFreq;
      HIBYTE(pc->SummFreq) = HIBYTE(Suffix->SummFreq) + (HIBYTE(Suffix->SummFreq) < 0x20u);
    }
    Symbol = HIBYTE(ps[13]);
  }
  if ( this->MRMethod > model_restoration_freeze )
  {
    pc = p->Successor;
    do
FROZEN:
      ps[15]->Successor = pc;
    while ( &v13 != &ps[15] );
    this->m_allocator.pText = this->m_allocator.HeapStart + 1;
    this->OrderFall = 1;
    return pc;
  }
  if ( p->Successor <= pText )
  {
    v11 = this->FoundState;
    this->FoundState = p;
    p->Successor = ppmd_compressor_impl::CreateSuccessors(0, pc, this, 0);
    this->FoundState = v11;
  }
  if ( this->OrderFall == 1 && ps[14] == (PPM_CONTEXT::STATE *)this->MaxContext )
  {
    this->FoundState->Successor = p->Successor;
    --this->m_allocator.pText;
  }
  return p->Successor;
}
