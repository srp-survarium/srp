void __usercall boost::asio::ssl::detail::stream_core::~stream_core(
        boost::asio::ssl::detail::stream_core *this@<ecx>,
        int a2@<eax>,
        int a3@<edi>)
{
  boost::asio::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime> > > *v4; // ecx
  boost::asio::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime> > > *v5; // ecx
  boost::asio::ssl::detail::engine *v6; // ecx

  stlp_std::vector<unsigned char,stlp_std::allocator<unsigned char>>::~vector<unsigned char,stlp_std::allocator<unsigned char>>((stlp_std::vector<unsigned char,stlp_std::allocator<unsigned char> > *)(a2 + 108));
  stlp_std::vector<unsigned char,stlp_std::allocator<unsigned char>>::~vector<unsigned char,stlp_std::allocator<unsigned char>>((stlp_std::vector<unsigned char,stlp_std::allocator<unsigned char> > *)(a2 + 88));
  boost::asio::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::~basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>(
    v4,
    (int *)(a2 + 48));
  boost::asio::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::~basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>(
    v5,
    (int *)(a2 + 8));
  boost::asio::ssl::detail::engine::~engine(v6, a2, a3);
}
