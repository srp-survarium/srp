void __thiscall boost::asio::detail::select_reactor::select_reactor(
        boost::asio::detail::select_reactor *this,
        boost::asio::io_service *io_service)
{
  boost::asio::detail::win_thread *v2; // eax
  boost::asio::detail::binder1<void (__cdecl*)(boost::asio::detail::select_reactor *),boost::asio::detail::select_reactor *> v3; // [esp-Ch] [ebp-180h]
  boost::asio::detail::win_thread *v4; // [esp+0h] [ebp-174h]
  boost::asio::detail::win_thread *v6; // [esp+16Ch] [ebp-8h]
  boost::asio::detail::null_signal_blocker sb; // [esp+173h] [ebp-1h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->key_);
  this->__vftable = (boost::asio::detail::select_reactor_vtbl *)&boost::asio::io_service::service::`vftable';
  this->key_.type_info_ = 0;
  this->key_.id_ = 0;
  this->owner_ = io_service;
  this->next_ = 0;
  this->__vftable = (boost::asio::detail::select_reactor_vtbl *)&boost::asio::detail::service_base<boost::asio::detail::select_reactor>::`vftable';
  this->__vftable = (boost::asio::detail::select_reactor_vtbl *)&boost::asio::detail::select_reactor::`vftable';
  this->io_service_ = io_service->impl_;
  boost::asio::detail::win_mutex::win_mutex(&this->mutex_);
  boost::asio::detail::socket_select_interrupter::open_descriptors(&this->interrupter_);
  `vector constructor iterator'(
    (char *)this->op_queue_,
    0x1Cu,
    4,
    (void *(__thiscall *)(void *))boost::asio::detail::reactor_op_queue<unsigned int>::reactor_op_queue<unsigned int>);
  `vector constructor iterator'(
    (char *)this->fd_sets_,
    0xCu,
    3,
    (void *(__thiscall *)(void *))boost::asio::detail::win_fd_set_adapter::win_fd_set_adapter);
  this->timer_queues_.first_ = 0;
  this->stop_thread_ = 0;
  this->thread_ = 0;
  this->shutdown_ = 0;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&sb);
  v6 = (boost::asio::detail::win_thread *)operator new(0xCu);
  if ( v6 )
  {
    v3.arg1_ = this;
    v3.handler_ = boost::asio::detail::select_reactor::call_run_thread;
    boost::asio::detail::win_thread::win_thread(v6, v3, 0);
    v4 = v2;
  }
  else
  {
    v4 = 0;
  }
  this->thread_ = v4;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&sb);
}
