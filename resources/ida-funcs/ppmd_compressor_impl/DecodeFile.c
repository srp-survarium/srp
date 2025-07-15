void __userpurge ppmd_compressor_impl::DecodeFile(
        ppmd_compressor_impl *a1@<eax>,
        ppmd_compressor_impl *this,
        compression::ppmd::stream *DecodedFile,
        compression::ppmd::stream *EncodedFile,
        int MaxOrder,
        vostok::ppmd_compressor::model_restoration_enum MRMethod)
{
  int v7; // edi
  PPM_CONTEXT *MaxContext; // ebx
  unsigned __int8 i; // al
  ppmd_compressor_impl *v10; // ecx
  ppmd_compressor_impl *v11; // ecx
  ppmd_compressor_impl *StartModelRare_context; // ecx
  PPM_CONTEXT *Successor; // eax
  unsigned __int8 MRMethod_3; // [esp+1Fh] [ebp+13h]

  a1->m_code = 0;
  a1->m_low = 0;
  a1->m_range = -1;
  v7 = 4;
  do
  {
    --v7;
    a1->m_code = (a1->m_code << 8) | compression::ppmd::stream::get_char(DecodedFile);
  }
  while ( v7 );
  ppmd_compressor_impl::StartModelRare((vostok::ppmd_compressor::model_restoration_enum)EncodedFile, a1, 8);
  MaxContext = a1->MaxContext;
  for ( i = MaxContext->NumStats; ; i = MRMethod_3 )
  {
    if ( i )
    {
      PPM_CONTEXT::decodeSymbol1(MaxContext, a1);
LABEL_11:
      ppmd_compressor_impl::rcRemoveSubrange(v10, a1);
    }
    else
    {
      PPM_CONTEXT::decodeBinSymbol(MaxContext, a1);
    }
    if ( !a1->FoundState )
      break;
    StartModelRare_context = (ppmd_compressor_impl *)this->StartModelRare_context;
    LOBYTE(StartModelRare_context->__vftable) = a1->FoundState->Symbol;
    ++this->StartModelRare_context;
    if ( a1->OrderFall
      || (Successor = a1->FoundState->Successor, (unsigned __int8 *)Successor < a1->m_allocator.UnitsStart) )
    {
      ppmd_compressor_impl::UpdateModel(StartModelRare_context, (int)a1, (ppmd_allocator *)MaxContext);
      if ( !a1->EscCount )
      {
        a1->EscCount = 1;
        memset((int)a1->CharMask, 0, sizeof(a1->CharMask));
        ++a1->PrintCount;
      }
    }
    else
    {
      a1->MaxContext = Successor;
    }
    MaxContext = a1->MaxContext;
    MRMethod_3 = MaxContext->NumStats;
    ppmd_compressor_impl::rcDecNormalize(StartModelRare_context, a1, DecodedFile);
  }
  ppmd_compressor_impl::rcDecNormalize(v11, a1, DecodedFile);
  while ( 1 )
  {
    ++a1->OrderFall;
    MaxContext = MaxContext->Suffix;
    if ( !MaxContext )
      break;
    if ( MaxContext->NumStats != a1->NumMasked )
    {
      PPM_CONTEXT::decodeSymbol2(a1, MaxContext);
      goto LABEL_11;
    }
  }
}
