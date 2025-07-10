int __thiscall boost::asio::basic_streambuf<stlp_std::allocator<char>>::underflow(
        boost::asio::basic_streambuf<stlp_std::allocator<char> > *this)
{
  char *M_gnext; // [esp+Ch] [ebp-10h]
  char *M_pnext; // [esp+10h] [ebp-Ch]

  if ( this->_M_gnext >= this->_M_pnext )
    return -1;
  M_pnext = this->_M_pnext;
  M_gnext = this->_M_gnext;
  this->_M_gbegin = this->buffer_._M_impl._M_start;
  this->_M_gnext = M_gnext;
  this->_M_gend = M_pnext;
  return *(unsigned __int8 *)this->_M_gnext;
}
