void __userpurge boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp>>::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp>>(
        boost::asio::io_service *io_service@<eax>,
        boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp> > *this)
{
  boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp> > *v2; // ebx
  boost::asio::detail::service_registry *service_registry; // edi
  boost::shared_ptr<void> *v4; // ecx
  boost::asio::detail::socket_ops::noop_deleter v5; // [esp+0h] [ebp-1Ch]
  boost::asio::io_service::service::key key; // [esp+10h] [ebp-Ch] BYREF

  key.id_ = 0;
  v2 = this;
  service_registry = io_service->service_registry_;
  key.type_info_ = (const type_info *)&boost::asio::detail::typeid_wrapper<boost::asio::ip::resolver_service<boost::asio::ip::tcp>> `RTTI Type Descriptor';
  this->service = (boost::asio::ip::resolver_service<boost::asio::ip::tcp> *)boost::asio::detail::service_registry::do_use_service(
                                                                               service_registry,
                                                                               &key,
                                                                               boost::asio::detail::service_registry::create<boost::asio::ip::resolver_service<boost::asio::ip::tcp>>);
  this->implementation.px = 0;
  this->implementation.pn.pi_ = 0;
  LOBYTE(this) = 0;
  boost::shared_ptr<void>::reset<void,boost::asio::detail::socket_ops::noop_deleter>(
    v4,
    (int *)&v2->implementation,
    this,
    v5);
}


void __userpurge boost::asio::ip::basic_resolver<boost::asio::ip::udp,boost::asio::ip::resolver_service<boost::asio::ip::udp>>::basic_resolver<boost::asio::ip::udp,boost::asio::ip::resolver_service<boost::asio::ip::udp>>(
        boost::asio::io_service *io_service@<eax>,
        boost::asio::ip::basic_resolver<boost::asio::ip::udp,boost::asio::ip::resolver_service<boost::asio::ip::udp> > *this)
{
  boost::asio::ip::basic_resolver<boost::asio::ip::udp,boost::asio::ip::resolver_service<boost::asio::ip::udp> > *v2; // ebx
  boost::asio::detail::service_registry *service_registry; // edi
  boost::shared_ptr<void> *v4; // ecx
  boost::asio::detail::socket_ops::noop_deleter v5; // [esp+0h] [ebp-1Ch]
  boost::asio::io_service::service::key key; // [esp+10h] [ebp-Ch] BYREF

  key.id_ = 0;
  v2 = this;
  service_registry = io_service->service_registry_;
  key.type_info_ = (const type_info *)&boost::asio::detail::typeid_wrapper<boost::asio::ip::resolver_service<boost::asio::ip::udp>> `RTTI Type Descriptor';
  this->service = (boost::asio::ip::resolver_service<boost::asio::ip::udp> *)boost::asio::detail::service_registry::do_use_service(
                                                                               service_registry,
                                                                               &key,
                                                                               boost::asio::detail::service_registry::create<boost::asio::ip::resolver_service<boost::asio::ip::udp>>);
  this->implementation.px = 0;
  this->implementation.pn.pi_ = 0;
  LOBYTE(this) = 0;
  boost::shared_ptr<void>::reset<void,boost::asio::detail::socket_ops::noop_deleter>(
    v4,
    (int *)&v2->implementation,
    this,
    v5);
}
