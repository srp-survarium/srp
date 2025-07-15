unsigned int __cdecl boost::asio::read_size_helper(
        boost::asio::basic_streambuf<stlp_std::allocator<char> > *sb,
        unsigned int max_size)
{
  const unsigned int *v2; // eax
  const unsigned int *v4; // [esp-4h] [ebp-38h]
  unsigned int __a; // [esp+28h] [ebp-Ch] BYREF
  unsigned int v6; // [esp+2Ch] [ebp-8h] BYREF
  unsigned int __b; // [esp+30h] [ebp-4h] BYREF

  __b = sb->max_size_ - (sb->_M_pnext - sb->_M_gnext);
  v6 = sb->buffer_._M_impl._M_end_of_storage._M_data - sb->buffer_._M_impl._M_start - (sb->_M_pnext - sb->_M_gnext);
  __a = 512;
  v4 = stlp_std::min<unsigned int>(&max_size, &__b);
  v2 = stlp_std::max<unsigned int>(&__a, &v6);
  return *stlp_std::min<unsigned int>(v2, v4);
}
