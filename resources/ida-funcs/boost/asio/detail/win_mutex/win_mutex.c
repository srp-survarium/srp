void __thiscall boost::asio::detail::win_mutex::win_mutex(
        boost::asio::detail::win_mutex *this,
        boost::asio::detail::win_mutex *a2)
{
  boost::system::error_code err; // [esp+8h] [ebp-Ch] BYREF

  err.m_val = boost::asio::detail::win_mutex::do_init(this, a2);
  err.m_cat = boost::system::system_category();
  if ( (err.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::asio::detail::do_throw_error(&err, "mutex");
}
