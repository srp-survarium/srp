void __thiscall vostok::network_core::udp_match_connection::~udp_match_connection(
        vostok::network_core::udp_match_connection *this)
{
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v1; // ecx
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v1,
    (int *)&this->m_on_disconnect);
  `vector destructor iterator'(
    (char *)&this->m_channels,
    0x18u,
    1,
    (void (__thiscall *)(void *))vostok::network_core::udp_match_connection::channel::~channel);
  survarium::weapon_user_dead_state::finalize(v2);
  survarium::weapon_user_dead_state::finalize(v3);
  survarium::weapon_user_dead_state::finalize(v4);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
