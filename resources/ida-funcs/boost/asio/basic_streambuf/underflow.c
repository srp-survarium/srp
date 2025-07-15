int __thiscall boost::asio::basic_streambuf<stlp_std::allocator<char>>::underflow(
        boost::asio::basic_streambuf<stlp_std::allocator<char> > *this)
{
  char *M_pnext; // eax
  char *M_gnext; // edx

  M_pnext = this->_M_pnext;
  M_gnext = this->_M_gnext;
  if ( M_gnext >= M_pnext )
    return -1;
  this->_M_gbegin = this->buffer_._M_impl._M_start;
  this->_M_gend = M_pnext;
  return (unsigned __int8)*M_gnext;
}
