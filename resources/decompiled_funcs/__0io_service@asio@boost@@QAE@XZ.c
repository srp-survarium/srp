void __thiscall boost::asio::io_service::io_service(boost::asio::io_service *this)
{
  boost::asio::detail::service_registry *v1; // eax
  boost::asio::detail::service_registry *v2; // [esp+0h] [ebp-2FCh]
  boost::asio::detail::service_registry *v4; // [esp+2F8h] [ebp-4h]

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  boost::asio::detail::winsock_init_base::startup(
    (boost::asio::detail::winsock_init_base::data *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.survarium::flash_external_handler,
    2u,
    0);
  boost::asio::detail::winsock_init_base::throw_on_error((boost::asio::detail::winsock_init_base::data *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.survarium::flash_external_handler);
  v4 = (boost::asio::detail::service_registry *)operator new(0x20u);
  if ( v4 )
  {
    boost::asio::detail::service_registry::service_registry(v4, this, 0, 0xFFFFFFFF);
    v2 = v1;
  }
  else
  {
    v2 = 0;
  }
  this->service_registry_ = v2;
  this->impl_ = boost::asio::detail::service_registry::first_service<boost::asio::detail::win_iocp_io_service>(this->service_registry_);
}
