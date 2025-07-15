void __usercall boost::asio::detail::resolver_service_base::resolver_service_base(
        boost::asio::detail::resolver_service_base *this@<edi>,
        boost::asio::io_service *io_service@<eax>,
        boost::asio::detail::win_mutex *a3@<ecx>)
{
  _RTL_CRITICAL_SECTION_DEBUG *v3; // eax
  boost::asio::io_service *v4; // eax
  boost::asio::io_service::work *v5; // esi
  boost::asio::detail::win_iocp_io_service *impl; // eax
  boost::asio::io_service *v7; // [esp-4h] [ebp-8h]

  this->io_service_impl_ = io_service->impl_;
  boost::asio::detail::win_mutex::win_mutex(a3, &this->mutex_);
  v3 = (_RTL_CRITICAL_SECTION_DEBUG *)operator new(0xCu);
  if ( v3 )
    boost::asio::io_service::io_service(v7, v3);
  else
    v4 = 0;
  this->work_io_service_.p_ = v4;
  this->work_io_service_impl_ = v4->impl_;
  v5 = (boost::asio::io_service::work *)operator new(4u);
  if ( v5 )
  {
    impl = this->work_io_service_.p_->impl_;
    v5->io_service_impl_ = impl;
    InterlockedIncrement(&impl->outstanding_work_);
  }
  else
  {
    v5 = 0;
  }
  this->work_.p_ = v5;
  this->work_thread_.p_ = 0;
}
