void __thiscall boost::asio::detail::win_thread::win_thread(
        boost::asio::detail::win_thread *this,
        boost::asio::detail::win_iocp_io_service::timer_thread_function f,
        unsigned int stack_size)
{
  boost::asio::detail::win_iocp_io_service::timer_thread_function *v4; // [esp+404h] [ebp-4h]

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  this->thread_ = 0;
  this->exit_event_ = 0;
  v4 = (boost::asio::detail::win_iocp_io_service::timer_thread_function *)operator new(0x10u);
  if ( v4 )
  {
    v4->io_service_ = (boost::asio::detail::win_iocp_io_service *)&boost::asio::detail::win_thread::func_base::`vftable';
    v4->io_service_ = (boost::asio::detail::win_iocp_io_service *)&boost::asio::detail::win_thread::func<boost::asio::detail::win_iocp_io_service::timer_thread_function>::`vftable';
    v4[3].io_service_ = f.io_service_;
    boost::asio::detail::win_thread::start_thread(this, (boost::asio::detail::win_thread::func_base *)v4, stack_size);
  }
  else
  {
    boost::asio::detail::win_thread::start_thread(this, 0, stack_size);
  }
}
