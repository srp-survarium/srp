void __thiscall boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread>::reset(
        boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread> *this,
        boost::asio::detail::win_thread *p)
{
  boost::asio::detail::win_thread *v3; // [esp+Ch] [ebp-4h]

  v3 = this->p_;
  if ( this->p_ )
  {
    CloseHandle(v3->thread_);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v3);
    operator delete(v3);
  }
  this->p_ = p;
}


void __thiscall boost::asio::detail::scoped_ptr<boost::asio::io_service::work>::reset(
        boost::asio::detail::scoped_ptr<boost::asio::io_service::work> *this,
        boost::asio::io_service::work *p)
{
  boost::asio::detail::win_iocp_io_service *io_service_impl; // [esp+8h] [ebp-174h]
  boost::asio::io_service::work *v4; // [esp+178h] [ebp-4h]

  v4 = this->p_;
  if ( this->p_ )
  {
    io_service_impl = v4->io_service_impl_;
    if ( !InterlockedDecrement(&v4->io_service_impl_->outstanding_work_) )
      boost::asio::detail::win_iocp_io_service::stop(io_service_impl);
    operator delete(v4);
  }
  this->p_ = p;
}
