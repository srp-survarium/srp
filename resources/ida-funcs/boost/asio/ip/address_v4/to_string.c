stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__userpurge boost::asio::ip::address_v4::to_string@<eax>(
        boost::asio::ip::address_v4 *this@<ecx>,
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *a2@<esi>,
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *result)
{
  char *v3; // eax
  char v5[256]; // [esp+0h] [ebp-10Ch] BYREF
  boost::system::error_code err; // [esp+100h] [ebp-Ch] BYREF

  err.m_val = 0;
  err.m_cat = boost::system::system_category();
  v3 = boost::asio::detail::socket_ops::inet_ntop((char *)result, 2, v5, 0, &err);
  if ( v3 )
  {
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
      a2,
      v3,
      (const stlp_std::allocator<char> *)&result + 3);
  }
  else
  {
    a2->_M_finish = (char *)a2;
    a2->_M_start_of_storage._M_data = (char *)a2;
    *a2->_M_finish = 0;
  }
  if ( (err.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::asio::detail::do_throw_error(&err);
  return a2;
}
