void __userpurge survarium::game_statistics_handler::start_match(
        survarium::game_statistics_handler *this@<eax>,
        const survarium::match_options *match_options@<edi>,
        survarium::game_statistics_handler *a3@<ecx>,
        survarium::game_world_core *game_world_core)
{
  survarium::game_world_core *v4; // ebx
  survarium::gather_victory_items_rule *v6; // eax

  v4 = game_world_core;
  this->m_game_world_core = game_world_core;
  game_world_core->m_statistics_events_handler = this;
  this->m_match_options = match_options;
  this->m_players_count = match_options->players_count;
  if ( (this->m_on_score_changed_callback.vtable != 0
      ? (unsigned int)vostok::memory::process_allocator::finalize_impl
      : 0) != 0 )
  {
    LOBYTE(game_world_core) = 0;
    while ( (_BYTE)game_world_core != this->m_players_count )
    {
      survarium::game_statistics_handler::emit_score_changed_event(
        a3,
        (int)this,
        (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)game_world_core,
        (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(unsigned __int16)this->m_players_scores.elems[(unsigned __int8)game_world_core]);
      LOBYTE(game_world_core) = (_BYTE)game_world_core + 1;
    }
  }
  this->m_shared_statistics.m_match_options = match_options;
  this->m_shared_statistics.m_winner_team = team_undefined;
  this->m_shared_statistics.m_players_count = match_options->players_count;
  this->m_shared_statistics.m_teammate_cure_event_manager.m_match_options = match_options;
  v6 = (survarium::gather_victory_items_rule *)survarium::game_world_core::game_rule(v4);
  if ( v6 )
    survarium::victory_item_event_manager::start_match(
      match_options,
      &this->m_shared_statistics.m_victory_item_event_manager,
      v6);
}
