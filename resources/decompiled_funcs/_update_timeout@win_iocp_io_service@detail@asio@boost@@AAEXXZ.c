void __thiscall boost::asio::detail::win_iocp_io_service::update_timeout(
        boost::asio::detail::win_iocp_io_service *this)
{
  boost::asio::detail::timer_queue_base *i; // [esp+4h] [ebp-1Ch]
  int v3; // [esp+8h] [ebp-18h]
  _LARGE_INTEGER timeout; // [esp+10h] [ebp-10h] BYREF
  int timeout_usec; // [esp+1Ch] [ebp-4h]

  if ( this->timer_thread_.p_ )
  {
    v3 = 300000000;
    for ( i = this->timer_queues_.first_; i; i = i->next_ )
      v3 = i->wait_duration_usec(i, v3);
    timeout_usec = v3;
    if ( v3 < 300000000 )
    {
      timeout.QuadPart = 10LL * -timeout_usec;
      SetWaitableTimer(this->waitable_timer_.handle, &timeout, (LONG)&loc_493DF + 1, 0, 0, 0);
    }
  }
}
