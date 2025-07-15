unsigned int __thiscall vostok::particle::color_matrix::save_binary(
        vostok::particle::color_matrix *this,
        vostok::mutable_buffer *buffer,
        bool calc_size)
{
  const vostok::variant<32> **v3; // eax
  vostok::particle::color_matrix_point_type *pointer; // [esp-8h] [ebp-14h]
  unsigned int save_size; // [esp+8h] [ebp-4h]

  save_size = 24 * this->m_num_columns * this->m_num_rows;
  if ( !calc_size )
  {
    pointer = this->m_points.pointer;
    v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
           (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)save_size,
           (int)buffer);
    vostok::memory::copy(v3, save_size, pointer, save_size);
    vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)save_size, buffer);
  }
  return save_size;
}
