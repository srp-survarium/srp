void __userpurge ppmd_compressor_impl::StartModelRare(
        vostok::ppmd_compressor::model_restoration_enum MRMethod@<eax>,
        ppmd_compressor_impl *this,
        int MaxOrder)
{
  ppmd_allocator *v5; // ecx
  int v6; // edi
  PPM_CONTEXT *m; // eax
  unsigned __int16 *v8; // ecx
  unsigned __int8 *i; // eax
  unsigned int j; // esi
  unsigned int v11; // edx
  unsigned __int16 *v12; // eax
  _DWORD *v13; // eax
  int v14; // edx
  _DWORD *v15; // edi
  unsigned __int8 *v16; // esi
  SEE2_CONTEXT *v17; // eax
  SEE2_CONTEXT *v18; // edx
  PPM_CONTEXT *v19; // eax
  compression::ppmd::stream *v20; // esi
  int v21; // ecx
  unsigned int k; // eax
  int v23; // eax
  int v24; // ecx
  PPM_CONTEXT *StartModelRare_context; // eax
  unsigned __int8 *CharMask; // [esp-Ch] [ebp-24h]
  unsigned __int8 *QTable; // [esp+Ch] [ebp-Ch]
  int v28; // [esp+Ch] [ebp-Ch]
  unsigned __int16 *v29; // [esp+10h] [ebp-8h]
  int v30; // [esp+10h] [ebp-8h]
  unsigned int v31; // [esp+14h] [ebp-4h]
  int v32; // [esp+14h] [ebp-4h]
  ppmd_compressor_impl *impl; // [esp+20h] [ebp+8h]
  ppmd_compressor_impl *impla; // [esp+20h] [ebp+8h]

  CharMask = this->CharMask;
  if ( this->StartModelRare_first_time )
  {
    memset((int)CharMask, 0, 0x100u);
    v6 = MaxOrder;
    this->PrintCount = 1;
    this->EscCount = 1;
    if ( MaxOrder >= 2 )
    {
      this->MRMethod = MRMethod;
      this->MaxOrder = MaxOrder;
      this->OrderFall = MaxOrder;
      ppmd_allocator::InitSubAllocator(v5, &this->m_allocator.m_allocator);
      if ( MaxOrder >= 12 )
        v6 = 12;
      v31 = 0;
      impl = 0;
      this->InitRL = -1 - v6;
      this->RunLength = -1 - v6;
      QTable = this->QTable;
      v8 = this->BinSumm[0];
      do
      {
        for ( i = QTable; *i == v31; QTable = i )
        {
          impl = (ppmd_compressor_impl *)((char *)impl + 1);
          i = &impl->QTable[(_DWORD)this];
        }
        v29 = v8;
        for ( j = 0; j < 8; ++j )
        {
          v11 = 0x4000 - InitBinEsc[j] / ((unsigned int)&impl->__vftable + 1);
          v12 = v29++;
          *v12 = v11;
        }
        v13 = v8 + 8;
        v14 = 7;
        do
        {
          *v13 = *(_DWORD *)v8;
          v13[1] = *((_DWORD *)v8 + 1);
          v13[2] = *((_DWORD *)v8 + 2);
          v15 = v13 + 3;
          v13 += 4;
          --v14;
          *v15 = *((_DWORD *)v8 + 3);
        }
        while ( v14 );
        ++v31;
        v8 += 64;
      }
      while ( v31 < 0x19 );
      impla = 0;
      v16 = &this->QTable[3];
      v32 = 3;
      v17 = this->SEE2Cont[0];
      v30 = 24;
      do
      {
        while ( *v16 == v32 )
        {
          impla = (ppmd_compressor_impl *)((char *)impla + 1);
          v16 = &this->QTable[(_DWORD)impla + 3];
        }
        v17->Summ = 16 * (_WORD)impla + 40;
        v17->Shift = 3;
        v17->Count = 7;
        v18 = v17 + 1;
        v28 = 31;
        do
        {
          *v18++ = *v17;
          --v28;
        }
        while ( v28 );
        ++v32;
        v17 += 32;
        --v30;
      }
      while ( v30 );
      v19 = (PPM_CONTEXT *)ppmd_allocator::AllocContext(&this->m_allocator);
      v20 = trained_model;
      this->MaxContext = v19;
      v19->Suffix = 0;
      if ( v20 && compression::ppmd::stream::get_char(v20) <= MaxOrder )
      {
        PPM_CONTEXT::read(this->MaxContext, this, v20, 0xFFu);
        PPM_CONTEXT::makeSuffix(this->MaxContext);
      }
      else
      {
        this->MaxContext->NumStats = -1;
        this->MaxContext->SummFreq = 257;
        this->MaxContext->Stats = (PPM_CONTEXT::STATE *)ppmd_allocator::AllocUnits(&this->m_allocator, 0x80u);
        v21 = 0;
        this->PrevSuccess = 0;
        for ( k = 0; k < 256; ++k )
        {
          this->MaxContext->Stats[k].Symbol = v21;
          this->MaxContext->Stats[k].Freq = 1;
          this->MaxContext->Stats[k].Successor = 0;
          ++v21;
        }
      }
      this->StartModelRare_context = this->MaxContext;
    }
    else
    {
      this->OrderFall = this->MaxOrder;
      for ( m = this->MaxContext; m && m->Suffix; m = m->Suffix )
        --this->OrderFall;
    }
  }
  else
  {
    memset((int)CharMask, 0, 0x100u);
    v23 = MaxOrder;
    this->PrintCount = 1;
    this->EscCount = 1;
    this->MaxOrder = MaxOrder;
    this->OrderFall = MaxOrder;
    this->MRMethod = MRMethod;
    if ( MaxOrder >= 12 )
      v23 = 12;
    v24 = -1 - v23;
    StartModelRare_context = this->StartModelRare_context;
    this->FoundState = 0;
    this->InitRL = v24;
    this->RunLength = v24;
    this->MaxContext = StartModelRare_context;
  }
}
