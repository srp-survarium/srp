survarium::base_player *__thiscall survarium::game_world_core::player(
        survarium::game_world_core *this,
        unsigned __int8 player_id)
{
  return stlp_std::lower_bound<vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *,unsigned char,client_id_predicate>(
           this->m_clients.m_begin,
           this->m_clients.m_end,
           &player_id)->m_object;
}
