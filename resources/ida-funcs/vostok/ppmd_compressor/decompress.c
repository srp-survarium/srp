char __thiscall vostok::ppmd_compressor::decompress(
        vostok::ppmd_compressor *this,
        vostok::const_buffer src,
        vostok::mutable_buffer dest,
        unsigned int *out_size)
{
  ((void (__thiscall *)(ppmd_compressor_impl *, const char *, unsigned int, char *, unsigned int, unsigned int *))this->m_impl->decompress)(
    this->m_impl,
    src.m_data,
    src.m_size,
    dest.m_data,
    dest.m_size,
    out_size);
  return 1;
}
