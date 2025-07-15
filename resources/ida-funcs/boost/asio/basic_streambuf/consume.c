void __thiscall boost::asio::basic_streambuf<stlp_std::allocator<char>>::consume(
        boost::asio::basic_streambuf<stlp_std::allocator<char> > *this,
        unsigned int n)
{
  char *M_gnext; // [esp+18h] [ebp-10h]
  char *M_pnext; // [esp+1Ch] [ebp-Ch]

  if ( this->_M_gend < this->_M_pnext )
  {
    M_pnext = this->_M_pnext;
    M_gnext = this->_M_gnext;
    this->_M_gbegin = this->buffer_._M_impl._M_start;
    this->_M_gnext = M_gnext;
    this->_M_gend = M_pnext;
  }
  if ( &this->_M_gnext[n] > this->_M_pnext )
    n = this->_M_pnext - this->_M_gnext;
  this->_M_gnext += n;
}
