void __thiscall boost::asio::detail::scoped_ptr<boost::asio::io_service::work>::reset(
        boost::asio::detail::scoped_ptr<boost::asio::io_service::work> *this,
        boost::asio::io_service::work *p)
{
  boost::asio::detail::win_iocp_io_service *io_service_impl; // [esp+8h] [ebp-174h]
  boost::asio::io_service::work *v4; // [esp+178h] [ebp-4h]

  v4 = this->p_;
  if ( this->p_ )
  {
    io_service_impl = v4->io_service_impl_;
    if ( !InterlockedDecrement(&v4->io_service_impl_->outstanding_work_) )
      boost::asio::detail::win_iocp_io_service::stop(io_service_impl);
    operator delete(v4);
  }
  this->p_ = p;
}
