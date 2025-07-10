void __cdecl boost::asio::detail::do_throw_error(const boost::system::error_code *err)
{
  boost::system::system_error e; // [esp+28h] [ebp-130h] BYREF

  boost::system::system_error::system_error(&e, *err);
  boost::throw_exception(&e);
  e.__vftable = (boost::system::system_error_vtbl *)&boost::system::system_error::`vftable';
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&e.m_what);
  stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)&e);
}
