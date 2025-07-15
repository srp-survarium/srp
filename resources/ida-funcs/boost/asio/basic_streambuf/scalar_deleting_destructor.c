boost::asio::basic_streambuf<stlp_std::allocator<char> > *__thiscall boost::asio::basic_streambuf<stlp_std::allocator<char>>::`scalar deleting destructor'(
        boost::asio::basic_streambuf<stlp_std::allocator<char> > *this,
        char a2)
{
  boost::asio::basic_streambuf<stlp_std::allocator<char>>::~basic_streambuf<stlp_std::allocator<char>>(this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
