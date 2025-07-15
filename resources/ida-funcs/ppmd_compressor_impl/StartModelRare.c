void __userpurge ppmd_compressor_impl::StartModelRare(
        vostok::ppmd_compressor::model_restoration_enum MRMethod@<eax>,
        unsigned int a2@<edi>,
        ppmd_compressor_impl *this,
        int MaxOrder)
{
  ppmd_allocator *v6; // ecx
  int v7; // edi
  PPM_CONTEXT *MaxContext; // eax
  unsigned int v9; // ecx
  int v10; // ebx
  unsigned __int16 *v11; // esi
  unsigned __int16 *v12; // edi
  unsigned __int16 *v13; // eax
  int v14; // ecx
  int v15; // ecx
  int v16; // edx
  unsigned __int8 *v17; // edi
  SEE2_CONTEXT *v18; // eax
  SEE2_CONTEXT *v19; // ecx
  int v20; // esi
  bool v21; // zf
  unsigned __int8 *HiUnit; // eax
  PPM_CONTEXT *next; // eax
  BLK_NODE *Stats; // edx
  compression::ppmd::stream *v25; // eax
  unsigned __int8 *m_pointer; // ecx
  int v27; // edx
  int v28; // ecx
  unsigned int i; // eax
  int v30; // eax
  PPM_CONTEXT *StartModelRare_context; // edx
  unsigned __int8 *QTable; // [esp+8h] [ebp-4h]
  int v34; // [esp+8h] [ebp-4h]
  unsigned int m; // [esp+10h] [ebp+4h]
  unsigned int ma; // [esp+10h] [ebp+4h]

  if ( this->StartModelRare_first_time )
  {
    memset((int)this->CharMask, 0, sizeof(this->CharMask));
    v7 = MaxOrder;
    this->PrintCount = 1;
    this->EscCount = 1;
    if ( MaxOrder >= 2 )
    {
      this->MRMethod = MRMethod;
      this->MaxOrder = MaxOrder;
      this->OrderFall = MaxOrder;
      ppmd_allocator::InitSubAllocator(v6, (int)&this->m_allocator);
      if ( MaxOrder >= 12 )
        v7 = 12;
      this->InitRL = -1 - v7;
      this->RunLength = -1 - v7;
      v9 = 0;
      m = 0;
      v10 = 0;
      QTable = this->QTable;
      v11 = &this->BinSumm[0][8];
      v12 = &this->BinSumm[0][1];
      while ( 1 )
      {
        for ( ; *QTable == v9; QTable = &this->QTable[v10] )
          ++v10;
        *(v12 - 1) = 0x4000 - 0x3CDDu / (v10 + 1);
        *v12 = 0x4000 - 0x1F3Fu / (v10 + 1);
        v12[1] = 0x4000 - 0x59BFu / (v10 + 1);
        v12[2] = 0x4000 - 0x48F3u / (v10 + 1);
        v12[3] = 0x4000 - 0x64A1u / (v10 + 1);
        v12[4] = 0x4000 - 0x5ABCu / (v10 + 1);
        v12[5] = 0x4000 - 0x6632u / (v10 + 1);
        v12[6] = 0x4000 - 0x6051u / (v10 + 1);
        v13 = v11;
        v14 = 7;
        do
        {
          *(_QWORD *)v13 = *((_QWORD *)v11 - 2);
          *((_QWORD *)v13 + 1) = *((_QWORD *)v11 - 1);
          v13 += 8;
          --v14;
        }
        while ( v14 );
        v12 += 64;
        v11 += 64;
        if ( ++m >= 0x19 )
          break;
        v9 = m;
      }
      v15 = 3;
      v16 = 0;
      v17 = &this->QTable[3];
      ma = 3;
      v18 = this->SEE2Cont[0];
      v34 = 24;
      do
      {
        for ( ; *v17 == v15; v17 = &this->QTable[v16 + 3] )
          ++v16;
        v18->Summ = 16 * v16 + 40;
        v18->Shift = 3;
        v18->Count = 7;
        v19 = v18 + 1;
        v20 = 31;
        do
        {
          *v19++ = *v18;
          --v20;
        }
        while ( v20 );
        v15 = ma + 1;
        v18 += 32;
        v21 = v34-- == 1;
        ++ma;
      }
      while ( !v21 );
      HiUnit = this->m_allocator.HiUnit;
      if ( HiUnit == this->m_allocator.LoUnit )
      {
        if ( this->m_allocator.BList[0].next )
        {
          next = (PPM_CONTEXT *)this->m_allocator.BList[0].next;
          Stats = (BLK_NODE *)next->Stats;
          --this->m_allocator.BList[0].Stamp;
          this->m_allocator.BList[0].next = Stats;
        }
        else
        {
          next = (PPM_CONTEXT *)ppmd_allocator::AllocUnitsRare(&this->m_allocator, 0, a2);
        }
      }
      else
      {
        next = (PPM_CONTEXT *)(HiUnit - 12);
        this->m_allocator.HiUnit = &next->NumStats;
      }
      this->MaxContext = next;
      next->Suffix = 0;
      v25 = trained_model;
      if ( trained_model
        && ((m_pointer = trained_model->m_pointer, m_pointer >= &trained_model->m_buffer[trained_model->m_buffer_size])
          ? (unsigned __int8 *)(v27 = -1)
          : (v27 = *m_pointer, trained_model->m_pointer = m_pointer + 1),
            v27 <= MaxOrder) )
      {
        PPM_CONTEXT::read(this->MaxContext, (unsigned int)this, this, (int)v25, 0xFFu);
        PPM_CONTEXT::makeSuffix(this->MaxContext);
        this->StartModelRare_context = this->MaxContext;
      }
      else
      {
        this->MaxContext->NumStats = -1;
        this->MaxContext->SummFreq = 257;
        this->MaxContext->Stats = (PPM_CONTEXT::STATE *)ppmd_allocator::AllocUnits(&this->m_allocator, 0x80u);
        v28 = 0;
        this->PrevSuccess = 0;
        for ( i = 0; i < 256; ++i )
        {
          this->MaxContext->Stats[i].Symbol = v28;
          this->MaxContext->Stats[i].Freq = 1;
          this->MaxContext->Stats[i].Successor = 0;
          ++v28;
        }
        this->StartModelRare_context = this->MaxContext;
      }
    }
    else
    {
      MaxContext = this->MaxContext;
      for ( this->OrderFall = this->MaxOrder; MaxContext; MaxContext = MaxContext->Suffix )
      {
        if ( !MaxContext->Suffix )
          break;
        --this->OrderFall;
      }
    }
  }
  else
  {
    memset((int)this->CharMask, 0, sizeof(this->CharMask));
    v30 = MaxOrder;
    this->PrintCount = 1;
    this->EscCount = 1;
    this->MaxOrder = MaxOrder;
    this->OrderFall = MaxOrder;
    this->MRMethod = MRMethod;
    if ( MaxOrder >= 12 )
      v30 = 12;
    StartModelRare_context = this->StartModelRare_context;
    this->InitRL = -1 - v30;
    this->RunLength = -1 - v30;
    this->MaxContext = StartModelRare_context;
    this->FoundState = 0;
  }
}
