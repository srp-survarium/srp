void __thiscall vostok::network_core::http_client::~http_client(vostok::network_core::http_client *this)
{
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&this->m_on_error);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&this->m_on_content_downloaded);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&this->m_result_content);
  stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::~_Impl_vector<char,stlp_std::allocator<char>>(&this->m_response_buff.buffer_._M_impl);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_response_buff.max_size_);
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::~basic_streambuf<char,stlp_std::char_traits<char>>(&this->m_response_buff);
  stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::~_Impl_vector<char,stlp_std::allocator<char>>(&this->m_request_buff.buffer_._M_impl);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_request_buff.max_size_);
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::~basic_streambuf<char,stlp_std::char_traits<char>>(&this->m_request_buff);
  boost::asio::basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp>>::~basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp>>((boost::asio::basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp> > *)&this->m_socket);
  boost::shared_ptr<void>::reset(&this->m_resolver.implementation);
  if ( this->m_resolver.implementation.pn.pi_ )
    boost::detail::sp_counted_base::release(this->m_resolver.implementation.pn.pi_);
}
