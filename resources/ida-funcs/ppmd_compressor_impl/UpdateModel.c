void __userpurge ppmd_compressor_impl::UpdateModel(
        ppmd_compressor_impl *this@<ecx>,
        int a2@<eax>,
        ppmd_allocator *MinContext)
{
  char *v4; // eax
  PPM_CONTEXT *next; // ecx
  PPM_CONTEXT *NumStats; // ebx
  PPM_CONTEXT::STATE *Stats; // edx
  PPM_CONTEXT *v8; // edi
  PPM_CONTEXT::STATE *v9; // eax
  unsigned __int8 Freq; // bl
  __int16 v11; // ax
  PPM_CONTEXT *v12; // eax
  unsigned int v13; // ecx
  PPM_CONTEXT *v14; // eax
  PPM_CONTEXT *Successors; // eax
  bool v16; // zf
  ppmd_allocator *v17; // ecx
  unsigned int v18; // edx
  unsigned __int8 *v19; // eax
  unsigned __int8 *v20; // eax
  unsigned __int8 v21; // cl
  int SummFreq; // ecx
  int v23; // eax
  unsigned int v24; // ecx
  unsigned int v25; // eax
  unsigned __int16 v26; // ax
  int v27; // eax
  __int16 v28; // [esp+Ch] [ebp-18h]
  unsigned int m_allocator_low; // [esp+Ch] [ebp-18h]
  PPM_CONTEXT *Successor; // [esp+10h] [ebp-14h]
  PPM_CONTEXT *v31; // [esp+10h] [ebp-14h]
  unsigned int v32; // [esp+14h] [ebp-10h]
  unsigned int v33; // [esp+18h] [ebp-Ch]
  PPM_CONTEXT *v34; // [esp+1Ch] [ebp-8h]
  char i; // [esp+22h] [ebp-2h]
  char v36; // [esp+23h] [ebp-1h]

  v4 = *(char **)(a2 + 4112);
  NumStats = (PPM_CONTEXT *)(unsigned __int8)v4[1];
  v34 = *(PPM_CONTEXT **)(v4 + 2);
  next = (PPM_CONTEXT *)MinContext->BList[0].next;
  v33 = (unsigned int)NumStats;
  LOBYTE(NumStats) = *v4;
  Stats = 0;
  v8 = *(PPM_CONTEXT **)(a2 + 3592);
  v36 = *v4;
  if ( v33 < 0x1F && next )
  {
    if ( next->NumStats )
    {
      Stats = next->Stats;
      if ( Stats->Symbol != (_BYTE)NumStats )
      {
        do
          ++Stats;
        while ( Stats->Symbol != (_BYTE)NumStats );
        if ( Stats->Freq >= Stats[-1].Freq )
        {
          v9 = Stats - 1;
          v28 = *(_WORD *)&Stats->Symbol;
          Successor = Stats->Successor;
          *(_WORD *)&Stats->Symbol = *(_WORD *)&Stats[-1].Symbol;
          NumStats = Stats[-1].Successor;
          Stats->Successor = NumStats;
          *(_WORD *)&v9->Symbol = v28;
          v9->Successor = Successor;
          --Stats;
        }
      }
      Freq = Stats->Freq;
      v11 = 2 * (Freq < 0x73u);
      Stats->Freq = v11 + Freq;
      next->SummFreq += v11;
      LOBYTE(NumStats) = v36;
    }
    else
    {
      Stats = (PPM_CONTEXT::STATE *)&next->SummFreq;
      HIBYTE(next->SummFreq) += HIBYTE(next->SummFreq) < 0x20u;
    }
  }
  if ( *(_DWORD *)(a2 + 4120) || !v34 )
  {
    *(_BYTE *)(*(_DWORD *)(a2 + 500))++ = (_BYTE)NumStats;
    v13 = *(_DWORD *)(a2 + 504);
    v31 = *(PPM_CONTEXT **)(a2 + 500);
    if ( (unsigned int)v31 >= v13 )
      goto RESTART_MODEL;
    if ( v34 )
    {
      if ( (unsigned int)v34 >= v13 )
      {
LABEL_20:
        if ( !v34 )
          goto RESTART_MODEL;
        v16 = (*(_DWORD *)(a2 + 4120))-- == 1;
        v17 = MinContext;
        if ( v16 )
        {
          v31 = v34;
          *(_DWORD *)(a2 + 500) -= *(_DWORD *)(a2 + 3592) != (_DWORD)MinContext;
        }
        else if ( *(int *)(a2 + 7596) > 2 )
        {
          *(_DWORD *)(a2 + 4120) = 0;
          v31 = v34;
          *(_DWORD *)(a2 + 500) = *(_DWORD *)(a2 + 496);
        }
        v18 = HIWORD(MinContext->m_allocator) - LOBYTE(MinContext->m_allocator) - v33;
        m_allocator_low = LOBYTE(MinContext->m_allocator);
        v32 = v18;
        for ( i = 8 * ((unsigned __int8)NumStats >= 0x40u); v8 != (PPM_CONTEXT *)MinContext; v8 = v8->Suffix )
        {
          NumStats = (PPM_CONTEXT *)v8->NumStats;
          if ( v8->NumStats )
          {
            if ( ((unsigned __int8)NumStats & 1) != 0 )
            {
              v19 = ppmd_allocator::ExpandUnits(
                      v17,
                      (ppmd_allocator *)(a2 + 12),
                      (BLK_NODE *)v8->Stats,
                      (unsigned int)&NumStats->Flags >> 1);
              if ( !v19 )
                goto RESTART_MODEL;
              v18 = v32;
              v8->Stats = (PPM_CONTEXT::STATE *)v19;
            }
            v8->SummFreq += 3 * (int)NumStats + 1 < m_allocator_low;
          }
          else
          {
            v20 = ppmd_allocator::AllocUnits((ppmd_allocator *)(a2 + 12), 1u);
            if ( !v20 )
              goto RESTART_MODEL;
            *(_WORD *)v20 = v8->SummFreq;
            *(_DWORD *)(v20 + 2) = v8->Stats;
            v8->Stats = (PPM_CONTEXT::STATE *)v20;
            v21 = v20[1];
            if ( v21 >= 0x1Eu )
              v20[1] = 120;
            else
              v20[1] = 2 * v21;
            v18 = v32;
            v8->SummFreq = v20[1] + *(_WORD *)(a2 + 4116) + (m_allocator_low > 2);
          }
          SummFreq = v8->SummFreq;
          v23 = v33 * (SummFreq + 6);
          v24 = v18 + SummFreq;
          v25 = 2 * v23;
          if ( v25 >= 6 * v24 )
          {
            v17 = (ppmd_allocator *)((12 * v24 < v25) + (15 * v24 < v25) + (9 * v24 < v25) + 4);
            v18 = v32;
            v26 = (_WORD)v17 + v8->SummFreq;
          }
          else
          {
            v17 = (ppmd_allocator *)((v25 >= 4 * v24) + (v24 < v25) + 1);
            v26 = v8->SummFreq + 4;
          }
          ++v8->NumStats;
          v8->SummFreq = v26;
          v27 = (int)&v8->Stats[v8->NumStats];
          *(_DWORD *)(v27 + 2) = v31;
          *(_BYTE *)v27 = v36;
          *(_BYTE *)(v27 + 1) = (_BYTE)v17;
          v8->Flags |= i;
        }
        v14 = v34;
        goto LABEL_41;
      }
      Successors = ppmd_compressor_impl::CreateSuccessors(
                     Stats,
                     (PPM_CONTEXT *)MinContext,
                     (ppmd_compressor_impl *)a2,
                     0);
    }
    else
    {
      Successors = ppmd_compressor_impl::ReduceOrder((ppmd_compressor_impl *)a2, Stats, (PPM_CONTEXT *)MinContext);
    }
    v34 = Successors;
    goto LABEL_20;
  }
  v12 = ppmd_compressor_impl::CreateSuccessors(Stats, (PPM_CONTEXT *)MinContext, (ppmd_compressor_impl *)a2, 1);
  v13 = *(_DWORD *)(a2 + 4112);
  *(_DWORD *)(v13 + 2) = v12;
  v14 = *(PPM_CONTEXT **)(*(_DWORD *)(a2 + 4112) + 2);
  if ( !v14 )
  {
RESTART_MODEL:
    ppmd_compressor_impl::RestoreModelRare(
      (ppmd_compressor_impl *)v13,
      (ppmd_allocator *)NumStats,
      (ppmd_compressor_impl *)a2,
      v8,
      (PPM_CONTEXT *)MinContext,
      v34);
    return;
  }
LABEL_41:
  *(_DWORD *)(a2 + 3592) = v14;
}
