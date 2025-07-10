void __thiscall boost::asio::detail::service_registry::~service_registry(boost::asio::detail::service_registry *this)
{
  boost::asio::io_service::service *next_service; // [esp+14h] [ebp-8h]
  boost::asio::io_service::service *service; // [esp+18h] [ebp-4h]

  for ( service = this->first_service_; service; service = service->next_ )
    service->shutdown_service(service);
  while ( this->first_service_ )
  {
    next_service = this->first_service_->next_;
    ((void (__thiscall *)(boost::asio::io_service::service *, int))this->first_service_->~boost::asio::io_service::service)(
      this->first_service_,
      1);
    this->first_service_ = next_service;
  }
  DeleteCriticalSection(&this->mutex_.crit_section_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
