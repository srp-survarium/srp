void __thiscall boost::asio::detail::resolver_service_base::shutdown_service(
        boost::asio::detail::resolver_service_base *this)
{
  boost::asio::io_service *p; // [esp+2Ch] [ebp-180h]

  boost::asio::detail::scoped_ptr<boost::asio::io_service::work>::reset(&this->work_, 0);
  if ( this->work_io_service_.p_ )
  {
    boost::asio::detail::win_iocp_io_service::stop(this->work_io_service_.p_->impl_);
    if ( this->work_thread_.p_ )
    {
      boost::asio::detail::win_thread::join(this->work_thread_.p_);
      boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread>::reset(&this->work_thread_, 0);
    }
    p = this->work_io_service_.p_;
    if ( p )
    {
      boost::asio::io_service::~io_service(p);
      operator delete(p);
    }
    this->work_io_service_.p_ = 0;
  }
}
