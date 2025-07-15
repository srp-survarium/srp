void __thiscall survarium::weapon_user_animations_selector::set_sprint_callbacks(
        survarium::weapon_user_animations_selector *this,
        const boost::function<void __cdecl(void)> *start_callback,
        const boost::function<void __cdecl(void)> *end_callback)
{
  int v3; // eax
  boost::_bi::list4<enum vostok::connection_error_types_enum &,enum vostok::handshaking_error_types_enum &,enum vostok::socket_error_types_enum &,enum vostok::lobby_server_message_types_enum &> *v4; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  vostok::socket_error_types_enum *v6; // [esp+Ch] [ebp-8h] BYREF
  survarium::player_logic_base_state *state; // [esp+10h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v6 = boost::_bi::list3<char const * &,enum survarium::hit_affects_type_enum &,enum survarium::affect_event_type_enum &>::operator[](
         v4,
         v3);
  for ( state = (survarium::player_logic_base_state *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                        v5,
                                                        (int)&v6);
        state;
        state = (survarium::player_logic_base_state *)state->next )
  {
    if ( state->m_weapon_user_state_id == type_sprint )
      survarium::player_logic_sprint_state::set_callbacks(
        (survarium::player_logic_sprint_state *)state,
        start_callback,
        end_callback);
  }
}
