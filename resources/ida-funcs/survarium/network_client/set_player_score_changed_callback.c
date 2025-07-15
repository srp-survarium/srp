void __thiscall survarium::network_client::set_player_score_changed_callback(
        survarium::network_client *this,
        const boost::function<void __cdecl(unsigned char,short)> *callback)
{
  if ( !vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_disable_game_statistics_gathering) )
    boost::function<void __cdecl (enum vostok::network_core::disconnect_event_types_enum)>::operator=(
      callback,
      (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_game_statistics.m_on_score_changed_callback);
}
