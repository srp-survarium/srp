void __thiscall boost::asio::detail::win_thread::join(boost::asio::detail::win_thread *this)
{
  void *handles[2]; // [esp+4h] [ebp-8h] BYREF

  handles[0] = this->exit_event_;
  handles[1] = this->thread_;
  WaitForMultipleObjects(2u, handles, 0, 0xFFFFFFFF);
  CloseHandle(this->exit_event_);
  if ( InterlockedExchangeAdd(
         (volatile LONG *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_parent_scene,
         0) )
  {
    TerminateThread(this->thread_, 0);
  }
  else
  {
    QueueUserAPC(boost::asio::detail::apc_function, this->thread_, 0);
    WaitForSingleObject(this->thread_, 0xFFFFFFFF);
  }
}
