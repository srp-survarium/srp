void __thiscall boost::asio::ssl::context::load_verify_file(
        boost::asio::ssl::context *this,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *filename)
{
  boost::system::error_code result; // [esp+178h] [ebp-10h] BYREF
  boost::system::error_code ec; // [esp+180h] [ebp-8h] BYREF

  ec.m_val = 0;
  ec.m_cat = boost::system::system_category();
  boost::asio::ssl::context::load_verify_file(this, &result, filename, &ec);
  if ( (ec.m_val != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
    boost::asio::detail::do_throw_error(&ec, "load_verify_file");
}
