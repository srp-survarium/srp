void __userpurge ppmd_compressor_impl::RestoreModelRare(
        ppmd_compressor_impl *this@<ecx>,
        int a2@<esi>,
        PPM_CONTEXT *pc1,
        PPM_CONTEXT *MinContext,
        PPM_CONTEXT *FSuccessor)
{
  PPM_CONTEXT *v5; // edi
  PPM_CONTEXT::STATE *Stats; // eax
  unsigned __int8 NumStats; // al
  vostok::ppmd_compressor::model_restoration_enum v9; // ebp
  int v10; // ecx
  int v11; // edx
  int v12; // edx
  ppmd_allocator *v13; // ecx
  ppmd_allocator *v14; // [esp+0h] [ebp-Ch]
  ppmd_allocator *v15; // [esp+0h] [ebp-Ch]

  v5 = *(PPM_CONTEXT **)(a2 + 3592);
  for ( *(_DWORD *)(a2 + 500) = *(_DWORD *)(a2 + 496); v5 != pc1; v5 = v5->Suffix )
  {
    if ( v5->NumStats-- == 1 )
    {
      Stats = v5->Stats;
      v5->Flags = (v5->Flags & 0x10) + 8 * (Stats->Symbol >= 0x40u);
      v5->SummFreq = *(_WORD *)&Stats->Symbol;
      v5->Stats = (PPM_CONTEXT::STATE *)Stats->Successor;
      if ( Stats == *(PPM_CONTEXT::STATE **)(a2 + 504) )
      {
        *(_DWORD *)&Stats->Symbol = -1;
        *(_DWORD *)(a2 + 504) += 12;
      }
      else
      {
        *(PPM_CONTEXT **)((char *)&Stats->Successor + 2) = *(PPM_CONTEXT **)(a2 + 20);
        *(_DWORD *)(a2 + 20) = Stats;
        *(_DWORD *)&Stats->Symbol = -1;
        Stats[1].Successor = (PPM_CONTEXT *)1;
        ++*(_DWORD *)(a2 + 16);
      }
      HIBYTE(v5->SummFreq) = (HIBYTE(v5->SummFreq) + 11) >> 3;
    }
    else
    {
      PPM_CONTEXT::refresh((PPM_CONTEXT *)a2, v5, (v5->NumStats + 3) >> 1, 0);
    }
  }
  for ( ; v5 != MinContext; v5 = v5->Suffix )
  {
    NumStats = v5->NumStats;
    if ( v5->NumStats )
    {
      v5->SummFreq += 4;
      if ( v5->SummFreq > 4 * NumStats + 128 )
        PPM_CONTEXT::refresh((PPM_CONTEXT *)a2, v5, (NumStats + 2) >> 1, 1);
    }
    else
    {
      HIBYTE(v5->SummFreq) -= HIBYTE(v5->SummFreq) >> 1;
    }
  }
  v9 = *(_DWORD *)(a2 + 7596);
  if ( v9 > model_restoration_freeze )
  {
    *(_DWORD *)(a2 + 488) += (*(_DWORD *)(a2 + 24) & 1) == 0;
    *(_DWORD *)(a2 + 3592) = FSuccessor;
    return;
  }
  if ( v9 == model_restoration_freeze )
  {
    if ( *(_DWORD *)(*(_DWORD *)(a2 + 3592) + 8) )
    {
      do
      {
        v10 = *(_DWORD *)(*(_DWORD *)(a2 + 3592) + 8);
        *(_DWORD *)(a2 + 3592) = v10;
      }
      while ( *(_DWORD *)(v10 + 8) );
    }
    PPM_CONTEXT::removeBinConts(*(PPM_CONTEXT **)(a2 + 3592), (ppmd_compressor_impl *)a2, 0);
    ++*(_DWORD *)(a2 + 7596);
LABEL_21:
    v11 = *(_DWORD *)(a2 + 4132);
    *(_DWORD *)(a2 + 488) = 0;
    *(_DWORD *)(a2 + 4120) = v11;
    return;
  }
  if ( v9 )
  {
    v5 = (PPM_CONTEXT *)(a2 + 12);
    if ( ppmd_allocator::GetUsedMemory(v14) >= *(_DWORD *)(a2 + 492) >> 1 )
    {
      if ( *(_DWORD *)(*(_DWORD *)(a2 + 3592) + 8) )
      {
        do
        {
          v12 = *(_DWORD *)(*(_DWORD *)(a2 + 3592) + 8);
          *(_DWORD *)(a2 + 3592) = v12;
        }
        while ( *(_DWORD *)(v12 + 8) );
      }
      do
      {
        PPM_CONTEXT::cutOff(*(PPM_CONTEXT **)(a2 + 3592), (ppmd_compressor_impl *)a2, 0);
        ppmd_allocator::ExpandTextArea(v13, a2 + 12);
      }
      while ( ppmd_allocator::GetUsedMemory(v15) > 3 * (*(_DWORD *)(a2 + 492) >> 2) );
      goto LABEL_21;
    }
  }
  ppmd_compressor_impl::StartModelRare(v9, (unsigned int)v5, (ppmd_compressor_impl *)a2, *(_DWORD *)(a2 + 4132));
  *(_BYTE *)(a2 + 4394) = 0;
  *(_BYTE *)(a2 + 4395) = -1;
}
