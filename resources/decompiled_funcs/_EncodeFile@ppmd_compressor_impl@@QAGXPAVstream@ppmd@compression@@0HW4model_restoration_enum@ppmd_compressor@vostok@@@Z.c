void __userpurge ppmd_compressor_impl::EncodeFile(
        ppmd_compressor_impl *this@<edi>,
        vostok::ppmd_compressor::model_restoration_enum MRMethod@<eax>,
        compression::ppmd::stream *EncodedFile,
        compression::ppmd::stream *DecodedFile,
        int MaxOrder)
{
  unsigned __int8 *m_pointer; // eax
  PPM_CONTEXT *MaxContext; // ebp
  unsigned __int8 NumStats; // dl
  int v8; // ebx
  unsigned int v9; // eax
  unsigned int low; // ecx
  unsigned int v11; // eax
  PPM_CONTEXT *Successor; // eax

  this->m_low = 0;
  this->m_range = -1;
  ppmd_compressor_impl::StartModelRare(MRMethod, (unsigned int)this, this, 8);
  while ( 1 )
  {
    m_pointer = DecodedFile->m_pointer;
    MaxContext = this->MaxContext;
    NumStats = MaxContext->NumStats;
    if ( m_pointer >= &DecodedFile->m_buffer[DecodedFile->m_buffer_size] )
    {
      v8 = -1;
    }
    else
    {
      v8 = *m_pointer;
      DecodedFile->m_pointer = m_pointer + 1;
    }
    if ( NumStats )
    {
      PPM_CONTEXT::encodeSymbol1(MaxContext, this, v8);
      v9 = this->m_range / this->m_SubRange.scale;
      low = this->m_SubRange.low;
      this->m_low += v9 * low;
      this->m_range = v9 * (this->m_SubRange.high - low);
    }
    else
    {
      PPM_CONTEXT::encodeBinSymbol(MaxContext, this, v8);
    }
    if ( !this->FoundState )
      break;
LABEL_13:
    if ( this->OrderFall
      || (Successor = this->FoundState->Successor, (unsigned __int8 *)Successor < this->m_allocator.UnitsStart) )
    {
      ppmd_compressor_impl::UpdateModel((ppmd_compressor_impl *)low, this, MaxContext);
      if ( !this->EscCount )
      {
        this->EscCount = 1;
        memset((int)this->CharMask, 0, sizeof(this->CharMask));
        ++this->PrintCount;
      }
      ppmd_compressor_impl::rcEncNormalize(this, EncodedFile);
    }
    else
    {
      this->MaxContext = Successor;
      ppmd_compressor_impl::rcEncNormalize(this, EncodedFile);
    }
  }
LABEL_9:
  ppmd_compressor_impl::rcEncNormalize(this, EncodedFile);
  while ( 1 )
  {
    ++this->OrderFall;
    MaxContext = MaxContext->Suffix;
    if ( !MaxContext )
      break;
    if ( MaxContext->NumStats != this->NumMasked )
    {
      PPM_CONTEXT::encodeSymbol2(this, MaxContext, v8);
      v11 = this->m_range / this->m_SubRange.scale;
      low = this->m_SubRange.low;
      this->m_low += v11 * low;
      this->m_range = v11 * (this->m_SubRange.high - low);
      if ( !this->FoundState )
        goto LABEL_9;
      goto LABEL_13;
    }
  }
  *EncodedFile->m_pointer++ = HIBYTE(this->m_low);
  this->m_low <<= 8;
  *EncodedFile->m_pointer++ = HIBYTE(this->m_low);
  this->m_low <<= 8;
  *EncodedFile->m_pointer++ = HIBYTE(this->m_low);
  this->m_low <<= 8;
  *EncodedFile->m_pointer++ = HIBYTE(this->m_low);
  this->m_low <<= 8;
}
