void __thiscall boost::asio::basic_streambuf<stlp_std::allocator<char>>::commit(
        boost::asio::basic_streambuf<stlp_std::allocator<char> > *this,
        unsigned int n)
{
  char *M_gnext; // [esp+8h] [ebp-18h]
  char *M_pnext; // [esp+Ch] [ebp-14h]

  if ( &this->_M_pnext[n] > this->_M_pend )
    n = this->_M_pend - this->_M_pnext;
  this->_M_pnext += n;
  M_pnext = this->_M_pnext;
  M_gnext = this->_M_gnext;
  this->_M_gbegin = this->_M_gbegin;
  this->_M_gnext = M_gnext;
  this->_M_gend = M_pnext;
}
