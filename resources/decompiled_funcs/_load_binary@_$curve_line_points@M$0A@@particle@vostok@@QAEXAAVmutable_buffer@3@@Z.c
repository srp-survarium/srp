void __thiscall vostok::particle::curve_line_points<float,0>::load_binary(
        vostok::particle::curve_line_points<float,0> *this,
        vostok::mutable_buffer *buffer)
{
  this->points.pointer = (vostok::particle::curve_point<float> *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                                   (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
                                                                   (int)buffer);
  vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)(24 * this->num_points), buffer);
  vostok::particle::curve_line_points<float,0>::recalculate_ranges(this);
}
