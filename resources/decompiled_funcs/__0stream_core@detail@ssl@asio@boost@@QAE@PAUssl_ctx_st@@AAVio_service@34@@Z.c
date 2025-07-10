void __thiscall boost::asio::ssl::detail::stream_core::stream_core(
        boost::asio::ssl::detail::stream_core *this,
        ssl_ctx_st *context,
        boost::asio::io_service *io_service)
{
  survarium::game_camera *v3; // ecx
  const stlp_std::allocator<unsigned char> *v4; // eax
  survarium::game_camera *v5; // ecx
  const unsigned __int8 *v6; // eax
  survarium::game_camera *v7; // ecx
  survarium::game_camera *v8; // ecx
  survarium::game_camera *v9; // eax
  const unsigned __int8 *v10; // eax
  survarium::game_camera *v11; // ecx
  const stlp_std::allocator<unsigned char> *v12; // [esp-4h] [ebp-348h]
  const stlp_std::allocator<unsigned char> *v13; // [esp-4h] [ebp-348h]
  boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config> v15; // [esp+32Ch] [ebp-18h] BYREF
  boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config> result; // [esp+334h] [ebp-10h] BYREF
  char v17; // [esp+340h] [ebp-4h]
  char v18; // [esp+342h] [ebp-2h]

  boost::asio::ssl::detail::engine::engine(&this->engine_, context);
  boost::asio::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>(
    &this->pending_read_,
    io_service);
  boost::asio::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>(
    &this->pending_write_,
    io_service);
  v18 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  v12 = v4;
  survarium::weapon_user_dead_state::finalize(v5);
  stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>(
    &this->output_buffer_space_._M_impl,
    0x4400u,
    v6,
    v12);
  survarium::weapon_user_dead_state::finalize(v7);
  boost::asio::buffer<unsigned char,stlp_std::allocator<unsigned char>>(
    &this->output_buffer_,
    &this->output_buffer_space_);
  v17 = 0;
  survarium::weapon_user_dead_state::finalize(v8);
  v13 = (const stlp_std::allocator<unsigned char> *)v9;
  survarium::weapon_user_dead_state::finalize(v9);
  stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>(
    &this->input_buffer_space_._M_impl,
    0x4400u,
    v10,
    v13);
  survarium::weapon_user_dead_state::finalize(v11);
  boost::asio::buffer<unsigned char,stlp_std::allocator<unsigned char>>(
    &this->input_buffer_,
    &this->input_buffer_space_);
  this->input_.data_ = 0;
  this->input_.size_ = 0;
  boost::date_time::counted_time_system<boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>>::get_time_rep(
    &result,
    neg_infin);
  boost::asio::basic_deadline_timer<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>,boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::expires_at(
    &this->pending_read_,
    (const boost::posix_time::ptime *)&result);
  boost::date_time::counted_time_system<boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>>::get_time_rep(
    &v15,
    neg_infin);
  boost::asio::basic_deadline_timer<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>,boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::expires_at(
    &this->pending_write_,
    (const boost::posix_time::ptime *)&v15);
}
