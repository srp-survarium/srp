void __thiscall boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp>::basic_resolver_query<boost::asio::ip::tcp>(
        boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp> *this,
        const boost::asio::ip::tcp *protocol,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *host,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *service,
        boost::asio::ip::resolver_query_base::flags resolve_flags)
{
  this->hints_.ai_flags = 0;
  this->hints_.ai_family = 0;
  this->hints_.ai_socktype = 0;
  this->hints_.ai_protocol = 0;
  this->hints_.ai_addrlen = 0;
  this->hints_.ai_canonname = 0;
  this->hints_.ai_addr = 0;
  this->hints_.ai_next = 0;
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    &this->host_name_,
    host);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    &this->service_name_,
    service);
  this->hints_.ai_flags = resolve_flags;
  this->hints_.ai_family = protocol->family_;
  this->hints_.ai_socktype = 1;
  this->hints_.ai_protocol = 6;
  this->hints_.ai_addrlen = 0;
  this->hints_.ai_canonname = 0;
  this->hints_.ai_addr = 0;
  this->hints_.ai_next = 0;
}
