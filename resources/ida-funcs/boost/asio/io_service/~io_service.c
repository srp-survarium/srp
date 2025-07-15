void __thiscall boost::asio::io_service::~io_service(boost::asio::io_service *this)
{
  boost::asio::detail::service_registry *service_registry; // [esp+20h] [ebp-4h]

  service_registry = this->service_registry_;
  if ( service_registry )
  {
    boost::asio::detail::service_registry::~service_registry(service_registry);
    operator delete(service_registry);
  }
  if ( !InterlockedDecrement((volatile LONG *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.survarium::flash_external_handler) )
    WSACleanup();
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
