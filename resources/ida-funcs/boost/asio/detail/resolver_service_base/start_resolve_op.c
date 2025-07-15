void __thiscall boost::asio::detail::resolver_service_base::start_resolve_op(
        boost::asio::detail::resolver_service_base *this,
        boost::asio::detail::win_iocp_operation *op)
{
  boost::asio::detail::win_iocp_io_service *work_io_service_impl; // [esp+4h] [ebp-58h]

  boost::asio::detail::resolver_service_base::start_work_thread(this);
  InterlockedIncrement(&this->io_service_impl_->outstanding_work_);
  work_io_service_impl = this->work_io_service_impl_;
  InterlockedIncrement(&work_io_service_impl->outstanding_work_);
  boost::asio::detail::win_iocp_io_service::post_deferred_completion(work_io_service_impl, op);
}
