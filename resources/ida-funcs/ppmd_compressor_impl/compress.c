void __thiscall ppmd_compressor_impl::compress(
        ppmd_compressor_impl *this,
        vostok::const_buffer src,
        vostok::mutable_buffer dest,
        unsigned int *out_size)
{
  compression::ppmd::stream DecodedFile; // [esp+0h] [ebp-18h] BYREF
  compression::ppmd::stream EncodedFile; // [esp+Ch] [ebp-Ch] BYREF

  DecodedFile.m_buffer = (unsigned __int8 *)src.m_data;
  DecodedFile.m_pointer = (unsigned __int8 *)src.m_data;
  EncodedFile.m_buffer_size = dest.m_size;
  EncodedFile.m_buffer = (unsigned __int8 *)dest.m_data;
  EncodedFile.m_pointer = (unsigned __int8 *)dest.m_data;
  ppmd_compressor_impl::EncodeFile(this, this->m_MRMethod, &EncodedFile, &DecodedFile, src.m_size);
  *out_size = EncodedFile.m_pointer - EncodedFile.m_buffer + 1;
}
