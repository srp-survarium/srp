int __thiscall boost::asio::basic_streambuf<stlp_std::allocator<char>>::overflow(
        boost::asio::basic_streambuf<stlp_std::allocator<char> > *this,
        int c)
{
  char *M_pnext; // eax
  unsigned int v4; // eax
  boost::asio::basic_streambuf<stlp_std::allocator<char> > *max_size; // ecx

  if ( c == -1 )
    return 0;
  M_pnext = this->_M_pnext;
  if ( M_pnext == this->_M_pend )
  {
    v4 = M_pnext - this->_M_gnext;
    max_size = (boost::asio::basic_streambuf<stlp_std::allocator<char> > *)this->max_size_;
    if ( v4 >= (unsigned int)max_size
      || (max_size = (boost::asio::basic_streambuf<stlp_std::allocator<char> > *)((char *)max_size - v4),
          (unsigned int)max_size >= 0x80) )
    {
      boost::asio::basic_streambuf<stlp_std::allocator<char>>::reserve(
        max_size,
        (stlp_std::vector<char,stlp_std::allocator<char> > *)this,
        0x80u);
    }
    else
    {
      boost::asio::basic_streambuf<stlp_std::allocator<char>>::reserve(
        max_size,
        (stlp_std::vector<char,stlp_std::allocator<char> > *)this,
        (unsigned int)max_size);
    }
  }
  *this->_M_pnext++ = c;
  return c;
}
