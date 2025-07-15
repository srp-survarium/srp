unsigned int __thiscall vostok::particle::curve_line_points<float,0>::save_binary(
        vostok::particle::curve_line_points<float,0> *this,
        vostok::mutable_buffer *buffer,
        bool calc_size)
{
  const vostok::variant<32> **v3; // eax
  vostok::particle::curve_point<float> *pointer; // [esp-8h] [ebp-14h]
  unsigned int save_size; // [esp+8h] [ebp-4h]

  save_size = 24 * this->num_points;
  if ( !calc_size )
  {
    pointer = this->points.pointer;
    v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
           (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
           (int)buffer);
    vostok::memory::copy(v3, save_size, pointer, save_size);
    vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)save_size, buffer);
  }
  return save_size;
}


unsigned int __thiscall vostok::particle::curve_line_points<vostok::math::float4_pod,1>::save_binary(
        vostok::particle::curve_line_points<vostok::math::float4_pod,1> *this,
        vostok::mutable_buffer *buffer,
        bool calc_size)
{
  const vostok::variant<32> **v3; // eax
  vostok::particle::curve_point<vostok::math::float4_pod> *pointer; // [esp-8h] [ebp-14h]
  unsigned int save_size; // [esp+8h] [ebp-4h]

  save_size = 72 * this->num_points;
  if ( !calc_size )
  {
    pointer = this->points.pointer;
    v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
           (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
           (int)buffer);
    vostok::memory::copy(v3, save_size, pointer, save_size);
    vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)save_size, buffer);
  }
  return save_size;
}
