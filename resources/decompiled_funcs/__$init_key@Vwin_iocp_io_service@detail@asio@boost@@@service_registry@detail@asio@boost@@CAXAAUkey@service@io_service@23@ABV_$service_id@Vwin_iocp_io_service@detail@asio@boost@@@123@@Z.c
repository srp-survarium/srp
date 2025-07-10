void __cdecl boost::asio::detail::service_registry::init_key<boost::asio::detail::win_iocp_io_service>(
        boost::asio::io_service::service::key *key)
{
  key->type_info_ = (const type_info *)&boost::asio::detail::typeid_wrapper<boost::asio::detail::win_iocp_io_service> `RTTI Type Descriptor';
  key->id_ = 0;
}
