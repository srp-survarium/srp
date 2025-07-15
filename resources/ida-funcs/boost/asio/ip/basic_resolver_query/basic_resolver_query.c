void __thiscall boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp>::basic_resolver_query<boost::asio::ip::tcp>(
        boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp> *this,
        boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp> *__that,
        int a3)
{
  qmemcpy(__that, (const void *)a3, 0x20u);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    &__that->host_name_,
    (const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)(a3 + 32));
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    &__that->service_name_,
    (const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)(a3 + 56));
}
