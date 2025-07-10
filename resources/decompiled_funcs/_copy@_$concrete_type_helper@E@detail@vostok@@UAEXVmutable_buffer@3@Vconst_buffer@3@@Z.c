void __thiscall vostok::detail::concrete_type_helper<unsigned char>::copy(
        vostok::detail::concrete_type_helper<unsigned char> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  *dest_buffer.m_data = *src_buffer.m_data;
}
