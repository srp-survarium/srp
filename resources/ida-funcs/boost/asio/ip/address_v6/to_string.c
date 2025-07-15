stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__usercall boost::asio::ip::address_v6::to_string@<eax>(
        boost::asio::ip::address_v6 *this@<ecx>,
        char *a2@<edi>,
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *a3@<esi>)
{
  char *v3; // eax
  char dest[260]; // [esp+0h] [ebp-110h] BYREF
  boost::system::error_code scope_id; // [esp+104h] [ebp-Ch] BYREF
  stlp_std::allocator<char> v7; // [esp+10Fh] [ebp-1h] BYREF

  scope_id.m_val = 0;
  scope_id.m_cat = boost::system::system_category();
  v3 = boost::asio::detail::socket_ops::inet_ntop(a2, 23, dest, *((_DWORD *)a2 + 4), &scope_id);
  if ( v3 )
  {
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
      a3,
      v3,
      &v7);
  }
  else
  {
    a3->_M_finish = (char *)a3;
    a3->_M_start_of_storage._M_data = (char *)a3;
    *a3->_M_finish = 0;
  }
  if ( (scope_id.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::asio::detail::do_throw_error(&scope_id);
  return a3;
}
