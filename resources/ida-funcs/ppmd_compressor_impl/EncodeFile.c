void __userpurge ppmd_compressor_impl::EncodeFile(
        ppmd_compressor_impl *this@<ecx>,
        vostok::ppmd_compressor::model_restoration_enum MRMethod@<eax>,
        compression::ppmd::stream *EncodedFile,
        compression::ppmd::stream *DecodedFile,
        int MaxOrder)
{
  PPM_CONTEXT *MaxContext; // esi
  unsigned __int8 NumStats; // bl
  ppmd_compressor_impl *v8; // ecx
  compression::ppmd::stream *v9; // ebx
  PPM_CONTEXT *Successor; // eax
  int v11; // eax
  int v12; // [esp+Ch] [ebp-4h]

  this->m_low = 0;
  this->m_range = -1;
  ppmd_compressor_impl::StartModelRare(MRMethod, this, 8);
  while ( 1 )
  {
    MaxContext = this->MaxContext;
    NumStats = MaxContext->NumStats;
    v12 = compression::ppmd::stream::get_char(DecodedFile);
    if ( NumStats )
    {
      PPM_CONTEXT::encodeSymbol1(MaxContext, this, v12);
      ppmd_compressor_impl::rcEncodeSymbol(this);
    }
    else
    {
      PPM_CONTEXT::encodeBinSymbol(MaxContext, this, v12);
    }
    if ( !this->FoundState )
      break;
    v9 = EncodedFile;
LABEL_12:
    if ( this->OrderFall
      || (Successor = this->FoundState->Successor, (unsigned __int8 *)Successor < this->m_allocator.UnitsStart) )
    {
      ppmd_compressor_impl::UpdateModel(v8, (int)this, (ppmd_allocator *)MaxContext);
      if ( !this->EscCount )
      {
        this->EscCount = 1;
        memset((int)this->CharMask, 0, sizeof(this->CharMask));
        ++this->PrintCount;
      }
    }
    else
    {
      this->MaxContext = Successor;
    }
    ppmd_compressor_impl::rcEncNormalize(this, v9);
  }
LABEL_6:
  v9 = EncodedFile;
  ppmd_compressor_impl::rcEncNormalize(this, EncodedFile);
  while ( 1 )
  {
    ++this->OrderFall;
    MaxContext = MaxContext->Suffix;
    if ( !MaxContext )
      break;
    if ( MaxContext->NumStats != this->NumMasked )
    {
      PPM_CONTEXT::encodeSymbol2(this, MaxContext, v12);
      ppmd_compressor_impl::rcEncodeSymbol(this);
      if ( !this->FoundState )
        goto LABEL_6;
      goto LABEL_12;
    }
  }
  v11 = 4;
  do
  {
    *EncodedFile->m_pointer++ = HIBYTE(this->m_low);
    this->m_low <<= 8;
    --v11;
  }
  while ( v11 );
}
