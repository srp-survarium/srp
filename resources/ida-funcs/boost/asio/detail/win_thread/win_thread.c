void __userpurge boost::asio::detail::win_thread::win_thread(
        boost::asio::detail::win_thread *this@<ecx>,
        boost::asio::detail::win_thread *a2@<edi>,
        boost::asio::detail::resolver_service_base::work_io_service_runner f,
        unsigned int stack_size)
{
  boost::asio::detail::resolver_service_base::work_io_service_runner *v4; // eax

  a2->thread_ = 0;
  a2->exit_event_ = 0;
  v4 = (boost::asio::detail::resolver_service_base::work_io_service_runner *)operator new(0x10u);
  if ( v4 )
  {
    v4->io_service_ = (boost::asio::io_service *)&boost::asio::detail::win_thread::func<boost::asio::detail::resolver_service_base::work_io_service_runner>::`vftable';
    v4[3].io_service_ = f.io_service_;
  }
  else
  {
    v4 = 0;
  }
  boost::asio::detail::win_thread::start_thread((boost::asio::detail::win_thread::func_base *)v4, a2, 0);
}
