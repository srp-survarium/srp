boost::asio::ip::address *__usercall boost::asio::ip::address::to_string@<eax>(
        boost::asio::ip::address *this@<ecx>,
        int a2@<eax>)
{
  if ( *(_DWORD *)a2 == 1 )
    boost::asio::ip::address_v6::to_string(
      (boost::asio::ip::address_v6 *)this,
      (char *)(a2 + 8),
      (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)this);
  else
    boost::asio::ip::address_v4::to_string(
      (boost::asio::ip::address_v4 *)this,
      (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)this,
      (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)(a2 + 4));
  return this;
}
