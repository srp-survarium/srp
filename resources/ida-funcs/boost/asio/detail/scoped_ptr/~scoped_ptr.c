void __thiscall boost::asio::detail::scoped_ptr<boost::asio::io_service>::~scoped_ptr<boost::asio::io_service>(
        boost::asio::detail::scoped_ptr<boost::asio::io_service> *this)
{
  boost::asio::io_service *p; // [esp+28h] [ebp-4h]

  p = this->p_;
  if ( this->p_ )
  {
    boost::asio::io_service::~io_service(p);
    operator delete(p);
  }
}


void __thiscall boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread>::~scoped_ptr<boost::asio::detail::win_thread>(
        boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread> *this)
{
  boost::asio::detail::win_thread *p; // [esp+Ch] [ebp-4h]

  p = this->p_;
  if ( this->p_ )
  {
    CloseHandle(p->thread_);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)p);
    operator delete(p);
  }
}


void __thiscall boost::asio::detail::scoped_ptr<boost::asio::io_service::work>::~scoped_ptr<boost::asio::io_service::work>(
        boost::asio::detail::scoped_ptr<boost::asio::io_service::work> *this)
{
  boost::asio::detail::win_iocp_io_service *io_service_impl; // [esp+8h] [ebp-174h]
  boost::asio::io_service::work *p; // [esp+178h] [ebp-4h]

  p = this->p_;
  if ( this->p_ )
  {
    io_service_impl = p->io_service_impl_;
    if ( !InterlockedDecrement(&p->io_service_impl_->outstanding_work_) )
      boost::asio::detail::win_iocp_io_service::stop(io_service_impl);
    operator delete(p);
  }
}
