int __usercall boost::asio::read_size_helper@<eax>(
        boost::asio::basic_streambuf<stlp_std::allocator<char> > *sb@<eax>,
        unsigned int max_size)
{
  int v2; // edx
  unsigned int v3; // ecx
  unsigned int *p_max_size; // edx
  int *v5; // eax
  int v7; // [esp+4h] [ebp-Ch] BYREF
  unsigned int v8; // [esp+8h] [ebp-8h] BYREF
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v2 = sb->_M_gnext - sb->_M_pnext;
  v3 = v2 + sb->buffer_._M_impl._M_end_of_storage._M_data - sb->buffer_._M_impl._M_start;
  v9 = v2 + sb->max_size_;
  v8 = v3;
  v7 = 512;
  p_max_size = &v9;
  if ( v9 >= max_size )
    p_max_size = &max_size;
  v5 = (int *)&v8;
  if ( v3 <= 0x200 )
    v5 = &v7;
  if ( *p_max_size < *v5 )
    v5 = (int *)p_max_size;
  return *v5;
}
