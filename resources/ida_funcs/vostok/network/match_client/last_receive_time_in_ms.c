unsigned int __thiscall vostok::network::match_client::last_receive_time_in_ms(vostok::network::match_client *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return *(_DWORD *)((char *)&loc_258133 + (unsigned int)*this->m_client + 1);
}
