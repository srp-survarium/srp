unsigned int __thiscall boost::asio::detail::win_iocp_io_service::poll(
        boost::asio::detail::win_iocp_io_service *this,
        boost::system::error_code *ec)
{
  const boost::system::error_category *v2; // edx
  unsigned int v5; // [esp+1D4h] [ebp-1Ch]
  boost::asio::detail::call_stack<boost::asio::detail::win_iocp_io_service,unsigned char>::context ctx; // [esp+1E0h] [ebp-10h] BYREF
  unsigned int n; // [esp+1ECh] [ebp-4h]

  if ( InterlockedExchangeAdd(&this->outstanding_work_, 0) )
  {
    boost::asio::detail::call_stack<boost::asio::detail::win_iocp_io_service,unsigned char>::context::context(
      &ctx,
      this);
    n = 0;
    while ( boost::asio::detail::win_iocp_io_service::do_one(this, 0, ec) )
    {
      if ( n != -1 )
        ++n;
    }
    v5 = n;
    TlsSetValue(
      boost::asio::detail::call_stack<boost::asio::detail::win_iocp_io_service,unsigned char>::top_.tss_key_,
      ctx.next_);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&ctx);
    return v5;
  }
  else
  {
    boost::asio::detail::win_iocp_io_service::stop(this);
    v2 = boost::system::system_category();
    ec->m_val = 0;
    ec->m_cat = v2;
    return 0;
  }
}
