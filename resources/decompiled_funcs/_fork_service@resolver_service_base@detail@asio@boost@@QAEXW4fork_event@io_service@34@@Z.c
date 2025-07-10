void __thiscall boost::asio::detail::resolver_service_base::fork_service(
        boost::asio::detail::resolver_service_base *this,
        boost::asio::io_service::fork_event fork_ev)
{
  boost::asio::detail::win_thread *v2; // eax
  boost::asio::detail::win_thread *v4; // [esp+48h] [ebp-4h]

  if ( this->work_thread_.p_ )
  {
    if ( fork_ev )
    {
      InterlockedExchange(&this->work_io_service_.p_->impl_->stopped_, 0);
      v4 = (boost::asio::detail::win_thread *)operator new(0xCu);
      if ( v4 )
      {
        boost::asio::detail::win_thread::win_thread(
          v4,
          (boost::asio::detail::resolver_service_base::work_io_service_runner)this->work_io_service_.p_,
          0);
        boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread>::reset(&this->work_thread_, v2);
      }
      else
      {
        boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread>::reset(&this->work_thread_, 0);
      }
    }
    else
    {
      boost::asio::detail::win_iocp_io_service::stop(this->work_io_service_.p_->impl_);
      boost::asio::detail::win_thread::join(this->work_thread_.p_);
    }
  }
}
