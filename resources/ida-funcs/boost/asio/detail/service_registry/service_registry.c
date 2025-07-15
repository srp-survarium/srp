void __thiscall boost::asio::detail::service_registry::service_registry(
        boost::asio::detail::service_registry *this,
        boost::asio::io_service *o,
        boost::asio::detail::win_iocp_io_service *__formal,
        unsigned int arg)
{
  boost::asio::io_service::service *v4; // eax
  boost::asio::io_service::service *v5; // [esp+0h] [ebp-2DCh]
  boost::asio::detail::win_iocp_io_service *v7; // [esp+2D0h] [ebp-Ch]
  boost::asio::io_service::service::key key; // [esp+2D4h] [ebp-8h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  boost::asio::detail::win_mutex::win_mutex(&this->mutex_);
  this->owner_ = o;
  v7 = (boost::asio::detail::win_iocp_io_service *)operator new(0x54u);
  if ( v7 )
  {
    boost::asio::detail::win_iocp_io_service::win_iocp_io_service(v7, o, arg);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  this->first_service_ = v5;
  key = 0;
  boost::asio::detail::service_registry::init_key<boost::asio::detail::win_iocp_io_service>(&key);
  this->first_service_->key_ = key;
  this->first_service_->next_ = 0;
}
