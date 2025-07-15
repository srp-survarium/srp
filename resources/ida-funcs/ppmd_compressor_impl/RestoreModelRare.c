void __userpurge ppmd_compressor_impl::RestoreModelRare(
        ppmd_compressor_impl *this@<ecx>,
        ppmd_allocator *a2@<ebx>,
        ppmd_compressor_impl *a3@<edi>,
        PPM_CONTEXT *pc1,
        PPM_CONTEXT *MinContext,
        PPM_CONTEXT *FSuccessor)
{
  PPM_CONTEXT *MaxContext; // esi
  PPM_CONTEXT::STATE *Stats; // ecx
  unsigned __int8 NumStats; // al
  vostok::ppmd_compressor::model_restoration_enum MRMethod; // esi
  PPM_CONTEXT *v11; // eax
  int MaxOrder; // eax
  ppmd_allocator *v13; // ecx
  int v14; // eax
  ppmd_allocator *v15; // [esp-4h] [ebp-8h]

  MaxContext = a3->MaxContext;
  a3->m_allocator.pText = a3->m_allocator.HeapStart;
  while ( MaxContext != pc1 )
  {
    if ( MaxContext->NumStats-- == 1 )
    {
      Stats = MaxContext->Stats;
      MaxContext->Flags = (MaxContext->Flags & 0x10) + 8 * (Stats->Symbol >= 0x40u);
      MaxContext->SummFreq = *(_WORD *)&Stats->Symbol;
      MaxContext->Stats = (PPM_CONTEXT::STATE *)Stats->Successor;
      ppmd_allocator::SpecialFreeUnit((ppmd_allocator *)Stats, &a3->m_allocator.m_allocator);
      HIBYTE(MaxContext->SummFreq) = (HIBYTE(MaxContext->SummFreq) + 11) >> 3;
    }
    else
    {
      PPM_CONTEXT::refresh(MaxContext, (MaxContext->NumStats + 3) >> 1, a3, 0);
    }
    MaxContext = MaxContext->Suffix;
  }
  while ( MaxContext != MinContext )
  {
    NumStats = MaxContext->NumStats;
    if ( MaxContext->NumStats )
    {
      MaxContext->SummFreq += 4;
      if ( MaxContext->SummFreq > 4 * NumStats + 128 )
        PPM_CONTEXT::refresh(MaxContext, (NumStats + 2) >> 1, a3, 1u);
    }
    else
    {
      HIBYTE(MaxContext->SummFreq) -= HIBYTE(MaxContext->SummFreq) >> 1;
    }
    MaxContext = MaxContext->Suffix;
  }
  MRMethod = a3->MRMethod;
  if ( MRMethod <= model_restoration_freeze )
  {
    if ( MRMethod == model_restoration_freeze )
    {
      while ( 1 )
      {
        v11 = a3->MaxContext;
        if ( !v11->Suffix )
          break;
        a3->MaxContext = a3->MaxContext->Suffix;
      }
      PPM_CONTEXT::removeBinConts(v11, a3, 0);
      MaxOrder = a3->MaxOrder;
      ++a3->MRMethod;
      a3->m_allocator.GlueCount = 0;
      a3->OrderFall = MaxOrder;
    }
    else if ( MRMethod && ppmd_allocator::GetUsedMemory(a2) >= a3->m_allocator.SubAllocatorSize >> 1 )
    {
      while ( a3->MaxContext->Suffix )
        a3->MaxContext = a3->MaxContext->Suffix;
      do
      {
        PPM_CONTEXT::cutOff(a3->MaxContext, a3, 0);
        ppmd_allocator::ExpandTextArea(v13, (int)&a3->m_allocator);
      }
      while ( ppmd_allocator::GetUsedMemory(v15) > 3 * (a3->m_allocator.SubAllocatorSize >> 2) );
      v14 = a3->MaxOrder;
      a3->m_allocator.GlueCount = 0;
      a3->OrderFall = v14;
    }
    else
    {
      ppmd_compressor_impl::StartModelRare(MRMethod, a3, a3->MaxOrder);
      a3->EscCount = 0;
      a3->PrintCount = -1;
    }
  }
  else
  {
    a3->MaxContext = FSuccessor;
    a3->m_allocator.GlueCount += (a3->m_allocator.BList[1].Stamp & 1) == 0;
  }
}
