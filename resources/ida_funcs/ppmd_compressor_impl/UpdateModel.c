void __thiscall ppmd_compressor_impl::UpdateModel(
        ppmd_compressor_impl *this,
        ppmd_compressor_impl *MinContext,
        PPM_CONTEXT *MinContexta)
{
  PPM_CONTEXT *v3; // ecx
  PPM_CONTEXT::STATE *MaxContext; // ebp
  PPM_CONTEXT *FoundState; // esi
  unsigned __int8 NumStats; // al
  PPM_CONTEXT::STATE *Stats; // edx
  PPM_CONTEXT *Suffix; // edi
  unsigned __int8 Symbol; // cl
  __int16 v11; // ax
  PPM_CONTEXT *v12; // ecx
  unsigned __int8 Freq; // cl
  __int16 v14; // ax
  PPM_CONTEXT::STATE *v15; // eax
  unsigned __int8 *UnitsStart; // esi
  PPM_CONTEXT *Successors; // eax
  unsigned int v19; // edi
  unsigned int v20; // esi
  unsigned int v21; // eax
  char *v22; // eax
  BLK_NODE *v23; // eax
  unsigned __int8 v24; // cl
  unsigned __int16 v25; // dx
  unsigned int v26; // ecx
  unsigned int v27; // eax
  __int16 v28; // dx
  int v29; // eax
  int v30; // eax
  unsigned __int8 Flag; // [esp+13h] [ebp-19h]
  PPM_CONTEXT *FSuccessor; // [esp+14h] [ebp-18h]
  unsigned int FFreq; // [esp+18h] [ebp-14h]
  PPM_CONTEXT *Successor; // [esp+1Ch] [ebp-10h]
  unsigned int ns; // [esp+20h] [ebp-Ch]
  unsigned int s0; // [esp+24h] [ebp-8h]
  unsigned int ns1; // [esp+28h] [ebp-4h]
  unsigned __int8 FSymbol; // [esp+30h] [ebp+4h]

  v3 = MinContexta;
  MaxContext = (PPM_CONTEXT::STATE *)MinContext->MaxContext;
  FoundState = (PPM_CONTEXT *)MinContext->FoundState;
  FSuccessor = *(PPM_CONTEXT **)&FoundState->SummFreq;
  FFreq = FoundState->Flags;
  NumStats = FoundState->NumStats;
  Stats = 0;
  Suffix = MinContexta->Suffix;
  FSymbol = FoundState->NumStats;
  if ( FFreq < 0x1F && Suffix )
  {
    if ( Suffix->NumStats )
    {
      Stats = Suffix->Stats;
      if ( Stats->Symbol != NumStats )
      {
        do
        {
          Symbol = Stats[1].Symbol;
          ++Stats;
        }
        while ( Symbol != NumStats );
        if ( Stats->Freq >= Stats[-1].Freq )
        {
          v11 = *(_WORD *)&Stats->Symbol;
          v12 = Stats->Successor;
          *(_WORD *)&Stats->Symbol = *(_WORD *)&Stats[-1].Symbol;
          Stats->Successor = Stats[-1].Successor;
          *(_WORD *)&Stats[-1].Symbol = v11;
          Stats[-1].Successor = v12;
          --Stats;
        }
      }
      Freq = Stats->Freq;
      v14 = 2 * (Freq < 0x73u);
      Stats->Freq = v14 + Freq;
      Suffix->SummFreq += v14;
    }
    else
    {
      Stats = (PPM_CONTEXT::STATE *)&Suffix->SummFreq;
      HIBYTE(Suffix->SummFreq) += HIBYTE(Suffix->SummFreq) < 0x20u;
    }
    v3 = MinContexta;
    NumStats = FSymbol;
  }
  if ( !MinContext->OrderFall && FSuccessor )
  {
    MinContext->FoundState->Successor = ppmd_compressor_impl::CreateSuccessors(MinContext, 1, Stats, v3);
    v15 = (PPM_CONTEXT::STATE *)MinContext->FoundState->Successor;
    if ( !v15 )
    {
LABEL_14:
      v3 = MinContexta;
RESTART_MODEL:
      ppmd_compressor_impl::RestoreModelRare((ppmd_compressor_impl *)v3, (PPM_CONTEXT *)MaxContext, v3, FSuccessor);
      return;
    }
    goto LABEL_29;
  }
  *MinContext->m_allocator.pText++ = NumStats;
  UnitsStart = MinContext->m_allocator.UnitsStart;
  Successor = (PPM_CONTEXT *)MinContext->m_allocator.pText;
  if ( Successor >= (PPM_CONTEXT *)UnitsStart )
    goto RESTART_MODEL;
  if ( FSuccessor )
  {
    if ( FSuccessor >= (PPM_CONTEXT *)UnitsStart )
      goto LABEL_22;
    Successors = ppmd_compressor_impl::CreateSuccessors(MinContext, 0, Stats, v3);
  }
  else
  {
    Successors = ppmd_compressor_impl::ReduceOrder(MinContext, Stats, v3);
  }
  v3 = MinContexta;
  FSuccessor = Successors;
  NumStats = FSymbol;
LABEL_22:
  if ( !FSuccessor )
    goto RESTART_MODEL;
  if ( MinContext->OrderFall-- == 1 )
  {
    Successor = FSuccessor;
    MinContext->m_allocator.pText -= MinContext->MaxContext != v3;
  }
  else if ( MinContext->MRMethod > model_restoration_freeze )
  {
    Successor = FSuccessor;
    MinContext->m_allocator.pText = MinContext->m_allocator.HeapStart;
    MinContext->OrderFall = 0;
  }
  v19 = v3->NumStats;
  v20 = v3->SummFreq - v19 - FFreq;
  ns = v19;
  s0 = v20;
  Flag = 8 * (NumStats >= 0x40u);
  if ( MaxContext == (PPM_CONTEXT::STATE *)v3 )
  {
    v15 = (PPM_CONTEXT::STATE *)FSuccessor;
LABEL_29:
    MinContext->MaxContext = (PPM_CONTEXT *)v15;
    return;
  }
  while ( 1 )
  {
    v21 = MaxContext->Symbol;
    ns1 = v21;
    if ( MaxContext->Symbol )
    {
      if ( (v21 & 1) != 0 )
      {
        v22 = ppmd_allocator::ExpandUnits(
                &MinContext->m_allocator,
                *(ppmd_allocator **)((char *)&MaxContext->Successor + 2),
                (v21 + 1) >> 1);
        if ( !v22 )
          goto LABEL_14;
        v20 = s0;
        *(PPM_CONTEXT **)((char *)&MaxContext->Successor + 2) = (PPM_CONTEXT *)v22;
        v21 = ns1;
      }
      LOWORD(MaxContext->Successor) += 3 * v21 + 1 < ns;
    }
    else
    {
      v23 = ppmd_allocator::AllocUnits(&MinContext->m_allocator, 1u);
      if ( !v23 )
        goto LABEL_14;
      LOWORD(v23->Stamp) = MaxContext->Successor;
      *(unsigned int *)((char *)&v23->Stamp + 2) = *(unsigned int *)((char *)&MaxContext->Successor + 2);
      *(PPM_CONTEXT **)((char *)&MaxContext->Successor + 2) = (PPM_CONTEXT *)v23;
      v24 = BYTE1(v23->Stamp);
      BYTE1(v23->Stamp) = v24 >= 0x1Eu ? 120 : 2 * v24;
      LOWORD(MaxContext->Successor) = BYTE1(v23->Stamp) + LOWORD(MinContext->InitEsc) + (v19 > 2);
    }
    v25 = (unsigned __int16)MaxContext->Successor;
    v26 = v20 + v25;
    v27 = 2 * FFreq * (v25 + 6);
    if ( v27 >= 6 * v26 )
    {
      LOWORD(v26) = (12 * v26 < v27) + (15 * v26 < v27) + (9 * v26 < v27) + 4;
      v20 = s0;
      v28 = v26 + v25;
    }
    else
    {
      LOBYTE(v26) = (v27 >= 4 * v26) + (v26 < v27) + 1;
      v28 = v25 + 4;
    }
    v29 = ++MaxContext->Symbol;
    LOWORD(MaxContext->Successor) = v28;
    v30 = *(int *)((char *)&MaxContext->Successor + 2) + 6 * v29;
    *(_DWORD *)(v30 + 2) = Successor;
    *(_BYTE *)v30 = FSymbol;
    *(_BYTE *)(v30 + 1) = v26;
    MaxContext->Freq |= Flag;
    MaxContext = (PPM_CONTEXT::STATE *)MaxContext[1].Successor;
    if ( MaxContext == (PPM_CONTEXT::STATE *)MinContexta )
      break;
    v19 = ns;
  }
  MinContext->MaxContext = FSuccessor;
}
