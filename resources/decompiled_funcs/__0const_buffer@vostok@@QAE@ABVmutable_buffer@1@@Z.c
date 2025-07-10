void __thiscall vostok::const_buffer::const_buffer(vostok::const_buffer *this, const vostok::mutable_buffer *buffer)
{
  this->m_data = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                 (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
                                 (int)buffer);
  this->m_size = buffer->m_size;
}
