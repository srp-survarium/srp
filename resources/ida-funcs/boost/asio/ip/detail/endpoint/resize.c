void __thiscall boost::asio::ip::detail::endpoint::resize(void *ec)
{
  boost::system::error_code err; // [esp+8h] [ebp-8h] BYREF

  err.m_cat = boost::system::system_category();
  err.m_val = 10022;
  if ( vostok::memory::process_allocator::finalize_impl )
    boost::asio::detail::do_throw_error(&err);
}
