void __thiscall boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::~op_queue<boost::asio::detail::win_iocp_operation>(
        boost::asio::detail::op_queue<boost::asio::detail::timer_op> *this)
{
  _DWORD v2[2]; // [esp+4h] [ebp-14h] BYREF
  boost::asio::detail::timer_op *next; // [esp+Ch] [ebp-Ch]
  boost::asio::detail::timer_op *front; // [esp+10h] [ebp-8h]
  boost::asio::detail::timer_op *op; // [esp+14h] [ebp-4h]

  while ( 1 )
  {
    op = this->front_;
    if ( !op )
      break;
    if ( this->front_ )
    {
      front = this->front_;
      next = (boost::asio::detail::timer_op *)this->front_->next_;
      this->front_ = next;
      if ( !this->front_ )
        this->back_ = 0;
      front->next_ = 0;
    }
    v2[0] = 0;
    v2[1] = boost::system::system_category();
    op->func_(0, op, (const boost::system::error_code *)v2, 0);
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
