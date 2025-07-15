void __usercall boost::asio::detail::do_throw_error(const boost::system::error_code *err@<eax>)
{
  int m_val; // esi
  const boost::system::error_category *m_cat; // edi
  boost::system::system_error v3; // [esp+8h] [ebp-150h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > __str; // [esp+13Ch] [ebp-1Ch] BYREF
  stlp_std::allocator<char> v5; // [esp+157h] [ebp-1h] BYREF

  m_val = err->m_val;
  m_cat = err->m_cat;
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    &__str,
    (char *)uri,
    &v5);
  stlp_std::__Named_exception::__Named_exception(&v3, &__str);
  v3.__vftable = (boost::system::system_error_vtbl *)&stlp_std::runtime_error::`vftable';
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&__str);
  v3.m_what._M_finish = (char *)&v3.m_what;
  v3.m_what._M_start_of_storage._M_data = (char *)&v3.m_what;
  v3.__vftable = (boost::system::system_error_vtbl *)&boost::system::system_error::`vftable';
  v3.m_error_code.m_val = m_val;
  v3.m_error_code.m_cat = m_cat;
  v3.m_what._M_buffers._M_static_buf[0] = 0;
  boost::throw_exception(&v3);
  boost::system::system_error::~system_error(&v3);
}


void __usercall boost::asio::detail::do_throw_error(const boost::system::error_code *err@<eax>, char *location)
{
  int m_val; // esi
  const boost::system::error_category *m_cat; // edi
  stlp_std::allocator<char> v4; // [esp+Fh] [ebp-149h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > __str; // [esp+10h] [ebp-148h] BYREF
  boost::system::system_error v6; // [esp+28h] [ebp-130h] BYREF

  m_val = err->m_val;
  m_cat = err->m_cat;
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    &__str,
    location,
    &v4);
  stlp_std::__Named_exception::__Named_exception(&v6, &__str);
  v6.__vftable = (boost::system::system_error_vtbl *)&stlp_std::runtime_error::`vftable';
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&__str);
  v6.m_what._M_finish = (char *)&v6.m_what;
  v6.m_what._M_start_of_storage._M_data = (char *)&v6.m_what;
  v6.__vftable = (boost::system::system_error_vtbl *)&boost::system::system_error::`vftable';
  v6.m_error_code.m_val = m_val;
  v6.m_error_code.m_cat = m_cat;
  v6.m_what._M_buffers._M_static_buf[0] = 0;
  boost::throw_exception(&v6);
  boost::system::system_error::~system_error(&v6);
}
