stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__usercall boost::asio::ip::host_name@<eax>(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *a1@<edi>)
{
  int v1; // eax
  char name[1028]; // [esp+8h] [ebp-410h] BYREF
  boost::system::error_code v4; // [esp+40Ch] [ebp-Ch] BYREF
  stlp_std::allocator<char> v5; // [esp+417h] [ebp-1h] BYREF

  v4.m_val = 0;
  v4.m_cat = boost::system::system_category();
  WSASetLastError(0);
  v1 = gethostname(name, 1024);
  if ( boost::asio::detail::socket_ops::error_wrapper<int>(&v4, v1) )
  {
    if ( (v4.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
      boost::asio::detail::do_throw_error(&v4);
    a1->_M_finish = (char *)a1;
    a1->_M_start_of_storage._M_data = (char *)a1;
    *a1->_M_finish = 0;
  }
  else
  {
    boost::system::system_category();
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
      a1,
      name,
      &v5);
  }
  return a1;
}
