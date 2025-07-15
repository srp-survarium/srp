void __thiscall boost::asio::ssl::detail::stream_core::~stream_core(boost::asio::ssl::detail::stream_core *this)
{
  stlp_std::vector<unsigned char,stlp_std::allocator<unsigned char> > *v1; // ecx

  stlp_std::vector<unsigned char,stlp_std::allocator<unsigned char>>::~vector<unsigned char,stlp_std::allocator<unsigned char>>(
    (stlp_std::vector<unsigned char,stlp_std::allocator<unsigned char> > *)this,
    (int)&this->input_buffer_space_);
  stlp_std::vector<unsigned char,stlp_std::allocator<unsigned char>>::~vector<unsigned char,stlp_std::allocator<unsigned char>>(
    v1,
    (int)&this->output_buffer_space_);
  boost::asio::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::~basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>(&this->pending_write_);
  boost::asio::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::~basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>(&this->pending_read_);
  boost::asio::ssl::detail::engine::~engine(&this->engine_);
}
