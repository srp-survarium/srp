void __userpurge boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>(
        boost::asio::io_service *io_service@<eax>,
        boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > *this)
{
  boost::asio::detail::service_registry *service_registry; // edi
  boost::asio::io_service::service::key key; // [esp+Ch] [ebp-8h] BYREF

  key.id_ = 0;
  service_registry = io_service->service_registry_;
  key.type_info_ = (const type_info *)&boost::asio::detail::typeid_wrapper<boost::asio::stream_socket_service<boost::asio::ip::tcp>> `RTTI Type Descriptor';
  this->service = (boost::asio::stream_socket_service<boost::asio::ip::tcp> *)boost::asio::detail::service_registry::do_use_service(
                                                                                service_registry,
                                                                                &key,
                                                                                boost::asio::detail::service_registry::create<boost::asio::stream_socket_service<boost::asio::ip::tcp>>);
  this->implementation.cancel_token_.px = 0;
  this->implementation.cancel_token_.pn.pi_ = 0;
  this->implementation.protocol_.family_ = 2;
  this->implementation.have_remote_endpoint_ = 0;
  memset(&this->implementation.remote_endpoint_, 0, sizeof(this->implementation.remote_endpoint_));
  this->implementation.remote_endpoint_.impl_.data_.base.sa_family = 2;
  this->implementation.remote_endpoint_.impl_.data_.v4.sin_addr.S_un.S_addr = 0;
  this->implementation.remote_endpoint_.impl_.data_.v4.sin_port = 0;
  boost::asio::detail::win_iocp_socket_service_base::construct(&this->service->service_impl_, &this->implementation, 0);
}
