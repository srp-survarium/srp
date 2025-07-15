boost::asio::mutable_buffers_1 *__cdecl boost::asio::buffer(
        boost::asio::mutable_buffers_1 *result,
        const boost::asio::mutable_buffer *b,
        unsigned int max_size_in_bytes)
{
  unsigned int size; // [esp+0h] [ebp-18h]

  if ( b->size_ >= max_size_in_bytes )
    size = max_size_in_bytes;
  else
    size = b->size_;
  result->data_ = b->data_;
  result->size_ = size;
  return result;
}


boost::asio::mutable_buffers_1 *__cdecl boost::asio::buffer<unsigned char,stlp_std::allocator<unsigned char>>(
        boost::asio::mutable_buffers_1 *result,
        vostok::fs_new::path_string_impl *data)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  survarium::game_camera *v3; // ecx
  void *v4; // eax
  void *v6; // [esp+0h] [ebp-14h]
  unsigned int v7; // [esp+10h] [ebp-4h]

  if ( vostok::fs_new::path_string_impl::length(data) )
  {
    stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v2, (int)data);
    survarium::weapon_user_dead_state::finalize(v3);
    v6 = v4;
  }
  else
  {
    v6 = 0;
  }
  v7 = vostok::fs_new::path_string_impl::length(data);
  result->data_ = v6;
  result->size_ = v7;
  return result;
}
