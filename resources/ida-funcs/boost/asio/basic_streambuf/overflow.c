int __thiscall boost::asio::basic_streambuf<stlp_std::allocator<char>>::overflow(
        boost::asio::basic_streambuf<stlp_std::allocator<char> > *this,
        int c)
{
  unsigned int buffer_size; // [esp+330h] [ebp-4h]

  if ( c == -1 )
    return 0;
  if ( this->_M_pnext == this->_M_pend )
  {
    buffer_size = this->_M_pnext - this->_M_gnext;
    if ( buffer_size >= this->max_size_ || this->max_size_ - buffer_size >= 0x80 )
      boost::asio::basic_streambuf<stlp_std::allocator<char>>::reserve(this, 0x80u);
    else
      boost::asio::basic_streambuf<stlp_std::allocator<char>>::reserve(this, this->max_size_ - buffer_size);
  }
  *this->_M_pnext++ = c;
  return c;
}
