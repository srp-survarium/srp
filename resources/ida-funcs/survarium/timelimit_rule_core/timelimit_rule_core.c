void __usercall survarium::timelimit_rule_core::timelimit_rule_core(
        survarium::timelimit_rule_core *this@<eax>,
        const survarium::match_options *options@<edi>,
        survarium::game_match_rule_base *a3@<ecx>)
{
  survarium::game_match_rule_base::game_match_rule_base(a3, this, timelimit_rule_type);
  this->m_current_state = game_status_inactive;
  this->m_state_start_time_ms = -1;
  this->m_current_time_in_ms = -1;
  this->m_players_mask = 0;
  this->survarium::game_match_rule_base::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::timelimit_rule_core_vtbl *)&survarium::timelimit_rule_core::`vftable'{for `vostok::resources::unmanaged_resource'};
  this->survarium::game_match_rule_base::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::timelimit_rule_core::`vftable'{for `survarium::link_resolver'};
  this->m_match_length_ms = 1000 * options->match_time;
  this->m_wait_player_percent = options->wait_player_percent;
  this->m_wait_players_time = 60000 * (options->wait1_time + options->wait2_time);
  this->m_countdown_time = 1000 * options->countdown_time;
  this->m_players_count = options->players_count;
}
