void __userpurge boost::asio::detail::resolver_service_base::fork_service(
        boost::asio::detail::resolver_service_base *this@<ecx>,
        boost::asio::detail::resolver_service_base::work_io_service_runner *a2@<eax>,
        boost::asio::io_service::fork_event fork_ev)
{
  HANDLE **v4; // ebx
  boost::asio::detail::win_iocp_io_service *impl; // eax
  boost::asio::detail::win_thread *v6; // ecx
  boost::asio::detail::win_thread *v7; // eax
  boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread> *v8; // ecx
  HANDLE *v9; // eax
  boost::asio::detail::win_thread *v10; // [esp-4h] [ebp-10h]
  unsigned int v11; // [esp+0h] [ebp-Ch]

  v4 = (HANDLE **)&a2[10];
  if ( a2[10].io_service_ )
  {
    impl = a2[7].io_service_->impl_;
    if ( fork_ev )
    {
      InterlockedExchange(&impl->stopped_, 0);
      v7 = (boost::asio::detail::win_thread *)operator new(0xCu);
      v8 = (boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread> *)v10;
      if ( v7 )
        boost::asio::detail::win_thread::win_thread(v10, v7, a2[7], v11);
      else
        v9 = 0;
      boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread>::reset(v8, v4, v9);
    }
    else
    {
      boost::asio::detail::win_iocp_io_service::stop((boost::asio::detail::win_iocp_io_service *)this, (int)impl);
      boost::asio::detail::win_thread::join(v6, (int)*v4);
    }
  }
}
