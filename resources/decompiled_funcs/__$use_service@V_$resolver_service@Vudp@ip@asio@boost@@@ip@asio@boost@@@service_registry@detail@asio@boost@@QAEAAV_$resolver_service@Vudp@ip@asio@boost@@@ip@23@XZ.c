boost::asio::ip::resolver_service<boost::asio::ip::udp> *__thiscall boost::asio::detail::service_registry::use_service<boost::asio::ip::resolver_service<boost::asio::ip::udp>>(
        boost::asio::detail::service_registry *this)
{
  boost::asio::io_service::service::key key; // [esp+60h] [ebp-Ch] BYREF
  boost::asio::io_service::service *(__cdecl *factory)(boost::asio::io_service *); // [esp+68h] [ebp-4h]

  key.type_info_ = 0;
  key.id_ = 0;
  boost::asio::detail::service_registry::init_key<boost::asio::ip::resolver_service<boost::asio::ip::udp>>(
    &key,
    &boost::asio::detail::service_base<boost::asio::ip::resolver_service<boost::asio::ip::udp>>::id);
  factory = boost::asio::detail::service_registry::create<boost::asio::ip::resolver_service<boost::asio::ip::udp>>;
  return (boost::asio::ip::resolver_service<boost::asio::ip::udp> *)boost::asio::detail::service_registry::do_use_service(
                                                                      this,
                                                                      &key,
                                                                      boost::asio::detail::service_registry::create<boost::asio::ip::resolver_service<boost::asio::ip::udp>>);
}
