void __thiscall boost::asio::detail::win_iocp_io_service::do_add_timer_queue(
        boost::asio::detail::win_iocp_io_service *this,
        boost::asio::detail::timer_queue_base *queue)
{
  boost::asio::detail::win_thread *v2; // eax
  boost::asio::detail::win_thread *v4; // [esp+158h] [ebp-24h]
  boost::system::error_code ec; // [esp+160h] [ebp-1Ch] BYREF
  unsigned int last_error; // [esp+168h] [ebp-14h]
  _LARGE_INTEGER timeout; // [esp+16Ch] [ebp-10h] BYREF
  boost::asio::detail::scoped_lock<boost::asio::detail::win_mutex> lock; // [esp+174h] [ebp-8h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&lock);
  lock.mutex_ = &this->dispatch_mutex_;
  EnterCriticalSection(&this->dispatch_mutex_.crit_section_);
  lock.locked_ = 1;
  queue->next_ = this->timer_queues_.first_;
  this->timer_queues_.first_ = queue;
  if ( !this->waitable_timer_.handle )
  {
    this->waitable_timer_.handle = CreateWaitableTimerA(0, 0, 0);
    if ( !this->waitable_timer_.handle )
    {
      last_error = GetLastError();
      ec.m_val = last_error;
      ec.m_cat = boost::system::system_category();
      if ( (last_error != 0
          ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
          : 0) != 0 )
        boost::asio::detail::do_throw_error(&ec, "timer");
    }
    timeout.QuadPart = -3000000000LL;
    SetWaitableTimer(this->waitable_timer_.handle, &timeout, 300000, 0, 0, 0);
  }
  if ( !this->timer_thread_.p_ )
  {
    v4 = (boost::asio::detail::win_thread *)operator new(0xCu);
    if ( v4 )
    {
      boost::asio::detail::win_thread::win_thread(
        v4,
        (boost::asio::detail::win_iocp_io_service::timer_thread_function)this,
        (unsigned int)&_sbh_sizeHeaderList);
      boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread>::reset(&this->timer_thread_, v2);
    }
    else
    {
      boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread>::reset(&this->timer_thread_, 0);
    }
  }
  if ( lock.locked_ )
    LeaveCriticalSection(&lock.mutex_->crit_section_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&lock);
}
