void __thiscall boost::asio::detail::win_iocp_socket_service_base::start_connect_op(
        boost::asio::detail::win_iocp_socket_service_base *this,
        boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *impl,
        boost::asio::detail::reactor_op *op,
        const sockaddr *addr,
        unsigned int addrlen)
{
  char v5; // [esp+0h] [ebp-124h]
  char v6; // [esp+4h] [ebp-120h]
  boost::asio::detail::win_iocp_io_service *io_service; // [esp+Ch] [ebp-118h]
  const boost::system::error_category *v8; // [esp+10Ch] [ebp-18h]
  boost::asio::detail::select_reactor *r; // [esp+120h] [ebp-4h]

  r = boost::asio::detail::win_iocp_socket_service_base::get_reactor(this);
  if ( ((impl->state_ & 3) != 0
     || boost::asio::detail::socket_ops::set_internal_non_blocking(impl->socket_, &impl->state_, 1, &op->ec_))
    && boost::asio::detail::socket_ops::connect(impl->socket_, addr, addrlen, &op->ec_)
    && (op->ec_.m_cat != boost::system::system_category() || op->ec_.m_val != 10036 ? (v6 = 0) : (v6 = 1),
        v6 || (op->ec_.m_cat != boost::system::system_category() || op->ec_.m_val != 10035 ? (v5 = 0) : (v5 = 1), v5)) )
  {
    v8 = boost::system::system_category();
    op->ec_.m_val = 0;
    op->ec_.m_cat = v8;
    boost::asio::detail::select_reactor::start_op(r, 3, impl->socket_, &impl->reactor_data_, op, 0);
  }
  else
  {
    io_service = r->io_service_;
    InterlockedIncrement(&io_service->outstanding_work_);
    boost::asio::detail::win_iocp_io_service::post_deferred_completion(io_service, op);
  }
}
