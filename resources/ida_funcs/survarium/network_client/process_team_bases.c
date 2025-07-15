void __usercall survarium::network_client::process_team_bases(
        survarium::network_client *this@<eax>,
        vostok::network_core::packet_reader *reader@<esi>)
{
  survarium::game_world_ui::initialize_base_points(&this->m_game->m_game_world.game_ui, reader);
}
