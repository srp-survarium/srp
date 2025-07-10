void __userpurge ppmd_compressor_impl::DecodeFile(
        ppmd_compressor_impl *a1@<edi>,
        ppmd_compressor_impl *this,
        compression::ppmd::stream *DecodedFile,
        compression::ppmd::stream *EncodedFile,
        int MaxOrder,
        vostok::ppmd_compressor::model_restoration_enum MRMethod)
{
  PPM_CONTEXT *MaxContext; // ebp
  unsigned __int8 NumStats; // bl
  unsigned int low; // ecx
  unsigned int m_range; // eax
  unsigned int v10; // ecx
  unsigned int v11; // eax
  ppmd_compressor_impl *FoundState; // ecx
  PPM_CONTEXT *v13; // eax

  ppmd_compressor_impl::rcInitDecoder(a1, DecodedFile);
  ppmd_compressor_impl::StartModelRare(
    (vostok::ppmd_compressor::model_restoration_enum)EncodedFile,
    (unsigned int)a1,
    a1,
    8);
  MaxContext = a1->MaxContext;
  NumStats = MaxContext->NumStats;
  while ( 1 )
  {
    if ( NumStats )
    {
      PPM_CONTEXT::decodeSymbol1(a1, MaxContext);
      low = a1->m_SubRange.low;
      m_range = a1->m_range;
      a1->m_low += m_range * low;
      a1->m_range = m_range * (a1->m_SubRange.high - low);
    }
    else
    {
      PPM_CONTEXT::decodeBinSymbol(MaxContext, a1);
    }
    if ( !a1->FoundState )
      break;
LABEL_10:
    FoundState = this;
    (this->StartModelRare_context++)->NumStats = a1->FoundState->Symbol;
    if ( a1->OrderFall
      || (FoundState = (ppmd_compressor_impl *)a1->FoundState,
          v13 = *(PPM_CONTEXT **)((char *)&FoundState->__vftable + 2),
          (unsigned __int8 *)v13 < a1->m_allocator.UnitsStart) )
    {
      ppmd_compressor_impl::UpdateModel(FoundState, a1, MaxContext);
      if ( !a1->EscCount )
      {
        a1->EscCount = 1;
        memset((int)a1->CharMask, 0, sizeof(a1->CharMask));
        ++a1->PrintCount;
      }
    }
    else
    {
      a1->MaxContext = v13;
    }
    MaxContext = a1->MaxContext;
    NumStats = MaxContext->NumStats;
    ppmd_compressor_impl::rcDecNormalize(a1, DecodedFile);
  }
LABEL_6:
  ppmd_compressor_impl::rcDecNormalize(a1, DecodedFile);
  while ( 1 )
  {
    ++a1->OrderFall;
    MaxContext = MaxContext->Suffix;
    if ( !MaxContext )
      break;
    if ( MaxContext->NumStats != a1->NumMasked )
    {
      PPM_CONTEXT::decodeSymbol2(a1, MaxContext);
      v10 = a1->m_SubRange.low;
      v11 = a1->m_range;
      a1->m_low += v11 * v10;
      a1->m_range = v11 * (a1->m_SubRange.high - v10);
      if ( !a1->FoundState )
        goto LABEL_6;
      goto LABEL_10;
    }
  }
}
