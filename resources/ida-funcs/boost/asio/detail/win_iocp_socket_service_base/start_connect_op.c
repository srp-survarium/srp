void __userpurge boost::asio::detail::win_iocp_socket_service_base::start_connect_op(
        boost::asio::detail::win_iocp_socket_service_base *this@<ecx>,
        volatile LONG *a2@<eax>,
        boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *impl,
        boost::asio::detail::reactor_op *op,
        const sockaddr *addr,
        unsigned int addrlen)
{
  boost::asio::detail::service_registry *v8; // ecx
  boost::system::error_code *p_ec; // esi
  int io_service; // esi
  boost::asio::detail::win_iocp_io_service *v11; // ecx
  unsigned int v12; // [esp+0h] [ebp-18h]
  boost::asio::detail::select_reactor::per_descriptor_data *v13; // [esp+4h] [ebp-14h]
  bool v14; // [esp+8h] [ebp-10h]
  boost::asio::io_service::service::key key; // [esp+Ch] [ebp-Ch] BYREF
  volatile LONG *Target; // [esp+14h] [ebp-4h]
  boost::asio::detail::select_reactor *v17; // [esp+20h] [ebp+8h]

  Target = a2 + 2;
  v17 = (boost::asio::detail::select_reactor *)InterlockedCompareExchange(a2 + 2, 0, 0);
  if ( !v17 )
  {
    v8 = *(boost::asio::detail::service_registry **)(*a2 + 4);
    key.id_ = 0;
    key.type_info_ = (const type_info *)&boost::asio::detail::typeid_wrapper<boost::asio::detail::select_reactor> `RTTI Type Descriptor';
    v17 = (boost::asio::detail::select_reactor *)boost::asio::detail::service_registry::do_use_service(
                                                   v8,
                                                   &key,
                                                   (boost::asio::io_service::service *(__cdecl *)(boost::asio::io_service *))boost::asio::detail::service_registry::create<boost::asio::detail::select_reactor>);
    InterlockedExchange(Target, (LONG)v17);
  }
  if ( ((impl->state_ & 3) != 0
     || boost::asio::detail::socket_ops::set_internal_non_blocking(&impl->state_, &op->ec_, (int)impl, impl->socket_))
    && (p_ec = &op->ec_, boost::asio::detail::socket_ops::connect(&op->ec_, (int)impl, impl->socket_, addr, addrlen))
    && (op->ec_.m_cat == boost::system::system_category() && p_ec->m_val == 10036
     || op->ec_.m_cat == boost::system::system_category() && p_ec->m_val == 10035) )
  {
    op->ec_.m_cat = boost::system::system_category();
    p_ec->m_val = 0;
    boost::asio::detail::select_reactor::start_op(v17, op, impl->socket_, v12, v13, v14);
  }
  else
  {
    io_service = (int)v17->io_service_;
    InterlockedIncrement((volatile LONG *)(io_service + 24));
    boost::asio::detail::win_iocp_io_service::post_deferred_completion(v11, io_service, op);
  }
}
