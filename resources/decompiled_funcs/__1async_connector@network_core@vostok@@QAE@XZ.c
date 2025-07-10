void __thiscall vostok::network_core::async_connector::~async_connector(vostok::network_core::async_connector *this)
{
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v1; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v1,
    (int *)&this->m_on_error);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&this->m_on_connected);
  if ( this->m_host.values_.pn.pi_ )
    boost::detail::sp_counted_base::release(this->m_host.values_.pn.pi_);
}
