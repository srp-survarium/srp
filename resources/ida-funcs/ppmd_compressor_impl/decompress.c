void __thiscall ppmd_compressor_impl::decompress(
        ppmd_compressor_impl *this,
        vostok::const_buffer src,
        vostok::mutable_buffer dest,
        unsigned int *out_size)
{
  compression::ppmd::stream *m_MRMethod; // [esp-4h] [ebp-1Ch]
  compression::ppmd::stream DecodedFile; // [esp+0h] [ebp-18h] BYREF
  unsigned int m_size; // [esp+Ch] [ebp-Ch] BYREF
  char *m_data; // [esp+10h] [ebp-8h]
  char *v8; // [esp+14h] [ebp-4h]

  m_MRMethod = (compression::ppmd::stream *)this->m_MRMethod;
  m_size = dest.m_size;
  DecodedFile.m_pointer = (unsigned __int8 *)src.m_data;
  m_data = dest.m_data;
  v8 = dest.m_data;
  ppmd_compressor_impl::DecodeFile(
    this,
    (ppmd_compressor_impl *)&m_size,
    &DecodedFile,
    m_MRMethod,
    src.m_size,
    (vostok::ppmd_compressor::model_restoration_enum)src.m_data);
  *out_size = v8 - m_data;
}
