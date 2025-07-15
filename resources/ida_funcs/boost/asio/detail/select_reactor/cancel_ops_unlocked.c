void __thiscall boost::asio::detail::select_reactor::cancel_ops_unlocked(
        boost::asio::detail::select_reactor *this,
        unsigned int descriptor,
        const boost::system::error_code *ec)
{
  bool v3; // [esp+0h] [ebp-D8h]
  int i; // [esp+C8h] [ebp-10h]
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> ops; // [esp+CCh] [ebp-Ch] BYREF
  bool need_interrupt; // [esp+D7h] [ebp-1h]

  need_interrupt = 0;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&ops);
  ops.front_ = 0;
  ops.back_ = 0;
  for ( i = 0; i < 4; ++i )
  {
    v3 = boost::asio::detail::reactor_op_queue<unsigned int>::cancel_operations(
           &this->op_queue_[i],
           descriptor,
           &ops,
           ec)
      || need_interrupt;
    need_interrupt = v3;
  }
  boost::asio::detail::win_iocp_io_service::post_deferred_completions(this->io_service_, &ops);
  if ( need_interrupt )
    boost::asio::detail::socket_select_interrupter::interrupt(&this->interrupter_);
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::~op_queue<boost::asio::detail::win_iocp_operation>((boost::asio::detail::op_queue<boost::asio::detail::timer_op> *)&ops);
}
