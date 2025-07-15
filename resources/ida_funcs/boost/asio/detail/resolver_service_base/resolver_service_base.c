void __thiscall boost::asio::detail::resolver_service_base::resolver_service_base(
        boost::asio::detail::resolver_service_base *this,
        boost::asio::io_service *io_service)
{
  boost::asio::io_service *v2; // eax
  boost::asio::io_service::work *v4; // [esp+8h] [ebp-170h]
  boost::asio::io_service *v5; // [esp+20h] [ebp-158h]
  boost::asio::io_service::work *v6; // [esp+170h] [ebp-8h]
  boost::asio::io_service *v7; // [esp+174h] [ebp-4h]

  this->io_service_impl_ = io_service->impl_;
  boost::asio::detail::win_mutex::win_mutex(&this->mutex_);
  v7 = (boost::asio::io_service *)operator new(0xCu);
  if ( v7 )
  {
    boost::asio::io_service::io_service(v7);
    v5 = v2;
  }
  else
  {
    v5 = 0;
  }
  this->work_io_service_.p_ = v5;
  this->work_io_service_impl_ = this->work_io_service_.p_->impl_;
  v6 = (boost::asio::io_service::work *)operator new(4u);
  if ( v6 )
  {
    v6->io_service_impl_ = this->work_io_service_.p_->impl_;
    InterlockedIncrement(&v6->io_service_impl_->outstanding_work_);
    v4 = v6;
  }
  else
  {
    v4 = 0;
  }
  this->work_.p_ = v4;
  this->work_thread_.p_ = 0;
}
